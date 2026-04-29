#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>v[10001];
int visited[10001];
set<int>final_ans;
vector<int>farthest_point;
int maxdis=0;
void dfs(int cur){
    if(visited[cur])return;
    visited[cur]=1;
    for(int i:v[cur]){
        dfs(i);
    }
}
void dfs2(int cur,int depth){
    if(visited[cur])return;
    visited[cur]=1;
    if(depth>maxdis){
        maxdis=depth;
        farthest_point.clear();
        farthest_point.emplace_back(cur);
    }
    else if(depth==maxdis){
        farthest_point.emplace_back(cur);
    }
    for(int i:v[cur]){
        dfs2(i,depth+1);
    }
}
int main(){
    int N,i,j,k;
    cin>>N;
    for(i=1;i<N;i++){
        cin>>j>>k;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    for(i=1;i<=N;i++)visited[i]=0;
    int count=0;
    for(i=1;i<=N;i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    if(count>1){
        cout<<"Error: "<<count<<" components";
    }else{
        for(i=1;i<=N;i++)visited[i]=0;
        dfs2(1,0);
        for(int each:farthest_point)final_ans.insert(each);
        farthest_point.clear();
        maxdis=0;
        for(i=1;i<=N;i++)visited[i]=0;
        dfs2(*final_ans.begin(),0);
        for(int each:farthest_point)final_ans.insert(each);
        for(int each:final_ans){
            cout<<each<<'\n';
        }
    }
}