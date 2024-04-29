# include "TemperatureDatabase.h"
# include <fstream>
# include <sstream>

using std::cout, std::endl, std::string, std::ofstream, std::ifstream, std::stringstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	ifstream is(filename);

	if(!is.is_open()){
		cout << "Error: Unable to open " << filename << endl;
		return;
	}
	string line;

	while(getline(is, line)){
		try{

			stringstream s(line);

			string id, yrstr, monstr, tempstr;
			int year = 0;
			int month = 0;
			double temperature = 0.0;
			
			s >> id >> yrstr >> monstr >> tempstr;

			if(!s.good()){
				break;
			}

			cout << "id: " << id << "\nyrstr: " << yrstr << "\nmonstr: " << monstr << "\ntempstr: " << tempstr << endl;

			year = std::stoi(yrstr);
			month = std::stoi(monstr);
			temperature = std::stod(tempstr);

			if(temperature < -50 || temperature > 50){
				cout << "Error: Invalid temperature " << std::to_string(temperature) << endl;
				return;
			}
			if(year < 1800 || year > 2024){
				cout << "Error: Invalid year " << std::to_string(year) << endl;
				return;
			}
			if(month < 1 || month > 12){
				cout << "Error: Invalid month " << std::to_string(month) << endl;
				return;
			}
			cout << "inserted!" << endl;
			records.insert(id, year, month, temperature);
		}
		catch(...){
			cout << "Error: Other invalid input." << endl;
			return;
		}
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
