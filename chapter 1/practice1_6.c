#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    srand(time(NULL));
    int choice;
    int max;
    int max_stage;
    int num;

    do{
        printf("请选择难度[(1) 1 ~ 9   (2)1 ~ 99   (3)1 ~ 999   (4)1 ~ 9999：");
        scanf("%d", &choice);
    }while(choice < 1 || choice > 4);

    switch(choice){
        case 1 : max = 9;       max_stage = 4;      break;
        case 2 : max = 99;      max_stage = 8;      break;
        case 3 : max = 999;     max_stage = 10;     break;
        case 4 : max = 9999;    max_stage = 13;     break;
    }
    int remin = max_stage;

    int ans = (rand() % max) + 1;
    printf("猜一个位于1 ~ %d之间的数。\n", max);
    do{
        printf("还剩%d次机会，是多少呢：", remin);
        scanf("%d", &num);
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
        printf("回答正确！\n");
        printf("您用了%d次猜中。\n", max_stage - remin);
    }
    return 0;
}