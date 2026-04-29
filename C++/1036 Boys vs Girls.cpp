#include<iostream>
using namespace std;
struct student{
    string name,gender,ID;
    int grade;
};
student s[1000];
int main(){
    int i,N,haveboy=0,havegirl=0;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>s[i].name>>s[i].gender>>s[i].ID>>s[i].grade;
        if(s[i].gender=="M")haveboy=1;
        else havegirl=1;
    }
    int max_girl_grade=-1;
    int girl_index;
    if(havegirl){
        for(i=0;i<N;i++){
            if(s[i].gender=="F"&&s[i].grade>max_girl_grade){
                max_girl_grade=s[i].grade;
                girl_index=i;
            }
        }
        cout<<s[girl_index].name<<' '<<s[girl_index].ID<<endl;
    }else cout<<"Absent\n";
    int min_boy_grade=101;
    int boy_index;
    if(haveboy){
        for(i=0;i<N;i++){
            if(s[i].gender=="M"&&s[i].grade<min_boy_grade){
                min_boy_grade=s[i].grade;
                boy_index=i;
            }
        }
        cout<<s[boy_index].name<<' '<<s[boy_index].ID<<endl;
    }else cout<<"Absent\n";
    if(havegirl&&haveboy)cout<<s[girl_index].grade-s[boy_index].grade;
    else cout<<"NA";
}