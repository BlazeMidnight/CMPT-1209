#include <iostream>
using namespace std;

class laptopData {
private:
    string manufacturer;
    string processor;
    double screenSize;
    string colour;
    bool isNew;
public:
    string getManufacturer() /*const*/;
    string getProcessor();
    double getScreenSize();
    string getColour();
    bool getIsNew();
    void setManufacturer(string);
    void setProcessor(string);
    void setScreenSize(double);
    void setColour(string);
    void setIsNew(bool);
    void input();
    void output();
    laptopData(); // defult constructor
    laptopData(string, string = "Defult", double = 17, string = "Clear", bool = false);
    // don't make first case defult case --> ambugous call to overloaded function
    // it makes it a defult constructor
};

laptopData::laptopData(string a, string b, double c, string d, bool e) {
    manufacturer = a;
    processor = b;
    screenSize = c;
    colour = d;
    isNew = e;
}

laptopData::laptopData() {
    manufacturer = "Asus";
    processor = "AMD Ryzen";
    screenSize = 16.5;
    colour = "Blue";
    isNew = true;
}

void laptopData::input() {
    cout << "Enter the manufacturer: ";
    getline(cin, manufacturer);
    cout << "Enter the processor: ";
    getline(cin, processor);
    cout << "Enter the screen size (in inches): ";
    cin >> screenSize;
    cin.ignore();
    cout << "Enter colour: ";
    getline(cin, colour);
    cout << "Is the laptop new? (1 for true, 0 for false): ";
    cin >> isNew;
    cin.ignore();
}

void laptopData::output() {
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Processor: " << processor << "\n";
    cout << "Screen Size: " << screenSize << " inches \n";
    cout << "Colour: " << colour << "\n";
    if(isNew==0) cout << "The laptop is not new \n";
    else cout << "The laptop is new! \n";
}

string laptopData::getManufacturer() {return manufacturer;}
string laptopData::getProcessor() {return processor;}
double laptopData::getScreenSize() {return screenSize;}
string laptopData::getColour() {return colour;}
bool laptopData::getIsNew() {return isNew;}
void laptopData::setManufacturer(string m) {manufacturer = m; }
void laptopData::setProcessor(string p) {processor = p; }
void laptopData::setScreenSize(double s) {screenSize = s; }
void laptopData::setColour(string c) {colour = c; }
void laptopData::setIsNew(bool n) {isNew = n; }

int main() {
    laptopData a, b("Dell", "Intel i5", 15.6, "Black", false);
    laptopData c("HP", "AMD", 17);
    
    cout << "\nLaptop 1\n";
    a.input();
    cout << "\nLaptop 2\n";
    b.input();
    cout << "\n============ \n";
    cout << "\nLaptop 1\n";
    a.output();
    cout << "\nLaptop 2\n";
    b.output();

    return 0;
}
