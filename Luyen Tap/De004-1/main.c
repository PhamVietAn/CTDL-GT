#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Food {
    int id;
    char name[50];
    char category[50];
    float price;
    struct Food *next;
} Food;

typedef struct FoodNode {
    int id;
    char name[50];
    char category[50];
    float price;
    struct FoodNode *prev;
    struct FoodNode *next;
} FoodNode;

Food *head = NULL;
FoodNode *soldHead = NULL, *soldTail = NULL;

Food* createFood(int id, char name[], char category[], float price) {
    Food *newFood = (Food *)malloc(sizeof(Food));
    newFood->id = id;
    strcpy(newFood->name, name);
    strcpy(newFood->category, category);
    newFood->price = price;
    newFood->next = NULL;
    return newFood;
}

void addFood() {
    int id;
    char name[50], category[50];
    float price;
    printf("Nhap ID: "); scanf("%d", &id);
    printf("Nhap ten mon: "); fflush(stdin); gets(name);
    printf("Nhap danh muc: "); gets(category);
    printf("Nhap gia: "); scanf("%f", &price);
    Food *newFood = createFood(id, name, category, price);
    newFood->next = head;
    head = newFood;
    printf("Da them mon an thanh cong!\n");
}

void displayFoods() {
    Food *temp = head;
    if (!temp) {
        printf("Khong co mon nao dang ban!\n");
        return;
    }
    printf("Danh sach mon dang ban:\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Loai: %s | Gia: %.2f\n", temp->id, temp->name, temp->category, temp->price);
        temp = temp->next;
    }
}

void updateFood() {
    int id;
    printf("Nhap ID mon can cap nhat: "); scanf("%d", &id);
    Food *temp = head;
    while (temp) {
        if (temp->id == id) {
            printf("Nhap ten moi: "); fflush(stdin); gets(temp->name);
            printf("Nhap danh muc moi: "); gets(temp->category);
            printf("Nhap gia moi: "); scanf("%f", &temp->price);
            printf("Cap nhat thanh cong!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay mon co ID %d!\n", id);
}

void markAsStopped() {
    int id;
    printf("Nhap ID mon can ngung ban: "); scanf("%d", &id);
    Food *prev = NULL, *cur = head;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("Khong tim thay mon co ID %d!\n", id);
        return;
    }
    if (!prev) head = cur->next;
    else prev->next = cur->next;

    FoodNode *node = (FoodNode *)malloc(sizeof(FoodNode));
    *node = (FoodNode){cur->id, "", "", cur->price, NULL, NULL};
    strcpy(node->name, cur->name);
    strcpy(node->category, cur->category);
    if (!soldHead) soldHead = soldTail = node;
    else {
        soldTail->next = node;
        node->prev = soldTail;
        soldTail = node;
    }
    free(cur);
    printf("Mon da duoc chuyen vao danh sach ngung ban!\n");
}

void displayStoppedFoods() {
    FoodNode *temp = soldHead;
    if (!temp) {
        printf("Khong co mon nao ngung ban!\n");
        return;
    }
    printf("Danh sach mon da ngung ban:\n");
    while (temp) {
        printf("ID: %d | Ten: %s | Loai: %s | Gia: %.2f\n", temp->id, temp->name, temp->category, temp->price);
        temp = temp->next;
    }
}

void searchFoodByName() {
    char keyword[50];
    printf("Nhap tu khoa can tim: "); fflush(stdin); gets(keyword);
    Food *temp = head;
    int found = 0;
    while (temp) {
        if (strstr(temp->name, keyword)) {
            printf("ID: %d | Ten: %s | Loai: %s | Gia: %.2f\n", temp->id, temp->name, temp->category, temp->price);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("Khong tim thay mon nao!\n");
}

void sortFoodsByPrice() {
    if (!head || !head->next) return;
    int swapped;
    Food *ptr1;
    Food *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->price > ptr1->next->price) {
                // Swap content
                Food temp = *ptr1;
                *ptr1 = *ptr1->next;
                *ptr1->next = temp;

                Food *tmp = ptr1->next;
                ptr1->next = tmp->next;
                tmp->next = ptr1;

                // Restore correct content
                float tprice = ptr1->price;
                ptr1->price = tmp->price;
                tmp->price = tprice;

                char tname[50], tcat[50];
                strcpy(tname, ptr1->name);
                strcpy(ptr1->name, tmp->name);
                strcpy(tmp->name, tname);

                strcpy(tcat, ptr1->category);
                strcpy(ptr1->category, tmp->category);
                strcpy(tmp->category, tcat);

                int tid = ptr1->id;
                ptr1->id = tmp->id;
                tmp->id = tid;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Da sap xep theo gia tang dan!\n");
}

int main() {
    int choice;
    do {
        printf("\n————— RESTAURANT MENU —————\n");
        printf("1. Them mon an\n2. Hien thi danh sach mon dang ban\n3. Cap nhat mon an\n");
        printf("4. Danh dau ngung ban\n5. Hien thi mon da ngung ban\n6. Tim kiem theo ten\n");
        printf("7. Sap xep theo gia\n8. Thoat\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addFood(); break;
            case 2: displayFoods(); break;
            case 3: updateFood(); break;
            case 4: markAsStopped(); break;
            case 5: displayStoppedFoods(); break;
            case 6: searchFoodByName(); break;
            case 7: sortFoodsByPrice(); break;
            case 8: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}
