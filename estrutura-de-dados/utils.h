#ifndef utils_File
#define utils_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./hashTable.h"
#include "./list.h"
#include "./tuple.h"

typedef struct StaticInfo
{
    char* value;
    char* type;
    struct List *paramsType; 
}StaticInfo;

StaticInfo* utils_createStaticInfo(char* value, char* type) {
    StaticInfo *aux = (StaticInfo*) malloc(sizeof(StaticInfo));
    aux->value = (char*) malloc(strlen(value) * sizeof(char));
    aux->type  = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(aux->value, value);
    strcpy(aux->type, type);
    return aux;
}

void utils_freeStaticInfo(StaticInfo *si) {
    free(si->value);
    free(si->type);
    free(si);
}

char* utils_strcat(char *str1, char *str2) {
    char *aux = (char*) malloc(1 * sizeof(char));
    strcat(aux, str1);
    strcat(aux, str2);
    //printf("%s\n", aux);
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
    //printf("%s\n", str);
    //printf("%d\n", spacesBegin);
    //printf("%d\n", spacesEnd);
    
    ptr = malloc((strlen(str) - spacesBegin - spacesEnd) * sizeof(char));
    int i = 0;
    //printf("%lu\n", (strlen(str) - spacesEnd));
    for(int j = spacesBegin;j < (strlen(str) - spacesEnd - 1 );j++) {
        strcpy(ptr+i, &str[i]);
        i++;
    }
    ptr[i+1] = NULL;
    //printf("%d\n", i);
    //printf("remove: %s - %lu\n", ptr, strlen(ptr));
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

int utils_countComan(char *str) {
    int qtyComan = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ',') qtyComan++;
    }

    return qtyComan;
}

void utils_removeVarScope(HashTable *symbolTable, List *keys) {
    for(int i = keys->size - 1; i >= 0; i--) {
        hashTable_remove(symbolTable, list_get(keys, i));
        list_pop(keys);
    }

    //printf("Exit block\n");
    //hashTable_display(symbolTable);
}

void utils_addVarSymbolTable(HashTable *symbolTable, char *type, char *varName, char *key) {
    Tuple *tuple = tuple_create(varName, type); 
    hashTable_insert(symbolTable, key, tuple);
}

bool utils_isANumberType(char *type) {
    return strcmp(type, "int") == 0  || strcmp(type, "float") == 0 || strcmp(type, "double") == 0;
}

char* utils_convertType(char *type1, char *type2) {
    char *aux;

    if(strcmp(type1, type2) == 0 ) {
        aux = malloc(strlen(type1) * sizeof(char));
        strcpy(aux, type1);
        return aux;
    }

    if((strcmp(type1, "float") == 0 || strcmp(type2, "float") == 0) && (strcmp(type1, "int") == 0 || strcmp(type2, "int") == 0)) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "float");
        return aux;
    }

    if((strcmp(type1, "double") == 0 || strcmp(type2, "double") == 0) && (strcmp(type1, "float") == 0 || strcmp(type2, "float") == 0)) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "double");
        return aux;
    }

    if((strcmp(type1, "double") == 0 || strcmp(type2, "double") == 0) && (strcmp(type1, "int") == 0 || strcmp(type2, "int") == 0)) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "double");
        return aux;
    }

    if((utils_isANumberType(type1) || utils_isANumberType(type2)) && (strcmp(type1, "string") == 0 || strcmp(type2, "string") == 0)) {
        aux = malloc(7 * sizeof(char));
        strcpy(aux, "string");
        return aux;
    }

}

char* utils_convertTypeAssigment(char *lhsType, char *rhstype) {
    char *aux;

    if(strcmp(lhsType, rhstype) == 0 ) {
        aux = malloc(strlen(lhsType) * sizeof(char));
        strcpy(aux, lhsType);
        return aux;
    }

    if(strcmp(lhsType, "float") == 0  && strcmp(rhstype, "int") == 0) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "float");
        return aux;
    }

    if(strcmp(lhsType, "double") == 0  && strcmp(rhstype, "float") == 0) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "double");
        return aux;
    }

    if(strcmp(lhsType, "double") == 0 && strcmp(rhstype, "int") == 0) {
        aux = malloc(6 * sizeof(char));
        strcpy(aux, "double");
        return aux;
    }

    if((utils_isANumberType(rhstype) || utils_isANumberType(rhstype)) && strcmp(lhsType, "string") == 0) {
        aux = malloc(7 * sizeof(char));
        strcpy(aux, "string");
        return aux;
    }

    return rhstype;

}

#endif