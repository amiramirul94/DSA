#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;




class Contact{
	
	private:
		char name[30];
		int phoneNumber;
		char email[30];
		int id;
		
	public:
		Contact(){
		};
		Contact(char* n, int number, char* email);
		void setName(char* n);
		void setPhone(int n);
		void setEmail(char* email);
		void setId(int i);
		char* getName();
		int getPhone();
		char* getEmail();
		int getId();
};


Contact::Contact(char* n, int number, char* e)
{
	strcpy(name,n);
	phoneNumber= number;
	strcpy(email, e);
}

void Contact::setName(char* n)
{
	strcpy(name, n);
	
}

void Contact::setPhone(int n)
{
	phoneNumber = n;
}

void Contact::setEmail(char* e)
{
	strcpy(email,e);
} 

void Contact::setId(int i)
{
	id=i;
}


char* Contact::getName()
{
	return name;
}


char* Contact::getEmail()
{
	return email;
}


int Contact::getPhone()
{
	return phoneNumber;
}

int Contact::getId()
{
	return id;
}




struct ContactNode{
	
	Contact contactNode;
	struct ContactNode* next;
};



class ContactList{
	private:
		ContactNode node;
		ContactNode* head;
		
	public:
		ContactList()
		{
			head=NULL;
		}
		
		~ContactList();
		
		void addContact(Contact contact);
		void displayContact() const;
		void deleteContact(int num);
		void writeFile();
		
		
	
};

void ContactList::addContact(Contact contact)
{
	ContactNode *newContact;
	ContactNode *nodePtr;
	int i=0;
	newContact = new ContactNode;
	newContact->contactNode= contact;
	newContact->next=NULL;
	
	if(!head)
	{
		head= newContact;
	}else{
		
		nodePtr = head;
		
		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
			i++;
		}
		
		contact.setId(i);
		nodePtr->next= newContact;
	}
	
	
}

void ContactList::displayContact() const
{
	ContactNode* contactPtr;
	
	contactPtr = head;
	int i=0;
	while(contactPtr)
	{
		cout<<"Contact id :"<<i<<endl;
		cout<<"Contact name :"<<contactPtr->contactNode.getName()<<endl;
		cout<<"Phone number :"<<contactPtr->contactNode.getPhone()<<endl;
		cout<<"email :"<<contactPtr->contactNode.getEmail()<<endl;
		cout<<endl;
		cout<<endl;		
		
		contactPtr= contactPtr->next;	
		i++;
	}

}

void ContactList::deleteContact(int num)
{
	ContactNode *previousContact;
	ContactNode *currentContact;
	
	currentContact = head;
	
	for(int i=0; i<num; i++)
	{
		previousContact = currentContact;
		currentContact = currentContact->next;
	}
	
	previousContact->next = currentContact->next;
	delete currentContact;
	
}

void ContactList::writeFile()
{
	
	ContactNode* contactPtr;
	ofstream outFile;
	outFile.open("contact.txt");
	
	contactPtr = head;
	int i=1;
	while(contactPtr)
	{
	
		outFile<<contactPtr->contactNode.getName()<<endl;
		outFile<<contactPtr->contactNode.getPhone()<<endl;
		outFile<<contactPtr->contactNode.getEmail()<<endl;
		
		
		contactPtr= contactPtr->next;	
		
	}
	
}



//Function Prototype
bool newContact(ContactList* );

void readFile(ContactList* );




int main()
{
	//Contact List	
	ContactList* myContacts = new ContactList();
	readFile(myContacts);  //Read contact list from info
	bool continueAdd=true;
	cout<<"===========My Info=========="<<endl;
	Contact contact("zafran",0137446251,"muhammad.zafran@outlook.com");
	myContacts->addContact(contact);
	myContacts->displayContact();
	
	int choice=0;
	int deleteNo;
	
	

	
	//loop while user wants to continue
	while(choice!=4){
		//menu
		cout<<"1-Add Contact"<<endl;
		cout<<"2-Delete Contact"<<endl;
		cout<<"3-View contacts"<<endl;
		cout<<"4-Exit application"<<endl;
		cin>>choice;
		
		if(choice==1)
		{	
			while(continueAdd)
			{
				continueAdd = newContact(myContacts);
			}
		}else if(choice==2)
		{
			cout<<"Enter contact number to delete";
			cin>>deleteNo;
			myContacts->deleteContact(deleteNo);
		}else if(choice==3)
		{
			myContacts->displayContact();
		}else if(choice==4)
		{
			myContacts->writeFile();
		}
			
	
	
	}
	

	return 0;
	
}



//add new contact
bool newContact(ContactList* myContacts)
{
	char* name;
	int phone;
	int choice;
	char* email;
	Contact contact;
	cout<<"Enter name >> ";
	cin>>name;
	contact.setName(name);
	cout<<"Enter phone number >> ";
	cin>>phone;
	contact.setPhone(phone);
	
	cout<<"Enter email >> ";
	cin>>email;
	
	contact.setEmail(email);
	
	
	//append to contact list
	myContacts->addContact(contact);
	
	cout<<"Continue? 1- Yes 2- No >>";
	cin>>choice;
	
	if(choice==1)
	{
		return true;
	}else if(choice==2)
	{
		return false;	
	}
}

//read from File
void readFile(ContactList* myContact)
{
	ifstream inFile;
	Contact contact;
	int id;
	int phone;
	char name[30];
	char email[30];
	inFile.open("contact.txt");


	while(!inFile.eof())
	{
		
		inFile>>name;
		inFile>>phone;
		inFile>>email;
		contact.setId(id);
		contact.setName(name);
		contact.setPhone(phone);
		contact.setEmail(email);
		
		myContact->addContact(contact);
		cout<<id<<endl;
		cout<<name<<endl;
		cout<<phone<<endl;
		cout<<email<<endl;
	}

	
}






