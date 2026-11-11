#include <iomanip>
#include <iostream>
using namespace std;
enum class Zone{Inner,Middle,Outer};constexpr int BASE[]={1000,2000,3000};constexpr int SURCHARGE=20;constexpr long long MIN_BALANCE=5000;
long long fare(Zone z,bool peak){long long f=0;switch(z){case Zone::Inner:f=BASE[0];break;case Zone::Middle:f=BASE[1];break;case Zone::Outer:f=BASE[2];break;default:return -1;}if(peak)f=f*(100+SURCHARGE)/100;return f;}
bool canTravel(long long b,long long f){return f>=0&&b-f>=MIN_BALANCE;}
int main(){long long b=10000;struct Trip{Zone zone;bool peak;};Trip trips[]={{Zone::Inner,false},{Zone::Outer,true},{Zone::Middle,false}};for(auto t:trips){long long f=fare(t.zone,t.peak);if(canTravel(b,f)){b-=f;cout<<"Fare Rs "<<f/100<<'.'<<setw(2)<<setfill('0')<<f%100<<setfill(' ');}else cout<<"Denied (low balance)";cout<<" balance Rs "<<b/100<<'\n';}}
