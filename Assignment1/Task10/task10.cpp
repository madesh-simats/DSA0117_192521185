#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;
int main(){long long counts[]={20000,500000,3000000};for(long long n:counts){long long total=n*3000;cout<<n<<" journeys: "<<total<<" paise = Rs "<<fixed<<setprecision(2)<<total/100.0<<" | fits int: "<<boolalpha<<(total<=INT_MAX)<<'\n';}long long exact=0;double approximate=0;for(int i=0;i<3000000;++i){exact+=3000;approximate+=30.0;}cout<<"long long total paise: "<<exact<<"\ndouble total Rs: "<<fixed<<setprecision(2)<<approximate<<"\nINT_MAX: "<<INT_MAX<<'\n';}
