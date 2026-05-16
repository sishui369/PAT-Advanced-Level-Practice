#include<iostream>
using namespace std;
int main(){
    int N,n,i,j,a_first=-1,a_point=-1,b_first=-1,b_point=-1,a_c,b_c;
    string a,b;
    bool t=true;
    cin>>N>>a>>b;
    n=N;
    for(i=0;i<a.size();i++){
        if(a[i] == '-') i++;
        if(a[i]!='0'&&a[i]!='.'&&a_first==-1)a_first=i;
        if(a[i]=='.')a_point=i;
        if(a_first>=0&&a_point>=0)break;
    }
    if(a_first == -1){
        a_first = 0;
        a_point = 0;
    }
    if(a_point<0){
        a_point=a.size();
        a+='.';
    }
    if(a_first+N+1>a.size()){
        i=a_first+N+1-a.size();
        while(i--)a+='0';
    }
    
    if(a_first-a_point>0){
        a_c=a_point-a_first+1;
    }else{
        a_c=a_point-a_first;
    }
    for(i=0;i<b.size();i++){
        if(b[i] == '-') i++;
        if(b[i]!='0'&&b[i]!='.'&&b_first==-1)b_first=i;
        if(b[i]=='.')b_point=i;
        if(b_first>=0&&b_point>=0)break;
    }
    if(b_first == -1){
        b_first = 0;
        b_point = 0;
    }
    if(b_point<0){
        b_point=b.size();
        b+='.';
    }
    if(b_first+N+1>b.size()){
        i=b_first+N+1-b.size();
        while(i--)b+='0';
    }
    if(b_first-b_point>0){
        b_c=b_point-b_first+1;
    }else{
        b_c=b_point-b_first;
    }
    i=a_first,j=b_first;
    if((a[0]=='-'&&b[0]!='-')||(b[0]=='-'&&a[0]!='-'))t=false;
    else{
        while(n--){
            if(a[i]=='.')i++;
            if(b[j]=='.')j++;
            if(a[i]!=b[j]){
                t=false;
                break;
            }
            i++,j++;
        }
    }
    n=N;
    i=a_first,j=b_first;
    if(a_c==b_c&&t){
        cout<<"YES 0.";
        while(n--){
            if(a[i]=='.')i++;
            cout<<a[i];
            i++;
        }
        cout<<"*10^"<<a_c;
    }else{
        n=N;
        if(b[0]=='-')cout<<"NO -0.";
        else cout<<"NO 0.";
        
        while(n--){
            if(a[i]=='.')i++;
            cout<<a[i];
            i++;
        }
        n=N;
        if(b[0]=='-')cout<<"*10^"<<a_c<<" -0.";
        else cout<<"*10^"<<a_c<<" 0.";
        
        while(n--){
            if(b[j]=='.')j++;
            cout<<b[j];
            j++;
        }
        cout<<"*10^"<<b_c;
    }
    
}