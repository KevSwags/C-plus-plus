#include <iostream>
using namespace std;

class Student {
    private:
    string lastname, firstname, standing;
    int credits;
    double gpa; 
    string dob;
    string matriationDate;

    public:
    Student(string fname, string lname, int credit, double GPA, string DOB, string mdate) {
        firstname = fname;
        lastname = lname;
        credits = credit;
        gpa = GPA;
        dob = DOB;
        matriationDate = mdate;
    }

    Student() {
        firstname = "";
        lastname = "";
        credits = 0;
        gpa = 0.0;
        dob = "";
        matriationDate = "";
    }

    void input() {
        cout << "FirstName: ";
        cin >> firstname;

        cout << "LastName: ";
        cin >> lastname;

        cout << "Credits: ";
        cin >> credits;

        cout << "GPA: ";
        cin >> gpa;

        cout << "Date of Birth: ";
        cin >> dob;

        cout << "Matriculation date: ";
        cin >> matriationDate;

        cout << endl;
    }

    void standingyear(int x) {
    if((x >= 0) && (x < 15))
        standing = "Lower Freshman";
    else if((x >= 15) && (x < 30))
        standing = "Upper Freshman";
    else if((x >= 30) && (x < 45))
        standing = "Upper Freshman";
    else if((x >= 45) && (x < 60))
        standing = "Upper Freshman";
    else if((x >= 60) && (x < 75))
        standing = "Upper Freshman";
    else if((x >= 75) && (x < 90))
        standing = "Upper Freshman";
    else if((x >= 90) && (x < 105))
        standing = "Upper Freshman";
    else if((x >= 150))
        standing = "Upper Freshman";

    else 
    cout << "credit error!" << endl;
    }

    void output() {
        cout << "OUTPUT: " << endl;
        cout << "Firstname: " << firstname << endl;
        cout << "Lastname: " << lastname << endl;
        cout << "Standing: " << standing << endl;
        cout << "Credits: " << credits << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Matriculation date: " << matriationDate << endl;
    }

    void setfirstname(string setfirstName) {
        firstname = setfirstName;
    }

    void setlastname(string setlastName) {
        lastname = setlastName;
    }

    void setstanding(string setstanding) {
        standing = setstanding;
    }

    void setcredits(int setcredits) {
        credits = setcredits;
    }

    void setgpa(double setgpa) {
        gpa = setgpa;
    }

    void setdob(string setdob) {
        dob = setdob;
    }

    void setmatriculationdate(string setmdate) {
        matriationDate = setmdate;
    }

    string getfirstname() {
        return firstname;
    }

    string getlastname() {
        return lastname;
    }

    string getstanding() {
        return standing;
    }

    int getcredits() {
        return credits;
    } 

    double getgpa() {
        return gpa;
    }

    string getdob() {
        return dob;
    }

    string getmatriculationdate() {
        return matriationDate;
    }

};


int main() {
    Student s1("","",0,0.0,"", "");
    s1.input();
    int credits = s1.getcredits();
    s1.standingyear(credits);
    s1.output();
    cout << endl;
    
    return 0;
}