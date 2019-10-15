#ifndef LORENTZVECTOR_H   
#define LORENTZVECTOR_H
class LorentzVector {
	private:
		double vt,vx,vy,vz;
	public:
		LorentzVector(); //default constructor
		LorentzVector(double t, double x, double y, double z); //t,x,y,z constructor
		double t() const; //get t
		double x() const; //get x
		double y() const; //get y
		double z() const; //get z
		double norm() const; //get norm
		void t(double n); //put t
		void x(double n); //put x
		void y(double n); //put y
		void z(double n); //put z
		void operator+=(const LorentzVector& v);
		void operator-=(const LorentzVector& v);
		void operator*=(double a);
		LorentzVector operator+(const LorentzVector& v) const;
		LorentzVector operator-(const LorentzVector& v) const;
		friend LorentzVector operator*(const LorentzVector& v, double a);
		friend std::ostream& operator<<(std::ostream& out, const LorentzVector& v);
		double dot(const LorentzVector& v2) const;
		void zboost(double beta);
};
std::ostream& operator << (std::ostream& out,const LorentzVector& v); 

#endif
