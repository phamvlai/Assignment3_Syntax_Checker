#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "GenStack.h"

using namespace std;


template <typename T>
GenStack<T> :: GenStack() {
  end = 0;
  arr.resize(MAX);
}

template <typename T>
GenStack<T> :: ~GenStack() {
  arr.clear();
}

template <typename T>
void GenStack<T> :: push(T val) {
  try {
    if (end == MAX) {
      throw "Limit reached";
    }
    arr[end++] = val;
  } catch (string message) {
    cerr << "There is an exception : " + message << endl;
    exit(0);
  }
}

template <typename T>
void GenStack<T> :: pop() {
  try {
    if (end == 0) {
      throw "Empty stack";
    }
    end--;
  } catch (const char *message) {
    cerr << "There is an exception : " << message << endl;
    exit(0);
  }
}

template <typename T>
bool GenStack<T> :: empty() {
  return end == 0;
}

template <typename T>
bool GenStack<T> :: full() {
  return end == MAX;
}


template <typename T>
T GenStack<T> :: top() {
  try {
    if (end == 0) {
      throw "Empty stack";
    }
    return arr[end - 1];
  } catch (string message) {
    cerr << "There is an exception : " + message << endl;
    exit(0);
  }
}
