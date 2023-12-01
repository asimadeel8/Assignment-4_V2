#include <iostream>
using namespace std;
void clear() {
	system("pause");
	system("cls");
}
class Node {
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int value) {
			data=value;
		}
};
class SinglyLinkedList {
	public:
		Node* head;
		int counter=0;
		SinglyLinkedList() {
			head = NULL;
		}
/////////////////////////////////////// ADD FIRST FUNCTION //////////////////////////////////////////
		void addFirst(int value) {
			Node* newNode = new Node(value);
			if (head == NULL) {
				head = newNode;
				newNode->next= NULL;
			} else {
				newNode->next = head;
				head = newNode;
			}
			counter++;
		}
//////////////////////////////////// ADD LAST FUNCTION /////////////////////////////////////
		void addLast(int value) {
			Node* new_node = new Node(value);
			if (head == NULL) {
				head = new_node;
			} else {
				Node* temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new_node;
			}
			new_node->next = NULL;
			counter++;
		}
/////////////////////////////////////// DELETE FIRST /////////////////////////////////////////////////
		void deleteFirst() {
			if(head==NULL) {
				cout<<"linkedList is empty";
			}
			Node* temp= head;
			head = head->next;
			delete temp;
			counter--;
		}
//////////////////////////////////////// DELETE LAST FUNCTION /////////////////////////////////////////
		void Deletelast() {
			if (head == NULL) {
				cout<<"node is empty"<<endl;
				return;
			}
			Node* temp = head;
			Node* prev = NULL;
			while(temp->next != NULL) {
				prev = temp;
				temp = temp->next;
			}
			if(prev != NULL) {
				prev->next = NULL;
			} else {
				head = NULL;
			}
			delete temp;
			counter--;
		}
///////////////////////////////////////INSERT AT FUNCTION //////////////////////////////////////////////
		void Insertat() {
			int index;
			cout<<"enter the index where you want to add the new node ";
			cin>>index;
			if(index>counter && index<0) {
				cout<<"The index is greater than size of linked list!";
			} else {
				int value;
				cout<<"Enter the value : ";
				cin>>value;
				Node* new_node=new Node(value);
				Node* temp=head;
				if(index==0) {
					addFirst(value);
				} else {
					for(int i=1; i<index-1; i++) {
						temp=temp->next;
					}
					new_node->next=temp->next;
					temp->next=new_node;
					counter++;
				}
			}
		}
////////////////////////////////////////////Search Function////////////////////////////////////////
		void search() {
			bool found=0;
			if(head==NULL) {
				cout<<"There is no node in linked list";
			} else {
				int value;
				cout<<"Enter the value you want to search: ";
				cin>>value;
				Node* temp=head;
				while(temp!=NULL) {
					if(temp->data==value) {
						found=1;
						break;
					}
					temp=temp->next;
				}
				if(found) {
					cout<<"Value found";
				} else {
					cout<<"Value not found";
				}

			}
		}
//////////////////////////////////////////////////////////  count node  //////////////////////////////////////////////
		void count_node() {
			cout<<"The number of Nodes are: "<<counter;
		}
//////////////////////////////////////////////// Max ////////////////////////////////////////////////////////////////
		int Max() {
			if (head ==NULL) {
				cout << "List is empty." << std::endl;
				return -1 ;
			}
			int max=head->data;
			Node* temp = head;
			while (temp!=NULL) {
				if (temp->data>max) {
					max=temp->data;
				}
				temp = temp->next;
			}
			return max;
		}
///////////////////////////////////////////////// Average //////////////////////////////////////////////
		float Average() {
			if (head == NULL) {
				cout << "List is empty."<<endl;
				return 0.0;
			}
			float sum = 0;
			int count = 0;
			Node* temp = head;
			while (temp != NULL) {
				sum += temp->data;
				count++;
				temp = temp->next;
			}
			return (sum) / count;
		}
//////////////////////////////////////////// Reverse /////////////////////////////////////////////////
		void reverse() {
			if(head==NULL) {
				cout<<"Empty Linked list!"<<endl;
				return;
			}
			Node* p=head;
			Node* r=NULL;
			Node* q=NULL;
			while(p!=NULL) {
				r=q;
				q=p;
				p=p->next;
				q->next=r;
			}
			head=q;
		}
/////////////////////////////////////////// Detect_Loop  ////////////////////////////////////////////
		bool detectLoop() {
			if (head == NULL || head->next == NULL) {
				return false;
			}
			Node* slow = head;
			Node* fast = head->next;
			while (fast != NULL && fast->next != NULL) {
				if (slow == fast) {
					return true;
				}
				slow = slow->next;
				fast = fast->next->next;
			}
			return false;
		}
/////////////////////////////////////// Singly Palindrome //////////////////////////////////////////////
		bool isPalindrome() {
			if (!head) {
				return false;
			}

			Node* slow = head;
			Node* fast = head;

			Node* reversedFirstHalf = NULL;

			while (fast != NULL && fast->next != NULL) {
				fast = fast->next->next;
				Node* newNode = new Node(slow->data);
				newNode->next = reversedFirstHalf;
				reversedFirstHalf = newNode;
				slow = slow->next;
			}
			if (fast != NULL) {
				slow = slow->next;
			}
			while (slow != NULL) {
				if (slow->data != reversedFirstHalf->data) {
					cout << "Is not a palindrome" << endl;
					while (reversedFirstHalf != NULL) {
						Node* temp = reversedFirstHalf;
						reversedFirstHalf = reversedFirstHalf->next;
						delete temp;
					}
					return false;
				}

				Node* temp = reversedFirstHalf;
				reversedFirstHalf = reversedFirstHalf->next;
				delete temp;

				slow = slow->next;
			}

			cout << "Is a palindrome" << endl;

			while (reversedFirstHalf != NULL) {
				Node* temp = reversedFirstHalf;
				reversedFirstHalf = reversedFirstHalf->next;
				delete temp;
			}
			return true;
		}
/////////////////////////////////////// DISPLAY FUNTION ///////////////////////////////////////////////
		void displaySingly() {
			Node* temp = head;
			if (temp == NULL) {
				cout << "The Simple Singly Linked List is empty." << endl;
				return;
			}
			cout << "Elements in the Simple Singly Linked List: ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

class CircularSinglyLinkedList {
	public:
		int counter=0;
		Node* head;
		CircularSinglyLinkedList() {
			head = NULL;
		}
		void addFirst(int value) {
			Node* new_node = new Node(value);
			if (head == NULL) {
				new_node->next = new_node;
				head = new_node;
			} else {
				new_node->next = head;
				Node* temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				temp->next = new_node;
				head = new_node;
			}
			counter++;
		}

		void addLast(int value) {
			Node* new_node = new Node(value);
			if (head == NULL) {
				new_node->next = new_node;
				head = new_node;
			} else {
				new_node->next = head;
				Node* temp = head;
				while (temp->next != head) {
					temp = temp->next;
				}
				temp->next = new_node;
			}
			counter++;
		}

		void deleteFirst() {
			if (head == NULL) {
				cout << "Circular linked list is empty" << endl;
				return;
			}
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			if (temp == head) {
				head = NULL;
			} else {
				temp->next = head->next;
				head = head->next;
			}
			delete temp;
			counter--;
		}

		void deleteLast() {
			if (head == NULL) {
				cout << "Circular linked list is empty" << endl;
				return;
			}
			Node* current = head;
			Node* prev = NULL;
			while (current->next != head) {
				prev = current;
				current = current->next;
			}
			if (prev == NULL) {
				head = NULL;
			} else {
				prev->next = head;
			}
			delete current;
			counter--;
		}
		void Insertat() {
			int index;
			cout<<"enter the index where you want to add the new node ";
			cin>>index;
			if(index>counter && index<0) {
				cout<<"The index is greater than size of linked list!";
			} else {
				int value;
				cout<<"Enter the value : ";
				cin>>value;
				Node* new_node=new Node(value);
				Node* temp=head;
				if(index==0) {
					addFirst(value);
				} else {
					for(int i=1; i<index-1; i++) {
						temp=temp->next;
					}
					new_node->next=temp->next;
					temp->next=new_node;
					counter++;
				}
			}
		}
////////////////////////////////////////////Search Function////////////////////////////////////////
		void search() {
			bool found=0;
			if(head==NULL) {
				cout<<"There is no node in linked list";
			} else {
				int value;
				cout<<"Enter the value you want to search: ";
				cin>>value;
				Node* temp=head;
				while(temp!=NULL) {
					if(temp->data==value) {
						found=1;
						break;
					}
					temp=temp->next;
				}
				if(found) {
					cout<<"Value found";
				} else {
					cout<<"Value not found";
				}

			}
		}
//////////////////////////////////////////////////////////  count node  //////////////////////////////////////////////
		void count_node() {
			cout<<"The number of Nodes are: "<<counter;
		}
//////////////////////////////////////////////// Max ////////////////////////////////////////////////////////////////
		int Max() {
			if (head ==NULL) {
				cout << "List is empty." << std::endl;
				return -1 ;
			}
			int max=head->data;
			Node* temp = head;
			while (temp!=NULL) {
				if (temp->data>max) {
					max=temp->data;
				}
				temp = temp->next;
			}
			return max;
		}
///////////////////////////////////////////////// Average //////////////////////////////////////////////
		float Average() {
			if (head == NULL) {
				cout << "List is empty."<<endl;
				return 0.0;
			}
			float sum = 0;
			int count = 0;
			Node* temp = head;
			while (temp != NULL) {
				sum += temp->data;
				count++;
				temp = temp->next;
			}
			return (sum) / count;
		}
//////////////////////////////////////////// Reverse /////////////////////////////////////////////////
		void reverse() {
			if(head==NULL) {
				cout<<"Empty Linked list!"<<endl;
				return;
			}
			Node* p=head;
			Node* r=NULL;
			Node* q=NULL;
			while(p!=NULL) {
				r=q;
				q=p;
				p=p->next;
				q->next=r;
			}
			head=q;
		}
/////////////////////////////////////////// Detect_Loop  ////////////////////////////////////////////
		bool detectLoop() {
			if (head == NULL || head->next == NULL) {
				return false;
			}
			Node* slow = head;
			Node* fast = head->next;
			while (fast != NULL && fast->next != NULL) {
				if (slow == fast) {
					return true;
				}
				slow = slow->next;
				fast = fast->next->next;
			}
			return false;
		}
		void displayCircularSingly() {
			Node* temp = head;
			if (temp == NULL) {
				cout << "The Circular Singly Linked List is empty." << endl;
				return;
			}
			cout << "Elements in the Circular Singly Linked List: ";
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
			cout << endl;
		}

		// Implement other methods for circular singly linked list
};
class DoublyLinkedList {
	public:
		Node* head;
		int counter=0;
		DoublyLinkedList() {
			head = NULL;
		}
		void addFirst(int value) {
			Node* new_node = new Node(value);
			new_node->next = head;
			new_node->prev = NULL;

			if (head != NULL)
				head->prev = new_node;
			head = new_node;
			counter++;
		}
//////////////////////////////////// Add at Last ////////////////////////////////////////////////////////
		void addlast(int value) {
			Node* new_node = new Node(value);
			new_node->next = NULL;
			new_node->prev = NULL;

			if (head == NULL) {
				head = new_node;
			} else {
				Node* temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->prev = temp;
			}
			counter++;
		}
//////////////////////////////////////// Insert At ///////////////////////////////////////////////////////
		void Insertat() {
			int index;
			cout<<"enter the index where you want to add the new node: ";
			cin>>index;
			if(index>counter && index<0) {
				cout<<"The index is greater than size of linked list!";
			} else {
				int value;
				cout<<"Enter the value : ";
				cin>>value;
				Node* new_node=new Node(value);
				Node* temp=head;
				new_node->next=NULL;
				new_node->prev=NULL;

				if(index==0) {
					addFirst(value);
				} else {
					for(int i=0; i<index-1; i++) {
						temp=temp->next;
					}
					new_node->prev=temp;
					new_node->next=temp->next;
					temp->next=new_node;
					new_node->next->prev=new_node;
					counter++;
				}
			}
		}
////////////////////////////////////////Delete First ////////////////////////////////////////////////////
		void deletefirst() {
			Node* temp=head;
			head= temp->next;
			delete temp;
			counter--;
		}
//////////////////////////////////////// Delete Last ////////////////////////////////////////////////////
		void deletelast() {
			Node* temp=head;
			while(temp->next!=NULL) {
				temp=temp->next;
			}
			temp->prev->next=NULL;
			delete temp;
			counter--;
		}
/////////////////////////////////////// Delete At ///////////////////////////////////////////////////////
		void deleteat() {
			int index;
			cout<<"enter the index where you want to add the new node ";
			cin>>index;
			if(index>counter && index<0) {
				cout<<"The index is greater than size of linked list!";
			}
			Node* current=head;
			Node* temp=head;
			for(int i=0; i<index-1; i++) {
				temp=temp->next;
			}
			current=temp->next;
			temp->next->next->prev=temp;
			temp->next=temp->next->next;
			delete current;
			counter--;
		}
//////////////////////////////////////// Search Doubly //////////////////////////////////////////////////
		void search() {
			bool found=0;
			if(head==NULL) {
				cout<<"There is no node in linked list";
			} else {
				int value;
				cout<<"Enter the value you want to search: ";
				cin>>value;
				Node* temp=head;
				while(temp!=NULL) {
					if(temp->data==value) {
						found=1;
						break;
					}
					temp=temp->next;
				}
				if(found) {
					cout<<"Value found";
				} else {
					cout<<"Value not found";
				}
			}
		}
/////////////////////////////// Max doubly simple //////////////////////////////////////////////////////////////////
		int Max() {
			if (head ==NULL) {
				cout << "List is empty." << std::endl;
				return -1 ;
			}
			int max=head->data;
			Node* temp = head;
			while (temp!=NULL) {
				if (temp->data>max) {
					max=temp->data;
				}
				temp = temp->next;
			}
			return max;
		}
		void count_node() {
			cout<<"The number of Node are: "<<counter;
		}
///////////////////////////////////////////////// Average doubly simple //////////////////////////////////////////////
		float Average() {
			if (head == NULL) {
				cout << "List is empty."<<endl;
				return 0.0;
			}
			float sum = 0;
			int count = 0;
			Node* temp = head;
			while (temp != NULL) {
				sum += temp->data;
				count++;
				temp = temp->next;
			}
			return (sum) / count;
		}
//////////////////////////////////////// Reverse Doubly simple ////////////////////////////////////////
		void reverse() {
			Node* current = head;
			Node* temp = NULL;
			while (current != NULL) {
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL) {
				head = temp->prev;
			}
		}
/////////////////////////////////////// Dispaly Doubly /////////////////////////////////////////////////
		void displayDoubly() {
			Node* temp = head;
			if (temp == NULL) {
				cout << "The Simple Doubly Linked List is empty." << endl;
				return;
			}
			cout << "Elements in the Simple Doubly Linked List: ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};
class CircularDoublyLinkedList {
	public:
		Node* head;
		int counter=0;
		CircularDoublyLinkedList() {
			head =NULL;
		}
		void addFirst(int value) {
			Node* new_node = new Node(value);
			if (head == NULL) {
				new_node->next = new_node;
				new_node->prev = new_node;
				head = new_node;
			} else {
				new_node->next = head;
				new_node->prev = head->prev;
				head->prev->next = new_node;
				head->prev = new_node;
				head = new_node;
			}
			counter++;
		}
		void addLast(int value) {
			Node* new_node = new Node(value);
			if (head == NULL) {
				new_node->next = new_node;
				new_node->prev = new_node;
				head = new_node;
			} else {
				new_node->next = head;
				new_node->prev = head->prev;
				head->prev->next = new_node;
				head->prev = new_node;
			}
			counter++;
		}
		void insertAt() {
			int index;
			cout<<"enter the index where you want to add the new node: ";
			cin>>index;
			if (index < 0 || index > counter) {
				cout<<"Invalid index."<<endl;
				return;
			}
			int value;
			cout<<"Enter the value : ";
			cin>>value;
			if (index == 0) {
				addFirst(value);
				return;
			}

			Node* new_node = new Node(value);
			Node* temp = head;
			for (int i = 0; i < index - 1; ++i) {
				temp = temp->next;
			}
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->next->prev = new_node;
			temp->next = new_node;
			counter++;
		}

		void deleteFirst() {
			if (head == NULL) {
				cout<<"List is empty."<<endl;
				return;
			}

			Node* temp = head;
			if (head->next == head) {
				head =NULL;
			} else {
				head = head->next;
				head->prev = temp->prev;
				temp->prev->next = head;
			}

			delete temp;
			counter--;
		}

		void deleteLast() {
			int index;
			cout<<"enter the index where you want to add the new node: ";
			cin>>index;
			if (head == NULL) {
				cout<<"List is empty."<<endl;
				return;
			}

			Node* temp = head->prev;
			if (head->next == head) {
				head = NULL;
			} else {
				temp->prev->next = head;
				head->prev = temp->prev;
			}
			delete temp;
			counter--;
		}

		void deleteAt() {
			int index;
			cout<<"enter the index where you want to add the new node: ";
			cin>>index;
			if (index < 0 || index >= counter) {
				cout<<"Invalid index."<<endl;
				return;
			}

			if (index == 0) {
				deleteFirst();
				return;
			}
			Node* temp = head;
			for (int i = 0; i < index; ++i) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			delete temp;
			counter--;
		}
		void search() {

			if (head == NULL) {
				cout<<"List is empty."<<endl;
				return;
			}
			int value;
			cout<<"Enter the value you want to search: ";
			cin>>value;
			Node* temp = head;
			do {
				if (temp->data == value) {
					cout<<"Value found."<<endl;
					return;
				}
				temp = temp->next;
			} while (temp != head);

			cout<<"Value not found."<<endl;
		}
		int max() {
			if (head == NULL) {
				cout<<"List is empty."<<endl;
				return -1;
			}

			int max = head->data;
			Node* temp = head->next;

			do {
				if (temp->data > max) {
					max = temp->data;
				}
				temp = temp->next;
			} while (temp != head);

			return max;
		}

		void countNodes() {
			cout << "The number of nodes are: " << counter << endl;
		}

		float average() {
			if (head == NULL) {
				cout<<"List is empty."<<endl;
				return 0.0;
			}

			float sum = 0;
			Node* temp = head;

			do {
				sum =sum+temp->data;
				temp = temp->next;
			} while (temp != head);

			return (sum / counter);
		}
		void reverse() {
			if (head == NULL || head->next == head) {
				return;
			}
			Node* current = head;
			Node* temp = NULL;

			do {
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			} while (current != head);

			head = temp->prev;
		}
		void displayCircularDoubly() {
			if (head == NULL) {
				cout<<"The Circular Doubly Linked List is empty."<<endl;
				return;
			}

			Node* temp = head;
			do {
				cout<<temp->data << " ";
				temp=temp->next;
			} while (temp != head);

			cout<<endl;
		}
};
void linked_lists_choice() {
	cout << "Choose the type of Linked List:" << endl;
	cout << "1. Singly Linked List" << endl;
	cout << "2. Doubly Linked List" << endl;
	cout << "0. to exit."<<endl;
	cout << "Enter your choice: "<<endl;
}
void printSinglyOptions() {
	cout << "Choose the type of Singly Linked List:" << endl;
	cout << "1. Simple Singly Linked List" << endl;
	cout << "2. Circular Singly Linked List" << endl;
	cout << "Enter your choice: ";
}
void printDoublyOptions() {
	cout << "Choose the type of Doubly Linked List:" << endl;
	cout << "1. Simple Doubly Linked List" << endl;
	cout << "2. Circular Doubly Linked List" << endl;
	cout << "Enter your choice: ";
}

void printSimpleSinglyOptions() {
	cout <<"Operations for Simple Singly Linked List:" << endl;
	cout <<"1.  Add at beginning" << endl;
	cout <<"2.  Add at last "<<endl;
	cout <<"3.  Delete first "<<endl;
	cout <<"4.  Delete last "<<endl;
	cout <<"5.  Insert at "<<endl;
	cout <<"6.  Search "<<endl;
	cout <<"7.  Palindrome."<<endl;
	cout <<"8.  Count Nodes."<<endl;
	cout <<"9.  Max."<<endl;
	cout <<"10. Average."<<endl;
	cout <<"11. Reverse."<<endl;
	cout <<"12. Detect loop."<<endl;
	cout << "0. Exit" << endl;
}

void printCircularSinglyOptions() {
	cout << "Operations for Circular Singly Linked List:" << endl;
	cout <<"1.  Add at beginning" << endl;
	cout <<"2.  Add at last "<<endl;
	cout <<"3.  Delete first "<<endl;
	cout <<"4.  Delete last "<<endl;
	cout <<"5.  Insert at "<<endl;
	cout <<"6.  Search "<<endl;
	cout <<"7.  Count Nodes."<<endl;
	cout <<"8.  Max."<<endl;
	cout <<"9. Average."<<endl;
	cout <<"10. Reverse."<<endl;
	cout <<"11. Detect loop."<<endl;
	cout << "0. Exit" << endl;
}
void printSimpleDoublyOptions() {
	cout << "Operations for Simple Doubly Linked List:" << endl;
	cout << "1. Add at beginning. " << endl;
	cout << "2. Add at Last. "<<endl;
	cout << "3. Insert At. "<<endl;
	cout << "4. Delete First. "<<endl;
	cout << "5. Delete Last.  "<<endl;
	cout << "6. Delete at. "   <<endl;
	cout << "7. Search." <<endl;
	cout << "8. Max."<<endl;
	cout << "9. Count Nodes."<<endl;
	cout <<"10. Average."<<endl;
	cout <<"11. Reverse."<<endl;
	cout << "0. Exit" << endl;
}

void printCircularDoublyOptions() {
	cout << "Operations for Circular Doubly Linked List:" << endl;
	cout << "1. Add at beginning. " << endl;
	cout << "2. Add at Last. "<<endl;
	cout << "3. Insert At. "<<endl;
	cout << "4. Delete First. "<<endl;
	cout << "5. Delete Last.  "<<endl;
	cout << "6. Delete at. "   <<endl;
	cout << "7. Search." <<endl;
	cout << "8. Max."<<endl;
	cout << "9. Count Nodes."<<endl;
	cout <<"10. Average."<<endl;
	cout <<"11. Reverse."<<endl;
	cout << "0. Exit" << endl;
}
void menu() {
	int choice;
	do {
		linked_lists_choice();
		cin >> choice;

		switch (choice) {
			case 1: {
				int options_for_singly;
				printSinglyOptions();
				cin >> options_for_singly;

				switch (options_for_singly) {
					case 1: {
						SinglyLinkedList ss1;
						int operationChoice;
						do {
							printSimpleSinglyOptions();
							cout << "Enter your choice: ";
							cin >> operationChoice;

							switch (operationChoice) {
								case 1: {
									int value;
									cout << "Enter value to insert at the beginning: ";
									cin >> value;
									ss1.addFirst(value);
									ss1.displaySingly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 2: {
									int value;
									cout<<" Enter value to insert at the last :";
									cin>>value;
									ss1.addLast(value);
									ss1.displaySingly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;

									clear();
									break;
								}
								case 3: {
									cout<<"before deleting first"<<endl;
									ss1.displaySingly();
									ss1.deleteFirst();
									cout<<"after deleting first"<<endl;
									ss1.displaySingly();
									cout<<endl;
									cout<<"The value of counter is :"<<ss1.counter;

									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 4: {
									cout<<"Before deleting last "<<endl;
									ss1.Deletelast();
									ss1.displaySingly();
									cout<<"after deleting last"<<endl;
									ss1.displaySingly();
									cout<<endl;
									cout<<"The value of counter is :"<<ss1.counter;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 5: {
									ss1.displaySingly();
									ss1.Insertat();
									cout<<endl;
									cout<<"The value of counter is :"<<ss1.counter;
									cout<<endl;
									ss1.displaySingly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 6: {
									ss1.search();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;

									clear();
									break;
								}
								case 7: {
									bool check=ss1.isPalindrome();
									if(check) {
										cout<<"Linked list is palindrome"<<endl;

									} else {
										cout<<"Linked list is not palindrome"<<endl;
									}
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 8: {
									ss1.count_node();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 9: {
									int max=ss1.Max();
									cout<<"Max number is "<<max;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 10: {
									float avg=ss1.Average();
									cout<<"Average is :"<<avg<<endl;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 11: {
									ss1.reverse();
									ss1.displaySingly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 12: {
									bool a=ss1.detectLoop();
									if(a) {
										cout<<"Loop detected.";
									} else {
										cout<<"No loop detected.";
									}
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 0:
									cout << "Exiting Simple Singly Linked List operations." << endl;
									clear();
									break;
								default:
									cout << "Invalid choice!" << endl;
									clear();
									break;
							}
						} while (operationChoice != 0);
						break;
					}
					case 2: {
						CircularSinglyLinkedList cs1;
						int operationChoice;
						do {
							printCircularSinglyOptions();
							cout << "Enter your choice: ";
							cin >> operationChoice;

							switch (operationChoice) {
								case 1: {
									int value;
									cout << "Enter value to insert at the beginning: ";
									cin >> value;
									cs1.addFirst(value);
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The value of counter is :"<<cs1.counter;
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 2: {
									int value;
									cout<<" Enter value to insert at the last :";
									cin>>value;
									cs1.addLast(value);
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The value of counter is :"<<cs1.counter;
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 3: {
									cout<<"before deleting first"<<endl;
									cs1.displayCircularSingly();
									cs1.deleteFirst();
									cout<<"after deleting first"<<endl;
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The value of counter is :"<<cs1.counter;
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 4: {
									cout<<"Before deleting last "<<endl;
									cs1.deleteLast();
									cs1.displayCircularSingly();
									cout<<"after deleting last"<<endl;
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The value of counter is :"<<cs1.counter;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 5: {
									cs1.displayCircularSingly();
									cs1.Insertat();
									cout<<endl;
									cout<<"The value of counter is :"<<cs1.counter;
									cout<<endl;
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();

									break;
								}
								case 6: {
									cs1.search();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 7: {
									cs1.count_node();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 8: {
									int max=cs1.Max();
									cout<<"Max number is "<<max;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 9: {
									float avg=cs1.Average();
									cout<<"Average is :"<<avg<<endl;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 10: {
									cs1.reverse();
									cs1.displayCircularSingly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 11: {
									bool a=cs1.detectLoop();
									if(a) {
										cout<<"Loop detected.";
									} else {
										cout<<"No loop detected.";
									}
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 0:
									cout << "Exiting Circular Singly Linked List operations." << endl;
									clear();

									break;
								default:
									cout << "Invalid choice!" << endl;
									clear();
									break;
							}
						} while (operationChoice != 0);
						break;
					}
					default:
						cout << "Invalid choice for Singly Linked List!" << endl;
						clear();
						break;
				}
				break;
			}
			case 2: {
				int doublyChoice;
				printDoublyOptions();
				cin >> doublyChoice;

				switch (doublyChoice) {
					case 1: {
						DoublyLinkedList ds1;
						int operationChoice;
						do {
							printSimpleDoublyOptions();
							cout << "Enter your choice: ";
							cin >> operationChoice;

							switch (operationChoice) {
								case 1: {
									int value;
									cout << "Enter value to insert at the beginning: ";
									cin >> value;
									ds1.addFirst(value);
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 2: {
									int value;
									cout << "Enter value to insert at the Last: ";
									cin >> value;
									ds1.addlast(value);
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 3: {
									ds1.displayDoubly();
									ds1.Insertat();
									cout<<endl;
									cout<<"The value of counter is :"<<ds1.counter;
									cout<<endl;
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;

									clear();
									break;
								}
								case 4: {
									cout<<"before deleting first"<<endl;
									ds1.displayDoubly();
									ds1.deletefirst();
									cout<<"after deleting first"<<endl;
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 5: {
									cout<<"Before deleting last "<<endl;
									ds1.displayDoubly();
									ds1.deletelast();
									cout<<"after deleting last"<<endl;
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 6: {
									cout<<"Before deleteing At "<<endl;
									ds1.displayDoubly();
									ds1.deleteat();
									cout<<"After deleting At "<<endl;
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 7: {
									ds1.search();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 8: {
									int max=ds1.Max();
									cout<<"Max number is "<<max;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 9: {
									ds1.count_node();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 10: {
									float avg=ds1.Average();
									cout<<"Average is :"<<avg<<endl;

									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 11: {
									ds1.reverse();
									ds1.displayDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 0:
									cout << "Exiting Simple Doubly Linked List operations." << endl;
									clear();
									break;
								default:
									cout << "Invalid choice!" << endl;
									break;
							}
						} while (operationChoice != 0);
						break;
					}
					case 2: {
						CircularDoublyLinkedList cd1;
						int operationChoice;
						do {
							printCircularDoublyOptions();
							cout << "Enter your choice: ";
							cin >> operationChoice;

							switch (operationChoice) {
								case 1: {
									int value;
									cout << "Enter value to insert at the beginning: ";
									cin >> value;
									cd1.addFirst(value);
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;

									clear();
									break;

								}
								case 2: {
									int value;
									cout << "Enter value to insert at the Last: ";
									cin >> value;
									cd1.addLast(value);
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 3: {
									cd1.displayCircularDoubly();
									cd1.insertAt();
									cout<<endl;
									cout<<endl;
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 4: {
									cout<<"before deleting first"<<endl;
									cd1.displayCircularDoubly();
									cd1.deleteFirst();
									cout<<"after deleting first"<<endl;
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 5: {
									cout<<"Before deleting last "<<endl;
									cd1.displayCircularDoubly();
									cd1.deleteLast();
									cout<<"after deleting last"<<endl;
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(1).";
									cout<<endl;
									clear();
									break;
								}
								case 6: {
									cout<<"Before deleteing At "<<endl;
									cd1.displayCircularDoubly();
									cd1.deleteAt();
									cout<<"After deleting At "<<endl;
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 7: {
									cd1.search();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 8: {
									int max=cd1.max();
									cout<<"Max number is "<<max;
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 9: {
									cd1.countNodes();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 10: {
									float avg=cd1.average();
									cout<<"Average is :"<<avg<<endl;

									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 11: {
									cd1.reverse();
									cd1.displayCircularDoubly();
									cout<<endl;
									cout<<"The Time complexity is O(n).";
									cout<<endl;
									clear();
									break;
								}
								case 0:
									cout << "Exiting Simple Doubly Linked List operations." << endl;
									clear();
									break;
								default:
									cout << "Invalid choice!" << endl;
									clear();
									break;
							}
						} while (operationChoice != 0);
						break;
					}
					default:
						cout << "Invalid choice for Doubly Linked List!" << endl;
						clear();
						break;
				}

				break;
			}
			default:
				cout << "Invalid choice! Please enter a valid option." << endl;
				break;
		}
	} while (choice!=0);
}
int main() {
	menu();
}
