#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;
}

//生成level不重复的英文字母
void makeword(const int level, char quest[]){
    int i, j;
    const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "abcdefghijklmnopqrstuvwxyz";

    for(i = 0; i < level; i++){
        do{
            quest[i] = ltr[rand() % strlen(ltr)];
            for(j = 0; j < i; j++)
                if(quest[i] == quest[j])
                    break;
        }while(j < i);
        quest[level] = '\0';
    }
}

int main(void){
    int stage;
    int level;
    int success = 0;
    clock_t start, end;
    char quest[LEVEL_MAX + 1];

    srand(time(NULL));

    printf("英文字母记忆训练\n");
    do{
        printf("要挑战的等级（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    }while(level < LEVEL_MIN || level > LEVEL_MAX);

    printf("来记忆%d个英文字母吧。\n", level);

    start = clock();
    for(stage = 0; stage < MAX_STAGE; stage++){
        int input;

        makeword(level, quest);
        printf("%s", quest);
        fflush(stdout);
        sleep(125 * level);

        int choice = rand() % level;

        printf("\r%*s\r请输入%c的位置：", level, " ", quest[choice]);
        fflush(stdout);
        scanf("%d", &input);

        if(input != (choice + 1))
            printf("回答错误。\n");
        else{
            printf("回答正确。\n");
            success++;
        }
    }
    end = clock();

    printf("%d次答对了%d次。\n", MAX_STAGE, success);
    printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}