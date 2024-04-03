#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
������� ������������ ��� ���������� ������ ��� ������ � ������� ����������� ������ ��������.
������� ��������� ���� �������, ����� ��������� ��� ����������������� �������:
- � ���������� ������������ ������� ����� ��������;
- ��-�� ����� ��������� ������� �� �������� ������;
- ������� ����� ��������� �������� ����� ������� �����;
- ������ ������ �������� ����� �������� ������������ ��������� ����������� ����������� ��������, ��������� ������� ��������� ��������.
*/

// Flyweight (House) - ��������� ���������, � ������� �������� �������������� ����� �������� ������� ���������.

class Base abstract
{
protected:
	int power;
	int speed;
public:
	virtual void Create(double longitude, double latitude, string sprite) abstract;
};

/*
ConcreteFlyweight (PanelHouse) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
*/
class Infantry: public Base
{
public:
	Infantry()
	{
		power = 20;
		speed = 10;
	}
	void Create(double longitude, double latitude, string sprite) override
	{
		char buffer[200];
		sprintf_s(buffer, "Infantry has 20 power 10 speed and located in latitude - %f longitude - %f and has a sprite %s\0", latitude, longitude, sprite.c_str());
		cout << buffer << endl;
	}
};

/*
ConcreteFlyweight (BrickHouse) - ���������� ��������������.
��������� ��������� ������ Flyweight � ��������� ��� ������������� ���������� ���������.
������ ������ ConcreteFlyweight ������ ���� �����������.
����� ����������� �� ��������� ������ ���� ����������, �� ���� �� ��������� �� ���������.
*/
class CargoTruck: public Base
{
public:
	CargoTruck()
	{
		power = 0;
		speed = 70;
	}
	void Create(double longitude, double latitude, string sprite) override
	{
		char buffer[200];
		sprintf_s(buffer, "Cargo truck has 0 power 70 speed and located in latitude - %f longitude - %f and has a sprite %s\0", latitude, longitude, sprite.c_str());
		cout << buffer << endl;
	}
};

class HeavyGroundVehicle : public Base
{
public:
	HeavyGroundVehicle()
	{
		power = 150;
		speed = 15;
	}
	void Create(double longitude, double latitude, string sprite) override
	{
		char buffer[200];
		sprintf_s(buffer, "Heavy ground vehicle has 150 power 15 speed and located in latitude - %f longitude - %f and has a sprite %s\0", latitude, longitude, sprite.c_str());
		cout << buffer << endl;
	}
};

class LightGroundVehicle : public Base
{
public:
	LightGroundVehicle()
	{
		power = 30;
		speed = 50;
	}
	void Create(double longitude, double latitude, string sprite) override
	{
		char buffer[200];
		sprintf_s(buffer, "Light ground vehicle has 30 power 50 speed and located in latitude - %f longitude - %f and has a sprite %s\0", latitude, longitude, sprite.c_str());
		cout << buffer << endl;
	}
};

class Plane : public Base
{
public:
	Plane()
	{
		power = 100;
		speed = 300;
	}
	void Create(double longitude, double latitude, string sprite) override
	{
		char buffer[200];
		sprintf_s(buffer, "Plane has 100 power 300 speed and located in latitude - %f longitude - %f and has a sprite %s\0", latitude, longitude, sprite.c_str());
		cout << buffer << endl;
	}
};


/*
FlyweightFactory - ������� ���������������:
- ������� �������-�������������� � ��������� ���;
- ������������ ������� ���������� ���������������. ����� ������ ����������� ��������������,
������ FlyweightFactory ������������� ������������ ���������.
*/
class BaseFactory
{
	map<string, Base*> military;
public:
	BaseFactory()
	{
		military["Infantry"] = new Infantry();
		military["CargoTruck"] = new CargoTruck();
		military["HeavyGroundVehicle"] = new HeavyGroundVehicle();
		military["LightGroundVehicle"] = new LightGroundVehicle();
		military["Plane"] = new Plane();
	}
	~BaseFactory()
	{
		delete military["Infantry"];
		delete military["CargoTruck"];
		delete military["HeavyGroundVehicle"];
		delete military["LightGroundVehicle"];
		delete military["Plane"];
		military.clear();
	}
	Base* GetMilitary(string key)
	{
		if (military[key]!= nullptr)
			return military[key];
		else
			return nullptr;
	}
};

int main()
{
	/*
	 Client - ������:
		- ������ ������ �� ������ ��� ���������� ���������������;
		- ��������� ��� ������ ������� ��������� ���������������.
	 */

	double longitude = 37.61;
	double latitude = 55.74;
	string sprite = "Sprite.png";

	BaseFactory *Basefactory = new BaseFactory();

	for (int i = 0; i < 5; i++)
	{
		Base *Infantry = Basefactory->GetMilitary("Infantry");
		if (Infantry != nullptr)
			Infantry->Create(longitude, latitude, sprite);
		longitude += 0.1;
		latitude += 0.1;
	}

	for (int i = 0; i < 5; i++)
	{
		Base *CargoTruck = Basefactory->GetMilitary("CargoTruck");
		if (CargoTruck != nullptr)
			CargoTruck->Create(longitude, latitude, sprite);
		longitude += 0.1;
		latitude += 0.1;
	}

	for (int i = 0; i < 5; i++)
	{
		Base* HeavyGroundVehicle = Basefactory->GetMilitary("HeavyGroundVehicle");
		if (HeavyGroundVehicle != nullptr)
			HeavyGroundVehicle->Create(longitude, latitude, sprite);
		longitude += 0.1;
		latitude += 0.1;
	}

	for (int i = 0; i < 5; i++)
	{
		Base* LightGroundVehicle = Basefactory->GetMilitary("LightGroundVehicle");
		if (LightGroundVehicle != nullptr)
			LightGroundVehicle->Create(longitude, latitude, sprite);
		longitude += 0.1;
		latitude += 0.1;
	}

	for (int i = 0; i < 5; i++)
	{
		Base* Plane = Basefactory->GetMilitary("Plane");
		if (Plane != nullptr)
			Plane->Create(longitude, latitude, sprite);
		longitude += 0.1;
		latitude += 0.1;
	}

	delete Basefactory;
	system("pause");
}