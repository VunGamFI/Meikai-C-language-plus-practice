#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define MAX_STAGE 10

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;

    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){
    int stage;
    int success = 0;        //答对数量
    clock_t start, end;

    srand(time(NULL));

    printf("来记录一个4位的数值吧。\n");
    printf("请输入与原数值顺序相反的数。\n");

    start = clock();

    for(stage = 0; stage < MAX_STAGE; stage++){
        int input;
        int ans = 0;
        int quest = rand() % 9000 + 1000;
        int temp = quest;

        for(int i = 0; i < 4; i++){
            ans += ((temp % 10) * (int)pow(10, 3 - i));
            temp /= 10;
        }

        printf("%d", quest);
        fflush(stdout);
        sleep(500);

        printf("\r请输入：");
        fflush(stdout);
        scanf("%d", &input);

        if(input == ans){
            printf("回答正确。\n");
            success++;
        }else
            printf("回答错误。\n");
    }
    end = clock();

    printf("%d次中答对了%d次。\n", MAX_STAGE, success);
    printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
