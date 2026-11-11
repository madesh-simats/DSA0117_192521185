#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
int main(){int z,h;long long b;cout<<"Zone (1-3): ";while(!(cin>>z)||z<1||z>3){cout<<"Invalid. Enter 1-3: ";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');}cout<<"Hour (0-23): ";while(!(cin>>h)||h<0||h>23){cout<<"Invalid. Enter 0-23: ";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');}cout<<"Balance in paise: ";while(!(cin>>b)||b<0){cout<<"Invalid balance: ";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');}long long f[]={0,1000,2000,3000};long long fare=f[z];bool peak=(h>=8&&h<10)||(h>=17&&h<20);if(peak)fare=fare*120/100;cout<<fixed<<setprecision(2)<<"Fare Rs "<<fare/100.0<<'\n';if(b-fare>=5000)cout<<"Approved. Remaining Rs "<<(b-fare)/100.0<<'\n';else cout<<"Denied: minimum Rs 50 must remain.\n";}
