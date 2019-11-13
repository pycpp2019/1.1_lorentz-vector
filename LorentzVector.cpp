#include <iostream>
#include <cmath>
#include "LorentzVector.h"

using namespace std;


LorentzVector::LorentzVector(){
         t1=0;
         x1=0;
         y1=0;
         z1=0;
    };
LorentzVector::LorentzVector( double t,double x, double y, double z ){
         t1=t;
         x1=x;
         y1=y;
         z1=z;
    }

double LorentzVector::  t () const {
        return this->t1;
    }
double LorentzVector:: x () const {
        return this->x1;
    }
double LorentzVector:: y ()const {
        return this->y1;
    }
double LorentzVector:: z () const {
        return this->z1;
    }
double LorentzVector:: norm() const {
        return sqrt(fabs((this->t())*(this->t())-(this->x())*(this->x())-(this->y())*(this->y())-(this->z())*(this->z())));
    }

void LorentzVector:: x (double x) {
            x1=x;
    }
void LorentzVector:: y (double y) {
            y1=y;
    }
void LorentzVector:: z (double z) {
            z1=z;
    }
void LorentzVector:: t (double t) {
            t1=t;
    }
void LorentzVector:: operator+= (const LorentzVector& other) {
        this->x(x()+other.x());
        this->y(y()+other.y());
        this->z(z()+other.z());
        this->t(t()+other.t());
    }
void LorentzVector:: operator-=  (const LorentzVector& other) {
        this->x(this->x()-other.x());
        this->y(this->y()-other.y());
        this->z(this->z()-other.z());
        this->t(this->t()-other.t());
    }
void LorentzVector:: operator*= (double a) {
        this->x(this->x()*a);
        this->y(this->y()*a);
        this->z(this->z()*a);
        this->t(this->t()*a);
    }
LorentzVector LorentzVector:: operator+ (const LorentzVector& other) const {
        LorentzVector V=LorentzVector(this->t()+other.t(),this->x()+other.x(),this->y()+other.y(),this->z()+other.z());
        return V;
    }
LorentzVector LorentzVector:: operator- (const LorentzVector& other) const {
        LorentzVector V(this->t()-other.t(),this->x()-other.x(),this->y()-other.y(),this->z()-other.z());
        return V;
    }
LorentzVector operator* (const LorentzVector& lv, double a) {
        return LorentzVector(lv.t1*a,lv.x1*a,lv.y1*a,lv.z1*a);
    }
void LorentzVector:: zboost (double beta) {
        double z=this->z();
        double Gamma=1/sqrt(1-beta*beta);
        this->z(Gamma*(this->z()+this->t()*beta));
        this->t(Gamma*(this->t()+beta*z));
    }
double LorentzVector:: dot (const LorentzVector& other) const {
     return -(this->x()*other.x()+this->y()*other.y()+this->z()*other.z()-this->t()*other.t());
    }

std::ostream& operator << (std::ostream& o, const LorentzVector& lv){
 o <<lv.t() <<" "<< lv.x()<<" " << lv.y()<<" " << lv.z() << endl;
}


