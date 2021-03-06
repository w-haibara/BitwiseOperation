#include <stdio.h>
#define NUM1 6
#define NUM2 5

int NUM3 = NUM1+NUM2-1;
int and(int a,int b);
int or(int a,int b);
int not(int a);
int nand(int a, int b);
int nor(int a, int b);
int exor(int a, int b);
void HA(int a,int b,int *s,int *c);
void FA(int a,int b,int pre_c,int *s,int *c);

int main(void){
    int a[NUM1],b[NUM2];
    int c[NUM2][NUM3];

    int C[NUM3],S[NUM3];
    a[0]=1;
    a[1]=1;
    a[2]=0;
    a[3]=0;
    a[4]=0;
    a[5]=0;
    printf("A = ");
    for(int i=NUM1-1;i>=0;i--){
        printf("%d",a[i]);
    }
    printf("\n");

    b[0]=1;
    b[1]=0;
    b[2]=0;
    b[3]=0;
    b[4]=0;
    printf("B = ");
    for(int i=NUM2-1;i>=0;i--){
        printf("%d",b[i]);
    }
    printf("\n");

    for(int i=0;i<NUM1;i++){
        c[0][i]=a[i];
    }
    for(int i=NUM1;i<NUM3;i++){
        c[0][i]=0;
    }
    printf("C = ");
    for(int i=NUM3-1;i>=0;i--){
        printf("%d",c[0][i]);
    }
    printf("\n");

    int count=0;

    for(int i=0;i<NUM2;i++){
        if(b[i]==1){
            for(int j=i;j<NUM1+i;j++){
                c[count+1][j]=c[count][j-i];
                printf("c[%d] = %d\n",j-i,c[count+1][j-i]);;
            }
            if(i>0){
                for(int j=0;j<i;j++){
                    c[count][j]=0;
                }
            }
            count++;
        }else{
            for(int j=0;j<=i;j++){
                c[count][j]=0;
            }
            count++;
        }
    }





    printf("\nA*B = ");
    for(int i=NUM3-1;i>=0;i--){
        printf("%d",c[NUM2-1][i]);
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
