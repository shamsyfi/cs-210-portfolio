/*
 * File: Investment.h
 * Author: Shamsy Fiza
 * Course: CS-210
 * Purpose: Declares the Investment class for the Airgead Banking app.
 */
#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>

 // Holds the results for one year of an investment.
struct YearlyResult {
    int year;
    double yearEndBalance;
    double yearEndInterest;
};

class Investment {
public:
    // Creates an investment with all values set to zero.
    Investment();

    // Setters. Each returns false when the value is invalid.
    bool setInitialInvestment(double amount);
    bool setMonthlyDeposit(double amount);
    bool setAnnualInterest(double percent);
    bool setNumberOfYears(int years);

    // Getters. Each is const because it does not change the object.
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumberOfYears() const;

    // Calculates yearly results with and without monthly deposits.
    std::vector<YearlyResult> calculateWithoutDeposits() const;
    std::vector<YearlyResult> calculateWithDeposits() const;

private:
    // Shared calculation. The deposit argument is added every month.
    std::vector<YearlyResult> calculate(double monthlyDeposit) const;

    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;   // Stored as a percent, such as 5.0.
    int m_numberOfYears;
};

#endif
