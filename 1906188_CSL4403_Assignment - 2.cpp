/*﻿Design and Analysis of Algorithms Laboratory


Name : Digvijay Srivastava
Roll No. : 1906188
Branch : CSE
Course Code : CSL4403
11th January 2021


Lab - 2


1. Write a program to implement Quick sort algorithm.  */




//Program to implement QuickSort to illustrate Divide and Conquer technique
//Digvijay Srivastava (1906188)
#include <stdio.h>
int ar[50];
void QuickSort(int low,int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (ar[i] <= ar[pivot] && i <= high)
            {
                i++;
            }
            while (ar[j] > ar[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
        temp = ar[j];
        ar[j] = ar[pivot];
        ar[pivot] = temp;
        QuickSort( low, j - 1);
        QuickSort( j + 1, high);
    }    
}


int main()
{
    int i, n;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    ar[n] = 5000;
    printf("\nEnter the elements of the array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("\nEntered array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    QuickSort(0,n-1);
    printf("\nSorted array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}




















//Output
  

//2. Write a program to implement Binary Search.


//Program to implement Binary search
//Digvijay Srivastava (1906188)
#include <stdio.h>
int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int s;  // Element to search
    int p;  // To sotre the position of element where the element s found in the array 
    int k,i; // To store the input is in the required form for binary search or not
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);// Function to read n elements into an array
    printf("\nEntered array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    QuickSort(a,0,n-1);
    printf("\nSorted array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
        s = Read_Element_to_Search();  // Function to read the searching element   
        p = Binary_Search(a, 0, n, s);   // Function implements the linear search
        if(p==-1)
            printf("\n Element not found");
        else
            printf("\n Element found at position: %d",p);
        return 0;
}


int Read_Number_of_Elements() // Read the number of elements in the Array and return it 
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    return n;
}


void Read_Elements_to_Array(int *p, int n) // Read the n elements into array from the keyboard
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
}


void QuickSort(int ar[],int low,int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (ar[i] <= ar[pivot] && i <= high)
            {
                i++;
            }
            while (ar[j] > ar[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
        temp = ar[j];
        ar[j] = ar[pivot];
        ar[pivot] = temp;
        QuickSort(ar, low, j - 1);
        QuickSort(ar, j + 1, high);
    }    
}




int Read_Element_to_Search() // Read the element you want to search from keyboard and return
{
    int s;
    printf("\nEnter the element to search:");
    scanf("%d",&s);
    return s;
}
// Write the code for Binary search
// l is the first element position
// h is the last element position-1
int Binary_Search(int *p, int l, int h, int s)  
{
    while(h>=l){
        int middle = l+(h-l)/2;
        
        if(p[middle] == s){
            return middle+1;
        }
        if(p[middle] >s){
            h = middle-1;
        }
        l = middle+1;
    }
    return -1;
}

