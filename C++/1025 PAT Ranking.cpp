#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

struct testee{
    string ID;
    int score,final_rank,location_number,local_rank;
};
testee t[30000];
bool comp(testee x,testee y){
    return x.score>y.score;
}
bool comp2(testee x,testee y){
    if(x.score!=y.score)return x.score>y.score;
    else return x.ID<y.ID;
}
int main(){
    int N,K,i,j;
    cin>>N;
    for(i=1,j=0;i<=N;i++){
        int start=j;
        cin>>K;
        while(K--){
            cin>>t[j].ID>>t[j].score;
            t[j].location_number=i;
            j++;
        }
        sort(t+start,t+j,comp);
        for(int k=start;k<j;k++){
            if(k==start||t[k].score!=t[k-1].score)t[k].local_rank=k-start+1;
            else t[k].local_rank=t[k-1].local_rank;
        }
    }
    sort(t,t+j,comp2);
    for(int k=0;k<j;k++){
        if(k==0||t[k].score!=t[k-1].score)t[k].final_rank=k+1;
        else t[k].final_rank=t[k-1].final_rank;
    }
    cout<<j<<endl;
    for(int k=0;k<j;k++){
        cout<<t[k].ID<<' '<<t[k].final_rank<<' '<<t[k].location_number<<' '<<t[k].local_rank<<endl;
    }
    
}