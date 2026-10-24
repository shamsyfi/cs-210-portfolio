/*
 * File: Investment.cpp
 * Author: Shamsy Fiza
 * Course: CS-210
 * Purpose: Implements the Investment class for the Airgead Banking app.
 */
#include "Investment.h"

namespace {
    const int MONTHS_PER_YEAR = 12;
    const double PERCENT_DIVISOR = 100.0;
}

Investment::Investment()
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterest(0.0),
    m_numberOfYears(0) {
}

bool Investment::setInitialInvestment(double amount) {
    // Reject negative amounts.
    if (amount < 0.0) {
        return false;
    }
    m_initialInvestment = amount;
    return true;
}

bool Investment::setMonthlyDeposit(double amount) {
    // Reject negative deposits.
    if (amount < 0.0) {
        return false;
    }
    m_monthlyDeposit = amount;
    return true;
}

bool Investment::setAnnualInterest(double percent) {
    // Reject negative rates.
    if (percent < 0.0) {
        return false;
    }
    m_annualInterest = percent;
    return true;
}

bool Investment::setNumberOfYears(int years) {
    // Require at least one year.
    if (years < 1) {
        return false;
    }
    m_numberOfYears = years;
    return true;
}

double Investment::getInitialInvestment() const { return m_initialInvestment; }
double Investment::getMonthlyDeposit() const { return m_monthlyDeposit; }
double Investment::getAnnualInterest() const { return m_annualInterest; }
int Investment::getNumberOfYears() const { return m_numberOfYears; }

std::vector<YearlyResult> Investment::calculateWithoutDeposits() const {
    // A deposit of zero removes the monthly deposit from the math.
    return calculate(0.0);
}

std::vector<YearlyResult> Investment::calculateWithDeposits() const {
    return calculate(m_monthlyDeposit);
}

std::vector<YearlyResult> Investment::calculate(double monthlyDeposit) const {
    std::vector<YearlyResult> results;
    results.reserve(m_numberOfYears);

    double balance = m_initialInvestment;
    const double monthlyRate = m_annualInterest / PERCENT_DIVISOR / MONTHS_PER_YEAR;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearInterest = 0.0;

        for (int month = 1; month <= MONTHS_PER_YEAR; ++month) {
            // Add the deposit first, then earn interest on the new total.
            balance += monthlyDeposit;
            const double monthInterest = balance * monthlyRate;
            balance += monthInterest;
            yearInterest += monthInterest;
        }

        // Save the year-end totals.
        results.push_back({ year, balance, yearInterest });
    }
    return results;
}
