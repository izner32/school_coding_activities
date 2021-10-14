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
