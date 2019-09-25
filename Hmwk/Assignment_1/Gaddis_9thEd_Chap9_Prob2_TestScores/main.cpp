/* 
 * File:   main.cpp
 * Author: Jrrobert Jabonillo
 * Created on September 23, 2019, 8:19 PM
 * Purpose:  Program that dynamically allocates an array large enough that holds a user defined number of test scores.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void selsort(float *, int);
void average(float, int);
void display(float *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float *score; 
    float total;
    int num;
    
    //User number of scores
    cout<<"Enter the amount of scores: "<<endl;
    cin>>num;
    
    //Dynamic allocate array
    score = new float[num];
    
    //Enter each score in array
    cout<<"Enter test scores: "<<endl;
    for(int i=0; i<num; i++){
        cout<<"Test score: "<<(i + 1)<<": ";
        cin>>score[i];
        while(score <= 0){
            cout<<"Scores cannot be negative"<<endl;
            cout<<"Test score: "<<(i + 1)<<": ";
            cin>>score[i];
        }
    }
    
    //Calculate total for average
    for(int i=0; i < num; i++){
        total += score[i];
    }
    
    //Sort array
    selsort(score, num);
    
    //Display sorted array
    display(score, num);
    
    //Calculate average and display
    average(total, num);

    delete [] score;
    //Exit
    return 0;
}

void selsort(float *num, int s){
    int scan;
    int minindx;
    float minval;
    
    for(scan = 0; scan < (s - 1); scan++){
        minindx = scan;
        minval = *(num + scan);
        for(int i = scan +1; i<s; i++){
            if(*(num + i) < minval){
                minval = *(num+i);
                minindx = i;
            }
        }
        *(num + minindx) = *(num + scan);
        *(num + scan) = minval;
    }
}

void display(float *n, int s){
    for(int i=0; i<s; i++){
        cout<<n[i]<<" ";
        cout<<endl;
    }
}

void average(float total, int s){
    float ave;
    
    ave = total/s;
    
    cout<<fixed<<setprecision(2)<<"Average Score: "<<ave<<endl;
    
}




