#include "CMS/update/Update.c"


int main(){
    int count = 0;
    struct Student *records1 = openfile("../../DB/Sample_CMS.txt", &count);
    
    if (records1 != NULL) {
        for (int i = 0; i < count; i++) {
            printf("%d, %s, %s, %.2f\n",
                records1[i].id,
                records1[i].name,
                records1[i].programme,
                records1[i].mark);
        }
    }

    free(records1);

    return 0;
}