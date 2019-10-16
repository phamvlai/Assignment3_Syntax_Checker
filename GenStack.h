#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
class GenStack {
private:
  vector <T> arr;
  int end;
  int MAX = (int) (1e10);
public:
  GenStack();
  ~GenStack();
  void push(T val);
  void pop();
  bool empty();
  bool full();
  T top();
};

#endif
