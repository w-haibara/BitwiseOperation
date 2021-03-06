#include <stdio.h>

int and(int a,int b);
int or(int a,int b);
int not(int a);
int nand(int a, int b);
int nor(int a, int b);
int exor(int a, int b);
void HA(int a,int b,int *s,int *c);
void FA(int a,int b,int pre_c,int *s,int *c);

int main(void){
    int a[5],b[5];
    int c[5],s[6];

    printf("a[0]=");
    scanf("%d",&a[0]);
    printf("a[1]=");
    scanf("%d",&a[1]);
    printf("a[2]=");
    scanf("%d",&a[2]);
    printf("a[3]=");
    scanf("%d",&a[3]);
    printf("a[4]=");
    scanf("%d",&a[4]);

    printf("\n");

    printf("A = ");
    printf("%d",a[4]);
    printf("%d",a[3]);
    printf("%d",a[2]);
    printf("%d",a[1]);
    printf("%d",a[0]);
    printf("\n");

    printf("\n");

    printf("b[0]=");
    scanf("%d",&b[0]);
    printf("b[1]=");
    scanf("%d",&b[1]);
    printf("b[2]=");
    scanf("%d",&b[2]);
    printf("b[3]=");
    scanf("%d",&b[3]);
    printf("b[4]=");
    scanf("%d",&b[4]);
    
    printf("\n");

    printf("B = ");
    printf("%d",b[4]);
    printf("%d",b[3]);
    printf("%d",b[2]);
    printf("%d",b[1]);
    printf("%d",b[0]);
    printf("\n");

    printf("\n");

    HA(a[0],b[0],&s[0],&c[0]);
    printf("HA : s0 = %d , c0 = %d\n",s[0],c[0]);

    FA(a[1],b[1],c[0],&s[1],&c[1]);
    printf("FA : s%d = %d , c%d = %d\n",1,s[1],1,c[1]);
    FA(a[2],b[2],c[1],&s[2],&c[2]);
    printf("FA : s%d = %d , c%d = %d\n",2,s[2],2,c[2]);
    FA(a[3],b[3],c[2],&s[3],&c[3]);
    printf("FA : s%d = %d , c%d = %d\n",3,s[3],3,c[3]);
    FA(a[4],b[4],c[3],&s[4],&c[4]);
    printf("FA : s%d = %d , c%d = %d\n",4,s[4],4,c[4]);


    printf("\nA+B = ");

    printf("%d",s[4]);
    printf("%d",s[3]);
    printf("%d",s[2]);
    printf("%d",s[1]);
    printf("%d",s[0]);
    printf("\n");

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
    a==0? (a=1) : (a=0); 
    return a;
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
}

