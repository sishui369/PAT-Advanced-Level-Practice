#include<iostream>
#include<vector>
using namespace std;
int N,M,maxlevel,num_of_eachlevel[100];
vector<int>child[100];
void dfs(int curID,int curlevel){
    if(curlevel>maxlevel)maxlevel=curlevel;
    if(child[curID].size()>0){
        for(auto x:child[curID]){
            dfs(x,curlevel+1);
        }
    }
    else{
        num_of_eachlevel[curlevel]++;
    }
}
int main(){
    int i,j,k;
    cin>>N>>M;
    for(i=0;i<M;i++){
        int ID,K;
        cin>>ID>>K;
        while(K--){
            cin>>j;
            child[ID].emplace_back(j);
        }
    }
    dfs(1,1);
    for(i=1;i<=maxlevel;i++){
        if(i>1)cout<<' ';
        cout<<num_of_eachlevel[i];
    }
}
