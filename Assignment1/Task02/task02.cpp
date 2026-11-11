#include <iostream>
using namespace std;
enum class Zone { Inner, Middle, Outer };
constexpr long long INNER=1000, MIDDLE=2000, OUTER=3000, MIN_BALANCE=5000;
constexpr int PEAK_PERCENT=20;
int main(){cout<<"Inner fare: "<<INNER<<" paise\nMiddle fare: "<<MIDDLE<<" paise\nOuter fare: "<<OUTER<<" paise\nPeak surcharge: "<<PEAK_PERCENT<<"%\nMinimum balance: "<<MIN_BALANCE<<" paise\n";}
