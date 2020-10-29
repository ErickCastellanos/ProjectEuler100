
/* 
    The prime factors of 13195 are 5, 7, 13 and 29.
    The largest among them is 29
    Write a program to find the largest prime factor of a number?
*/

#include<stdio.h>
#include<math.h>

int prime(int number){  //For letting in only prime numbers inside loop
    for (int i=3; i<=number/2; ++i){
        if(!(number % i == 0)){
            return 1;
        }
        else{
            return 0;
            break;
        }
    }
}

int main(){
    long limit, maxPrimeFactor, i;
    scanf("%ld", &limit);
    /*
    First divide the number by 2 for highest possible times in order to reduce it.
    */
    while(limit % 2 == 0){
        limit /= 2;
        maxPrimeFactor = 2;
    }
    /* 
    It is a convention that the prime factor would always be less than or equal to square root of the number 
    */
    for(i=3; i <= sqrt(limit); i = i+2){  //Increment by 2 for getting only odd numbers
        if(prime(i)){
            while(limit % i == 0){
                maxPrimeFactor = i;
                limit /= i;
            }
        }
    }
    if(limit > 2 && prime(limit)){
        maxPrimeFactor = limit;
    }
    printf("%ld", maxPrimeFactor);
    return 0;
}