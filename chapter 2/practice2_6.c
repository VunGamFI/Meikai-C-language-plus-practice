#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    int a, b, c;            //要进行加法运算的数值
    int x;                  //已读取的值
    int n;                  //空白的宽度
    int num;                //抽题
    clock_t start, end, start_total, end_total;     //开始时间
    int result;                //运算结果

    srand(time(NULL));
    printf("扩大视野心算训练现在开始！！\n");
    start_total = clock();
    for(int i = 0; i < 10; i++){
        a = 10 + rand() % 90;
        b = 10 + rand() % 90;
        c = 10 + rand() % 90;
        n = rand() % 17;
        num = rand() % 4;

        switch(num){
            case 0 :
                printf("%d%*s + %*s%d%*s + %*s%d：", a, n, " ", n, " ", b, n, " ", n, " ", c);
                result = a + b + c;
                break;
            case 1 :
                printf("%d%*s + %*s%d%*s - %*s%d：", a, n, " ", n, " ", b, n, " ", n, " ", c);
                result = a + b - c;
                break;
            case 2 :
                printf("%d%*s - %*s%d%*s + %*s%d：", a, n, " ", n, " ", b, n, " ", n, " ", c);
                result = a - b + c;
                break;
            case 3 :
                printf("%d%*s - %*s%d%*s - %*s%d：", a, n, " ", n, " ", b, n, " ", n, " ", c);
                result = a - b - c;
                break;
        }
        start = clock();
        do{
            scanf("%d", &x);
            if(x == result){
                end = clock();
                printf("用时%f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }
            printf("\a回答错误。请重新输入：");
        }while(1);
    }
    end_total = clock();
    printf("运算的平均时间为%f秒。\n", ((double)(end_total - start_total) / CLOCKS_PER_SEC) / 10);

    return 0;
}