# ifndef TEMPERATUREDATA
# define TEMPERATUREDATA

# include <string>

struct TemperatureData {
	public:
		TemperatureData();
		TemperatureData(std::string id, int year, int month, double temperature);
		virtual ~TemperatureData();
		bool operator<(const TemperatureData& b);
	private:
		string id;
		int year;
		int month;
		double temperature;
};

# endif
