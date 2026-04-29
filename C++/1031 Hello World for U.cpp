#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=s.size();
    int n1,n2,n3;
    n1=n3=(l+2)/3;
    n2=l+2-n1-n1;
    int i,j,k;
    for(i=0;i<n1-1;i++){
        cout<<s[i];
        for(j=0;j<n2-2;j++)cout<<' ';
        cout<<s[l-1-i]<<endl;
    }
    for(j=0;j<n2;j++){
        cout<<s[i];
        i++;
    }
}