#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
typedef short int si;


inline int rando(bool except[9],si upLim=9){
	unsigned int seed=time(NULL);int rann;
	srand(seed);
	rann=rand()%upLim;
	if (except[rann]==0){
		rando(except,upLim);
	}
		return rann;
}

class sudoku{
      private:
        si sudo[9][9];
      public:
      		
    	void printLs(){
            cout<<"\t1\t2\t3\t4\t5\t6\t7\t8\t9";
            for (int i=1;i<10;i++){
             	cout<<endl<<i<<"\t";
             	for (int j=0;j<9;j++){
             		cout<<sudo[i-1][j]<<"\t";
             	}
        	}
		}
		
		void genPuzzle(int diff){
			bool check[10]={1};
			for (int i=0;i<9;i++){
				for (int j=0;j<9;j++){
					for (int l=0;l<9;l++){
						check[l]=sudo[i][l];
						check[l]=sudo[l][j];	
					}
					for (int x=1;x<4;x++){
						for (int y=1;y<4;y++){
							check[sudo[(((int)((x-1)/3))*3+x)][(((int)((y-1)/3))*3+y)]]=sudo[(((int)((x-1)/3))*3+x)][(((int)((y-1)/3))*3+y)];
						}
					}
					sudo[i][j]=rando(check);
				}
			}
			
		}
};

int main(int argc, char *argv[]){
    sudoku game;si diff;
    cout<<"Welcome to sudoku!What is your name?";
    cout<<"How do you want the game to be difficult?1-5";
    cin>>diff;
    game.genPuzzle(diff);
    system("pause");
    return 0;
}