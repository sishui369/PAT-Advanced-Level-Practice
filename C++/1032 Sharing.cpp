#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct node{
    char data;
    int next;
};
node n[100000];
int main(){
    int h1,h2,N,i,j;
    cin>>h1>>h2>>N;
    while(N--){
        cin>>i>>n[i].data>>n[i].next;
    }
    vector<int>v1,v2;
    for(i=h1;i!=-1;i=n[i].next){
        v1.emplace_back(i);
    }
    for(i=h2;i!=-1;i=n[i].next){
        v2.emplace_back(i);
    }
    for(i=v1.size()-1,j=v2.size()-1;i>=0&&j>=0&&v1[i]==v2[j];i--,j--);
    if(i==v1.size()-1)printf("-1");
    else printf("%05d",v1[i+1]);
}