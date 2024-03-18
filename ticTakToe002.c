#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int grid[4][4]={{9,1,2,3},{1,0,0,0},{2,0,0,0},{3,0,0,0}};
int helperArray[15]={0};
int helperArrayIndex=0;
int emptyCells=9;
int numOfMoves=0;

int row,col;


void displayGrid(int matrix[][4] )
{
    for(int i=0 ; i<4 ; i++)
    {
        for (int y = 0; y < 4 ; y++)
        {
            printf(" %d ",matrix[i][y]);
        }
        printf("\n");
    }
}

void readInput(int matrix[][4])
{
    printf("\nenter row and col\n ");
    scanf("%d%d",&row,&col);
    matrix[row][col]=6;
    displayGrid(grid);
    helperArray[helperArrayIndex]=row;
    helperArray[helperArrayIndex+1]=col;
    helperArrayIndex+2;
    numOfMoves++;
    emptyCells--;

}

void blockMove(int matrix[][4])
{
    for(int i=0 ; i<15 ; i+2)
    {
        for(int j=2 ; j<15 ; j+2)
        {
            if(helperArray[i]==helperArray[j] && helperArray[j]!=0)
            {
                for(int y=1 ; y<4 ; y++)
                {
                    if(grid[helperArray[i]][y]!=0)
                    {
                        grid[helperArray[i]][y]=8;
                        numOfMoves++;
                        displayGrid(grid);
                        emptyCells--;
                    }
                } 
            }
            else if(helperArray[i+1]==helperArray[j+1] && helperArray[j+1]!=0)
            {
                for(int y=1 ; y<4 ; y++)
                {
                    if(grid[y][helperArray[j+1]]!=0)
                    {
                        grid[y][helperArray[j+1]]=8;
                        numOfMoves++;
                        displayGrid(grid);
                        emptyCells--;
                    }
                }

            }
            else
            {
                printf("error ");
            }
        }
    }
}


int checkWinner(int matrix[][4])
{
    //rows
    if ((matrix[1][1]==matrix[2][1]  && matrix[2][1]==matrix[3][1])&&((matrix[1][1]==6)|| (matrix[1][1]==8)))
    {
        if(matrix[1][1]==6)
        {
        return 1; // if winner 6 returns 1
        }
        else
        {
            return 2; //if winner is 8 returns 2
        }
    }
    else if((matrix[1][2]==matrix[2][2] && matrix[2][2]==matrix[3][2]) && ((matrix[1][2]==6)|| (matrix[1][2]==8)))
    {
        if(matrix[1][2]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((matrix[1][3]==matrix[2][3] && matrix[1][3]==matrix[3][3]) && ((matrix[1][3]==6)|| (matrix[1][3]==8)))
    {
        if(matrix[1][3]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }
     //columnms
    else if((matrix[1][1]==matrix[1][2] && matrix[1][2]==matrix[1][3]) && ((matrix[1][1]==6)|| (matrix[1][1]==8)))
    {
       if(matrix[1][1]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((matrix[2][1]==matrix[2][2] && matrix[2][2]==matrix[2][3]) && ((matrix[2][1]==6)|| (matrix[2][1]==8)))
    {
        if(matrix[2][1]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((matrix[3][1]==matrix[3][2] && matrix[3][2]==matrix[3][3]) && ((matrix[3][1]==6)|| (matrix[3][1]==8)))
    {
        if(matrix[3][1]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }

    //diagonal
    else if((matrix[1][1]==matrix[2][2] && matrix[2][2]==matrix[3][3]) && ((matrix[1][1]==6)|| (matrix[1][1]==8)))
    {
        if(matrix[1][1]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((matrix[1][3]==matrix[2][2] && matrix[2][2]==matrix[3][1]) && ((matrix[1][3]==6)|| (matrix[1][3]==8)))
    {
       if(matrix[1][3]==6)
        {
        return 1;
        }
        else
        {
            return 2;
        }
    }

    //default
    else
    {
        return 0;
    }



}

void playGame(int matrix[][4])
{
    readInput(grid);
    if(emptyCells==8)
    {
        if(grid[2][2]==0)
        {
            grid[2][2]=8;
            numOfMoves++;
            emptyCells--;
        }
        else
        {
            grid[1][1]=8;
            numOfMoves++;
            emptyCells--;
        }
    }

    while(emptyCells<8)
    {
        readInput(grid);
        blockMove(grid);
        if(numOfMoves>4)
        {
            if(checkWinner(grid)!=0)
            {
                if(checkWinner(grid)==1)
                {
                    printf("i let you win this time");
                }
                else
                {
                    printf("you are a loser");
                }
            }
        }

    }

}

int main()
{
    displayGrid(grid);
    playGame(grid);
}
