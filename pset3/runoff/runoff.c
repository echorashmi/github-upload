#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
void print_table();

int main(int argc, string argv[])
{
    voter_count     = 4;
    candidate_count = 3;

    /* Creating Mock Candidates:
    candidates[0].name  = "A";
    candidates[0].votes = 0;
    candidates[0].eliminated = false;

    candidates[1].name  = "B";
    candidates[1].votes = 0;
    candidates[1].eliminated = false;

    candidates[2].name  = "C";
    candidates[2].votes = 0;
    candidates[2].eliminated = false;
    */


    /* Creating Mock Votes:
    preferences[0][0] = 0;//0'th voter's first preference
    preferences[0][1] = 1;//0'th voter's second preference
    preferences[0][2] = 2;//0'th voter's third preference

    preferences[1][0] = 0;//1st voter's first preference
    preferences[1][1] = 2;//1st voter's second preference
    preferences[1][2] = 1;//1st voter's third preference

    preferences[2][0] = 1;//2nd voter's first preference
    preferences[2][1] = 2;//2nd voter's second preference
    preferences[2][2] = 0;//2nd voter's third preference

    preferences[3][0] = 2;//3rd voter's first preference
    preferences[3][1] = 1;//3rd voter's second preference
    preferences[3][2] = 0;//3rd voter's third preference
    */

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    int count = 1;
    while (count < 4)
    {
        printf("------%i------\n", count);
        // Calculate votes given remaining candidates
        tabulate();

        print_table();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
        count++;
    }
    return 0;
}

void print_table()
{
    printf("\nCandidates: \n");
    for (int j = 0; j < candidate_count; j++)
    {
        printf("%s: %i\t", candidates[j].name, candidates[j].votes);
    }
    printf("\n\n");


    /*
    printf("Preferences: \n");
    for(int i = 0; i < voter_count; i++)
    {
        printf("Voter #%i:\n", i);
        for(int j = 0; j < candidate_count; j++)
        {
            //Get Candidate Name:
            int candidate_index = preferences[i][j];
            printf("%s\t", candidates[candidate_index].name);
        }
        printf("\n\n");
    }
    */
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (strcmp(name, candidates[j].name) == 0) //If Name is a valid name
            {
                preferences[voter][rank] = j;
                return true;
            }
        }
    }

    // TODO
    return false;
}

// Tabulate votes for non-eliminated candidates
/*
 1. Update the number of votes each candidate has at this stage in the runoff.
 2. At each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.
 What we want to do here, is update the candidates[i].votes array with the numbers in the placements array.
*/
void tabulate(void)
{
    /*
        We only want the top preference here, not all the preferences.
    */
    int winner = 0;
    int index  = 0;
    for (int i = 0; i < voter_count; i++) //Columns: Voters
    {
        index = preferences[i][0];
        printf("\nChecking Vote of Candidate: %s", candidates[index].name);
        if (candidates[index].eliminated == false)
        {
            printf("\nIncrementing Vote of Candidate: %s", candidates[index].name);
            candidates[index].votes++;
        }
    }

    printf("\n");
    /*
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].eliminated == false)
            printf("\n%s: %i", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
    */
    // TODO
    return;
}

// Print the winner of the election, if there is one
/*
    1. If any candidate has more than half of the votes, their name prints out, and the function returns true
    2. If nobody has won the election yet, return false
*/
bool print_winner(void)
{
    int majority = voter_count / 2;
    //printf("Majority: %i\n", majority);
    /*
        Find out if any candidate has more than majority votes:
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority && candidates[i].eliminated != true)
        {
            printf("Winner: %s", candidates[i].name);
            return true;
            break;
        }
    }
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
/*
    1. Return the minimum vote total for any candidate still in the election.
    2. Loop through candidates and find the person who has the minimum number of votes.
*/
int find_min(void)
{

    /*
        Start by Sorting out the array from left to right:
        Using Linear Sort:
    */
    candidate temp;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }

    int min_votes = 0;
    for (int i = 0; i < candidate_count; i++) //Only take the votes that are not eliminated
    {
        if (candidates[i].eliminated != true)
        {
            min_votes = candidates[i].votes;
            break;
        }
    }

    //printf("MinVotes: %i\n\n", min_votes);
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
/*
    1. Return true if there is a tie, false otherwise.
    2. Min is the minimum number of votes that anyone in the election currently has
*/
bool is_tie(int min)
{
    bool is_tie = false;
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        //printf("Min: %i, CVotes: %i\n", min, candidates[i].votes);
        if (candidates[i].votes == min)
        {
            is_tie = true;
        }
        else
        {
            is_tie = false;
        }
    }
    return is_tie;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    //Takes argument: min, that will be minimum number of votes that anyone in the election currently has.
    //Eliminate the candidate(s) who have minimum number of votes.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    // TODO
    return;
}
