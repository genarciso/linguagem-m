#ifndef utils_File
#define utils_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./hashTable.h"
#include "./tuple.h"

typedef struct LITERAL
{
    char* value;
    char* type;
}LITERAL;

LITERAL* utils_createLiteral(char* value, char* type) {
    LITERAL *aux = (LITERAL*) malloc(sizeof(LITERAL));
    aux->value = (char*) malloc(strlen(value) * sizeof(char));
    aux->type  = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(aux->value, value);
    strcpy(aux->type, type);
    return aux;
}

char* utils_strcat(char *str1, char *str2) {
    char *aux = (char*) malloc(1 * sizeof(char));
    strcat(aux, str1);
    strcat(aux, str2);

    return aux;
}

char* utils_strAppendInt(char *str, int n) {
    char *ptr = malloc(strlen(str) + 4 * sizeof(char));
    sprintf(ptr, "%s%d", str, n);

    return ptr;
}

char* utils_strRemoveSpace(char *str) {
    char *ptr;
    int spacesBegin = 0, spacesEnd = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') break;
        spacesBegin++;
    }

    for(int i = strlen(str) - 1; i >= 0; i--) {
        if(str[i] != ' ') break;
        spacesEnd++;
    }

    ptr = malloc(strlen(str) - spacesBegin - spacesEnd * sizeof(char));
    strncpy(ptr, str+spacesBegin, strlen(str) - spacesBegin - spacesEnd);
    return ptr;
}

Tuple* utils_findVar(HashTable *symbolTable, char* varName, int scopeLevel) {
    char *key;
    Tuple *aux;
    
    while(scopeLevel >= 0) {
        key = utils_strAppendInt(varName, scopeLevel);
        aux = hashTable_find(symbolTable, key);
        if(aux != NULL) return aux;
        scopeLevel--;
    }

    return NULL;
}

#endif
