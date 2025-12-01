#include <iostream>

using namespace std;

static int counter = -1 ; // take constructor into account (list as well)

typedef enum {
	prio = 0, // we want prio always top of list...
	normal, 
	done // and done last... (this works with bubblesort)
}  item_state;

//Not very optimezed struct (mem-usage) but not important for this... (string destroys this anyway...)
typedef struct {
    int ID ; // int ID:8
    item_state state ;
    string name ;
} item_data_t;

class CTodoItem
{
	public:
		CTodoItem()
		{
            pData = new item_data_t;
            pData->ID = counter ; //head will be ID 0
            counter ++; 
            pData->state = normal ;
            pNext = NULL ;
			//printf("item construct!\n");
		}
		~CTodoItem()
        { 
	//		printf("item destruct\n");
            if(pData != NULL) delete pData ;
		}
        
        void swap(CTodoItem *a, CTodoItem *b) 
        { 
            item_data_t* pTemp = a->pData; 
            a->pData = b->pData; 
            b->pData = pTemp; 
        }

        // getters/setters...
        void updateState(item_state newState) { pData->state = newState ; }
        
        void setName(string newName) { pData->name = newName ; }
        const char* getName() { return pData->name.c_str() ; }
        
        int getID() { return pData->ID; }
        item_state getState() { return pData->state ; }
        
        CTodoItem* getNext() { return pNext ; };
        void setNext(CTodoItem* pNew) { if(pNew == NULL) return ; pNext = pNew ; } 

    protected:
        item_data_t* pData ; 

    private:
        //list stuff...
        CTodoItem* pNext ; 
};

class CTodoList : CTodoItem
{
	public:

        CTodoList();
		~CTodoList();

        void addItem(string name);
        void updateItem(int ID, item_state state, string name = "");

        void printList();      

    private:

       // void swap(CTodoItem *a, CTodoItem *b);
        void sort();
        void destroy();
        void insertItem(CTodoItem* newItem);

        bool sorted ;

        CTodoItem* pList ;
};

