#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int i,j;
    cin>>j;
    while(j--){
        // cin>>i;
        scanf("%d",&i);
        v.emplace_back(i);
    }
    cin>>j;
    while(j--){
        cin>>i;
        v.emplace_back(i);
    }
    sort(v.begin(),v.end());
    cout<<v[(v.size()-1)/2];
}