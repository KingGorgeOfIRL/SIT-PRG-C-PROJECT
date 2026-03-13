struct Student 
{
    int id;
    char name[255];
    char programme[255];
    float mark;
};
/*open IO function to read from txt file*/
struct Student *openfile(const char *file_path, int *out_count);

int update_student(Student *student_record, int *size_of_array,Student *new_data);

int delete_student(int id,Student *student_record,int *size_of_array);
