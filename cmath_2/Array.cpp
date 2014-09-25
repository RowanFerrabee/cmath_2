//
//  Array.cpp
//  cmath_2
//
//  Created by Rowan Ferrabee on 2014-03-31.
//  Copyright (c) 2014 Rowan Ferrabee. All rights reserved.
//

#include "Array.h"
#include <iostream>

using namespace std;

Array(){}

Array(int length){
    l = length;}

void setArray(int arr1[]){
    arr = new int [l];
    
    for(int x=0; x<l; x++){
        arr[x]=arr1[x];}}

Array(int,int[]);

void sort();
int getLength();
int checkValue(int);
void deleteElement(int);
void deleteValue(int);
void printSet();