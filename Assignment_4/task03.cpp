#include <iostream>
#include <string>

class Address {
    std::string city_;
    int pin_;

public:
    Address(std::string city, int pin) : city_(std::move(city)), pin_(pin) {
        std::cout << "Address ";
    }
    ~Address() { std::cout << "~Address "; }
    std::string str() const { return city_ + "-" + std::to_string(pin_); }
};

class Person {
protected:
    std::string name_;
    int age_;
    Address home_;

public:
    Person(const std::string& name, int age, const std::string& city, int pin)
        : name_(name), age_(age), home_(city, pin) {
        std::cout << "Person ";
    }
    virtual ~Person() { std::cout << "~Person "; }
};

class Course {
    std::string title_;

public:
    explicit Course(std::string title) : title_(std::move(title)) {
        std::cout << "Course ";
    }
    ~Course() { std::cout << "~Course "; }
};

class Student : public Person {
    long long regNo_;
    Course course_;

public:
    Student(const std::string& name, int age, long long regNo,
            const std::string& city, int pin, const std::string& course)
        : Person(name, age, city, pin), regNo_(regNo), course_(course) {
        std::cout << "Student ";
    }
    ~Student() override { std::cout << "~Student "; }

    void print() const {
        std::cout << "\n" << regNo_ << " " << name_ << " (" << age_
                  << ") " << home_.str() << '\n';
    }
};

int main() {
    {
        Student s("Kavya", 19, 192311001, "Salem", 636001, "C++");
        s.print();
    }
    std::cout << '\n';
    return 0;
}
