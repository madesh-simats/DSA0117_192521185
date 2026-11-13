#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}

    Money operator+(const Money& other) const {
        return Money(0, static_cast<int>(paise + other.paise));
    }

    Money operator-(const Money& other) const {
        return Money(0, static_cast<int>(paise - other.paise));
    }

    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    bool operator==(const Money& other) const { return paise == other.paise; }
    bool operator<(const Money& other) const { return paise < other.paise; }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long magnitude = m.paise < 0 ? -m.paise : m.paise;
        if (m.paise < 0) out << "-";
        out << "Rs " << magnitude / 100 << '.'
            << setw(2) << setfill('0') << magnitude % 100 << setfill(' ');
        return out;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << '\n' << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << "Carry test: " << x + y << '\n';

    Money bill(100, 0);
    bill += Money(25, 50);
    cout << "Bill after +=: " << bill << '\n';
    cout << "Is bill less than Rs 200? " << (bill < Money(200)) << '\n';
    cout << "Negative subtraction: " << Money(10) - Money(12, 50) << '\n';
}
