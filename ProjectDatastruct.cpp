#include<iostream>
#include<string.h>

using namespace std;




class Contact{
	
	private:
		char name[30];
		int phoneNumber;
		char email[30];
		
	public:
		Contact(){
		};
		Contact(char* n, int number, char* email);
		void setName(char* n);
		void setPhone(int n);
		void setEmail(char* email);
		char* getName();
		int getPhone();
		char* getEmail();
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
		
		
	
};

void ContactList::addContact(Contact contact)
{
	ContactNode *newContact;
	ContactNode *nodePtr;
	
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
		}
		
		nodePtr->next= newContact;
	}
	
	
}

void ContactList::displayContact() const
{
	ContactNode* contactPtr;
	
	contactPtr = head;
	int i=1;
	while(contactPtr)
	{
		cout<<"Contact id :"<<i; 
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


bool newContact(ContactList* );

int menu();


int main()
{
	ContactList* myContacts = new ContactList();
	bool continueAdd=true;
	cout<<"===========My Info=========="<<endl;
	Contact contact("zafran",0137446251,"muhammad.zafran@outlook.com");
	myContacts->addContact(contact);
	myContacts->displayContact();
	
	int choice=0;
	int deleteNo;
	
	

	
	while(choice!=4){
		
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
		}
		
		
		
	
	
	}
	

	return 0;
	
}




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




