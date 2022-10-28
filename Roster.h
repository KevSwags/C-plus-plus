#include <iostream>
#define capacity 10;
using namespace std;

class Roster {
private:
string student_name;
string course_name;
int course_code;
int number_of_credits;
string instructor_name;

public:
Roster() {

}
void setstudent_name(string studentname) {
    student_name = studentname;
}

void setcourseName(string coursename) {
    course_name = coursename;
}

void setcourseCode(int coursecode) {
    course_code = coursecode;
}

void setnumberCredits(int numbercredits) {
    number_of_credits = numbercredits;
}

void setinstructorName(string instructorName) {
    instructor_name = instructorName;
}

string getstudent_name() {
    return student_name;
}

string getcourseName() {
    return course_name;
}

int getcourseCode() {
    return course_code;
}

int getnumberCredits() {
    return number_of_credits;
}

string getinstructorName() {
    return instructor_name;
}



};
