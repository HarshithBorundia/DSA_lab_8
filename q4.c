#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int stack[n];
    int top = -1;
    int leftSmall[n], rightSmall[n];

    // Calculate leftSmaller
    for(int i = 0; i < n; i++) {
        while(top != -1 && a[stack[top]] >= a[i]) {
            top--;
        }
        if(top == -1) {
            leftSmall[i] = 0;
        } else {
            leftSmall[i] = stack[top] + 1;
        }
        top++;
        stack[top] = i;
    }

    top = -1;
    // Calculate rightSmaller
    for(int i = n - 1; i >= 0; i--) {
        while(top != -1 && a[stack[top]] >= a[i]) {
            top--;
        }
        if(top == -1) {
            rightSmall[i] = n - 1;
        } else {
            rightSmall[i] = stack[top] - 1;
        }
        top++;
        stack[top] = i;
    }

    long long maxi = 0;
    for(int i = 0; i < n; i++) {
        long long temp = (rightSmall[i] - leftSmall[i] + 1) * (long long)a[i];
        if(temp > maxi) {
            maxi = temp;
        }
    }

    printf("%lld ", maxi);
}
