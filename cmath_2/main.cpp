
#include <iostream>
#include <string>
#include <cmath>
#include "cmath_2.h"

using namespace std;

int main(){
    
    Fraction f1(1,2), f2(10/9), f3(4);
    f4 = f1 - f2 * (f3/5);
    cout << f4.printAsMixed() << " equals " << f4.printAsDouble() << endl;
    
    ComplexNum n1(0,0), n2(1,-1);
    
    RomanNum r1(19), r2("XVII");
    
    int arr[10] = {1,2,5,8,3,6,7,9,4,10};
    Array a1(arr);
    a1.sort();
    a1.print();
    
    Combinatorics c1(7,5);
    c1.printAllPermutations;
    
    if(toDouble("9.812")==9.812)
        cout << true << endl;

    //A lot of random shit; check the header file for pages and pages of functions
    
}
 
