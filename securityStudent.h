
/* 
 * File:   securityStudent.h
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:12 PM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student {
public:
    // Constructors
    SecurityStudent();
    SecurityStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysComplete, Degree degree);
    // Get and set degree
    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree degree);
    // Print Degree
    void print() override;
    // Deconstructor
    ~SecurityStudent();
private:
    Degree degree = SECURITY;
protected:
    
    
};

#endif /* SECURITYSTUDENT_H */

