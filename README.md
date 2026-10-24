# CS 210 Portfolio Project: Airgead Banking

## Project files

The `AirgeadBanking/` folder contains the completed CS 210 Project Two source files and pseudocode. The program collects investment assumptions and reports year-end balances and interest with and without monthly deposits.

## Reflection

### Project summary

Airgead Banking is a console program that models how an initial investment can grow over time. It calculates yearly ending balances and interest for two scenarios: without additional deposits and with recurring monthly deposits. This gives a user a clear way to compare the effect of regular contributions.

### What I did particularly well

I separated the investment calculations from the console interface by putting the investment data and calculation methods in the `Investment` class. I also reused one calculation routine for both scenarios, which keeps their monthly compounding rules consistent. The input loop checks values through the class setters and gives the user another chance when a value is invalid.

### What I could improve

The program stores money and interest calculations in `double`, so rounding can accumulate during repeated monthly calculations. I could use integer cents for currency or a decimal type with defined rounding rules. I could also reject non-finite numeric inputs, set a reasonable maximum for the number of years, and add automated tests for boundary values and known calculation examples. These changes would make results more predictable and protect the program from unreasonable input sizes.

### Most challenging part and support resources

The most challenging part was keeping the two projections consistent while applying monthly deposits and compounding interest in the correct order. I addressed this by using a shared calculation method and recording each year's ending balance and interest in a `YearlyResult`. The pseudocode helped me plan the loops before implementing them. For future work, I can build on that approach with small calculation examples, a debugger, compiler warnings, and unit tests to check edge cases.

### Transferable skills

This project strengthened my ability to model a problem with a class, divide a program into interface and calculation responsibilities, validate user input, and return structured results from reusable functions. Those skills transfer to other C++ programs that collect data, apply repeated calculations, and present reports.

### Maintainability, readability, and adaptability

The `Investment` class owns the financial inputs and calculation behavior, while `main.cpp` handles prompts and output. Descriptive names, `const` getters and calculation methods, comments, and the `YearlyResult` structure make the code easier to follow. Keeping the shared monthly calculation in one method also means a change to the compounding logic can be made in one place. Additional report formats or calculation scenarios could be added without rewriting the existing user interface from scratch.

## Build

With a C++11-compatible compiler, build from the `AirgeadBanking/` directory:

```sh
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Investment.cpp -o airgead_banking
```

Run the resulting executable and enter an initial investment amount, monthly deposit, annual interest rate, and number of years.
