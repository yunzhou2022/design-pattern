#include <iostream>
#include <string>
using namespace std;

class House {
public:
  string basic;
  string wall;
  string roofed;
};

class HouseBuilder {
public:
  House house;
  virtual void buildBasic() = 0;
  virtual void buildWall() = 0;
  virtual void buildRoofed() = 0;
};

class CommonHouse : public HouseBuilder {
public:
  void buildBasic() { house.basic = "common basic"; }
  void buildWall() { house.wall = "common wall"; }
  void buildRoofed() { house.roofed = "common roofed"; }
  CommonHouse() { cout << "CommonHouse" << endl; }
};

class HighHouse : public HouseBuilder {
public:
  void buildBasic() { house.basic = "high basic"; }
  void buildWall() { house.wall = "high wall"; }
  void buildRoofed() { house.roofed = "high roofed"; }
  HighHouse() { cout << "HighHouse" << endl; }
};

class OtherHouse : public HouseBuilder {
public:
  void buildBasic() { house.basic = "other basic"; }
  void buildWall() { house.wall = "other wall"; }
  void buildRoofed() { house.roofed = "other roofed"; }
  OtherHouse() { cout << "OtherHouse" << endl; }
};

class HouseDirector {
public:
  void createHouse(HouseBuilder *houseBuilder) {
    houseBuilder->buildBasic();
    houseBuilder->buildWall();
    houseBuilder->buildRoofed();
  }
};

int main() {
  HouseDirector houseDirector;
  houseDirector.createHouse(new CommonHouse());
  houseDirector.createHouse(new HighHouse());
  houseDirector.createHouse(new OtherHouse());

  return 0;
}