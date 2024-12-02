#include <iostream>
using namespace std;

template <typename T> 
T total(T arr[], int size) {
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    int intArr[] = {1, 2, 3, 4};
    double doubleArr[] = {1.1, 2.1, 3.2, 4.03};
    
    cout << total(intArr, 4) << endl;
    cout << total(doubleArr, 4) << endl;

    return 0;
}
