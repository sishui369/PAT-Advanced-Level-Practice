#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct customer{
    int come_time,process_time,leave_time=0;
};
bool comp(customer x,customer y){
    return x.come_time<y.come_time;
}
customer c[10001];
int main(){
    int i,j,N,K;
    cin>>N>>K;
    for(i=0;i<N;i++){
        int hh,mm,ss,process_time;
        char d;
        cin>>hh>>d>>mm>>d>>ss>>process_time;
        c[i].come_time=hh*3600+mm*60+ss;
        c[i].process_time=process_time*60;
        if(c[i].process_time>3600)c[i].process_time=3600;
    }
    c[N].come_time=9999999;
    sort(c,c+N,comp);
    int next=0;
    int window[K];
    for(i=0;i<K;i++)window[i]=-1;
    double Sum=0;
    for(int Time=28800;c[next].come_time<=61200;Time++){
        for(i=0;i<K;i++){
            if(window[i]>=0){
                j=window[i];
                if(c[j].leave_time==Time){
                    window[i]=-1;
                }
            }
        }
        for(i=0;i<K;i++){
            if(window[i]==-1){
                if(c[next].come_time<=Time){
                    window[i]=next;
                    next++;
                }
            }
        }
        for(i=0;i<K;i++){
            if(window[i]>=0){
                j=window[i];
                if(c[j].leave_time==0){
                    Sum+=Time-c[j].come_time;
                    c[j].leave_time=Time+c[j].process_time;
                }
            }
        }
    }
    printf("%.1f",Sum/next/60);
}