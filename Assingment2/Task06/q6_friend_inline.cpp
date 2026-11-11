#include <iostream>
#include <cstdlib>
using namespace std;
class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend inline int minutesBetween(const Time& a, const Time& b);
    friend inline bool earlier(const Time& a, const Time& b);
};
inline int minutesBetween(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m, y = b.h * 60 + b.m;
    return std::abs(x - y); // TODO 1
}
inline bool earlier(const Time& a, const Time& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m; // TODO 2
}
int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';
    Time noonBefore(11, 59), noonAfter(12, 1), same(12, 1);
    cout << minutesBetween(noonBefore, noonAfter) << ' '
         << earlier(noonBefore, noonAfter) << ' '
         << earlier(same, noonAfter) << '\n';
}
