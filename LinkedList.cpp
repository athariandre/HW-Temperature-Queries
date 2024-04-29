# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"
# include <sstream>

using std::string, std::ostream;

LinkedList::LinkedList() /* TODO */ {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	this->clear();
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
	

	if(*newnode < *this->head){
		newnode->next = head;
		head = newnode;
		return;
	}

	if(*tail < *newnode){
		tail->next = newnode;
		tail = newnode;
		return;
	}

	Node* current = head;
	Node* prev = head;

	while(current != nullptr && *current < *newnode){
		prev = current;
		current = current->next;
	}
	newnode->next = current;
	prev->next = newnode;

}

void LinkedList::clear() {
	if(head == nullptr){
		return;
	}
	Node* temp = head;
	while(temp != nullptr){
		Node* tempnext = temp->next;
		delete temp;
		temp = tempnext;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	std::ostringstream outputOSS;
	Node* temp = head;
	while(temp != nullptr){
		outputOSS << temp->data.id << " " << temp->data.year << " " << temp->data.month << " " << temp->data.temperature << "\n";

		temp = temp->next;
	}

	return outputOSS.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
