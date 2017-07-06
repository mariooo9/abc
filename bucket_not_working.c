#include<stdio.h>
#include<stdlib.h>
 
 void sort(float a, int n)
 {
    int i,j;
    float value =0.0f;
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
          {
              value=a[j+1];
              a[j+1]=a[j];
              a[j]=value;
          }
      }
    }
  }

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
   // vector<float> b[n];
    int i,j;
    float b[n][];
    // 2) Put array elements in different buckets
    for (i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi]=arr[i];
    }
 
    // 3) Sort individual buckets
    for (i=0; i<n; i++)
       sort(b[i].begin(),n);
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          arr[index++] = b[i][j];
}
 
/* Driver program to test above funtion */
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
 
   // cout << "Sorted array is \n";
    int i;
    for (i=0; i<n; i++)
       printf("%f ",arr[i]);
     printf("\n");
    return 0;
}