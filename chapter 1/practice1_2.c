#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    srand(time(NULL));
    int straw = rand() % 71;

    printf("今年运势为：");
    if(straw >= 0 && straw < 8)
        printf("大吉\n");
    else if(straw >= 8 && straw < 22)
        printf("中吉\n");
    else if(straw >= 22 && straw < 39)
        printf("小吉\n");
    else if(straw >= 39 && straw < 64)
        printf("吉\n");
    else if(straw >= 64 && straw < 67)
        printf("末吉");
    else if(straw >= 67 && straw < 69)
        printf("凶\n");
    else
        printf("大凶\n");

    return 0;
}