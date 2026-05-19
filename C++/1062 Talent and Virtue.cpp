#include<iostream>
#include<algorithm>
using namespace std;
struct person{
    int ID;
    int de,cai,total;
    int level;
};
bool comp(person x,person y){
    if(x.level!=y.level)return x.level<y.level;
    else if(x.total!=y.total)return x.total>y.total;
    else if(x.de!=y.de)return x.de>y.de;
    return x.ID<y.ID;
}
person p[100000];
int main(){
    int N,L,H,i,j,k,l;
    int M=0;
    cin>>N>>L>>H;
    for(i=0;i<N;i++){
        cin>>j>>k>>l;
        p[i].ID=j;
        p[i].de=k;
        p[i].cai=l;
        p[i].total=k+l;
        if(k<L||l<L)p[i].level=5;
        else if(k>=H&&l>=H)p[i].level=1;
        else if(k>=H)p[i].level=2;
        else if(l<H&&k>=l)p[i].level=3;
        else p[i].level=4;
        if(p[i].level<5)M++;
    }
    sort(p,p+N,comp);
    cout<<M<<endl;
    for(i=0;i<M;i++){
        cout<<p[i].ID<<' '<<p[i].de<<' '<<p[i].cai<<endl;
    }
}