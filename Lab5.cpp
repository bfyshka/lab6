#include <iostream> 
using namespace std;

class Engine
{
protected:
    int power;
    double capacity, fuelConsumption;
    string model;

    Engine() : power(100), capacity(1.0), fuelConsumption(0.1), model("Regular engine")
    {

    }

public:
    void setPower(int power) { this->power = power; }
    void setCapacity(double capacity) { this->capacity = capacity; }
    void setFuelConsumption(double fuelConsumption) { this->fuelConsumption = fuelConsumption; }
    void setModel(string model) { this->model = model; }
};

class Color
{
protected:
    string main, secondary;

    Color() : main("White"), secondary("White")
    {

    }

public:
    void setMain(string main) { this->main = main; }
    void setSecondary(string secondary) { this->secondary = secondary; }
};

enum class BodyType
{
    SEDAN, UNIVERSAL, HATCHBACK, MINIVEN, CROSSOVER,
    KUPE, PICKUP, CABRIOLET, LIMUZIN
};

inline ostream& operator << (ostream& out, BodyType type)
{
    switch (type)
    {
    case BodyType::SEDAN: return out << "SEDAN";
    case BodyType::UNIVERSAL: return out << "UNIVERSAL";
    case BodyType::HATCHBACK: return out << "HATCHBACK";
    case BodyType::MINIVEN: return out << "MINIVEN";
    case BodyType::CROSSOVER: return out << "CROSSOVER";
    case BodyType::KUPE: return out << "KUPE";
    case BodyType::PICKUP: return out << "PICKUP";
    case BodyType::CABRIOLET: return out << "CABRIOLET";
    case BodyType::LIMUZIN: return out << "LIMUZIN";
    default: return out << static_cast<int>(type);
    }
}

inline istream& operator >> (istream& in, BodyType& type)
{
    int intType;
    in >> intType;
    type = static_cast<BodyType>(intType);
    return in;
}

class Body
{
protected:
    BodyType type = BodyType::SEDAN;

public:
    void setType(BodyType type) { this->type = type; }
};

class Car : public Engine, public Color, public Body
{
public:
    Car() : Engine(), Color(), Body()
    {

    }

    friend ostream& operator << (ostream& out, Car& car)
    {
        cout << "Car info: " << endl;
        cout << "Engine model - " << car.model << endl;
        cout << "Power - " << car.power << endl;
        cout << "Capacity - " << car.capacity << endl;
        cout << "Fuel consumption - " << car.fuelConsumption << endl;
        cout << "Main color - " << car.main << endl;
        cout << "Secondary color - " << car.secondary << endl;
        cout << "Body type - " << car.type << endl;
        return out;
    }
};

int main()
{
    Car car;

    string model, main, secondary;
    BodyType type = BodyType::SEDAN;
    int power;
    double capacity, fuelConsumption;

    cout << "Engine model: ";
    cin >> model;
    cout << "Power: ";
    cin >> power;
    cout << "Capacity: ";
    cin >> capacity;
    cout << "Fuel consumption: ";
    cin >> fuelConsumption;
    cout << "Main color: ";
    cin >> main;
    cout << "Secondary color: ";
    cin >> secondary;
    cout << "Body type: ";
    cin >> type;

    car.setModel(model);
    car.setPower(power);
    car.setCapacity(capacity);
    car.setFuelConsumption(fuelConsumption);
    car.setMain(main);
    car.setSecondary(secondary);
    car.setType(type);
    cout << car;

    return 0;
}
