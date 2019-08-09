#include <stdio.h>

int fibonacciSequence(int n)
{
    /*int fibSeq[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181};
    return(fibSeq[x-1]);
    */

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;

    return fibonacciSequence(n-2)+fibonacciSequence(n-1);

}

int main()
{
    int userInput;

    printf("Which Fibonacci number would you like to know about: \n");
    scanf("%d",&userInput);
    printf("Your Fibonacci number is: %d\n",fibonacciSequence(userInput-1));

    return(0);
}
