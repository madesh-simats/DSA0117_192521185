#include <iostream>
#include <string>

class Person {
protected:
    std::string name_;
    int id_;
    std::string phone_;

public:
    Person(std::string name, int id, std::string phone)
        : name_(std::move(name)), id_(id), phone_(std::move(phone)) {
        std::cout << "Person ";
    }
    virtual ~Person() = default;
};

class Student : virtual public Person {
protected:
    std::string programme_;
    double cgpa_;

public:
    Student(std::string name, int id, std::string phone,
            std::string programme, double cgpa)
        : Person(std::move(name), id, std::move(phone)),
          programme_(std::move(programme)), cgpa_(cgpa) {
        std::cout << "Student ";
    }
};

class Staff : virtual public Person {
protected:
    std::string department_;
    double salary_;

public:
    Staff(std::string name, int id, std::string phone,
          std::string department, double salary)
        : Person(std::move(name), id, std::move(phone)),
          department_(std::move(department)), salary_(salary) {
        std::cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(std::string name, int id, std::string phone,
                      std::string programme, double cgpa,
                      std::string department, double salary)
        : Person(std::move(name), id, std::move(phone)),
          Student(name_, id_, phone_, std::move(programme), cgpa),
          Staff(name_, id_, phone_, std::move(department), salary) {
        std::cout << "TA ";
    }

    void display() const {
        std::cout << "\nName: " << name_ << "\nID: " << id_
                  << "\nPhone: " << phone_ << "\nProgramme: " << programme_
                  << "\nCGPA: " << cgpa_ << "\nDepartment: " << department_
                  << "\nSalary: " << salary_ << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship_;

public:
    ResearchScholar(std::string name, int id, std::string phone,
                    std::string programme, double cgpa, double fellowship)
        : Person(std::move(name), id, std::move(phone)),
          Student(name_, id_, phone_, std::move(programme), cgpa),
          fellowship_(fellowship) {}
    void displayFellowship() const {
        std::cout << "Fellowship: " << fellowship_ << '\n';
    }
};

int main() {
    TeachingAssistant ta("Kavya", 501, "9876543210", "CSE", 8.7,
                         "Computer Science", 25000);
    ta.display();
    std::cout << "\nConstruction order check: ";
    return 0;
}
