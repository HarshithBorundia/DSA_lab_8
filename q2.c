/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void max_heapify(int a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}

void build_max_heap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int b[k];
    for(int i=0;i<k;i++){
        b[i] = a[i];
    }
    build_max_heap(b,k);
    printf("%d ",b[0]);
    int j = 0;
    for(int i=k;i<n;i++){
        for(int t=0;t<k;t++){
            if(b[t]==a[j]){
                b[t] = a[i];
                build_max_heap(b,k);
                j++;
                break;
            }
        }
        printf("%d ",b[0]);
    }
    return 0;
}

