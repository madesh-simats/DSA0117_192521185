#include <iostream>
using namespace std;

void byValue(long long fee, int percent) { fee -= fee * percent / 100; }
void byReference(long long& fee, int percent) { fee -= fee * percent / 100; }
void byPointer(long long* fee, int percent) {
    if (fee != nullptr) *fee -= (*fee) * percent / 100;
}
long long concessionResult(long long fee, int percent) {
    return fee - fee * percent / 100;
}

int main() {
    long long a = 45000, b = 45000, c = 45000;
    byValue(a, 10);
    byReference(b, 10);
    byPointer(&c, 10);
    cout << "After value: " << a << '\n';
    cout << "After reference: " << b << '\n';
    cout << "After pointer: " << c << '\n';
    cout << "Returned fee (25%): " << concessionResult(45000, 25) << '\n';
}
