#pragma once
#include "Base_Plane.h"
class Transport: public Base_Plane
{
public:
	Transport();
	~Transport();
	std::ostream& print() override
	{
		Base_Plane::print();
		cout << "Type: " << type << "\nAdditional gateway: " << std::boolalpha << dop_sluz << "\n---------------------" << std::endl;
		return cout;
	}
	void read(std::istream& in) override
	{
		Base_Plane::read(in);
		in >> type >> dop_sluz;
	}
private:
	string type;
	bool dop_sluz;
};

Transport::Transport()
{
}

Transport ::~Transport()
{
}