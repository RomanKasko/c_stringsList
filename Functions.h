// Created by Romeo on 03.08.2021.
#ifndef C_STRINGSLIST_FUNCTIONS_H
#define C_STRINGSLIST_FUNCTIONS_H

#include <string.h>
#include <stdlib.h>
#include <iostream>

#define VALUE 0
#define NEXT_NODE 1

typedef char* String;

template<typename T> bool IsNull(T value);
void PrintList(char** listHead);

/* Initializes list */
void StringListInit(char*** list);

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);

/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str);

/* Removes all occurrences of str in the list. */
void StringListRemove(char** list, String str);

void DeleteNode(char** list, unsigned int index);

/* Returns the number of items in the list. */
int StringListSize(char** list);

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str);

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list);

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after);

/* Sorts the list of strings in ascending order */
void StringListSort(char** list);

void Swap(char** firstEl, char** secEl);
void ShowUI(char** list);

#endif //C_STRINGSLIST_FUNCTIONS_H
