// Ellawynn Sian 
// Student id 300382676

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PersonData {
protected:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
public:
    PersonData();
    PersonData(string, string, string, string, string, string, string);
    string getLastName() const;
    string getFirstName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getPhone() const;
    void setLastName(string);
    void setFirstName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setPhone(string);
    void input();
    void output() const;
};

PersonData::PersonData() {
    lastName = "Doe";
    firstName = "John";
    address = "0000 Knowwhere Street";
    city = "Somewhere";
    state = "Alaska";
    zip = "A1B C2D";
    phone = "1234567890";
}

PersonData::PersonData(string a, string b, string c, string d, string e, string f, string g) {
    lastName = a;
    firstName = b;
    address = c;
    city = d;
    state = e;
    zip = f;
    phone = g;
}

string PersonData::getLastName() const { return lastName; }
string PersonData::getFirstName() const { return firstName; }
string PersonData::getAddress() const { return address; }
string PersonData::getCity() const { return city; }
string PersonData::getState() const { return state; }
string PersonData::getZip() const { return zip; }
string PersonData::getPhone() const { return phone; }
void PersonData::setLastName(string a) { lastName = a; }
void PersonData::setFirstName(string b) { firstName = b; }
void PersonData::setAddress(string c) { address = c; }
void PersonData::setCity(string d) { city = d; }
void PersonData::setState(string e) { state = e; }
void PersonData::setZip(string f) { zip = f; }
void PersonData::setPhone(string g) { phone = g; }

void PersonData::output() const {
    cout << left
         << "~PERSONAL DATA~" << endl
         << setw(20) << "\tLast Name:" << lastName << endl
         << setw(20) << "\tFirst Name:" << firstName << endl
         << setw(20) << "\tAddress:" << address << endl
         << setw(20) << "\tCity:" << city << endl
         << setw(20) << "\tState:" << state << endl
         << setw(20) << "\tZip Code:" << zip << endl
         << setw(20) << "\tPhone #:" << phone << endl;
}

void PersonData::input() {
    cout << "~Please enter personal details~" << endl;
    cout << "First Name: "; getline(cin, firstName);
    cout << "Last Name: "; getline(cin, lastName);
    cout << "Address: "; getline(cin, address);
    cout << "City: "; getline(cin, city);
    cout << "State: "; getline(cin, state);
    cout << "Zip Code: "; getline(cin, zip);
    cout << "Phone #: "; getline(cin, phone);
}






class CustomerData : public PersonData {
protected:
    static int nextCustomerNumber;
    int customerNumber;
    bool mailingList;
public:
    CustomerData();
    CustomerData(bool mailList);
    int getCustomerNumber() const;
    bool getMailingList() const;
    void setMailingList(bool);
    void output() const;
    void input();
};

int CustomerData::nextCustomerNumber = 1;
CustomerData::CustomerData() {
    customerNumber = nextCustomerNumber++;
    mailingList = true;
}
CustomerData::CustomerData(bool mailList) {
    customerNumber = nextCustomerNumber++;
    mailingList = mailList;
}

int CustomerData::getCustomerNumber() const { return customerNumber; }
bool CustomerData::getMailingList() const { return mailingList; }
void CustomerData::setMailingList(bool a) { mailingList = a; }


void CustomerData::output() const {
    PersonData::output();
    cout << "~CUSTOMER DATA~" << endl << setw(20) << "\tID:" << customerNumber << endl;
    cout << setw(20) << "\tMailing List:" << (mailingList ? "Yes" : "No") << endl;
}


void CustomerData::input() {
    int yn;
    cout << "Do you want to be on the mainling list? (1 = yes, 2 = no) ";
    cin >> yn;
    while(yn != 1 and yn != 2) {
        cout << "Invalid. Please enter 1 for yes or 2 for no: ";
        cin >> yn;
    }
}





class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;
public:
    PreferredCustomer();
    PreferredCustomer(double);
    double getPurchasesAmount() const;
    double getDiscountLevel() const;
    void addPurchase(double);
    void updateDiscountLevel();
    void input();
    void output() const;
};

PreferredCustomer::PreferredCustomer() {
    purchasesAmount = 0;
    discountLevel = 0;
}

PreferredCustomer::PreferredCustomer(double a) {
    purchasesAmount = a;
    updateDiscountLevel();
}

double PreferredCustomer::getPurchasesAmount() const { return purchasesAmount; }

double PreferredCustomer::getDiscountLevel() const { return discountLevel; }

void PreferredCustomer::addPurchase(double amount) {
    if (amount < 0) {
        cout << "Invalid purchase amount!" << endl;
        return;
    }
    purchasesAmount += amount;
    updateDiscountLevel();
}

void PreferredCustomer::updateDiscountLevel() {
    if (purchasesAmount >= 2000) discountLevel = 0.10;
    else if (purchasesAmount >= 1500) discountLevel = 0.07;
    else if (purchasesAmount >= 1000) discountLevel = 0.06;
    else if (purchasesAmount >= 500) discountLevel = 0.05;
    else discountLevel = 0.0;
}

void PreferredCustomer::input() {
    double amount;
    cout << "Enter total historical purchases amount: ";
    cin >> amount;
    addPurchase(amount);
}

void PreferredCustomer::output() const {
    CustomerData::output();
    cout << "~DISCOUNT DATA~" << endl << setw(20) << "\tTotal Amount: $" << purchasesAmount << endl;
    cout << setw(20) << "\tDiscount:" << (discountLevel * 100) << "%" << endl;
}



int main() {
    PersonData person;
    person.input();
    person.output();

    CustomerData customer;
    customer.input();
    customer.output();

    PreferredCustomer preferred;
    preferred.input();
    preferred.output();

    double additionalPurchase;
    cout << "\nEnter an additional purchase amount to add: $";
    cin >> additionalPurchase;
    preferred.addPurchase(additionalPurchase);
    preferred.output();

    return 0;
}


