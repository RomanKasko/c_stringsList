#include "Functions.h"
int main()
{
    char** list = nullptr;
    StringListInit(&list);

    StringListAdd(list,(char*)"beta");
    StringListAdd(list,(char*)"alpha");
    StringListAdd(list,(char*)"romeo");
    StringListAdd(list,(char*)"delta");
    StringListAdd(list,(char*)"romeo");
    StringListAdd(list,(char*)"romeo");
    StringListAdd(list,(char*)"beta");

    PrintList(list);

    ShowUI(list);

    StringListDestroy(&list);
    return 0;
}
