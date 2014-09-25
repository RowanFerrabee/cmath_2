//
//  Array.h
//  cmath_2
//
//  Created by Rowan Ferrabee on 2014-03-31.
//  Copyright (c) 2014 Rowan Ferrabee. All rights reserved.
//

#ifndef __cmath_2__Array__
#define __cmath_2__Array__

#include <iostream>

using namespace std;

class Array{
    
public:
    Array();
    Array(int);
    void setArray(int[]);
    
    Array(int,int[]);
    
    void sort();
    int getLength();
    int checkValue(int);
    void deleteElement(int);
    void deleteValue(int);
    void printSet();
    
private:
    int *arr;
    int l;

};

#endif /* defined(__cmath_2__Array__) */
