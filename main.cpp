using namespace std;

//#include <list>
#include <string>
#include "todo.hpp"

int main ()
{
	CTodoList list ;
	string cmd = "";
	int nr = 0;

	printf("Welcome to TODO-app.\n");

	printf("Commands Add, Prioritize, Finish, List, Quit>") ;

	cin >> cmd; 

	while(cmd != "")
	{
		if(cmd.size() != 1)
			printf("Invalid input, please try again.\n");
		else
		{
			switch(cmd[0])
			{
				case 'a':
				case 'A': 
					printf("Enter name: ");
					cin >> cmd; 
					list.addItem(cmd);
					break;
				case 'p':
				case 'P': 
					printf("Specify item: ");
					cin >> cmd; 
					nr = atoi(cmd.c_str());
					if(nr > 0)
						list.updateItem(nr, prio);
					else
						printf("Invalid input, please try again.\n");
					break;
				case 'f':
				case 'F': 
					printf("Specify item: ");
					cin >> cmd; 
					nr = atoi(cmd.c_str());
					if(nr > 0)
						list.updateItem(nr, done);
					else 
						printf("Invalid input, please try again.\n");
					break;					
				case 'l':
				case 'L': 
					list.printList() ;
					break;
				case 'q':
				case 'Q': 
					return 0 ;
					break;
				default:
					printf("Invalid input, please try again.\n");
					break ;
			}
		}

		printf("Commands Add, Prioritize, Finish, List>") ;

		cin >> cmd; 
	}

	return 0 ;

}	
