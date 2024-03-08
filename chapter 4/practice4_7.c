#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//返回数字的位数
int digit_num(const int x){
    int count = 0;
    int temp = x;

    do{
        temp /= 10;
        count++;
    }while(temp > 0);

    return count;
}

//将数字各位数存储进数组并更改重复数值
void change(int x[], const int digit){
    int i, j, val;

    //将数字各位数存储进数组
    val = digit;

    for(i = 0; i < digit_num(digit); i++){
        x[i] = val % 10;
        val /= 10;
    }

    //更改重复数值
    for(i = 0; i < digit_num(digit); i++){
        do{
            for(j = 0; j < i; j++)
                if(x[j] == x[i]) {
                    x[j] = rand() % 10;
                    break;
                }
        }while(j < i);
    }
}

//创建新的数值
int newnum(const int x[], const int digit){
    int temp = 0;

    for(int i = 0; i < digit_num(digit); i++){
        temp += (x[i] * (int)pow(10, i));
    }
    return temp;
}

int main(void){
    int input, ans[3];

    srand(time(NULL));
    int digit = rand() % 1000;

    change(ans, digit);

    int num = newnum(ans, digit);

    printf("请猜一个0～999的整数。\n\n");
    do{
        printf("是多少呢：");
        scanf("%d", &input);

        if(input > num)
            printf("再小一点！\n");
        else if(input < num)
            printf("再大一点！\n");
    }while(input != num);
    printf("回答正确！\n");

    return 0;
}