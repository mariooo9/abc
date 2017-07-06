#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b)
{
   return (*(float*)a - *(float*)b);
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    // vector<float> b[n];
    float b[n+1][1000];
    int ind[10000] = {0};
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi][ind[bi]] = arr[i];
       ind[bi]++;
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       qsort(b[i], ind[i], sizeof(float), cmp);
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < ind[i]; j++)
          arr[index++] = b[i][j];
}
 
/* Driver program to test above funtion */
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
    printf("Sorted array is \n");
    for (int i=0; i<n; i++)
       printf("%f ",arr[i]);
     printf("\n");
    return 0;
}
