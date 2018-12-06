#include "IntSet.h"

#include <iostream>

using namespace std;

int main() {
    IntSet a{5,4,3,2,1}, b{7,6,5,4,3}, c{1,2,7};
    c.insert(4);
    b.remove(3);
    cout << "A: " << a << "\nB: " << b << "\nC: "<< c << endl;
    cout << "A+B: " << a+b << "\nA-B: " << a-b << "\nA+B: " << a+b << endl;
    cout << "A<=B: " << (a<=b) << "\nA<=B+C: " << (a<=b+c) << "\nc<=A+B: " << (c<=a+b) << endl;;
    return 0;
}
