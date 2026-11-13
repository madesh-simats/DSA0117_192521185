#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;
public:
    explicit Time(int total = 0) : seconds(total < 0 ? 0 : total) {}
    Time& operator++() { ++seconds; return *this; }       // prefix
    Time operator++(int) { Time old(*this); ++seconds; return old; } // postfix
    bool operator==(const Time& t) const { return seconds == t.seconds; }
    bool operator<(const Time& t) const { return seconds < t.seconds; }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;
        cout << h << ':' << (m < 10 ? "0" : "") << m
             << ':' << (s < 10 ? "0" : "") << s;
    }
};

class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> names) : tracks(names) {}
    string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }
    const string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size()))
            throw out_of_range("Playlist index out of range");
        return tracks[index];
    }
    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(3599);
    Time a = t++;
    Time b = ++t;
    cout << "a = "; a.display();
    cout << "\nb = "; b.display();
    cout << "\nt = "; t.display();
    cout << "\n";

    Playlist list{"Track One", "Track Two", "Track Three"};
    cout << "Playing: " << list[0] << '\n';
    list[1] = "Updated Track";
    cout << "Updated: " << list[1] << '\n';
    try {
        cout << list[list.size()] << '\n';
    } catch (const out_of_range& e) {
        cout << "Range check: " << e.what() << '\n';
    }
}
