/* 
 * File:   main.cpp
 * Author: Jrrobert Jabonillo
 * Created on September 23, 2019, 11:48 PM
 * Purpose:  Dynamically allocate donations array from figure progam 9-19. And ask for user values. Change the order to ascending.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void selsort(float *[], int);
void show(float [], int);
void sorted(float *[], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float *donate;
    float **arrPtr;
    int num;
    int size;
    
    //User number of scores
    cout<<"Enter the amount of donations: "<<endl;
    cin>>num;
    size = num;
    
    //Dynamic allocate array
    donate = new float[num];
    arrPtr = new float*[num];
    
    //Enter each score in array
    cout<<"Enter donation amounts: "<<endl;
    for(int count=0; count<size; count++){
        cout<<"Donations Amount: "<<(count + 1)<<": ";
        cin>>donate[count];
        /*while(donate <= 0){
            cout<<"Donations cannot be zero"<<endl;
            cout<<"Donation Amount: "<<(i + 1)<<": ";
            cin>>donate[i];
        */
        arrPtr[count] = &donate[count];
    }
    
    //Sort array
    selsort(arrPtr, size);
    
    //Display sorted array
    cout<<"Sorted Array "<<endl;
    sorted(arrPtr, num);
    
    //Display array in original order
    cout<<"Original Order of Array"<<endl;
    show(donate, num);
    
    if(size > 0){
        delete [] donate;
        donate = 0;
        delete [] arrPtr;
        arrPtr = 0;
    }
    //Exit
    return 0;
}

void selsort(float *arr[], int size){
    int scan, minindx;
    float *minval;
    
    for(scan = 0; scan < (size - 1); scan++){
        minindx = scan;
        minval = arr[scan];
        for(int i = scan +1; i<size; i++){
            if(*(arr[i]) > *minval){
                minval = arr[i];
                minindx = i;
            }
        }
        arr[minindx] = arr[scan];
        arr[scan] = minval;
    }
}

void sorted(float *n[], int size){
    for(int count=0; count<size; count++){
        cout<<*(n[count])<<" ";
        cout<<endl;
    }
}

void show(float n[], int size){
    for(int count=0; count<size; count++){
        cout<<n[count]<<" ";
        cout<<endl;
    }
}





