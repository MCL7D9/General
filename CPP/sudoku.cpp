#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;


inline int rando(bool except[9]={1},int upLim=9){
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
          int sudo[9][9], record[81]={0},top=0;
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
		
     void genPuzzle(){
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
          for (int i=0;i<20;i++){
               sudo[rando()][rando()]=0;
          }
          print("Puzzle Generated")
     }

     bool judge(){
          for (int i=0;i<9;i++){
               for (int j=0;j<9;j++){
                    for (int x=0;x<9;x++){
                         if ((sudo[i][j]==sudo[i][x])||(sudo[i][j]==sudo[x][j])){
                              return 0;
                         }
                    }
                    for (int x=1;x<4;x++){
                         for (int y=1;y<4;y++){
                              if (sudo[i][j]==sudo[((int)((i-1)/3))*3+y][((int)((j-1)/3))*3+x]){
                                   print("Fail");
                                   return 0;
                              }
                         }
                    }
               }
          }
          print("Success");
          return 1;
     }

     bool input(bool a,int x,int y,int z){
          char *x0,*y0;string temp;
          x0=itoa(x);y0=itoa(y)
          if (a==1&&sudo[x][y]==0){
               sudo[x][y]=z;
               record[top]=temp;
               top++;
               return 1;
          }
          if (a==1){
               for (int i=0;i<top;i++){
                    if record[i]==temp(
                         sudo[x][y]=z;
                         record[top]=temp;
                         top++;
                         return 1;
                    )
               }
          }
          if (a==0){
               for (int i=0;i<top;i++){
                    if record[i]==temp(
                         sudo[x][y]=0;
                         return 1;
                    )
               }
          }
          return 0;
     }
};

int main(int argc, char *argv[]){
    sudoku game;int diff;string inp;
    cout<<"Welcome to sudoku!";
    game.genPuzzle();
    while ()
    {
          cin>>inp;bool ans;
          if (inp[2]==c){
               bool res;
               res=game.judge();
               if (res==1){
                    print("You have won!");
                    return 0;
               }else{
                    print("Wrong. Please Modify Your Answer");
                    continue;
               }

          }
          ans=input(inp[0],inp[1],inp[2]);
          if (ans==1){
               print("Number Modified Successfully");
               game.printLs();
          }else{
               print("Number Update Failed");
               game.printLs();
          }

    }
    
    system("pause");
    return 0;
}