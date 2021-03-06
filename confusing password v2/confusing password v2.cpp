// confusing password v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Yuliya Vaskiv
// created: 5/25/2021
// v2 - last updated 7/10/2021
// 
// this program uses array to store numbers.
// the app promts user to put desired even set of numbers,
// those numbers are stored in the array.
// 
// the app uses forst array and by arrangement 
// create new set of numbers gthat reads every second number in array:
// 
// old set    ->     new set
// 1 2 3 4    ->     2 4 4 4
// 
// 
// 

#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"


//global variables
const int ARRAY_SIZE = 100;

//===============================================================
// 
//function that sispalys 'menu'
int intro() {
    int num;
    cout << "enter num of numbers: ";
    cin >> num;

    return num;
}

//==============================================================
// 
//function that stores value into the array
void askNum(int listN[], int& k) {
    int userN;

    if (k >= ARRAY_SIZE) {
        cout << "error......";
    }

    else {
        //stores value into specific place in array
        for (int i = 0; i < k; i++) {
            cout << "enteer " << i + 1 << " number: ";
            cin >> userN;
            listN[i] = userN; //value -> placement
        }
    }

}


//====================================================================
// 
//function that rewrites array 
int readArray(int l[], int n, int newL[]) {
    
    int nNew = 0; //value for the length of new array

    cout << "................... ";

    //looks into placemnent in the array
    for (int i = 0; i < n; i++) {
        
        //if array placemnt is divisible by two
        if (i % 2 != 0)
        {
            //writes repeated number of number that is divisible by 2
            // and repeat it depending on a previous number
            for (int p = 1; p <= l[i-1]; p++) {
                //cout << l[i]; //try1
                newL[nNew] = l[i];

                nNew++; //constantly moves into new place in array
            }
        }

        //number is not divisible by 2
        else {
            //cout << "_"; //prints blank
        }

    }
    return nNew; 
}


//
//arry can be stored in .txt, but needs modifications!!!!! 7/10/2021

/*void openFile(int num, int k[]) {
    const string FILE_NAME = "RewrittenCode.txt";
    ofstream outFile;
    outFile.open(FILE_NAME);

    if (!outFile.is_open()) {
        cout << "unable to create following file: " << FILE_NAME;
    }

    else {
        cout << "writting value into file.....";
        while (outFile.good()) {
            for (int lineCount = 0; lineCount < num; lineCount++) {
                outFile << k[lineCount];
            }
        }
    }
}*/




//============================================================
// 
//
int main()
{
    //variables
    int NUM[ARRAY_SIZE]; 
    int newNUM[ARRAY_SIZE];
    int number; //number that will be entered

    cout << "Hello World!\n";
    number = intro(); //function that promts user


    //number needs to be even
    while (number % 2 != 0) {
        cout << "========================\n";
        cout << "Try even number!\n";
        number = intro();
    }

    //function that stores each value into array
    askNum(NUM, number);

    //function that rewrites the values
    int newNumber = readArray(NUM, number, newNUM);

    //print original set of numbers from array
    cout << "\nold set of numbers: ";
    for (int d = 0; d < number; d++) 
        cout << " " << NUM[d];
    

    //print new set of numbers deom new array
    cout << "\nnew set of numbers: ";
    for (int v = 0; v < newNumber; v++) 
        cout << " " << newNUM[v];
    
    
    //final statement
    cout << "\n\nend\n.......................";
    

}
//=====================================================================

