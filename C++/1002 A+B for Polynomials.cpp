#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
int main(){
    map<int,double,greater<int>> poly;
    int K,exp;
    double coe;
    cin >> K;
    for(int i=0; i<K;i++){
        cin >>exp>>coe;
        poly[exp]+=coe;
    }
    cin >> K;
    for(int i=0; i<K;i++){
        cin >>exp>>coe;
        poly[exp]+=coe;
    }
    int count =0;
    for(auto& p:poly){
        if(abs(p.second)>1e-6) count++;
    }
    cout << count;
    for(auto& p:poly){
        if(abs(p.second)>1e-6){
            cout << ' '<<p.first<< ' '<<fixed<<setprecision(1)<<p.second;
        }
    }
    return 0;
}