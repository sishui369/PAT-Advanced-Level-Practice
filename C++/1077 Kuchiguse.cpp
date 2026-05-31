#include<iostream>
#include<string>
using namespace std;
int main(){
    string s[100];
    int N,i,j,k;
    cin>>N;
    getchar();
    for(i=0;i<N;i++){
        getline(cin,s[i]);
    }
    for(i=1;;i++){
        for(j=0;j<N;j++){
            if(s[j].size()<i)break;
        }
        if(j<N)break;
        bool signal=true;
        char c=s[0][s[0].size()-i];
        for(j=1;j<N;j++){
            char d=s[j][s[j].size()-i];
            if(d!=c)signal=false;
        }
        if(signal==false){
            break;
        }
    }
    if(i==1){
        cout<<"nai";
    }else{
        for(j=s[0].size()-i+1;j<s[0].size();j++){
            cout<<s[0][j];
        }
    }
}