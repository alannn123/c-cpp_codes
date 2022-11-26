#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

typedef struct node
{
	char ch;
	int freq;
	struct node *left;
	struct node *right;
}node;

node * pque[MAX];
int size = -1;

void insertnode(node * element)
{
	int i, j;
	if(size==-1)
	{
		size++;
		pque[size] = element;
	}
	else
	{
		i=0;
		while(element->freq <= pque[i]->freq && i<=size)
			i++;
		if(i <= size)
		{
			for(j=size; j>=i; j--)
				pque[j+1] = pque[j];
			pque[i] = element;
			size++;
		}
		else
		{
			size++;
			pque[size] = element;
		}
	}
}

node * deleteMin()
{
	size--;
	return(pque[size+1]);
}

void printcode(node *temp, char *code)
{
	int len;
	char leftcode[MAX], rightcode[MAX];

	if(temp->left==NULL && temp->right==NULL)
	{
		printf("\n%c\t%d\t%s", temp->ch, temp->freq, code);
		return;
	}

	len = strlen(code);
	strcpy(leftcode, code);
	strcpy(rightcode, code);
	leftcode[len] = '0';
	leftcode[len+1] = '\0';
	rightcode[len] = '1';
	rightcode[len+1] = '\0';
	printcode(temp->left, leftcode);
	printcode(temp->right, rightcode);
}
int main()
{
	int n, freq, i;
	char ch, code[MAX];
	node *tree, *temp;
	//clrscr();

	printf("\nHuffman Coding Algorithm\n");
	printf("\nEnter the no. of characters: ");
	scanf("%d", &n);

	printf("\nEnter the characters and their frequencies:\n");
	for(i=0; i<n; i++)
	{
		temp = (node *)malloc(sizeof(node));
		scanf("\n%c", &ch);
		scanf("%d", &freq);
		temp -> ch = ch;
		temp -> freq = freq;
		temp -> left = temp -> right = NULL;
		insertnode(temp);
	}

	printf("\nThe Huffman codes are:-");
	printf("\nChar\tFreq\tCode\n");
	if(n==1)
		printf("\n%c\t%d\t0\n", ch, freq);
	else
	{
		for(i=0; i<n-1; i++)
		{
			node *left = deleteMin();
			node *right = deleteMin();

			temp = (node *)malloc(sizeof(node));
			temp -> ch = 0;
			temp -> left = left;
			temp -> right = right;

			temp -> freq = left->freq + right->freq;
			insertnode(temp);
		}

		tree = deleteMin();
		code[0] = '\0';
		printcode(tree, code);
	}

	getch();
	return 0;
}



/*
OUTPUT

Huffman Coding Algorithm

Enter the no. of characters: 6

Enter the characters and their frequencies:
a 45
b 13
c 12
d 16
e 9
f 5

The Huffman codes are:-
Char    Freq    Code

a       45      0
c       12      100
b       13      101
f       5       1100
e       9       1101
d       16      111


*/
