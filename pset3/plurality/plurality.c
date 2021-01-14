#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  string name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void swap_candidates(int a, int b);

int main(int argc, string argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
  }

  int voter_count = get_int("Number of voters: ");

  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    string name = get_string("Vote: ");

    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }
  }
  // Display winner of election
  print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
  int i;

  i = candidate_count;
  while (i--)
  {
    if (strcmp(candidates[i].name, name) == 0)
    {
      candidates[i].votes++;
      printf("Candidate found!\n");
      printf("%s ", candidates[i].name);
      printf("has %i votes\n", candidates[i].votes);
      return true;
    }
  }
  // Name not found
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  int i;
  int max_votes;
  // candidate buffer;

  i = 0;
  // We only need to iterate once using bubble sort as we only need to get track of the biggest number of votes
  while (i < candidate_count - 1)
  {
    if (candidates[i].votes > candidates[i + 1].votes)
    {
      swap_candidates(i, i + 1);
    }
    max_votes = candidates[i + 1].votes;
    i++;
  }
  i = 0;
  // Display all candidates who got the maximum number of votes
  while (i < candidate_count)
  {
    if (candidates[i].votes == max_votes)
    {
      printf("%s\n", candidates[i].name);
    }
    i++;
  }
}

void swap_candidates(int a, int b)
{
  candidate buffer;

  buffer.name = candidates[b].name;
  candidates[b].name = candidates[a].name;
  candidates[a].name = buffer.name;

  buffer.votes = candidates[b].votes;
  candidates[b].votes = candidates[a].votes;
  candidates[a].votes = buffer.votes;
}