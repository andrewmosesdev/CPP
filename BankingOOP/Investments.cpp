#include <iostream>
#include <iomanip>
#include <vector>

class Investment
{
private:
    // Initial amount invested
    double initialAmount;
    // Monthly deposit made into the investment
    double monthlyDeposit;
    // Annual interest rate in percentage
    double annualInterest;
    // Number of years for the investment
    int numberOfYears;
    // Number of months for the investment (calculated based on numberOfYears)
    int numberOfMonths;

public:
    // Constructor to initialize the investment account
    Investment(double initialAmount, double monthlyDeposit, double annualInterest, int numberOfYears)
        : initialAmount(initialAmount), monthlyDeposit(monthlyDeposit), annualInterest(annualInterest),
          numberOfYears(numberOfYears), numberOfMonths(numberOfYears * 12) {}

    // Function to calculate the interest earned on the investment
    double calculateInterest(double openingAmount, double depositedAmount)
    {
        // (opening amount + deposited amount) * (annual interest rate / 12 months)
        return (openingAmount + depositedAmount) * (annualInterest / 100.0 / 12.0);
    }

    // Function to display the yearly balances and interest earned WITHOUT monthly deposits
    void displayYearlyBalancesWithoutDeposits()
    {
        // Output header for the table
        std::cout << "Year\tYear End Balance\tYear End Earned Interest" << std::endl;
        // Keep track of the current balance
        double balance = initialAmount;
        // Loop through the number of years to calculate the yearly balance
        for (int year = 1; year <= numberOfYears; year++)
        {
            // Calculate the interest earned with no additional deposit
            double interest = calculateInterest(balance, 0);
            // Update the balance with the interest earned
            balance += interest;
            // Output the year, year-end balance, and interest earned
            std::cout << year << "\t$ " << std::fixed << std::setprecision(2) << balance << "\t\t$ " << interest << std::endl;
        }
    }

    // Function to display the yearly balances and interest earned WITH monthly deposits
    void displayYearlyBalancesWithDeposits()
    {
        // Output header for the table
        std::cout << "Year\tYear End Balance\tYear End Earned Interest" << std::endl;
        // Keep track of the current balance
        double balance = initialAmount;
        // Loop through the number of years to calculate the yearly balance
        for (int year = 1; year <= numberOfYears; year++)
        {
            // Calculate the interest earned with monthly deposit
            double interest = calculateInterest(balance, monthlyDeposit * numberOfMonths);
            // Update the balance with the interest earned and the total monthly deposits
            balance += interest + monthlyDeposit * numberOfMonths;
            // Output the year, year-end balance, and interest earned
            std::cout << year << "\t$ " << std::fixed << std::setprecision(2) << balance << "\t\t$ " << interest << std::endl;
        }
    }
};

int main()
{
    // Vars
    double initialAmount, monthlyDeposit, annualInterest;
    int numberOfYears;

    // Inputs and assignment
    std::cout << "Enter the initial investment amount: ";
    std::cin >> initialAmount;
    std::cout << "Enter the monthly deposit amount: ";
    std::cin >> monthlyDeposit;
    std::cout << "Enter the annual interest rate: ";
    std::cin >> annualInterest;
    std::cout << "Enter the number of years: ";
    std::cin >> numberOfYears;

    // Class instance
    Investment investment(initialAmount, monthlyDeposit, annualInterest, numberOfYears);

    // Outputs
    std::cout << std::endl
              << "Balances and Interest Without Additional Monthly Deposits:" << std::endl;
    investment.displayYearlyBalancesWithoutDeposits();

    std::cout << std::endl
              << "Balances and Interest With Additional $" << monthlyDeposit << " Monthly Deposits:" << std::endl;
    investment.displayYearlyBalancesWithDeposits();

    return 0;
}
