#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *concat(const char *s1, const char *s2); 

int main(void) {

    char s1[] = "abcdefghij";
    char s2[] = "ooooiioooo";
    char s3[] = "ABCDEFGHIJ";

    int len = sizeof(s1); 

    int i;
    for (i=0; i <= len; i++) {
        printf("%c %c\n", s1[i], s2[i]); 
    }

    char *dest = (char *)malloc(sizeof(s1));

    strcpy(s1, s2);

    //for (i=1; i<=11; i++) { off by 1
    for (i=0; i<=len; i++) {
        dest[i] = s1[i];
        printf("%c %c\n", dest[i], s1[i]); 
    }
    dest[len] = '\0';

    const char *bigstr;
    bigstr = concat(s2, s3);
    printf("%s\n", bigstr); 

    return 0;
}

char *concat(const char *s1, const char *s2) {
    char *result;

    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE); 
    }
    strcpy(result, s1); 
    strcat(result, s2); 
    return result;
}











