#include <iostream>
#include <math.h>
#include "LorentzVector.h"
std::ostream& operator << (std::ostream&, const LorentzVector&);
using namespace std;
 LorentzVector:: LorentzVector(){
        t(0);x(0); y(0);z(0);
        }

LorentzVector::LorentzVector(double T, double X, double Y, double Z){
        t(T); x(X); y(Y); z(Z);}

double LorentzVector::t() const{
return p;
}

double LorentzVector::x() const{
return b;
}

double LorentzVector::y() const{
return c;
}

double LorentzVector::z() const{
return d;
}

double LorentzVector::norm() const{
return sqrt(fabs((p*p)-b*b-c*c-d*d));

}
    void LorentzVector::t(double x){
    this -> p = x;
    }

    void LorentzVector::x(double x){
    this -> b = x;
    }

    void LorentzVector::y(double x){
    this -> c = x;
    }

    void LorentzVector::z(double x){
    this -> d = x;
    }

    void LorentzVector:: print() const {
    cout << "LorentzVector is " << t() << ',' << x() <<','<< y() << ',' << z() << endl;
    }

    void LorentzVector::operator+=(const LorentzVector& other){
    p+=other.t();
    b+=other.x();
    c+=other.y();
    d+=other.z();
    }

     void LorentzVector::operator-=(const LorentzVector& other){
    p-=other.t();
    b-=other.x();
    c-=other.y();
    d-=other.z();
    }

    void LorentzVector::operator*=(double a){
    p*=a;
    b*=a;
    c*=a;
    d*=a;
    }

    LorentzVector LorentzVector::operator+(const LorentzVector& other) const{
    LorentzVector third(p,b,c,d);
    third+=other;
    return third;
    }

    LorentzVector LorentzVector::operator-(const LorentzVector& other) const{
    LorentzVector third(p,b,c,d);
    third-=other;
    return third;
    }

    LorentzVector operator*(const LorentzVector& lv, double a){
        LorentzVector third(a*lv.p,a*lv.b,a*lv.c,a*lv.d);
        return third;
    }
    std::ostream& operator << (std::ostream& out, const LorentzVector& lv){
     out<<"{"<<lv.p<<","<<lv.b<<","<<lv.c<<","<<lv.d<<"}";
        return out;
    }
    double LorentzVector::dot(const LorentzVector& other) const{
    return p*other.t()-b*other.x()-c*other.y()-d*other.z();
    }

    void LorentzVector::zboost ( double beta ) {
    double Q = sqrt(1-beta*beta);
    double P = (p + beta*d)/Q;
    double B = b;
    double C = c;
    double D = (d + beta*p)/Q;
    p = P;
    b = B;
    c = C;
    d = D;
    }
    void LorentzVector::read(){
    cin>>p>>b>>c>>d;
    }
