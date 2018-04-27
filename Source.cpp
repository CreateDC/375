//Program Name: User Interface
//Programmer Name(s): Chris Schram
//Description: This includes the user being able to login...
//Date Created: 4/18/2018
//

   
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <sstream> //stringstream
#include <iomanip> //set width used for 00001

using namespace std;

class Item
{
public:
	
	string item_name, item_id, category, vendor_code, description;

	int quantity = 10000;
	int warehouse;


};
class User
{
public:
	string id;
	string firstName;
	string lastName;
	string username;
	string password;
	string streetAddress;
	string city;
	string state;
	string zip;
	string billingStreet;
	string billingCity;
	string billingState;
	string billingZip;
	vector <Item> cart;
};
class Manager
{
public:
	void add_item()
	{
		Item tem;
		char category;
		do {

			cout << "Please enter new item name" << endl;
			cin >> tem.item_name;
			if (tem.item_name.length() > 20 || tem.item_name.length() == 0)
			{
				cout << "Invalid input either exceeded 20 chars or empty" << endl;
			}
		} while (tem.item_name.length() > 20 || tem.item_name.length() == 0);


		cout << "Choose category" << endl
			<< "A. Electronics " << endl
			<< "B. Clothing    " << endl
			<< "C. Gardening   " << endl
			<< "D. Food        " << endl
			<< "E. Instrument  " << endl;

		cin >> category;

		if (category == ('A' || 'a'))
		{
			tem.category = "Electronics";
		}
		else if
			(category == ('B' || 'b'))
		{
			tem.category = "Clothing";
		}

		else if
			(category == ('C' || 'c'))
		{
			tem.category = "Gardening";
		}
		else if
			(category == ('D' || 'd'))
		{
			tem.category = "Food";
		}
		else if
			(category == ('E' || 'e'))
		{
			tem.category = "Instrument";
		}

		cout << "Enter item description";

		cin >> tem.description;

		catalog.push_back(tem);
	}
	void delete_item()
	{
		int delitem;
		do {
			cout << "Which item would you like to delete: " << endl;
			for (int i = 0; i < catalog.size(); i++)
			{
				cout << i << ". " << catalog[i].item_name << endl;
			}
			cin >> delitem;
			if (delitem>catalog.size())
			{
				cout << "Invalid choice" << endl;
			}

		} while (delitem > catalog.size());

		if (catalog[delitem].quantity != 0)
		{
			catalog.erase(catalog.begin() + delitem);
		}


	}
	void view_iteminfo()
	{
		int vItem;

		cout << "Which item would you like to view: " << endl;
		for (int i = 0; i < catalog.size(); i++)
		{
			cout << i << ". " << catalog[i].item_name << endl;
		}
		cin >> vItem;

		cout << catalog[vItem].item_name << endl;
		cout << catalog[vItem].description << endl;
		cout << catalog[vItem].quantity << endl;
		cout << catalog[vItem].warehouse << endl;
	}

private:

	string id;
	string password;
	vector <Item> catalog;

};



string changeUsername(const User& userAccount);
string changePassword(const User& userAccount);

void getInfo(ifstream& user, User& userAccount);
void saveChanges(ofstream& user, User& userAccount);

void login();
void createAccount(ofstream&);
inline bool doesFileExist(string);

void AccountManagement();


int main()
{
	char menuOption; //can be used for menu options as well as field entries
	string username, password;
	ifstream companyFile;
	//cannot have two files open at once, so close after using or else will erase file
	ofstream user;
	//remove("FileName.txt"); can use this to remove files

	do {
		cout << "*************************************" << "\n"
			<< "    Mo's Company - User Interface" << "\n"
			<< "*************************************" << "\n";

		cout << "A.) Login" << "\n"
			<< "B.) Create New Account" << "\n"
			<< "C.) Account Management" << "\n"
			<< "X.) Exit Application" << "\n";
		cin >> menuOption;
		menuOption = toupper(menuOption);
		while ((menuOption != 'A') && (menuOption != 'B') && (menuOption != 'C') && (menuOption != 'X')) { cout << "You've entered an invalid command" << "\n"; cin >> menuOption; };

		if (menuOption == 'A')
		{
			cout << "*************************************" << "\n"
				<< "    Mo's Company - Login" << "\n"
				<< "*************************************" << "\n";
			login();
		}
		else if (menuOption == 'B')
		{
			cout << "*************************************" << "\n"
				<< "    Mo's Company - Create an Account" << "\n"
				<< "*************************************" << "\n";
			createAccount(user);

		}
		else if (menuOption == 'C')
		{
			cout << "*************************************" << "\n"
				<< "    Mo's Company - Account Management" << "\n"
				<< "*************************************" << "\n";
			AccountManagement();

		}
	} while (menuOption != 'X');
	{
		cout << "Goodbye." << "\n";
	}

	system("pause");
	return NULL;
}

void getItemInfo() {

	/*
	struct Item {

	string id;
	string name;
	string description;
	string price;
	string reorderQuantity;
	string reorderPoint;
	string vendorCode;
	string distribFields;

	Item(string ID,
	string Name,
	string Description,
	string Price,
	string ReorderQuantity,
	string ReorderPoint,
	string VendorCode,
	string DistribFields) {
		id = ID,
			name = Name,
			description = Description,
			price = Price,
			reorderQuantity = ReorderQuantity,
			reorderPoint = ReorderPoint,
			vendorCode = VendorCode,
			distribFields = DistribFields;
	}

	int getID() {
		return stoi(id);
	}
	string getName() {
		return name;
	}
	string getDescript() {
		return description;
	}
	string getPrice() {
		return price;
	}
	string getReorderQ() {
		return reorderQuantity;
	}
	string getReorderP() {
		return reorderPoint;
	}
	string getVendorCode() {
		return vendorCode;
	}
	string getDistFields() {
		return distribFields;
	}
	



	vector<Item> items;
	vector<Item>::iterator itr;
	string item;
	string id;
	string name;
	string description;
	string price;
	string reorderQuantity;
	string reorderPoint;
	string vendorCode;
	string distribFields;
	string space;
	ifstream inCatalog;
	int selection, amount;
	int num = 1;

	inCatalog.open("Catalog.txt");

	while (!inCatalog.eof()) {
	getline(inCatalog, id);
	getline(inCatalog, name);
	getline(inCatalog, description);
	getline(inCatalog, price);
	getline(inCatalog, reorderQuantity);
	getline(inCatalog, reorderPoint);
	getline(inCatalog, vendorCode);
	getline(inCatalog, distribFields);
	getline(inCatalog, space);

	Item item(id, name, description, price, reorderQuantity, reorderPoint, vendorCode, distribFields);
	items.push_back(item);
	}
	*/

void login() {
	//check if mo, then check if it exists in the files
	//if mo, check if password is "Boss"
	//else check to see if the password matches the existing user's password in their file
	string username, password, userFile, fromFile, userFileCopy;
	ofstream userOut, fileCopy;
	ifstream userIn;
	vector<string> fileContents;
	char menuOption;
	bool overCharLimit = false;
	bool usernameTaken = false;
	bool mo = false;
	bool passwordCorrect = false;
	do {
		cout << "Please enter your username" << "\n";
		cin >> username;
		if (username == "Mo")
		{
			cout << "Hey Mo, enter your password." << "\n";
			cin >> password;
			while (password != "Boss")
			{
				cout << "Sorry \"Mo\", wrong password..." << "\n";
				cin >> password;
			}

			{
				cout << "Welcome back, Mo!" << "\n";
				usernameTaken = true;
				mo = true;
				//can be taken to manager functionality from here.
			}
		}
		else if (doesFileExist(username))
		{
			//no file is open
			usernameTaken = true;
			userFile = username + ".txt";

			userIn.open(userFile);
			while (!userIn.eof())
			{
				getline(userIn, fromFile);
				fileContents.push_back(fromFile);
			}
			userIn.close();
			//for (int i = 0; i < fileContents.size()-1; i++) cout << fileContents[i] << "\n";
			userOut.open(userFile);
			for (int i = 0; i < fileContents.size() - 1; i++) userOut << fileContents[i] << "\n";
			userOut.close();
		}
		else
		{
			cout << "Username not found or incorrect" << "\n";
			usernameTaken = false;
		}
	} while (!usernameTaken);
	if (!mo)
	{
		do {
			cout << "Please enter your password" << "\n";
			cin >> password;
			if (password == fileContents[4])passwordCorrect = true;
			else {
				cout << "You've entered a wrong password" << "\n";
			}
		} while (!passwordCorrect);
		cout << "Welcome " << fileContents[1] << " " << fileContents[2] << "\n";

		//LOGIN
		//After logging in, the user can be sent to other parts of the interface from here
		do {
			cout << "*************************************" << "\n"
				<< "    Mo's Company - User Interface" << "\n"
				<< "*************************************" << "\n";

			cout << "A.) Place an order" << "\n"
				<< "B.) Account info" << "\n"
				<< "X.) Logout" << "\n";
			cin >> menuOption;
			menuOption = toupper(menuOption);
			while ((menuOption != 'A') && (menuOption != 'B') && (menuOption != 'X')) { cout << "You've entered an invalid command" << "\n"; cin >> menuOption; };

		} while (menuOption != 'X');
		cout << fileContents[1] << ", you have been logged out." << "\n";
		fileContents.clear();//empties this out to be used for the next user

	}

}

void createAccount(ofstream& userOut)
{
	string entry, firstName, lastName, username, password, shipStreet, shipCity, shipState, billStreet, billCity, billState, fromFile;
	vector<string> fileContents;
	ifstream companyFile;
	ofstream rewriteToFile;
	int shipZip = 123456789; int billZip = 123456789;
	char option;
	int userID = 10001;
	bool overCharLimit = false;
	bool usernameTaken = false;
	do {
		cout << "Please enter your new username (30 characters or less, no spaces)" << "\n";
		cin >> username;
		if (username.length() > 30)
		{
			overCharLimit = true;
			cout << "That is above the character limit" << "\n";
		}
		else if (doesFileExist(username))
		{
			cout << "That username is taken" << "\n";
			usernameTaken = true;
		}
		else
		{
			overCharLimit = false;
			usernameTaken = false;
		}
	} while (overCharLimit || usernameTaken);

	do {
		cout << "Please enter your password (30 characters or less, no spaces)" << "\n";
		if (password.length() > 30)cout << "That is above the character limit" << "\n";
		cin >> password;
	} while (password.length() > 30);

	do {
		cout << "Please enter your first name (15 characters or less)" << "\n";
		if (firstName.length() > 15)cout << "That is above the character limit" << "\n";
		cin >> firstName;
	} while (firstName.length() > 15);
	do {
		cout << "Please enter your last name (15 characters or less)" << "\n";
		if (lastName.length() > 15)cout << "That is above the character limit" << "\n";
		cin >> lastName;
	} while (lastName.length() > 15);

	do {
		cout << "Please enter your Shipping Street Address (20 characters or less)" << "\n";
		if (shipStreet.length() > 20)cout << "That is above the character limit" << "\n";
		cin.ignore();
		getline(cin, shipStreet);
	} while (shipStreet.length() > 20);

	do {
		cout << "Please enter your Shipping City (20 characters or less)" << "\n";
		if (shipCity.length() > 20)cout << "That is above the character limit" << "\n";
		cin.ignore();
		getline(cin, shipCity);
	} while (shipCity.length() > 20);

	do {
		cout << "Please enter your Shipping State (2 characters or less)" << "\n";
		if (shipState.length() > 2)cout << "That is above the character limit" << "\n";
		cin >> shipState;
	} while (shipState.length() > 2);

	do {
		cout << "Please enter your Shipping Zip code (9 digits or less)" << "\n";
		if (shipZip > 999999999 || shipZip < 100000000)cout << "That is above the character limit" << "\n";
		cin >> shipZip;
	} while (shipZip > 999999999 || shipZip < 100000000);

	entry = username; //turn their username into a file!
	entry.append(".txt");
	//id = ?
	companyFile.open("CompanyInfo.txt");
	getline(companyFile, fromFile);
	stringstream stringToInt(fromFile);
	stringToInt >> userID; userID++;//this new employee is one ID higher.
	companyFile.close(); //always close asap
	rewriteToFile.open("CompanyInfo.txt");
	rewriteToFile << userID;
	rewriteToFile.close();
	userOut.open(entry); //creates and opens new file
	userOut << setfill('0') << setw(5) << userID << "\n" << firstName << "\n" << lastName << "\n" << username << "\n" << password
		<< "\n" << shipStreet << "\n" << shipCity << "\n" << shipState << "\n" << shipZip << "\n";

	cout << "Is your billing address the same as your shipping? (type 'y' or 'n')" << "\n";
	cin >> option;
	option = toupper(option);
	while ((option != 'Y') && (option != 'N'))
	{
		cout << "You've entered an invalid command" << "\n"; cin >> option; option = toupper(option);
	}
	if (option == 'Y')
	{
		billStreet = shipStreet;
		billCity = shipCity;
		billState = shipState;
		billZip = shipZip;
		cout << "You've created your account successfully! Now you may log in." << "\n";
	}
	else if (option == 'N')
	{
		do {
			cout << "Please enter your Billing Street Address (20 characters or less)" << "\n";
			if (billStreet.length() > 20)cout << "That is above the character limit" << "\n";
			cin.ignore();
			getline(cin, billStreet);
		} while (billStreet.length() > 20);

		do {
			cout << "Please enter your Billing City (20 characters or less)" << "\n";
			if (billCity.length() > 20)cout << "That is above the character limit" << "\n";
			cin.ignore();
			getline(cin, billCity);
		} while (billCity.length() > 20);

		do {
			cout << "Please enter your Billing State (2 characters or less)" << "\n";
			if (billState.length() > 2)cout << "That is above the character limit" << "\n";
			cin >> billState;
		} while (billState.length() > 2);

		do {
			cout << "Please enter your Billing Zip code (9 digits or less)" << "\n";
			if (billZip > 999999999 || shipZip < 100000000)cout << "That is above the character limit" << "\n";
			cin >> billZip;
		} while (billZip > 999999999 || shipZip < 100000000);
		cout << "You've created your account successfully! Now you may log in." << "\n";

	}

	userOut << billStreet << "\n" << billCity << "\n" << billState << "\n" << billZip << "\n";
	userOut.close();

}


inline bool doesFileExist(string name) {
	struct stat buffer;
	name.append(".txt");
	return (stat(name.c_str(), &buffer) == 0);
}

void AccountManagement()
{
	char option = '$';


	ifstream user("Ranch.txt");
	User userAccount;


	string newUsername;
	string newPassword;
	string oldUsername;
	string oldPassword;
	bool validOption = false;
	getInfo(user, userAccount);
	oldUsername = userAccount.username;
	oldPassword = userAccount.password;
	while (option != 'X')
	{
		cout << "A.) Change Username" << endl;
		cout << "B.) Change Password" << endl;
		cout << "C.) View Previous Orders" << endl;
		cout << "D.) View Coupons/Rewards" << endl << endl;
		cout << "X.) Back To Main Menu" << endl;
		cin >> option;

		option = toupper(option);

		switch (option)
		{
		case 'A':
			newUsername = changeUsername(userAccount);
			userAccount.username = newUsername;
			break;

		case 'B':
			newPassword = changePassword(userAccount);
			userAccount.password = newPassword;
			break;
		case 'C':
			// view previous orders
			break;
		case 'D':
			// coupons
			break;
		case 'X':
			// back 2 menu
			break;
		default:
			cout << "Invalid selection." << endl << endl << endl << endl;
			break;
		}
	}
	ofstream saveUserChanges;
	string oldFileName = oldUsername;
	string newFileName;
	oldFileName.append(".txt");

	char filename[100];
	strcpy_s(filename, oldFileName.c_str());

	if (oldUsername != newUsername && newUsername != "")
	{
		newFileName = newUsername;
		newFileName.append(".txt");
		remove(filename);
		saveUserChanges.open(newFileName);
	}
	else
	{
		saveUserChanges.open(oldFileName);
	}
	saveChanges(saveUserChanges, userAccount);
	return;
}

void getInfo(ifstream& user, User& userAccount)
{
	string info;
	user >> info;
	userAccount.id = info;
	user >> info;
	userAccount.firstName = info;
	user >> info;
	userAccount.lastName = info;
	user >> info;
	userAccount.username = info;
	user >> info;
	userAccount.password = info;
	user.ignore();
	getline(user, info);
	userAccount.streetAddress = info;
	user >> info;
	userAccount.city = info;
	user >> info;
	userAccount.state = info;
	user >> info;
	userAccount.zip = info;
	user.ignore();
	getline(user, info);
	userAccount.billingStreet = info;
	user >> info;
	userAccount.billingCity = info;
	user >> info;
	userAccount.billingState = info;
	user >> info;
	userAccount.billingZip = info;

	user.close();
}

void saveChanges(ofstream& user, User& userAccount)
{
	string info;
	info = userAccount.id;
	user << info << endl;
	info = userAccount.firstName;
	user << info << endl;
	info = userAccount.lastName;
	user << info << endl;
	info = userAccount.username;
	user << info << endl;
	info = userAccount.password;
	user << info << endl;
	info = userAccount.streetAddress;
	user << info << endl;
	info = userAccount.city;
	user << info << endl;
	info = userAccount.state;
	user << info << endl;
	info = userAccount.zip;
	user << info << endl;
	info = userAccount.billingStreet;
	user << info << endl;
	info = userAccount.billingCity;
	user << info << endl;
	info = userAccount.billingState;
	user << info << endl;
	info = userAccount.billingZip;
	user << info << endl;

	user.close();
}


string changeUsername(const User& userAccount)
{

	string newUsername, confirmPassword;

	cout << "Enter your new username: ";
	cin >> newUsername;
	cout << "Enter your password: ";
	cin >> confirmPassword;

	if (confirmPassword == userAccount.password)
	{
		cout << "Change successful!" << endl;
		return newUsername;
	}
	else
	{
		cout << "Change unsuccessful, password did not match." << endl;
		return userAccount.username;
	}
}
string changePassword(const User& userAccount)
{
	int count = 0;

	string newPassword, confirmPassword;
	cout << "Enter your new password: ";
	cin >> newPassword;
	cout << "Enter your password: ";
	cin >> confirmPassword;

	if (confirmPassword == userAccount.password)
	{
		cout << "Change successful!" << endl;
		return newPassword;
	}
	else
	{
		cout << "Change unsuccessful, password did not match." << endl;
		return userAccount.password;
	}
}