#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    srand(time(NULL));
    int num_1 = rand();
    int num_2 = rand();
    int count = 1;
    int num;

    int max = num_1 > num_2 ? num_1 : num_2;
    int min = num_1 < num_2 ? num_1 : num_2;

    int ans = (rand() % (max - min + 1)) + min;
    int temp = ans;
    while((temp /= 2) != 0)
        count++;
    int remin = count;

    printf("猜一个%d ~ %d之间的数。\n", min, max);
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
        printf("您用了%d次猜中！\n", count - remin);
    }
    return 0;
}