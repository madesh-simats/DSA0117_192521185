#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double realPart, imagPart;

public:
    Complex() : realPart(0), imagPart(0) {}
    Complex(double real) : realPart(real), imagPart(0) {}
    Complex(double real, double imag) : realPart(real), imagPart(imag) {}

    Complex operator+(const Complex& z) const {
        return {realPart + z.realPart, imagPart + z.imagPart};
    }
    Complex operator-(const Complex& z) const {
        return {realPart - z.realPart, imagPart - z.imagPart};
    }
    Complex operator*(const Complex& z) const {
        return {realPart*z.realPart - imagPart*z.imagPart,
                realPart*z.imagPart + imagPart*z.realPart};
    }
    Complex operator/(const Complex& z) const {
        double denominator = z.realPart*z.realPart + z.imagPart*z.imagPart;
        if (denominator < 1e-12) throw domain_error("Division by zero impedance");
        return {(realPart*z.realPart + imagPart*z.imagPart)/denominator,
                (imagPart*z.realPart - realPart*z.imagPart)/denominator};
    }
    bool operator==(const Complex& z) const {
        return abs(realPart-z.realPart) < 1e-9 &&
               abs(imagPart-z.imagPart) < 1e-9;
    }
    double magnitude() const { return hypot(realPart, imagPart); }

    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << fixed << setprecision(2) << z.realPart;
        if (z.imagPart >= 0) out << " + j" << z.imagPart;
        else out << " - j" << -z.imagPart;
        return out;
    }
};

int main() {
    const double pi = acos(-1.0);
    const double frequency = 50.0;
    const double omega = 2.0 * pi * frequency;
    const double inductance = 0.1;
    const double capacitance = 100e-6;

    Complex resistor(10.0, 0.0);
    Complex inductor(0.0, omega * inductance);
    Complex capacitor(0.0, -1.0 / (omega * capacitance));

    Complex series = resistor + inductor + capacitor;
    cout << "Series impedance: " << series << '\n';
    cout << "Series magnitude: " << series.magnitude() << " ohms\n";

    Complex z1(10.0, 5.0), z2(20.0, -3.0);
    Complex parallel = (z1 * z2) / (z1 + z2);
    cout << "Parallel impedance: " << parallel << '\n';
    cout << "Parallel magnitude: " << parallel.magnitude() << " ohms\n";

    try {
        Complex invalid = z1 / Complex(0.0, 0.0);
        cout << invalid << '\n';
    } catch (const domain_error& e) {
        cout << "Safe error: " << e.what() << '\n';
    }
}
