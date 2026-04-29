#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct gang{
    vector<int>member;
    string head;
    int totaltime;
};
int N,K,minute[2001]={0},visited[2001]={0};
unordered_map<string,int>M1;
unordered_map<int,string>M2;
vector<int>v[2001];
gang g[2001];
int num_of_gang=0;
void dfs(int cur){
    if(visited[cur])return;
    visited[cur]=1;
    g[num_of_gang].member.emplace_back(cur);
    g[num_of_gang].totaltime+=minute[cur];
    for(int each:v[cur]){
        dfs(each);
    }
}
bool comp(gang x,gang y){
    return x.head<y.head;
}
int main(){
    int i,j,k,l;
    cin>>N>>K;
    for(i=0;i<N;i++){
        string s1,s2;
        cin>>s1>>s2>>l;
        if(M1.count(s1))j=M1[s1];
        else{
            j=M1[s1]=M1.size()+1;
            M2[j]=s1;
        }
        if(M1.count(s2))k=M1[s2];
        else{
            k=M1[s2]=M1.size()+1;
            M2[k]=s2;
        }
        minute[j]+=l;
        minute[k]+=l;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    for(i=0;i<=M1.size();i++){
        if(!visited[i]){
            g[num_of_gang].member.clear();
            g[num_of_gang].totaltime=0;
            dfs(i);
            if(g[num_of_gang].member.size()>2&&g[num_of_gang].totaltime>K*2){
                int maxminute=0;
                int head;
                for(int each:g[num_of_gang].member){
                    if(minute[each]>maxminute){
                        maxminute=minute[each];
                        head=each;
                    }
                }
                g[num_of_gang].head=M2[head];
                num_of_gang++;
            }
        }
    }
    sort(g,g+num_of_gang,comp);
    cout<<num_of_gang<<endl;
    for(i=0;i<num_of_gang;i++){
        cout<<g[i].head<<' '<<g[i].member.size()<<endl;
    }
}