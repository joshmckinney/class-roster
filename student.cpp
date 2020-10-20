#include <iostream>
#include "student.h"

using namespace std;

// Initialize
Student::Student() {
    this->studentID="null";
    this->firstName="null";
    this->lastName="null";
    this->emailAddress="null";
    this->age=0;
    for (int iteratorDays = 0; iteratorDays < 3; iteratorDays++) {
        this->daysComplete[iteratorDays]=0;

    }

    
}

// Assign
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysComplete, Degree degreeType) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int iteratorDays = 0; iteratorDays < 3; iteratorDays++) {
        this->daysComplete[iteratorDays] = daysComplete[iteratorDays];

    }
}

// Accessors
string Student::getStudentID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmailAddress() {
    return emailAddress;
}
int Student::getStudentAge() {
    return age;
}
int* Student::getDaysComplete() {
    return daysComplete;
}
Degree Student::getDegreeProgram() {
    return Degree();
}

// Mutators
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setStudentAge(int age) {
    this->age = age;
}
void Student::setDaysComplete(int* daysComplete) {
    

    for (int iteratorDays = 0; iteratorDays < 3; iteratorDays++) {
        this->daysComplete[iteratorDays] = daysComplete[iteratorDays];

    }


    
}
void Student::setDegreeProgram(Degree) {
}

// Print
void Student::print() {
    //TODO
}

// Deconstruct
Student::~Student() {
}