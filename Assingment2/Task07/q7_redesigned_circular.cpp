#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

class CircularHistory {
    vector<int> values;
    int capacity, count = 0, next = 0;
public:
    explicit CircularHistory(int k) : values(k), capacity(k) {}
    void add(int x) {
        values[next] = x;
        next = (next + 1) % capacity;
        if (count < capacity) ++count;
    }
    int newest() const { return values[(next + capacity - 1) % capacity]; }
    int size() const { return count; }
};
int main() {
    constexpr int K = 50, N = 1000000;
    CircularHistory h(K);
    auto start = steady_clock::now();
    for (int i=0;i<N;++i) h.add(i);
    auto end = steady_clock::now();
    cout << "Circular history size: " << h.size() << '\n';
    cout << "Circular history newest: " << h.newest() << '\n';
    cout << "Circular insertion benchmark ns: "
         << duration_cast<nanoseconds>(end-start).count() << '\n';
}
