#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE {
    int data;
    char name[100];
    struct NODE* link;
} Node;

Node* head = NULL;
Node* tail = NULL;

void creat_array_node(int jumsu, char name[100]) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = jumsu;
    strcpy(newnode->name, name);
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    Node* cur = head;
    Node* prev = NULL;
    
    while (cur != NULL && cur->data >= jumsu) {
        prev = cur;
        cur = cur->link;
    }
    
    if (prev == NULL) {
        newnode->link = head;
        head = newnode;
    }
    else {
        prev->link = newnode;
        newnode->link = cur;
        if (cur == NULL) {
            tail = newnode;
        }
    }
}

void all_print_node() {
    printf("-----------------------\n");
    Node* cur = head;
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->data);
        cur = cur->link;
    }
}

int delete_node(char names[100]){
    Node* prev = NULL;
    Node* cur = head;

    while (cur != NULL) {
        if (strcmp(cur->name, names) == 0) {
            if (prev == NULL) {
                head = cur->link;
            }
            else {
                prev->link = cur->link;
            }

            if (cur == tail) {
                tail = prev;
            }
            
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }

    printf("\n그런 이름은 존재 하지 않습니다.\n\n");
    return 0;
}

int main(void) {
    while (1) {
        int input;
        printf("-----------------------\n");
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &input);

        int jumsu;
        char name[100];
        if (input == 1) {
            printf("학생 이름 : ");
            scanf("%s", name);
            printf("%s의 성적 : ", name);
            scanf("%d", &jumsu);

            creat_array_node(jumsu, name);
        }
        else if (input == 2) {
            printf("제거할 학생 이름 정보 입력 : ");
            scanf("%s", name);

            delete_node(name);
        }
        else if (input == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        
        all_print_node();
    }

    return 0;
}