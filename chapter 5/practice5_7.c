#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;

    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){
    int i, stage, max_stage, level, success;
    int *score;
    clock_t start, end;

    srand(time(NULL));

    printf("加一训练开始！！\n");
    printf("记忆2位的数值。\n");
    printf("请输入原数值减1后的值。\n");

    do{
        printf("要挑战的等级（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    }while(level < LEVEL_MIN || level > LEVEL_MAX);

    score = calloc(max_stage, sizeof(int));
    success = 0;
    start = clock();

    for(stage = 0; stage < max_stage; stage++){
        int ans[LEVEL_MAX];
        int input[LEVEL_MAX];
        int correct = 0;

        printf("\n第%d关卡开始！！\n", stage + 1);

        for(i = 0; i < level; i++){
            ans[i] = rand() % 90 + 10;
            printf("%d ", ans[i]);
        }
        fflush(stdout);
        sleep(300 * level);
        printf("\r%*s\r", 3 * level, " ");
        fflush(stdout);

        for(i = 0; i < level; i++){
            printf("第%d个数：", i + 1);
            scanf("%d", &input[i]);
            while(input[i] == -1){
                if(i > 0) {
                    printf("重新输入第%d个数：", i);
                    scanf("%d", &input[i - 1]);
                    i--;
                }else{
                    printf("重新输入第%d个数：", i + 1);
                    scanf("%d", &input[i]);
                }
            }
        }

        for(i = 0; i < level; i++){
            if(input[i] != ans[i] - 1)
                printf("X  ");
            else {
                printf("O  ");
                correct++;
            }
        }
        putchar('\n');
        for(i = 0; i < level; i++)
            printf("%2d ", ans[i]);
        printf("···答对了%d个。\n", correct);
        score[stage] = correct;
        success += correct;
    }
    end = clock();

    printf("%d个中答对了%d个。\n", level * max_stage, success);

    for(stage = 0; stage < max_stage; stage++)
        printf("第%2d关卡：%d\n", stage + 1, score[stage]);
    printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(score);

    return 0;
}