
/* 
 * File:   softwareStudent.h
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:11 PM
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student {
public:
    // Constructors
    SoftwareStudent();
    SoftwareStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysComplete, Degree degree);
    // Get and set degree
    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree degree);
    // Print Degree
    void print() override;
private:
    // Deconstructor
    ~SoftwareStudent();
protected:
    Degree degree = SOFTWARE;
    
};

#endif /* SOFTWARESTUDENT_H */

