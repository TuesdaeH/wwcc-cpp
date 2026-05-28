#include <iostream>
#include <string>
#include <vector>

const double SAVINGS_RATE = 1.03;
const double CHECKING_RATE = 1.01;
const double BUSINESS_RATE = 1.005;

class BankAccount {
private:
    std::string customerName;
    double balance;
    bool isOpen;
    int accountNumber;
    std::string accountType;

    struct Transaction {
        std::string type;
        double amount;
        double runningBalance;
    };
    std::vector<Transaction> history;

public:
    BankAccount(std::string name, int number, std::string type) {
        if (type != "savings" && type != "checking" && type != "business") {
            std::cout << "Invalid account type. Defaulting to checking.\n";
            type = "checking";
        }
        customerName = name;
        accountNumber = number;
        accountType = type;
        balance = 0.0;
        isOpen = true;
    }

    void deposit(double amount) {
        if (!isOpen) { std::cout << "Account is closed.\n"; return; }
        if (amount <= 0) { std::cout << "Deposit amount must be positive.\n"; return; }
        balance += amount;
        history.push_back({"Deposit", amount, balance});
    }

    void withdraw(double amount) {
        if (!isOpen) { std::cout << "Account is closed.\n"; return; }
        if (amount <= 0) { std::cout << "Withdrawal amount must be positive.\n"; return; }
        if (amount > balance) { std::cout << "Insufficient funds.\n"; return; }
        balance -= amount;
        history.push_back({"Withdrawal", amount, balance});
    }

    void applyInterest() {
        if (!isOpen) { std::cout << "Account is closed.\n"; return; }
        if (accountType == "savings") balance *= SAVINGS_RATE;
        else if (accountType == "checking") balance *= CHECKING_RATE;
        else if (accountType == "business") balance *= BUSINESS_RATE;
    }

    void print() const {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Customer Name: " << customerName << "\n";
        std::cout << "Balance: $" << balance << "\n";
        std::cout << "Account Type: " << accountType << "\n";
        std::cout << "Status: " << (isOpen ? "Open" : "Closed") << "\n";
    }

    void close() {
        isOpen = false;
    }

    double getBalance() const { return balance; }

    void printLastTransactions(int n) const {
        int start = std::max(0, (int)history.size() - n);
        std::cout << "Last " << n << " transactions:\n";
        for (int i = start; i < history.size(); i++) {
            std::cout << "  " << history[i].type << ": $" << history[i].amount
                      << " | Balance: $" << history[i].runningBalance << "\n";
        }
    }
};

int main() {
    BankAccount acc1("John Smith", 12345, "savings");

    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.applyInterest();
    acc1.print();

    std::cout << "\nTesting validation:\n";
    acc1.deposit(-50);
    acc1.withdraw(99999);

    std::cout << "\n";
    acc1.printLastTransactions(3);

    acc1.close();

    return 0;
}