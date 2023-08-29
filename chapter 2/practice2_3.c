#include<stdio.h>
#include<string.h>
#include<time.h>

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void bput(const char *s, int d, int e, int n){
    int length = strlen(s);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < length; j++) {
            printf("%c", s[j]);
            fflush(stdout);
            sleep(d);
            printf("\b \b");
            fflush(stdout);
            sleep(e);
        }
    }
}

int main(void){
    char output[128];
    int show;
    int hide;
    int num;

    printf("字符串：");
    scanf("%s", output);
    printf("显示时间：");
    scanf("%d", &show);
    printf("消失时间：");
    scanf("%d", &hide);
    printf("显示次数：");
    scanf("%d", &num);

    bput(output, show, hide, num);

    return 0;
}