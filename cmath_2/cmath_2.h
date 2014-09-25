//
//  cmath_2.h
//  cmath_2
//
//  Created by Rowan Ferrabee on 2014-03-25.
//  Copyright (c) 2014 Rowan Ferrabee. All rights reserved.
//

#ifndef __cmath_2__cmath_2__
#define __cmath_2__cmath_2__

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Fraction{
public:
    Fraction (int = 0, int = 1);
    Fraction (double a);
    Fraction operator+(Fraction);
    Fraction operator+(int);
    Fraction operator-(Fraction);
    Fraction operator-(int);
    Fraction operator*(Fraction);
    Fraction operator*(int);
    Fraction operator/(Fraction);
    Fraction operator/(int);
    Fraction operator^(Fraction);
    Fraction operator^(int);
    void operator=(double);
    bool operator==(Fraction);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    operator int();
    operator double();
    void simplify();
    double returnAsDouble();
    void printAsDouble();
    string returnAsFract();
    void printAsFract();
    void printAsMixed();
    int getNum();
    int getDenom();
private:
    int num;
    int denom;
};



class ComplexNum{
    
public:
    ComplexNum();
    ComplexNum(double, double = 0);
    ComplexNum(int, int = 0);
    ComplexNum(float, float = 0);
    
    ComplexNum(Fraction, Fraction);
    ComplexNum operator+ (ComplexNum);
    ComplexNum operator- (ComplexNum);
    ComplexNum operator* (double);
    ComplexNum operator* (ComplexNum);
    ComplexNum operator/ (double);
    ComplexNum operator/ (ComplexNum);
    ComplexNum operator^ (double);
    bool operator> (ComplexNum);
    bool operator< (ComplexNum);
    bool operator== (ComplexNum);
    friend istream& operator>>(istream&, ComplexNum&);
    friend ostream& operator<<(ostream&, const ComplexNum&);
    ComplexNum conjugate();
    void printSqrt();
    double getLength();
    double getAngle();
    void printCN();
    string returnCN();
    string returnCisCN();
    void printCisCN();
    void printRoots(int);
    void printRoots(Fraction);
    
    double Re;
    double Im;
    Fraction f_Re;
    Fraction f_Im;
    bool f_check;
    
private:
    double angle;
    double length;
};



class IntSet{
public:
    
    IntSet();
    IntSet(int);
    IntSet(int, int[]);
    void sort();
    int* passToArray();
    IntSet Union(IntSet);
    IntSet Intersect(IntSet);
    IntSet operator-(IntSet);
    int getLength();
    void setArray(int[]);
    void printSet();
    bool checkIfElement(int);
    void deleteElement(int);
    
private:
    int *arr;
    int l;
};



class Bool{
public:
    Bool();
    Bool(bool);
    Bool operator&&(Bool);
    Bool operator||(Bool);
    Bool operator!();
    
private:
    bool b;
};



class Array{
public:
    Array();
    Array(int);
    void setArray(int[]);
    void setArray();
    
    Array(int, int[]);
    
    bool checkIfValue(int);
    void sort();
    int* getArray();
    int checkValue(int);
    int getLength();
    void deleteElement(int);
    void deleteValue(int);
    void printArray();
    void addElement(int, int);
    Array operator+(Array);
    
private:
    int *arr;
    int l;
};



class Combinatorics{
public:
    Combinatorics();
    Combinatorics(int,int = -1234);
    void setElements();
    void setCombination();
    void nextCombination();
    void printCombination();
    Combinatorics getCombination();
    Combinatorics getPermutation();
    Combinatorics getElements();
    void setPermutation();
    void printPermutation();
    void nextPermutation();
    void printCombinations();
    void printPermutations();
    void printAll();
private:
    int n;
    int k;
    int *arr;
    int *perm;
    string *elements;
};



class RomanNum{
public:
    RomanNum();
    RomanNum(string);
    void setInt();
    void setRoman();
    friend ostream &operator<<(ostream &, RomanNum &);
    friend istream &operator>>(istream &, RomanNum &);
    RomanNum operator+(RomanNum);
    RomanNum operator-(RomanNum);
    RomanNum operator*(RomanNum);
    RomanNum operator/(RomanNum);
    RomanNum operator%(RomanNum);
    bool operator>(RomanNum);
    bool operator<(RomanNum);
    bool operator==(RomanNum);
    void printNum();
    string returnNum();
    
private:
    string roman;
    int num;
};





int factorial(int);
int GCD(int,int);
int LCM(int,int);
int C(int,int);
int P(int,int);
int getPascal(int,int);
void printTriangle(int);
ComplexNum pow(ComplexNum, int);
int to_int(string);
int to_int(char);
int to_int(double);
double to_double(string);



#endif /* defined(__cmath_2__cmath_2__) */
