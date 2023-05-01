#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int guess,seed,target;
    for (int i=0;i<8;i++){
    seed=time(NULL);
    srand(seed);
    target=rand();
    cout<<target<<"\n";}
    return 0;
}
