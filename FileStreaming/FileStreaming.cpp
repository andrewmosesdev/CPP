#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string city;
  int fahrenheit;
  ifstream inputFile;
  inputFile.open("FahrenheitTemperature.txt");

  ofstream outputFile;
  outputFile.open("CelsiusTemperature.txt");

  while (inputFile >> city >> fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    outputFile << city << " " << celsius << endl;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
