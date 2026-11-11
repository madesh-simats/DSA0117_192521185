#include <iostream>
using namespace std;constexpr long long MIN_BALANCE=5000;
bool proceduralPay(long long& b,long long f){if(b-f<MIN_BALANCE)return false;b-=f;return true;}
class SmartCard{long long balance;public:SmartCard(long long b):balance(b){}bool canTravel(long long f)const{return f>=0&&balance-f>=MIN_BALANCE;}bool deduct(long long f){if(!canTravel(f))return false;balance-=f;return true;}long long getBalance()const{return balance;}};
int main(){long long b=10000;cout<<boolalpha<<"Procedural: "<<proceduralPay(b,2000)<<", balance "<<b<<" paise\n";SmartCard c(10000);cout<<"OOP: "<<c.deduct(2000)<<", balance "<<c.getBalance()<<" paise\n";cout<<"OOP rejects low balance: "<<!c.deduct(4000)<<'\n';}
