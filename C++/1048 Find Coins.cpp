#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,M,i,j,k,a[100001];
    cin>>N>>M;
    for(i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    for(i=0,j=N-1;i<j;){
        int Sum=a[i]+a[j];
        if(Sum==M){
            cout<<a[i]<<' '<<a[j];
            return 0;
        }
        if(Sum<M){
            i++;
        }else{
            j--;
        }
    }
    cout<<"No Solution";
}