#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cycle(int winner, int loser);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            //printf("%i\n", ranks[rank]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
     for (int i = 0; i < candidate_count; i++)
     {
         for (int j = i + 1; j < candidate_count; j++)
         {
             int winnerIndex = ranks[i];
             int loserIndex = ranks[j];
             preferences[winnerIndex][loserIndex]++;
             //printf("%i %i %i %i %i %i",  preferences[0][0],preferences[0][1],preferences[0][2],preferences[1][0],preferences[1][1],preferences[1][2]);
         }
     }
     return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //TO DO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i + 1; j < candidate_count; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {

            pairs[pair_count].winner = i;
            pairs[pair_count].loser = j;
            printf("%i %i\n", pairs[pair_count].winner,pairs[pair_count].loser);
            pair_count++;

            }
            else if(preferences[j][i] > preferences[i][j])
            {

            pairs[pair_count].winner = j;
            pairs[pair_count].loser = i;
            printf("%i %i\n", pairs[pair_count].winner, pairs[pair_count].loser);
            pair_count++;
            }
         }
    }
    printf("%i\n", pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    int winner = 0;
    int loser = 0;
    int otherWinner = 0;
    int otherLoser = 0;
    for (int i = 0; i < pair_count; i++)
    {

        for (int j = 0; j < pair_count; j++)
        {
              winner = pairs[j].winner;
              loser = pairs[j].loser;
              otherWinner = pairs[j+1].winner;
              otherLoser = pairs[j+1].loser;

             if (preferences[winner][loser] > preferences[otherWinner][otherLoser])
             {
                 pairs[j].winner =  winner;
                 pairs[j].loser = loser;
                 printf("%i  %i\n",pairs[j].winner, pairs[j].loser );
                 pairs[j+1].winner = otherWinner;
                 pairs[j+1].loser = otherLoser;
                 printf("%i  %i\n",pairs[j+1].winner, pairs[j+1].loser );

             }
             else if(preferences[otherWinner][otherLoser] > preferences[winner][loser])
             {
                 pairs[j].winner =  otherWinner;
                 pairs[j].loser = otherLoser;
                 printf("%i  %i\n",pairs[j].winner, pairs[j].loser );
                 pairs[j+1].winner = winner;
                 pairs[j+1].loser = loser;
                 printf("%i  %i\n",pairs[j+1].winner, pairs[j+1].loser );
             }

        }
    }

    printf("%i %i\n %i %i\n %i %i\n",pairs[0].winner,pairs[0].loser,pairs[1].winner, pairs[1].loser,pairs[2].winner,pairs[2].loser );
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int winner, loser;
    for (int i = 0; i < pair_count; i++)
    {
        winner = pairs[i].winner;
        loser = pairs[i].loser;
        if(!cycle(winner,loser))
        {
        locked[winner][loser] = true;
        }
    }
    return;
}

bool cycle(int winner,int loser)
{

    for (int i = 0; i < candidate_count; i++)
    {
        //loser direct to other node
        if (locked[loser][i])
        {
            //check directed node is Winner or not
            // or check if creates cycle with WINNER
            if(i == winner || cycle(winner,i))
            {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // qalib namized graph'n source'du, bo o demekdir ki ona qarsi ox yoneldilmeyib yeni ona qarsi true(locked'da index nomresnin yerinde) "true" yoxdur.
    // men de qalibi tapmaq ucun locked'da qalibin indexinin yerlesdiyi yerde "true" olmamasini arasdiriram.
    // bunun ucunde a adli variable yaradib qalibin indexinin yerlesdiyi yerdeki "false"lari sayiram. bir namized ucun candidate_count sayda false olarsa
    // demeli qalib odur.
    for(int i = 0; i < candidate_count; i++)
    {
        int a = 0;
        for (int j = 0; j <candidate_count; j++)
        {
            if (!locked[j][i])
            {
                a++;
            }
        }

            if (a == candidate_count)
            {
                printf("%s\n", candidates[i]);
                return;
            }
    }
    return;
}