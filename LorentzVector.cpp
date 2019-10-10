#include <iostream>
#include <cmath>
#include "LorentzVector.h"
		LorentzVector::LorentzVector(){ //default constructor
		vt=0;
		vx=0;
		vy=0;
		vz=0;
		} 
		LorentzVector::LorentzVector(double t, double x, double y, double z){ //t,x,y,z constructor
			this->vt=t;
			this->vx=x;
			this->vy=y;
			this->vz=z;
		}
		double LorentzVector::t() const { //get t
			return vt;
		}
		double LorentzVector::x() const { //get x
			return vx;
		}
		double LorentzVector::y() const { //get y
			return vy;
		}
		double LorentzVector::z() const { //get z
			return vz;
		}
		double LorentzVector::norm() const { //get norm
			return sqrt(std::abs(vx * vx + vy * vy + vz * vz - vt * vt));
		}
		void LorentzVector::t(double n){ //put t
			vt=n;
		}
		void LorentzVector::x(double n){ //put x
			vx=n;
		}
		void LorentzVector::y(double n){ //put y
			vy=n;
		}
		void LorentzVector::z(double n){ //put z
			vz=n;
		}
		void LorentzVector::operator+=(const LorentzVector& v){
			vt += v.t();
			vx += v.x();
		 	vy += v.y();
		  	vz += v.z();	
		}
		void LorentzVector::operator-=(const LorentzVector& v){
			vt -= v.t();
			vx -= v.x();
		 	vy -= v.y();
		  	vz -= v.z();	
		}
		void LorentzVector::operator*=(double a){
			vt *= a;
			vx *= a;
		 	vy *= a;
		  	vz *= a;
		}
		LorentzVector LorentzVector::operator+(const LorentzVector& v) const{
			LorentzVector vres(vt + v.t() ,vx + v.x() ,vy + v.y() ,vz + v.z());
			return vres;
		}
		LorentzVector LorentzVector::operator-(const LorentzVector& v) const{
			LorentzVector vres(vt - v.t() ,vx - v.x() ,vy - v.y() ,vz - v.z());
			return vres;
		}
		LorentzVector operator*(const LorentzVector& v, double a){
			LorentzVector vres(v.t() * a ,v.x() * a ,v.y() * a ,v.z() * a);
			return vres;
		}
		std::ostream& operator<<(std::ostream& out, const LorentzVector& v){
			out<<"("<< v.t() <<", "<< v.x() <<", "<< v.y() <<", "<< v.z() <<")\n";
			return out;
		}
		
	/*	LorentzVector LorentzVector::add(const LorentzVector& v2) const{ //addition
			LorentzVector vres(vt + v2.t() , vx + v2.x() , vy + v2.y() , vz + v2.z());
			return vres;
		} 
		LorentzVector LorentzVector::sub(const LorentzVector& v2) const{ //subtraction
			LorentzVector vres(vt - v2.t() , vx - v2.x() , vy - v2.y() , vz - v2.z());
			return vres;
		}
		LorentzVector LorentzVector::mul(double a) const{ //multiplication by a const
			LorentzVector vres(vt * a ,vx * a ,vy * a ,vz * a);
			return vres;
		}*/
		double LorentzVector::dot(const LorentzVector& v2) const{
			return (-vt * v2.vt + vx * v2.vx + vy * v2.vy + vz * v2.vz);	
		}
		void LorentzVector::zboost(double beta){
			double vzOld=vz;
			vz=(vz-vt*beta)/sqrt(1-beta*beta);
			vt=(vt-vzOld*beta)/sqrt(1-beta*beta);
		}
	/*	void LorentzVector::print() const {
			std::cout<<"("<< vt <<", "<< vx <<", "<< vy <<", "<< vz <<")\n";
		} 
		void LorentzVector::read(){
			std::cin>>vt>>vx>>vy>>vz;		
		}*/
