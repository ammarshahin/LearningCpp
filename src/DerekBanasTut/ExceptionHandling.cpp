//*! EXCEPTION HANDLING EX1
//* Exceptions are errors that occur when things don't go as expected.
//* 1. You expect and int and get a string
//* 2. You expect a file to be available and it isn't
//* 3. You expect the user to not enter 0 and they do
//* You try to execute code that could be troublesome
//* and if an error occurs you catch it and throw it to another block of code for handling

#include <iostream>

int main(int argc, char const *argv[])
{

    double num1, num2;

    std::cout << "Enter number 1 : ";
    std::cin >> num1;
    std::cout << "Enter number 2 : ";
    std::cin >> num2;

    try
    {
        if (num2 == 0)
        {
            throw "Division by zero is not possible";
        }
        else
        {

            printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
        }
    }

    catch (const char *exp)
    {
        std::cout << "Error : " << exp << "\n";
    }

    // ----- END OF EXCEPTION HANDLING EX 1 -----

    // ----- EXCEPTION HANDLING EX 2 -----
    try
    {
        std::cout << "Throwing exception\n";

        // Another way to throw an exception
        throw std::runtime_error("Error Occurred");

        // This point is never reached
        std::cout << "Can you print me?\n";
    }

    // All exceptions are based on std::exception
    catch (std::exception &exp)
    {

        // what() Prints an explanatory string
        std::cout << "Handled Exception : " << exp.what() << "\n";
    }

    // If exceptions aren't caught any place else
    // this will catch it
    catch (...)
    {
        std::cout << "Default exception catch\n";
    }
    // ----- END OF EXCEPTION HANDLING EX 2 -----

    /* code */
    return 0;
}