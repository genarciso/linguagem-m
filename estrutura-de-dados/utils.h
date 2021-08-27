#ifndef utils_File
#define utils_File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./hashTable.h"
#include "./list.h"
#include "./tuple.h"

typedef struct RuleInfo
{
    char* value;
    char* type;
}RuleInfo;

RuleInfo* utils_createRuleInfo(char* value, char* type) {
    RuleInfo *aux = (RuleInfo*) malloc(sizeof(RuleInfo));
    aux->value = (char*) malloc(strlen(value) * sizeof(char));
    aux->type  = (char*) malloc(strlen(type) * sizeof(char));
    strcpy(aux->value, value);
    strcpy(aux->type, type);
    return aux;
}

void utils_freeRuleInfo(RuleInfo *ri) {
    free(ri->value);
    free(ri->type);
    free(ri);
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

#endif
