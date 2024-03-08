#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10

int answer(const int quest, int choice) {
    int ans;
    int temp = quest;

    for (int i = 0; i < 5 - choice; i++){
        ans = temp % 10;
        temp /= 10;
    }

    return ans;
}

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;

    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){
    int stage;
    int success = 0;
    int ans;
    clock_t start, end;

    srand(time(NULL));

    printf("来记忆一个4位数的数值吧。\n");

    int choice = rand() % 4 + 1;

    printf("请输入从左往右数第%d位的数字。\n", choice);
    fflush(stdout);
    sleep(1000);

    start = clock();
    for(stage = 0; stage < MAX_STAGE; stage++){
        int input;
        int quest = rand() % 9000 + 1000;

        ans = answer(quest, choice);

        printf("%d", quest);
        fflush(stdout);
        sleep(500);

        printf("\r请输入：");
        scanf("%d", &input);

        if(input != ans)
            printf("回答错误！\n");
        else{
            printf("回答正确！\n");
            success++;
        }
    }

    end = clock();

    printf("%d次中答对了%d次。\n", MAX_STAGE, success);
    printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}