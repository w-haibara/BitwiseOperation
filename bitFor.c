#include <stdio.h>

int and(int a,int b);
int or(int a,int b);
int not(int a);
int nand(int a, int b);
int nor(int a, int b);
int exor(int a, int b);
void HA(int a,int b,int *s,int *c);
void FA(int a,int b,int pre_c,int *s,int *c);
void binaryAdder(int a[], int b[], int s[], int c);

int main(void){
    static int i;



    return 0;
}

int and(int a, int b){
    int s = a&b;
    return s;
}

int or(int a, int b){
    int s = a|b;
    return s;
}

int not(int a){
    int s;
    if(a==1){
        s=0;
    }else{
        s=1;
    }
    return s;
}

int nand(int a, int b){
    int s = not(a&b);
    return s;
}

int nor(int a, int b){
    int s = not(a|b);
    return s;
}

int exor(int a,int b){
    int s=a^b;
    return s;
}

void HA(int a,int b,int *s,int *c){
    int or1, and1,not1,and2;
    or1 = or(a,b);
    and1 = and(a,b);
    not1 = not(and1);
    and2 = and(or1,not1);

    *s = and2;
    *c = and1; 
}

void FA(int a,int b,int pre_c,int *s,int *c){
int HAs1,HAc1,HAs2,HAc2,or1;
HA(a,b,&HAs1,&HAc1);
HA(HAs1,pre_c,&HAs2,&HAc2);
or1 = or(HAc1,HAc2);
*s = HAs2;
*c = or1;
}$


void add1(int a[],int s[], int c){
    a[0]=0;
    a[1]=0;
    a[2]=0;
    a[3]=0;
    a[4]=0;

    b[0]=1;
    b[1]=0;
    b[2]=0;
    b[3]=0;
    b[4]=0;

    s[0]=0;
    s[1]=0;
    s[2]=0;
    s[3]=0;
    s[4]=0;

    HA(a[0],b[0],&s[0],&c[0]);
    FA(a[1],b[1],s[0],&s[0],&c[0]);

    printf("\nA+B = ");

    for(int i=NUM-1;i>=0;i--){
        printf("%d",s[i]);
    }
    printf("\n");
}