#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int key,next;
};
node n[100000];
vector<int>v;
bool comp(int x,int y){
    return n[x].key<n[y].key;
}
int main(){
    int N,head,i,j,k;
    cin>>N>>head;
    while(N--){
        int address;
        cin>>address;
        cin>>n[address].key>>n[address].next;
    }
    for(i=head;i>=0;i=n[i].next){
        v.emplace_back(i);
    }
    sort(v.begin(),v.end(),comp);
    cout<<v.size();
    for(i=0;i<v.size();i++){
        printf(" %05d\n%05d %d",v[i],v[i],n[v[i]].key);
    }
    cout<<' '<<-1;
}