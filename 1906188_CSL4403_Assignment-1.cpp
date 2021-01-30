/*﻿Design and Analysis of Algorithms Laboratory


Name : Digvijay Srivastava
Roll No. : 1906188
Branch : CSE
Course Code : CSL4403
4th January 2021


Lab - 1. */


//1. Find maximum and minimum element in an array using Divide and Conquer Technique.


//Divide & Conquer technique
//Program to find the maximum and minimum values in an array
//Digvijay Srivastava (1906188)
#include <stdio.h>
int ar[20]; 
void MaxMin(int i,int j,int *max,int *min)
{
    int mid, max1, min1;
    if(i==j)
    {
    *max = ar[i];
    *min = ar[i];
    }
    else if(i==j-1)
    {
        if(ar[i]>ar[j])
        {
        *max=ar[i];
        *min=ar[j];
        }
        else
        {
        *max=ar[j];
        *min=ar[i];
        }
        
    }
    else
    {
        mid = (i + j)/2;
        MaxMin(i,mid,max,min);
        max1 = *max;
        min1 = *min;
        MaxMin(mid + 1,j,&max1,&min1);
        if(*max<max1)
        *max = max1;
        if(*min>min1)
        *min = min1;
    }
}


int main() //Driver of the program
{
    int i, n, max, min;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    printf("\nEnter the elements of the array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    min = ar[0];
    max = ar[0];
    MaxMin(0,n-1,&max,&min);
    printf("\nThe maximum value is : %d",max);
    printf("\nThe minimum value is : %d",min);
    return 0;
}

