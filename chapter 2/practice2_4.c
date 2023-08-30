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

void telop(const char *s, int direction, int speed, int n){
    int cnt = 0;
    int length = strlen(s);
    for(int i = 0; i < n; i++){
        putchar('\r');
        for(int j = 0; j < length; j++){
            if(cnt + j < length)
                putchar(s[cnt + j]);
            else
                putchar(s[cnt + j - length]);
        }
        fflush(stdout);
        sleep(speed);

        if(direction == 0){
            if(cnt < length - 1)
                cnt++;
            else
                cnt = 0;
        }
        else{
            if(cnt > 0)
                cnt--;
            else
                cnt = length - 1;
        }
    }
}

int main(void){
    char output[128];
    int direction;
    int speed;
    int num;

    printf("字符串：");
    scanf("%s", output);
    do{
        printf("滚动方向[0 --- 从右往左 / 1 --- 从左往右]：");
        scanf("%d", &direction);
    }while(direction < 0 || direction > 1);
    printf("滚动速度：");
    scanf("%d", &speed);
    printf("显示次数：");
    scanf("%d", &num);

    telop(output, direction, speed, num);

    return 0;
}