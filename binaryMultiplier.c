#include <stdio.h>
#define NUM 5
int and(int a,int b);
int or(int a,int b);
int not(int a);
int nand(int a, int b);
int nor(int a, int b);
int exor(int a, int b);
void HA(int a,int b,int *s,int *c);
void FA(int a,int b,int pre_c,int *s,int *c);

int main(void){
    int a[NUM],b[NUM];
    int c[NUM],s[NUM];
    a[0]=1;
    a[1]=1;
    a[2]=0;
    a[3]=0;
    a[4]=0;
    printf("A = ");
    for(int i=NUM-1;i>=0;i--){
        printf("%d",a[i]);
    }
    
    int n = 5;
    printf("\nn = %d",n);

    printf("\n\n");

    for(int i=0;i<NUM;i++){
        b[i]=a[i];
    }

    for(int i=2;i<=n;i++){
        HA(a[0],b[0],&s[0],&c[0]);
        printf("HA : s0 = %d , c0 = %d\n",s[0],c[0]);
        for(int j=1;j<NUM;j++){
            FA(a[j],b[j],c[j-1],&s[j],&c[j]);
            printf("FA : s%d = %d , c%d = %d\n",j,s[j],j,c[j]);
        }   

        printf("A*%d = ",i);
        for(int j=NUM-1;j>=0;j--){
            printf("%d",s[j]);
        }
        printf("\n\n");

        for(int j=0;j<NUM;j++){
            b[j]=s[j];
            if(i!=n){
                s[j]=0;
            }
        }
    }

    printf("\nA*n = ");
    for(int i=NUM-1;i>=0;i--){
        printf("%d",s[i]);
    }
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
}
