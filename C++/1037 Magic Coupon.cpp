#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N1,N2,i,j,Sum=0;
    int a[100000],b[100000];
    cin>>N1;
    for(i=0;i<N1;i++)cin>>a[i];
    cin>>N2;
    for(i=0;i<N2;i++)cin>>b[i];
    sort(a,a+N1);
    sort(b,b+N2);
    for(i=j=0;i<N1&&j<N2&&a[i]<0&&b[j]<0;i++,j++){
        Sum+=a[i]*b[j];
    }
    for(i=N1-1,j=N2-1;i>=0&&j>=0&&a[i]>0&&b[j]>0;i--,j--){
        Sum+=a[i]*b[j];
    }
    cout<<Sum;
    return 0;
}