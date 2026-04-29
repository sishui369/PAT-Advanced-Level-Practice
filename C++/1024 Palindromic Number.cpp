#include<iostream>
using namespace std;
int ispalindromic(int digit[],int len){
    int i;
    for(i=0;i<len;i++){
        if(digit[i]!=digit[len-1-i])break;
    }
    if(i==len)return 1;
    else return 0;
}
int main(){
    int digit[100]={0},rev[100];
    int K,i,j,len;
    long long N;
    cin>>N>>K;
    string s=to_string(N);
    for(i=0;i<s.size();i++)digit[i]=s[s.size()- 1-i]-'0';
    len=s.size();
    j=0;
    while(!ispalindromic(digit,len)){
        for(i=0;i<len;i++)rev[i]=digit[len-1-i];
        int jinwei=0;
        for(i=0;i<len;i++){
            digit[i]+=rev[i]+jinwei;
            if(digit[i]>=10){
                digit[i]-=10;
                jinwei=1;
            }else jinwei=0;
        }
        if(jinwei==1){
            digit[len]=1;
            len++;
        }
        if(++j==K)break;
    }
    for(i=len-1;i>=0;i--)cout<<digit[i];
    cout<<endl;
    cout<<j;
}