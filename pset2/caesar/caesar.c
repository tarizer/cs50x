#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_args(int argc, char *argv[]);
string get_ciphertext(string plaintext, int key);

int main(int argc, char *argv[])
{
  string plaintext;
  string ciphertext;

  if (check_args(argc, argv) == 1) // Check for input errors
  {
    printf("Usage: ./caesar key\n");
    return (1);
  }
  plaintext = get_string("plaintext: ");                 // Prompt user for for plain text
  ciphertext = get_ciphertext(plaintext, atoi(argv[1])); // Get ciphertext
  printf("ciphertext: %s\n", ciphertext);                // Outout ciphertext
}

int check_args(int argc, char *argv[])
{
  int key_length;

  if (argc == 2)
  {
    key_length = strlen(argv[1]);
    while (key_length-- > 0)
    {
      if (!isdigit(argv[1][key_length]))
      {
        return (1);
      }
    }
  }
  else
  {
    return (1);
  }
  return (0);
}

string get_ciphertext(string plaintext, int key)
{
  int length;
  string ciphertext;

  // printf("So far so good!\n");
  // printf("Key is: %s\n", argv[1]);
  // Cipher the text
  length = strlen(plaintext);
  ciphertext = plaintext; // So that we can iterate through it and focus only on ciphering alphabetical characters
  while (length-- > 0)
  {
    if (isupper(plaintext[length]))
    {
      // Give the character a value between 0 and 25 to be able to use modulus then add it back
      ciphertext[length] = (plaintext[length] - 65 + key) % 26 + 65;
    }
    else if (islower(plaintext[length]))
    {
      ciphertext[length] = (plaintext[length] - 97 + key) % 26 + 97;
    }
  }
  return ciphertext;
}