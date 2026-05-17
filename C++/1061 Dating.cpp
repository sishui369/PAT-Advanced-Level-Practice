#include<iostream>
#include<string>
using namespace std;
string weekday[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int i,j;

    int day;
    for(i=0;;i++){
        if(s1[i]>='A'&&s1[i]<='G'&&s1[i]==s2[i])break;
    }
    day=s1[i]-'A';

    int hour;
    for(j=i+1;;j++){
        if((isdigit(s1[j])||(s1[j]>='A'&&s1[j]<='N'))&&s1[j]==s2[j])break;
    }
    if(isdigit(s1[j]))hour=s1[j]-'0';
    else hour=s1[j]-'A'+10;

    int minute;
    for(i=0;;i++){
        if(isalpha(s3[i])&&s3[i]==s4[i])break;
    }
    minute=i;
    
    cout<<weekday[day];
    printf(" %02d:%02d",hour,minute);
}