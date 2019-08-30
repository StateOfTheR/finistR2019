
#include <Rcpp.h>

//' @title Class Sde driftedRw
//' @name driftedRw
//' @description drifted random walk class
//' @export driftedRw
class driftedRw 
{ 
  // Access specifier 
private: 
  
  double mu ;
  double sigma ;
  
  double compute_drift(double x) {
    return mu;
  }
  
  
public: 
  
  driftedRw( double mu_, double sigma_){
    mu = mu_;
    sigma = sigma_;
  }
  
  void set_mu(double mu_){
    mu = mu_;
  }
  
  double get_mu(){
    return mu ;
  }  
  
  void set_sigma(double sigma_){
    sigma = sigma_;
  }
  double get_sigma(){
    return sigma ;
  }  
  
  Rcpp::NumericVector simulate(Rcpp::NumericVector times, double x0){
    int n = times.size();
    Rcpp::NumericVector out(n);
    out[0] = x0;
    Rcpp::NumericVector noise = Rcpp::rnorm(n - 1);
    for(int i = 0; i < n - 1 ; ++i ){
      out[i+1] = out[i] + 
        compute_drift(out[i]) + (times[i+1]-times[i]) * sigma * noise[i]; 
    }
    return out;
  }
  
};

RCPP_MODULE(drift_rw_Module) {
  using namespace Rcpp;
  //  .constructor()
  class_<driftedRw>("driftedRw")
  .constructor<double, double>()
  .property( "mu_R", &driftedRw::get_mu, &driftedRw::set_mu )
  .property( "sigma_R", &driftedRw::get_sigma, &driftedRw::set_sigma )
  .method( "simulate_R", &driftedRw::simulate )
  ;
}