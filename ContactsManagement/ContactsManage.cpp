#include <iostream>
#include <list>
#include <vector>
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

const int MAX = 1000;

struct Person 
{
	string name;
	int gender;
	int age;
	string cell;
	string address;
};

struct ContactList 
{
	Person list[MAX];
	int count;
};

void addPerson(ContactList * contactList) 
{
	if (contactList->count == MAX) 
	{
		cout << "contact list is full" << endl;
	}
	else 
	{
		string name;
		int gender = 0;
		cout << "enter a name" << endl;
		cin >> name;
		contactList->list[contactList->count].name = name;
		cout << "enter the gender: 1 for male and 2 for female" << endl;
		while (true) 
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				contactList->list[contactList->count].gender = gender;
				break;
			}
			else 
			{
				cout << "please enter a correct number" << endl;
			}
		}
		cout << "please enter a age" << endl;
		int age = 0;
		while (true) 
		{
			cin >> age;
			bool isValid = false;
			if (age >= 0 && age <= 130)
			{
				isValid = true;
			}
			else 
			{
				cout << "please enter a valid age" << endl;
			}
			if (isValid) 
			{
				contactList->list[contactList->count].age = age;
				break;
			}
		}
		string cell;
		cout << "please enter a number" << endl;
		while (true) 
		{
			cin >> cell;
			bool isValid = true;
			for (char const& c : cell)
			{
				if (isalpha(c))
				{
					cout << "please enter a valid number" << endl;
					isValid = false;
					break;
				}
			}
			if (isValid) 
			{
				contactList->list[contactList->count].cell = cell;
				break;
			}
		}
		string address;
		cout << "please enter a address" << endl;
		cin >> address;
		contactList->list[contactList->count].address = address;
		contactList->count++;
		cout << "successful" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(ContactList* contactList)
{
	if (contactList->count == 0) 
	{
		cout << "no record" << endl;
		system("pause"); // press any key to continue;
		system("cls");
	}
	else 
	{
		for (int i = 0; i < contactList->count; i++) 
		{
			cout << "name: " << contactList->list[i].name << "\t";
			cout << "gender: " << (contactList->list[i].gender == 1 ? "male":"female") << "\t";
			cout << "age: " << contactList->list[i].age << "\t";
			cout << "cell: " << contactList->list[i].cell << "\t";
			cout << "address: " << contactList->list[i].address << endl;
		}
		system("pause"); // press any key to continue;
		system("cls");
	}
}

// return the index of the person if exists
int exist(ContactList* contactList, string name)
{
	for (int i = 0; i < contactList->count; i++) 
	{
		if (contactList->list[i].name == name) 
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(ContactList* contactList)
{
	string name;
	cout << "please enter the person name to remove" << endl;
	cin >> name;
	int index = exist(contactList, name);
	if (index == -1) 
	{
		cout << "person doesn't exists" << endl;
		system("pause"); // press any key to continue;
		system("cls");
	}
	else 
	{
		for (int i = index; i < contactList->count-1; i++) 
		{
			contactList->list[i] = contactList->list[i + 1];
		}
		contactList->count--;
		cout << "delete successfully" << endl;
		system("pause"); // press any key to continue;
		system("cls");
	}
}

void findPerson(ContactList* contactList)
{
	string name;
	cout << "please enter the person name to search" << endl;
	cin >> name;
	int index = exist(contactList, name);
	if (index == -1) 
	{
		cout << "person doesn't exists" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "name: " << contactList->list[index].name << "\t";
		cout << "gender: " << (contactList->list[index].gender == 1 ? "male" : "female") << "\t";
		cout << "age: " << contactList->list[index].age << "\t";
		cout << "cell: " << contactList->list[index].cell << "\t";
		cout << "address: " << contactList->list[index].address << endl;
		system("pause");
		system("cls");
	}
}

void editPerson(ContactList* contactList)
{
	string name;
	cout << "please enter the person name to edit" << endl;
	cin >> name;
	int index = exist(contactList, name);
	if (index == -1)
	{
		cout << "person doesn't exists" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		string name;
		cout << "please enter name: " << endl;
		cin >> name;
		contactList->list[index].name = name;
		int gender;
		cout << "please enter gender: 1 for male, 2 for female" << endl;
		while (true) 
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				cout << "successful" << endl;
				contactList->list[index].gender = gender;
				break;
			}
			else 
{
				cout << "please enter a valid gender" << endl;

			}
		}
		int age;
		cout << "please enter age: " << endl;
		cin >> age;
		contactList->list[index].age = age;
		string cell;
		cout << "please enter cell: " << endl;
		cin >> cell;
		contactList->list[index].cell = cell;
		string address;
		cout << "please enter address: " << endl;
		cin >> address;
		contactList->list[index].address = address;

		cout << "edit successfully" << endl;
		system("pause");
		system("cls");
	}
}

void removeAll(ContactList* contactList) 
{
	contactList->count = 0;
	cout << "remove successfully" << endl;
	system("pause");
	system("cls");
}

int main() 
{

	int options = 0;
	ContactList contactList;
	contactList.count = 0;
	while (true) 
	{
		showMenu();
		cin >> options;
		switch (options)
		{
		case 1: // 1. Add contact
			addPerson(&contactList);
			break;
		case 2: // 2. Show contact
			showPerson(&contactList);
			break;
		case 3: // 3. Delete contact
			deletePerson(&contactList);
			break;
		case 4: // 4. Find contact
			findPerson(&contactList);
			break;
		case 5: // 5. Edit contact
			editPerson(&contactList);
			break;
		case 6: // 6. Clear all contact
			removeAll(&contactList);
			break;
		case 0:
			cout << "Exiting" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "Please choose a valid option number" << endl;
			break;
	    }
	}
	system("pause");
	return 0;
}