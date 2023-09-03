#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make4digits(int x[]){
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

int check(const char s[]){
    if(strlen(s) != 4)
        return 1;
    for(int i = 0; i < 4; i++){
        if(!isdigit(s[i]))
            return 2;
        for(int j = 0; j < i; j++)
            if(s[i] == s[j])
                return 3;
    }
    return 0;
}

void judge(const char s[], const int no[], int *hit, int *blow){
    *hit = *blow = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(s[i] == '0' + no[j]){
                if (i == j)
                    (*hit)++;
                else
                    (*blow)++;
            }
}

void print_result(int snum, int spos){
    if(spos == 4)
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

void tips(const char s[], const int no[], int *blow){
    int x;
    int count = 0;
    int num = 0;
    int temp[*blow];

    printf("提示列表：\n");
    printf("    [1]开头的第一个字符。\n");
    printf("    [2]数字和位置都相同的数字中最前面的1个字符。\n");
    printf("    [3]数字正确但位置不对的数字中最末尾的1个字符。\n");
    printf("请选择需要的提示：");
    scanf("%d", &x);

    switch(x){
        case 1 : printf("%d\n", no[0]);     break;
        case 2 :
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(s[i] == '0' + no[j])
                        if(i == j){
                            temp[num] = no[j];
                            num++;
                        }
            printf("%d\n", temp[0]);
            break;
        case 3 :
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(s[i] == '0' + no[j])
                        if(i != j){
                            count++;
                            if(count == *blow)
                                printf("%d\n", no[j]);
                            break;
                        }
            break;
    }
}

int main(void){
    int i, ans;
    int try_no = 0;
    int chk;
    int hit;
    int blow;
    int no[4];
    char buff[10];
    int count = 10;
    int tip = 3;
    clock_t start, end;

    srand(time(NULL));

    puts("来玩珠玑妙算吧。");
    puts("请猜4个数字。");
    puts("其中不包含相同数字。");
    puts("请像4307这样连续输入数字。");
    puts("不能输入空格字符。");
    printf("输入次数为%d次。\n\n", count);

    make4digits(no);
    start = clock();

    for(i = 0; i < count; i++){
        if(try_no % 3 == 0 && tip > 0 && try_no > 0){
            printf("需要提示吗……[0]否   [1]是：");
            scanf("%d", &ans);
            if(ans == 1){
                tips(buff, no, &blow);
                tip--;
            }
        }
        do{
            printf("请输入：");
            scanf("%s", buff);
            chk = check(buff);
            switch (chk){
                case 1 : puts("\a请确保输入4个字符。");      break;
                case 2 : puts("\a请不要输入除了数字之外的字符。");     break;
                case 3 : puts("\a请不要输入相同的数字。");     break;
            }
        }while (chk != 0);
        try_no++;
        judge(buff, no, &hit, &blow);
        print_result(hit + blow, hit);
        if(hit == 4)
            break;
    }

    end = clock();

    if(i == count && hit != 4){
        printf("可输入次数用完，游戏失败。\n");
        printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
    }
    else
        printf("用了%d次。\n用时%.1f秒。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}