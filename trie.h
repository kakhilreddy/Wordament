#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#define	ALPHABET_SIZE	26
#include<iostream>
using namespace std;
struct TNode
{
	bool isEOW;
	TNode *next[ALPHABET_SIZE];
};
/*
TNode *createTrieNode();
bool insertWordInTrie(TNode *root, char *word);
void printWordsInTrie(TNode* root,char* str1);
bool deleteWordFromTrie(TNode *root, char *word);
TNode* initializeTrie(TNode *root);*/
bool hasWord(TNode*root,char *word)
{

    if(root==NULL)
        return false;
        if(strlen(word)==0 && root->isEOW)
            return true;
            if(strlen(word)==0 && !root->isEOW)
                return false;

        if(word[0]=='\0' && root->isEOW)
            return true;
    if(root->next[word[0]-'a'])
          return  hasWord(root->next[word[0]-'a'],word+1);

return false;

}
TNode *createTrieNode()
{

    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    newNode->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        newNode->next[i] = NULL;
    return newNode;
}
bool insertWordInTrie(TNode *root, char *word)
{
  int len=strlen(word);
  for(int i=0;i<len;i++)
  {
  if(root->next[word[i]-'a']==NULL)
    root->next[word[i]-'a']=createTrieNode();
    root=root->next[word[i]-'a'];



  }
  if(root->isEOW)
    return false;
  root->isEOW=true;
  return true;


}
char str[10000];
int index=0;
void printWordsInTrie(TNode* root){

  if(root==NULL)
    return;
  if(root->isEOW)
  { str[index]='\0';
    cout<<str<<endl;}
  for(int i=0;i<26;i++)
  {

   if(root->next[i]!=NULL)
   {
   str[index]=i+'a';
     index++;
     printWordsInTrie(root->next[i]);
     index--;
     str[index]='\0';



   }
  }

}
TNode* initializeTrie(TNode *root)
{
     fstream fs("words.txt");
    while(!fs.eof())
    {

        char temp[100];
        fs>>temp;
        //cout<<temp<<endl;
        insertWordInTrie(root,temp);

    }

    return root;

}



#endif // TRIE_H_INCLUDED
