/*
 * Name:		Hissouna Hassan Ballah
 * Class:		2nd Class
 * Department:	Computer Engineering
*/

#include <iostream>
#include <string>
using namespace std;
class contact{
	private:
		string name, family, phone, gender, email, address;
	public:
		contact *next;
		contact(){}; //constructor without any parameter
		contact(string name, string phone, string family, string email,string gender, string address){
			this -> name = name ; this -> family = family ; this -> phone = phone; this -> gender = gender; this -> address = address ; this -> email = email ; next = NULL;
		}
		//geting the name of contact
		string getName(){
			return name;
		}
		//geting the familly name of contact
		string getFamily(){
			return family;
		}
		//geting the email of contact
		string getEmail(){
			return email;
		}
		//geting the phonenumber of contact
		string getPhone(){
			return phone;
		}
		//geting the Gender of contact
		string getGender(){
			return gender;
		}
		//geting the address of contact
		string getAddress(){
			return address;
		}

		//seting information for a contact
		void setContact(string name, string phone, string family, string email, string gender, string address){
			this -> name = name; this -> family = family; this -> phone = phone; this -> email = email; this -> gender = gender; this -> address = address;
		}

		//printing all of information for a contact
		void getContact(){
			cout << name << "   " << family << "   " << phone << "   " << address << "   " << gender << "   " << email << endl;
		}
};
class contactsList{
	private:
		contact *head;
		contact *last;
		int size;
	public:
		contactsList();
		contact* find(string);
		void add(string, string, string, string, string, string);
		void deleteContact(string);
		contact* findContact(string);
		void showContacts();
	};

//consructor for contactsList without any paramater 
contactsList::contactsList(){
	head = NULL ; last = NULL; size = 0;
}

//add contact to end of contactslist
void contactsList::add(string name, string phone, string family, string email, string gender, string address){
	contact* new_contact = new contact(name, family, phone, email, gender, address);
	if (last == NULL || head == NULL){
		head = new_contact;
		last = new_contact;
	}
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
//searching list by any Term
contact* contactsList::find(string serachQuery ){
	contact* n = NULL;
	for( n = head ; n != NULL ; n = n->next)
		if (n -> getName() == serachQuery || n -> getFamily() == serachQuery || ( n -> getName() + " " + n -> getFamily() ) == serachQuery || n -> getEmail() == serachQuery || n -> getAddress() == serachQuery || n -> getGender() == serachQuery) {
			return n;
		}
	return n;
}

//printing founded contact in list
contact* contactsList::findContact(string serachQuery){
	contact* f = find(serachQuery);
	if (f == NULL){
		cout << "\n\nNot found!" << endl;
	}
	else {
		cout << "\n\n------------------------------------" << endl;
		f -> getContact();
		cout << "-----------------------------------" << endl;
	}
	return f;
}

//deleting contact in list
void contactsList::deleteContact(string serachQuery){
	if( head->getName() == serachQuery || head->getFamily() == serachQuery || ( head->getName() + " " + head->getFamily() ) == serachQuery )  {
		contact* temp = head->next;
		delete head;
		head = temp;
		size--;
		return;
	}
	contact* temp = head;
	if( temp->next == NULL ){
		 cout << "\n\nNot found!" << endl;
		 return;
	}
	while(temp -> next -> getName() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
		temp = temp -> next;
		if ( temp -> next == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
    if(temp != NULL){
	contact* temp2 = temp -> next;
	temp -> next = temp2 -> next;
	delete temp2;
	if( last -> getName() == serachQuery || last -> getFamily() == serachQuery || ( last->getName() + " " + last->getFamily() ) == serachQuery ) {
		last = temp;
	}
	size--;
	}
}

//printing all of contacts in the list
void contactsList::showContacts(){
	cout << "\n\n" << endl;
	if (last == NULL || head == NULL){
		throw "No contacts!";
	}
	int l = 1;
	for (contact* n = head; n != NULL ; n = n -> next) {
		cout << l << ") "; l++;
		n -> getContact();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
contact* f;
bool menu(); //prototype for printing menu
int main(){
	int n;
	string name, family, phone, address, email, gender, search;
	contactsList a;
	while(menu()){
		cout << "\nYor choice: ";
		cin >> n;
		switch(n){
			case 1:
				cout << "\nName: ";
				cin >> name;
				cout << "Family: ";
				cin >> family;
				cout << "Phone: ";
				cin >> phone;
				cout << "Gender: ";
				cin >> gender;
				cout << "E-Mail: ";
				cin >> email;
				cout << "Address: ";
				cin >> address;
				a.add(name,family,phone,email,gender,address);
				break;
			case 2:
				a.showContacts();
				break;
			case 3:
				cout << "\nSearch a Contact Using any Term: ";
				cin >> search;
				f = a.findContact(search);
			case 4:
				cout << "Name (And / Or Family Name) of the Contact to Delete: ";
				cin >> search;
			case 5:
				a.deleteContact(search);

			case 6:
				exit(1);
			default:
				break;
		}
	}
	return 0;
}
bool menu(){
	cout << "\n\nMain Menu:" << endl;
	cout << "==========" << endl;
	cout << "\n\n1- Add a Contact" << endl;
	cout << "2- Show Contacts" << endl;
	cout << "3- Search a Contact" << endl;
	cout << "4- Delete a Contact" << endl;
	cout << "5- Merge Two Contacts" << endl;
	cout << "6- Exit" << endl;
	cout << "==============================\n" << endl;
	return true;
}
