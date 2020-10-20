#include <iostream>
#include "softwareStudent.h"
#include "student.h"
using namespace std;

// Constructors
SoftwareStudent::SoftwareStudent() {
    setDegreeProgram(degree);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysComplete, Degree degree) : Student(studentID, firstName, lastName, emailAddress, age, daysComplete, degree) {
    setDegreeProgram(degree);
}

// Get and Set Degree

Degree SoftwareStudent::getDegreeProgram() {
    return degree;
}

void SoftwareStudent::setDegreeProgram(Degree degree) {
    this->degree = degree;
}

// Print Degree

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << endl;
}

// Deconstructor

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
    delete this;
}