#include <functions/functions.h>
#include <stdexcept>
#include <string>
#include <cmath>


using namespace vehicle;
using namespace std;


Vehicle::Vehicle(VehicleKinds model, string name):_model(model), _name(name){}
Vehicle::Vehicle():_model(Car), _name(""){}
VehicleList::VehicleList() :_size(0) {}

void Vehicle::set_v(float v) { _v = v; }
void Vehicle::set_t(float t) { _t = t; }
VehicleKinds Vehicle::get_model() { return _model; }
string Vehicle::get_name() { return _name; }
float Vehicle::get_v() { return _v; }
float Vehicle::get_t() { return _t; }
int VehicleList::size() { return _size; }

float Vehicle::calc(float s) {

    switch (_model) {

    case Car:

        return s * _v;

    case Freight:

        return s * _v * (_t / 2 + 1);

    case Motorbike:

        return 0.3 * s * _v;

    }

}


int vehicle::max(VehicleList& vehicle, float s) {

    int sz = vehicle.size();
    int index = 0;
    float max_tax = vehicle[0].calc(s);

    for (int i = 1; i < sz; i++) {

        const float tax = vehicle[i].calc(s);

        if (tax > max_tax) {

            max_tax = tax;
            index = i;

        }

    }

    return index;

}

Vehicle& VehicleList::operator[](int index) {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    return _vehicle[index];

}

const Vehicle& VehicleList::operator[](int index) const {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    return _vehicle[index];

}

void VehicleList::insert(Vehicle vehicle, int index) {

    if (index < 0 or index >= CAPACITY) {

        throw out_of_range("fault");

    }

    for (int i = _size - 1; i >= index; --i) {

        _vehicle[i] = _vehicle[i - 1];

    }

    _vehicle[index] = vehicle;
    _size++;
}

void VehicleList::add(Vehicle vehicle) {

    if (_size == CAPACITY) {

        throw runtime_error("fault");

    }
    
    _vehicle[_size] = vehicle;
    _size++;

}

void VehicleList::remove(int index) {

    if (index < 0 or index >= _size) {

        throw out_of_range("fault");

    }

    for (int i = index; i < _size - 1; i++) {

        _vehicle[i] = _vehicle[i + 1];

    }

    _size--;
}
