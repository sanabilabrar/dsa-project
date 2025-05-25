#include<iostream>
#include<string>
using namespace std;

class node {
public:
    int data;
    string data1;
    node* next, * current;

    node(int value) {
        data = value;
        next = NULL;
    }

    node(string value) {
        data1 = value;
        next = NULL;
    }

    node(node* value) {
        current = value;
        next = NULL;
    }
};

class list {
public:
    node* head, * tail, * head1, * tail1;

    list() {
        head = tail = head1 = tail1 = NULL;
    }

    void prod(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void prod1(string val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void prod2(node* val) {
        node* newnode = new node(val);
        if (head1 == NULL) {
            head1 = tail1 = newnode;
        } else {
            tail1->next = newnode;
            tail1 = newnode;
        }
    }

    void display() {
        node* temp = head;
        if (!temp || !temp->next || !temp->next->next) {
            cout << "Incomplete list!" << endl;
            return;
        }
        cout << temp->data << " -> ";
        temp = temp->next;
        cout << temp->data1 << " -> ";
        temp = temp->next;
        cout << temp->data << " -> ";
        temp=temp->next;
        cout << temp->data1 << " ->NULL" << endl;
    }
};

class operations {
public:
    list l1, l2, l3, master;

         operations() {
     
            l1.prod(1);
            l1.prod1("sugar");
            l1.prod(700);
            l1.prod1("10:00");
            master.prod2(l1.head);

            l2.prod(2);
            l2.prod1("submit");
            l2.prod(2200);
            l2.prod1("10:00");
            master.prod2(l2.head);

            l3.prod(3);
            l3.prod1("gas");
            l3.prod(1500);
            l3.prod1("10:00");
            master.prod2(l3.head);
    }

    void displaymaster() {
        node* temp1 = master.head1;
        while (temp1) {
            cout << temp1->current->data << " -> ";
            temp1 = temp1->next;
        }
        cout << "NULL" << endl;
    }

    void removeFromMaster(node* headToRemove) {
        node* temp = master.head1;
        node* prev = NULL;

        while (temp != NULL) {
            if (temp->current == headToRemove) {
                if (prev == NULL) {
                    master.head1 = temp->next;
                } else {
                    prev->next = temp->next;
                }

                if (temp == master.tail1) {
                    master.tail1 = prev;
                }

                delete temp;
                cout << "List removed from master list." << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "List not found in master list." << endl;
    }

    void show() {
        
        cout << "list 1:" << endl;
        l1.display();

        cout << "list 2:" << endl;
        l2.display();

        cout << "list 3:" << endl;
        l3.display();
    }

    void add() {
        

        int choice;
        cout << "Enter choice (1 = add 1 list, 2 = add 2 lists): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            list l4;
            int m,o;
            string n,p;
            cout<<"enter the data u want enter in the list 4:"<<endl;
			cin>>m>>n>>o>>p;
            cout << "list 4:" << endl;
            l4.prod(m);
            l4.prod1(n);
            l4.prod(o);
            l4.prod1(p);
            l4.display();
            master.prod2(l4.head);
            cout << endl << "master linklist:";
            displaymaster();
            char del;
            cout << "\nDo you want to delete list 4? (y/n): ";
            cin >> del;
            if (del == 'y' || del == 'Y') {
                removeFromMaster(l4.head);
                node* temp = l4.head;
                while (temp != NULL) {
                    node* toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }
                l4.head = l4.tail = NULL;
            }

            cout << "Updated Master linked list: ";
            displaymaster();
             int price1=0,price2=0,price3=0,price4=0;
      node*temp=l1.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price1=temp->next->next->data;
	  	
		  }	
	temp=l2.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price2=temp->next->next->data;
	  	
		  }	
		temp=l3.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price3=temp->next->next->data;
	  	
		  }	
		  temp=l4.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price4=temp->next->next->data;
	  	
		  }	
	cout<<"price of list 1: "<<price1<<endl;
	cout<<"price of list 2: "<<price2<<endl;
	cout<<"price of list 3: "<<price3<<endl;
	cout<<"price of list 4: "<<price4<<endl;
	if(price1>price2&&price1>price3&&price1>price4)
	{
		cout<<"list 1 has the greatest expense "<<price1<<endl;
	}
	else if(price2>price1&&price2>price3&&price2>price4)
	{
		cout<<"list 2 has the greatest expense "<<price2<<endl;
	}
	else if(price3>price1&&price3>price2&&price3>price4)
	{
		cout<<"list 3 has the greatest expense "<<price3<<endl;
	}
	else if(price4>price1&&price4>price2&&price4>price3)
	{
		cout<<"list 4 has the greatest expense "<<price4<<endl;
	}
            break;
        }
        case 2: {
            list l4, l5;
             int m,o,a,c;
            string n,p,b,d;
            cout<<"enter the data u want enter in the list 4:"<<endl;
			cin>>m>>n>>o>>p;
            cout << "list 4:" << endl;
            l4.prod(m);
            l4.prod1(n);
            l4.prod(o);
            l4.prod1(p);
            master.prod2(l4.head);
            l4.display();
            cout<<"enter the data u want enter in the list 5:"<<endl;
            cin>>a>>b>>c>>d;
            cout << "list 5:" << endl;
            l5.prod(a);
            l5.prod1(b);
            l5.prod(c);
            l5.prod1(d);
            l5.display();
            master.prod2(l5.head);
            cout << endl << "master linklist:";
            displaymaster();

            char del;
            cout << "\nDo you want to delete list 4? (y/n): ";
            cin >> del;
            if (del == 'y' || del == 'Y') {
                removeFromMaster(l4.head);
                node* temp = l4.head;
                while (temp != NULL) {
                    node* toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }
                l4.head = l4.tail = NULL;
            }

            cout << "\nDo you want to delete list 5? (y/n): ";
            cin >> del;
            if (del == 'y' || del == 'Y') {
                removeFromMaster(l5.head);
                node* temp = l5.head;
                while (temp != NULL) {
                    node* toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }
                l5.head = l5.tail = NULL;
            }

            cout << "Updated Master linked list: ";
            displaymaster();
             int price1=0,price2=0,price3=0,price4=0,price5=0;
      node*temp=l1.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price1=temp->next->next->data;
	  	
		  }	
	temp=l2.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price2=temp->next->next->data;
	  	
		  }	
		temp=l3.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price3=temp->next->next->data;
	  	
		  }	
		  temp=l4.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price4=temp->next->next->data;
	  	
		  }	
		   temp=l5.head;
	  if(temp&&temp->next&&temp->next->next)
	  {
	  	price5=temp->next->next->data;
	  	
		  }	
	cout<<"price of list 1: "<<price1<<endl;
	cout<<"price of list 2: "<<price2<<endl;
	cout<<"price of list 3: "<<price3<<endl;
	cout<<"price of list 4: "<<price4<<endl;
	cout<<"price of list 5: "<<price5<<endl;
	if(price1>price2&&price1>price3&&price1>price4&&price1>price5)
	{
		cout<<"list 1 has the greatest expense "<<price1<<endl;
	}
	else if(price2>price1&&price2>price3&&price2>price4&&price2>price5)
	{
		cout<<"list 2 has the greatest expense "<<price2<<endl;
	}
	else if(price3>price1&&price3>price2&&price3>price4&&price3>price5)
	{
		cout<<"list 3 has the greatest expense "<<price3<<endl;
	}
	else if(price4>price1&&price4>price2&&price4>price3&&price4>price5)
	{
		cout<<"list 4 has the greatest expense "<<price4<<endl;
	}
		
	else if(price5>price1&&price5>price2&&price5>price3&&price5>price4)
	{
		cout<<"list 5 has the greatest expense "<<price5<<endl;
            break;
        }}
        default:
            {
			cout << "wrong operation" << endl;
            break;}
        }
    }

    void del(int option) {

        node* dellist = NULL;
        switch (option) {
        case 1:
            dellist = l1.head;
            removeFromMaster(l1.head);
            l1.head = l1.tail = NULL;
            break;
        case 2:
            dellist = l2.head;
            removeFromMaster(l2.head);
            l2.head = l2.tail = NULL;
            break;
        case 3:
            dellist = l3.head;
            removeFromMaster(l3.head);
            l3.head = l3.tail = NULL;
            break;
        default:
            cout << "invalid choice:" << endl;
            return;
        }

        while (dellist != NULL) {
            node* todelete = dellist;
            dellist = dellist->next;
            delete todelete;
        }

        cout << "List " << option << " deleted successfully" << endl;

        if (l1.head != NULL) {
            cout << "list 1:" << endl;
            l1.display();
        }
        if (l2.head != NULL) {
            cout << "list 2:" << endl;
            l2.display();
        }
        if (l3.head != NULL) {
            cout << "list 3:" << endl;
            l3.display();
        }

        cout << "Updated Master linked list: ";
        displaymaster();
    }

    void greaterexpense() {

        int price1 = 0, price2 = 0, price3 = 0;
        node* temp = l1.head;
        if (temp && temp->next && temp->next->next) 
		price1 = temp->next->next->data;
        temp = l2.head;
        if (temp && temp->next && temp->next->next) 
		price2 = temp->next->next->data;
        temp = l3.head;
        if (temp && temp->next && temp->next->next) 
		price3 = temp->next->next->data;
        cout << "price of list 1: " << price1 << endl;
        cout << "price of list 2: " << price2 << endl;
        cout << "price of list 3: " << price3 << endl;
        if (price1 > price2 && price1 > price3) 
		cout << "list 1 has the greatest expense " << price1 << endl;
        else if (price2 > price1 && price2 > price3) 
		cout << "list 2 has the greatest expense " << price2 << endl;
        else if (price3 > price1 && price3 > price2) 
		cout << "list 3 has the greatest expense " << price3 << endl;
    }
    
};

int main() {
    operations l;
    cout << endl << "1. Display linked lists" << endl
        << "2. Delete a linked list" << endl
        << "3. Add more linked lists , delete them if you want and check the greatest expense as well" << endl
        << "4. List with greatest expense" << endl;

    for (int i = 0; i <= 5; i++) {
        cout << endl << "Choice: ";
        int c;
        cin >> c;
        switch (c) {
        case 1:
            l.show();
            cout << "Master linked list: ";
            l.displaymaster();
            break;
        case 2:
            int deletechoice;
            cout << "Enter which linked list to delete (1,2,3): ";
            cin >> deletechoice;
            l.del(deletechoice);
            break;
        case 3:
            l.add();
            break;
        case 4:
            l.greaterexpense();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}