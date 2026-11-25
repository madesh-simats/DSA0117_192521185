#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
class BillingError:public std::runtime_error{public:using std::runtime_error::runtime_error;};
class Bill{
protected:std::string patient;
public:explicit Bill(std::string p):patient(std::move(p)){}virtual ~Bill()noexcept=default;
 virtual double total()const=0;virtual std::string type()const=0;
 void print()const{std::cout<<type()<<" "<<patient<<": "<<total()<<'\n';}
};
class OutPatientBill:public Bill{
 double consultation,tests;
public:OutPatientBill(std::string p,double c,double t):Bill(std::move(p)),consultation(c),tests(t){if(c<0||t<0)throw BillingError("negative amount");}
 double total()const override{return consultation+tests;}std::string type()const override{return "OP";}
};
class DayCareBill:public Bill{
 double package;
public:DayCareBill(std::string p,double x):Bill(std::move(p)),package(x){if(x<0)throw BillingError("negative package");}
 double total()const override{return package;}std::string type()const override{return "DayCare";}
};
class Payer{public:virtual ~Payer()noexcept=default;virtual double amountCovered(const Bill&)const=0;};
class SelfPay:public Payer{public:double amountCovered(const Bill&b)const override{return b.total();}};
class CorporatePayer:public Payer{
 double percent,limit;
public:CorporatePayer(double p,double l):percent(p),limit(l){if(p<0||p>100||l<0)throw BillingError("invalid corporate policy");}
 double amountCovered(const Bill&b)const override{double x=b.total()*percent/100;return x<limit?x:limit;}
};
class Guard{std::string label;public:explicit Guard(std::string s):label(std::move(s)){std::cout<<"acquire "<<label<<'\n';}~Guard()noexcept{std::cout<<"release "<<label<<'\n';}};
int main(){
 try{
  std::vector<std::unique_ptr<Bill>>bills;bills.push_back(std::make_unique<OutPatientBill>("Nila",700,1300));bills.push_back(std::make_unique<DayCareBill>("Arun",22000));
  SelfPay self;CorporatePayer corp(80,30000);
  for(auto&b:bills){b->print();std::cout<<"self "<<self.amountCovered(*b)<<" corporate "<<corp.amountCovered(*b)<<'\n';}
  try{Guard g("temporary resource");throw BillingError("simulated claim failure");}
  catch(const BillingError&e){std::cout<<"recovered: "<<e.what()<<'\n';}
 }catch(const std::exception&e){std::cerr<<"fatal: "<<e.what()<<'\n';return 1;}
}
