
/* 
 * File:   classRoster.cpp
 * Author: Joshua McKinney
 *
 * Created on November 9, 2019, 10:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

using namespace std;

// Constructors
Roster classRoster;
Roster::Roster(){
    
    //Empty classRosterArray 
    for (int i = 0; i < numStudents; ++i){
        classRosterArray[i]=nullptr;
    
    }
}

// Add student to roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
    // Switch to add student objects by subclass
    
    Student* studentPointer = nullptr;
    int dayCourseArray [] = {daysInCourse1,daysInCourse2,daysInCourse3};
    int spaceAvailableInArray=0;
    spaceAvailableInArray = arrayEmptySpaceAvailable();
    //cout<<spaceAvailableInArray<<endl;
    
    switch (degreeType) {
        // Per Degree enum 0 = Security, 1 = Networking, 2 = Software.
        
        case 0:
            //cout<<"Creating Student Security Object"<<endl;
            this->classRosterArray[spaceAvailableInArray]= new SecurityStudent(studentID,firstName,lastName,emailAddress,age,dayCourseArray,degreeType);  
            break;
        case 1:
            //cout<<"Creating Student Networking Object"<<endl;
            this->classRosterArray[spaceAvailableInArray]= new NetworkStudent(studentID,firstName,lastName,emailAddress,age,dayCourseArray,degreeType);  
            break;
        case 2:
            //cout<<"Creating Student Software Object"<<endl;
            this->classRosterArray[spaceAvailableInArray]= new SoftwareStudent(studentID,firstName,lastName,emailAddress,age,dayCourseArray,degreeType);  
            break;
    }
    
    
    
}
// Remove student by studentID
void Roster::remove(string studentID) {
    try
    {
        for( int i = 0; i < numStudents; i++) {
            if(classRosterArray[i] == nullptr)
            throw 1;
            if(classRosterArray[i]->getStudentID() == studentID) {
                classRosterArray[i] = nullptr;
                cout << "Student " << studentID << " deleted." << endl;
            };
        }
    }
    catch(int err_code)
    {
        cout << "ERROR CODE " << err_code << '-' << " No Student " << studentID << " found." << endl;
    }
}

void Roster::printAll() {
    for(int i = 0; i < numStudents; i++) {
        string degreeString;
        
        
        switch (classRoster.classRosterArray[i]->getDegreeProgram()) {
            case SECURITY:
                degreeString = "Security";
                break;
            case NETWORKING:
                degreeString = "Networking";
                break;
            case SOFTWARE:
                degreeString = "Software";
                break;
        }
        
        cout << classRoster.classRosterArray[i]->getStudentID() << "\t" << "First Name: " << classRoster.classRosterArray[i]->getFirstName() << "\t" << "Last Name: "
             << classRoster.classRosterArray[i]->getLastName() << "\t" << "Email: " << setw(20) << classRoster.classRosterArray[i]->getEmailAddress() << "\t"
             << "Age: " << classRoster.classRosterArray[i]->getStudentAge() << "\t" << "daysInCourse: " << classRoster.classRosterArray[i]->getDaysComplete()[0] << "," << classRoster.classRosterArray[i]->getDaysComplete()[1] << "," << classRoster.classRosterArray[i]->getDaysComplete()[2] << "\t"
             << "Degree Program: " << degreeString << endl;
        
       
           
    }    
}

// Print average days in course
void Roster::printAverageDaysInCourse(string query) {
    for(int i = 0; i < numStudents; i++) {
        string studentID = classRoster.classRosterArray[i]->getStudentID();
        if(studentID == query) {
            double averageDays = (((classRoster.classRosterArray[i]->getDaysComplete()[0]) + (classRoster.classRosterArray[i]->getDaysComplete()[1]) + (classRoster.classRosterArray[i]->getDaysComplete()[2])) / 3.0);
            cout << "Average Days: " << setprecision(3) << averageDays << " " << "(" << classRoster.classRosterArray[i]->getDaysComplete()[0] << ',' << classRoster.classRosterArray[i]->getDaysComplete()[1] << ',' << classRoster.classRosterArray[i]->getDaysComplete()[2] << ")" << endl; 
        }
    }
}
// Print invalid email addresses
void Roster::printInvalidEmails() {
    // Check for no spaces, an @ symbol and at least one period at the end
    for( int i = 0; i < numStudents; i++) {
        string emailAddress = classRoster.classRosterArray[i]->getEmailAddress();
        if(emailAddress.find(' ') != string::npos) {
            cout << "Found a space in email address " << classRoster.classRosterArray[i]->getEmailAddress() << endl;
        }
        else if(emailAddress.find('@') == string::npos) {
            cout << "No \'@\' in email address " << classRoster.classRosterArray[i]->getEmailAddress() << endl;
        }
        else if(emailAddress.find('.') == string::npos) {
            cout << "No top level domain ie .com or period found in email address " << classRoster.classRosterArray[i]->getEmailAddress() << endl;
        }
        else {
            break;
         }
    }
}
// Print by degree
void Roster::printByDegreeProgram(int degreeProgram) {
    for(int i = 0; i < numStudents; i++) {
        int degree = classRoster.classRosterArray[i]->getDegreeProgram();
        switch(degree) {
            case 0:
                if(degreeProgram != degree) {
                    break;
                }
                cout << classRoster.classRosterArray[i]->getStudentID() << "\t" << "First Name: " << classRoster.classRosterArray[i]->getFirstName() << "\t" << "Last Name: "
                << classRoster.classRosterArray[i]->getLastName() << "\t" << "Email: " << setw(20) << classRoster.classRosterArray[i]->getEmailAddress() << "\t"
                << "Age: " << classRoster.classRosterArray[i]->getStudentAge() << "\t" << "daysInCourse: " << classRoster.classRosterArray[i]->getDaysComplete()[0] << "," << classRoster.classRosterArray[i]->getDaysComplete()[1] << "," << classRoster.classRosterArray[i]->getDaysComplete()[2] << "\t"
                << "Degree Program: " << "Security" << endl;
                break;
            case 1:
                if(degreeProgram != degree) {
                    break;
                }
                cout << classRoster.classRosterArray[i]->getStudentID() << "\t" << "First Name: " << classRoster.classRosterArray[i]->getFirstName() << "\t" << "Last Name: "
                << classRoster.classRosterArray[i]->getLastName() << "\t" << "Email: " << setw(20) << classRoster.classRosterArray[i]->getEmailAddress() << "\t"
                << "Age: " << classRoster.classRosterArray[i]->getStudentAge() << "\t" << "daysInCourse: " << classRoster.classRosterArray[i]->getDaysComplete()[0] << "," << classRoster.classRosterArray[i]->getDaysComplete()[1] << "," << classRoster.classRosterArray[i]->getDaysComplete()[2] << "\t"
                << "Degree Program: " << "Networking" << endl;
                break;
            case 2:
                if(degreeProgram != degree) {
                    break;
                }
                cout << classRoster.classRosterArray[i]->getStudentID() << "\t" << "First Name: " << classRoster.classRosterArray[i]->getFirstName() << "\t" << "Last Name: "
                << classRoster.classRosterArray[i]->getLastName() << "\t" << "Email: " << setw(20) << classRoster.classRosterArray[i]->getEmailAddress() << "\t"
                << "Age: " << classRoster.classRosterArray[i]->getStudentAge() << "\t" << "daysInCourse: " << classRoster.classRosterArray[i]->getDaysComplete()[0] << "," << classRoster.classRosterArray[i]->getDaysComplete()[1] << "," << classRoster.classRosterArray[i]->getDaysComplete()[2] << "\t"
                << "Degree Program: " << "Software" << endl;
                break;
        }
    }
}

int Roster::arrayEmptySpaceAvailable(){
    int counter=0;
    for(Student* studentElement : this->classRosterArray){
        
        if(studentElement==nullptr){
            return counter;
        }else{
           counter++;
           if(counter>=numStudents){
           
               return counter;
           }
        } 
    }
    return 0;
}

int main(int argc, char** argv) {
    const string welcomeMsg = "Student Information Parser\nWritten in C++ by Joshua McKinney";
    cout << welcomeMsg << endl;
    
    Degree currentDegree;
    // Student Data Parser
    // Parse the data (csv) when program runs
    string result, cell[cellCount];
        for (int i = 0; i < numStudents; i++) {
            istringstream stream(studentData[i]);
            for (int c = 0; c < cellCount; c++) {
                getline(stream, result, ',');
                cell[c] = result;      
            }
            if(cell[8] == "SECURITY") {
                Degree currentDegree = SECURITY;
                classRoster.add(cell[0],cell[1],cell[2],cell[3],stoi(cell[4]),stoi(cell[5]),stoi(cell[6]),stoi(cell[7]),currentDegree);
            }
            else if(cell[8] == "NETWORK") {
                Degree currentDegree = NETWORKING;
                classRoster.add(cell[0],cell[1],cell[2],cell[3],stoi(cell[4]),stoi(cell[5]),stoi(cell[6]),stoi(cell[7]),currentDegree);
            }
            else {
                Degree currentDegree = SOFTWARE;
                classRoster.add(cell[0],cell[1],cell[2],cell[3],stoi(cell[4]),stoi(cell[5]),stoi(cell[6]),stoi(cell[7]),currentDegree);
            }
        }
    
    // Print the entire studentData table
    cout << "\nPrint all student data:" << endl;
    classRoster.printAll();
    
    // Print invalid email addresses
    cout << "\nInvalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    
    // Print daysInCourse
    cout << "\ndaysInCourse for student A5:" << endl;
    classRoster.printAverageDaysInCourse("A5");

    // Print by degree type
    cout << "\nPrint by degree program software:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    // Remove student object by studentID
    cout << "\nRemoving student by id A3.." << endl;
    classRoster.remove("A3");
    
    // Remove again and check if empty, return error message
    cout << "\nAttempt to remove student again, checking for errors.." << endl;
    classRoster.remove("A3");
    
    return 0;
}