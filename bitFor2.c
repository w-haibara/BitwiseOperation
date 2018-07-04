#include <stdio.h>
#define NUM 5
int and (int a, int b);
int or (int a, int b);
int not(int a);
int nand(int a, int b);
int nor(int a, int b);
int exor(int a, int b);
void HA(int a, int b, int *s, int *c);
void FA(int a, int b, int pre_c, int *s, int *c);
void Add();

int main(void) {

    int count = 0;

        static int i = 1;//カウント用の変数
        static int c = 1;//カウント番号の桁数
        static int num = 0;//カウント番号
        while(count<256*1024){
            if(i >= 1073741824){//29カウント毎にiの値をリセット
                i = 1;
                c = c << 1;//iをリセットした回数を記録
            }
            if(1){//i<1024000){
            //ここに繰り返す処理を記述する
            
            printf("%d:%d-%d\n",count,c,i);
            i = i << 1;
            }else{
                break;
            }
        }
    return 0;
}

/*
    int a[NUM], b[NUM];
    int c[NUM], s[NUM];
    a[0] = 1;
    a[1] = 1;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    printf("A = ");
    for (int i = NUM - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n");

    b[0] = 1;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    printf("B = ");
    for (int i = NUM - 1; i >= 0; i--) {
        printf("%d", b[i]);
    }
    printf("\n");


    HA(a[0], b[0], &s[0], &c[0]);
    printf("HA : s0 = %d , c0 = %d\n", s[0], c[0]);
    for (int i = 1; i < NUM; i++) {
        FA(a[i], b[i], c[i - 1], &s[i], &c[i]);
        printf("FA : s%d = %d , c%d = %d\n", i, s[i], i, c[i]);
    }

    printf("\nA+B = ");
    for (int i = NUM - 1; i >= 0; i--) {
        printf("%d", s[i]);
    }
    printf("\n");




    return 0;
}


int and (int a, int b) {
    int s = a & b;
    return s;
}

int or (int a, int b) {
    int s = a | b;
    return s;
}

int not(int a) {
    int s;
    if (a == 1) {
        s = 0;
    } else {
        s = 1;
    }
    return s;
}

int nand(int a, int b) {
    int s = not(a & b);
    return s;
}

int nor(int a, int b) {
    int s = not(a | b);
    return s;
}

int exor(int a, int b) {
    int s = a ^ b;
    return s;
}

void HA(int a, int b, int *s, int *c) {
    int or1, and1, not1, and2;
    or1 = or (a, b);
    and1 = and (a, b);
    not1 = not(and1);
    and2 = and (or1, not1);
    
    *s = and2;
    *c = and1;
}

void FA(int a, int b, int pre_c, int *s, int *c) {
    int HAs1, HAc1, HAs2, HAc2, or1;
    HA(a, b, &HAs1, &HAc1);
    HA(HAs1, pre_c, &HAs2, &HAc2);
    or1 = or (HAc1, HAc2);
    
    *s = HAs2;
    *c = or1;
}

void Add(int a[], int b[], int s[], int c) {

    HA(a[0], b[0], &s[0], &c[0]);
    printf("HA : s0 = %d , c0 = %d\n", s[0], c[0]);
    for (int i = 1; i < NUM; i++) {
        FA(a[i], b[i], c[i - 1], &s[i], &c[i]);
        printf("FA : s%d = %d , c%d = %d\n", i, s[i], i, c[i]);
    }
    
    printf("\nA+B = ");
    for (int i = NUM - 1; i >= 0; i--) {
        printf("%d", s[i]);
    }
    printf("\n");

}

*/
