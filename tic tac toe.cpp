#include<iostream>
#include<windows.h>
using namespace std ;
char p1[10];
        char p2[10];
struct demo
{
    int x ,i ,k;
};
void        row1(char array1[3][3]);
    void    row2(char array1[3][3]);
        void row3(char array1[3][3]);
      void   col1(char array1[3][3]);
        void col2(char array1[3][3]);
        void col3(char array1[3][3]);
        void dia1(char array1[3][3]);
        void dia2(char array1[3][3]);
void tic(int , struct demo *,int,char array1[3][3]);
void tac(int , int ,int, char array1[3][3]);
void gotoxy(int x ,int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X=x;
	dwpos.Y=y;
	SetConsoleCursorPosition(hcon , dwpos);
}

int main(void)
{
    demo d[9];
    d[0].x=1  , d[0].i=0  , d[0].k=0;
      d[1].x=2  , d[1].i=0  , d[1].k=1;
        d[2].x=3  , d[2].i=0  , d[2].k=2;
          d[3].x=4  , d[3].i=1  , d[3].k=0;
            d[4].x=5  , d[4].i=1  , d[4].k=1;
              d[5].x=6  , d[5].i=1  , d[5].k=2;
                d[6].x=7  , d[6].i=2  , d[6].k=0;
                  d[7].x=8  , d[7].i=2  , d[7].k=1;
                    d[8].x=9  , d[8].i=2  , d[8].k=2;
    gotoxy(49,0);
    cout<<"TIC TAC TOE";
    char array1[3][3];
    int i,k ;
     gotoxy(50,1);
    for(i=0;i<3;i++)
    {
         for(k=0;k<3;k++)
             array1[i][k]='*';
             cout<<"\n";
    }
          for(i=0;i<3;i++)
        {
              for(k=0;k<3;k++)
               {
                   gotoxy(50+(k*4) , 2+(2*i));
                   cout<<array1[i][k];
               }
        }

        cout<<"\nPLAYER 1 NAME :";
        cin>>p1;
        system("cls");
        cout<<"\nPLAYER 2 NAME :";
        cin>>p2;
         system("cls");
        int count1=1;
    int a1[3][3];
    int p=0;
    for(i=0;i<3;i++)
    {
         for(k=0;k<3;k++)
         {
            if(count1%2!=0)
            {
                cout<<"\n"<<p1<<"'s"<<" Chance : ";
                cout<<"\nyour character is # enter position :  \n";
                count1++;
                cin>>a1[i][k];
                 system("cls");

                tic(a1[i][k],d,count1,array1);
                 if(count1==10)
    {

        cout<<"\nDRAW GAME :";
        exit(1);
    }
            }
            else
                 {
                cout<<"\n"<<p2<<"'s"<<" Chance : ";
                 cout<<"\nyour character is $ enter position :\n";
                count1++;
                 cin>>a1[i][k];
                 system("cls");


                 tic(a1[i][k], d,count1,array1);
                 if(count1==10)
    {

        cout<<"\nDRAW GAME :";
        exit(1);
    }

            }
         }

    }



}
void tic(int m,struct demo *s , int count1,char array1[3][3])
{
     int p,r,o;
    int x=1;
  for( o=0;o<9;o++)
  {
      if(s[o].x==m)
      {
          break;
      }
      x++;
  }
  //int p,int r;
  p=s[o].i;
  r=s[o].k;
  tac(p,r,count1,array1);

}
void tac(int x ,int y,int count1,char array1[3][3])
{
    int i,k;
    if(count1%2!=0)
    array1[x][y]='$';
    else
        array1[x][y]='#';
    for(i=0;i<3;i++)
        {
              for(k=0;k<3;k++)
               {
                   gotoxy(50+((k*4)) , 2+(2*i));
                   cout<<array1[i][k];
               }
        }
        row1(array1);
        row2(array1);
        row3(array1);
        col1(array1);
        col2(array1);
        col3(array1);
        dia1(array1);
        dia2(array1);



}
void row1(char array1[3][3])
{
    if(array1[0][0]!='*'){
    if(array1[0][0]==array1[0][1]&&array1[0][1]==array1[0][2]){
            if(array1[0][0]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[0][0]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void row2(char array1[3][3])
{
    if(array1[1][0]!='*'){
    if(array1[1][0]==array1[1][1]&&array1[1][1]==array1[1][2]){
            if(array1[1][0]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[1][0]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void row3(char array1[3][3])
{
    if(array1[2][0]!='*'){
    if(array1[2][0]==array1[2][1]&&array1[2][1]==array1[2][2]){
            if(array1[2][0]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[2][0]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void col1(char array1[3][3])
{
    if(array1[0][0]!='*'){
    if(array1[0][0]==array1[1][0]&&array1[1][0]==array1[2][0]){
            if(array1[0][0]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[0][0]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void col2(char array1[3][3])
{
    if(array1[0][1]!='*'){
    if(array1[0][1]==array1[1][1]&&array1[1][1]==array1[2][1]){
            if(array1[0][1]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[0][1]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void col3(char array1[3][3])
{
    if(array1[0][2]!='*'){
    if(array1[0][2]==array1[1][2]&&array1[1][2]==array1[2][2]){
            if(array1[0][2]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[0][2]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void dia1(char array1[3][3])
{
    if(array1[1][1]!='*'){
    if(array1[0][0]==array1[1][1]&&array1[1][1]==array1[2][2]){
            if(array1[1][1]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[1][1]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}
void dia2(char array1[3][3])
{
    if(array1[0][2]!='*'){
    if(array1[0][2]==array1[1][1]&&array1[1][1]==array1[2][0]){
            if(array1[1][1]=='#')
      cout<<"\n"<<p1<<" Winner";
    if(array1[1][1]=='$')
      cout<<"\n"<<p2<<" Winner";
    exit(1);
    }
    }

}

