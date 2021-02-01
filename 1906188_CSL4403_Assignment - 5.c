//Job Sequencing with deadlines problem using greedy method
//Digvijay Srivastava (1906188)
# include<stdio.h>
 
void jobSequencing(int n, int d[], int p[]) {
   int J[20] , k, r, i, q, profit = 0;
   J[0] = d[0] = p[0] = 0;
   J[1] = 1;
   k = 1;
   
   for( i = 2; i <= n; i++)
   {
        r = k;
        while( (d[J[r]] > d[i]) && (d[J[r]] != r) )
            r -= 1;
        if( (d[J[r]] <= d[i]) && (d[i] > r) ){
            for(q = k; q <= (r+1); q++ ){
                J[q+1] = J[q];
            }
            J[r+1] = i;
            k += 1;
        }    
   }
   
   for (i = 1; i <= k; i++)
   {
        profit += p[J[i]];
   }
   
   printf("\nThe resultant optimal solution (Job Sequence) is : ");
   for (i = 1; i <= k; i++)
      printf("%d\t", J[i]);
 
   printf("\nTotal profit : %d", profit);
 
}
 
int main() {
   int deadline[10], profit[10];
   int jobs, i, j;
   int temp;
 
   printf("\nEnter the no. of jobs : ");
   scanf("%d", &jobs);
 
   printf("\nEnter the deadline and profit of each object : ");
   for (i = 1; i <= jobs; i++) {
      printf("\nEnter the deadline of job %d :", i);
      scanf("%d", &deadline[i]);
      printf("Enter the profit of job %d :", i);
      scanf("%d", &profit[i]);
   }
 
 
   for (i = 1; i <= jobs; i++) {
      for (j = i + 1; j <= jobs; j++) {
         if (profit[i] < profit[j]) {
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
            
            temp = deadline[j];
            deadline[j] = deadline[i];
            deadline[i] = temp;
         }
      }
   }
 
   jobSequencing( jobs , deadline , profit);
   return(0);
}




