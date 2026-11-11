#include <iomanip>
#include <iostream>
using namespace std;
enum class Zone{Inner,Middle,Outer};
long long fare(Zone z,int h){long long f= z==Zone::Inner?1000:z==Zone::Middle?2000:3000;bool p=(h>=8&&h<10)||(h>=17&&h<20);return p?f*120/100:f;}
int main(){struct T{const char*name;Zone z;int h;long long expected;};T ts[]={{"Inner off-peak",Zone::Inner,11,1000},{"Middle at 08:00",Zone::Middle,8,2400},{"Outer at 10:00",Zone::Outer,10,3000},{"Inner at 17:00",Zone::Inner,17,1200},{"Outer at 20:00",Zone::Outer,20,3000}};for(auto t:ts){long long a=fare(t.z,t.h);cout<<left<<setw(20)<<t.name<<" expected "<<t.expected<<" actual "<<a<<(a==t.expected?" PASS":" FAIL")<<'\n';}cout<<"Exactly Rs 50 remains: "<<boolalpha<<(6000-1000==5000)<<'\n';long long total=1000+2000+3000+1200+2400;cout<<"Five journey total: "<<total<<" paise = Rs "<<fixed<<setprecision(2)<<total/100.0<<'\n';}
