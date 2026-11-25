#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Cart {
    std::string items_[10];
    double prices_[10]{};
    int n_ = 0;
    double discount_ = 0.0;

public:
    Cart& add(const std::string& item, double price) {
        if (n_ < 10) {
            items_[n_] = item;
            prices_[n_] = price;
            ++n_;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount_ = discount;
        return *this;
    }

    double total() const {
        double sum = 0.0;
        for (int i = 0; i < n_; ++i) sum += prices_[i];
        return sum * (100.0 - discount_) / 100.0;
    }

    void display() const {
        for (int i = 0; i < n_; ++i)
            std::cout << items_[i] << ": " << prices_[i] << '\n';
    }
};

int main() {
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    Cart* pointer = &c;
    pointer->add("Oil", 180);

    Cart& reference = c;
    reference.add("Soap", 40);

    Cart* dynamicCart = new Cart;
    dynamicCart->add("Milk", 30);
    std::cout << "Dynamic cart total: " << dynamicCart->total() << '\n';
    delete dynamicCart;

    std::cout << std::fixed << std::setprecision(2)
              << "Main cart total: " << pointer->total() << '\n';

    Cart second;
    second.add("Book", 250);
    Cart* carts[] = {&c, &second};
    const int count = 2;

    int highestIndex = 0;
    for (int i = 1; i < count; ++i) {
        if (carts[i]->total() > carts[highestIndex]->total())
            highestIndex = i;
    }
    std::cout << "Highest cart total: " << carts[highestIndex]->total() << '\n';
    return 0;
}
