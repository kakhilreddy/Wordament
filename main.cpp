#include<bits/stdc++.h>
#include<iostream>
#include "trie.h"
using namespace std;
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

    cout<<"  ";
    for(i=0;i<COLS;i++)
        cout<<i<<" ";
    cout<<endl;

    for(i=0;i<ROWS;i++)
    {
        cout<<i<<" ";
        for(j=0;j<ROWS;j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }

}
bool containsWord(char *s)
{

    for(int i=0;i<c;i++)
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
	do{ cout<<"Score :"<<points<<endl;
 cout<<"current word is : "<<w<<endl;
            cout<<"Choose any row and column (i,j) \n";
                    printBoard();
    int x,y;
    cin>>x>>y;


    cout<<"The letter selected is : "<<board[x][y]<<endl;
    w[m++]=board[x][y];
    w[m]='\0';

    if(containsWord(w))
    {
        cout<<"Match found \n";
        points++;

        m=0;
        w[m]='\0';
    }

	cout<<"Do you want to continue game (Y/N)?"<<endl;
	char c;
	cin>>c;
	if(c=='N'|| c=='n')
        break;




	}while(true);




    return 0;
}
