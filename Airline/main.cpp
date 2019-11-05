#include "Base_Plane.h"
#include "Agricultural.h"
#include "Transport_air.h"
#include "Passenger.h"
#include <fstream>

using std::vector;
class Error_opening
{
public:

};
void opening_file(std::ifstream & file)
{
	try
	{
		if (!file.is_open()) throw Error_opening();
		cout << "File open\n";
	}
	catch (Error_opening& e)
	{
		cout << "Error: file isn't opened\n";
		system("pause");
		exit(1);
	}
	catch (...)
	{
		cout << "Error\n";
		system("pause");
		exit(1);
	}
}

Base_Plane* get_pointer(char marker)
{
	if (marker == 'a')
		return new Agricultural;
	else if (marker == 't')
		return new Transport;
	else if (marker == 'p')
		return new Passenger;
}

int main()
{
	vector<Base_Plane*> planes;
	int all_planes = 0, all_people = 0, all_gruz = 0;
	std::ifstream file("Text.txt");
	opening_file(file);
	while (true)
	{
		char marker;
		file >> marker;
		if (file.eof())
			break;
		planes.push_back(get_pointer(marker));
		string str;
		std::getline(file, str);
		std::istringstream stream(str);
		planes.back()->read(stream);
	}
	sort(planes.begin(), planes.end(), [](Base_Plane*& planes_1, Base_Plane*& planes_2) { return planes_1->get_range_of_fly() > planes_2->get_range_of_fly(); });
	cout << "BELAVIA:\n---------------------\n";
	std::ostream_iterator<Base_Plane*&> it_os(cout);
	copy(planes.begin(), planes.end(), it_os);
	double fuel_min, fuel_max;

	system("pause");
	system("cls");

	std::for_each(planes.begin(), planes.end(),
		[&all_people]
	(Base_Plane*& _pas)
		{
			all_people += _pas->get_capacity();
		});

	std::for_each(planes.begin(), planes.end(),
		[&all_gruz]
	(Base_Plane*& _tra)
		{
			all_gruz += _tra->get_carrying();
		});

	cout << "Total capacity in airline: " << all_people << " people." << std::endl;
	cout << "Total carrying capacity in airline: " << all_gruz << " kg." << std::endl;

	system("pause");
	system("cls");

	cout << "\nEnter your desired fuel consumption(min, max): ";
	cin >> fuel_min >> fuel_max;
	cout << "\nPlanes with your fuel consumption: \n\n";
	std::copy_if(planes.begin(), planes.end(), it_os,
		[fuel_min, fuel_max, &all_planes]
	(Base_Plane*& _oil)
		{
			if (_oil->get_rashod_fuel() <= fuel_max && _oil->get_rashod_fuel() >= fuel_min)
			{
				all_planes++;
			}
			return _oil->get_rashod_fuel() <= fuel_max && _oil->get_rashod_fuel() >= fuel_min;
		});

	cout << "The number of aircraft of a given criterion: " << all_planes << std::endl;

	
	std::for_each(planes.begin(), planes.end(), [](Base_Plane*& for_del) {delete for_del; });
	system("pause");
	return 0;
}