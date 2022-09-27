#include <string.h>
#include <stdio.h>


int evaluator(char* filename);
int UpperFile(char* filename);


int main(int argc, char* argv[]){
    char* filename;
    if(argc != 2)
    {
        printf("error input!");
    }else
    {
        filename = argv[1];
        evaluator(filename);
        UpperFile(filename);
    }
    
};

int evaluator(char* filename){
    FILE *fp;
    int newlines = 0 ;
    int characters = 0;
    int uppercaseLetters = 0;
    int words = 0;
    char c;
    int flag = 0;
    fp = fopen(filename, "r");
    while((c = fgetc(fp)) != EOF)
    {
        if((c == '\n') || (c == ' '))
        {
        	flag = 0;
            if((c ==  '\n'))
                newlines++;
        }
            
        else if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            characters++;
            if ((c >= 'A' && c <= 'Z'))
                uppercaseLetters++;
        }
        if(c != ' ' && c != '\n' && flag == 0){
        	words++;
        	flag = 1;
        }
    }
    printf("newlines number: %d\n", newlines);
    printf("characters number: %d\n", characters);
    printf("uppercaseLetters number: %d\n", uppercaseLetters);
    printf("words number: %d\n", words);
    fclose(fp);
    return 0;
}

int UpperFile(char* filename)
{
    FILE *fp, *fpnew;
    char transwords;
    char c;
    fp = fopen(filename, "r");
    fpnew = fopen("UPPER", "w");
    while((c = fgetc(fp)) != EOF)
    {
        if((c >= 'a' && c <= 'z'))
        {
            transwords = c - 32;
        }else
        {
            transwords = c;
        }
        fprintf(fpnew, "%c", transwords);
    }
    return 0;

}