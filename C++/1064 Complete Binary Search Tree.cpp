#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int a[1001];
vector<int>inorder;
vector<int>num;
void inordertraverse(int i){
    if(i>N)return;
     inordertraverse(i*2);
     inorder.emplace_back(i);
     inordertraverse(i*2+1);
}
int main(){
    int i,j,k;
    cin>>N;
    inordertraverse(1);
    for(i=0;i<N;i++){
        cin>>j;
        num.emplace_back(j);
    }
    sort(num.begin(),num.end());
    for(i=0;i<N;i++){
        a[inorder[i]]=num[i];
    }
    queue<int>Q;
    Q.push(1);
    while(Q.size()){
        i=Q.front();
        Q.pop();
        if(i>1)cout<<' ';
        cout<<a[i];
        if(i*2<=N)Q.push(i*2);
        if(i*2+1<=N)Q.push(i*2+1);
    }

}