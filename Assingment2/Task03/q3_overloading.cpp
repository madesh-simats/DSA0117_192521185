#include <iostream>
using namespace std;
struct Parcel { double kilograms; bool express; bool insured; };

double charge(double kilograms, bool express = false, bool insured = false) {
    double total = kilograms * 40.0;
    if (express) total += 50.0;
    if (insured) total += 25.0;
    return total;
}
double charge(int grams) {
    return charge(grams / 1000.0, false, false);
}
double charge(const Parcel& p) {
    return charge(p.kilograms, p.express, p.insured);
}
int main() {
    Parcel p{2.5, true, true};
    cout << "charge(2) [int grams]: " << charge(2) << '\n';
    cout << "charge(2.0) [kg]: " << charge(2.0) << '\n';
    cout << "charge(2.0f) [float to double]: " << charge(2.0f) << '\n';
    cout << "charge(2.0, true): " << charge(2.0, true) << '\n';
    cout << "charge(2.0, true, true): " << charge(2.0, true, true) << '\n';
    cout << "charge(Parcel): " << charge(p) << '\n';
}
