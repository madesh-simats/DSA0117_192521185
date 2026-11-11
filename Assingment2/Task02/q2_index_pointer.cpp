#include <iostream>
using namespace std;
int highestIndex(const int a[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (a[i] > a[best]) best = i;
    return best;
}
int* highestPointer(int a[], int n) {
    return &a[highestIndex(a, n)];
}
int main() {
    int marks[] = {78, 92, 85, 88};
    int i = highestIndex(marks, 4);
    cout << "Index: " << i << ", mark: " << marks[i] << '\n';
    *highestPointer(marks, 4) += 2;
    cout << "Updated highest: " << marks[highestIndex(marks, 4)] << '\n';
}
