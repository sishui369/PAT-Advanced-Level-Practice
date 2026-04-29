#include<iostream>
#include<vector>
using namespace std;
int Cmax,N,Sp,M;
int bike[501],dis[501][501],mindis_to[501];
vector<int>v[501];
vector<int>path;
int final_dis=999999,final_send,final_take;
vector<int>final_ans;
void dfs(int curstation,int curdis,int cursend,int curtake){
    if(curdis>mindis_to[curstation])return;
    path.emplace_back(curstation);
    if(curstation==Sp){
        if(curdis<final_dis||(curdis==final_dis&&cursend<final_send)||(curdis==final_dis&&cursend==final_send&&curtake<final_take)){
            final_ans=path;
            final_dis=curdis;
            final_send=cursend;
            final_take=curtake;
        }
    }else{
        if(curdis<mindis_to[curstation])mindis_to[curstation]=curdis;
        for(int i:v[curstation]){
            if(curtake+bike[i]<Cmax/2){
                dfs(i,curdis+dis[curstation][i],cursend+Cmax/2-curtake-bike[i],0);
            }else{
                dfs(i,curdis+dis[curstation][i],cursend,curtake-Cmax/2+bike[i]);
            }
        }
    }
    
    path.pop_back();
}
int main(){
    int i,j,k;
    cin>>Cmax>>N>>Sp>>M;
    for(i=1;i<=N;i++)cin>>bike[i];
    while(M--){
        cin>>i>>j>>k;
        v[i].emplace_back(j);
        v[j].emplace_back(i);
        dis[i][j]=dis[j][i]=k;
    }
    for(i=0;i<=N;i++)mindis_to[i]=99999;
    dfs(0,0,0,0);
    cout<<final_send<<' ';
    cout<<final_ans[0];
    for(i=1;i<final_ans.size();i++){
        cout<<"->"<<final_ans[i];
    }
    cout<<' '<<final_take;
}