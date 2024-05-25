/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int stack[n];
    int top = -1;
    int right[n];
    int end = -1;
    top++;
    stack[top] = n-1;
    right[n-1] = n-1;
    for(int i=n-2;i>=0;i--){
        int val = top;
        while(val!=end && abs(a[stack[val]]-a[i])<=k){
            val--;
        }
        end = val;
        right[i] = stack[val+1];
        top++;
        stack[top] = i;
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += right[i]-i+1;
    }
    printf("%lld",ans);
    return 0;
}


