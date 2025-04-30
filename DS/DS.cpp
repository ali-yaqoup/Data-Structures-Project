#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	T element;
	Node* next;
	template <class T>
	friend class LinkedList;
};

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	bool empty() const;
	T front() const;
	void addFront(T);
	void addBack(T);
	void removeFront();
	void traverse() const;
	Node<T>* find(const T) const;
	void removeBefore(const T); // New function
private:
	Node<T>* head;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while (!empty())
		removeFront();
}

template <class T>
bool LinkedList<T>::empty() const {
	return (head == NULL);
}
template <class T>
T LinkedList<T>::front() const {
	return head->element;
}
template <class T>
void LinkedList<T>::removeFront()
{
	Node<T>* old = head;
	head = old->next;
	delete old;
}

template <class T>
void LinkedList<T>::addFront(T X)
{
	Node<T>* v = new Node<T>;
	v->element = X;
	v->next = head;
	head = v;
}

template <class T>
void LinkedList<T>::addBack(T x) {
	Node<T>* v = new Node<T>;
	v->element = x;
	v->next = NULL;

	Node<T>* current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = v;
}

template <class T>
void LinkedList<T>::traverse() const
{
	Node<T>* current = head;
	while (current != NULL)
	{
		cout << current->element << " ";
		current = current->next;
	}
	cout << endl;
}

template <class T>
Node<T>* LinkedList<T>::find(const T x) const {
	Node<T>* current = head;
	while (current != NULL && current->element != x)
	{
		current = current->next;
	}
	if (current == NULL)
		cout << "Element is not found" << endl;
	else
		cout << "found " << current->element << endl;
	return current;
}



template <class T>
void LinkedList<T>::removeBefore(const T ) {
	Node<T>* current = head;
	Node<T>* previous = NULL;

	while (current != NULL && current->element != x) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "Element not found" << endl;
		return;
	}

	if (previous == NULL) {
		// Remove the first node
		removeFront();
	}
	else {
		// Remove the node before the current node
		previous->next = current->next;
		delete current;
	}
}

void main()
{
	LinkedList<int> L;
	L.addFront(5);
	L.addFront(20);
	L.addFront(19);
	L.addFront(50);
	L.removeFront();
	L.addBack(90);
	L.find(20);
	L.find(99);
	L.find(50);

	// Remove the node before 20
	L.removeBefore(20);

	L.traverse();
}
