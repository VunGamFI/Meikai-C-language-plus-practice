#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    srand(time(NULL));
    const int stage = 20;
    int ans = rand() % 1999 - 999;
    int num;
    int remin = stage;

    printf("请输入一个 -999 ~ 999的整数。\n");

    do{
        printf("还剩%d次机会，是多少呢：", remin);
        scanf("%d", &num);
        remin--;

        if(num > ans)
            printf("\a比这个数小。\n");
        else if(num < ans)
            printf("\a比这个数大。\n");
    }while(num != ans && remin > 0);

    if(num != ans)
        printf("\a很遗憾，正确答案是%d。\n", ans);
    else{
        printf("回答正确。\n");
        printf("您用列%d次猜中了。\n", stage - remin);
    }

    return 0;
}