#include<iostream>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    cout<<n<<"=";
    if(n==1){
        cout<<1;
        return 0;
    }
    for(i=2;i<=n;i++){
        int t=0;
        while(n%i==0){
            t++;
            n=n/i;
        }
        if(t>0)cout<<i;
        if(t>1)cout<<"^"<<t;
        if(t>0&&n!=1)cout<<"*";
    }
}