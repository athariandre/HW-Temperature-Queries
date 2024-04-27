# include <string>
# include "Node.h"

using std::string;

Node::Node() /* TODO */ {
	this->data = TemperatureData();
	next = nullptr;
}

Node::Node(string id, int year, int month, double temperature) /* TODO */ {
	this->data = TemperatureData(id, year, month, temperature);
	next = nullptr;
}

bool Node::operator<(const Node& b) {	
	return this->data < b.data;
}
