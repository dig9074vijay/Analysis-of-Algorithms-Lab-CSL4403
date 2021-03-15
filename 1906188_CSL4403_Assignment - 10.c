//0-1 Knapsack problem
//Digvijay Srivastava (1906188)
#include <stdio.h>
 

int max(int a, int b)
{ 
    return (a > b) ? a : b; 
}
 
int Knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]] , K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    return K[n][W];
}
 
int main()
{
    int val[100], wt[100]; 
    int W , n, i , j;
    printf ("Enter number of items: ");
    scanf ("%d", &n);
    printf ("\nEnter values of item :- \n");
    for (i = 0; i < n; i++)
    {
      printf ("Profit for Item[%d] : ", i + 1);
      scanf ("%d", &val[i]);
    }
    printf ("\nEnter weights of item:- \n");
    for (j = 0; j < n; j++)
    {
      printf ("Weight for Item[%d]: ", j + 1);
      scanf ("%d", &wt[j]);
    }
    printf ("\nEnter the Knapsack capacity: ");
    scanf ("%d", &W);
    printf("\nMaximum Profit : %d", Knapsack(W, wt, val, n));
    return 0;
}

