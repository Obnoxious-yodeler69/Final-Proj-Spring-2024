#include <fstream>
#include <iostream>
#include <string>

int getRows(std::string filename);


void readWeatherData(std::string filename, int rows,
                     struct WeatherData weatherData[rows],
                     struct dateTime dateTime[rows]);

void printWeatherData(struct WeatherData weatherData[],
struct dateTime dateTime[], int rows);

void sumByYear(struct WeatherData weatherData[], struct dateTime dateTime[],
 int startYear, int endYear, int rows);

void meanByYear(struct WeatherData weatherData[], struct dateTime dateTime[],
int startYear, int endYear, int rows);

void GetMinMaxTemp(struct WeatherData weatherData[], struct dateTime dateTime[],
 int startYear, int endYear, int rows, double minTemp,
 double maxTemp, double MinObsTemp, double maxObsTemp);

void DataOut(WeatherData weatherData[], dateTime dateTime[], int startYear,
 int endYear, int rows);
