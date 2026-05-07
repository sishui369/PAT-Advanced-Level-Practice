#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,M,S=0;
    cin>>N;
    int i,j,k,a[100005],b[100005];      //数组的长度必须是固定常量
    b[0]=0;
    for(i=0;i<N;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
        S=S+a[i];
    }
    cin>>M;
    int a1,a2,s1,s2;
    for(i=0;i<M;i++){
        s1=0,s2=0;
        cin>>a1>>a2;
        if(a1>a2)s1=b[a1-1]-b[a2-1];
        else s1=b[a2-1]-b[a1-1];
        s2=S-s1;
        cout<<min(s1,s2)<<endl;
    }
    
}