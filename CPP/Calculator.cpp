#include <cstdlib>
#include <iostream>
using namespace std;
int sum(int,int);
int sub(int,int);
int mul(int,int);
int main(){
    int x,y,mod,(*ptr)(int,int);
    cout<<"Input Mode";
    cin>>mod>>x>>y;
    switch (mod)
    {
    case 0:
        ptr=sum;
        break;
    case 1:
        ptr=sub;
        break;
    case 2:
        ptr=mul;
        break;
    case 3:
        break;
    default:
        break;
    }
    cout<<ptr(x,y);
    return 0;
}
int sum(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}