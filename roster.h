
/* 
 * File:   roster.h
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:11 PM
 */

#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"

// Number of Students
static const int numStudents = 5;
// Number of table cells
static const int cellCount = 9;
// Student Data Table
const std::string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Joshua,McKinney,jmck@test.com,29,13,37,42,SOFTWARE",
};

class Roster {


    
    
public:
    
    // Constructors
    
    Roster();
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType );
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram);
    int arrayEmptySpaceAvailable();
    Student* classRosterArray[numStudents];
  
    // Destructor
    ~Roster() {
        std::cout << "\nExiting!" << std::endl;
    }
    
    
    
};
#endif /* ROSTER_H */

