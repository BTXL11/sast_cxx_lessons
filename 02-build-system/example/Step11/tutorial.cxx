#include <iostream>
#include <string>

#include "MathFunctions.h"
#include "TutorialConfig.h"


int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  const double inputValue = std::stod(argv[1]);

  const double outputValue = mathfunctions::sqrt(inputValue);

  std::cout << inputValue << " is " << outputValue << std::endl;
  return 0;
}
