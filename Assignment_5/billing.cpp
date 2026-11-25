#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
class BillingError : public std::runtime_error { public: using std::runtime_error::runtime_error; };
class Bill {
protected: std::string patient;
public:
 explicit Bill(const std::string& p):patient(p){}
 virtual ~Bill()=default;
 virtual double total() const=0;
 virtual std::string type() const { return "Bill"; }
 void print() const { std::cout<<type()<<" "<<patient<<": "<<total()<<'\n'; }
};
class OutPatient:public Bill {
 double consultation,tests;
public:
 OutPatient(const std::string&p,double c,double t):Bill(p),consultation(c),tests(t){if(c<0||t<0)throw BillingError("negative OP charge");}
 double total()const override{return consultation+tests;}
 std::string type()const override{return "OP";}
};
class InPatient:public Bill {
 int days; double perDay,procedures,medicines;
public:
 InPatient(const std::string&p,int d,double r,double s,double m=0):Bill(p),days(d),perDay(r),procedures(s),medicines(m){if(d<0||r<0||s<0||m<0)throw BillingError("negative IP charge");}
 double total()const override{return days*perDay+procedures+medicines;}
 std::string type()const override{return "IP";}
};
class DayCare:public Bill {
 double packagePrice;
public:
 DayCare(const std::string&p,double x):Bill(p),packagePrice(x){if(x<0)throw BillingError("negative package");}
 double total()const override{return packagePrice;}
 std::string type()const override{return "DayCare";}
};
class Emergency:public Bill {
 double base,hourRate,hours;
public:
 Emergency(const std::string&p,double b,double r,double h):Bill(p),base(b),hourRate(r),hours(h){if(b<0||r<0||h<0)throw BillingError("negative emergency charge");}
 double total()const override{return base+hourRate*hours;}
 std::string type()const override{return "Emergency";}
};
class Payer { public: virtual ~Payer()=default; virtual double amountCovered(const Bill&)const=0; };
class SelfPay:public Payer { public: double amountCovered(const Bill&b)const override{return b.total();} };
class Insurance:public Payer {
 double limit,copay;
public:
 Insurance(double l,double c):limit(l),copay(c){if(l<0||c<0||c>100)throw BillingError("invalid policy");}
 double amountCovered(const Bill&b)const override{double x=b.total()*(100-copay)/100;return x<limit?x:limit;}
};
class GovernmentScheme:public Payer {
 double packageRate;
public:
 explicit GovernmentScheme(double r):packageRate(r){if(r<0)throw BillingError("invalid scheme rate");}
 double amountCovered(const Bill&)const override{return packageRate;}
};
int main(){
 try{
  std::vector<std::unique_ptr<Bill>> bills;
  bills.push_back(std::make_unique<OutPatient>("Ravi",500,1200));
  bills.push_back(std::make_unique<InPatient>("Meena",3,2500,40000));
  bills.push_back(std::make_unique<DayCare>("Arun",18000));
  bills.push_back(std::make_unique<Emergency>("Leela",2000,500,4));
  double sum=0; for(const auto&b:bills){b->print();sum+=b->total();}
  std::cout<<"Grand total: "<<sum<<'\n';
  SelfPay self; Insurance insurance(50000,10); GovernmentScheme scheme(12000);
  for(const auto&b:bills)std::cout<<b->type()<<" | self "<<self.amountCovered(*b)<<" | insurance "<<insurance.amountCovered(*b)<<" | scheme "<<scheme.amountCovered(*b)<<'\n';
 }catch(const std::exception&e){std::cerr<<"Billing failure: "<<e.what()<<'\n';return 1;}
}
