#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;



int main(int argc, char* argv[]){
    fstream oFile, iFile;
    iFile.open(argv[1], ios::in);
    oFile.open("RESULT", ios::out);
    List list_1;
    
    if(!iFile.fail()){
        unsigned int datalength;
        if(iFile >> datalength){
            oFile << "input datalength = " << datalength << endl;
            list_1.setLength(datalength);
            oFile << "Create a list_1, its array size = " << list_1.getLength() << endl; 
            iFile >> list_1;
            oFile << "input list's array: " << list_1 << endl;
            iFile.close();
        }
    }
    
    oFile << "using 3 different ways to  copy list_1" << endl << endl;
    oFile << "//////////////////////////////////////////////////////" << endl;
    
    

    //copy constructor
    
    List list_copy(list_1);
    oFile << "1. use copy constructor" << endl;
    oFile << "list_1 =  " << list_1;
    oFile << "list_copy = " << list_copy;
    oFile << "//////////////////////////////////////////////////////" << endl;

    //memenber function
    unsigned int i;   
    List list_member(list_1.getLength());
    for(i = 0; i < list_1.getLength(); i++){
        list_member.setElement(i, list_1.getElement(i));
    }
    oFile << "2. use member function to copy" << endl;
    oFile << "list_1 =  " << list_1;
    oFile << "list_member = " << list_member;
    oFile << "//////////////////////////////////////////////////////" << endl;

    //assignment constructor
    List list_assignment;
    list_assignment = list_1;
    oFile << "3. use assignment constructor" << endl;
    oFile << "list_1 = " << list_1;
    oFile << "list_assignment = " << list_assignment;
    oFile << "//////////////////////////////////////////////////////" << endl;


    /*for(i = 0; i < list_1.getLength(); i++){
        list_member.setElement(i, list_1.getElement(i));
    }
    oFile << "*****use function test******" << endl;
    oFile << "list_1 =  " << list_1;
    oFile << "list_member = " << list_member;
    oFile << "//////////////////////////////////////////////////////" << endl;

    list_assignment = list_1;
    oFile << "*****use assignment test*****" << endl;
    oFile << "list_1 = " << list_1;
    oFile << "list_assignment = " << list_assignment;
    oFile << "//////////////////////////////////////////////////////" << endl;*/

    oFile << "(add two of Lists using operator+)" << endl;
    oFile << "list_copy = " << list_copy;
    oFile << "list_member = " << list_member;
    oFile << "list_assignment = " << list_assignment;
    list_assignment = list_copy + list_member;
    oFile << "Equation : list_assignment = list_copy + list_member = " << list_assignment;
    oFile << "//////////////////////////////////////////////////////" << endl;

    oFile << "(use operator++ to add 1 to another List)" << endl;//++a
    oFile << "list_assignment =  " << list_assignment;
    oFile << "list_copy = " << list_copy;
    oFile << "Equation : list_copy = ++list_assignment " << endl;
    list_copy = ++list_assignment;
    oFile << "list_assignment = " << list_assignment;
    oFile << "list_copy = " << list_copy;
    oFile << "//////////////////////////////////////////////////////" << endl;

    oFile << "(use operator++(int) to add 1 to another List)" << endl;//a++
    oFile << "list_assignment =  " << list_assignment;
    oFile << "list_member = " << list_member;
    oFile << "Equation : list_member = list_assignment++ " << endl;  
    list_member = list_assignment++;
    oFile << "list_assignment = " << list_assignment;
    oFile << "list_member = " << list_member;
    oFile << "//////////////////////////////////////////////////////" << endl;  

    oFile << "(use operator+= to add another List to a List)" << endl;
    oFile << "list_assginment =  " << list_assignment;
    oFile << "list_copy = " << list_copy;
    list_assignment += list_copy;
    oFile << "Equation : list_assignment += list_copy =  " << list_assignment;
    oFile << "//////////////////////////////////////////////////////" << endl;

    oFile << "(use operator-- to subtract 1 from all elements in a List)" << endl;
    oFile << "list_assignment =  " << list_assignment;
    oFile << "list_copy = " << list_copy;
    oFile << "Equation : list_copy = --list_assignment " << endl;
    list_copy = --list_assignment;
    oFile << "list_assignment = " << list_assignment;
    oFile << "list_copy = " << list_copy;
    oFile << "//////////////////////////////////////////////////////" << endl;

    oFile << "(use operator--(int) to subtract 1 from all elements in a List)" << endl;
    oFile << "list_assignment = " << list_assignment;
    oFile << "list_member = " << list_member;
    oFile << "Equation : list_member = list_assignment-- " << endl;
    list_member = list_assignment--;
    oFile << "list_assignment = " << list_assignment;
    oFile << "list_member = " << list_member;
   

    oFile.close();
}

