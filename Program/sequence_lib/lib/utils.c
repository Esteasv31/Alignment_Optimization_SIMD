//
// Created by esteasv31 on 6/5/19.
//

#include "../include/utils.h"

char* read_file(char *line) {

    /* declare a file pointer */
    FILE    *infile;
    long    numbytes;
    static const char filename[] = URLS_FILE;

    /* open an existing file for reading */
    infile = fopen(filename, "r");

    /* quit if the file does not exist */
    if(infile == NULL)
        return (char *)1;

    /* Get the number of bytes */
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);

    /* reset the file position indicator to
    the beginning of the file */
    fseek(infile, 0L, SEEK_SET);

    /* grab sufficient memory for the
    buffer to hold the text */
    line = (char*)calloc(numbytes, sizeof(char));

    /* memory error */
    if(line == NULL)
        return (char *)1;

    /* copy all the text into the buffer */
    fread(line, sizeof(char), numbytes, infile);
    fclose(infile);

    return line;
}

void download_test_files(char *a, int limit){

    int init_size = strlen(a);
    char delim[] = "\n";

    char *ptr = strtok(a, delim);

    int i = 0;
    while (ptr != NULL){
        if (i == limit) {
            printf("'%s'\n", ptr);
            char cmd[512];
            sprintf(cmd, "wget %s -P ../../test_files", ptr);
            system(cmd);
            ptr = strtok(NULL, delim);
            i = 0;
        }
        i++;
    }
}

char* get_sequence(char *path, char *line){

    /* declare a file pointer */
    FILE    *infile;
    long    numbytes;
    int count = 0;

    /* open an existing file for reading */
    infile = fopen(path, "r");

    /* quit if the file does not exist */
    if(infile == NULL)
        return (char *)1;

    /* Get the number of bytes */
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);

    /* reset the file position indicator to
    the beginning of the file */
    fseek(infile, 0L, SEEK_SET);

    /* grab sufficient memory for the
    buffer to hold the text */
    line = (char*)calloc(numbytes, sizeof(char));

    /* memory error */
    if(line == NULL)
        return (char *)1;

    /* copy all the text into the buffer */
    fread(line, sizeof(char), numbytes, infile);
    fclose(infile);

    return line;
}

int main(void){

    char line [ MAXCHAR ];

    char *a = read_file(line);

//    printf("%s \n", a);

//    download_test_files(a, 6);

    char line_1 [ MAXCHAR ];

    char *b = get_sequence(RISE507, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I1097, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE94, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE00, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE436, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE431, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(GoyetQ116_1, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE349, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE391, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(RISE577, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(Rochedane, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(Loschbour, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I6774, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I5759, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I1970, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I0260, line_1);
    printf("%s \n", b);
    printf("\n");

    b = get_sequence(I4933, line_1);
    printf("%s \n", b);
    printf("\n");
}
