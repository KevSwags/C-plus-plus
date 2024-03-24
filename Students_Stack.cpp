#include <iostream>
#include <stack>
#include "Roster.h"
using namespace std;


Roster addstudent() 
{
    Roster r;
        cout << "You chose Add a student: " << endl;
        cout << "Student Name: ";
        string s;
        cin.ignore();
        getline(cin, s);
        r.setstudent_name(s);

        cout << "Course Name: ";
        string c;
        cin.ignore();
        getline(cin, c);
        r.setcourseName(c);

        cout << "Course Code: ";
        int ccode;
        cin >> ccode;
        r.setcourseCode(ccode);

        cout << "Course Earn: ";
        int cearn;
        cin >> cearn;
        r.setnumberCredits(cearn);

        cout << "Instructor's Name: ";
        string i;
       cin.ignore();
        getline(cin, i);
        r.setinstructorName(i);
        cout << endl;

        return r;
}

stack<Roster> remove(stack<Roster> list_students, string rName) {
    stack<Roster> Students;

while(!list_students.empty()){
Roster Student = list_students.top();
list_students.pop();
if(Student.getstudent_name() != rName) 
Students.push(Student);
}

cout << rName << " is removed from the list!" << endl;
cout << endl;
return Students;
}

void search_student(stack<Roster> list_students) {

Roster aStudent = list_students.top();
    cout << "Student Name: " << aStudent.getstudent_name() << endl;
    cout << "Course Name: " << aStudent.getcourseName() << endl;
    cout << "Course Code : " << aStudent.getcourseCode() << endl;
    cout << "Credits Earned : " << aStudent.getnumberCredits() << endl;
    cout << "Instructor Name : " << aStudent.getinstructorName() << endl;
    cout << endl;
}

void output_students(stack<Roster> list) {
    stack<Roster> S;
    S = list;

while(!S.empty()){
Roster student = S.top();
S.pop();
    cout << "Student Name: " << student.getstudent_name() << endl;
    cout << "Course Name: " << student.getcourseName() << endl;
    cout << "Course Code : " << student.getcourseCode() << endl;
    cout << "Credits Earned : " << student.getnumberCredits() << endl;
    cout << "Instructor Name : " << student.getinstructorName() << endl;
    cout << endl;
}
}
int main() {
stack<Roster> list_students;
bool repeat = true;
int choose;
while(repeat) {
cout << "Would you like to: " << endl;
cout << "1. Add a student" << endl;
cout << "2. Remove a student " << endl;
cout << "3. Search a student " << endl;
cout << "4. Output all Students from a roster to console" << endl;
cout << "0. Leave" << endl;

cin >> choose;

if(choose == 0)
return 0;

else if(choose == 1)
list_students.push(addstudent());

else if(choose == 2) {
 if(list_students.size() == 0) {
    cout << "ERROR! you did not enter a student!" << endl;
    return 0;
}

cout << "Student's name: ";
string rName;
cin.ignore();
getline(cin, rName);

Roster s = list_students.top();
if(s.getstudent_name() == rName) {
list_students = remove(list_students, rName);
}
else
cout << "No student found" << endl;
}

else if(choose == 3) {
    if(list_students.size() == 0) {
    cout << "ERROR! you did not enter a student!" << endl;
    return 0;
}
    else {
        string search;
        cout << "Name: ";
        cin >> search;
        
        Roster a_Student = list_students.top();
        if(a_Student.getstudent_name() == search){
        search_student(list_students);
        }
        else
        cout << "Student Does not exist\n";


}

}

else if(choose == 4) {
    if(list_students.size() == 0) {
        cout << "NO STUDENTS FOUND!";
        return 0;
    }
    output_students(list_students);
}


}
 return 0;
}
