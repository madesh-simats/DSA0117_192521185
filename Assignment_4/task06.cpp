#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string registration_;
    double dailyRate_;
    bool rented_ = false;

public:
    Vehicle(std::string registration, double dailyRate)
        : registration_(std::move(registration)), dailyRate_(dailyRate) {}
    virtual ~Vehicle() = default;

    virtual double charge(int days) const = 0;
    virtual std::string type() const = 0;

    void rent() {
        if (!rented_) {
            rented_ = true;
            std::cout << registration_ << " rented\n";
        } else {
            std::cout << registration_ << " is already rented\n";
        }
    }

    void returnVehicle(int daysLate = 0) {
        if (rented_) {
            rented_ = false;
            std::cout << registration_ << " returned; late charge: "
                      << daysLate * 100.0 << '\n';
        } else {
            std::cout << registration_ << " was not rented\n";
        }
    }

    void list() const {
        std::cout << type() << " | " << registration_
                  << " | daily rate: " << dailyRate_ << '\n';
    }
};

class Bicycle : public Vehicle {
public:
    using Vehicle::Vehicle;
    double charge(int days) const override { return dailyRate_ * days; }
    std::string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelOrChargeLevel_;
    std::string serviceDue_;

public:
    MotorVehicle(std::string reg, double rate, double level, std::string due)
        : Vehicle(std::move(reg), rate), fuelOrChargeLevel_(level),
          serviceDue_(std::move(due)) {}
};

class TwoWheeler : public MotorVehicle {
public:
    using MotorVehicle::MotorVehicle;
    double charge(int days) const override { return dailyRate_ * days; }
    std::string type() const override { return "Two-wheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats_;

public:
    Car(std::string reg, double rate, double level, std::string due, int seats)
        : MotorVehicle(std::move(reg), rate, level, std::move(due)), seats_(seats) {}
    double charge(int days) const override { return dailyRate_ * days; }
    std::string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryCapacityKWh_;
    double kWhRate_;

public:
    ElectricCar(std::string reg, double rate, double level, std::string due,
                int seats, double batteryCapacity, double kWhRate)
        : Car(std::move(reg), rate, level, std::move(due), seats),
          batteryCapacityKWh_(batteryCapacity), kWhRate_(kWhRate) {}

    double charge(int days) const override {
        return dailyRate_ * days + batteryCapacityKWh_ * kWhRate_;
    }
    std::string type() const override { return "Electric car"; }
};

class ElectricBus : public Vehicle {
    int seats_;
    double batteryCapacityKWh_;

public:
    ElectricBus(std::string reg, double rate, int seats, double batteryCapacity)
        : Vehicle(std::move(reg), rate), seats_(seats),
          batteryCapacityKWh_(batteryCapacity) {}

    double charge(int days) const override {
        return dailyRate_ * days + batteryCapacityKWh_ * 0.20;
    }
    std::string type() const override { return "Electric bus"; }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("BIKE-101", 100));
    fleet.push_back(std::make_unique<TwoWheeler>("TN01-AB1234", 250, 80, "2027-01-15"));
    fleet.push_back(std::make_unique<Car>("TN01-CD5678", 1500, 70, "2027-02-10", 5));
    fleet.push_back(std::make_unique<ElectricCar>("TN01-EV0001", 1800, 90,
                                                   "2027-03-01", 5, 60, 0.20));
    fleet.push_back(std::make_unique<ElectricBus>("TN01-EB0001", 3500, 30, 180));

    for (const auto& vehicle : fleet) {
        vehicle->list();
        vehicle->rent();
        std::cout << "Rental charge for 2 days: "
                  << vehicle->charge(2) << '\n';
        vehicle->returnVehicle(1);
    }
    return 0;
}
