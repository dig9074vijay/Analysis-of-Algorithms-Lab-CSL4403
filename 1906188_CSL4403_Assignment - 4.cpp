/*﻿Design and Analysis of Algorithms Laboratory


Name : Digvijay Srivastava
Roll No. : 1906188
Branch : CSE
Course Code : CSL4403
25th January 2021


Lab - 4*/


//1. Write a program to solve Knapsack problem using Greedy method.




//Solving KNAPSACK problem using greedy method
//Digvijay Srivastava (1906188)
# include<stdio.h>
 
void bag(int n, float weight[], float profit[], float capacity) {
   float x[20], totalProfit = 0;
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         totalProfit = totalProfit + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   totalProfit = totalProfit + (x[i] * profit[i]);
 
   printf("\nThe resultant vector is : ");
   for (i = 0; i < n; i++)
      printf("%.2f\t", x[i]);
 
   printf("\nMaximum profit : %.2f", totalProfit);
 
}
 
int main() {
   float weight[10], profit[10], capacity;
   int num, i, j;
   float ratio[10], temp;
 
   printf("\nEnter the no. of objects : ");
   scanf("%d", &num);
 
   printf("\nEnter the weight and profit of each object : ");
   for (i = 0; i < num; i++) {
      printf("\nEnter the weight of object %d :", i + 1);
      scanf("%f", &weight[i]);
      printf("Enter the profit of object %d :", i + 1);
      scanf("%f", &profit[i]);
   }
 
   printf("\nEnter the capacity of knapsack : ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
 
   bag(num, weight, profit, capacity);
   return(0);
}


