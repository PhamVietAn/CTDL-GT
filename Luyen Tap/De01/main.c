#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc đơn hàng
typedef struct Order {
    int id;
    char customer[100];
    int status; // 0: chưa giao, 1: đã giao
    char total[20]; // tổng tiền dạng chuỗi
} Order;

// Node danh sách liên kết đôi (đơn chưa giao)
typedef struct DNode {
    Order order;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Node danh sách liên kết đơn (đơn đã giao)
typedef struct SNode {
    Order order;
    struct SNode *next;
} SNode;

DNode *headPending = NULL;
SNode *headDelivered = NULL;

// Hàm tạo một đơn hàng mới
Order createOrder() {
    Order o;
    printf("Nhap ID don hang: ");
    scanf("%d", &o.id);
    getchar(); // xóa ký tự '\n'
    printf("Nhap ten khach hang: ");
    fgets(o.customer, sizeof(o.customer), stdin);
    o.customer[strcspn(o.customer, "\n")] = 0;
    printf("Nhap tong tien: ");
    fgets(o.total, sizeof(o.total), stdin);
    o.total[strcspn(o.total, "\n")] = 0;
    o.status = 0;
    return o;
}

// Thêm vào danh sách liên kết đôi (chưa giao)
void addOrder() {
    Order o = createOrder();
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->order = o;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (headPending == NULL) {
        headPending = newNode;
    } else {
        DNode *temp = headPending;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Da them don hang thanh cong!\n");
}

// Hiển thị danh sách đơn hàng
void displayOrders() {
    printf("\n--- Don hang CHUA giao ---\n");
    DNode *temp = headPending;
    while (temp != NULL) {
        printf("ID: %d | Ten KH: %s | Trang thai: Chua giao | Tong tien: %s\n",
               temp->order.id, temp->order.customer, temp->order.total);
        temp = temp->next;
    }

    printf("\n--- Don hang DA giao ---\n");
    SNode *sTemp = headDelivered;
    while (sTemp != NULL) {
        printf("ID: %d | Ten KH: %s | Trang thai: Da giao | Tong tien: %s\n",
               sTemp->order.id, sTemp->order.customer, sTemp->order.total);
        sTemp = sTemp->next;
    }
}

// Xoá đơn hàng theo ID (chưa giao)
void deleteOrder() {
    int id;
    printf("Nhap ID don hang can xoa: ");
    scanf("%d", &id);

    DNode *temp = headPending;
    while (temp != NULL && temp->order.id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        headPending = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Da xoa don hang thanh cong!\n");
}

// Cập nhật đơn hàng
void updateOrder() {
    int id;
    printf("Nhap ID don hang can cap nhat: ");
    scanf("%d", &id);
    getchar();

    DNode *temp = headPending;
    while (temp != NULL && temp->order.id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    printf("Nhap ten khach hang moi: ");
    fgets(temp->order.customer, sizeof(temp->order.customer), stdin);
    temp->order.customer[strcspn(temp->order.customer, "\n")] = 0;
    printf("Nhap tong tien moi: ");
    fgets(temp->order.total, sizeof(temp->order.total), stdin);
    temp->order.total[strcspn(temp->order.total, "\n")] = 0;

    printf("Da cap nhat don hang!\n");
}

// Đánh dấu đã giao
void markAsDelivered() {
    int id;
    printf("Nhap ID don hang da giao: ");
    scanf("%d", &id);

    DNode *temp = headPending;
    while (temp != NULL && temp->order.id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    Order o = temp->order;
    o.status = 1;

    // Thêm vào danh sách đã giao
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->order = o;
    newNode->next = headDelivered;
    headDelivered = newNode;

    // Xoá khỏi danh sách chưa giao
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        headPending = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Don hang da duoc danh dau la da giao!\n");
}

// Chuyển đổi chuỗi tiền về số để so sánh
int parseTotal(char *total) {
    return atoi(total); // chỉ đơn giản lấy phần số nguyên
}

// Sắp xếp danh sách đơn hàng chưa giao theo tổng tiền
void sortOrders() {
    if (headPending == NULL || headPending->next == NULL) return;

    DNode *i, *j;
    for (i = headPending; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (parseTotal(i->order.total) > parseTotal(j->order.total)) {
                Order tmp = i->order;
                i->order = j->order;
                j->order = tmp;
            }
        }
    }
    printf("Da sap xep don hang theo tong tien tang dan!\n");
}

// Tìm kiếm theo tên khách hàng
void searchOrders() {
    char name[100];
    getchar();
    printf("Nhap ten khach hang can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;

    DNode *temp = headPending;
    while (temp != NULL) {
        if (strstr(temp->order.customer, name)) {
            printf("[CHUA GIAO] ID: %d | Ten: %s | Tong tien: %s\n",
                   temp->order.id, temp->order.customer, temp->order.total);
            found = 1;
        }
        temp = temp->next;
    }

    SNode *sTemp = headDelivered;
    while (sTemp != NULL) {
        if (strstr(sTemp->order.customer, name)) {
            printf("[DA GIAO] ID: %d | Ten: %s | Tong tien: %s\n",
                   sTemp->order.id, sTemp->order.customer, sTemp->order.total);
            found = 1;
        }
        sTemp = sTemp->next;
    }

    if (!found) {
        printf("Khong tim thay khach hang!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n—————————— ORDER MANAGER ——————————\n");
        printf("1. Them don hang moi\n");
        printf("2. Hien thi danh sach don hang\n");
        printf("3. Xoa don hang (theo id)\n");
        printf("4. Cap nhat thong tin don hang\n");
        printf("5. Danh dau don hang da duoc giao\n");
        printf("6. Sap xep don hang theo tong tien\n");
        printf("7. Tim kiem don hang\n");
        printf("8. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addOrder(); break;
            case 2: displayOrders(); break;
            case 3: deleteOrder(); break;
            case 4: updateOrder(); break;
            case 5: markAsDelivered(); break;
            case 6: sortOrders(); break;
            case 7: searchOrders(); break;
            case 8: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}
