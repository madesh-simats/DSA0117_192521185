#include <array>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balancePaise;
    array<long long, 10> transactions{};
    int count = 0;
    int next = 0; // next circular slot; oldest is at next when full

    void record(long long amount) { // inline inside class
        transactions[next] = amount;
        next = (next + 1) % static_cast<int>(transactions.size());
        if (count < static_cast<int>(transactions.size())) ++count;
    }
public:
    SavingsAccount(string number, long long openingPaise)
        : accountNumber(std::move(number)), balancePaise(openingPaise) {}
    bool deposit(long long amountPaise);
    bool withdraw(long long amountPaise);
    void miniStatement() const;
    long long balance() const { return balancePaise; }
};

bool SavingsAccount::deposit(long long amountPaise) {
    if (amountPaise <= 0) return false;
    balancePaise += amountPaise;
    record(amountPaise);
    return true;
}
bool SavingsAccount::withdraw(long long amountPaise) {
    if (amountPaise <= 0 || amountPaise > balancePaise) return false;
    balancePaise -= amountPaise;
    record(-amountPaise);
    return true;
}
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nTransactions (oldest to newest):\n";
    int start = (count == static_cast<int>(transactions.size())) ? next : 0;
    for (int i = 0; i < count; ++i) {
        long long v = transactions[(start + i) % static_cast<int>(transactions.size())];
        cout << (v >= 0 ? "Deposit " : "Withdraw ")
             << (v >= 0 ? v : -v) << " paise\n";
    }
    cout << "Balance: " << balancePaise << " paise\n";
}
int main() {
    SavingsAccount account("SB1001", 100000);
    account.deposit(5000);
    account.withdraw(2000);
    for (int i = 1; i <= 10; ++i) account.deposit(i * 100);
    account.miniStatement();
}
