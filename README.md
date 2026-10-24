# CS 210 Portfolio Project: Airgead Banking

## Project files

This repository contains my completed CS 210 Project Two files. The program collects investment information and shows year-end balances and interest with and without monthly deposits.

- main.cpp handles the prompts, input validation, and reports.
- Investment.h and Investment.cpp define the investment data and calculation methods.
- Pseudocode.txt records the plan for the calculations and program flow.

## Reflection

### Project summary
Airgead Banking is a console program that models how an initial investment can grow over time. It calculates year-end balances and interest for two cases: without extra deposits and with monthly deposits. This helps show how regular contributions can affect an investment.

### What I did particularly well
I separated the investment calculations from the console interface by putting the investment data and calculation methods in the Investment class. I reused one calculation routine for both cases, which keeps the monthly compounding rules consistent. The input loop also checks values through the class setters and gives the user another chance when a value is invalid.

### What I could improve
The program uses double for money and interest calculations, so rounding can build up over repeated monthly calculations. I could use integer cents for currency and apply clear rounding rules. I could also reject non-finite numbers, set a reasonable limit on the number of years, and add tests for edge cases and known results. These changes would make the results more reliable and help prevent unreasonable inputs.

### Most challenging part and support resources
The most challenging part for me was keeping both projections consistent while applying deposits and interest in the correct order each month. I used a shared calculation method and stored each year's ending balance and interest in a YearlyResult. The pseudocode helped me plan the loops before I wrote the C++ code. For future projects, I can use small example calculations, a debugger, compiler warnings, and unit tests to check my work.

### Transferable skills
This project helped me practice modeling a problem with a class, separating user interaction from calculations, validating input, and returning structured results from reusable functions. I can use these skills in other C++ projects that collect information, perform calculations, and present reports.

### Maintainability, readability, and adaptability
The Investment class manages the financial inputs and calculation behavior, while main.cpp handles prompts and output. Descriptive names, comments, const methods, and the YearlyResult structure make the code easier to follow. The shared calculation method also keeps the monthly compounding logic in one place, so it is easier to update. New report formats or scenarios could be added without rewriting the whole program.

## Build
With a C++11-compatible compiler, build from the repository root:

    g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Investment.cpp -o airgead_banking

Run the executable and enter an initial investment amount, monthly deposit, annual interest rate, and number of years.
