#include "iostream"
using namespace std;
int main()
{
    int marks[10][5];
    int i, j,sum=0;

    for(i=0;i<10;i++)  //loop for input
    {
    for(j=0;j<5;j++)
    {
        cout<<"Enter the marks of the student "<<i+1<<" Sem "<<j+1<<" = ";
        cin>>marks[i][j];
        while(marks[i][j]<0 || marks[i][j]>100)
        {
            cout<<"***Invalid input, please try again.***";
            cin>>marks[i][j];
        }
         }
     }
     cout<<endl;

      for(i=0;i<10;i++)   //output loop
     {
         for(j=0;j<5;j++)
         {
             if(marks[i][j]<60)
             {
                 cout<<"Student "<<i+1<<" has scored "<<marks[i][j]<<" in Sem "<<j+1<<"."<<endl;
                cout<<"The student is NOT ELIGIBLE."<<endl<<endl;
                j=5;  //to defy the condition and get out of the block
                sum=0;
                break;
            }
            sum=sum+marks[i][j];
            if(j==4)
            {
                if(sum/5 > 70)
                {
                    cout<<"Student "<<i+1<<" has scored "<<sum/5<<"%"<<"."<<endl;
                    cout<<"The student is ELIGIBLE."<<endl<<endl;
                    sum=0;
                }
                else
                {
                    cout<<"Student "<<i+1<<" has scored "<<sum/5<<"%"<<"."<<endl;
                    cout<<"The student is NOT ELIGIBLE."<<endl<<endl;
                    sum=0;
                }
            }
        }
    }
    return 0;
}
