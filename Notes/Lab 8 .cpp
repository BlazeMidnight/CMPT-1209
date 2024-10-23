#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
protected:
    string fullName;
    int employeeNum;
    int hireYear;
public:
    Employee();
    Employee(string, int, int);
    string getFullName() const;
    int getEmplyeeNum() const;
    int getHireYear() const;
    void setFullName(string);
    void setEmplyeeNum(int);
    void setHireYear(int);
    void input();
    void output() const;
    friend ostream& operator<< (ostream os, const Employee a);
    friend istream& operator>> (istream is, Employee a);

};

Employee::Employee() {
    fullName = "John Doe";
    employeeNum = 000000000;
    hireYear = 0000;
}

Employee::Employee(string a, int b, int c) {
    fullName = a;
    employeeNum = b;
    hireYear = c;
}

string Employee::getFullName() const {return fullName;}
int Employee::getEmplyeeNum() const {return employeeNum;}
int Employee::getHireYear() const {return hireYear;}
void Employee::setFullName(string name) {fullName = name;}
void Employee::setEmplyeeNum(int num) {employeeNum = num;}
void Employee::setHireYear(int year) {hireYear = year;}

void Employee::output() const {
    cout << "Name: " << left << setw(20) << fullName << "#: " << setw(15) << employeeNum << "Hire Year: " << setw(10) << hireYear << endl;
}

void Employee::input() {
    cout << "What is the Employee's Name?: ";
    getline(cin, fullName);
    cout << "What is their Employee Number?: ";
    cin >> employeeNum;
    cin.ignore();
    cout << "What year did thier employment begin?: ";
    cin >> hireYear;
}

class ProductionWorker: public Employee {
private:
    int shift;
    double hourlyPay;
public:
    ProductionWorker();
    ProductionWorker(int, double);
    int getShift() const;
    double getHourlyPay() const;
    void setShift(int);
    void setHourlyPay(double);
    void input();
    void output() const;
    
};

ProductionWorker::ProductionWorker() {
    shift = 1;
    hourlyPay = 0.00;
}

ProductionWorker::ProductionWorker(int a, double b) {
    shift = a;
    hourlyPay = b;
}

int ProductionWorker::getShift() const {return shift;}
double ProductionWorker::getHourlyPay() const {return hourlyPay;}
void ProductionWorker::setShift(int s) {if(s == 1 || s == 2) shift = s; else cout << "Invalid shift type." << endl;}
void ProductionWorker::setHourlyPay(double p) {hourlyPay = p;}

void ProductionWorker::output() const {
    cout << "Name: " << left << setw(20) << fullName << "#: " << setw(15) << employeeNum << "Hire Year: " << setw(8) << hireYear << setw(14);
    if (shift==1) {cout << "Shift: Day";} else {cout << "Shift: Night";}
    cout << "Hourly Pay: $" << hourlyPay << endl;
}

void ProductionWorker::input() {
    cout << "What is the Employee's Name?: ";
    getline(cin, fullName);
    cout << "What is their Employee Number?: ";
    cin >> employeeNum;
    cin.ignore();
    cout << "What year did thier employment begin?: ";
    cin >> hireYear;
    cout << "What shift? (1 = Day, 2 = Night)";
    cin >> shift;
    while (shift != 1 and shift != 2) {
        cout << "Shift must be day (1) or night (2). Please enter a valid number: ";
        cin >> shift;
    }
    cout << "What is their hourly pay?: ";
    cin >> hourlyPay;
}



int main() {
    Employee a, b("Jane Doe", 123456789, 1999);
    a.output();
    b.output();
    ProductionWorker c, d;
    c.output();
    d.input();
    d.output();
    

    return 0;
}
