#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "List.h"
using namespace std;

int main(int argc, char *argv[]){


    fstream oFile, inFile1, inFile2;
    inFile1.open(argv[1], ios::in);
    inFile2.open(argv[2], ios::in);
    oFile.open("RESULT", ios::out);

    List<double> List_double;
    List<string> List_string;
    unsigned int datalength1;
    unsigned int datalength2;
    
    if (argc != 3) {
        cout << "input error. Sorry!" << endl;
        return 1;
    }

    //inFile1.open(argv[1], ios::in);
    if (inFile1.fail()) {
       cout << "inFile1 " << argv[1] << " open error. Sorry!" << endl;
       return 1;
    }else{
        //unsigned int datalength1;
        if(inFile1 >> datalength1){
            oFile << "inFile1 datalength1 = " << datalength1 << endl;
            List_double.setLength(datalength1);
            oFile << "Create a List_double, its array size = " << List_double.getLength() << endl;
            inFile1 >> List_double;
            oFile << "List_double's array: " << List_double;
            inFile1.close();
        }
    }
    //copy constructor
    List<double> List_double_copy(List_double);
    cout << "List_double: " << List_double << endl;
    cout << "List_double_copy: " << List_double_copy << endl;
    oFile << "List_double_copy's array: " << List_double_copy << endl << endl;
    if(List_double == List_double_copy){
        cout << "List_double == List_double_copy !" << endl << endl;
        oFile << "List_double == List_double_copy !" << endl << endl;
    }else{
        cout << "List_double != List_double_copy !" << endl << endl;
        oFile << "List_double != List_double_copy !" << endl << endl;
    } 
    

    //inFile2.open(argv[2], ios::in);
    if (inFile2.fail()) {
       cout << "inFile2 " << argv[2] << " open error. Sorry!" << endl;
       return 1;
    }else{
        //unsigned int datalength2;
        if(inFile2 >> datalength2){
            oFile << "inFile1 datalength2 = " << datalength2 << endl;
            List_string.setLength(datalength2);
            oFile << "Create a List_string, its array size = " << List_string.getLength() << endl;
            inFile2 >> List_string;
            oFile << "List_string's array: " << List_string;
            inFile2.close();
        }
    }
    //assignment operator
    List<string> List_string_assignment;
    List_string_assignment = List_string;
    cout << "List_string: " << List_string << endl;
    cout << "List_string_assignment: " << List_string_assignment << endl;
    oFile << "List_string_assignment's array: " << List_string_assignment << endl << endl;
    if(List_string_assignment == List_string){
        cout << "List_string_assignment == List_assignment !" << endl << endl;
        oFile << "List_string_assignment == List_assignment !" << endl << endl;
    }else{
        cout << "List_string_assignment != List_assignment !" << endl << endl;
        oFile << "List_string_assignment != List_assignment !" << endl << endl;
    }
    


    List<double> List_setELement(20);
    cout << "create a array object and it size= " << List_setELement.getLength() << endl;
    oFile << "create a array object and it size= " << List_setELement.getLength() << endl;
    for (int i = 0; i < 20; i++){
        List_setELement.setElement(i, i+1);
    }
    oFile << "List_setElement: " << List_setELement << endl;
    cout << "List_setElement: " << List_setELement << endl;


}