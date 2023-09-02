#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;
int count = 0;
int times;

char *hd[] = {"石头", "剪刀", "布 "};

void initialize(void){
    win_no = 0;
    lose_no = 0;
    draw_no = 0;

    srand(time(NULL));
    printf("猜拳游戏开始！！\n");
}

void jyanken(void){
    comp = rand() % 3;

    do{
        printf("剪刀石头布……");
        for(int i = 0; i < 3; i++)
            printf(" (%d)%s", i, hd[i]);
        printf("：");
        scanf("%d", &human);
    }while(human < 0 || human > 2);
}

void count_no(int result){
    switch(result){
        case 0 : draw_no++;     break;
        case 1 : lose_no++;     break;
        case 2 : win_no++;      break;
    }
}

void disp_result(int result){
    switch(result){
        case 0 : puts("平局。");       break;
        case 1 : puts("你输了。");      break;
        case 2 : puts("你赢了。");      break;
    }
}

int main(void){
    int judge;
    int retry;
    int comp_input[128];
    int human_input[128];
    int result[128];

    printf("要猜赢几次：");
    scanf("%d", &times);

    initialize();
    do{
        jyanken();
        printf("我出%s，你出%s。\n", hd[comp], hd[human]);
        comp_input[count] = comp;
        human_input[count] = human;
        count++;
        judge = (human - comp + 3) % 3;
        result[count] = judge;
        count_no(judge);
        disp_result(judge);
    }while(win_no < times && lose_no < times);
    printf("%d胜%d负%d平。\n", win_no, lose_no, draw_no);

    puts("\n      游戏记录      ");
    printf("玩家          电脑\n");
    puts("-------------------");
    for(int i = 0; i < count; i++){
        printf("%s          %s\n", hd[human_input[i]], hd[comp_input[i]]);
        disp_result(result[i]);
    }

    return 0;
}