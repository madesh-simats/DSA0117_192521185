#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <variant>
#include <vector>
struct Base{virtual ~Base()=default;virtual double total()const=0;};
struct OP:Base{double a,b;OP(double x,double y):a(x),b(y){}double total()const override{return a+b;}};
struct IP:Base{double d,r,p;IP(double x,double y,double z):d(x),r(y),p(z){}double total()const override{return d*r+p;}};
struct SwitchBill{int type;double x,y,z;double total()const{switch(type){case 0:return x+y;case 1:return x*y+z;default:return 0;}}};
using VBill=std::variant<OP,IP>;
double vtotal(const VBill&b){return std::visit([](const auto&x){return x.total();},b);}
template<class F>double ms(F f){auto s=std::chrono::steady_clock::now();volatile double result=f();(void)result;auto e=std::chrono::steady_clock::now();return std::chrono::duration<double,std::milli>(e-s).count();}
void run(std::size_t n){
 std::vector<std::unique_ptr<Base>> a;std::vector<SwitchBill>b;std::vector<VBill>c;a.reserve(n);b.reserve(n);c.reserve(n);
 for(std::size_t i=0;i<n;++i)if(i%2==0){a.push_back(std::make_unique<OP>(100,50));b.push_back({0,100,50,0});c.emplace_back(OP(100,50));}else{a.push_back(std::make_unique<IP>(2,100,50));b.push_back({1,2,100,50});c.emplace_back(IP(2,100,50));}
 auto t1=ms([&]{double s=0;for(auto&x:a)s+=x->total();return s;});
 auto t2=ms([&]{double s=0;for(auto&x:b)s+=x.total();return s;});
 auto t3=ms([&]{double s=0;for(auto&x:c)s+=vtotal(x);return s;});
 std::cout<<"n="<<n<<" virtual_ms="<<t1<<" switch_ms="<<t2<<" variant_ms="<<t3<<'\n';
}
bool ret(double x){return x>=0&&x<=1e6;}
bool exc(double x){if(x<0)throw std::invalid_argument("negative");if(x>1e6)throw std::out_of_range("large");return true;}
void validateBench(int percent){
 constexpr std::size_t n=1000000;std::vector<double>v(n,500);for(std::size_t i=0;i<n*static_cast<std::size_t>(percent)/100;++i)v[i]=-1;
 auto t1=ms([&]{std::size_t bad=0;for(double x:v)if(!ret(x))++bad;return double(bad);});
 auto t2=ms([&]{std::size_t bad=0;for(double x:v)try{(void)exc(x);}catch(const std::exception&){++bad;}return double(bad);});
 std::cout<<"invalid="<<percent<<"% return_ms="<<t1<<" exception_ms="<<t2<<'\n';
}
int main(){std::cout<<std::fixed<<std::setprecision(3);for(auto n:{1000U,1000000U,10000000U})run(n);std::cout<<"Validation of 1,000,000 values:\n";for(int p:{0,1,50})validateBench(p);std::cout<<"Record actual times on your own system.\n";}
