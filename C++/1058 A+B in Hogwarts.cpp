#include<iostream>
using namespace std;
int main(){
    long long g1, s1, k1;
    long long g2, s2, k2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
    k1+=k2;
    if(k1/29){
        k1=k1%29;
        s1++;
    }
    s1+=s2;
    if(s1/17){
        s1=s1%17;
        g1++;
    }
    g1+=g2;
    cout<<g1<<'.'<<s1<<'.'<<k1;
}