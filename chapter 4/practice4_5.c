#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

char *color[] = {"白色", "黑色", "红色", "蓝色", "黄色", "绿色", "橙色", "褐色"};

//随机生成4种不同颜色
void make4color(int x[]){
    int i, j, val;

    for(i = 0; i < 4; i++){
        do{
            val = rand() % 9;
            for(j = 0; j < i; j++)
                if(val == x[j])
                    break;
        }while(j < i);
        x[i] = val;
    }
}

//检查输入字符串的有效性
int check(const char s[]){
    if(strlen(s) != 4)
        return 1;                       //字符串长度不为4

    for(int i = 0; i < 4; i++) {
        if(!isdigit(s[i]))
            return 2;                  //包含数字之外的字符
        if((s[i] - '0') > 7)
            return 3;
        for (int j = 0; j < i; j++)
            if (s[i] == s[j])
                return 4;              //含有相同数字
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
        printf("    这些颜色里没有答案颜色。\n");
    else{
        printf("    这些颜色里包括%d个答案颜色。\n", snum);

        if(spos == 0)
            printf("    但是颜色的位置都不一样。\n");
        else
            printf("    其中有%d个颜色的位置是一样的。\n", spos);
    }
}

int main(void){
    int try_no = 0;     //输入次数
    int chk;            //检查已输入的字符串的结果
    int hit;            //位置和颜色都正确的颜色个数
    int blow;           //颜色正确但位置不正确的颜色个数
    int no[4];          //要猜的颜色组合
    char buff[10];      //存放读取的颜色
    clock_t start, end;  //开始、结束时间

    srand(time(NULL));  //设定随机种子

    puts("来玩珠玑妙算吧！");
    puts("请猜4个颜色！");
    puts("其中不包含相同颜色！");
    puts("按提示选择对应颜色序号！");
    puts("不能输入空格字符！\n");

    make4color(no);

    start = clock();

    do{
        do{
            printf("请选择颜色组合（");
            for(int i = 0; i < 8; i++){
                printf("%d：%s，", i, color[i]);
            }
            printf("）:");
            scanf("%s", buff);
            chk = check(buff);

            switch(chk){
                case 1: puts("请确保选择4个颜色！");         break;
                case 2: puts("请选择对应颜色的序号！");        break;
                case 3: puts("请勿输入范围外的数字！");        break;
                case 4: puts("请勿选择相同颜色！");          break;
            }
        }while(chk != 0);
        try_no++;
        judge(buff, no, &hit, &blow);
        print_result(hit + blow, hit);
    }while(hit < 4);
    end = clock();
    printf("用了%d次。\n用时%.1f秒。\n", try_no, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}