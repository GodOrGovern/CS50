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
int dim;

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
        printf("Usage: ./fifteen dimension\n");
        return 1;
    }

    // ensure valid dimensions
    dim = atoi(argv[1]);
    if (dim < DIM_MIN || dim > DIM_MAX)
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
    int row = dim;
    int col = 0;
    int val = 0;

    do
    {
        for (col = dim; col >= 0; col--)
        {
            val = ((dim - row) * dim) - (col + 1);
            board[row][col] = val;

            if (dim % 2 == 0)
            {
                if (board[row][col] == 1)
                {
                    board[row][col] = 2;
                }

                else if (board[row][col] == 2)
                {
                    board[row][col] = 1;
                }
            }

            if (col == (dim - 1))
            {
                row--;
            }
        }
    }
    while (row >= 0);
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int row = 0;
    int col = 0;
    int val = 0;

    printf("\n\n");

    do
    {
        for (col = 0; col < dim; col++)
        {
            val = (row * dim) + (col + 1);

            if (board[row][col] == 0)
            {
                printf("   _   ");
            }

            else if (board[row][col] > 9)
            {
                if (board[row][col] == val)
                {
                    printf(GRN "  %i   " RST, board[row][col]);
                }

                else
                {
                    printf("  %i   ", board[row][col]);
                }
            }

            else
            {
                if (board[row][col] == val)
                {
                    printf(GRN "   %i   " RST, board[row][col]);
                }

                else
                {
                    printf("   %i   ", board[row][col]);
                }
            }

            if (col == (dim - 1))
            {
                printf("\n\n\n");
                row++;
            }
        }
    }
    while(row < dim);
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    int row = 0;
    int col = 0;
    int loc[2][2];
    int buffer = 0;

    do
    {
        for (col = 0; col < dim; col++)
        {
            if (board[row][col] == tile)
            {
                loc[0][0] = row;
                loc[1][0] = col;
            }

            if (board[row][col] == 0)
            {
                loc[0][1] = row;
                loc[1][1] = col;
            }

            if (col == (dim - 1))
            {
                row++;
            }
        }
    }
    while (row < dim);


    if (loc[0][0] == loc[0][1])
    {
        if (abs(loc[1][1] - loc[1][0]) == 1)
        {
            buffer = board[loc[0][0]][loc[1][0]];
            board[loc[0][0]][loc[1][0]] = board[loc[0][1]][loc[1][1]];
            board[loc[0][1]][loc[1][1]] = buffer;
            return true;
        }

        else
        {
            return false;
        }
    }

    else if (loc[1][0] == loc[1][1])
    {
        if (abs(loc[0][1] - loc[0][0]) == 1)
        {
            buffer = board[loc[0][0]][loc[1][0]];
            board[loc[0][0]][loc[1][0]] = board[loc[0][1]][loc[1][1]];
            board[loc[0][1]][loc[1][1]] = buffer;
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
    int row = 0;
    int col = 0;
    int count = 0;
    int val = 0;

    do
    {
        for (col = 0; col < dim; col++)
        {
            val = (row * dim) + (col + 1);

            if (board[row][col] == val)
            {
                count++;
            }

            if (col == (dim - 1))
            {
                row++;
            }
        }
    }
    while (row < dim);

    if (count == (dim * dim) - 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}
