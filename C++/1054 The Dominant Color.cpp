#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<int,int>MAP;
int main(){
    int N,M,total,i,j;
    scanf("%d %d",&N,&M);
    total=N*M;
    for(i=0;i<total;i++){
        scanf("%d",&j);
        MAP[j]++;
        if(MAP[j]>total/2){
            cout<<j;
            return 0;
        }
    }
}