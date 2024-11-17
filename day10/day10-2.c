#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {
    VIP = 1,
    GOLD = 2,
    SILVER = 3,
    BRONZE = 4
} Rank;

typedef struct Customer {
    char customerName[100];
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} cus;

cus* head = NULL;

cus* createCustomer(const char* name, Rank rank, int order_amount, int point) {
    cus* newCustomer = (cus*)malloc(sizeof(cus));
    if (newCustomer == NULL) {
        return NULL;
    }
    strcpy(newCustomer->customerName, name);
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->prev = newCustomer->next = NULL;
    return newCustomer;
}

void insertCustomer(cus* newCustomer) {
    if (head == NULL) {
        head = newCustomer;
        return;
    }
    
    cus* current = head;
    while (current != NULL && current->rank <= newCustomer->rank) {
        if (current->rank == newCustomer->rank) {
            if (current->order_amount > newCustomer->order_amount) break;
            if (current->order_amount == newCustomer->order_amount && current->point >= newCustomer->point) break;
        }
        current = current->next;
    }

    if (current == NULL) {
        cus* tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = newCustomer;
        newCustomer->prev = tail;
    } else {
        newCustomer->next = current;
        newCustomer->prev = current->prev;
        if (current->prev != NULL)
            current->prev->next = newCustomer;
        else
            head = newCustomer;
        current->prev = newCustomer;
    }
}

void deleteCustomer(const char* name) {
    cus* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                head = current->next;
            
            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
            printf("고객 %s 삭제 완료\n", name);
            return;
        }
        current = current->next;
    }
    printf("고객 %s를 찾을 수 없습니다.\n", name);
}

void updateCustomer(const char* name) {
    cus* current = head;
    while (current != NULL) {
        if (strcmp(current->customerName, name) == 0) {
            printf("새로운 등급 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            int newRank;
            scanf("%d", &newRank);
            current->rank = (Rank)newRank;

            printf("새로운 주문량: ");
            scanf("%d", &current->order_amount);

            printf("새로운 포인트: ");
            scanf("%d", &current->point);

            printf("고객 %s 정보 수정 완료\n", name);
            return;
        }
        current = current->next;
    }
    printf("고객 %s를 찾을 수 없습니다.\n", name);
}

void printCustomerList() {
    int count = 0;
    cus* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    cus* customers[count];
    current = head;
    for (int i = 0; i < count; i++) {
        customers[i] = current;
        current = current->next;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (customers[j]->rank > customers[j + 1]->rank ||
                (customers[j]->rank == customers[j + 1]->rank &&
                customers[j]->order_amount < customers[j + 1]->order_amount) ||
                (customers[j]->rank == customers[j + 1]->rank &&
                customers[j]->order_amount == customers[j + 1]->order_amount &&
                customers[j]->point < customers[j + 1]->point)) {
                
                cus* temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }
    printf("----------------------------------------\n");
    printf("\n고객 리스트\n");
    for (int i = 0; i < count; i++) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
                customers[i]->customerName, customers[i]->rank,
                customers[i]->order_amount, customers[i]->point);
    }
    printf("----------------------------------------\n");
}

int main(void) {
    char name[100];
    int input;

    while (1) {
        printf("고객 정보 관리 프로그램\n");
        printf("1. 고객 정보 추가\n");
        printf("2. 고객 정보 삭제\n");
        printf("3. 고객 정보 수정\n");
        printf("4. 전체 리스트 출력\n");
        printf("5. 종료\n");
        printf("-----------------------------\n");
        printf("선택 : ");
        scanf("%d", &input);

        if (input == 1) {
            printf("고객 이름: ");
            scanf("%s", name);
            printf("고객 등급 (1: VIP, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            int rank;
            scanf("%d", &rank);
            printf("주문량: ");
            int order_amount;
            scanf("%d", &order_amount);
            printf("포인트: ");
            int point;
            scanf("%d", &point);
            
            insertCustomer(createCustomer(name, (Rank)rank, order_amount, point));
        }
        else if (input == 2) {
            printf("삭제할 고객 이름: ");
            scanf("%s", name);
            deleteCustomer(name);
        }
        else if (input == 3) {
            printf("수정할 고객 이름: ");
            scanf("%s", name);
            updateCustomer(name);
        }
        else if (input == 4) {
            printCustomerList();
        }
        else if (input == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else
            printf("잘못된 입력입니다.\n");
    }
    
    return 0;
}