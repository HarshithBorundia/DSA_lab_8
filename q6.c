/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int stack[n];
    int top=-1;
    int nge[n];
    nge[n-1] = 0;
    top++;
    stack[top] = n-1;
    for(int i=n-2;i>=0;i--){
        while(top!=-1 && a[stack[top]]<=a[i]){
            top--;
        }
        if(top==-1){
            nge[i] = 0;
        }
        else{
            nge[i] = stack[top]-i;
        }
        top++;
        stack[top] = i;
    }
    top=-1;
    int nse[n];
    nse[n-1] = 0;
    top++;
    stack[top] = n-1;
    for(int i=n-2;i>=0;i--){
        while(top!=-1 && a[stack[top]]>=a[i]){
            top--;
        }
        if(top==-1){
            nse[i] = 0;
        }
        else{
            nse[i] = stack[top] - i;
        }
        top++;
        stack[top] = i;
    }
    for(int i=0;i<n;i++){
        printf("%d ",nge[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",nse[i]);
    }
    printf("\n");
    return 0;
}

