#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[50];
    struct Task *next;  // cho taskList
    struct Task *prev, *nextDone; // cho completedList
} Task;

Task *taskList = NULL;
Task *completedHead = NULL, *completedTail = NULL;

Task* createTask(int id, char *title, int priority, char *deadline) {
    Task *newTask = (Task*)malloc(sizeof(Task));
    newTask->id = id;
    strcpy(newTask->title, title);
    newTask->priority = priority;
    strcpy(newTask->deadline, deadline);
    newTask->next = NULL;
    newTask->prev = newTask->nextDone = NULL;
    return newTask;
}

void addTask() {
    int id, priority;
    char title[100], deadline[50];
    printf("Nhap ID: "); scanf("%d", &id);
    printf("Nhap tieu de: "); getchar(); fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;
    printf("Nhap do uu tien: "); scanf("%d", &priority);
    printf("Nhap deadline: "); getchar(); fgets(deadline, 50, stdin);
    deadline[strcspn(deadline, "\n")] = 0;

    Task *newTask = createTask(id, title, priority, deadline);
    newTask->next = taskList;
    taskList = newTask;
    printf("✅ Da them nhiem vu!\n");
}

void displayTasks() {
    printf("\n📌 Nhiem vu dang thuc hien:\n");
    Task *cur = taskList;
    while (cur) {
        printf("ID: %d | %s | Priority: %d | Deadline: %s\n", cur->id, cur->title, cur->priority, cur->deadline);
        cur = cur->next;
    }

    printf("\n✅ Nhiem vu da hoan thanh:\n");
    cur = completedHead;
    while (cur) {
        printf("ID: %d | %s | Priority: %d | Deadline: %s\n", cur->id, cur->title, cur->priority, cur->deadline);
        cur = cur->nextDone;
    }
}

void deleteTask() {
    int id;
    printf("Nhap ID nhiem vu muon xoa: "); scanf("%d", &id);
    Task *cur = taskList, *prev = NULL;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("❌ Khong tim thay nhiem vu!\n");
        return;
    }
    if (prev) prev->next = cur->next;
    else taskList = cur->next;
    free(cur);
    printf("✅ Da xoa nhiem vu.\n");
}

void updateTask() {
    int id;
    printf("Nhap ID can cap nhat: "); scanf("%d", &id);
    Task *cur = taskList;
    while (cur && cur->id != id) cur = cur->next;
    if (!cur) {
        printf("❌ Khong tim thay!\n");
        return;
    }
    printf("Nhap tieu de moi: "); getchar(); fgets(cur->title, 100, stdin);
    cur->title[strcspn(cur->title, "\n")] = 0;
    printf("Nhap deadline moi: "); fgets(cur->deadline, 50, stdin);
    cur->deadline[strcspn(cur->deadline, "\n")] = 0;
    printf("Nhap do uu tien moi: "); scanf("%d", &cur->priority);
    printf("✅ Cap nhat thanh cong!\n");
}

void markDone() {
    int id;
    printf("Nhap ID nhiem vu da hoan thanh: "); scanf("%d", &id);
    Task *cur = taskList, *prev = NULL;
    while (cur && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("❌ Khong tim thay!\n");
        return;
    }
    if (prev) prev->next = cur->next;
    else taskList = cur->next;

    cur->next = NULL;
    if (!completedHead) {
        completedHead = completedTail = cur;
    } else {
        completedTail->nextDone = cur;
        cur->prev = completedTail;
        completedTail = cur;
    }
    printf("✅ Da danh dau hoan thanh!\n");
}

void sortTasks() {
    if (!taskList) return;
    int swapped;
    do {
        swapped = 0;
        Task *cur = taskList;
        while (cur->next) {
            if (cur->priority > cur->next->priority) {
                // Hoán đổi nội dung
                int tmp_id = cur->id;
                char tmp_title[100], tmp_deadline[50];
                int tmp_priority = cur->priority;

                strcpy(tmp_title, cur->title);
                strcpy(tmp_deadline, cur->deadline);

                cur->id = cur->next->id;
                strcpy(cur->title, cur->next->title);
                cur->priority = cur->next->priority;
                strcpy(cur->deadline, cur->next->deadline);

                cur->next->id = tmp_id;
                strcpy(cur->next->title, tmp_title);
                cur->next->priority = tmp_priority;
                strcpy(cur->next->deadline, tmp_deadline);

                swapped = 1;
            }
            cur = cur->next;
        }
    } while (swapped);
    printf("✅ Da sap xep theo do uu tien tang dan.\n");
}

void searchTask() {
    char keyword[100];
    printf("Nhap tu khoa tim kiem: "); getchar(); fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    Task *cur = taskList;
    printf("📌 Nhiem vu dang thuc hien:\n");
    while (cur) {
        if (strstr(cur->title, keyword))
            printf("ID: %d | %s | Priority: %d | Deadline: %s\n", cur->id, cur->title, cur->priority, cur->deadline);
        cur = cur->next;
    }

    cur = completedHead;
    printf("✅ Nhiem vu da hoan thanh:\n");
    while (cur) {
        if (strstr(cur->title, keyword))
            printf("ID: %d | %s | Priority: %d | Deadline: %s\n", cur->id, cur->title, cur->priority, cur->deadline);
        cur = cur->nextDone;
    }
}

int main() {
    int choice;
    do {
        printf("\n————— TASK MANAGER —————\n");
        printf("1. Them nhiem vu\n2. Hien thi\n3. Xoa\n4. Cap nhat\n5. Danh dau hoan thanh\n6. Sap xep\n7. Tim kiem\n8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: deleteTask(); break;
            case 4: updateTask(); break;
            case 5: markDone(); break;
            case 6: sortTasks(); break;
            case 7: searchTask(); break;
            case 8: printf("👋 Tam biet!\n"); break;
            default: printf("❌ Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}
