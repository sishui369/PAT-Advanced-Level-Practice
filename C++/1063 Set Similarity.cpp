#include<iostream>
#include<unordered_set>
#include<cstdio>
using namespace std;
unordered_set<int>S[51];
int main(){
    int N,M,K,i,j,k;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>M;
        while(M--){
            cin>>k;
            S[i].insert(k);
        }
    }
    cin>>K;
    while (K--)
    {
        cin>>i>>j;
        i--; j--;
        unordered_set<int>temp;
        for(int each:S[i])temp.insert(each);
        for(int each:S[j])temp.insert(each);
        int Nt=temp.size();
        int Nc=S[i].size()+S[j].size()-Nt;
        printf("%.1f%%\n",100.0*Nc/Nt);
    }
    return 0;
}