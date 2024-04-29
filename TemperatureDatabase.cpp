# include "TemperatureDatabase.h"
# include <fstream>
# include <sstream>

using std::cout, std::endl, std::string, std::ofstream, std::ifstream, std::stringstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	ifstream is(filename);
	
	if(!is.is_open()){
		cout << "Error: Unable to open " << filename << endl;
	}

	string line = "";
	int cnt = 0;
	while(getline(is, line)){

		string id = "";
		int year,month = 0;
		double temp = 0.0;

		is >> id >> year >> month >> temp;


		if(is.fail() || temp == -99.99){
			cout << "Error: Other invalid input" << endl;
		}
		if(temp < -50 || temp > 50){
			cout << "Error: Invalid temperature " << temp << endl;
		}
		if(year < 1800 || year > 2024){
			cout << "Error: Invalid year " << year << endl;

		}
		if(month < 1 || month > 12){
			cout << "Error: Invalid month " << month << endl;
		}
		

		records.insert(id, year, month, temp);
	}
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
