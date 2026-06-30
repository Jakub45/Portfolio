#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <math.h>

using namespace std;

class MY_POINT {
private:
    double coord[3];
public:
    MY_POINT(double xx, double yy, double zz) { coord[0] = xx, coord[1] = yy, coord[2] = zz; }
    void disp() { cout << "x = " << coord[0] << " y = " << coord[1] << " z = " << coord[2] << endl; }

    double get_x();
    double get_y();
    double get_z();
};

double MY_POINT::get_x() {
    return coord[0];
}
double MY_POINT::get_y() {
    return coord[1];
}
double MY_POINT::get_z() {
    return coord[2];
}


class MY_LINE {
private:
    MY_POINT frst;
    MY_POINT sec;
public:
    MY_LINE(MY_POINT first, MY_POINT second) :  frst(first), sec(second) {}
    void disp_line(const char *str);
    double lenth_of_side();
};

void MY_LINE::disp_line(const char *str) {
    cout << str << endl;
    frst.disp();
    sec.disp();
}

double MY_LINE::lenth_of_side() {
    return sqrt(
        pow(frst.get_x() - sec.get_x(), 2) +
        pow(frst.get_y() - sec.get_y(), 2) +
        pow(frst.get_z() - sec.get_z(), 2)
    );
}

class MY_TRIANGLE {
private:
    MY_LINE line1;
    MY_LINE line2;
    MY_LINE line3;
public:
    MY_TRIANGLE(MY_LINE first, MY_LINE second, MY_LINE third) : line1(first), line2(second), line3(third)  {}
    void disp_triangle(const char* str);
    double surface_area();
};

void MY_TRIANGLE::disp_triangle(const char* str) {
    cout << str << endl;
    line1.disp_line("line ");
    line2.disp_line("line ");
    line3.disp_line("line ");
}

double MY_TRIANGLE::surface_area() {
    double a = line1.lenth_of_side();
    double b = line2.lenth_of_side();
    double c = line3.lenth_of_side();
    double p = (a + b + c) / 2;
    double P = sqrt(p * (p - a)* (p - b) * (p - c));
    return line1.lenth_of_side();

}


class MY_TETRAHEDRON {
private:
    MY_TRIANGLE ABC;
    MY_TRIANGLE ABD;
    MY_TRIANGLE BCD;
    MY_TRIANGLE ACD;
public:
    MY_TETRAHEDRON(MY_TRIANGLE first, MY_TRIANGLE second, MY_TRIANGLE third, MY_TRIANGLE fourth) : ABC(first), ABD(second), BCD(third), ACD(fourth) {}
    void disp_tetrahedron(const char* str);
};

void MY_TETRAHEDRON::disp_tetrahedron(const char* str) {
    cout << str << endl;
    ABC.disp_triangle("first ");
    ABD.disp_triangle("second ");
    BCD.disp_triangle("third ");
    ACD.disp_triangle("fourth ");
}

int main()
{

    MY_POINT A(0, 0, 0);
    MY_POINT B(2, 3, 4);
    MY_POINT C(5, 5, 5);
    MY_POINT D(8, 9, 7);

    MY_LINE AB(A, B);
    MY_LINE BC(B, C);
    MY_LINE AC(A, C);
    MY_LINE AD(A, D);
    MY_LINE BD(B, D);
    MY_LINE CD(C, D);
    //cout << AB.lenth_of_side();


    MY_TRIANGLE ABC(AB, BC, AC);
    MY_TRIANGLE ABD(AB, BD, AD);
    MY_TRIANGLE ACD(AC, CD, AD);
    MY_TRIANGLE BCD(BC, CD, BD);
    cout << BCD.surface_area();

    MY_TETRAHEDRON ABCD(ABC, ABD, ACD, BCD);
    ABCD.disp_tetrahedron("Tetrahedron :");
    

    system("pause");
    return 0;
}
