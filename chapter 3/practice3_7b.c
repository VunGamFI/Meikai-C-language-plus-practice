#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int human;
int comp_1;
int comp_2;
int win_no;
int lose_no;
int draw_no;

char *hd[] = {"石头", "剪刀", "布"};

void initialize(void){
        win_no = 0;
        lose_no = 0;
        draw_no = 0;

    srand(time(NULL));

    printf("猜拳游戏现在开始！！\n");
}

void jyanken(void){
    comp_1 = rand() % 3;
    comp_2 = rand() % 3;

    do{
        printf("\n\a石头剪刀布……");
        for(int i = 0; i < 3; i++)
            printf("(%d)%s", i, hd[i]);
        printf("：");
        scanf("%d", &human);
    }while(human > 2 || human < 0);
}

void count_no(int result){
    switch(result){
        case 0 : draw_no++;     break;
        case 1 : lose_no++;     break;
        case 2 : win_no++;      break;
    }
}

void disp_result(int i, int result){
    switch(i){
        case 0 : printf("玩家和电脑1的猜拳结果：");        break;
        case 1 : printf("玩家和电脑2的猜拳结果：");        break;
    }

    switch(result){
        case 0 : printf("平局。\n");       break;
        case 1 : printf("你输了。\n");      break;
        case 2 : printf("你赢了。\n");      break;
    }
}

int main(void){
    int judge[2];
    int count;

    printf("要猜赢几次：");
    scanf("%d", &count);

    initialize();
    do{
        jyanken();
        printf("你出%s，电脑1出%s，电脑2出%s。\n", hd[human], hd[comp_1], hd[comp_2]);
        judge[0] = (human - comp_1 + 3) % 3;
        judge[1] = (human - comp_2 + 3) % 3;
        for(int i = 0; i < 2; i++){
            count_no(judge[i]);
            disp_result(i, judge[i]);
        }
    }while(win_no < count && lose_no < count);
    printf("%d胜%d负%d平。\n", win_no, lose_no, draw_no);

    return 0;
}