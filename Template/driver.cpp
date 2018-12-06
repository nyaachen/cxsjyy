#include <iostream>
#include <string>
#include "array.h"

using namespace std;

int main() {
    Array<double> arr(5);
    arr[0] = 24.63;
    arr[3] = 16.4;
    cout << arr[0] << " And " << arr[3] << endl;
    string ss[3] = {"hello", "NJU", "Programmer"};
    Array<string> sarr(ss, 3);
    for (size_t i=0; i < 3; ++i) {
        cout << ss[i] << ends;
    }
    return 0;
}
