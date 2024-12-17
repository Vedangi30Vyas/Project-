#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For formatting output

using namespace std;

// Class to represent a Bank Account
class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNum, double initialDeposit)
        : accountHolderName(name), accountNumber(accNum), balance(initialDeposit) {}

    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance! Your current balance is $" << balance << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << ". Remaining balance: $" << balance << endl;
        }
    }

    // Display account details
    void displayDetails() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    // Get account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

// Bank Management System
class BankSystem {
private:
    vector<BankAccount> accounts; // List of all bank accounts

public:
    // Create a new account
    void createAccount() {
        string name;
        int accNum;
        double initialDeposit;

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account Number: ";
        cin >> accNum;

        cout << "Enter Initial Deposit: $";
        cin >> initialDeposit;

        // Create a new account and add it to the list
        accounts.emplace_back(name, accNum, initialDeposit);
        cout << "Account created successfully!" << endl;
    }

    // Find an account by account number
    BankAccount* findAccount(int accNum) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    // Perform deposit
    void depositMoney() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account) {
            cout << "Enter Amount to Deposit: $";
            cin >> amount;
            account->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Perform withdrawal
    void withdrawMoney() {
        int accNum;
        double amount;

        cout << "Enter Account Number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account) {
            cout << "Enter Amount to Withdraw: $";
            cin >> amount;
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Display account details
    void displayAccountDetails() {
        int accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account) {
            account->displayDetails();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Main menu
    void menu() {
        int choice;
        do {
            cout << "\n--- Bank Management System ---" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Display Account Details" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    depositMoney();
                    break;
                case 3:
                    withdrawMoney();
                    break;
                case 4:
                    displayAccountDetails();
                    break;
                case 5:
                    cout << "Exiting the system. Thank you!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }
};

// Main function
int main() {
    BankSystem bank;
    bank.menu();
    return 0;
}

