#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Problematic code using std::vector<bool>
  std::vector<bool> boolVector = {true, false, true, true};
  // boolVector.begin() returns a special iterator that isn't a standard random access iterator.
  // std::find is using the wrong iterator logic to find the element.
  auto it = std::find(boolVector.begin(), boolVector.end(), false);
  if (it != boolVector.end()) {
    std::cout << "Found false at index: " << std::distance(boolVector.begin(), it) << std::endl; //Output might be incorrect.
  } else {
    std::cout << "false not found" << std::endl;
  }

  //Solution 1: use a std::vector<int>
  std::vector<int> intVector = {1, 0, 1, 1};
  auto it2 = std::find(intVector.begin(), intVector.end(), 0);
  if (it2 != intVector.end()) {
    std::cout << "Found 0 at index: " << std::distance(intVector.begin(), it2) << std::endl; //Output will be correct
  } else {
    std::cout << "0 not found" << std::endl;
  }

  //Solution 2: Manual search (if space efficiency is essential)
  size_t index = -1;
  for(size_t i = 0; i < boolVector.size(); ++i){
    if(!boolVector[i]){
      index = i;
      break;
    }
  }
  if (index != -1){
    std::cout << "Found false at index: " << index << std::endl; //Output will be correct.
  } else {
    std::cout << "false not found" << std::endl;
  }
  return 0;
} 