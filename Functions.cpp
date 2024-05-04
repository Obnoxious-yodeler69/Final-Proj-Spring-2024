#include <fstream>
#include <iostream>
#include <string>

int getRows(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Error opening file" << std::endl;
  }
  int rows = 0;
  std::string line;
  while (std::getline(file, line)) {
    rows++;
  }
  file.close();
  return rows;
}

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

void readWeatherData(std::string filename, int rows,
                     struct WeatherData weatherData[rows],
                     struct dateTime dateTime[rows]) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Error opening file" << std::endl;
  }
  for (int i = 0; i < rows; i++) {
    file >> dateTime[i].day >> dateTime[i].month >> dateTime[i].year >>
        weatherData[i].percipitation >> weatherData[i].snowfall >>
        weatherData[i].snowdepth >> weatherData[i].maxtemp >>
        weatherData[i].mintemp >> weatherData[i].obstemp;
  }
}
void printWeatherData(struct WeatherData weatherData[],
                      struct dateTime dateTime[], int rows) {
  for (int i = 0; i < rows; i++) {
    std::cout << dateTime[i].day << " " << dateTime[i].month << " "
              << dateTime[i].year << " " << weatherData[i].percipitation << " "
              << weatherData[i].snowfall << " " << weatherData[i].snowdepth
              << " " << weatherData[i].maxtemp << " " << weatherData[i].mintemp
              << " " << weatherData[i].obstemp << std::endl;
  }
}
void sumByYear(struct WeatherData weatherData[], struct dateTime dateTime[],
               int startYear, int endYear, int rows) {
  double totalPercipitation = 0;
  double totalSnowfall = 0;
  double totalSnowdepth = 0;

  for (int i = 0; i < rows; i++) {
    if (dateTime[i].year >= startYear && dateTime[i].year <= endYear) {
      totalPercipitation += weatherData[i].percipitation;
      totalSnowfall += weatherData[i].snowfall;
      totalSnowdepth += weatherData[i].snowdepth;
    }
  }
  std::cout << "Total percipitation for years " << startYear << " to "
            << endYear << " is " << totalPercipitation << std::endl
            << "Total snowfall for years " << startYear << " to " << endYear
            << " is " << totalSnowfall << std::endl
            << "Total snowdepth for years " << startYear << " to " << endYear
            << " is " << totalSnowdepth << std::endl;
}

void meanByYear(struct WeatherData weatherData[], struct dateTime dateTime[],
                int startYear, int endYear, int rows) {
  double totalPercipitation = 0;
  double totalSnowfall = 0;
  double totalSnowdepth = 0;
  double totalMaxTemp = 0;
  double totalMintemp = 0;
  double totalObstemp = 0;

  int count = 0;
  for (int i = 0; i < rows; i++) {
    if (dateTime[i].year >= startYear && dateTime[i].year <= endYear) {
      totalPercipitation += weatherData[i].percipitation;
      totalSnowfall += weatherData[i].snowfall;
      totalSnowdepth += weatherData[i].snowdepth;
      totalMaxTemp += weatherData[i].maxtemp;
      totalMintemp += weatherData[i].mintemp;
      totalObstemp += weatherData[i].obstemp;

      count++;
    }
  }
  double meanPercipitation = totalPercipitation / count;
  double meanSnowfall = totalSnowfall / count;
  double meanSnowdepth = totalSnowdepth / count;
  double meanMaxTemp = totalMaxTemp / count;
  double meanMintemp = totalMintemp / count;
  double meanObstemp = totalObstemp / count;

  std::cout << "Mean percipitation for years " << startYear << " to " << endYear
            << " is " << meanPercipitation << std::endl
            << "Mean snowfall for years " << startYear << " to " << endYear
            << " is " << meanSnowfall << std::endl
            << "Mean snowdepth for years " << startYear << " to " << endYear
            << " is " << meanSnowdepth << std::endl;
  std::cout << "Mean maxtemp for years " << startYear << " to " << endYear
            << " is " << meanMaxTemp << std::endl
            << "Mean mintemp for years " << startYear << " to " << endYear
            << " is " << meanMintemp << std::endl
            << "Mean obstemp for years " << startYear << " to " << endYear
            << " is " << meanObstemp << std::endl;
}
void GetMinMaxTemp(struct WeatherData weatherData[], struct dateTime dateTime[],
                   int startYear, int endYear, int rows, double minTemp,
                   double maxTemp, double MinObsTemp, double maxObsTemp) {
  maxTemp = weatherData[0].maxtemp;
  minTemp = weatherData[0].mintemp;
  for (int i = 0; i < rows; i++) {
    if (dateTime[i].year >= startYear && dateTime[i].year <= endYear) {
      if (weatherData[i].maxtemp > maxTemp) {
        maxTemp = weatherData[i].maxtemp;
      }
      if (weatherData[i].mintemp < minTemp) {
        minTemp = weatherData[i].mintemp;
      }
      if (weatherData[i].obstemp > maxObsTemp) {
        maxObsTemp = weatherData[i].obstemp;
      }
      if (weatherData[i].obstemp < MinObsTemp) {
        MinObsTemp = weatherData[i].obstemp;
      }
    }
  }
  std::cout << "Max Temp for years " << startYear << " to " << endYear << " is "
            << maxTemp << std::endl
            << "Min Temp for years " << startYear << " to " << endYear << " is "
            << minTemp << std::endl
            << "Max Obs Temp for years " << startYear << " to " << endYear
            << " is " << maxObsTemp << std::endl
            << "Min Obs Temp for years " << startYear << " to " << endYear
            << " is " << MinObsTemp << std::endl;
}

void DataOut(WeatherData weatherData[], dateTime dateTime[], int startYear,
             int endYear, int rows) {
  std::ofstream file("output.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return;
  }

  for (int year = startYear; year <= endYear; ++year) {
    double totalPrecipitation = 0.0;
    double totalSnowfall = 0.0;
    double totalSnowdepth = 0.0;
    double totalMaxTemp = 0.0;
    double totalMinTemp = 0.0;
    double totalObsTemp = 0.0;
    double minTempOfYear = 0.0;
    double maxTempOfYear = 0.0;
    int count = 0;

    for (int i = 0; i < rows; ++i) {
      if (dateTime[i].year == year) {
        totalPrecipitation += weatherData[i].percipitation;
        totalSnowfall += weatherData[i].snowfall;
        totalSnowdepth += weatherData[i].snowdepth;
        totalMaxTemp += weatherData[i].maxtemp;
        totalMinTemp += weatherData[i].mintemp;
        totalObsTemp += weatherData[i].obstemp;

        if (count == 0) {

          minTempOfYear = weatherData[i].mintemp;
          maxTempOfYear = weatherData[i].maxtemp;
        } else {
          // Update min/max temp for the year
          if (weatherData[i].mintemp < minTempOfYear) {
            minTempOfYear = weatherData[i].mintemp;
          }
          if (weatherData[i].maxtemp > maxTempOfYear) {
            maxTempOfYear = weatherData[i].maxtemp;
          }
        }

        ++count;
      }
    }

    if (count > 0) {
      double meanPrecipitation = totalPrecipitation / count;
      double meanSnowfall = totalSnowfall / count;
      double meanSnowdepth = totalSnowdepth / count;
      double meanMaxTemp = totalMaxTemp / count;
      double meanMinTemp = totalMinTemp / count;
      double meanObsTemp = totalObsTemp / count;

      file << year << " " << minTempOfYear << " " << maxTempOfYear << " "
           << meanPrecipitation << " " << meanSnowfall << " " << meanSnowdepth
           << " " << meanMaxTemp << " " << meanMinTemp << " " << meanObsTemp
           << std::endl;
    }
  }

  file.close();
}
