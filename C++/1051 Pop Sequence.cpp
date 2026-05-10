#include<iostream>
#include<stack>
using namespace std;
int main(){
    int M,N,K,i,j;
    cin>>M>>N>>K;
    while(K--){
        stack<int>S;
        int a[1005];
        for(i=0;i<N;i++)cin>>a[i];
        j=0;//表示push的位置
        for(i=0;i<N;i++){
            //判断a[i]能否被拿出来
            if(a[i]>j){
                while(S.size()<M&&a[i]>j){
                    S.push(j+1);
                    j++;
                }
            }
            if(a[i]>j){
                break;
            }else if(S.top()!=a[i]){
                break;
            }else S.pop();
        }
        if(i==N)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}