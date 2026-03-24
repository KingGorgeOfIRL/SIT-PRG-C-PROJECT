#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linked list to store student details
typedef struct Student{
    int id;
    char name[255];
    char programme[255];
    float mark;
}Student;

// array of linked list pointers, point to the first node of every 10 IDs
typedef struct Record{
    Student *node;
}Record;

// returns position if found and sorted, expected position if not found 
int binary_search(Record *student_record,int *count, int id){
/* binary search of array */
    int low = 0;
    int high = *count - 1;

    while(low <= high){
        int position = low + (high - low) / 2;
        int current_id = student_record[position].node->id;
        if (current_id == id){
            return position;
        }else if (current_id < id){
            low = position + 1;
        }else{
            high = position - 1;
        }
    }
    return low;
}

// assumes that student is not in record
int insert(Record **student_record, int *capacity, int *count, int position, int id, const char *name, const char *programme,float mark){
    /* expanding memory allocation */
    if (*capacity == *count){
        int new_cap = *capacity + 1;
        Record *temp = realloc(*student_record,new_cap * sizeof((*student_record)[0]));
        if (temp == NULL){
            return -1;
        }
        *student_record = temp;
        *capacity = new_cap;
    }

    /* create new student*/
    Student *new_student = malloc(sizeof(Student));
    if (new_student == NULL) {
        return -1;
    }else{
        new_student->mark=mark;
        new_student->id=id;
        strcpy(new_student->name,name);
        strcpy(new_student->programme,programme);
    }
    

    /* create first address */
    for ( int i = *count; i > position; i--){
        (*student_record)[i].node = (*student_record)[i-1].node;
    }
    (*student_record)[position].node = new_student;
    (*count)++;
    return 1;
}

// open IO function to read from txt file
Record *openfile(const char *file_path, char err_msg[255], int *count){
    FILE *fptr = fopen(file_path,"r");
    int capacity = 1;
    *count = 0;

    /* invalid file*/
    Record *student_records = malloc(capacity * sizeof(Record));
    if (student_records == NULL) {
        strcpy(err_msg, "Initial memory allocation failure");
        if (fptr != NULL) {
            fclose(fptr);
        }
        return NULL;
    }else if (fptr == NULL) {
        strcpy(err_msg, "Failed to open file");
        free(student_records);
        return NULL;
    }

    int result;
    /* reads fileline for variables */
    int id = 0;
    char name[255] = "";
    char programme[255] = "";
    float mark = 0.0f;
    do{
        result = fscanf(fptr, "%d,%254[^,],%254[^,],%f", &id, name, programme, &mark);

        if (result == 4){
            int position = binary_search(student_records,count,id);
            result = insert(&student_records,&capacity,count,position,id,name,programme,mark);
            if (result == -1){
                strcpy(err_msg, "Expanded memory allocation failure");
                fclose(fptr);
                free(student_records);
                return NULL;
            }else if (result == 0){
                strcpy(err_msg, "Unexpected failure");
                fclose(fptr);
                free(student_records);
                return NULL;
            }
        }else{
            int ch;
            while ((ch = fgetc(fptr)) != '\n' && ch != EOF) {
            }
        }
    }while (result != EOF);
    fclose(fptr);
    return student_records;
}

// returns student id if there is an error, assumes that student is in record
int update(Record *student_record, int size_of_array, int position, Student *new_data){
    if (position <= size_of_array){
        Student *old_student = student_record[position].node;
        old_student->id = new_data->id;
        strcpy(old_student->name,new_data->name);
        strcpy(old_student->programme,new_data->programme);
        old_student->mark = new_data->mark;
        return -1;
    }else{
        /* error message of invalid id*/
        return new_data->id;
    }

}

int delete(int position, Record *student_record,int size_of_array){
    if (position <= size_of_array){
        free(student_record[position].node);
        for (int i = position; i < size_of_array; i++){
            student_record[i].node = student_record[i+1].node;
        }
        return -1;
    }else{
        return position;
    }
}

void show_all(Record *records,int count){
    for (int i = 0; i < count; i++) {
    Student *current = records[i].node;
    if (current == NULL){
        continue;
    }
    
    printf("%d, %s, %s, %.2f\n",
        current->id,
        current->name,
        current->programme,
        current->mark);
    }
    printf("\n");
}

int main(){    
    int id = 2304567,count = 0,capacity = 1;
    char err_msg[255];
    Record *records = openfile("../../StudentRecords/P1-7_CMS.txt",err_msg, &count);
    if (records != NULL) {
       Student update_data = {id,"testname","testprogramme",11.11};
       int position = binary_search(records,&count, id);
       show_all(records,count);

       update(records,count,position,&update_data);
       show_all(records,count);

       delete(position,records,count);
       show_all(records,count);
       
       insert(&records,&capacity,&count,position,id,update_data.name,update_data.programme,update_data.mark);
       show_all(records,count);
    }  

    free(records);
    return 0;
}