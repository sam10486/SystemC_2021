#include <stdio.h>
#include <stdlib.h>


int memoryallocate(char* inputnum);

int main(int argc, char* argv[])
{
    char* inputnum = argv[1];
    memoryallocate(inputnum);
}

int memoryallocate(char* inputnum)
{
    int argvValue = atoi(inputnum);//10
    char* memorysize ;
    memorysize = (char*) malloc(sizeof(char)*argvValue); 
    printf("argvValue= %d\n", argvValue);
    printf("address: %p\n", memorysize);
    printf("value: %d\n", *memorysize);

    char English = 0x41;//A
    char Number = 0x31;//1
    int flag = 0;
    int i = 0;

    for(i = 0; i < argvValue; i++){
     
        if(flag == 0){
            memorysize[i] = English; 
            if(English == 0x5A){
                English = 0x41;
                flag = 1;
            } 
            else
                English += 1;  
        }
        else if(flag == 1){
            memorysize[i] = Number;
            if(Number == 0x39){
                Number = 0x31;
                flag = 0;
            }
            else
                Number += 1;
            
        }
        printf("i= %d ", i);
        printf("flag= %d ", flag);
        printf("memoryvalue= %c\n", memorysize[i]);
        ///////////////////////////////////// 
    }

    int *Intmemory = (int*) memorysize ;  
    i = 0;
    int iteration;
    iteration = (argvValue/4) ;
    /*if (argvValue % 4 == 0)
        iteration = (argvValue/4) ;
    else
        iteration = (argvValue/4) + 1 ;*/
    
    do{
        
        printf("iteration= %d // ", i);
        printf("Before minus Intmemory= 0x%x // ", Intmemory[i]);
        Intmemory[i]--;
        printf("After minus Intmemory= 0x%x\n", Intmemory[i]);
        i++;
        
    }while(i < iteration);

    free(memorysize);
    return 0; 
}

