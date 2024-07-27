#include <iostream>
#include<string>
using namespace std;

class Student
{private:
    string name;
    string address;
    int rollNo;
public:
    Student(string n, string a, int r, string CN)
    {
        name = n;
        address = a;
        rollNo = r;
        ClassName = CN;
    }
    string ClassName;
    void setName(string name) { this->name = name; }
    void setAddress(string address) { this->address = address; }
    void setRollNo(int rollNo) { this->rollNo = rollNo; }
    string getName() { return name; }
    string getAddress() { return address; }
    int getRollNo() { return rollNo; }
    string PrintInfo()
    {
        return "Student Information" "\nName of Student : " + name +
            "\nAddress of Student : " + address +
            "\nRoll No of Student : " + to_string(rollNo) + "\nClass Name : "+ClassName;
    }

};
class BSStudent : public Student
{private:
    int year;
public:
    BSStudent(string n, string a, int r,string CN, int y) :Student(n, a, r,CN)
    {
        year = y;
    }
    void setYear(int year){ this->year = year;}
    int setYear(){ return year; }
    string PrintInfo()
    {
       return "\n\n" +Student::PrintInfo() + "\nStudent is studying in : Year " + to_string(year) ;
    }
};
class MSStudent : public Student
{private:
    string Advisor;
public:
    MSStudent(string n, string a, int r,string CN, string ad) :Student(n, a, r,CN)
    {
        Advisor = ad;
    }
    void setAdvisor(string Advisor) { this->Advisor = Advisor; }
    string getAdvisor() { return Advisor; }
    string PrintInfo()
    {
        return "\n\n" +Student::PrintInfo() + "\nStudent's Advisor is : " + Advisor;
    }

};
class MSByCourse : public MSStudent
{public:
    MSByCourse(string n, string a, int r,string CN, string ad):MSStudent(n,a,r,CN,ad)
    {

    }
    string PrintInfo()
    {
        return  MSStudent::PrintInfo() ;
    }
};
class MSByResearch : public MSStudent
{
private:
    string ThesisStatus;
public:
    MSByResearch( string n, string a, int r,string CN, string ad,string TS ) :MSStudent(n, a, r,CN, ad)
    {
        ThesisStatus = TS;
    }
    void setThesisStatus(string ThesisStatus) {this->ThesisStatus = ThesisStatus;}
    string getThesisStatus() { return ThesisStatus; }
    string PrintInfo()
    {
        return MSStudent::PrintInfo() + "\nThesis Status is : " + ThesisStatus;
    }
};
int main()
{
    Student student = Student("ALI", "MIRPUR", 007,"Student");
    cout << student.PrintInfo()<<endl;
    BSStudent BSstudent = BSStudent("USMAN", "BHIMBER", 071,"BSStudent",1);
    cout << BSstudent.PrintInfo() << endl;
    MSStudent MSstudent = MSStudent("AHMED", "ISLAMABAD", 037,"MSStudent","ASIM");
    cout << MSstudent.PrintInfo() << endl;
    MSByCourse MSBycourse = MSByCourse("ABDULLAH", "MZD", 027, "MSByCourse", "AMIR");
    cout << MSBycourse.PrintInfo() << endl;
    MSByResearch MSByresearch = MSByResearch( "UMER", "LAHORE", 037, "MSByResearch", "WAQAS","WORKING" );
    cout << MSByresearch.PrintInfo() << endl;
        return 0;
    
}

