#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// single element record
typedef struct Student {
    int id;
    char name[255];
    char programme[255];
    float mark;
}Student;

// open IO function to read from txt file
Student *openfile(const char *file_path, int *out_count){
    FILE *fptr = fopen(file_path,"r");
    Student *student_records = NULL;
    int count = 0, capacity = 0;

    if (out_count != NULL){
        *out_count = 0;
    }

    // checks file pointer is vaild
    if(fptr != NULL){
        while (1){
            int id = 0;
            char name[255] = "";
            char programme[255] = "";
            float mark = 0.0f;
            int result = fscanf(fptr, "%d,%254[^,],%254[^,],%f", &id, name, programme, &mark);
            if (result == 4){
                if (count == capacity){
                    int new_cap = (capacity == 0) ? 2 : capacity * 2;
                    Student *temp = realloc(student_records,new_cap * sizeof(*student_records));
                    if (temp == NULL){
                        free(student_records);
                        fclose(fptr);
                        return NULL;
                    }
                    student_records = temp;
                    capacity = new_cap;
                }
                student_records[count].id = id;
                strncpy(student_records[count].name, name, sizeof(student_records[count].name) - 1);
                student_records[count].name[sizeof(student_records[count].name) - 1] = '\0';

                strncpy(student_records[count].programme, programme, sizeof(student_records[count].programme) - 1);
                student_records[count].programme[sizeof(student_records[count].programme) - 1] = '\0';

                student_records[count].mark = mark;
                count++;
            }else if (result == EOF){
                break;
            }else{
                int ch;
                while ((ch = fgetc(fptr)) != '\n' && ch != EOF) {
                }
            }

        }
        // loops through file, line by line of a buffer size of 255 and will break if a newline character is found

    } else{
        return NULL;
    }
    fclose(fptr);
    if (out_count != NULL) {
        *out_count = count;
    }
    return student_records;
}

// generic bool check of 
int check_query(int id, Student *student_record,int size){
    for (int i = 0; i < size; i++){
        if (student_record[i].id == id){
            return i;
        }
    }
    return sizeof(student_record) + 1;
}

int update_student(Student *student_record, int *size_of_array,Student *new_data){
    int position = check_query(new_data[0].id,student_record,*size_of_array);
    if (position <= *size_of_array){
        student_record[position].id = new_data[0].id;
        strcpy(student_record[position].name,new_data[0].name);
        strcpy(student_record[position].programme,new_data[0].programme);
        student_record[position].mark = new_data[0].mark;
        return -1;
    }else{
        /* error message of invalid id*/
        return new_data[0].id;
    }

}

int delete_student(int id,Student *student_record,int *size_of_array){
    int i = check_query(id,student_record,*size_of_array);
    if (i <= *size_of_array){
        int count = *size_of_array;
        for (i; i < count; i++) student_record[i] = student_record[i+1];
        *size_of_array = count - 1;
        return -1;
    }else{
        return id;
    }
}

void show_all(Student *records,int count){
    for (int i = 0; i < count; i++) {
    printf("%d, %s, %s, %.2f\n\n",
        records[i].id,
        records[i].name,
        records[i].programme,
        records[i].mark);
    }
}

int main(){    
    int id,err,count = 0;
    Student *records = openfile("../../DB/Sample_CMS.txt", &count);
    Student update_data = {id,"testname","testprogramme",11.11};
    if (records != NULL) {
        show_all(records,count);
        int id;
        printf("enter ID to update\n");
        scanf("%d",&id);
        update_data.id = id;
        err = update_student(records,&count,&update_data);
        if (err == -1){
            show_all(records,count);
        }else printf("%d\n",err);
        
        printf("enter ID to delete\n");
        scanf("%d",&id);
        err = delete_student(id,records,&count);
        if (err == -1){
            show_all(records,count);
        }else printf("%d\n",err);        
    }

    free(records);
    return 0;
}