#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int chessMat[8][8]={0,0};
int currentRow=0;
int currentCol=0;
int count=0;


bool checkCell(int row , int col )
{
    if(chessMat[row][col]==1)
    {
        return false;

    }

    //checking upper row
    for(int i=row-1;i>=0;i--)
    {
        if(chessMat[i][col]==1)
            return false;
    }

    //checking coloumn
    for(int j=col-1;j>=0;j--)
    {
     if(chessMat[row][j]==1)
            return false;
    }





    int m=row-1;
    int n=col-1;

    // check for upper left diagonal queens
    while(m>=0 && n>=0)
    {
        if(chessMat[m][n]==1)
            return false;
        m--;
        n--;
    }

    // check for upper right diagonal queens
    m=row-1;
    n=col+1;
    while(m>=0 && n<=7)
    {
        if(chessMat[m][n]==1)
        return false;
        m--;
        n++;

    }

    return true;


}



void printMat()
{

    printf("----------\n");
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            printf("%d  ",chessMat[i][j]);

        }
        printf("\n");
    }

printf("----------\n");
}





bool PlaceQueen()
{
    bool PlacedQueen;

     while(currentRow<=7)
    {
        PlacedQueen=false;



     while(currentCol<8)

    {
        if(checkCell(currentRow,currentCol)==true)
        {
            chessMat[currentRow][currentCol]=1;
            PlacedQueen=true;


            if(currentRow==7)
            {
                printf("soln aditya found");
                printMat();
               printf("num of soln %d",count++);
                PlacedQueen=false;
                currentRow++;
                getch();

            }


            else
                {currentRow++;
            currentCol=0;
            break;
            }

        }
        currentCol++;


    }
    if(PlacedQueen==false)
    {


       currentRow--;
       for(int k=0;k<=7;k++)
       {
           if(chessMat[currentRow][k]==1)
           {
               chessMat[currentRow][k]=0;
               currentCol=k+1;

           }

       }
    }


    }




}



int main()
{

    PlaceQueen();
}
