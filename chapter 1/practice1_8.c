#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10

int main(void){
    int stage;
    int no;
    int num[MAX_STAGE];

    srand(time(NULL));
    int ans = rand() % 1000;

    printf("请猜一个0 ~ 999的整数。%d\n\n", ans);

    int i = 0;
    for(; i < MAX_STAGE; i++){
        printf("还剩%d次机会。是多少呢：", MAX_STAGE - i);
        scanf("%d", &no);
        num[i] = no;

        if(no > ans)
            printf("\a再小一点。\n");
        else if(no < ans)
            printf("\a再大一点。\n");
        else {
            i++;
            break;
        }
    }

    if(no != ans)
        printf("\a很遗憾，正确答案是%d。\n", ans);
    else{
        printf("回答正确。\n");
        printf("您用了%d次猜中了。\n", i);
    }

    puts("\n--- 输入记录 ---");
    for(int j = 0; j < i; j++)
        printf(" %2d : %4d %+4d\n", j + 1, num[j], num[j] - ans);

    return 0;
}