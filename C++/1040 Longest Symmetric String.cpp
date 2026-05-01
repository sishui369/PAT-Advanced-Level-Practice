#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int i,j,k,maxlength=1;
    string s;
    getline(cin, s);
    int len=s.size();
    if(len==0)cout<<0;
    else{
         for(i=0;i<s.size();i++){
            k=min(i,len-i-1);
            int lengthj=1;
            int lengthf=0;
            j=1;
            while(j<=k){
                if(s[i-j]!=s[i+j])break;
                lengthj=lengthj+2;
                j++;
            }
            j=0;
            int k2 = min(i, len - (i+1) - 1);
            while(j<=k2){
                if(s[i-j]!=s[i+1+j])break;
                lengthf=lengthf+2;
                j++;
            }
            if(maxlength<lengthj)maxlength=lengthj;
            if(maxlength<lengthf)maxlength=lengthf;
        }
        cout<<maxlength;
    }
}