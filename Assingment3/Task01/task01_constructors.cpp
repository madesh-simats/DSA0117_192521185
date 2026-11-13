#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 1) {}
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c < 0 ? throw invalid_argument("Copies cannot be negative") : c) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};

class ExplicitDemo {
public:
    explicit ExplicitDemo(int value) { cout << "Explicit value: " << value << '\n'; }
};

int main() {
    try {
        Book empty;
        Book donated("The Alchemist");
        Book complete("Wings of Fire", "A. P. J. Abdul Kalam", 5);

        cout << "Default constructor:\n"; empty.display();
        cout << "Title-only constructor:\n"; donated.display();
        cout << "Parameterized constructor:\n"; complete.display();

        ExplicitDemo valid(10);
        // ExplicitDemo invalid = 10; // Uncomment to see compile-time error.

        try {
            Book invalid("Bad Record", "Unknown", -2);
            invalid.display();
        } catch (const invalid_argument& e) {
            cout << "Invalid book rejected: " << e.what() << '\n';
        }
    } catch (const exception& e) {
        cerr << e.what() << '\n';
    }
}
