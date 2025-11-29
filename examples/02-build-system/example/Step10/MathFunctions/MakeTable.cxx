#include <cmath>
#include <fstream>
#include <iostream>


int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Required output file" << std::endl;
    return 1;
  }

  std::ofstream fout(argv[1]);
  if (!fout) {
    std::cerr << "Failed to open output file" << std::endl;
    return 1;
  }

  fout << "static double sqrtTable[] = {\n";
  for (int i = 0; i < 10; ++i) {
    double v = std::sqrt(static_cast<double>(i));
    fout << "  " << v;
    if (i < 9) {
      fout << ",";
    }
    fout << "\n";
  }
  fout << "};\n";

  return 0;
}
