#include <iostream>
using namespace std;


void printValue(float value) {
    cout << value << endl;
    return;
}


int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    float var1, var2, result1, result2, result3, check;
    float gm1 = 2;
    float gm2 = 1;
    float gm3 = 5;

    cout << "This program calculates the proper bases for two rectangles given their heights." << endl;
    cout << "Height 1 (in cm): ";
    cin >> var1;
    cout << "Height 2 (in cm): ";
    cin >> var2;

    __asm {
        finit
        fld var1
        fld var2
        fld gm1
        fld gm2
        fld gm3

        fsqrt                       ;

        fstp check
        push check
        call printValue
        add esp, 4
        fld check

        fadd ST, ST(1)              ; Calculate Golden Ratio
        fdiv ST, ST(2)              ;

        fstp check
        push check
        call printValue
        add esp, 4
        fld check

        fstp result1
        fld result1
        fld ST
        fmul ST, ST(5)              ; Calculate base 1

        fstp check
        push check
        call printValue
        add esp, 4
        fld check

        fstp result2
        fmul ST, ST(3)              ; Calculate base 2
        fstp result3
    }
    cout.precision(5);
    cout << "The golden ratio is about 1:" << result1 << endl;
    cout.precision(2);
    cout << "The base for rectangle 1 should be " << result2 << " cm." << endl;
    cout << "The base for rectangle 2 should be " << result3 << " cm." << endl;
    return 0;
}