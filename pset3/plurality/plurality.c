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
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void print_votes_table();

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

    //Print votes table
    //print_votes_table();
}

void print_votes_table()
{
    printf("\n-----------\n");
    /*
    * In the interest of Transparency & for testing, Print out the struct of all the votes
    */
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%i. %s: %i\n", i, candidates[i].name, candidates[i].votes);
    }

    printf("\n-----------\n");
}

// Update vote totals given a new vote
bool vote(string name)
{
    //Linear Search:
    /*
    * Have to look through the entire array.
    * Best Case: Omega (1)
    * Worst Case: O(n)
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int swap_counter = 1;
    while (swap_counter != 0)
    {
        swap_counter = 0;
        //Sort candidates using Bubble Sort on .votes:
        for (int i = 0; i < candidate_count; i++)
        {
            if (i >= candidate_count - 1)
            {
                break;
            }
            if (candidates[i].votes > candidates[i + 1].votes)
            {
                candidate t     = candidates[i];
                candidates[i]   = candidates[i + 1];
                candidates[i + 1] = t;
                swap_counter++;
            }
        }
    }

    int n = candidate_count - 1;
    for (int i = n; i >= 0; i--)
    {
        //printf("i: %i | n: %i\n\n", i, n);
        if (n - 1 == 0)
        {
            printf("%s\n", candidates[i].name);
            break;
        }
        else
        {
            if (candidates[i].votes == candidates[i - 1].votes)
            {
                printf("%s\n", candidates[i].name);
            }
            else
            {
                printf("%s\n", candidates[i].name);
                break;
            }
        }
    }

    return;
}

