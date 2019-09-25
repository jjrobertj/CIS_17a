/* 
 * File:   main.cpp
 * Author: Jabonillo, Jrrobert
 * Created on September 23, 2019, 11:56 PM
 * Purpose:  Write a function that accepts an int array and array size as arguments
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *allocate(int size);
void fillarray(int *array, int size);
void print(int *array, int size);
int *reversearray(int *array, int size);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *array;
    int size = 20;
    
    //Process/Calculations Here
    array = allocate(size);
    
    fillarray(array, size);
    
    //Create another array with elements reversed
    int *reverse = reversearray(array, size);
    
    //Reversing the original array
    //delete []array;
    //array = reverse;
    
    //Output Located Here
    cout<<"Original Array: "<<endl;
    print(array, size);
    cout<<"Reverse Array: "<<endl;
    print(reverse, size);
    
    //Clear memory
    delete []array;
    delete []reverse;
    
    //Exit
    return 0;
}

int *allocate(int size){
    int *p = new int [size];
    return p;
    
}

void fillarray(int *array, int size){
    for(int i = 0; i < size; i++){
        array[i] = i;
    }
}

void print(int *array, int size){
//    for(int i = 0; i < size; i++){
//        cout<<array[i]<<" ";
//    }
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int *reversearray(int *array, int size){
    int *p = new int [size];
    for(int i = 0; i < size; i++){
        p[i] = array[(size - 1) - i];
    }
    return p;
}


