#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct player{
    int come_time,play_time,serve_time,leave_time;
    int isvip;
};
struct table{
    int count=0,serve=-1;
    int isvip=0;
    
};
bool comp(player x,player y){
    return x.come_time<y.come_time;
}
void printtime(int Time){
    printf("%02d:%02d:%02d ",Time/3600,Time%3600/60,Time%60);
}
player p[100000];
table t[101];
vector<int>v;
int main(){
    int N,K,M,i,j;
    cin>>N;
    for(i=0;i<N;i++){
        int hh,mm,ss;
        char c;
        cin>>hh>>c>>mm>>c>>ss>>p[i].play_time>>p[i].isvip;
        p[i].come_time=hh*3600+mm*60+ss;
        p[i].play_time*=60;
        if(p[i].play_time>7200)p[i].play_time=7200;
    }
    cin>>K>>M;
    while(M--){
        cin>>i;
        t[i].isvip=1;
    }
    sort(p,p+N,comp);
    queue<int>q1,q2;
    int cursor=0;
    for(int Time=28800;Time<75600;Time++){
        for(i=1;i<=K;i++){
            if(t[i].serve>=0){
                j=t[i].serve;
                if(p[j].leave_time==Time){
                    t[i].serve=-1;
                }
            }
        }
        while(cursor<N&&p[cursor].come_time==Time){
            q1.push(cursor);
            if(p[cursor].isvip)q2.push(cursor);
            cursor++;
        }
        while(q2.size()&&p[q2.front()].serve_time!=0)q2.pop();
        for(i=1;i<=K;i++){
            if(!t[i].isvip)continue;
            if(t[i].serve<0){
                if(q2.size()){
                    j=q2.front();
                    v.emplace_back(j);
                    t[i].serve=j;
                    t[i].count++;
                    p[j].serve_time=Time;
                    p[j].leave_time=Time+p[j].play_time;
                    while(q2.size()&&p[q2.front()].serve_time!=0)q2.pop();
                }
            }
        }
        while(q1.size()&&p[q1.front()].serve_time!=0)q1.pop();
        for(i=1;i<=K;i++){
            if(t[i].serve<0){
                if(q1.size()){
                    j=q1.front();
                    v.emplace_back(j);
                    t[i].serve=j;
                    t[i].count++;
                    p[j].serve_time=Time;
                    p[j].leave_time=Time+p[j].play_time;
                    while(q1.size()&&p[q1.front()].serve_time!=0)q1.pop();
                }
            }
        }
    }
    for(int each:v){
        printtime(p[each].come_time);
        printtime(p[each].serve_time);
        cout<<(p[each].serve_time-p[each].come_time+30)/60;
        cout<<endl;
    }
    for(i=1;i<=K;i++){
        cout<<t[i].count;
        if(i<K)cout<<' ';
    }
}