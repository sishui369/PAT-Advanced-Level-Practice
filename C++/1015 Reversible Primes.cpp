#include<iostream>
using namespace std;
int isprime(int n){
    if(n<2)return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int translate(string N,int r){
    int Sum=0;
    for(int i=N.size()-1,unit=1;i>=0;i--,unit*=r){
        Sum+=unit*(N[i]-'0');
    }
    return Sum;
}
int main(){
    while(1){
        int n,r;
        cin>>n>>r;
        if(n<0)break;
        if(!isprime(n))cout<<"No\n";
        else{
            string N="";
            while(n!=0){
                N+='0'+n%r;
                n/=r;
            }
            int value=translate(N,r);
            if(isprime(value))cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}