#include<iostream>
#include<string>
using namespace std;
int main(){
    int i,j,k,l;
    string s[54];
    for(i=0;i<52;i++){
        j=i/13;
        if(j==0)s[i]+='S';
        else if(j==1)s[i]+='H';
        else if(j==2)s[i]+='C';
        else s[i]+='D';
        s[i]+=to_string(i%13+1);
    }
    s[52]="J1";
    s[53]="J2";
    int K,gowhere[54];
    cin>>K;
    for(i=0;i<54;i++){
        cin>>gowhere[i];
    }
    while(K--){
        string temp[54];
        for(i=0;i<54;i++){
            temp[gowhere[i]-1]=s[i];
        }
        for(i=0;i<54;i++)s[i]=temp[i];
    }
    for(i=0;i<54;i++){
        if(i)cout<<' ';
        cout<<s[i];
    }
}
