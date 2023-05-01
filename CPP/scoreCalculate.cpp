/*Thanks to Kimmy for the orignal version of the code 
Link: https://www.onlinegdb.com/mXYTlA1Lg
By MCL7D9*/
#include <iostream>
#include <string>
using namespace std;

int main() {   
     START:
     int score[17]={0},final=y=1;
     string subjects[15]={"Eng1","Eng2","Eng3","Eng4","Eng Dict","Chin1","Chin2","Chin3","Math","Sci","C.Hist","Hist","Geog","Eng","Chin"};
     cout<<"Which modes do you wanna choose,exam or CT?(1 for exam,2 for CT,3 for term mark)"<<endl;cin>>y;
     cout<<"Enter your mark in xx/100"<<endl;
     switch(y){
          case 1:
          for (int i=0;i<13;i++){
               cout<<"Your "<<subjects[i]<<" result is: ";
               cin>>score[i];
          }
               final=(score[0]*0.4+score[1]*0.34+score[2]*0.06+score[3]*0.14+score[4]*0.06 )*0.25+(score[5]*0.45+score[6]*0.45+score[7]*0.1+score[8]+score[9])*0.17+(score[10]+score[11]+score[12])*0.08;
               break;
          case 2:
               for (int i=8;i<15;i++){
                    cout<<"Your "<<subjects[i]<<" result is ";
                    cin>>score[i];
               }
               final=score[13]*0.25+(score[14]+score[8]+score[9])*0.18+(score[10]+score[11]+score[12])*0.07;
               break;
          case 3:
               cout<<"Enter your CT mark"<<endl;
               cin>>score[15];
               cout<<"Enter your exam mark "<<endl; 
               cin>>score[16];
               final=score[16]*0.7+score[15]*0.3;
               break;
          default : 
               cout<<"I don't understand your command"<<endl;
               goto START;
          }
          if (final<101){
          cout <<"The average is :"<<final<< endl;
     } 
     cout<<"Ur Asian parent:";
     if(final==100){
          cout<<"U cheat"<<endl;
     }else if(final>=90){
          cout<<"average only"<<endl;
     }else if(final>=80){
          cout<<"bad"<<endl;
     }else if(final>=70){
          cout<<"clumsy"<<endl;
     }else if(final>=60){
          cout<<"dont sleep at my home"<<endl;
     }else if(final>=50){
          cout<<"ever u shouldnt exist"<<endl;
     }else if(final<50){
          cout<<"ffffffff"<<endl;
     }else{
          cout<<"error"<<endl;
     }
     return 0;
}    





















