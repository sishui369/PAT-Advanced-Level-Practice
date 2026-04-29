#include<iostream>
using namespace std;
void print(int a){
    if(a>9)cout<<(char)('A'+a-10);
    else cout<<a;
}
int main(){
    cout<<'#';
    for(int i=0;i<3;i++){
        int j;
        cin>>j;
        print(j/13);
        print(j%13);
    }
}