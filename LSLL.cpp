#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node()
	{
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
};
template<class T>
class LinkedList
{
	Node<T>* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList()
	{
		while (head)
			deleteAtHead();
	}
	/*LinkedList(const LinkedList<T>& linkedList)
	{
		head->info = linkedList->head->info;

	}
	*/
	void insertAtHead(T value)
	{
		Node<T>* p = new Node<T>(value);
		p -> next = head;
		head = p;
	}
	void insertAtTail(T value)
	{
		if (!head)
		{
			head = new Node<T>(value);
			return;
		}
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(value);
	}
	bool deleteAtHead()
	{
		if (!head)
			return false;
		Node<T>* x = head;
		head = head->next;
		delete x;
		return true;
	}
	bool deleteAtTail() 
	{
		if (!head)
			return false;
		Node<T>* p = head;
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		Node<T>* x = p -> next ;
		p->next = nullptr;
		delete x;
		return true;
	}
	void printList()
	{
		Node<T>* p = head;
		while (p != nullptr)
		{
			cout << p->info << " : ";
			p = p->next;
		}
		cout << endl;
	}
	Node<T>* getNode(int n)
	{
		Node<T>* p = head;
		while (n != 1)
		{
			if(p->next != nullptr)
				p = p->next;
			n--;
		}
		return p;
	}
	bool insertAfter(T value, T key)
	{
		if (!head)
			return false;
		Node<T>* p = head;
		while (p!= nullptr && p->info != key)
		{
			p = p->next;
		}
		Node<T>* q = new Node<T>(value);
		q->next = p->next;
		p->next = q;
		return true;
	}
	bool insertBefore(T value, T key)
	{
		if (!head)
			return false;
		if (head->info == key)
		{
			Node<T>* p = new Node<T>(value);
			p->next = head;
			head = p;
			return true;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next;
		while (p!= nullptr && p->info != key)
		{
			prev = p;
			p = p->next;
		}
		if (p)
		{
			Node<T>* x = new Node<T>(value);
			x->next = p;
			prev->next = x;
			return true;
		}
	}
	bool deleteBefore(T key) 
	{
		if (!head || head->info == key)
			return false;
		if (head->next->info == key)
		{
			Node<T>* p = head;
			head = head->next;
			delete p;
			return true;
		}
		Node<T>* p = head;
		while ( p->next->next->info != key)
		{
			p = p->next;
		}
		Node<T>* q = p -> next;
		p->next = p->next->next;
		delete q;
		return true;
	}
	bool deleteAfter(T key)
	{
		if (!head)
			return false;
		Node<T>* p = head;
		while (p->info != key)
			p = p->next;
		Node<T>* q = p->next;
		p->next = p->next->next;
		delete q;
		return true;

	}
	int getLength()
	{
		int length = 0;
		Node<T>* p = head;
		while (p)
		{
			p = p->next;
			length++;
		}
		return length;
	}
	Node<T>* search(T x)
	{
		if (!head)
			exit(0);
		Node<T>* p = head;
		while (p)
		{
			if (p->info == x)
				return p;
			p = p->next;
		}
	}
};
int main()
{
	LinkedList<int> list;
	cout << "Creating linked list...\n";
	cout << "Inserting 10 at head...\n";
	list.insertAtHead(10);
	cout << "Inserting 20 at head...\n";
	list.insertAtHead(20);
	cout << "Inserting 30 at head...\n";
	list.insertAtHead(30);
	cout << "Inserting 40 at head...\n";
	list.insertAtHead(40);
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "Inserting 50 at tail...\n";
	list.insertAtTail(50);
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "Deleting at head...\n";
	list.deleteAtHead();
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "Deleting after 20...\n";
	list.deleteAfter(20);
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "Deleting before 50...\n";
	list.deleteBefore(50);
	cout << "Printing Linked List...\n";
	list.printList();
	cout<<endl<<"List length: "<<list.getLength();

	cout << "\n\nCreating new linked list\n";
	LinkedList<int> list2;
	cout << "Inserting 10 at head...\n";
	list2.insertAtHead(10);
	cout << "Printing Linked List...\n";
	list2.printList();
	cout << "Inserting 20 after 10...\n";
	list2.insertAfter(20,10);
	cout << "Printing Linked List...\n";
	list2.printList();
	cout << "Inserting 15 before 20...\n";
	list2.insertBefore(15,20);
	cout << "Printing Linked List...\n";
	list2.printList();
	cout << "\nTrying to delete before 10";
	if (list2.deleteBefore(10))
		cout << "\nDeleted.\n";
	else
		cout << "\nCannot be deleted.\n";
	cout << "\nAccessing node at 2nd position.\n";
	cout << (list2.getNode(2))->info;
	cout << "\nAccessing node with info equal to 20.\n";
	cout << list2.search(20)->info <<endl;
	system("pause");
	return 0;
}