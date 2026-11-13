#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;

public:
    explicit Text(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "[copy] ";
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* fresh = new char[strlen(other.data) + 1];
            strcpy(fresh, other.data);
            delete[] data;
            data = fresh;
        }
        return *this;
    }

    ~Text() { delete[] data; }

    Text operator+(const Text& other) const {
        size_t n = strlen(data) + strlen(other.data);
        char* joined = new char[n + 1];
        strcpy(joined, data);
        strcat(joined, other.data);
        Text result(joined);
        delete[] joined;
        return result;
    }

    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }
    bool operator!=(const Text& other) const { return !(*this == other); }

    friend ostream& operator<<(ostream& out, const Text& t) {
        return out << t.data;
    }
};

int main() {
    Text a("Hello"), b(" "), c("World");
    Text message = a + b + c;
    cout << "\nMessage: " << message << '\n';

    Text empty;
    cout << "Empty text: [" << empty << "]\n";
    Text copy = message;
    copy = copy; // self-assignment
    cout << "Copy equals original: " << boolalpha << (copy == message) << '\n';

    Text longText("A longer SMS gateway message for testing.");
    cout << "Long message: " << longText << '\n';
}
