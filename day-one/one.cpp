#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file;
  std::string line;
  int locationID;
  std::vector<int> leftList;
  std::vector<int> rightList;
  int diffSum = 0;

  file.open("input.txt", std::ifstream::in);

  while (!file.eof()) {
    file >> line;
    locationID = std::stoi(line);
    leftList.push_back(locationID);

    file >> line;
    locationID = std::stoi(line);
    rightList.push_back(locationID);
  }
  file.close();

  std::sort(leftList.begin(), leftList.end());
  std::sort(rightList.begin(), rightList.end());

  for (int i = 0; i < leftList.size(); ++i) {
    diffSum += abs(leftList.at(i) - rightList.at(i));
  }

  std::cout << "Sum: " << diffSum << std::endl;

  return 0;
}
