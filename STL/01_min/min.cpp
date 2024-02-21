#include <algorithm>
#include <initializer_list>
#include <iostream>

template <class T> const T &custom_min(const T &a, const T &b) {
  return (b < a) ? b : a;
}

template <class T, class Compare>
const T &custom_min(const T &a, const T &b, Compare comp) {
  return (comp(b, a)) ? b : a;
}

template <class T> T custom_min(std::initializer_list<T> ilist) {
  return *std::min_element(ilist.begin(), ilist.end());
}

template <class T, class Compare>
T custom_min(std::initializer_list<T> ilist, Compare comp) {
  return *std::min_element(ilist.begin(), ilist.end(), comp);
}

int main() {
  std::cout
      << custom_min(2020, 2023) << "\n"
      << custom_min({1998, 2011, 2014, -5}) << "\n"
      << custom_min(-10, -5,
                    [](int a, int b) { return std::abs(a) < std::abs(b); })
      << "\n"
      << custom_min({20, -30, -10, 40},
                    [](int a, int b) { return std::abs(a) < std::abs(b); })
      << "\n";
  return 0;
}