# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() /* TODO */ {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	if(head == nullptr){
		return;
	}
	Node* temp = head;
	Node* tempnext = temp->next;
	while(tempnext != nullptr){
		delete temp;
		temp = tempnext;
		tempnext = tempnext->next;
	}
	delete temp;
	delete tempnext;
	delete head;
	delete tail;
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& source) /* TODO */ {
    *this = source;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
		if (source.head == nullptr) {
        head = nullptr;
        tail = nullptr;
        return *this;
    }
	
    head = source.head;
    tail = head;
    
    Node* sourcenext = source.head->next;
    Node* temp = head;
    
    while (sourcenext != nullptr) {
        temp->next = sourcenext;
        temp = temp->next;
        sourcenext = sourcenext->next;
    }
    
    tail = temp;
	
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	Node* newnode = new Node(location, year, month, temperature);

	if(head == nullptr){
		head = newnode;
		tail = newnode;
		return;
	}

	if(newnode < head){
		newnode->next = head;
		head = newnode;
		return;
	}

	Node* temp = head;
	Node* tempnext = head->next;
	while(tempnext != nullptr){
		if(newnode < tempnext){
			temp->next = newnode;
			newnode->next = tempnext;
			return;
		}
		temp = tempnext;
		tempnext = tempnext->next;
	}
	tail->next = newnode;
	tail = newnode;
}

void LinkedList::clear() {
	if(head == nullptr){
		return;
	}
	Node* temp = head;
	Node* tempnext = head->next;
	while(tempnext != nullptr){
		delete temp;
		temp = tempnext;
		tempnext = tempnext->next;
	}
	delete temp;
	delete tempnext;
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	string outputString;

	// TODO: implement this function

	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
