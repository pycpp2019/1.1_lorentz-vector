#include "LorentzVector.h"

using namespace std;


LorentzVector::LorentzVector(): ct1(0), x1(0), y1(0), z1(0) {}

LorentzVector::LorentzVector(double ct, double x, double y, double z): ct1(ct), x1(x), y1(y), z1(z) {}

void LorentzVector::read()
{
	cin >> ct1 >> x1 >> y1 >> z1; 
}

void LorentzVector::print() const
{
	cout << "[" << ct1 << ", " << x1 << ", " << y1 << ", " << z1 << "]" << endl;
}

/*ostream &operator<<(ostream &out, const LorentzVector &v)
{
	return(out << "[" << v.t() << ", " << v.x() << ", " << v.y() << ", " << v.z() << "]");
}*/	

double LorentzVector::t() const { return ct1; }
double LorentzVector::x() const { return x1; }
double LorentzVector::y() const { return y1; }
double LorentzVector::z() const { return z1; }

void LorentzVector::t(double input) { ct1 = input; }
void LorentzVector::x(double input) { x1 = input; }
void LorentzVector::y(double input) { y1 = input; }
void LorentzVector::z(double input) { z1 = input; }

LorentzVector operator+(const LorentzVector &v1, const LorentzVector &v2) 
{
	return LorentzVector(v1.t() + v2.t(), v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
LorentzVector operator-(const LorentzVector &v1, const LorentzVector &v2) 
{
	return LorentzVector(v1.t() - v2.t(), v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
void operator+=(LorentzVector &v1, const LorentzVector &v2) 
{
	v1.t(v1.t() + v2.t());
	v1.x(v1.x() + v2.x());
	v1.y(v1.y() + v2.y());
	v1.z(v1.z() + v2.z());
	//return LorentzVector(v1.t() + v2.t(), v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
void operator-=(LorentzVector &v1, const LorentzVector &v2) 
{
	v1.t(v1.t() - v2.t());
	v1.x(v1.x() - v2.x());
	v1.y(v1.y() - v2.y());
	v1.z(v1.z() - v2.z());
	//return LorentzVector(v1.t() - v2.t(), v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
LorentzVector operator-(const LorentzVector &v1) 
{
	return LorentzVector(-v1.t(), -v1.x(), -v1.y(), -v1.z());
}
LorentzVector operator*(const LorentzVector &v1, double a)
{
	return LorentzVector(v1.t() * a, v1.x() * a, v1.y() * a,  v1.z() * a);
}
LorentzVector operator*(double a, const LorentzVector &v1)
{
	return LorentzVector(v1.t() * a, v1.x() * a, v1.y() * a,  v1.z() * a);
}
void operator*=(LorentzVector &v1, double a)
{
	v1.t(v1.t() * a);
	v1.x(v1.x() * a);
	v1.y(v1.y() * a);
	v1.z(v1.z() * a);
}
double operator*(const LorentzVector &v1, const LorentzVector &v2)
{
	return -v1.t() * v2.t() + v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

double LorentzVector::norm() const
{	
	return sqrt(abs(x1*x1 + y1*y1 + z1*z1 - ct1*ct1));
}
void LorentzVector::zboost(double b)
{
	double ct2 = ct1;
	ct1 = (ct1 - b * z1) / sqrt(1 - b*b);
	z1 = (z1 - b*ct2) / sqrt(1 - b*b);
}

std::ostream &operator<<(std::ostream &out, const LorentzVector &v)
{
	return(out << "[" << v.t() << ", " << v.x() << ", " << v.y() << ", " << v.z() << "]");
}

double LorentzVector::dot(const LorentzVector &v1) const
{
	return -v1.t() * ct1 + v1.x() * x1 + v1.y() * y1 + v1.z() * z1;
}