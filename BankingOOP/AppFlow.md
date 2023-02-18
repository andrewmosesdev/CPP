# Class: InvestmentCalculator

- Store data and perform calculations

## Private member variables

- Initial investment amount
- Monthly deposit amount
- Annual interest rate
- Number of years
- Other related values

## Constructor function

- Takes in initial investment amount, monthly deposit amount, annual interest rate, and number of years as arguments
- Stores them in corresponding private member variables

## Public member function: calculateWithoutDeposits

- Calculates year-end balances and earned interest without monthly deposits
- Loops for number of years
- Calculates year-end balance and earned interest for each year

## Public member function: calculateWithDeposits

- Calculates year-end balances and earned interest with monthly deposits
- Loops for number of years
- Calculates year-end balance and earned interest for each year, taking into account monthly deposit amount

## Public member function: displayResults

- Displays results of calculations
- Prints header for year-end balances and earned interest without monthly deposits
- Calls calculateWithoutDeposits function and prints results
- Prints header for year-end balances and earned interest with monthly deposits
- Calls calculateWithDeposits function and prints results

## Main function

- Creates instance of InvestmentCalculator class
- Passes initial investment amount, monthly deposit amount, annual interest rate, and number of years entered by user
- Calls displayResults function on instance of InvestmentCalculator class to display results
