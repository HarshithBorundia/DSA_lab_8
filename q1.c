/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
int main()
{   char a[1000000];
    int j = -1;
    char arr[1000000];
    scanf("%s",arr);
    int len = strlen(arr);
    for(int i=0;i<len;i++){
        if(arr[i]=='{'|| arr[i]=='('|| arr[i]=='['){
            j++;
            a[j] = arr[i];
        }
        else{
            if(j==-1){
                printf("NO");
                return 0;
            }
            if(arr[i]==']'){
                if(a[j]=='[')j--;
                else{
                    printf("NO");
                    return 0;
                }
            }
            else if(arr[i]=='}'){
                if(a[j]=='{')j--;
                else{
                    printf("NO");
                    return 0;
                }
            }
            else if(arr[i]==')'){
                if(a[j]=='(')j--;
                else{
                    printf("NO");
                    return 0;
                }
            }
            
        }
    }
    printf("YES");

    return 0;
}

