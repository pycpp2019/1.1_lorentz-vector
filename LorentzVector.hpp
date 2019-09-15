#ifndef _LORENTZ_VECTOR_
#define _LORENTZ_VECTOR_

class LorentzVector {
private:
	double t;
	double x;
	double y;
	double z;

public:
//##########___CONSTRUCTORS___#########################################################################################################
	LorentzVector();
	LorentzVector(double input_t, double input_x,\
				double input_y, double input_z);
//##########___GETTERS___##############################################################################################################
	double get_t() const;
	double get_x() const;
	double get_y() const;
	double get_z() const;
//##########___SETTERS___##############################################################################################################
	double set_t(double new_t);
	double set_x(double new_x);
	double set_y(double new_y);
	double set_z(double new_z);
//##########___OUTPUTTING_METHOD___####################################################################################################
	void print() const;
//##########___OPERATIONS___###########################################################################################################
	LorentzVector add(const LorentzVector & other_vector) const;
	LorentzVector sub(const LorentzVector & other_vector) const;
	LorentzVector mul(double Lambda) const;
	double dot(const LorentzVector & other_vector) const;
	double norm() const;
//##########___CONVERSION_METHOD___####################################################################################################	
	void zboost(double beta);		//If |beta| > 1, this function do nothing
	
};

#endif