#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

using std::cout;
using std::string;
using std::cin;
using std::ostream;

class Base_Plane
{
public:
	Base_Plane();
	virtual ~Base_Plane();
	virtual std::ostream& print();
	virtual void read(std::istream&);
	double get_weight() const
	{
		return weight;
	}
	double get_fuel() const
	{
		return fuel;
	}
	double get_range_of_fly() const
	{
		return range_of_fly;
	}
	double get_rashod_fuel() const
	{
		return rashod_fuel;
	}
	int get_capacity() const
	{
		return capacity;
	}
	int get_carrying() const
	{
		return carrying;
	}
	bool operator==(int _rashod_fuel)
	{
		return this->rashod_fuel == _rashod_fuel;
	}
	friend ostream& operator<<(ostream&, Base_Plane*&);

private:
	string name;
	double weight;
	double fuel;
	double range_of_fly;
	double rashod_fuel;
	string motor_type;
	int price;
	int capacity;
	int carrying; // грузоподъемность
};

Base_Plane::Base_Plane()
{
}

Base_Plane::~Base_Plane()
{
}

std::ostream& Base_Plane::print()
{
	cout << "Name: " << name << "\nWeight: " << weight << " kg.\nTank: " << fuel << " litres.\nRange of fly: " << range_of_fly << " km.\nFuel consumption in 100 km : " << rashod_fuel << "\nMotor type: " <<  motor_type << "\nPrice: " << price << " $" << "\nCapacity: " << capacity << " people\nCarrying : " << carrying << "kg." << std::endl;
	return cout;
}
void Base_Plane::read(std::istream& in)
{
	in >> name >> weight >> fuel >> range_of_fly >> rashod_fuel >> motor_type >> price >> capacity >> carrying;
}

ostream& operator<<(ostream& out, Base_Plane*& plane)
{
	(*plane).print();
	return out;
}