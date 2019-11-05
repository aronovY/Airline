#pragma once
#pragma once
#include "Base_Plane.h"
class Agricultural : public Base_Plane
{
public:
	Agricultural();
	~Agricultural();
	std::ostream& print() override
	{
		Base_Plane::print();
		cout << "For what: " << for_what << "\nFertilizer: " << fertilizer << "\n---------------------" << std::endl;
		return cout;
	}
	void read(std::istream& in) override
	{
		Base_Plane::read(in);
		in >> for_what >> fertilizer;
	}
private:
	string for_what;
	string fertilizer;
};

Agricultural::Agricultural()
{
}

Agricultural ::~Agricultural()
{
}