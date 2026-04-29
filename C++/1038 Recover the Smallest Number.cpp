#include<iostream>
#include<algorithm>
using namespace std;
bool comp(string x,string y){
    return x+y<y+x;
}
int main(){
    int N,i;
    string s[10000];
    cin>>N;
    for(i=0;i<N;i++)cin>>s[i];
    sort(s,s+N,comp);
    string ans="";
    for(i=0;i<N;i++)ans+=s[i];
    for(i=0;ans[i]=='0';i++);
    if(i==ans.size())cout<<"0";
    while(i<ans.size()){
        cout<<ans[i];
        i++;
    }
}