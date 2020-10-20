#include <iostream>
#include "networkStudent.h"
#include "student.h"
using namespace std;

// Constructors
NetworkStudent::NetworkStudent() {
    setDegreeProgram(degree);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysComplete, Degree degree) : Student(studentID, firstName, lastName, emailAddress, age, daysComplete, degree){
    setDegreeProgram(degree);
}

// Get and Set Degree

Degree NetworkStudent::getDegreeProgram() {
    return degree;
}

void NetworkStudent::setDegreeProgram(Degree degree) {
    this->degree = degree;
}

// Print Degree

void NetworkStudent::print() {
    this->Student::print();
    cout << "NETWORKING" << endl;
}

// Deconstructor

NetworkStudent::~NetworkStudent() {
    Student::~Student();
    delete this;
}
