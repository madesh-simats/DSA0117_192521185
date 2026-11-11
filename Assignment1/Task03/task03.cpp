#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;
int main(){cout<<"sizeof(bool): "<<sizeof(bool)<<"\nsizeof(char): "<<sizeof(char)<<"\nsizeof(int): "<<sizeof(int)<<"\nsizeof(long long): "<<sizeof(long long)<<"\nsizeof(float): "<<sizeof(float)<<"\nsizeof(double): "<<sizeof(double)<<"\nINT_MAX: "<<INT_MAX<<"\n";long long n=3000000, total=n*3000;double d=0;for(int i=0;i<n;++i)d+=30.0;cout<<"Integer total paise: "<<total<<"\nInteger total Rs: "<<fixed<<setprecision(2)<<total/100.0<<"\nDouble total Rs: "<<d<<"\n";}
