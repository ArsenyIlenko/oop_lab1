#include <gtest/gtest.h>
#include <functions/functions.h>


using namespace vehicle;
using namespace std;


TEST(GetTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");

	veh1.set_v(2);
	veh2.set_v(3);
	veh3.set_v(4);
	veh2.set_t(20);

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);

	EXPECT_EQ(vehicle[0].get_model(), Car);
	EXPECT_EQ(vehicle[2].get_name(), "Harley");
	EXPECT_EQ(vehicle[0].get_v(), 2);
	EXPECT_EQ(vehicle[1].get_t(), 20);

}

TEST(CarCalcTest, Test) {

	auto veh1 = Vehicle(VehicleKinds::Car, "LADA Granta");
	veh1.set_v(2);
	auto tax1 = veh1.calc(10);

	EXPECT_EQ(tax1, 20);

}

TEST(FreightCalcTest, Test) {

	auto veh2 = Vehicle(VehicleKinds::Freight, "вџурї");
	veh2.set_v(3);
	veh2.set_t(26);
	auto tax2 = veh2.calc(10);

	EXPECT_EQ(tax2, 420);

}

TEST(MotorbikeCalcTest, Test) {

	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Yamaha");
	veh3.set_v(3);
	auto tax3 = veh3.calc(10);

	EXPECT_EQ(tax3, 9);

}

TEST(SizeTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta");
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї");
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha");

	veh1.set_v(2);
	veh2.set_v(2);
	veh3.set_v(2);
	veh4.set_v(4);
	veh5.set_v(4);
	veh6.set_v(4);
	veh2.set_t(20);
	veh5.set_t(10);

	vehicle.insert(veh1, 0);
	vehicle.insert(veh2, 1);
	vehicle.insert(veh3, 2);
	vehicle.insert(veh4, 3);
	vehicle.insert(veh5, 4);
	vehicle.insert(veh6, 5);

	auto s = vehicle.size();

	EXPECT_EQ(s, 6);

}

TEST(OperatorTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");

	veh1.set_v(2);
	veh2.set_v(2);
	veh3.set_v(2);
	veh2.set_t(20);

	vehicle.add(veh1);
	vehicle.add(veh2);

	EXPECT_EQ(vehicle[0].get_model(), Car);
	EXPECT_EQ(vehicle[0].get_name(), "Porsche Cayen");

	vehicle[0] = veh3;

	EXPECT_EQ(vehicle[0].get_model(), Motorbike);
	EXPECT_EQ(vehicle[0].get_name(), "Harley");

}

TEST(OperatorTestThrow, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta");
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї");
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha");

	veh1.set_v(2);
	veh2.set_v(2);
	veh3.set_v(2);
	veh4.set_v(4);
	veh5.set_v(4);
	veh6.set_v(4);
	veh2.set_t(20);
	veh5.set_t(10);

	vehicle.insert(veh1, 0);
	vehicle.insert(veh2, 1);
	vehicle.insert(veh3, 2);
	vehicle.insert(veh4, 3);
	vehicle.insert(veh5, 4);
	vehicle.insert(veh6, 5);

	EXPECT_ANY_THROW(vehicle.operator[](6));
}

TEST(InsertTestThrow, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");

	veh1.set_v(2);

	vehicle.insert(veh1, 0);
	vehicle.insert(veh1, 1);
	vehicle.insert(veh1, 2);
	vehicle.insert(veh1, 3);
	vehicle.insert(veh1, 4);
	vehicle.insert(veh1, 5);
	vehicle.insert(veh1, 6);
	vehicle.insert(veh1, 7);
	vehicle.insert(veh1, 8);
	vehicle.insert(veh1, 9);

	EXPECT_ANY_THROW(vehicle.insert(veh1, 10));

}

TEST(AddTestThrow, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Freight, "брьютры");

	veh1.set_v(2);

	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);
	vehicle.add(veh1);

	EXPECT_ANY_THROW(vehicle.add(veh1));

}

TEST(RemoveTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta");
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї");
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha");

	veh1.set_v(2);
	veh2.set_v(2);
	veh3.set_v(2);
	veh4.set_v(4);
	veh5.set_v(4); 
	veh6.set_v(4); 
	veh2.set_t(10); 
	veh5.set_t(20); 

	vehicle.add(veh1);
	vehicle.add(veh2);
	vehicle.add(veh3);
	vehicle.add(veh4);
	vehicle.add(veh5);
	vehicle.add(veh6);

	auto sizebef = vehicle.size();
	vehicle.remove(5);
	vehicle.remove(4);
	auto sizeaft = vehicle.size();
	auto maxim = max(vehicle, 4);

	EXPECT_EQ(sizebef, 6);
	EXPECT_EQ(sizeaft, 4);
	EXPECT_EQ(maxim, 1);

}

TEST(MaximTest, Test) {

	VehicleList vehicle;
	auto veh1 = Vehicle(VehicleKinds::Car, "Porsche Cayen");
	auto veh2 = Vehicle(VehicleKinds::Freight, "брьютры");
	auto veh3 = Vehicle(VehicleKinds::Motorbike, "Harley");
	auto veh4 = Vehicle(VehicleKinds::Car, "LADA Granta");
	auto veh5 = Vehicle(VehicleKinds::Freight, "вџурї");
	auto veh6 = Vehicle(VehicleKinds::Motorbike, "Yamaha");

	veh1.set_v(2);
	veh2.set_v(2);
	veh3.set_v(2);
	veh4.set_v(4);
	veh5.set_v(4);
	veh6.set_v(4);
	veh2.set_t(10);
	veh5.set_t(20);

	vehicle.insert(veh1, 0);
	vehicle.insert(veh2, 1);
	vehicle.insert(veh3, 2);
	vehicle.insert(veh4, 3);
	vehicle.insert(veh5, 4);
	vehicle.insert(veh6, 5);

	auto maxim = max(vehicle, 4);
	
	EXPECT_EQ(maxim, 4);

}