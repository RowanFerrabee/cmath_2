//
//  cmath_2.cpp
//  cmath_2
//
//  Created by Rowan Ferrabee on 2014-03-25.
//  Copyright (c) 2014 Rowan Ferrabee. All rights reserved.
//

#include "cmath_2.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int to_int(char a){
    if(a == '1')return 1;
    else if(a == '2')return 2;
    else if(a == '3')return 3;
    else if(a == '4')return 4;
    else if(a == '5')return 5;
    else if(a == '6')return 6;
    else if(a == '7')return 7;
    else if(a == '8')return 8;
    else if(a == '9')return 9;
    else return 0;
}

int to_int(double a){

    return (int)a;}

int to_int(string s1){

    int counter = 0;
    if(s1.find('.')<s1.length()){
        s1 = s1.substr(0,s1.find('.'));
    }

    if(s1==""){s1 = "0";}
    
    for(int x=0; x<s1.length(); x++){
    
        counter += pow(10,(s1.length()-1)-x)*to_int(s1[x]);
    
    }

    return counter;
}

double to_double(string s1){

    int p = s1.find('.');
    
    if(p<s1.length()){
        string s2 = "";
        string s3 = " ";
        for(int x=0; x<s1.length(); x++){
            if(s1[x]!='.'){
                s3[0]=s1[x];
                s2+=s3;
            }
        }
        double a = (double)to_int(s2);
        a/=pow(10, s1.length()-p-1);
        return a;
    }
    else{return (double)to_int(s1);}
    
}

int factorial(int a){

    int product = 1;
    for(int x=1; x<=a; x++){
        product*=x;
    }

return product;}

int GCD(int a, int b){

    int g=1;
    
    for(int x=1; x<=a; x++){
        if(a%x==0&&b%x==0){
            g=x;}}
    
    return g;}

int LCM(int a, int b){

    int l = a*b/GCD(a,b);
    return l;
}

int C(int a, int b){
    double c = (double)factorial(a)/((double)factorial(b)*(double)factorial(a-b));
    
    int d = (int)c;
    
    return d;
}

int P(int a, int b){
    double c = ((double)factorial(a))/((double)factorial(a-b));
    
    int d = (int) c;
    
    return d;}

int getPascal(int row,int col){
    
    if(row<0||col<0){return 0;}
    else if(row==0&&col==0){return 1;}
    else{return (getPascal(row-1, col-1)+getPascal(row-1, col));}
    
}

void printTriangle(int row){
    
    for(int x=0; x<=row; x++){
        for(int y=0; y<=x; y++){
            cout<<getPascal(x, y)<<",";
        }cout<<endl;
    }
    
}















ComplexNum pow(ComplexNum c, int n){

    ComplexNum c2 = c^n;

    return c2;}

ComplexNum::ComplexNum(){}

ComplexNum::ComplexNum(double a, double b){
    Re=a;
    Im=b;
    f_Re = a;
    f_Im = b;
    f_check = false;
}

ComplexNum::ComplexNum(int a, int b){
    Re=(double)a;
    Im=(double)b;
    f_Re = a;
    f_Im = b;
    f_check = false;
}

ComplexNum::ComplexNum(float a, float b){
         Re = (double)a;
         Im = (double)b;
       f_Re = (double)a;
       f_Im = (double)b;
    f_check = false;
}

ComplexNum::ComplexNum(Fraction a,Fraction b){
    
      Re = a.returnAsDouble();
      Im = b.returnAsDouble();
    f_Re = a;
    f_Im = b;
    f_check = true;
    
}

ComplexNum ComplexNum::operator+(ComplexNum c1){
    ComplexNum c2;
    c2.Re = Re + c1.Re;
    c2.Im = Im + c1.Im;
    c2.f_Re = f_Re + c1.f_Re;
    c2.f_Im = f_Im + c1.f_Im;
    return c2;
}

ComplexNum ComplexNum::operator-(ComplexNum c1){
    ComplexNum c2;
    c2.Re = Re - c1.Re;
    c2.Im = Im - c1.Im;
    c2.f_Re = f_Re - c1.f_Re;
    c2.f_Im = f_Im - c1.f_Im;
    return c2;
}

ComplexNum ComplexNum::operator*(ComplexNum c1){
    ComplexNum c2;
    c2.Re = (c1.Re)*Re - (c1.Im)*Im;
    c2.Im = (c1.Im)*Re + (c1.Re)*Im;
    c2.f_Re = (c1.f_Re)*f_Re - (c1.f_Im)*f_Im;
    c2.f_Im = (c1.f_Im)*f_Re + (c1.f_Re)*f_Im;
    return c2;
}

ComplexNum ComplexNum::operator*(double a){
    ComplexNum c;
    c.Re = a*Re;
    c.Im = a*Im;
    c.f_Re = (Fraction)a*f_Re;
    c.f_Im = (Fraction)a*f_Im;
    return c;
}

ComplexNum ComplexNum::operator/ (double a){
    ComplexNum c;
    c.Re = Re/a;
    c.Im = Im/a;
    c.f_Re = f_Re/(Fraction)a;
    c.f_Im = f_Im/(Fraction)a;
    return c;}

ComplexNum ComplexNum::operator/ (ComplexNum c1){
    ComplexNum c2;
    c2.Re = (Re*(c1.Re)+Im*(c1.Im))/((c1.Re)*(c1.Re)+(c1.Im)*(c1.Im));
    c2.Im = (Im*(c1.Re)-Re*(c1.Im))/((c1.Re)*(c1.Re)+(c1.Im)*(c1.Im));
    c2.f_Re = (f_Re*(c1.f_Re)+f_Im*(c1.f_Im))/((c1.f_Re)*(c1.f_Re)+(c1.f_Im)*(c1.f_Im));
    c2.f_Im = (f_Im*(c1.f_Re)-f_Re*(c1.f_Im))/((c1.f_Re)*(c1.f_Re)+(c1.f_Im)*(c1.f_Im));
    return c2;}

ComplexNum ComplexNum::operator^ (double a){
    ComplexNum c;
    if(a==0){c.Re=1;c.f_Re=1;c.Im=0;c.f_Im=0;return c;}
    else{
        c.Re = Re;
        c.Im = Im;
        c.f_Re = f_Re;
        c.f_Im = f_Im;
        for(int x=0; x<(int)a-1; x++){
            c.Re = c.Re*Re-c.Im*Im;
            c.Im = c.Re*Im+Re*c.Im;
            c.f_Re = c.f_Re*f_Re-c.f_Im*f_Im;
            c.f_Im = c.f_Re*f_Im+f_Re*c.f_Im;}
        return c;}
    
}

ostream& operator<<(ostream& os, const ComplexNum& c)
{
    if(c.f_check){
        cout<< c.f_Re << " + " << c.f_Im << "*i" ;}
    else{
        cout << c.Re << " + " << c.Im << "*i" ;}
	
	return os;
}

istream& operator>>(istream& is, ComplexNum& c)
{
    
    double a;
    cin>>a;
    double b;
    cin>>b;
    c.Re = a;
    c.Im = b;

	return is;
    
}

bool ComplexNum::operator<(ComplexNum c){

    if(sqrt(Re*Re+Im*Im)<sqrt(c.Re*c.Re+c.Im*c.Im)){
        return true;
    }
    else return false;

}

bool ComplexNum::operator>(ComplexNum c){
    
    if(sqrt(Re*Re+Im*Im)>sqrt(c.Re*c.Re+c.Im*c.Im)){
        return true;
    }
    else return false;
    
}

bool ComplexNum::operator==(ComplexNum c){
    
    if(Re == c.Re && Im == c.Im)
        return true;
    
    else return false;
    
}

double ComplexNum::getLength(){
    double length = sqrt(Re*Re+Im*Im);
    return length;
}

double ComplexNum::getAngle(){
    double angle;
    if(Im==0&&Re==0){angle = 0;}
    else if(Im>0&&Re==0){angle = 3.14159265/2;}
    else if(Im<0&&Re==0){angle = 3*3.14159265/2;}
    else {angle = atan(Im/Re);}
    return angle;
}

void ComplexNum::printCN(){
    cout<<returnCN()<<endl;}

void ComplexNum::printCisCN(){
    cout<<returnCisCN()<<endl;}

string ComplexNum::returnCN(){
    if(f_check){
        string s1 = "";
            s1+=f_Re.returnAsFract();
            s1+=" + ";
            s1+=f_Im.returnAsFract();
            s1+="*i ";
        return s1;}
    else{
        string s1 = "";
        int check = Re;
        double check2 = check;
        if(check2==Re){
            s1+=to_string((int)Re);
            s1+=" + ";}
        else{
            s1+=to_string(Re);
            s1+=" + ";}
        check = Im;
        check2 = check;
        if(check2==Im){
            s1+=to_string((int)Im);
            s1+="*i ";}
        else{
            s1+=to_string(Im);
            s1+="*i ";}
        return s1;}
}

string ComplexNum::returnCisCN(){
    string s1 = "";
    int check = getLength();
    double check2 = check;
    if(check2==getLength()){
        s1+=to_string((int)getLength());}
    else{s1+=to_string(getLength());}
    s1+="[cos(";
    check = getAngle();
    check2 = check;
    if(check2==getAngle()){
        s1+=to_string((int)getAngle());
        s1+=") + i*sin(";
        s1+=to_string(getAngle());
        s1+=")]";}
    else{
        s1+=to_string(getAngle());
        s1+=") + i*sin(";
        s1+=to_string(getAngle());
        s1+=")]";}
    
    return s1;}

ComplexNum ComplexNum::conjugate(){
    ComplexNum c;
    c.Re = Re;
    c.Im = -1*Im;
    c.f_Re = f_Re;
    Fraction f(-1,1);
    c.f_Im = f*f_Im;
    return c;
}

ComplexNum conjugate(ComplexNum c){
    ComplexNum c2;
    c2.Re=c.Re;
    c2.Im=-1*c.Im;
    c2.f_Re = c.f_Re;
    Fraction f(-1,1);
    c2.f_Im = f*c.f_Im;
    return c2;}

void ComplexNum::printSqrt(){
    double r = getLength();
    r = sqrt(r);
    double a = getAngle();
    double temp = a + 2*3.14159265;
    ComplexNum c;
    a = a/2;
    c.Re = r*cos(a);
    c.Im = r*sin(a);
    cout<<"\n\t--> "<<c.returnCN()<<endl;
    a = temp/2;
    c.Re = r*cos(a);
    c.Im = r*sin(a);
    cout<<"\t--> "<<c.returnCN()<<endl;
}

void ComplexNum::printRoots(int n){
    
    ComplexNum c;
    double r = getLength();
    r = pow(r, 1/(double)n);
    double a = getAngle();
    double temp;
    
    cout<<"\n";
    for(int x=0; x<n; x++){
        temp = a/n;
        c.Re = r*cos(temp);
        c.Im = r*sin(temp);
        cout<<"\t--> "<<c.returnCN()<<endl;
        
        a = a + 2*3.14159265;
    }
    
}

void ComplexNum::printRoots(Fraction f){
    
    ComplexNum c;
    double r = getLength();
    r = pow(r, 1/(double)f.getDenom());
    double a = getAngle();
    double temp;
    
    for(int x=0; x<f.getDenom(); x++){
        temp = a/f.getDenom();
        c.Re = r*cos(temp);
        c.Im = r*sin(temp);
        
        c = c^(double)f.getNum();
        
        cout<<"\t--> "<<c.returnCN()<<endl;
        
        a = a + 2*3.14159265;
    }
    
}

void printSqrt(ComplexNum c){
    ComplexNum c2;
    double r = c.getLength();
    r = sqrt(r);
    double a = c.getAngle();
    double temp = a + 2*3.14159265;
    a = a/2;
    c2.Re = r*cos(a);
    c2.Im = r*sin(a);
    cout<<"\n\t--> "<<c2.returnCN()<<endl;
    a = temp/2;
    c2.Re = r*cos(a);
    c2.Im = r*sin(a);
    cout<<"\t--> "<<c2.returnCN()<<endl;
}
























Fraction::Fraction (int a, int b){
    num = a;
    denom = b;}

Fraction::Fraction (double a){

    double n;
    int n_int;
    
    bool first = true;
    
    for(int x=1; x<100000; x++){
        n = a*x;
        n_int = a*x;
        if(n==(double)n_int&&first){
            first = false;
            num = n;
            denom = x;}
    }
    
    simplify();
    
}

Fraction Fraction::operator+(Fraction f){
    
    Fraction f2;
    
    f2.num = f.denom*num + f.num*denom;
    f2.denom = denom*f.denom;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator+(int a){
    
    Fraction f2;
    
    f2.num = num + a*denom;
    f2.denom = denom;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator-(Fraction f){
    
    Fraction f2;
    
    f2.num = f.denom*num - f.num*denom;
    f2.denom = denom*f.denom;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator-(int a){
    
    Fraction f2;
    
    f2.num = num - a*denom;
    f2.denom = denom;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator*(Fraction f){
    
    Fraction f2;
    
    f2.num = f.num*num;
    f2.denom = denom*f.denom;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator*(int a){
    
    Fraction f;
    
    f.num = num*a;
    f.denom = denom;
    
    f.simplify();
    
    return f;}

Fraction Fraction::operator/(Fraction f){
    
    Fraction f2;
    
    f2.num = f.num*denom;
    f2.denom = denom*f.num;
    
    f2.simplify();
    
    return f2;}

Fraction Fraction::operator/(int a){
    
    Fraction f;
    f.num = num;
    f.denom = denom*a;
    
    f.simplify();
    
    return f;}

Fraction Fraction::operator^(int a){
    Fraction f;
    f.num = num^a;
    f.denom = denom^a;
    
    f.simplify();
    
    return f;}

bool Fraction::operator==(Fraction f){
    bool check = false;
    
    simplify();
    f.simplify();
    
    if(num==f.num&&denom==f.denom){
        check = true;}
    
    return check;
}

void Fraction::operator=(double a){

    Fraction f(a);
    
    num = f.num;
    denom = f.denom;


}

ostream& operator<<(ostream& os, const Fraction& f)
{
	cout << "(" << f.num << "/" << f.denom << ")" ;
	
	return os;
}

void Fraction::simplify(){
    
    int greatest = num;
    if (denom>num) greatest = denom;
    
    for(int x=2; x<=greatest; x++){
        if(num%x==0&&denom%x==0){
            num = num/x;
            denom = denom/x;
            x--;}
    }
    
}

double Fraction::returnAsDouble(){
    double a = (double)num/(double)denom;
    return a;}

string Fraction::returnAsFract(){

    string f="(";
    f += to_string(num);
    f += "/";
    f += to_string(denom);
    f += ")";

    return f;}

void Fraction::printAsDouble(){
    double a = num/denom;
    cout<<a<<endl;}

void Fraction::printAsFract(){
    cout<<"("<<num<<"/"<<denom<<")"<<endl;}

void Fraction::printAsMixed(){
    
    int q = num/denom;
    int r = num%denom;
    
    cout<<q<<"+("<<r<<"/"<<denom<<")"<<endl;
    
}

Fraction::operator int(){

    return num/denom;

}

Fraction::operator double(){

    return (double)num/(double)denom;
    
}

int Fraction::getNum(){
    return num;}

int Fraction::getDenom(){
    return denom;}





















Bool::Bool(){
}

Bool::Bool(bool b1){
    b = b1;
}

Bool Bool::operator&&(Bool b1){
    Bool b2;
    if(b==true&&b1.b==true){b2.b=true;}
    else{b2.b=false;}
    return b2;}

Bool Bool::operator!(){
    Bool b1;
    if(b==true){b1.b=false;}
    else{b1.b=true;}
    return b1;}

Bool Bool::operator||(Bool b1){
    Bool b2;
    if(b||b1.b){b2.b=true;}
    else{b2.b=false;}
    return b2;}
















IntSet::IntSet(){}

IntSet::IntSet(int length){

    arr = new int [length];
    l = length;

}

IntSet::IntSet(int length, int arr1[]){

    arr = new int [length];
    l = length;
    
    for(int x=0; x<l; x++){
        arr[x] = arr1[x];}
    
    sort();

}

void IntSet::sort(){

    int counter = 0, temp;
    
    for(int x=0; x<l; x++){
        for(int y=0; y<l-1; y++){
            if(arr[y]>arr[y+1]){
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;}}}
    
    bool check;
    
    for(int x=0; x<l-1; x++){
        check = true;
        for(int y=x+1; y<l; y++){
            if(arr[y]==arr[x]&&check){
                counter++;
                check = false;}
        }
    }
    
    int *arr2;
    arr2 = new int [l-counter];
    
    int c = 0;
    
    arr2[0]=arr[0];
    for(int x=1; x<l; x++){
        if(arr[x]!=arr[x-1]){
            c++;
            arr2[c]=arr[x];
        }
    }
    
    l = l-counter;
    arr = new int [l];
    arr = arr2;
    
}

void IntSet::setArray(int arr1[]){

    for(int x=0; x<l; x++){
        arr[x]=arr1[x];}
    
    sort();

}

IntSet IntSet::Union(IntSet I){

    IntSet I2(l+I.l);
    
    for(int x=0; x<l; x++){
        I2.arr[x]=arr[x];
    }
    for(int x=l; x<l+I.l; x++){
        I2.arr[x]=I.arr[x-l];
    }

    I2.sort();
    
    return I2;}

IntSet IntSet::Intersect(IntSet I){

    sort();
    I.sort();
    
    int counter = 0;
    for(int x=0; x<l; x++){
            if(I.checkIfElement(arr[x]))
                counter++;
    }
    
    IntSet I2(counter);
    
    int c = 0;
    for(int x=0; x<l; x++){
        if(I.checkIfElement(arr[x])){
            I2.arr[c]=arr[x];
            c++;}
            
    }
    

    return I2;}

IntSet IntSet::operator-(IntSet I){

    IntSet I2(l);
    I2.arr = arr;
    
    for(int x=0; x<I.l; x++){
        I2.deleteElement(I.arr[x]);
        I2.printSet();}
    
    return I2;}

void IntSet::deleteElement(int a){
    
    if(checkIfElement(a)){
    int *arr1;
    
    arr1 = new int [l];
    
    arr1 = arr;
    
    l--;
    arr = new int [l];
    
    int c = 0;
    for(int x=0; x<l; x++){
        if(arr1[x]!=a){
            arr[c]=arr1[x];
            c++;}
    }}
    else{}

}

bool IntSet::checkIfElement(int a){

    bool check = false;
    for(int x=0; x<l; x++){
        if(a==arr[x])
            check = true;
    }

    return check;}

void IntSet::printSet(){

    cout<<"{";
    for(int x=0; x<l; x++){
        cout<<arr[x];
        if(x!=l-1)
            cout<<",";}
    cout<<"}"<<endl;
}

int* IntSet::passToArray(){

    int *pointer;
    
    pointer = new int [l];
    
    pointer = arr;
    
    return pointer;

}























Array::Array(){
    int arr1[0] = {};
    arr = arr1;
    l = 0;}

Array::Array(int length){
    l = length;
    arr = new int [l];}

void Array::setArray(int arr1[]){
    
    arr = new int [l];
    
    for(int x=0; x<l; x++){
        arr[x] = arr1[x];
    }
    
}

void Array::setArray(){

    for(int x=0; x<l; x++){
    
        cin>>arr[x];
    
    }

}

Array::Array(int length, int arr1[]){
    
    l = length;
    arr = new int [l];
    
    for(int x=0; x<l; x++){
        arr[x] = arr1[x];}
    
}


void Array::sort(){
int temp;

for(int x=0; x<l; x++){
    for(int y=0; y<l-1; y++){
        if(arr[y]>arr[y+1]){
            temp = arr[y];
            arr[y] = arr[y+1];
            arr[y+1] = temp;}}}
    
}

int* Array::getArray(){

    int *pointer;
    
    pointer = new int [l];
    
    pointer = arr;

    return pointer;}

bool Array::checkIfValue(int a){
    bool check = false;
    
    for(int x=0; x<l; x++){
        if(arr[x] == a){check = true;}
    }
    
    return check;}

int Array::checkValue(int a){
    int check = 0;
    
    for(int x=0; x<l; x++){
        if(arr[x] == a){check++;}
    }
    
    return check;}

int Array::getLength(){return l;}

void Array::deleteElement(int a){
    
    int *arr1;
    arr1 = new int [l-1];
    
    int counter = 0;
    for(int x=0; x<l; x++){
        if(x!=a){
            arr1[counter]=arr[x];
            counter++;}
    }
    
    l = l-1;
    
    arr = new int [l];
    
    arr = arr1;
    
}

void Array::deleteValue(int a){
    
    for(int x=0; x<l; x++){
        if(arr[x]==a){
            deleteElement(x);}
    }
    
}

void Array::printArray(){
    
    for(int x=0; x<l; x++){
        cout<<arr[x];
        if(x!=l-1)
            cout<<",";}
    cout<<endl;
    
}

void Array::addElement(int pos, int value){
    
    int *arr1;
    arr1 = new int [l+1];
    
    int counter = 0;
    for(int x=0; x<l; x++){
        if(x == pos){
            arr1[counter] = value;
            counter++;}
        arr1[counter] = arr[x];
        counter++;
    }
    
    l = l+1;
    
    arr = new int [l];
    
    arr = arr1;
    
}

Array Array::operator+(Array a1){
    Array a2;
    
    a2.l=l+a1.l;
    
    a2.arr = new int [a2.l];
    
    for(int x=0; x<l; x++){
        a2.arr[x]=arr[x];
    }
    for(int x=l; x<l+a1.l; x++){
        a2.arr[x]=a1.arr[x-l];
    }
    
    return a2;
}





















Combinatorics::Combinatorics(){}

Combinatorics::Combinatorics(int l, int c){
    
    arr = new int [l];
    elements = new string [l];
    perm = new int [l];
    
    n = l;
    
    if(c==-1234){k=l;}
    else{k = c;}
    
}

void Combinatorics::setCombination(){
    for(int x=0; x<n; x++){
        if(x<k){arr[x]=1;}
        else{arr[x]=0;}
    }
}

void Combinatorics::setPermutation(){
    
    int counter = 1;
    for(int x=0; x<n; x++){
        if(counter<=k){
            perm[x]=counter;
            counter++;}
        else{perm[x]=0;}
    }
    
}

void Combinatorics::setElements(){
    
    for(int x=0; x<n; x++){
        cin>>elements[x];
    }
    
    setCombination();
    setPermutation();
    
}

void Combinatorics::nextCombination(){
    
    bool check1;
    int counter;
    
    int *temp;
    temp = new int [n];
    
    check1=true;
    for(int y=n-2; y>=0; y--){
        
        if(arr[y]==1&&arr[y+1]==0&&check1){
            counter = k;
            
            for(int z=0; z<y; z++){
                if(arr[z]==1){
                    temp[z]=arr[z];
                    counter--;}
                else{temp[z]=arr[z];}
            }
            
            arr[y]=0;
            
            for(int z=y+1; z<n; z++){
                if(counter>0){
                    temp[z]=1;
                    counter--;}
                else{temp[z]=0;}
            }
            check1 = false;
        }
        
    }
    arr = temp;
    
}

void Combinatorics::printCombination(){
    
    for(int x=0; x<n; x++){
        if(arr[x]==1)
            cout<<elements[x]<<",";}cout<<endl;
    
}

void Combinatorics::printPermutation(){
    
    int counter = 1;
    for(int x=0; x<k; x++){
        for(int y=0; y<n; y++){
            if(perm[y]==counter)
                cout<<elements[y]<<",";
        }counter++;
        
    }cout<<endl;
    
}

void Combinatorics::nextPermutation(){
    
    bool check1;
    int counter;
    bool check2;
    int zero;
    
    int *temp;
    temp = new int [n];
    
    check1=true;
    for(int y = k; y >= 1; y--){
        
        for(int x=0; x<n; x++){
            if(perm[x]==y&&check1){
                
                check2 = false;
                for(int z=x+1; z<n; z++){ //find next zero
                    if(perm[z]>perm[x]&&check2==false){
                        check2=true;
                        zero=z;}
                }
                
                if(check2){ // if there has been no move, and there is a next zero
                    
                    temp[x]=0;                  // switch variable with next zero
                    counter = y+1;
                    for(int w=0; w<n; w++){temp[w]=0;}
                    temp[zero]=y;
                    for(int w=0; w<n; w++){     // fill in the rest of the array
                        if(perm[w]!=0&&perm[w]<y)
                            temp[w]=perm[w];}
                    for(int w=0; w<n; w++){
                        if(temp[w]==0&&counter<=k){
                            temp[w]=counter;
                            counter++;}
                    }
                    check1=false;
                    perm = temp;
                }
                
            }
        }
    }
    
}

Combinatorics Combinatorics::getCombination(){
    
    Combinatorics p(k);
    
    int counter = 0;
    for(int x=0; x<n; x++){
        if(arr[x]==1){
            p.elements[counter]=elements[x];
            counter++;
        }
    }
    
    p.setPermutation();
    p.setCombination();
    
    return p;
}

Combinatorics Combinatorics::getPermutation(){
    
    Combinatorics p(k);
    
    for(int x=0; x<k; x++){
        for(int y=0; y<n; y++){
            if(perm[y]==x+1){p.elements[x]=elements[y];}
        }
    }
    
    p.setPermutation();
    p.setCombination();
    
    return p;}

Combinatorics Combinatorics::getElements(){
    
    Combinatorics p(n);
    
    for(int x=0; x<n; x++){
        p.elements[x]=elements[x];
    }
    
    p.setCombination();
    p.setPermutation();
    
    return p;}

void Combinatorics::printCombinations(){
    
    for(int x=0; x<C(n,k); x++){
        printCombination();
        nextCombination();
    }
    
}

void Combinatorics::printPermutations(){
    
    Combinatorics p;
    
    p = getCombination();
    
    for(int x=0; x<P(p.n,p.k); x++){
        p.printPermutation();
        p.nextPermutation();
    }
    
}

void Combinatorics::printAll(){
    
    Combinatorics p2;
    for(int x=0; x<C(n,k); x++){
        
        printCombination();
        
        p2 = getCombination();
        for(int y=1; y<P(k,k); y++){
            
            p2.nextPermutation();
            p2.printPermutation();
            
        }
        
        nextCombination();
        
    }
    
}















RomanNum::RomanNum(){
    roman = "";
    num = 0;
}

RomanNum::RomanNum(string r){
    roman = r;
    setInt();}

ostream &operator<<(ostream &output, RomanNum &i){
    
    cout<<i.roman;
    return output;

}

istream &operator>>(istream &input, RomanNum &i){

    cin>>i.roman;
    i.setInt();
    return input;
    
}

RomanNum RomanNum::operator+(RomanNum r){
    RomanNum r2;
    r2.num = num + r.num;
    
    r2.setRoman();
    
    return r2;
}

RomanNum RomanNum::operator-(RomanNum r){
    RomanNum r2;
    r2.num = num - r.num;
    
    r2.setRoman();
    
    return r2;
}

RomanNum RomanNum::operator*(RomanNum r){
    RomanNum r2;
    r2.num = num * r.num;
    
    r2.setRoman();
    
    return r2;
}

RomanNum RomanNum::operator/(RomanNum r){
    RomanNum r2;
    r2.num = num / r.num;
    
    r2.setRoman();
    
    return r2;
}

RomanNum RomanNum::operator%(RomanNum r){
    RomanNum r2;
    r2.num = num % r.num;
    
    r2.setRoman();
    
    return r2;
}

void RomanNum::setRoman(){
    
    int n = num;
    if(num>1000||num<=0)
        roman = "CONCORDIA CUM VERITATE";
    else{
        roman = "";
        while(n>0){
            
            if(n>=1000){
                roman+="M";
                n-=1000;}
            else if(n>=900){
                roman+="CM";
                n-=900;}
            else if(n>=500){
                roman+="D";
                n-=500;}
            else if(n>=400){
                roman+="CD";
                n-=400;}
            else if(n>=100){
                roman+="C";
                n-=100;}
            else if(n>=90){
                roman+="XC";
                n-=90;}
            else if(n>=50){
                roman+="L";
                n-=50;}
            else if(n>=40){
                roman+="XL";
                n-=40;}
            else if(n>=10){
                roman+="X";
                n-=10;}
            else if(n>=9){
                roman+="IX";
                n-=9;}
            else if(n>=5){
                roman+="V";
                n-=5;}
            else if(n>=4){
                roman+="IV";
                n-=4;}
            else if(n>=1){
                roman+="I";
                n-=1;}
            
        }
        
    }
    
}

bool RomanNum::operator>(RomanNum i){

    if(num>i.num)
        return true;
    else
        return false;
    
}

bool RomanNum::operator<(RomanNum i){

    if(num<i.num)
        return true;
    else
        return false;

}

bool RomanNum::operator==(RomanNum i){

    if(num<i.num)
        return true;
    else
        return false;
    
}

void RomanNum::setInt(){
    long int l = roman.length();
    int n = 0;
    for(int x=0; x<l; x++){
        if(roman[x]=='I'){
            if(roman[x+1]=='V'){
                x++;
                n+=4;
            }
            else if(roman[x+1]=='X'){
                x++;
                n+=9;}
            else{
                n+=1;}}
        else if(roman[x]=='V'){
            n+=5;}
        else if(roman[x]=='X'){
            if(roman[x+1]=='L'){
                x++;
                n+=40;}
            else if(roman[x+1]=='C'){
                x++;
                n+=90;}
            else{
                n+=10;}}
        else if(roman[x]=='L'){
            n+=50;}
        else if(roman[x]=='C'){
            if(roman[x+1]=='D'){
                x++;
                n+=400;}
            else if(roman[x+1]=='M'){
                x++;
                n+=900;}
            else{
                n+=100;}}
        else if(roman[x]=='D'){
            n+=500;}
        else if(roman[x]=='M'){
            n+=1000;}
        num = n;
    }
    
}

void RomanNum::printNum(){
    cout<<roman<<endl;
}

string RomanNum::returnNum(){
    return roman;
}



