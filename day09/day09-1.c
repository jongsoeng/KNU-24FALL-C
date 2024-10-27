#include<stdio.h>

struct v1 {
    int x1, y1, z1;
};
struct v2 {
    int x2, y2, z2;
};

void hap(struct v1 V1, struct v2 V2);
void cha(struct v1 V1, struct v2 V2);
void out(struct v1 V1, struct v2 V2);
void in(struct v1 V1, struct v2 V2);

int main(void) {
    struct v1 V1;
    struct v2 V2;
    int cmd;

    while (1) {
        printf("첫번째 벡터 : ");
        scanf("%d %d %d", &V1.x1, &V1.y1, &V1.z1);
        printf("두번째 벡터 : ");
        scanf("%d %d %d", &V2.x2, &V2.y2, &V2.z2);
        printf("-----------------------\n");
    
        printf("1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 외적\n4. 벡터의 내적\n5. 종료\n");
        printf("-----------------------\n");
        printf("명령 입력 : ");
        scanf("%d", &cmd);

        switch (cmd) {
        case 1:
            hap(V1, V2);
            break;
        case 2:
            cha(V1, V2);
            break;
        case 3:
            out(V1, V2);
            break;
        case 4:
            in(V1, V2);
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            break;
        }
    }
}

void hap(struct v1 V1, struct v2 V2) {
    int x = V1.x1 + V2.x2;
    int y = V1.y1 + V2.y2;
    int z = V1.z1 + V2.z2;

    printf("벡터의 합은 V1 + V2 = (%d, %d, %d)\n", x, y, z);
}
void cha(struct v1 V1, struct v2 V2) {
    int x = V1.x1 - V2.x2;
    int y = V1.y1 - V2.y2;
    int z = V1.z1 - V2.z2;

    printf("벡터의 차는 V1 - V2 = (%d, %d, %d)\n", x, y, z);
}
void out(struct v1 V1, struct v2 V2) {
    int x = V1.x1 * V2.x2;
    int y = V1.y1 * V2.y2;
    int z = V1.z1 * V2.z2;
    int result = x + y + z;

    printf("벡터의 내적은 V1 . V2 = %d\n", result);
}
void in(struct v1 V1, struct v2 V2) {
    int x = (V1.y1 * V2.z2) - (V1.z1 * V2.y2);
    int y = (V1.z1 * V2.x2) - (V1.x1 * V2.z2);
    int z = (V1.x1 * V2.y2) - (V1.y1 * V2.x2);

    printf("벡터의 외적은 x = %d, y = %d, z = %d\n", x, y, z);
}