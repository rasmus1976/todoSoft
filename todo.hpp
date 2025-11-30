#include <iostream>

using namespace std;

static int counter = 0;

typedef enum {
	prio = 0, // we want prio always top of list...
	normal, 
	done // and done last... (this works with bubblesort)
}  item_state;

typedef struct item_data {
    int ID ;
    string name ;
	item_state state ;
} item_data;

class CTodoItem
{
	public:
		CTodoItem()
		{
            data.ID = counter ;
            counter ++; //head will get 0 in list:construct() so start inc here..
			data.state = normal ;
            pNext = NULL ;
		//	printf("item construct!\n");
		}
		~CTodoItem()
		{ 
		//	printf("item destruct\n");
		}

        void updateState(item_state newState)
        {
            data.state = newState ;
        }
        void setName(string newName)
        {
            data.name = newName ;
        }
        const char* getName() { 
            return data.name.c_str() ;
        }
        int getID()
        {
            return data.ID;
        }
        item_state getState(){
            return data.state ;
        }
        CTodoItem* getNext() {
            return pNext ;
        };
        void setNext(CTodoItem* pNew) {
            if(pNew == NULL) return ;
            pNext = pNew ;
        };
	
        item_data data ; 
                 
	private:

        //list stuff...
        CTodoItem* pNext ; 
};

class CTodoList //: public CTodoItem
{
	public:

        CTodoList();
		~CTodoList();

        void addItem(string name);

        void updateItem(int ID, item_state state, string name = "");

        void printList();      

    private:

        void swap(CTodoItem *a, CTodoItem *b);

        //traditional "bubbleSort"....
        void sort();

        void destroy();

        bool sorted ;
            
        void insertItem(CTodoItem* newItem);

        CTodoItem* pList ;
};

