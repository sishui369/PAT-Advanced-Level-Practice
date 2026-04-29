#include<iostream>
#include<vector>
using namespace std;
int N,M,S,D,dis[500][500],cost[500][500];
vector<int>v[500];
int mindis[500];
vector<int>path,final_ans;
int mindistoD=10000000,mincosttoD;
void dfs(int curcity,int curdis,int curcost){
    if(curdis>mindis[curcity])return;
    path.emplace_back(curcity);
    if(curcity==D){
        if(curdis<mindistoD||(curdis==mindistoD&&curcost<mincosttoD)){
            final_ans=path;
            mindistoD=curdis;
            mincosttoD=curcost;
        }
    }else{
        if(curdis<mindis[curcity])mindis[curcity]=curdis;
        for(int each:v[curcity]){
            dfs(each,curdis+dis[curcity][each],curcost+cost[curcity][each]);
        }
    }
    path.pop_back();
}
int main(){
    int i,j,k,l;
    cin>>N>>M>>S>>D;
    while(M--){
        cin>>i>>j>>k>>l;
        v[i].emplace_back(j);
        v[j].emplace_back(i);
        dis[i][j]=dis[j][i]=k;
        cost[i][j]=cost[j][i]=l;
    }
    for(i=0;i<N;i++)mindis[i]=10000000;
    dfs(S,0,0);
    for(int each:final_ans){
        cout<<each<<' ';
    }
    cout<<mindistoD<<' '<<mincosttoD;
}