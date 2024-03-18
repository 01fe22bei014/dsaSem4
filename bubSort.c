#include<stdio.h>
#include<stdlib.h>
int num;
int array[10]={0};


void bubSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int array[],int size)
{
    for(int i=0 ; i<size-1 ; i++)
    {
        for(int j=i+1 ; j<size ; j++)
        {
            if(array[i]>array[j])
            {
               int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

}

void insertionSort(int array[], int size)
{
   for(int i =1;i<size ;i++)
   {
    int temp=array[i];
    int j=i-1;

    while(j>=0 && array[j]>temp)
    {
        array[j+1]=array[j];
        j=j-1;
    }
    array[j+1]=temp;
   }
}

void mergeSort(int array[],int size)
{
    int size2=size/2;
    for()

}

void displayArray(int array[],int size)
{
    for(int i =0 ; i<size ; i++)
    {
        printf("%d",array[i]);
        printf("\n");
    }
    
}



int binarySearch(int array[], int size, int key) 
{
    int low = 0;
    int high = size - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (array[mid] == key) 
        {
            return mid;  
        }

        if (array[mid] < key) 
        {
            low = mid + 1;
        } else 
        {
            high = mid - 1;
        }
    }

    return -1; 
}


int main()
{

    
    printf("enter num of elements  ");
    scanf("%d",&num);

    for(int i=0 ; i<num ; i++)
    {
        printf("enter data for num %d  ",i);
        scanf("%d",&array[i]);
    }
   // displayArray(array,num);
    insertionSort(array,num);
    displayArray(array,num);


}