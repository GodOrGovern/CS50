#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define GRN "\x1B[32m"
#define RST "\x1B[0m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("That's a wrap\n\n");
            usleep(2500000);
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // success
    clear();
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int i = 0;
    int k = 0;
    int val = 0;

    do
    {
        for (k = 0; k < d; k++)
        {
            val = ((d - i) * d) - (k + 1);
            board[i][k] = val;

            if (d % 2 == 0)
            {
                if (board[i][k] == 1)
                {
                    board[i][k] = 2;
                }

                else if (board[i][k] == 2)
                {
                    board[i][k] = 1;
                }
            }

            if (k == (d - 1))
            {
                i++;
            }
        }
    }
    while (i < d);
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int i = 0;
    int k = 0;
    int val = 0;

    do
    {
        for (k = 0; k < d; k++)
        {
            val = (i * d) + (k + 1);

            if (k == 0 && i == 0)
            {
                printf("\n\n");
            }

            if (board[i][k] == 0)
            {
                printf("   _   ");
            }

            else if (board[i][k] > 9)
            {
                if (board[i][k] == val)
                {
                    printf(GRN "  %i   " RST, board[i][k]);
                }

                else
                {
                    printf("  %i   ", board[i][k]);
                }
            }

            else
            {
                if (board[i][k] == val)
                {
                    printf(GRN "   %i   " RST, board[i][k]);
                }

                else
                {
                    printf("   %i   ", board[i][k]);
                }
            }

            if (k == (d - 1))
            {
                printf("\n\n\n");
                i++;
            }
        }
    }
    while(i < d);
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    int i = 0;
    int k = 0;
    int row[2] = { 0 };
    int col[2] = { 0 };
    int temp = 0;

    do
    {
        for (k = 0; k < d; k++)
        {
            if (board[i][k] == tile)
            {
                row[0] = i;
                col[0] = k;
            }

            if (board[i][k] == 0)
            {
                row[1] = i;
                col[1] = k;
            }

            if (k == (d - 1))
            {
                i++;
            }
        }
    }
    while (i < d);


    if (row[0] == row[1])
    {
        if (col[0] + 1 == col[1] || col[0] - 1 == col[1])
        {
            temp = board[row[0]][col[0]];
            board[row[0]][col[0]] = board[row[1]][col[1]];
            board[row[1]][col[1]] = temp;
            return true;
        }

        else
        {
            return false;
        }
    }

    else if (col[0] == col[1])
    {
        if (row[0] + 1 == row[1] || row[0] - 1 == row[1])
        {
            temp = board[row[0]][col[0]];
            board[row[0]][col[0]] = board[row[1]][col[1]];
            board[row[1]][col[1]] = temp;
            return true;
        }

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int i = 0;
    int k = 0;
    int count = 0;
    int val = 0;

    do
    {
        for (k = 0; k < d; k++)
        {
            val = (i * d) + (k + 1);

            if (board[i][k] == val)
            {
                count++;
            }

            if (k == (d - 1))
            {
                i++;
            }
        }
    }
    while (i < d);

    if (count == (d * d) - 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}
