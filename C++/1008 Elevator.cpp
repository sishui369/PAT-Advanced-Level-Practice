#include<iostream>
using namespace std;
int main()
{
    int current=0,N,Time;
    cin>>N;
    while(N--){
        int towhere;
        cin>>towhere;
        if(towhere>current)Time+=6*(towhere-current)+5;
        else if(towhere<current)Time+=4*(current-towhere)+5;
        else Time+=5;
        current=towhere;
    }
    cout<<Time;
}