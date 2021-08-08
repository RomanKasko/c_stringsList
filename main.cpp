#include "Functions.h"

int main()
{
    char** list = nullptr;
    StringListInit(&list);

    StringListAdd(list,(char*)"Beta");
    StringListAdd(list,(char*)"Alpha");
    StringListAdd(list,(char*)"else");
    StringListAdd(list,(char*)"else");
    StringListAdd(list,(char*)"lol");
    StringListAdd(list,(char*)"lol");
    StringListAdd(list,(char*)"dirol");

    PrintList(list);

    ShowUI(list);

    StringListDestroy(&list);

    return 0;
}
