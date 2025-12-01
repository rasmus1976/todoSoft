#include "todo.hpp"

CTodoList::CTodoList()
{
    pList = new CTodoItem ;
    sorted = true ;
}

CTodoList::~CTodoList()
{
    if(pList)
    {
        destroy();
        delete pList ;
     //   printf("list destruct\n");
    }
}

void CTodoList::swap(CTodoItem *a, CTodoItem *b) 
{ 
    item_data_t temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
}

//traditinal "bubbleSort".... ugly memcpy in the end...
void CTodoList::sort()
{
    if(sorted) return ;

    CTodoItem* start = pList->getNext();

    int swapped, i; 
    CTodoItem* ptr1; 
    CTodoItem* lptr = NULL; 

    //sanity check...
    if (start == NULL) 
        return; 

    do
    { 
        swapped = 0; 
        ptr1 = start; 

        while (ptr1->getNext() != lptr) 
        { 
            if (ptr1->getState() > ptr1->getNext()->getState()) 
            { 
                swap(ptr1, ptr1->getNext()); 
                swapped = 1; 
            } 
            ptr1 = ptr1->getNext(); 
        } 
        lptr = ptr1; 
    } 
    while (swapped);

    sorted = true ;
}

void CTodoList::addItem(string name)
{
    CTodoItem* pNew = new CTodoItem;
    pNew->setName(name) ;
    insertItem(pNew);
}

void CTodoList::updateItem(int ID, item_state state, string name)
{
    CTodoItem* pTemp = pList->getNext();
    while(pTemp != NULL)
    {
        if(pTemp->getID() == ID)
        {
            pTemp->updateState(state);
            if(name != "") pTemp->setName(name);
           // printf("update ID %d, name %s, newstate %d\n", pTemp->getID(), pTemp->getName(), pTemp->getState());  
            sorted = false ;
            return ;  
        }
        pTemp = pTemp->getNext() ;
    }
    printf("ID not found\n");
}

void CTodoList::printList()
{
    if(!pList) return ; //sanity check... shouldn't be needed but anyway...

    if(!sorted) 
    {
        sort();
    }

    if(pList->getNext()== NULL)
    {
        printf("Empty list\n");
        return ;
    }

  //  int count = 0;
    bool outComp = false ;

    CTodoItem* pTemp = pList->getNext();
    while(pTemp != NULL)
    {
        //printf("%d: %s\n", pTemp->getID(), pTemp->getName(), pTemp->getState());

        //all done?
        if(!outComp && pTemp->getState() == done)
        {
            outComp = true ;
            printf("Finished:\n");
        }

        if(pTemp->getState() == prio)
        {
            printf("%d: %s", pTemp->getID(), pTemp->getName());
            printf(" (prioritized)\n");
        }
        else if(pTemp->getState() == done)
        {       
            printf("%d: %s\n", pTemp->getID(), pTemp->getName());
         //   printf(" (done)\n");
        }
        else 
        {
            printf("%d: %s\n", pTemp->getID(), pTemp->getName());
        }        

        pTemp = pTemp->getNext() ;
    }
}

void CTodoList::destroy()
{
    if(!pList) return ; //sanity check... shouldn't be needed but anyway...

    CTodoItem* pTemp = pList->getNext();
    while(pTemp != NULL)
    {
        CTodoItem* pTempDestroy = pTemp ;
//                printf("ID %d, name %s, state %d\n", pTemp->getID(), pTemp->getName(), pTemp->getState());
        pTemp = pTemp->getNext() ;

        delete pTempDestroy ;
    }
}

void CTodoList::insertItem(CTodoItem* newItem)
{
    CTodoItem* pTemp = pList;
    while(pTemp->getNext() != NULL)
    {
        pTemp = pTemp->getNext() ;
    }
    sorted = false ;
    pTemp->setNext(newItem) ; 
}

