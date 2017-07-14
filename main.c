#include<stdio.h>
#include<string.h>
#include "trie.h"

#define ROWS    4
#define COLS    4
char board[ROWS][COLS];
char buf[100];
int k=0;
int c=0;
int visit[ROWS][COLS];
TNode *root;
char validWords[1000][100];

void printWordsStartingWith(int i, int j)
{
    if(i>=ROWS ||j>=COLS)
        return;
    if(i<0 || j<0)
        return;

    if(visit[i][j])
        return;

  buf[k++]=board[i][j];
    buf[k]='\0';
    visit[i][j]=1;


    if(hasWord(root,buf))
{

  strcpy(validWords[c],buf);
        c++;
}
    printWordsStartingWith(i+1,j);
    printWordsStartingWith(i,j+1);
    printWordsStartingWith(i,j-1);
    printWordsStartingWith(i-1,j);


         ///diagonal

    printWordsStartingWith(i+1,j+1);
    printWordsStartingWith(i-1,j-1);
    printWordsStartingWith(i-1,j+1);
    printWordsStartingWith(i+1,j-1);

    visit[i][j]=0;
    buf[k]='\0';

    k--;




}


void printBoard()
{
    int i, j;

    printf("  ");
    for(i=0;i<COLS;i++)
        printf("%d ",i);
    printf("\n);

    for(i=0;i<ROWS;i++)
    {
        printf("%d ",i);
	    for(j=0;j<ROWS;j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }

}
bool containsWord(char *s)
{
int i;
    for( i=0;i<c;i++)
        if(strcmp(s,validWords[i])==0)
        return true;
    return false;
}

void readBoard()
{
    int i, j;
    char c;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<ROWS;)
        {
            if(isalpha(c=getchar()))
            {
                board[i][j] = c;
                j++;
            }
        }
    }
}

int main()
{
     root=createTrieNode();

initializeTrie(root);

//printWordsInTrie(root);
cout<<"Enter board characters\n";
    readBoard();
    //printBoard();   // For Debugging Purpose Only


	int i,j;
	int points=0;

for(i=0;i<ROWS;i++)
        for(j=0;j<COLS;j++)
	printWordsStartingWith(i, j);
	 int m=0;
	     char w[100];
	do{ printf("Score : %d\n",points);
 printf("current word is : %d\n",w);
            printf("Choose any row and column (i,j) \n");
                    printBoard();
    int x,y;
    scanf("%d%d",&x,&y);


    printf("The letter selected is : %d\n",board[x][y]);
    w[m++]=board[x][y];
    w[m]='\0';

    if(containsWord(w))
    {
        printf("Match found \n");
        points++;

        m=0;
        w[m]='\0';
    }

	printf("Do you want to continue game (Y/N)?\n");
	char c;
	scanf("%c",&c);
	if(c=='N'|| c=='n')
        break;




	}while(true);




    return 0;
}
