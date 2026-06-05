#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string s;
    string f[9]={"yi","er","san","si","wu","liu","qi","ba","jiu"};
    stack<string> a;
    bool wan=true;
    int i;
    cin>>s;
    for(i=s.size()-1;i>=0;i--){
        if(s[i]=='-')cout<<"Fu ";
        else if(s[i]=='0'){
            if((!a.empty()&&a.top()!="ling")||i==0)a.push("ling");
        }else{
            if(s.size()-i>8){
                a.push("Yi");
            }else if(s.size()-i>4&&wan){
                a.push("Wan");
                wan=false;
            }
            if((s.size()-i)%4==2)a.push("Shi");
            else if((s.size()-i)%4==3)a.push("Bai");
            else if((s.size()-i)%4==0)a.push("Qian");
            a.push(f[s[i]-'0'-1]);
        }
    }
    cout<<a.top();
    a.pop();
    while(!a.empty()){
        cout<<' '<<a.top();
        a.pop();
    }
}