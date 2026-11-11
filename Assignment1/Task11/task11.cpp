#include <array>
#include <iostream>
using namespace std;
enum class Zone{Inner,Middle,Outer};constexpr array<long long,3> FARES={1000,2000,3000};constexpr long long MIN_BALANCE=5000;
long long calculate(Zone z,bool peak){long long f=FARES.at(static_cast<size_t>(z));return peak?f*120/100:f;}
class SmartCard{long long b;public:SmartCard(long long x):b(x){}bool pay(long long f){if(f<0||b-f<MIN_BALANCE)return false;b-=f;return true;}long long balance()const{return b;}};
int main(){SmartCard c(15000);long long f=calculate(Zone::Outer,true);cout<<"Fare: "<<f<<" paise\nPayment: "<<boolalpha<<c.pay(f)<<"\nBalance: "<<c.balance()<<" paise\nRecommended: constexpr fare table, integer paise, private balance.\n";}
