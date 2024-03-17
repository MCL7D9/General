#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#define ranNum rand((unsigned short int)time(NULL))%9
using namespace std;

struct command{
	int x=0;
	int y=0;
	char action=0;
};

void boradcast(string message){
    cout<<message<<endl;
}

void percentageGen(int pro,int total){
    cout<<"Process: [";
    for (int i=0;i<pro;i++){
        cout<<"=";
    }
    for(int j=0;j<(total-pro);j++){
        cout<<"-";
    }
    cout<<"]\n";
}
inline int genRan(int upLim=9){
    unsigned int seed;
    seed=time(NULL);
    srand(seed);
    return rand()%upLim;
}

class sudoku{

    private:
        int sudo[9][9]={{0}}, record[2][20],top=0;
    	bool del(int x,int y){
    		for (int i=0;i<20;i++){
    			if (record[0][i]==x&&record[1][i]==y){
    				sudo[x][y]=0;
    				return 1;
				}
			}
			return 0;
		}

		bool modify(int x,int y,int z){
			for (int i=0;i<20;i++){
				if (record[0][i]==x&&record[1][i]==y){
    				sudo[x][y]=z;
    				return 1;
    			}
    		}
    		return 0;
		}
		int chooseNum(int exc[10]){
		    int num=0;
		    do{
                num=genRan();
		    }while (exc[num]==0);
		    return num+1;
		}
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

    	int genPuzzle(){
    	    int x0=0,y0=0;
    		cout<<"Start Generating Game...\n";
        	for (int i=0;i<9;i++){
         	    for (int j=0;j<9;j++){
                    printLs();
                    cout<<"i= "<<i<<"j="<<j<<endl;
                    int check[10]={1,1,1,1,1,1,1,1,1,1};
            		for (int l=0;l<9;l++){
                        if (sudo[i][l]!=0||sudo[l][j]!=0){
                            check[l]=0;

                        }
            	    }
             		for (int x=0;x<3;x++){
             	    	for (int y=0;y<3;y++){
                    		x0=(int)(i/3)*3+x;
                    		y0=(int)(j/3)*3+y;
                            if (sudo[x0][y0]!=0){
                                check[sudo[x0][y0]]=0;
                            }
                        }
                    }
                    cout<<"Checklist:";
                    for(int a=0;a<10;a++){cout<<check[a];}cout<<endl;
                	sudo[i][j]=chooseNum(check);
                	cout<<"Randoing";
            	}
        	}
        	int aL[10]={1};
        	for (int i=0;i<20;i++){
            	int xx=genRan();
            	int yy=genRan();
            	record[0][top]=xx;
            	record[1][top]=yy;
            	sudo[xx][yy]=0;
        	}
        	cout<<"Puzzle Generated\n";
        	return 0;
    	}

	 	bool judge(){
        	for (int i=0;i<9;i++){
            	for (int j=0;j<9;j++){
                    for (int x=0;x<9;x++){
                        if ((sudo[i][j]==sudo[i][x])||(sudo[i][j]==sudo[x][j])){
                        	cout<<"Fail\n";
                            return 0;
                        }
                    }
                    for (int x=1;x<4;x++){
                        for (int y=1;y<4;y++){
                            if (sudo[i][j]==sudo[((int)((i-1)/3))*3+y][((int)((j-1)/3))*3+x]){
                            	cout<<"Fail\n";
                            	return 0;
                            }
                        }
                    }
               	}
          	}
          	cout<<"Successful\n";
          	return 1;
     	}

		int input(int x,int y,char z){
	 		bool res=false;
     		switch(z){
        		case 'c':
        			res=judge();
        			if (res==1){
        				return 2;
					}
         	   		break;
				case 'x':
					res=del(x,y);
		    		break;
				default:
					res=modify(x,y,z);
					break;
 			}
 			(res==1)?cout<<"Successful\n":cout<<"Fail\n";
      		return res;
    	}
};

int main(){
    sudoku game;string inp;int ans=0;
    cout<<"Welcome to sudoku!\n";
    struct command dataset;
    game.genPuzzle();
    game.printLs();
    for(;;){
    	game.printLs();
    	cout<<"Input Option\n";
        cin>>inp;
        dataset.x=(int)inp[0];
		dataset.y=(int)inp[1];
		dataset.action=inp[2];
		ans=game.input(dataset.x,dataset.y,dataset.action);
		if (ans==2){
			break;
		}
    }
    cout<<"\nYeah buddy\n";
    system("pause");
    return 0;
}
