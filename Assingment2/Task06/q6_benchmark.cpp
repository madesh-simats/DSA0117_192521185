#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

class ClockTime {
    int h, m;
public:
    ClockTime(int hh, int mm) : h(hh), m(mm) {}
    friend inline bool earlierInline(const ClockTime&, const ClockTime&);
    friend bool earlierNoInline(const ClockTime&, const ClockTime&);
};
inline bool earlierInline(const ClockTime& a, const ClockTime& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}
#if defined(__GNUC__)
__attribute__((noinline))
#endif
bool earlierNoInline(const ClockTime& a, const ClockTime& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}
int main() {
    ClockTime a(9, 30), b(10, 15);
    constexpr int N = 10000000;
    volatile int sink = 0;
    auto t1 = steady_clock::now();
    for (int i = 0; i < N; ++i) sink += earlierInline(a, b);
    auto t2 = steady_clock::now();
    for (int i = 0; i < N; ++i) sink += earlierNoInline(a, b);
    auto t3 = steady_clock::now();
    cout << "Inline ns: " << duration_cast<nanoseconds>(t2-t1).count() << '\n';
    cout << "No-inline ns: " << duration_cast<nanoseconds>(t3-t2).count() << '\n';
    cout << "Prevented optimization sink: " << sink << '\n';
}
