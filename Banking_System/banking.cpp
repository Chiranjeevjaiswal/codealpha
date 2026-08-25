#include <iostream>
#include <string>
using namespace std;

// Transaction Class
class Transaction
{
public:
    string type;
    double amount;

    void display()
    {
        cout << type << " : Rs. " << amount << endl;
    }
};

// Account Class
class Account
{
public:
    int accountNumber;
    double balance;

    Transaction transactions[50];
    int transactionCount;

    Account()
    {
        accountNumber = 0;
        balance = 0;
        transactionCount = 0;
    }

    // Deposit money
    void deposit(double amount)
    {
        balance = balance + amount;

        transactions[transactionCount].type = "Deposit";
        transactions[transactionCount].amount = amount;
        transactionCount++;

        cout << "\nMoney deposited successfully!" << endl;
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "\nInsufficient balance!" << endl;
            return;
        }

        balance = balance - amount;

        transactions[transactionCount].type = "Withdrawal";
        transactions[transactionCount].amount = amount;
        transactionCount++;

        cout << "\nMoney withdrawn successfully!" << endl;
    }

    // Display account information
    void showAccount()
    {
        cout << "\n========== ACCOUNT DETAILS ==========" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Show transaction history
    void showTransactions()
    {
        cout << "\n========== TRANSACTION HISTORY ==========" << endl;

        if (transactionCount == 0)
        {
            cout << "No transactions found." << endl;
            return;
        }

        for (int i = 0; i < transactionCount; i++)
        {
            cout << i + 1 << ". ";
            transactions[i].display();
        }
    }
};

// Customer Class
class Customer
{
public:
    int customerID;
    string name;
    string phone;

    Account account;

    // Create customer
    void createCustomer()
    {
        cout << "\n========== CREATE CUSTOMER ==========" << endl;

        cout << "Enter Customer ID: ";
        cin >> customerID;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Phone Number: ";
        cin >> phone;

        cout << "Enter Account Number: ";
        cin >> account.accountNumber;

        cout << "\nCustomer created successfully!" << endl;
    }

    // Display customer details
    void showCustomer()
    {
        cout << "\n========== CUSTOMER DETAILS ==========" << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;

        account.showAccount();
    }
};

int main()
{
    Customer customer1;
    Customer customer2;

    int choice;
    double amount;

    cout << "========================================" << endl;
    cout << "          BANKING SYSTEM" << endl;
    cout << "========================================" << endl;

    // Create two customers
    cout << "\nCreate Customer 1";
    customer1.createCustomer();

    cout << "\nCreate Customer 2";
    customer2.createCustomer();

    do
    {
        cout << "\n\n========================================" << endl;
        cout << "              BANK MENU" << endl;
        cout << "========================================" << endl;

        cout << "1. Show Customer Details" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Show Transaction History" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int customer;

            cout << "\nEnter Customer (1 or 2): ";
            cin >> customer;

            if (customer == 1)
                customer1.showCustomer();
            else if (customer == 2)
                customer2.showCustomer();
            else
                cout << "Invalid customer!" << endl;

            break;
        }

        case 2:
        {
            int customer;

            cout << "\nEnter Customer (1 or 2): ";
            cin >> customer;

            cout << "Enter amount to deposit: ";
            cin >> amount;

            if (customer == 1)
                customer1.account.deposit(amount);
            else if (customer == 2)
                customer2.account.deposit(amount);
            else
                cout << "Invalid customer!" << endl;

            break;
        }

        case 3:
        {
            int customer;

            cout << "\nEnter Customer (1 or 2): ";
            cin >> customer;

            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (customer == 1)
                customer1.account.withdraw(amount);
            else if (customer == 2)
                customer2.account.withdraw(amount);
            else
                cout << "Invalid customer!" << endl;

            break;
        }

        case 4:
        {
            double transferAmount;

            cout << "\nEnter amount to transfer from Customer 1 to Customer 2: ";
            cin >> transferAmount;

            if (transferAmount > customer1.account.balance)
            {
                cout << "\nInsufficient balance!" << endl;
            }
            else
            {
                customer1.account.balance =
                    customer1.account.balance - transferAmount;

                customer2.account.balance =
                    customer2.account.balance + transferAmount;

                // Store transaction for sender
                customer1.account.transactions[
                    customer1.account.transactionCount
                ].type = "Transfer Sent";

                customer1.account.transactions[
                    customer1.account.transactionCount
                ].amount = transferAmount;

                customer1.account.transactionCount++;

                // Store transaction for receiver
                customer2.account.transactions[
                    customer2.account.transactionCount
                ].type = "Transfer Received";

                customer2.account.transactions[
                    customer2.account.transactionCount
                ].amount = transferAmount;

                customer2.account.transactionCount++;

                cout << "\nTransfer successful!" << endl;
            }

            break;
        }

        case 5:
        {
            int customer;

            cout << "\nEnter Customer (1 or 2): ";
            cin >> customer;

            if (customer == 1)
                customer1.account.showTransactions();
            else if (customer == 2)
                customer2.account.showTransactions();
            else
                cout << "Invalid customer!" << endl;

            break;
        }

        case 6:
            cout << "\nThank you for using the Banking System!" << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
