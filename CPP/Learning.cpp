#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int sum(int,int);
int sub(int,int);
int mul(int,int);
int main(){
    int ls[5]={},x,y,(*ptr[])(int,int)={sum,sub,mul},mod;
    cout<<"Selectc Mode"<<endl;
    cin>>mod>>x>>y;
    switch (mod)
    {
    case 0:
        cout<<ptr[0](x,y);
        break;
    case 1:
        cout<<ptr[1](x,y);
        break;
    case 2:
        cout<<ptr[2](x,y);
        break;
    default:
        break;
    }

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