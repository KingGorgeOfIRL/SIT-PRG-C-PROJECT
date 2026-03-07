#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
    int ID;
    char Name[255];
    char programme[255];
    float mark;
};
int* openfile(char file_path){
    FILE* fptr;
    fptr = fopen(file_path,"r");
    char line_data[255];
    struct Student *student_records = NULL;
    int count = 0, capacity = 0;
    // checks file pointer is vaild
    if(fptr != NULL){
        int id = 0;
        char name[255] = "";
        char programme[255] = "";
        float mark = 0.0f;
        int result;
        while ((result = fscanf(fptr, "%d,%254[^,],%254[^,],%f\n", &id, name, programme, &mark)) != EOF){
            if (result == 4){
                struct Student new_student = {id,name,programme,mark};
                if (count == capacity){
                    int new_cap = (capacity == 0) ? 2 : capacity * 2;
                    struct Student *temp = realloc(student_records,new_cap * sizeof(*student_records));
                    if (temp == NULL){
                        free(student_records);
                    }
                    student_records = temp;
                    capacity = new_cap;
                }
                student_records[count] = new_student;
                count++;
            }else{
                int ch;
                while ((ch = fgetc(fptr)) != '\n' && ch != EOF) {
                }
            }

        }
        // loops through file, line by line of a buffer size of 255 and will break if a newline character is found

    }
    fclose(fptr);
    return;
};
int save(){

}
bool query(){
    return false;
}


int main(){

    return 0;
}