# include "TemperatureDatabase.h"
# include <fstream>

using std::cout, std::endl, std::string, std::ofstream, std::ifstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	ifstream is(filename);

	
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
}
