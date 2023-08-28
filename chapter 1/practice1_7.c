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

    printf("请猜一个0 ~ 999的整数。\n\n");

    stage = 0;
    do{
        printf("还剩%d次机会。是多少呢：", MAX_STAGE - stage);
        scanf("%d", &no);
        num[stage++] = no;

        if(no > ans)
            printf("\a再小一点。\n");
        else if(no < ans)
            printf("\a再大一点。\n");
    }while(no != ans && stage < MAX_STAGE);

    if(no != ans)
        printf("\a很遗憾，正确答案是%d。\n", ans);
    else{
        printf("回答正确。\n");
        printf("您用了%d次猜中了。\n", stage);
    }

    puts("\n--- 输入记录 ---");
    for(int i = 0; i < stage; i++){
        printf(" %2d : %4d", i + 1, num[i]);
        if(num[i] - ans != 0)
            printf(" %+4d\n", num[i] - ans);
        else
            printf(" %4d\n", num[i] - ans);
    }

    return 0;
}