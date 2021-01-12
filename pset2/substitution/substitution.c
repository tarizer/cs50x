#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_args(int argc, char *argv[]);
string get_ciphertext(string plaintext, string key);

int main(int argc, char *argv[])
{
  string plaintext;
  string ciphertext;

  if (check_args(argc, argv) == 1) // Check for input errors
  {
    return (1);
  }
  plaintext = get_string("plaintext: ");           // Prompt user for for plain text
  ciphertext = get_ciphertext(plaintext, argv[1]); // Get ciphertext
  printf("ciphertext: %s\n", ciphertext);          // Outout ciphertext
}

int check_args(int argc, char *argv[])
{
  int length;
  int duplicate[26];
  char c;
  string key;

  key = argv[1];
  if (argc != 2)
  {
    printf("Usage: ./substitution KEY\n");
    return (1);
  }
  length = strlen(key);
  if (length != 26)
  {
    printf("Key must contain 26 characters.\n");
    return (1);
  }
  while (length-- > 0) // O(n)
  {
    c = tolower(key[length]);

    if (isalpha(c))
    {
      if (duplicate[c - 97] == 1) // Letter already exists (-97 to reindex from 0 to 25)
      {
        printf("Key must not contain repeated characters.\n");
        return (1);
      }
      else
      {
        duplicate[c - 97] = 1;
      }
    }
    else
    {
      printf("Key must only contain alphabetic characters.\n");
      return (1);
    }
  }
  return (0);
}

string get_ciphertext(string plaintext, string key)
{
  int index;
  int length;
  char c;
  char original_letter;
  string ciphertext;

  length = strlen(plaintext);
  ciphertext = plaintext;
  while (length-- > 0)
  {
    original_letter = plaintext[length];
    if (isalpha(original_letter))
    {
      index = toupper(original_letter) - 65; // Give it a value from 0 to 25 so we can access the corresponding letter in the key
      ciphertext[length] = key[index];
      if (islower(original_letter))
      {
        ciphertext[length] = tolower(ciphertext[length]);
      }
      else
      {
        ciphertext[length] = toupper(ciphertext[length]);
      }
    }
  }
  return ciphertext;
}