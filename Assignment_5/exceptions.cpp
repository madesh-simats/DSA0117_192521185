#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
class ClaimError:public std::runtime_error{public:using std::runtime_error::runtime_error;};
double approve(double billed,double cover){
 if(billed<0||cover<0)throw std::invalid_argument("negative amount");
 if(billed>cover)throw ClaimError("exceeds cover");
 return billed;
}
double settle(double billed,double cover){
 try{return approve(billed,cover);}
 catch(const ClaimError&e){std::cout<<"audit: "<<e.what()<<'\n';throw;}
}
void validate(double x){
 if(x<0)throw std::invalid_argument("negative");
 if(x>1e6)throw std::out_of_range("too large");
 std::cout<<"ok ";
}
void process(double x){
 try{validate(x);}
 catch(const std::out_of_range&e){std::cout<<"[log "<<e.what()<<"] ";throw;}
}
int main(){
 std::cout<<"Predict-output experiment:\n";
 for(double x:{100.0,-5.0,2e6})try{process(x);std::cout<<"done ";}catch(const std::exception&e){std::cout<<"caught "<<e.what()<<' ';}
 std::cout<<"\n\nClaim tests:\n";
 double cases[][2]={{40000,50000},{60000,50000},{-1,50000}};
 for(auto&c:cases)try{std::cout<<"approved "<<settle(c[0],c[1])<<'\n';}
 catch(const ClaimError&e){std::cout<<"claim rejected: "<<e.what()<<'\n';}
 catch(const std::exception&e){std::cout<<"error: "<<e.what()<<'\n';}
 try{(void)std::stod("not-a-number");}catch(const std::invalid_argument&e){std::cout<<"conversion: "<<e.what()<<'\n';}
 try{std::vector<int> v;v.resize(std::numeric_limits<std::size_t>::max());}
 catch(const std::bad_alloc&e){std::cout<<"bad_alloc caught: "<<e.what()<<'\n';}
 catch(const std::exception&e){std::cout<<"allocation request rejected: "<<e.what()<<'\n';}
 try{throw std::runtime_error("top-level");}catch(...){std::cout<<"top-level catch(...) handled error\n";}
}
