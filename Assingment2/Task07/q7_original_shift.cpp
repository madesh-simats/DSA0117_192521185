#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

class ShiftHistory {
    vector<int> values;
    int capacity;
public:
    explicit ShiftHistory(int k) : capacity(k) {}
    void add(int x) {
        if (static_cast<int>(values.size()) == capacity) {
            for (int i = 1; i < capacity; ++i) values[i-1] = values[i];
            values[capacity-1] = x;
        } else values.push_back(x);
    }
    const vector<int>& data() const { return values; }
};
int main() {
    constexpr int K = 50, N = 1000000;
    ShiftHistory h(K);
    auto start = steady_clock::now();
    for (int i=0;i<N;++i) h.add(i);
    auto end = steady_clock::now();
    cout << "Shift history last: " << h.data().back() << '\n';
    cout << "Shift insertion benchmark ns: "
         << duration_cast<nanoseconds>(end-start).count() << '\n';
}
