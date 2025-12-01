#include <iostream>

using namespace std;

static int counter = 0;

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

        // only getter/setters...
        void updateState(item_state newState) { data.state = newState ; }
        
        void setName(string newName) { data.name = newName ; }
        const char* getName() { return data.name.c_str() ; }
        
        int getID() { return data.ID; }
        item_state getState() { return data.state ; }
        
        CTodoItem* getNext() { return pNext ; };
        void setNext(CTodoItem* pNew) { if(pNew == NULL) return ; pNext = pNew ; } 
	
        item_data_t data ; 
        
    private:

        //list stuff...
        CTodoItem* pNext ; 
};

class CTodoList
{
	public:

        CTodoList();
		~CTodoList();

        void addItem(string name);
        void updateItem(int ID, item_state state, string name = "");

        void printList();      

    private:

        void swap(CTodoItem *a, CTodoItem *b);
        void sort();
        void destroy();
        void insertItem(CTodoItem* newItem);

        bool sorted ;

        CTodoItem* pList ;
};

