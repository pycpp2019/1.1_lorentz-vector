#pragma once
#include <ostream>

class LorentzVector {
private:
	double t_coord;
	double x_coord;
	double y_coord;
	double z_coord;

public:
//##########___CONSTRUCTORS___#########################################################################################################
	LorentzVector();
	LorentzVector(double input_t, double input_x,\
				double input_y, double input_z);
//##########___GETTERS___##############################################################################################################
	double t() const;
	double x() const;
	double y() const;
	double z() const;
//##########___SETTERS___##############################################################################################################
	void t(double new_t);
	void x(double new_x);
	void y(double new_y);
	void z(double new_z);
//##########___OPERATIONS___###########################################################################################################
	double dot(const LorentzVector & other_vector) const;
	double norm() const;
//##########___CONVERSION_METHOD___####################################################################################################	
	void zboost(double beta);		//If |beta| > 1, this function do nothing
//##########___OPERATORS___############################################################################################################
	void operator+= (const LorentzVector& other_vector);
	void operator-= (const LorentzVector& other_vector);
	void operator*= (const double lambda);
	LorentzVector operator+ (const LorentzVector& other_vector) const;
	LorentzVector operator- (const LorentzVector& other_vector) const;
	LorentzVector operator* (const double lambda) const;

	friend LorentzVector operator* (const double lambda, const LorentzVector& l_vector);
	friend std::ostream& operator<< (std::ostream& std_out_stream, const LorentzVector& l_vector);
};