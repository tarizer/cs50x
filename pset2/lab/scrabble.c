#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet -> Global
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
  // Get input words from both players
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // Score both words
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // Print the winner
  if (score1 > score2)
  {
    printf("Player 1 wins!\n");
  }
  else if (score1 < score2)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("Tie!\n");
  }
}

int compute_score(string word)
{
  int length;
  int sum;

  length = strlen(word);
  sum = 0;

  while (length-- > 0)
  {
    word[length] = tolower(word[length]); // Put all characters in lower case
    if (word[length] >= 'a' && word[length] <= 'z')
    {
      // Sum of indivudual letters beggining with the last one
      sum += POINTS[word[length] - 97]; // a -> 97 / Implicit casting into int
    }
  }
  return (sum);
}