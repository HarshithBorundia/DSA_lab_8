/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
int partition(int a[],int low,int high,int ans){
    int ind = -1;
    for(int t=low;t<=high;t++){
        if(a[t]==ans){
            ind = t;
            break;
        }
    }
    int temp1 = a[ind];
    a[ind] = a[high];
    a[high] = temp1;
    int x = a[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(a[j]<=x){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = x;
    a[high] = temp;
    return i+1;
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j;
        for( j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int select(int l,int r,int k,int a[]){
    int size = r-l+1;
    int s = size/5;
    int arr[s+1][5];
    int j = l;
    for(int i=0;i<s;i++){
        for(int t=0;t<5;t++){
            arr[i][t] = a[j++];
        }
    }
    int val = 0;
    if(size%5){
        int i = 0;
        while(j<=r){
            arr[s][i++] = a[j++];
        }
        val = i;
    }
    int median[s+1];
    for(int i=0;i<s+1;i++){
        median[i] = -1;
    }
    for(int i=0;i<s;i++){
        int temp[5];
        for(int t=0;t<5;t++){
            temp[t] = arr[i][t];
        }
        insertionSort(temp,5);
        median[i] = temp[2];
    }
    bool f = false;
    if(val){
        int temp[val];
        for(int i=0;i<val;i++){
            temp[i] = arr[s][i];
        }
        insertionSort(temp,val);
        median[s] = temp[(val-1)/2];
        f = true;
    }
    int end = s;
    if(f)end = s+1;
    int temp[end];
    for(int i=0;i<end;i++){
        temp[i] = median[i];
    }
    insertionSort(temp,end);
    int ans = temp[(end-1)/2];
    int index = partition(a,l,r,ans);
    if(index==k-1) return ans;
    else if(index>k-1) return select(l,index-1,k,a);
    else return select(index+1,r,k,a);
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
    printf("%d",select(0,n-1,k,a));

    return 0;
}



