/* 
 * File:   main.cpp
 * Author: Jabonillo, Jrrobert
 * Created on September 23, 2019, 11:54 PM
 * Purpose:  Write a function that uses reference variables as parameters
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int dosomething(int &x, int &y);
int dosomething2(int *x, int *y);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int x1 = 2, y1 = 3;
    int z = dosomething2(&x1, &y1);
    
    //Process/Calculations Here
    cout<<" X= "<<x1<<" Y= "<<y1<<" Z= "<<z<<endl;
    
    
    
    
    
    //Exit
    return 0;
}

int dosomething(int &x, int &y){
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
}

int dosomething2(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}



