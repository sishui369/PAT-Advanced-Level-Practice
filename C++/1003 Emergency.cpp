#include<iostream>
#include<vector>
using namespace std;
int N,M,C1,C2;
int num_of_team[500],dis[500][500],mindis[500],paths,teams;
vector<int>v[500];
void dfs(int curcity,int curlen,int curteam)
{
    if(curlen>mindis[curcity])return;
    if(curcity==C2){
        if(curlen==mindis[curcity]){
            paths++;
            if(curteam>teams)teams=curteam;
        }
        else{
            mindis[C2]=curlen;
            paths=1;
            teams=curteam;
        }
    }
    else{
        if(curlen<mindis[curcity])mindis[curcity]=curlen;
        for(int i=0;i<v[curcity].size();i++){
            int j=v[curcity][i];
            dfs(j,curlen+dis[curcity][j],curteam+num_of_team[j]);
        }
    }
}
int main()
{
    int i,j,k,l;
    cin>>N>>M>>C1>>C2;
    for(i=0;i<N;i++)cin>>num_of_team[i];
    for(i=0;i<M;i++){
        cin>>j>>k>>l;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
        dis[j][k]=dis[k][j]=l;
    }
    for(i=0;i<N;i++)mindis[i]=100000000;
    dfs(C1,0,num_of_team[C1]);
    cout<<paths<<' '<<teams;
}