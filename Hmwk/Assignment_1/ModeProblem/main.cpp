/* 
 * File: main.cpp
 * Author: Jrrobert Jabonillo
 * Created on Sept 19,2019 11:35 AM
* Purpose:  Mode Template
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *filAray(int,int);
void prntAry(int *,int,int);
void prtMode(int *);
float mean(int *, int);
void prtMean(float);
int median(int *, int);
void prntMed(int);
void destroy(int *);
void markSrt(int *,int);
int *mode(int *,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int size,modVal,perLine,*a1D,*modAray,med;
    float average;
    
    //Input or initialize values Here
    size=10;
    modVal=5;
    a1D=filAray(size,modVal);
    
    //Display the unsorted array
    prntAry(a1D,size,modVal);
    
    //Process/Calculations Here
    markSrt(a1D,size);
    average=mean(a1D,size);
    med=median(a1D, size);
    
    //modAray is an array filled with the modes from a1D
    modAray=mode(a1D,size);
    
    //Output Located Here
    prntAry(a1D,size,modVal);
    prtMean(average);
    prntMed(med);
    prtMode(a1D);
    
    //Clean up
    destroy(a1D);
    destroy(modAray);

    //Exit
    return 0;
}

void prtMode(int *a){
    cout<<"The modes of the array are: "<<endl;
    for(int i = 0; i < 10; i++){
        cout<<*(a+i); 
    }
    
}

void prtMean(float average){
    cout<<"The mean of the array is: "<<average<<endl;
    
}

void prntMed(int median){
    cout<<"The median of the array is: "<<median<<endl;
}

int *mode(int *a,int n){
    //You write the function
    int *count = new int[n];
    int *modAray=new int[2];
    int num, max;
    modAray[0]=0;//Number of modes go here
    modAray[1]=0;//Frequence goes here
    for(int i = 0; i < n; i++){
        *(count+*(a+i));
    }
    max = count[0];
    for(int j = 1; j < n; j++){
        if(*(count+j) > max){
            max = *(count+j);
        }
    }
    
    num = 0;
    for(int i = 0; i < n; i++){
        if(*(count+i) == max){
            *(modAray+num) == *(a+i);
        }
    }
       
    //mode[2 to mode[0]];
    return modAray;
}

void markSrt(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void destroy(int *a){
    delete []a;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n,int m){
    n=n<2?2:
      n>1000?1000:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i%m;//2 digit numbers
    }
    return array;
}

float mean(int *a, int n){
    int sum = 0.0;
    float average;
    for(int i = 0; i < n; i++){
        sum += *(a+i);
    }
    return average = sum/n;
}

int median(int *a, int n){
    int mid, median;
    mid = (n-1)/2;
    if(n % 2 == 0){
        median = (*(a+mid)+*(a+(mid+1)))/2;
    }
    else{
        median = *(a+mid);
    }
    return median;
}
