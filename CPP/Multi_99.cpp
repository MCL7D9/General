#include <iostream>
using namespace std;
int main(){
    cout<<"99 Multi Table"<<"\n";
    int x,y,z;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cout<<i<<"x"<<j<<"="<<i*j;
            if ((i*j)<10)cout<<"  ";else cout<<" ";
   
        }
        cout<<"\n";
    }
    system("pause");
    return 0;
}