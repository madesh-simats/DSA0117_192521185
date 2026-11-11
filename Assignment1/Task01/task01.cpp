#include <iostream>
#include <string>
using namespace std;
enum class Zone { Inner, Middle, Outer };
struct Passenger { string name; bool student=false, senior=false; };
struct Journey { Zone zone; int hour; bool peak() const { return (hour>=8&&hour<10)||(hour>=17&&hour<20); } };
struct FareTable { static long long base(Zone z) { switch(z){case Zone::Inner:return 1000;case Zone::Middle:return 2000;case Zone::Outer:return 3000;} return 0; } };
class SmartCard { long long balance; public: explicit SmartCard(long long b):balance(b){} bool canTravel(long long f)const{return balance-f>=5000;} bool deduct(long long f){if(!canTravel(f))return false;balance-=f;return true;} long long getBalance()const{return balance;} };
int main(){Passenger p{"Yogesh"};Journey j{Zone::Middle,9};SmartCard c(10000);long long f=FareTable::base(j.zone);if(j.peak())f=f*120/100;cout<<"Passenger: "<<p.name<<"\nFare paise: "<<f<<"\n";cout<<(c.deduct(f)?"Approved":"Denied")<<"\nBalance paise: "<<c.getBalance()<<"\n";}
