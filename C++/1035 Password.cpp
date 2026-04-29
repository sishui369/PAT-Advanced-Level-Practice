#include<iostream>
using namespace std;
struct account{
    string s1,s2;
    int modified=0;
};
account a[1000];
int xuyaoxiuzheng(char&c){
    if(c=='0')c='%';
    else if(c=='1')c='@';
    else if(c=='O')c='o';
    else if(c=='l')c='L';
    else return 0;
    return 1;
}
int main(){
    int N,i;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    int count=0;
    for(i=0;i<N;i++){
        for(char&c:a[i].s2){
            if(xuyaoxiuzheng(c)){
                a[i].modified=1;
            }
        }
        if(a[i].modified)count++;
    }
    if(count){
        cout<<count<<endl;
        for(i=0;i<N;i++){
            if(a[i].modified){
                cout<<a[i].s1<<' '<<a[i].s2<<endl;
            }
        }
    }
    else{
        if(N>1){
            cout<<"There are "<<N<<" accounts and no account is modified";
        }else{
            cout<<"There is 1 account and no account is modified";
        }
    }
}