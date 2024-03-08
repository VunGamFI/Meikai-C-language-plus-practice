#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;

    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){
    int i, stage;
    int level;
    int success = 0;
    clock_t start, end;

    srand(time(NULL));
    printf("数值记忆训练\n");

    do{
        printf("要挑战的等级（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    }while(level < LEVEL_MIN || level > LEVEL_MAX);

    int choice = rand() % level + 1;

    printf("来记忆一个%d位的数值吧。\n", level);
    printf("请输入从左往右数第%d位的数字。\n", choice);
    fflush(stdout);
    sleep(1000);

    start = clock();
    for(stage = 0; stage < MAX_STAGE; stage++){
        char quest[LEVEL_MAX + 1];
        char input[LEVEL_MAX * 2];
        char ans[2];

        quest[0] = '1' + rand() % 9;
        for(i = 1; i < level; i++)
            quest[i] = '0' + rand() % 10;
        quest[level] = '\0';

        ans[0] = quest[choice - 1];
        ans[1] = '\0';

        printf("%s", quest);
        fflush(stdout);
        sleep(125 * level);

        printf("\r%*s\r请输入：", level, " ");
        scanf("%s", input);

        if(strcmp(input, ans) != 0)
            printf("回答错误。\n");
        else{
            printf("回答正确。\n");
            success++;
        }
    }
    end = clock();

    printf("%d次中答对了%d次。\n", MAX_STAGE, success);
    printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}