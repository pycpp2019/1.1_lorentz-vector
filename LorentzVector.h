#include <iostream>
class LorentzVector
{
private:
	double ct1, x1, y1, z1;
public:
	LorentzVector();

	LorentzVector(double, double, double, double);

	void read();

	void print() const;

	friend std::ostream &operator<<(std::ostream &out, const LorentzVector &v);

	double t() const;
	double x() const;
	double y() const;
	double z() const;

	void t(double);
	void x(double);
	void y(double);
	void z(double);

	friend LorentzVector operator+(const LorentzVector&, const LorentzVector&);
	friend LorentzVector operator-(const LorentzVector &, const LorentzVector &);
	friend void operator+=(LorentzVector&, const LorentzVector&);
	friend void operator-=(LorentzVector &, const LorentzVector &);
	friend LorentzVector operator-(const LorentzVector &);
	friend LorentzVector operator*(const LorentzVector &, double );
	friend LorentzVector operator*(double , const LorentzVector &);
	friend void operator*=(LorentzVector &, double );
	friend double operator*(const LorentzVector &, const LorentzVector &);

	double norm() const;

	void zboost(double);
    double dot(const LorentzVector& v1) const;
};
