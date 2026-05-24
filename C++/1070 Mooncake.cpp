#include<iostream>
#include<algorithm>
using namespace std;
struct mc
{
    double kc;
    double lr;
    double xjb;
};
bool cmp(mc a,mc b){
    return a.xjb>b.xjb;
}
mc a[1000];
int main(){
    int N;
    double D;
    int i,j,k;
    cin>>N>>D;
    for(i=0;i<N;i++)cin>>a[i].kc;
    for(i=0;i<N;i++)cin>>a[i].lr;
    for(i=0;i<N;i++)a[i].xjb=a[i].lr/a[i].kc;
    sort(a,a+N,cmp);
    double zlr=0;
    for(i=0;i<N;i++){
        if(D-a[i].kc>0){
            zlr=zlr+a[i].lr;
            D-=a[i].kc;
        }else{
            zlr=zlr+a[i].lr*D/a[i].kc;
            break;
        }
    }
    printf("%.2f",zlr);
}