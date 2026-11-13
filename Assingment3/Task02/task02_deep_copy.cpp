#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    explicit Prescription(int count)
        : n(count < 0 ? throw invalid_argument("Count cannot be negative") : count),
          medicines(new string[n]) {}

    Prescription(const Prescription& other)
        : n(other.n), medicines(new string[other.n]) {
        for (int i = 0; i < n; ++i) medicines[i] = other.medicines[i];
        cout << "Copy constructor called\n";
    }

    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* fresh = new string[other.n];
            for (int i = 0; i < other.n; ++i) fresh[i] = other.medicines[i];
            delete[] medicines;
            medicines = fresh;
            n = other.n;
        }
        return *this;
    }

    ~Prescription() { delete[] medicines; }

    void set(int i, const string& m) {
        if (i < 0 || i >= n) throw out_of_range("Medicine index out of range");
        medicines[i] = m;
    }
    string get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("Medicine index out of range");
        return medicines[i];
    }
    int size() const { return n; }
};

void byValue(Prescription p) { cout << "Passed by value\n"; }
void byReference(const Prescription& p) { cout << "Passed by const reference\n"; }

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;
    p.set(0, "Ibuprofen");
    r = r; // self-assignment test

    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';

    byValue(p);
    byReference(p);
}
