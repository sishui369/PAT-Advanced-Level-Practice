#include<iostream>
#include<string>
using namespace std;
int main(){
    int showed_in_s2[128]={0};
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(char c:s2){
        showed_in_s2[c]=1;
    }
    for(char c:s1){
        if(!showed_in_s2[c]){
            cout<<c;
        }
    }
}