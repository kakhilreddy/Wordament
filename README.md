# Wordament

 Game consists of a 4 by 4 matrix of letters from the English alphabet.
 Players form meaningful English words by selecting letters one by one to obtain points.
 

Input

2-D Array of characters of size 4x4.
Next subsequent lines are the various moves performed by the user

Output

For every move of the user, we need to check whether the formed word is a valid word or not and add points accordingly.

![20160924_075019](https://cloud.githubusercontent.com/assets/21156001/18805437/c419bf9a-822b-11e6-8c02-faedc788d629.gif)


![20160924_080447](https://cloud.githubusercontent.com/assets/21156001/18805522/ecb83060-822d-11e6-8ac0-89afa8586829.gif)

Trie is used to store the dictionary words.
At first,all possible dictionary words  that can be formed in the Wordament board has to be generated using backtracking.
Then these are words are being stored in an array for later use.
When the user makes a move ,array is searched to find the word selected by the user. If the word is present in array then we increment
points and proceed for next move. 




 
 
