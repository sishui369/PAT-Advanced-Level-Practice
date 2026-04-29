#include<iostream>
#include<algorithm>
using namespace std;
struct student{
    string ID,name;
    int grade;
};
bool comp1(student&x,student&y){
    return x.ID<y.ID;
}
bool comp2(student&x,student&y){
    if(x.name!=y.name)return x.name<y.name;
    else return x.ID<y.ID;
}
bool comp3(student&x,student&y){
    if(x.grade!=y.grade)return x.grade<y.grade;
    else return x.ID<y.ID;
}
student s[100000];
int main(){
    int N,C,i;
    cin>>N>>C;
    for(i=0;i<N;i++){
        cin>>s[i].ID>>s[i].name>>s[i].grade;
    }
    if(C==1)sort(s,s+N,comp1);
    else if(C==2)sort(s,s+N,comp2);
    else sort(s,s+N,comp3);
    for(i=0;i<N;i++){
        cout<<s[i].ID<<' '<<s[i].name<<' '<<s[i].grade<<endl;
    }
}