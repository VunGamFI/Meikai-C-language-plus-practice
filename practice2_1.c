#include<time.h>
#include<stdio.h>

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){
    clock_t c;
    for(int i = 10; i > 0; i--){
        printf("\r%2d", i);
        fflush(stdout);
        sleep(1000);
    }
    printf("\r\aFIRE!!\n");

    c = clock();
    printf("程序开始运行后经过了%d时%d分%d秒。\n",
           (int)((double)c / CLOCKS_PER_SEC) / 3600,
           (int)(((double)c / CLOCKS_PER_SEC) / 3600) % 60,
           (int)((double)c / CLOCKS_PER_SEC) % 60);

    return 0;
}