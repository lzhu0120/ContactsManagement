#include <iostream>
using namespace std;

void showMenu() 
{
	cout << "1. Add contact" << endl;
	cout << "2. Show contact" << endl;
	cout << "3. Delete contact" << endl;
	cout << "4. Find contact" << endl;
	cout << "5. Edit contact" << endl;
	cout << "6. Clear all contact" << endl;
	cout << "0. Exit" << endl;
}

void exit() 
{

}

int main() 
{

	int options = 0;
	while (true) 
	{
		showMenu();
		cin >> options;
		switch (options)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "Exiting" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
	    }
	}
	system("pause");
	return 0;
}