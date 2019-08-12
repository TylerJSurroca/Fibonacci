#include <stdio.h>
#include <time.h>

#define MAX_MEMORY 1000

unsigned long long g_fibNumbersWeveSeenSoFar[MAX_MEMORY];

unsigned long long getTheFibonacciNumberMemoization(int theFibNumberThatWeWant)
{

    //printf("theFibNumberThatWeWant = %d\n",theFibNumberThatWeWant);

    if(theFibNumberThatWeWant == 0)
        return 0;
    if(theFibNumberThatWeWant == 1)
        return 1;
    if(theFibNumberThatWeWant == 2)
        return 1;

    //Check if the number is in there
    if(g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant] != 0)
    {
        return g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant];
    }
    else
    {
        //Find the number with the Fibonacci algorithm and store it for later.
        g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant] = getTheFibonacciNumberMemoization(theFibNumberThatWeWant-2) +
                                                                                  getTheFibonacciNumberMemoization(theFibNumberThatWeWant-1);
        return g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant];
    }

}

unsigned long long getTheFibonacciNumberRecursive(int theFibNumberThatWeWant)
{
    if(theFibNumberThatWeWant == 0)
        return 0;
    if(theFibNumberThatWeWant == 1)
        return 1;
    if(theFibNumberThatWeWant == 2)
        return 1;

    return getTheFibonacciNumberRecursive(theFibNumberThatWeWant-2)+getTheFibonacciNumberRecursive(theFibNumberThatWeWant-1);

}

int getTheFibonacciNumberArray(int theFibNumberThatWeWant)
{
    int fibSeq[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181};

    if(theFibNumberThatWeWant > 19)
    {
        printf("ERROR: NUMBER NOT AVAILABLE\n");
        return NULL;
    }
    else
    {
        return(fibSeq[theFibNumberThatWeWant]);
    }

}

int main()
{
    int userInput;
    clock_t start, end;
    double cpu_time_used;
    unsigned long long returnValue;

    printf("Which Fibonacci number would you like to know about: \n");
    scanf("%d",&userInput);

    start = clock();
    returnValue = getTheFibonacciNumberMemoization(userInput-1);
    printf("Your Fibonacci number through Memoization is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    start = clock();
    returnValue = getTheFibonacciNumberArray(userInput-1);
    printf("Your Fibonacci number through an Array is: %d\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    start = clock();
    returnValue = getTheFibonacciNumberRecursive(userInput-1);
    printf("Your Fibonacci number through Recursion is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    return 0;
}
