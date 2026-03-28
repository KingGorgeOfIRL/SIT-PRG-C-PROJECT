#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../../assets/assets.h"

// ==== DB FUNCTIONS ====
void cmd_exit(char *args);
void cmd_help(char *args);

// ==== INSERT FUNCTIONS ====
void cmd_insert(char *args);

// ==== FILE I/O FUNCTIONS ====
void cmd_loadStudents(char *args);
void cmd_saveStudents(char *args);
Record *openfile(const char *file_path, char err_msg[255], int *count);
int save_records(const char *filename, Record *records, int recordCount);

// ==== READ / QUERY FUNCTIONS ====
int showAll();
void cmd_showall(char *args);

void cmd_delete(char *args);
void cmd_update(char *args);
int delete_record(Record *student_record, int *count, int position);
int update_record(Record *student_record, int count, int position, const char *name, const char *programme, float mark);

struct Student* query(int searchID);
void cmd_query(char *args);

#endif