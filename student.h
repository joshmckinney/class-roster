
/* 
 * File:   student.h
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:12 PM
 */

#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"

class Student {
public:
    // Constructors
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysComplete[3], Degree degreeType);
    // Print Function
    virtual void print();
    // Deconstructor
    ~Student();
    
    
    // Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getStudentAge();
    int* getDaysComplete();
    virtual Degree getDegreeProgram();
    // Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setStudentAge(int age);
    void setDaysComplete(int daysComplete[]);
    void setDegreeProgram(Degree);
    
    
    
private:
    
    //Members Class Variables
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysComplete[3];

protected:
    
    
};

#endif /* STUDENT_H */

