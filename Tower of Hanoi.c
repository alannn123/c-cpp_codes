#include <stdio.h>
void TowerofHanoi(int, char, char, char);          //function prototype
int main()
{
	int num;
	printf("Enter the number of disks: \n");
	scanf("%d",&num);
	if(num<=0)
    {
        printf("Stack Underflow\n");
    }
    else
	{printf("The sequence of moves involved in the Tower of Hanoi are: \n");
	TowerofHanoi(num,'A','B','C');                //function call
	}
	return 0;
}


void TowerofHanoi(int n, char A, char B, char C)  //function definition
{
	if(n>0)
	{
		TowerofHanoi(n-1, A , C , B);
		printf("Move a disk from %c to %c\n", A , C);
		TowerofHanoi(n-1, B , A , C);
	}
      return;
}
