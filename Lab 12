#include <iostream>
#include <iomanip>
using namespace std;

class DivSales {
private:
    double quarterlySales[4];
    static double totalCorporateSales;

public:
    DivSales() {
        for (int i = 0; i < 4; i++) {
            quarterlySales[i] = 0.0;
        }
    }

    void setQuarterlySales(double q1, double q2, double q3, double q4) {
        if (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0) {
            cout << "Error: Quarterly sales figures must be positive." << endl;
            return;
        }
        quarterlySales[0] = q1;
        quarterlySales[1] = q2;
        quarterlySales[2] = q3;
        quarterlySales[3] = q4;
        totalCorporateSales += q1 + q2 + q3 + q4;
    }

    double getQuarterlySales(int quarter) const {
        if (quarter < 0 || quarter > 3) {
            cout << "Error: Quarter index must be between 0 and 3." << endl;
            return -1;
        }
        return quarterlySales[quarter];
    }

    static double getTotalCorporateSales() {
        return totalCorporateSales;
    }
};

double DivSales::totalCorporateSales = 0.0;

int main() {
    const int NUM_DIVISIONS = 6;
    DivSales divisions[NUM_DIVISIONS];

    for (int i = 0; i < NUM_DIVISIONS; i++) {
        cout << "Enter the sales for Division " << (i + 1) << " for four quarters:" << endl;
        double q1, q2, q3, q4;

        while (true) {
            cout << "Quarter 1: ";
            cin >> q1;
            cout << "Quarter 2: ";
            cin >> q2;
            cout << "Quarter 3: ";
            cin >> q3;
            cout << "Quarter 4: ";
            cin >> q4;

            if (q1 >= 0 && q2 >= 0 && q3 >= 0 && q4 >= 0) {
                divisions[i].setQuarterlySales(q1, q2, q3, q4);
                break;
            } else {
                cout << "Error: All sales figures must be positive. Please re-enter the values." << endl;
            }
        }
    }

    cout << "\nDivision Sales Table:\n";
    cout << setw(10) << "Division" << setw(12) << "Q1" << setw(12) << "Q2"
         << setw(12) << "Q3" << setw(12) << "Q4" << endl;

    for (int i = 0; i < NUM_DIVISIONS; i++) {
        cout << setw(10) << (i + 1);
        for (int q = 0; q < 4; q++) {
            cout << setw(12) << fixed << setprecision(2) << divisions[i].getQuarterlySales(q);
        }
        cout << endl;
    }

    cout << "\nTotal Corporate Sales for the Year: $"
         << fixed << setprecision(2) << DivSales::getTotalCorporateSales() << endl;

    return 0;
}
