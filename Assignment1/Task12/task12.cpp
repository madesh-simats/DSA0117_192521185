#include <array>
#include <iostream>
using namespace std;
enum class Zone{Inner,Middle,Outer,Airport};constexpr array<long long,4> FARES={1000,2000,3000,6000};constexpr long long MIN_BALANCE=5000;
class MonthlyPass{Zone a,b;public:MonthlyPass(Zone x,Zone y):a(x),b(y){}bool covers(Zone z)const{return z==a||z==b;}};
class SmartCard{long long balance;public:SmartCard(long long x):balance(x){}bool pay(long long f){if(f<0||balance-f<MIN_BALANCE)return false;balance-=f;return true;}long long get()const{return balance;}};
long long fare(Zone z,bool peak,bool weekend){long long f=FARES.at(static_cast<size_t>(z));if(weekend)return f*90/100;if(peak)return f*120/100;return f;}
int main(){SmartCard c(20000);MonthlyPass pass(Zone::Inner,Zone::Middle);Zone trips[]={Zone::Inner,Zone::Airport,Zone::Outer};for(Zone z:trips){if(pass.covers(z)){cout<<"Pass covers journey: Rs 0.00\n";continue;}long long f=fare(z,true,true);cout<<"Fare "<<f<<" paise: "<<(c.pay(f)?"Approved":"Denied")<<'\n';}cout<<"Final balance: "<<c.get()<<" paise\n";}
