#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct person{
    string name;
    int age;
    int money;
};
bool comp(person x,person y){
    if(x.money!=y.money)return x.money>y.money;
    if(x.age!=y.age)return x.age<y.age;
    return x.name<y.name;
}
person p[100000];
int N,K;
int main(){
    int i,j,k;
    cin>>N>>K;
    for(i=0;i<N;i++){
        cin>>p[i].name>>p[i].age>>p[i].money;
    }
    sort(p,p+N,comp);
    int M,Min,Max;
    for(i=1;i<=K;i++){
        cin>>M>>Min>>Max;
        cout<<"Case #"<<i<<":"<<endl;
        k=0;
        for(j=0;j<N;j++){
            if(p[j].age<=Max&&p[j].age>=Min){
                cout<<p[j].name<<' '<<p[j].age<<' '<<p[j].money<<endl;
                k++;
                if(k==M)break;
            }
        }
        if(!k)cout<<"None\n";
    }
}