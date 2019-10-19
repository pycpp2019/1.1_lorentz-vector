#include <iostream>
#include <cmath>
#include "LorentzVector.h"

using namespace std;

LorentzVector::LorentzVector() : t_coord(0), x_coord(0), y_coord(0), z_coord(0) {}
LorentzVector::LorentzVector(double t, double x, double y, double z) : t_coord(t), x_coord(x), y_coord(y), z_coord(z) {}

double LorentzVector::t() const{
    return this->t_coord;
}
double LorentzVector::x() const{
    return this->x_coord;
}
double LorentzVector::y() const{
    return this->y_coord;
}
double LorentzVector::z() const{
    return this->z_coord;
}
double LorentzVector::norm() const{
    return (sqrt(abs(this->t() * this->t() - this->x() * this->x() - this->y() * this->y() - this->z() * this->z())));
}

void LorentzVector::t(double t) {
    this->t_coord = t;
}
void LorentzVector::x(double x) {
    this->x_coord = x;
}
void LorentzVector::y(double y) {
    this->y_coord = y;
}
void LorentzVector::z(double z) {
    this->z_coord = z;
}

void LorentzVector::operator += (const LorentzVector& other) {
    *this = LorentzVector(this->t() + other.t(), this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}
void LorentzVector::operator -= (const LorentzVector& other) {
    *this = LorentzVector(this->t() - other.t(), this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}
void LorentzVector::operator *= (double a) {
    *this = LorentzVector(a * this->t(), a * this->x(), a * this->y(), a * this->z());
}
LorentzVector LorentzVector::operator + (const LorentzVector& other) const {
    return LorentzVector(this->t() + other.t(), this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}
LorentzVector LorentzVector::operator - (const LorentzVector& other) const {
    return LorentzVector(this->t() - other.t(), this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}
LorentzVector operator * (const LorentzVector& lv, double a) {
    return LorentzVector(a * lv.t(), a * lv.x(), a * lv.y(), a * lv.z());
}
std::ostream& operator << (std::ostream& s, const LorentzVector& lv) {
    cout << "(" << lv.t() << ", " << lv.x() << ", " << lv.y() << ", " << lv.z() << ")" << endl;
    return s;
}
void LorentzVector::zboost(double beta) {
    double t_temp = this->t_coord; 
    this->t_coord = (this->t() - this->z() * beta) / sqrt(1 - beta * beta);
    this->z_coord = (this->z() - beta * t_temp) / sqrt(1 - beta * beta);
}
double LorentzVector::dot(const LorentzVector& other) const {
    return (this->t() * other.t() - this->x() * other.x() - this->y() * other.y() - this->z() * other.z());
}