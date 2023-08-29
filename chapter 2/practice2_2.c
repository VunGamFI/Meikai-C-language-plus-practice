#include<stdio.h>
#include<time.h>
#include<string.h>

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void gput(const char *s, int speed){
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        printf("%c", s[i]);
        fflush(stdout);
        sleep(speed);
    }
}

int main(void){
    char str[128];
    int time;

    printf("字符串：");
    scanf("%s", str);
    printf("显示速度：");
    scanf("%d", &time);

    gput(str, time);

    return 0;
}