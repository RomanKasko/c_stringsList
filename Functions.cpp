#include "Functions.h"

template<typename T>
bool IsNull(T value)
{
    if(value == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PrintList(char** listHead)
{
    if(IsNull(listHead))
    {
        std::cerr<<"List is null in PrintList"<<std::endl;
        return;
    }

    listHead = (char**)listHead[NEXT_NODE];

    while(listHead != nullptr)
    {
        std::cout << listHead[VALUE] << " ";
        listHead = (char**)listHead[NEXT_NODE];
    }
    std::cout<<std::endl;
}

/* -----------DONE----------- Initializes list */
void StringListInit(char*** list)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListInit"<<std::endl;
        return;
    }

    char* defaultStr = (char*)"Root";

    *list = (char**)malloc(sizeof(char*) * 2);
    (*list)[VALUE] = defaultStr;
    (*list)[NEXT_NODE] = nullptr;
}

/* Destroy list and set pointer to nullptr. */
void StringListDestroy(char*** list)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListDestroy"<<std::endl;
        return;
    }

    char** currentNode;
    do
    {
        currentNode = (char**)(*list)[NEXT_NODE];
        free(list[VALUE]);
        *list = currentNode;
    }while(currentNode != nullptr);
}

/* -----------DONE----------- Inserts value at the end of the list. */
void StringListAdd(char** list, String str)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListAdd"<<std::endl;
        return;
    }
    else if(IsNull(str))
    {
        std::cerr<<"String is null in StringListAdd"<<std::endl;
        return;
    }

    char** head = list;
    char* tmpStr = (char*)malloc(sizeof(char*));
    strcpy_s(tmpStr,strlen(str)+1,str);


    while(head[NEXT_NODE] != nullptr)
    {
        head = (char**)head[NEXT_NODE];
    }

    char** node = (char**)malloc(sizeof(char*) * 2);
    node[VALUE] = (char*)malloc(strlen(str)+1);
    node[VALUE] = tmpStr;
    node[NEXT_NODE] = nullptr;

    head[NEXT_NODE] = (char*)node;
}

/* -----------DONE----------- Removes all occurrences of str in the list. */
void StringListRemove(char** list, String str)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListRemove"<<std::endl;
        return;
    }
    else if(IsNull(str))
    {
        std::cerr<<"String is null in StringListRemove"<<std::endl;
        return;
    }

    char** head = list;

    while(head != nullptr)
    {
        int headIndex = -1;
        int newIndex = StringListIndexOf(head,str);
        if(newIndex < 0) return;

        while(headIndex != newIndex)
        {
            head = (char**)head[NEXT_NODE];
            ++headIndex;
        }
        DeleteNode(list,headIndex);
        head = list;
    }
}

void DeleteNode(char** list,unsigned int index)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in DeleteNode"<<std::endl;
        return;
    }
    else if(StringListSize(list) <= index)
    {
        std::cerr<<"Index out of range in DeleteNode"<<std::endl;
        return;
    }

    char** head = (char**)list[NEXT_NODE];

    if(index == 0)
    {
        char** root = list;
        root[NEXT_NODE] = head[NEXT_NODE];
        free(head);
    }
    else
    {
        unsigned int headIndex = 0;
        while (headIndex != index - 1)
        {
            head = (char **) head[NEXT_NODE];
            ++headIndex;
        }

        char **tmp = (char **) head[NEXT_NODE];
        head[NEXT_NODE] = tmp[NEXT_NODE];
        free(tmp);
    }
}

/* -----------DONE----------- Returns the number of items in the list. */
int StringListSize(char** list)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListSize"<<std::endl;
        return -1;
    }
    list = (char**)list[NEXT_NODE];

    int size = 0;
    while(list != nullptr)
    {
        ++size;
        list = (char**)list[NEXT_NODE];
    }
    return size;
}

/* -----------DONE----------- Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, char* str)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListIndexOf"<<std::endl;
        return -1;
    }
    else if(IsNull(str))
    {
        std::cerr<<"String in null in StringListIndexOf"<<std::endl;
        return -1;
    }

    list = (char**)list[NEXT_NODE];

    int index = 0;
    while(list != nullptr)
    {
        if(strcmp(list[VALUE],str) == 0) return index;
        list = (char**)list[NEXT_NODE];
        ++index;
    }
    return -1;
}

/* -----------DONE----------- Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListRemoveDuplicates"<<std::endl;
        return;
    }

    char** head = list;
    while(head != nullptr)
    {
        int index = StringListIndexOf(head,head[VALUE]);
        if(index >= 0)
        {
            StringListRemove(list,head[VALUE]);
            head = list;
        }
        head = (char**)head[NEXT_NODE];
    }
}

/* -----------DONE----------- Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, char* before, char* after)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListReplaceInStrings";
        return;
    }
    else if(IsNull(before) || IsNull(after))
    {
        std::cerr<<"One of string is null in StringListReplaceInStrings";
        return;
    }
    else if(strcmp(before,after) == 0)
    {
        return;
    }

    char** head = list;
    while(head != nullptr)
    {
        int headIndex = -1;
        int index = StringListIndexOf(head,before);

        if(index < 0)
        {
            return;
        }

        while(headIndex != index)
        {
            head = (char**)head[NEXT_NODE];
            ++headIndex;
        }

        head[VALUE] = after;
    }
}

/* -----------DONE----------- Sorts the list of strings in ascending order */
void StringListSort(char** list)
{
    if(IsNull(list))
    {
        std::cerr<<"List is null in StringListSort"<<std::endl;
        return;
    }

    char** currentNode;
    char** minString;
    for(char** swapEl = (char**)list[NEXT_NODE]; swapEl[NEXT_NODE] != nullptr; swapEl = (char**)swapEl[NEXT_NODE])
    {
        minString = swapEl;
        currentNode = (char**)swapEl[NEXT_NODE];
        while(currentNode != nullptr)
        {
            if(strcmp(minString[VALUE],currentNode[VALUE]) > 0)
            {
                minString = currentNode;
            }
            currentNode = (char**)currentNode[NEXT_NODE];
        }
        Swap(minString,swapEl);
    }
}

void Swap(char** firstEl, char** secEl)
{
    if(IsNull(firstEl) || IsNull(secEl))
    {
        std::cerr<<"Element is null in Swap";
        return;
    }
    if(*firstEl == *secEl)
    {
        return;
    }
    char* tmpEl = *firstEl;
    *firstEl = *secEl;
    *secEl = tmpEl;
}

void ShowUI(char** list)
{
    int mode = 1;
    while(mode == 1)
    {
        int option = -1;
        std::cout<<std::endl<<" (1)Add String\n"
                              " (2)Remove string\n"
                              " (3)Remove duplicates\n"
                              " (4)Replace string\n"
                              " (5)Sort list \n"
                              " (6)Get size of list\n"
                              " (7)Get the index position of first exact match string\n"
                              " Choose an option:";
        std::cin>>option;

        switch (option)
        {
            case 1:
            {
                std::cout<<" Write your string: ";
                char *str = (char*)malloc(sizeof(char*));
                std::cin>>str;

                StringListAdd(list,str);
                PrintList(list);

                str = nullptr;
                free(str);
                break;
            }
            case 2:
            {
                std::cout<<" Write string to delete: ";
                char *str = (char*)malloc(sizeof(char*));
                std::cin>>str;

                StringListRemove(list,str);
                PrintList(list);

                str = nullptr;
                free(str);
                break;
            }
            case 3:
            {
                StringListRemoveDuplicates(list);
                PrintList(list);
                break;
            }
            case 4:
            {
                std::cout<<" Write string to replace: ";
                char *str = (char*)malloc(sizeof(char*));
                std::cin>>str;

                std::cout<<"Write your new string: ";
                char *newStr = (char*)malloc(sizeof(char*));
                std::cin>>newStr;

                StringListReplaceInStrings(list,str,newStr);
                PrintList(list);

                newStr = nullptr;
                str = nullptr;
                free(str);
                free(newStr);
                break;
            }
            case 5:
            {
                StringListSort(list);
                PrintList(list);
                break;
            }
            case 6:
            {
                int size = StringListSize(list);
                std::cout<<"Size of list: "<<size<<std::endl;
                break;
            }
            case 7:
            {
                std::cout<<" Write string to find: ";
                char *str = (char*)malloc(sizeof(char*));
                std::cin>>str;

                int index = StringListIndexOf(list,str);
                if(index < 0)
                {
                    std::cout<<"There no such string in the list ";
                }
                else
                {
                    std::cout<<"Index of "<<str<<" in the list: "<<index;
                }
                str = nullptr;
                free(str);
                break;
            }
            default:
            {
                break;
            }
        }
        std::cout<<std::endl<<" Do you want to continue? (1)Yes (smth else)No : ";
        std::cin>>mode;
    }
}