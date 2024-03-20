#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int human, comp;
int win_num, lose_num, draw_num;
char *hd[] = {"石头", "剪刀", "布"};
int max_stage;
int human_count = 0;
int result_count = 0;
int *human_record;
int *result_record;

//初始处理
void initialize(void){
    win_num = 0;
    lose_num = 0;
    draw_num = 0;

    srand(time(NULL));
    printf("猜拳游戏开始！！\n");

    do{
        printf("要保存的记录数：");
        scanf("%d", &max_stage);
    }while(max_stage <= 0);

    human_record = calloc(max_stage, sizeof(int));
    result_record = calloc(max_stage, sizeof(int));
}

//运行猜拳游戏
void jyanken(void){
    int i;

    comp = rand() % 3;
    do{
        printf("\n石头剪刀布···");
        for(i = 0; i < 3; i++)
            printf(" (%d)%s", i, hd[i]);
        printf("：");
        scanf("%d", &human);
        human_record[human_count++] = human;
    }while(human < 0 || human > 2);
}

//更新胜利/失败/平局次数
void count_num(int result){
    switch(result){
        case 0 : draw_num++;    break;
        case 1 : lose_num++;    break;
        case 2 : win_num++;     break;
    }
}

//显示判断结果
void disp_result(int result){
    switch(result){
        case 0 : puts("平局。");       break;
        case 1 : puts("你输了。");      break;
        case 2 : puts("你赢了。");      break;
    }
}

int main(void){
    int judge;
    int retry = 0;

    initialize();
    do{
        jyanken();

        printf("我出%s，你出%s。\n", hd[comp], hd[human]);
        judge = (human - comp + 3) % 3;
        result_record[result_count++] = judge;
        count_num(judge);
        disp_result(judge);
        retry++;
    }while(retry < max_stage);

    printf("%d胜%d负%d平。\n", win_num, lose_num, draw_num);

    for(int i = 0; i < max_stage; i++){
        printf("------第%2d局------\n", i + 1);
        printf("\t手势：%s\n", hd[human_record[i]]);
        printf("\t");
        disp_result(result_record[i]);
    }

    free(human_record);
    free(result_record);

    return 0;
}