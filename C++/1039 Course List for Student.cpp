#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
unordered_map<string,set<int>>M;
int main(){
    int N,K,i,j,k;
    cin>>N>>K;
    for(i=0;i<K;i++){
        cin>>j>>k;
        scanf("%d %d",&j,&k);
        while(k--){
            string name;
            cin>>name;
            M[name].insert(j);
        }
    }
    while(N--){
        string name;
        cin>>name;
        cout<<name<<' '<<M[name].size();
        for(int each:M[name]){
            cout<<' '<<each;
        }
        cout<<endl;
    }
}