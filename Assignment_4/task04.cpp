#include <iostream>
#include <memory>
#include <vector>

struct Account {
    double rate() const { return 3.5; }              // non-virtual
    virtual double vrate() const { return 3.5; }     // virtual
    virtual ~Account() { std::cout << "~Account\n"; }
};

struct SeniorAccount : Account {
    double rate() const { return 4.0; }
    double vrate() const override { return 4.0; }
    ~SeniorAccount() override { std::cout << "~SeniorAccount\n"; }
};

int main() {
    SeniorAccount senior;
    Account* p = &senior;
    Account slicedCopy = senior;

    std::cout << p->rate() << ' ' << p->vrate()
              << ' ' << slicedCopy.vrate() << '\n';

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Account>());
    accounts.push_back(std::make_unique<SeniorAccount>());

    for (const auto& account : accounts)
        std::cout << account->vrate() << '\n';

    return 0;
}
