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

// 2. -------------------------------------------------------------------------------

// import necessary library
#include <iostream>
#include <stdlib.h>

// function that calculates the area of rectangle
float areaOfRectangle (float base, float height) {
    return base * height;
}

// higher order function that invokes the areaOfRectangle function
void askForBaseHeightPrintArea (float (*function)(float,float)) {
    // declare variables
    float base,height;
    
    // i/o
    std::cout << "Enter Base: ";
    if(!(std::cin >> base)){
        std::cout << "Please enter a valid character, enter only a number. Re-run the program!";
        exit(1);
    }
    std::cout << "Enter Height: ";
    if(!(std::cin >> height)){
        std::cout << "Please enter a valid character, enter only a number. Re-run the program!";
        exit(1);
    }
    
    // print and invoke the callback function
    std::cout << "Area is: " << function(base,height);
}

int main() {
    // call the higher order function 
    askForBaseHeightPrintArea(&areaOfRectangle);

    // successful execution
    return 0;
}
