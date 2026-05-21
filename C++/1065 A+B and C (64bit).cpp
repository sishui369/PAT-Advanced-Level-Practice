#include<iostream>
using namespace std;
int main(){
    int N,i,a,b,c;
    long long A,B,C;
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>A>>B>>C;
        a=A%10;
        b=B%10;
        c=C%10;
        if(A/10>C/10-B/10)cout<<"Case #"<<i<<": true"<<endl;
        else if(A/10==C/10-B/10){
            if(a+b>c)cout<<"Case #"<<i<<": true"<<endl;
            else cout<<"Case #"<<i<<": false"<<endl;
        }
        else cout<<"Case #"<<i<<": false"<<endl;
    }
}
