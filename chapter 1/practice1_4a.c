#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    srand(time(NULL));
    int ans = ((rand() % 333) + 1) * 3;
    int num;
    const int max_stage = 10;
    int remin = max_stage;

    printf("猜一个3 ~ 999之间的3的倍数的数。\n");
    do{
        printf("还剩%d次机会，是多少呢：", remin);
        scanf("%d", &num);
        if(num % 3 != 0)
            remin = 0;
        else
            remin--;
        if(num > ans)
            printf("比这个数小！\n");
        else if(num < ans)
            printf("比这个数大！\n");
    }while(num != ans && remin > 0);

    if(num != ans){
        printf("游戏结束！\n");
        printf("正确答案是%d。\n", ans);
    }else{
        printf("回答正确。\n");
        printf("您用了%d次猜中。\n", max_stage - remin);
    }

    return 0;
}