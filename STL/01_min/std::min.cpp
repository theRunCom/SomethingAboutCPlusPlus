#include <algorithm>
#include <iostream>

int main() {
  std::cout << std::min(2020, 2023) << "\n"
            << std::min({1998, 2011, 2014, -5}) << "\n"
            << std::min(-10, -5,
                        [](int a, int b) { return std::abs(a) < std::abs(b); })
            << "\n"
            << std::min({20, -30, -10, 40},
                        [](int a, int b) { return std::abs(a) < std::abs(b); })
            << "\n";
  return 0;
}