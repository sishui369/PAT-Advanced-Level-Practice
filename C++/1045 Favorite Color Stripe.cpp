#include<iostream>
using namespace std;
int Rank[201]={0};
int main(){
    int i,j,k;
    int N;
    cin>>N;
    int M,favorate[201];//喜欢的颜色顺序
    cin>>M;
    for(i=1;i<=M;i++){
        cin>>favorate[i];
        Rank[favorate[i]]=i;
    }
    int L,old[10000],long_max=0;//队列
    cin>>L;
    for(i=1;i<=L;i++)cin>>old[i];
    int longest_endwith[201]{0};//喜欢颜色为尾的最大队列长度
    for(i=1;i<=L;i++){
        if(!Rank[old[i]])continue;
        j=Rank[old[i]];
        int max=0;
        for(k=0;k<=j;k++)if(longest_endwith[k]>max)max=longest_endwith[k];
        longest_endwith[j]=max+1;
    }   
    int ans=0;
    for(i=1;i<=M;i++){
        if(ans<longest_endwith[i])ans=longest_endwith[i];
    }
    cout<<ans;

}