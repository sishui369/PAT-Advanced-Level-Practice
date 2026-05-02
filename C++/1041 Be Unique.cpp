#include<iostream>
using namespace std;
int main(){
    int marked[10001]={0};
    int N,a[100000],i,j;
    cin>>N;
    for(i=0;i<N;i++)cin>>a[i];
    for(i=0;i<N;i++){
        j=a[i];
        marked[j]++;
    }
    for(i=0;i<N;i++){
        if(marked[a[i]]==1){
            cout<<a[i];
            return 0;
        }
    }
    cout<<"None";
}