#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make4digits(int x[], int num){
    int i, j, val;

    for(i = 0; i < num; i++){
        do{
            val = rand() % 10;
            for(j = 0; j < i; j++)
                if(val == x[j])
                    break;
        }while(j < i);
        x[i] = val;
    }
}

int check(const char s[], int num){
    if(strlen(s) != num)
        return 1;
    for(int i = 0; i < num; i++){
        if(!isdigit(s[i]))
            return 2;
        for(int j = 0; j < i; j++)
            if(s[i] == s[j])
                return 3;
    }
    return 0;
}

void judge(const char s[], const int no[], int *hit, int *blow, int num){
    *hit = *blow = 0;

    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            if(s[i] == '0' + no[j]){
                if (i == j)
                    (*hit)++;
                else
                    (*blow)++;
            }
}

void print_result(int snum, int spos, int num){
    if(spos == num)
        printf("回答正确！！");
    else if(snum == 0)
        printf("    这些数字里没有答案数字。\n");
    else{
        printf("    这些数字里包括%d个答案数字。\n", snum);
        if(spos == 0)
            printf("    但是数字的位置都不一致。\n");
        else
            printf("    其中有%d个数字的位置是一致的。\n", spos);
    }
    printf("\n");
}

int main(void){
    int try_no = 0;
    int chk;
    int hit;
    int blow;
    int no[128];
    char buff[128];
    int num;

    clock_t start, end;

    srand(time(NULL));

    puts("来玩珠玑妙算吧。");
    puts("其中不包含相同数字。");
    puts("请像4307这样连续输入数字。");
    puts("不能输入空格字符。");

    printf("设成几位数：");
    scanf("%d", &num);

    make4digits(no, num);

    start = clock();
    do{
        do{
            printf("请输入：");
            scanf("%s", buff);
            chk = check(buff, num);
            switch (chk){
                case 1 : printf("\a请确保输入%d个字符。", num);      break;
                case 2 : puts("\a请不要输入除了数字之外的字符。");      break;
                case 3 : puts("\a请不要输入相同的数字。");      break;
            }
        }while (chk != 0);
        try_no++;
        judge(buff, no, &hit, &blow, num);
        print_result(hit + blow, hit, num);
        if(hit == num)
            break;
    }while(hit < num);

    end = clock();

    printf("用了%d次。\n用时%.1f秒。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}