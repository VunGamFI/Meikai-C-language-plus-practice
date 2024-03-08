#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// 随机生成4个不同数字
void make4digit(int x[]){
    int i, j, val;

    for(i = 0; i < 4; i++){
        do{
            val = rand() % 10;
            for(j = 0; j < i; j++)
                if(val == x[j])
                    break;
        }while(j < i);
        x[i] = val;
    }
}

//检查输入数字的有效性
int check(const char s[]){
    if(strlen(s) != 4)
        return 1;               //字符串长度不为4

    for(int i = 0; i < 4; i++){
        if(!isdigit(s[i]))
            return 2;           //包含数字之外的字符
        for(int j = 0; j < i; j++)
            if(s[i] == s[j])
                return 3;       //含有相同数字
    }
    return 0;       //检查通过
}

//输入判断
void judge_input(const int judge){
    switch(judge){
        case 1: puts("请确保输入4个数字！");     break;
        case 2: puts("请不要输入除数字之外的字符！"); break;
        case 3: puts("请不要输入相同的数字！");    break;
    }
}

//玩家
void human(const char s[]){
    do{
        printf("请输入：");
        scanf("%s", s);

        judge_input(check(s));

    }while(check(s) != 0);
}

void judge(const char s[], const int no[], int *hit, int *blow){
    *hit = *blow = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(s[i] == '0' + no[j]){
                if(i == j)
                    (*hit)++;
                else
                    (*blow)++;
            }
}

void print_result(int snum, int spos){
    if(spos == 4)
        printf("回答正确！");
    else if(snum == 0)
        printf("    这些数字里没有答案数字。\n");
    else{
        printf("    这些颜色里包含%d个答案数字。\n", snum);

        if(spos == 0)
            printf("    但是数字的位置都不一样。\n");
        else
            printf("    其中有%d个数字的位置是一样的。\n", spos);
    }
}

int main(void){
    int human_try = 0, robot_try = 0;       //输入次数
    int human_hit, robot_hit;               //位置和数字都正确的数字个数
    int human_blow, robot_blow;             //数字正确但位置不正确的数字个数
    int human_num[4], robot_num[4];         //玩家出题/机器出题
    int human_ans[10], robot_ans[10];       //回答数字

    puts("来玩珠玑妙算吧！");
    puts("请猜4个数字！");
    puts("其中不包含相同数字！");
    puts("不能输入空格字符！");
    puts("玩家和电脑轮流答题！\n");

    make4digit(robot_num);      //电脑出题

    puts("————玩家出题————");
    human(human_num);            //玩家出题

    do{
        puts("\n————玩家回合————");
        human(human_ans);   //玩家回答
        human_try++;
        judge(human_ans, robot_num, &human_hit, &human_blow);
        print_result(human_hit + human_blow, human_hit);

        puts("\n————电脑回合————");
        make4digit(robot_ans);
        robot_try++;
        judge(robot_ans, human_num, &robot_hit, &robot_blow);
        print_result(robot_hit + robot_blow, robot_hit);

    }while(human_hit < 4 || robot_hit < 4);

    if(human_hit == 4)
        puts("您赢了！");
    else
        puts("您输了！");

    return 0;
}