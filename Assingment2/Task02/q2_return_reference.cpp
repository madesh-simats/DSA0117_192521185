#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}
const int& highestMarkConst(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}
int highestMarkCopy(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}
int& danglingReference() {
    static int safeButShared = 0;
    return safeButShared; // Safe static storage; do not return a local variable reference.
}
int main() {
    int marks[] = {78, 92, 85, 88, 90};
    cout << "Highest: " << highestMark(marks, 5) << '\n';
    highestMark(marks, 5) += 2;
    cout << "After moderation: " << highestMark(marks, 5) << '\n';
    cout << "Const reference view: " << highestMarkConst(marks, 5) << '\n';
    cout << "Returned copy: " << highestMarkCopy(marks, 5) << '\n';
    int& chosen = danglingReference();
    chosen = 7;
    cout << "Static-storage reference example: " << chosen << '\n';
}
