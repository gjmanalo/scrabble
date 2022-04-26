#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int k;
int n = 1;
char score[1000];
int totalscore = 0;
int compute_score(string word);

int main(void)
{

    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
    printf("Player 1 Wins!\n");
    }
    if (score1 < score2)
    {
    printf("Player 2 Wins!\n");
    }
    else
    printf("Tie!\n");
}

int compute_score(string word)
{
        //Converts the given words to all caps

        int i = 0;
        while (word[i])
    {
        char CAP = word[i];
        char UP = toupper(CAP);
        word[i] = UP;
        i = i + 1;
    }
    
    //TODO: Compute and return score for string
    totalscore = 0;
    for (int j = 0; j < strlen(word); j++)      //sets up the outer most loop to check each letter of the users' word
    {
         for (k = 0; k < strlen(LETTERS); k++)  //sets up the nested loop to to check each letter in the users word against the alphabet array
         {
               if (word[j] == LETTERS[k])       //if the current letter matches any letters in the alphabet array, set n = 0 and exit loop
               {
                   n = 0;
                   break;
               }                                //if no match is found, set n = 1;
                   n = 1;
         }
         if (n == 0)                            //if n = 0; populate the score current score array index with the current score from points array
         {
            score[j] = POINTS[k];
         }
         else
         {
            score[j] = 0;                       //if n = 1, set the current index of the score array to 0
         }
         totalscore = totalscore + score[j];    //add the current score to the total score
    }
    return totalscore;
}
