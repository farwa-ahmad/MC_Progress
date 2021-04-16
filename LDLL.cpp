#include<iostream>
using namespace std;

template<class T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode()
	{
		next = prev = nullptr;
	}
	DNode(T val)
	{
		info = val;
		next = prev = nullptr;
	}
};
template<class T>
class DList
{
	DNode<T>* head;
public:
	DList()
	{
		head = nullptr;
	}
	~DList()
	{
		while (head)
			deleteAtHead();
	}
	/*LinkedList(const LinkedList<T>& linkedList)
	{
		head->info = linkedList->head->info;

	}
	*/
	void setHead(DNode<T>* Head)
	{
		head = Head;
	}
	void setTail(DNode<T>* Tail)////////////////////
	{
		DNode<T>* p = head;
		while (p->next != nullptr)
			p = p->next;
		p->next = Tail;
		Tail->next = nullptr;
		Tail->prev = p;
	}
	void insertAtHead(T value)/////////////////
	{
		DNode<T>* p = new DNode<T>(value);
		
		if (!head)
		{
			head = p;
			return;
		}
		p->next = head;
		head->prev = p;
		head = p;
	}
	void insertAtTail(T value)//////////////////
	{
		if (!head)
		{
			head = new DNode<T>(value);
			return;
		}
		DNode<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new DNode<T>(value);
		DNode<T>* q = p->next;
		q->prev = p;
		q->next = nullptr;
	}
	bool deleteAtHead()////////////
	{
		if (!head)
			return false;
		DNode<T>* x = head;
		head = head->next;
		head->prev = nullptr;
		delete x;
		return true;
	}
	bool deleteAtTail()//////////////
	{
		if (!head)
			return false;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return true;
		}
		DNode<T>* p = head;
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		p = p->prev;
		delete p->next;
		p->next = nullptr;
		return true;
	}
	void printList()////////////
	{
		DNode<T>* p = head;
		DNode<T>* q = nullptr;
		while (p != nullptr)
		{
			cout << p->info << " : ";
			q = p;
			p = p->next;
		}
		cout << endl;
		while (q != nullptr)
		{
			cout << q->info << " : ";
			q = q->prev;
		}
	}
	DNode<T>* getNode(int n)//////////////
	{
		DNode<T>* p = head;
		while (n != 1)
		{
			if (p->next != nullptr)
				p = p->next;
			n--;
		}
		return p;
	}
	bool insertAfter(T value, T key)/////////////
	{
		if (!head)
			return false;
		DNode<T>* p = head;
		while (p != nullptr && p->info != key)
		{
			p = p->next;
		}
		DNode<T>* q = new DNode<T>(value);
		q->next = p->next;
		p->next = q;
		q->prev = p;
		return true;
	}
	bool deleteAfter(T key)/////////////////
	{
		if (!head)
			return false;
		DNode<T>* p = head;
		while (p->info != key)
			p = p->next;
		DNode<T>* q = p->next;
		p->next = p->next->next;
		p->next->prev = p;
		delete q;
		return true;

	}
	int getLength()/////////////////////
	{
		int length = 0;
		DNode<T>* p = head;
		while (p)
		{
			p = p->next;
			length++;
		}
		return length;
	}
	DNode<T>* search(T x)///////////
	{
		if (!head)
			exit(0);
		DNode<T>* p = head;
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
	DList<int> list;
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
	cout << "\nInserting 50 at tail...\n";
	list.insertAtTail(50);
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "\nDeleting at head...\n";
	list.deleteAtHead();
	cout << "Printing Linked List...\n";
	list.printList();
	cout << "\nDeleting after 20...\n";
	list.deleteAfter(20);
	cout << "Printing Linked List...\n";
	list.printList();
	cout << endl << "List length: " << list.getLength();

	cout << "\n\nCreating new linked list\n";
	DList<int> list2;
	cout << "Inserting 10 at head...\n";
	list2.insertAtHead(10);
	cout << "Printing Linked List...\n";
	list2.printList();
	cout << "\nInserting 20 after 10...\n";
	list2.insertAfter(20, 10);
	cout << "Printing Linked List...\n";
	list2.printList();
	cout << "\nAccessing node at 2nd position.\n";
	cout << (list2.getNode(2))->info;
	cout << "\nAccessing node with info equal to 20.\n";
	cout << list2.search(20)->info << endl;
	system("pause");
	return 0;
}