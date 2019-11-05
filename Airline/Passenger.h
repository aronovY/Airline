#pragma once
#include "Base_Plane.h"
class Passenger : public Base_Plane
{
public:
	Passenger();
	~Passenger ();
	
	std::ostream& print() override
	{
		Base_Plane::print();
		cout << "Type: " << type << "\nEconomy Class: " << std::boolalpha << economy_class << "\nFirst Class: " << std::boolalpha << first_class << "\nBusiness Class: " << std::boolalpha << bizness_class << "\n---------------------" << std::endl;
		return cout;
	}
	void read(std::istream& in) override
	{
		Base_Plane::read(in);
		in >> type >> economy_class >> first_class >> bizness_class;
	}
private:
	string type;
	bool economy_class;
	bool first_class;
	bool bizness_class; 
};

Passenger::Passenger ()
{
}

Passenger ::~Passenger ()
{
}