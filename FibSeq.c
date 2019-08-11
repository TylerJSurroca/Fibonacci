#include <stdio.h>
#include <time.h>

#define MAX_MEMORY 1000

unsigned long long g_fibNumbersWeveSeenSoFar[MAX_MEMORY];

unsigned long long getTheFibonacciNumber(int theFibNumberThatWeWant)
{
    /*int fibSeq[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181};
    return(fibSeq[n-1]);
    */

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
        g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant] = getTheFibonacciNumber(theFibNumberThatWeWant-2) +
                                                                                  getTheFibonacciNumber(theFibNumberThatWeWant-1);
        return g_fibNumbersWeveSeenSoFar[theFibNumberThatWeWant];
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
    returnValue = getTheFibonacciNumber(userInput-1);
    printf("Your Fibonacci number is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    start = clock();
    returnValue = getTheFibonacciNumber(userInput-1);
    printf("Your Fibonacci number is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    start = clock();
    returnValue = getTheFibonacciNumber(userInput-1);
    printf("Your Fibonacci number is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    start = clock();
    returnValue = getTheFibonacciNumber(userInput-1);
    printf("Your Fibonacci number is: %llu\n",returnValue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf seconds\n",cpu_time_used);

    return 0;
}
