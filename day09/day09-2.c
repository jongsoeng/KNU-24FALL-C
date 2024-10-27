#include<stdio.h>

struct PtrInfo {
    int ID;
    char name[100];
    int money;
};

void printProduct(struct PtrInfo p[5]);

int main(void) {
    struct PtrInfo p[5];
    printProduct(p);

    return 0;
}

void printProduct(struct PtrInfo p[5]) {
    int index = 0;

    for (int i = 0; i < 5; i++) {
        printf("상품 정보를 입력하세요 (입력 중단은 ID에 0입력)\n");
        printf("상품 ID : ");
        scanf("%d", &p[i].ID);
        if (p[i].ID == 0) {
            break;
        }
        printf("상품명 : ");
        scanf("%s", p[i].name);
        printf("가격 : ");
        scanf("%d", &p[i].money);
        printf("\n");

        index++;
    }

    printf("<<입력된 상품 목록>>\n");
    for (int j = 0; j < index; j++) {
        printf("상품 ID : %d\n상품명 : %s\n가격 : %d\n\n", p[j].ID, p[j].name, p[j].money);
    }
}