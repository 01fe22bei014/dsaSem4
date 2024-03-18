#include <stdio.h>
#include <stdlib.h>


int grid[4][4]={{9,1,2,3},{1,0,0,0},{2,0,0,0},{3,0,0,0}};
int helperArray[15]={0};
int moves=-1;
int emptyCell=9;
int emptyCol=-1;
int row,col;
int emptyCol;
int vacantRow=1;
int vacantCol=1;
insertedSix=0;

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


void initilizeInput(int matrix[][4])
{
    //int row1,col1;
    printf("enter row and col ");
    scanf("%d%d",&row,&col);
    matrix[row][col]=6;
    helperArray[insertedSix]=row;
    helperArray[insertedSix+1]=col;
    insertedSix+2;
    moves++;
    emptyCell-2;
}



int emptyCoordinates(int matrix[][4])
{
    for(vacantRow ; vacantRow<4 ; vacantRow++)
    {
        for (vacantCol ; vacantCol < 4 ; vacantCol++)
        {
            if(matrix[vacantRow][vacantCol]==0);
            emptyCol=vacantCol;
            return vacantRow;
        }
    }
    return -1;

}
 int whichCol(int arr[],int row) 
 {
    if(helperArray[row+1]==1)
    {
        return 1;

    }
    else if(helperArray[row+1]==2)
    {
         return 2;

    }
    else if(helperArray[row+1]==3)
    {
         return 3;

    }
    return 0;


 }

void blockWin(int matrix[][4])
{
    if(moves==0)
    {
        if(grid[2][2]==0)
        {
            grid[2][2]=8;
        }
        else
        {
            grid[1][1]=8;
        }
        moves++;
        displayGrid(grid);   
        initilizeInput(grid); 
    }
    while (moves<9)
    {
        for(int i=0 ; i<15 ; i+2)
        {
            if((helperArray[i]==helperArray[i+2]) && helperArray[i]!=0)
            {
                int col1=whichCol(helperArray,i);
                int col2=whichCol(helperArray,i+2);

                if(col1 )
            }
        }

        
    }
    
}

void backTrack(int matrix[][4])
{
    while(checkWinner==0)
    {
        int empty=emptyCoordinates(grid);
        grid[empty][emptyCol]=8;
        if(checkWinner(grid)!=0)
        {

        }
        int empty2=emptyCoordinates(grid);
        grid[empty][emptyCol]=6;
        backTrack(grid);
    }
}

void winGmae(int matrix[][4])
{
    while(moves<9)
    {
        initilizeInput(grid);
        displayGrid(grid);
        backTrack(grid);        
    }





}








int main()
{
    winGmae(grid);
    displayGrid(grid);
    return -1;

}

