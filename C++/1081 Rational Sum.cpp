#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    int n,i,j,k;
    long long a,b,fz=0,fm=1;
    bool t=true;
    scanf("%d",&n);
    while(n--){
        scanf("%lld/%lld", &a, &b);
        if(b==fm)fz+=a;
        else{
            fz=fz*b+a*fm;
            fm*=b;
        }
        for(i=2;i<=fm&&i<=fz;){
        if(fz%i==0&&fm%i==0){
            fz/=i;
            fm/=i;
        }else i++;
    }
    }
    if(fz<0){t=false;
            fz*=-1;
    }
    
    int count=fz/fm;
    fz=fz%fm;
    if(!t)cout<<'-';
    if(count!=0&&fz!=0){
        if(t)cout<<count<<' '<<fz<<'/'<<fm;
        else cout<<count<<" -"<<fz<<'/'<<fm;
    }
    else if(count!=0)cout<<count;
    else if(fz!=0)cout<<fz<<'/'<<fm;
    else cout<<'0';
}