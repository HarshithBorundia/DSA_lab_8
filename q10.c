/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; 
        } 
    } 
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i; 
} 
int kthLargest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of  
    // elements in array 
    if (k > 0 && k <= r - l + 1) { 
  
        // Partition the array around last  
        // element and get position of pivot  
        // element in sorted array 
        int index = partition(arr, l, r); 
  
        // If position is same as k 
        if (index - l == k-1 ) 
            return arr[index]; 
  
        // If position is more, recur  
        // for left subarray 
        if (index - l > k-1 )  
            return kthLargest(arr, l, index - 1, k); 
  
        // Else recur for right subarray 
        return kthLargest(arr, index + 1, r,  
                            k); 
    } 
  
    // If k is more than number of  
    // elements in array 
    return 1e9; 
} 
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    k = n-k+1;
    printf("%d",kthLargest(a,0,n-1,k));

    return 0;
}

