#include <fstream>
#include <iostream>
#include <string>
#include "Functions.h"

struct dateTime {
  int day;
  int month;
  int year;
};

struct WeatherData {
  double percipitation;
  double snowfall;
  double snowdepth;
  double maxtemp;
  double mintemp;
  double obstemp;
};

int main() {
  std::string filename = "weatherData.txt";
  int maxRows = getRows(filename);

  std::cout << "Number of rows: " << maxRows << std::endl;
  struct WeatherData weatherData[maxRows];
  struct dateTime dateTime[maxRows];
  readWeatherData(filename, maxRows, weatherData, dateTime);



  std::cout << "Enter start year: ";
  int startYear;
  std::cin >> startYear;
  std::cout << "Enter end year: ";
  int endYear;
  std::cin >> endYear;
  sumByYear(weatherData, dateTime, startYear, endYear, maxRows);

  meanByYear(weatherData, dateTime, startYear, endYear, maxRows);

  double minTemp(0);
  double maxTemp(0);
  double MinObsTemp(0);
  double maxObsTemp(0);

  GetMinMaxTemp(weatherData, dateTime, startYear, endYear, maxRows, minTemp,
                maxTemp, MinObsTemp, maxObsTemp);
  
  DataOut(weatherData, dateTime, startYear, endYear, maxRows);
  return 0;
}
