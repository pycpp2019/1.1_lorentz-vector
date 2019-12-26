#include<iostream>
#include <cmath>
#include "LorentzVector.h"

using namespace std;
LorentzVector::LorentzVector(double a, double b, double c, double d)
{
  this->t1=a;
  this->x1=b;
  this->y1=c;
  this->z1=d;
}

LorentzVector::LorentzVector()
{
    this->x1=0; this->y1=0; this->z1=0; this->t1=0;
}

double LorentzVector::t() const
{
    return this->t1;
}

double LorentzVector::x() const
{
    return this->x1;
}

double LorentzVector::y() const
{
    return this->y1;
}

double LorentzVector::z() const
{
    return this->z1;
}
double LorentzVector::norm() const
{
    double a=(this->x1*this->x1+this->y1*this->y1+this->z1*this->z1-this->t1*this->t1);
    if (a>=0)
    {
       return sqrt(a);
    }
    else{ 
        return(sqrt(-a));
        };
}
void LorentzVector::t(double a)
{
    this->t1=a;
}

void LorentzVector::x(double a)
{
    this->x1=a;
}

void LorentzVector::y(double a)
{
    this->y1=a;
}

void LorentzVector::z(double a)
{
    this->z1=a;
}
double LorentzVector::dot(const LorentzVector& other) const
{
    double dot;
    dot = this->x1*other.x()+this->y1*other.y()+this->z1*other.z()-this->t1*other.t();
    return dot;
}

void LorentzVector::zboost(double beta)
{
    double z2=(this->z1-beta*this->t1)/(sqrt(1-beta*beta));
    this->t1=(this->t1-beta*this->z1)/(sqrt(1-beta*beta));
    this->z1=z2;
}
void LorentzVector::operator+=(const LorentzVector& other)
{
    t(t()+other.t());
    x(x()+other.x());
    y(y()+other.y());
    z(z()+other.z());
}
void LorentzVector::operator-=(const LorentzVector& other)
{
    t(t()-other.t());
    x(x()-other.x());
    y(y()-other.y());
    z(z()-other.z());
}
void LorentzVector::operator*=(double a)
{
    t(t()*a);
    x(x()*a);
    y(y()*a);
    z(z()*a);
}
LorentzVector LorentzVector::operator+(const LorentzVector& other) const
{
    LorentzVector v;
    v.t(t()+other.t());
    v.x(x()+other.x());
    v.y(y()+other.y());
    v.z(z()+other.z());
    return v;
}
LorentzVector LorentzVector::operator-(const LorentzVector& other) const
{
    LorentzVector v;
    v.t(t()-other.t());
    v.x(x()-other.x());
    v.y(y()-other.y());
    v.z(z()-other.z());
    return v;
}
LorentzVector operator*(const LorentzVector& lv, double a)
{
    LorentzVector v;
    v.t(lv.t()*a);
    v.x(lv.x()*a);
    v.y(lv.y()*a);
    v.z(lv.z()*a);
    return v;
}
std::ostream& operator << (std::ostream& out, const LorentzVector& v)
{
    return out<<"{"<<v.t() << "," << v.x() << "," << v.y() << "," << v.z() << "}";
}
