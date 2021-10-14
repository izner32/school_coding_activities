/* 
Sir, i've added 2 features po, and used advance concepts such as higher order function. I also made sure to employ the best practices, 
it is usually not a good idea to fill the main thread(main function) with unencapsulated codes. 
    
Features i've added:
    - if the input from the user isn't a number, return a message and forcefully end the program
    - if the arithmetic result doesn't have a floating point, print them as integer, otherwise print them as a float
*/

// import necessary library
#include <stdio.h>
#include <math.h>

// function that prints the basic arithmetic calculations for the specified input
void arithmetic (float firstNumber, float secondNumber) {
    // if the result of arithmetic calculations has decimal print float, if not print int; multiple conditional statement has to be placed since you cannot change the datatype at runtime
    if ((firstNumber - floor(firstNumber)) + (secondNumber - floor(secondNumber)) >= 0 ){
        printf("Sum: %d\n", (int)firstNumber + (int)secondNumber);
    } else {
        printf("Sum: %.2f\n", firstNumber + secondNumber);
    }
    if ((firstNumber - floor(firstNumber)) - (secondNumber - floor(secondNumber)) >= 0 ){
        printf("Difference: %d\n", (int)firstNumber - (int)secondNumber);
    } else {
        printf("Difference: %.2f\n", firstNumber - secondNumber);
    }
    if ((firstNumber - floor(firstNumber)) * (secondNumber - floor(secondNumber)) >= 0 ){
        printf("Product: %d\n", (int)firstNumber * (int)secondNumber);
    } else {
        printf("Product: %.2f\n", firstNumber * secondNumber);
    }
    if ((firstNumber - floor(firstNumber)) / (secondNumber - floor(secondNumber)) >= 0 ){
        printf("Quotient: %d\n", (int)firstNumber / (int)secondNumber);
    } else {
        printf("Quotient: %.2f\n", firstNumber / secondNumber);
    }
}

// creating a higher order function that makes use of a callback function
void askNumbersCalculateArithmetic (void (*f)(float,float)){
    // declaring variables
    float firstNumber,secondNumber;
    
    // i/o - ask for the user to rerun the program if they enter an invalid character
    printf("Enter the first number: ");
    if(scanf("%f",&firstNumber) != 1){
        printf("Invalid character for first number, please enter a number. Re-run the program!");
        exit(0);
    }
    printf("Enter the second number: ");
    if(scanf("%f",&secondNumber) != 1){
        printf("Invalid character for second number, please enter a number. Re-run the program");
        exit(0);
    }
    
    // invoking the arithmetic function/callback function
    (*f)(firstNumber,secondNumber);
}

int main() {
    // invoke the function
    askNumbersCalculateArithmetic(arithmetic);
    
    // success execution for main thread
    return 0;
}
