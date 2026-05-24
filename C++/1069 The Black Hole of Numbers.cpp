#include<iostream>
#include<algorithm>
using namespace std;
int M;
int a[4];
int main(){
    cin>>M;
    do{
        a[0]=M%10;
        a[1]=M/10%10;
        a[2]=M/100%10;
        a[3]=M/1000;
        sort(a,a+4);
        int big,small;
        big=a[3]*1000+a[2]*100+a[1]*10+a[0];
        small=a[3]+a[2]*10+a[1]*100+a[0]*1000;
        printf("%04d - %04d = %04d\n",big,small,big-small);
        M=big-small;
    }while(M&&M!=6174);
}