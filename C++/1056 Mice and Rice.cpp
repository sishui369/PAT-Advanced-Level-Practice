#include<iostream>
#include<vector>
using namespace std;
int Np,Ng;
int main(){
    cin>>Np>>Ng;
    int i,j,k,l,score[1000],Rank[1000];
    vector<int>players;
    for(i=0;i<Np;i++)cin>>score[i];
    for(i=0;i<Np;i++){
        cin>>j;
        players.emplace_back(j);
    }
    for(int num=Np;num>1;){
        vector<int>nextturn;
        for(i=0;i<num;i+=Ng){
            int jinji=i;
            for(j=i+1;j<i+Ng&&j<num;j++){
                if(score[players[j]]>score[players[jinji]]){
                    jinji=j;
                }
            }
            nextturn.emplace_back(players[jinji]);
            for(j=i;j<i+Ng&&j<num;j++){
                if(j!=jinji){
                    Rank[players[j]]=num/Ng+(num%Ng?1:0)+1;
                }
            }
        }
        players=nextturn;
        num=num/Ng+(num%Ng?1:0);
    }
    Rank[players[0]]=1;
    for(i=0;i<Np;i++){
        if(i!=0)cout<<' ';
        cout<<Rank[i];
    }
}