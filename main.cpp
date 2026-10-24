/*
 * File: main.cpp
 * Author: Shamsy Fiza
 * Course: CS-210
 * Purpose: Console interface for the Airgead Banking investment app.
 */
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#include "Investment.h"

 // Reads a number and repeats the prompt until the input is valid.
template <typename T>
T readValue(const std::string& prompt, bool (Investment::* setter)(T), Investment& investment) {
    T value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && (investment.*setter)(value)) {
            return value;
        }
        // Clear the error state and discard the bad input.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
}

// Prints the input screen with the current values.
void printInputScreen(const Investment& inv, bool showValues) {
    std::cout << std::string(36, '*') << "\n";
    std::cout << std::string(10, '*') << " Data Input " << std::string(10, '*') << "\n";
    if (showValues) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Initial Investment Amount: $" << inv.getInitialInvestment() << "\n";
        std::cout << "Monthly Deposit: $" << inv.getMonthlyDeposit() << "\n";
        std::cout << "Annual Interest: " << inv.getAnnualInterest() << "%\n";
        std::cout << "Number of years: " << inv.getNumberOfYears() << "\n";
    }
}

// Formats a number as a dollar amount with two decimals.
std::string formatMoney(double amount) {
    std::ostringstream out;
    out << "$" << std::fixed << std::setprecision(2) << amount;
    return out.str();
}

// Prints one report table.
void printReport(const std::string& title, const std::vector<YearlyResult>& results) {
    std::cout << "\n  " << title << "\n";
    std::cout << std::string(60, '=') << "\n";
    std::cout << std::left << std::setw(8) << "Year"
        << std::right << std::setw(26) << "Year End Balance"
        << std::setw(26) << "Year End Earned Interest" << "\n";
    std::cout << std::string(60, '-') << "\n";
    for (const YearlyResult& row : results) {
        // Format each value as a string so setw aligns the dollar sign.
        std::cout << std::left << std::setw(8) << row.year
            << std::right << std::setw(26) << formatMoney(row.yearEndBalance)
            << std::setw(26) << formatMoney(row.yearEndInterest) << "\n";
    }
}

int main() {
    Investment investment;
    printInputScreen(investment, false);

    // Collect and validate all four inputs.
    readValue<double>("Initial Investment Amount: $", &Investment::setInitialInvestment, investment);
    readValue<double>("Monthly Deposit: $", &Investment::setMonthlyDeposit, investment);
    readValue<double>("Annual Interest (%): ", &Investment::setAnnualInterest, investment);
    readValue<int>("Number of years: ", &Investment::setNumberOfYears, investment);

    // Wait for the user before showing the reports.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPress Enter to continue . . .";
    std::cin.get();

    // Show the entered values above the reports.
    printInputScreen(investment, true);
    printReport("Balance and Interest Without Additional Monthly Deposits",
        investment.calculateWithoutDeposits());
    printReport("Balance and Interest With Additional Monthly Deposits",
        investment.calculateWithDeposits());
    return 0;
}
