#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;

char *hd[] = {"石头", "剪刀", "布"};

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
        printf("\n\a石头剪刀布……");
        for(int i = 0; i < 3; i++)
            printf("(%d)%s", i, hd[i]);
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
    int count;

    initialize();
    printf("要猜赢几次：");
    scanf("%d", &count);

    do{
        jyanken();
        printf("我出%s，你出%s。\n", hd[comp], hd[human]);
        judge = (human - comp + 3) % 3;
        count_no(judge);
        disp_result(judge);
    }while(win_no < count && lose_no < count);
    printf(win_no == count ? "你赢了。\n" : "我赢了。\n");
    printf("%d胜%d负%d平。\n", win_no, lose_no, draw_no);

    return 0;
}