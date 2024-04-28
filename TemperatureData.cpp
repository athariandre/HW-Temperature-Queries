# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() /* TODO */ {
	this->id = -1;
	this->year = -1;
	this->month = -1;
	this->temperature = -51;
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) /* TODO */ {
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	if(this->id != b.id){
		return(b.id > this->id);
	}
	else if(this->year != b.year){
		return (b.year > this->year);
	}
	else{
		return (b.month > this->month);
	}
	return false;
}

