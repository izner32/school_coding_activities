// 1 
#include <iostream>
#include <cctype>

int main() {
    char carillo, normalizedCarillo;
    bool tryAgain = true;
    int iteration = 1;
    double num1,num2,sum;

    do {
        std::cout << "Iteration: " << iteration << std::endl;
        // ask user to input two numbers 
        std::cout << "Enter first number: ";
        std::cin >> num1; 
        std::cout << "Enter second number: ";
        std::cin >> num2; 

        // calculate and display 
        sum = num1 + num2;
        std::cout << "Sum of the numbers is: " << sum << std::endl;

        // ask user to try again 
        std::cout << "\nDo you want to try again? (Y/N): ";
        std::cin >> carillo;
        std::cout << "\n";
        
        // normalizing input
        normalizedCarillo = toupper(carillo);
        tryAgain = (normalizedCarillo != 'Y') ? false : true;
        
        if (!tryAgain){
            std::cout << "Initiating exit.";
        }
        
        iteration++;
    } while(tryAgain);

    return 0;
}

// 2 
#include <iostream>

int main() {
    double p, r, m, t;
    static double carillo = 1, iteration = 1;
    
    // ask for input 
    std::cout << "Enter Principal Amount: ";
    std::cin >> p;
    std::cout << "Enter Rate of Return: ";
    std::cin >> r;
    std::cout << "Enter No. of Time Compounded Annually: ";
    std::cin >> m;
    std::cout << "Enter No. of Years for investment: ";
    std::cin >> t;
    
    // calculate for compound interest 
    while (iteration <= m*t){
        carillo = carillo * (1+(r/100));
        iteration++;
    }
    carillo = p*carillo;
    
    // print output 
    std::cout << "\nFuture value of investment is: " << carillo;
    return 0;
}

