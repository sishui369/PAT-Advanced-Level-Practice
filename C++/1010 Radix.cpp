#include<iostream>
using namespace std;
long long trans(char c){
    if(c>='0'&&c<='9')return c-'0';
    else return c-'a'+10;
}
long long translate(string N,long long r){
    long long Sum=0;
    for(long long i=N.size()-1,unit=1;i>=0;i--,unit*=r){
        long long j=trans(N[i]);
        Sum+=j*unit;
    }
    return Sum;
}
int translate2(string N,long long r,long long value){
    long long Sum=0;
    for(long long i=N.size()-1,unit=1;i>=0;i--,unit*=r){
        if(unit>value)return 1;
        long long j=trans(N[i]);
        Sum+=j*unit;
    }
    if(Sum>value)return 1;
    else if(Sum==value)return 0;
    else return -1;
}
int main(){
    string N1,N2;
    long long tag,r1;
    cin>>N1>>N2>>tag>>r1;
    if(tag==2){
        auto a=N1;N1=N2;N2=a;
    }
    long long value=translate(N1,r1);
    long long Maxdigit=0;
    for(char c:N2){
        long long j=trans(c);
        if(j>Maxdigit)Maxdigit=j;
    }
    long long low,high;
    if(translate(N2,Maxdigit+1)==value){
        cout<<Maxdigit+1;
        return 0;
    }
    for(low=Maxdigit+1,high=2147483647;low<=high;){
        long long mid=(low+high)/2;
        int temp=translate2(N2,mid,value);
        if(temp==0){
            cout<<mid;
            return 0;
        }
        if(temp<0)low=mid+1;
        else high=mid-1;
    }
    cout<<"Impossible";
    return 0;
    // for(r2=Maxdigit+1;translate(N2,r2)<value;r2++);
    // if(translate(N2,r2)==value){
    //     cout<<r2;
    //     return 0;
    // }
    // cout<<'Impossible';
    // return 0;
}