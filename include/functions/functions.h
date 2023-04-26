#pragma once
#define CAPACITY 10
#include <string>


namespace vehicle {

	enum VehicleKinds { 
		Car,
		Freight,
		Motorbike
	};

	class Vehicle { 

	private:

		VehicleKinds _model; 
		std::string _name;
		float _v;
		float _t; 

	public:

		void set_v(float v); 
		void set_t(float t);
		VehicleKinds get_model();
		std::string get_name();
		float get_v();
		float get_t();
		Vehicle(VehicleKinds model, std::string name);
		Vehicle();
		float calc(float s);
	};

	class VehicleList {

	private:

		Vehicle _vehicle[CAPACITY];
		int _size;

	public:

		VehicleList();
		int size();
		const Vehicle &operator[](int index) const;
		Vehicle& operator[](int index);
		void insert(Vehicle vehicle, int index);
		void add(Vehicle vehicle);
		void remove(int index);
	};
	int max(VehicleList& vehicle, float s);
}

