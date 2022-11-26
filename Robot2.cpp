//Position of Robot C++ program
#include<iostream>
using namespace std;
int main()
{
    cout<<"    Aryabhatt's Robot's position:- "<<endl;
    int d=0,x=0,y=0,i;
    char direction='R';
        for(i=1;i<=10;i++)
        {
            switch(direction)
            {
                case 'R':
                    d=d+5;
                    x=x+d;
                    direction='U';
                    cout<<i<<". " <<"("<<x<<", "<<y<<")"<<" d= "<<d<<endl;
                    break;

                case 'U':
                    d=d+5;
                    y=y+d;
                    direction='L';
                    cout<<i <<". " <<"("<<x<<", "<< y<<")"<<" d= "<<d<<endl;
                    break;

                case 'L':
                    d=d+5;
                    x=x-d;
                    direction='D';
                    cout<<i <<". "<<"("<<x<<", "<< y<<")"<<" d= "<<d<<endl;
                    break;

                case 'D':
                    d=d+5;
                    y=y-d;
                    direction='R';
                    cout<<i <<". "<<"("<<x<<", "<< y<<")"<<" d= "<<d<<endl;
                    break;
            }
        }
    return 0;
}
