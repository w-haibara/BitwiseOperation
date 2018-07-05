#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    printf("%d\n",a);

    a = a & 0b1;
    printf("%d\n",a);
    
    a = a & 0b10;
    printf("%d\n",a);
    
    a = a & 0b100;
    printf("%d\n",a);
    
    return 0;
}
