#include "LorentzVector.h"
#include <ostream>
#include <cmath>




//##########___CONSTRUCTORS___#########################################################################################################


LorentzVector::LorentzVector(): t_coord(0), x_coord(0), y_coord(0), z_coord(0) {

}

LorentzVector::LorentzVector(double input_t, double input_x, double input_y, double input_z) {

	this->t_coord = input_t;
	this->x_coord = input_x;
	this->y_coord = input_y;
	this->z_coord = input_z;
}


//##########___GETTERS___##############################################################################################################


double LorentzVector::t() const {
	return this->t_coord;
}

double LorentzVector::x() const {
	return this->x_coord;
}

double LorentzVector::y() const {
	return this->y_coord;
}

double LorentzVector::z() const {
	return this->z_coord;
}


//##########___SETTERS___##############################################################################################################


void LorentzVector::t(double new_t) {
	this->t_coord = new_t;
	return;
}

void LorentzVector::x(double new_x) {
	this->x_coord = new_x;
	return;
}

void LorentzVector::y(double new_y) {
	this->y_coord = new_y;
	return;
}

void LorentzVector::z(double new_z) {
	this->z_coord = new_z;
	return;
}


//##########___OPERATIONS___###########################################################################################################


double LorentzVector::dot(const LorentzVector & other_vector) const {
	return (this->t_coord  * other_vector.t() -\
		this->x_coord * other_vector.x() - this->y_coord * other_vector.y() -\
		this->z_coord * other_vector.z());
}

double LorentzVector::norm() const {
	return sqrt(std::abs(this->dot(*this)));
}


//##########___CONVERSION_METHOD___####################################################################################################


void LorentzVector::zboost(double beta) {									//If |beta| > 1, this function do nothing
	if(beta * beta > 1) {
		return;
	}

	double gamma_factor = 1 / sqrt(1 - beta * beta);
	double tmp_t = this->t_coord;
	double tmp_z = this->z_coord;
	
	this->z_coord = gamma_factor * (tmp_z - beta * tmp_t);
	this->t_coord = gamma_factor * (tmp_t - beta * tmp_z);
	return;
}


//##########___OPERATORS___############################################################################################################


void LorentzVector::operator+= (const LorentzVector& other_vector) {
	this->t_coord += other_vector.t();
	this->x_coord += other_vector.x();
	this->y_coord += other_vector.y();
	this->z_coord += other_vector.z();
	return;
}

void LorentzVector::operator-= (const LorentzVector& other_vector) {
	this->t_coord -= other_vector.t();
	this->x_coord -= other_vector.x();
	this->y_coord -= other_vector.y();
	this->z_coord -= other_vector.z();
	return;
}

void LorentzVector::operator*= (const double lambda) {
	this->t_coord *= lambda;
	this->x_coord *= lambda;
	this->y_coord *= lambda;
	this->z_coord *= lambda;
	return;
}

LorentzVector LorentzVector::operator+ (const LorentzVector& other_vector) const {
	return LorentzVector(this->t_coord + other_vector.t(),\
		this->x_coord + other_vector.x(),\
		this->y_coord + other_vector.y(),\
		this->z_coord + other_vector.z());
}

LorentzVector LorentzVector::operator- (const LorentzVector& other_vector) const {
	return LorentzVector(this->t_coord - other_vector.t(),\
		this->x_coord - other_vector.x(),\
		this->y_coord - other_vector.y(),\
		this->z_coord - other_vector.z());
}

LorentzVector LorentzVector::operator* (const double lambda) const {
	return LorentzVector(this->t_coord * lambda, this->x_coord * lambda,\
		this->y_coord * lambda, this->z_coord * lambda);
}




LorentzVector operator* (const double lambda, const LorentzVector& l_vector) {
	return l_vector * lambda;
}

std::ostream& operator<< (std::ostream& out_stream, const LorentzVector& l_vector) {
	out_stream << "(" << l_vector.t() << "," <<\
	l_vector.x() << "," << l_vector.y() << "," << l_vector.z() << ")";
	return out_stream;
}