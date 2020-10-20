
/* 
 * File:   networkStudent.h
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:11 PM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {
public:
    // Constructors
    NetworkStudent();
    NetworkStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysComplete, Degree degree);
    // Get and set degree
    Degree getDegreeProgram() override;
    void setDegreeProgram(Degree degree);
    // Print Degree
    void print() override;
private:
    // Deconstructor
    ~NetworkStudent();
protected:
    Degree degree = NETWORKING;
    
};

#endif /* NETWORKSTUDENT_H */

