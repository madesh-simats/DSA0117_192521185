#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Staff {
protected:
    std::string name_;
    int id_;
    double basic_;

public:
    Staff(std::string name, int id, double basic)
        : name_(std::move(name)), id_(id), basic_(basic) {}
    virtual ~Staff() = default;

    virtual double pay() const = 0;
    virtual void display() const {
        std::cout << name_ << " (" << id_ << "): " << pay() << '\n';
    }
};

class Professor : public Staff {
    double research_;

public:
    Professor(std::string name, int id, double basic, double research)
        : Staff(std::move(name), id, basic), research_(research) {}
    double pay() const override { return basic_ + basic_ * 0.42 + research_; }
};

class LabAssistant : public Staff {
public:
    LabAssistant(std::string name, int id, double basic)
        : Staff(std::move(name), id, basic) {}
    double pay() const override { return basic_ + basic_ * 0.42; }
};

class GuestFaculty : public Staff {
    double hours_;
    double rate_;

public:
    GuestFaculty(std::string name, int id, double hours, double rate)
        : Staff(std::move(name), id, 0.0), hours_(hours), rate_(rate) {}
    double pay() const override { return hours_ * rate_; }
};

int main() {
    std::vector<std::unique_ptr<Staff>> staff;
    staff.push_back(std::make_unique<Professor>("Anita", 101, 50000, 8000));
    staff.push_back(std::make_unique<LabAssistant>("Kumar", 102, 30000));
    staff.push_back(std::make_unique<GuestFaculty>("Ravi", 103, 40, 900));

    for (const auto& person : staff) person->display();
    return 0;
}
