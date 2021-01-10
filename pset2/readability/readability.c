#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_readability_index(int letters, int words, int sentences);

int main(void)
{
  int letters;
  int words;
  int sentences;
  string text;
  int length;
  char c;
  int index;

  letters = 0;
  words = 1;
  sentences = 0;
  text = get_string("Text: ");
  length = strlen(text);

  // printf("Text length: %i\n", length);

  while (length-- > 0)
  {
    c = text[length];
    if (isalpha(c))
    {
      letters++;
    }
    if (c == ' ')
    {
      words++;
    }
    if (c == '.' || c == '?' || c == '!')
    {
      sentences++;
    }
  }

  // printf("Number of letters: %i\n", letters);
  // printf("Number of words: %i\n", words);
  // printf("Number of sentences: %i\n", sentences);

  index = get_readability_index(letters, words, sentences);

  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }
}

int get_readability_index(int letters, int words, int sentences)
{
  // index = 0.0588 * L - 0.296 * S - 15.8
  // Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

  int index;
  float average_letters;
  float average_sentences;

  average_letters = (letters * 100) / (float)words;     // Average number of letters per 100 words
  average_sentences = (sentences * 100) / (float)words; // Average number of sentences per 100 words

  // printf("Average letters: %f\n", average_letters);
  // printf("Average sentences: %f\n", average_sentences);

  index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

  return index; // maybe should return a string
}