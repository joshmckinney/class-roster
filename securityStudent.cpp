#include <iostream>
#include "securityStudent.h"
#include "student.h"
using namespace std;

// Constructors
SecurityStudent::SecurityStudent() {
    setDegreeProgram(degree);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysComplete, Degree degree) : Student(studentID, firstName, lastName, emailAddress, age, daysComplete, degree) {
    setDegreeProgram(degree);
}

// Get and Set Degree

Degree SecurityStudent::getDegreeProgram() {
    return degree;
}

void SecurityStudent::setDegreeProgram(Degree degree) {
    this->degree = degree;
}

// Print Degree

void SecurityStudent::print() {
    this->Student::print();
    cout << degree << endl;
}

// Deconstructor

SecurityStudent::~SecurityStudent() {
    Student::~Student();
    delete this;
}
