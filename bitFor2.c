#include <stdio.h>
int main(){
    int count = 0;

    static int i = 1;//カウント用の変数
    static int c = 1;//カウント番号の桁数
    static int num = 0;//カウント番号
    while(count<256){
        //if(i<1024){
            if(i >= 1073741824){//29カウント毎にiの値をリセット
                i = 1;
                c = c << 1;//iをリセットした回数を記録
            }
            //ここに繰り返す処理を記述する
            

            printf("%d:%d-%d\n",count,c,i);
            i = i << 1;
        //}else{
        //    break;
        //}
        count++;
    }
}
