#include <iostream>
#include <vector>
using namespace std;

class Car {
private:
    int age;
    string brand;
public:
    Car() : age(2000), brand("DEFAULT") {cout << "default\n";}
    Car(int age, string brand) : age(age), brand(brand) {cout << "default value\n";}
    Car(const Car& obj) : age(obj.age), brand(obj.brand) {cout << "copy\n";}
    Car(Car&& obj) : age(move(obj.age)), brand(move(obj.brand)) {cout << "move\n";}

    void showInfo() {cout << this->brand << "_" << this->age << "\n";}
    void setAge(int age) {this->age = age;}
    void setBrand(string brand) {this->brand = brand;}
};
int main(int argc, char* argv[]) {
    Car carA(2020, "AAA");
    Car carB = carA;
    Car carC = move(carB);

    cout << "\ncarA: ";
    carA.showInfo();
    cout << "carB: copy from carA (had been moved to carC) ";
    carB.showInfo();
    cout << "carC: (get resource from carB) ";
    carC.showInfo();

    vector<Car> cars;
    cars.reserve(2);
    cout << "\npush_back:\n";
    cars.push_back(carA);

    cout << "\nemplace_back:\n";
    cars.emplace_back(2023, "TESLA");
}