#include<iostream>
#include<unordered_map>   //哈希查找
#include<algorithm>   //排序
using namespace std;
struct student{
    string ID;
    int grade[4],rank[4];
};
bool comp0(student x,student y){
    return x.grade[0]>y.grade[0];
}
bool comp1(student x,student y){
    return x.grade[1]>y.grade[1];
}
bool comp2(student x,student y){
    return x.grade[2]>y.grade[2];
}
bool comp3(student x,student y){
    return x.grade[3]>y.grade[3];
}
int main(){
    student s[2000];
    int N,M,i,j,k,l;
    cin>>N>>M;
    for(i=0;i<N;i++){
        string temp;
        cin>>temp>>j>>k>>l;
        s[i].ID=temp;
        s[i].grade[0]=(j+k+l)/3;
        s[i].grade[1]=j;
        s[i].grade[2]=k;
        s[i].grade[3]=l;
    }
    sort(s,s+N,comp0);
    for(i=0;i<N;i++){
        if(i==0||s[i].grade[0]!=s[i-1].grade[0])j=i+1;
        s[i].rank[0]=j;
    }
    sort(s,s+N,comp1);
    for(i=0;i<N;i++){
        if(i==0||s[i].grade[1]!=s[i-1].grade[1])j=i+1;
        s[i].rank[1]=j;
    }
    sort(s,s+N,comp2);
    for(i=0;i<N;i++){
        if(i==0||s[i].grade[2]!=s[i-1].grade[2])j=i+1;
        s[i].rank[2]=j;
    }
    sort(s,s+N,comp3);
    for(i=0;i<N;i++){
        if(i==0||s[i].grade[3]!=s[i-1].grade[3])j=i+1;
        s[i].rank[3]=j;
    }
    
    unordered_map<string,int>MAP;
    for(i=0;i<N;i++)MAP[s[i].ID]=i;
    while(M--){
        string temp;
        cin>>temp;
        if(!MAP.count(temp)){
            cout<<"N/A"<<endl;
        }
        else{
            i=MAP[temp];
            int minrank=10000;
            for(j=0;j<4;j++){
                if(minrank>s[i].rank[j])minrank=s[i].rank[j];
            }
            if(minrank==s[i].rank[0]){
                cout<<minrank<<' '<<'A'<<endl;
            }
            else if(minrank==s[i].rank[1]){
                cout<<minrank<<' '<<'C'<<endl;
            }
            else if(minrank==s[i].rank[2]){
                cout<<minrank<<' '<<'M'<<endl;
            }
            else{
                cout<<minrank<<' '<<'E'<<endl;
            }
        }
    }
}