#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {
    char *str;
    char *fst = str;
    char *cnt = str;
    int adress;

    printf("문자를 입력하세요 : ");
    scanf("%s", str);

    while (*cnt != '\0' && *cnt != '\n') {
        if (!isalpha(*cnt) || *cnt == ' ') {
            printf("특수 문자, 공백이 입력 되었습니다. \n문자를 다시 입력하세요 : ");
            scanf("%s", str);
            cnt = str;
            continue;
        }
        cnt++;
    }
    cnt--;
    
    while (fst < cnt) {
        adress = *fst;
        *fst = *cnt;
        *cnt = adress;

        fst++;
        cnt--;
    }

    printf("뒤집힌 문자 : %s\n", str);

    return 0;
}