#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "GenStack.cpp"

using namespace std;

// Determine what variables classified as Delimeter.
bool is_bracket(char delim) {
  bool b1 = delim == '(' || delim == ')';
  bool b2 = delim == '[' || delim == ']';
  bool b3 = delim == '{' || delim == '}';
  return b1 || b2 || b3;
}

// Main arguement to run program.
int main(int argc, char* argv[]) {
  // Check if a command line arguement file is entered.
  if (argc != 2) {
    cerr << "Please enter: ./a.out file_name" << endl;
    exit(0);
  } else {
    // Reads in the command line file name.
    string choice;
    string name = string(argv[1]);
    // While loop to keep the program running until the user decide to exit.
    while (true) {
      // Checks whether the file is availible to be read in.
      ifstream in(name);
      if (in.fail()) {
        cerr << "File could not be opened." << endl;
      } else {
        string line;
        // Number to keep count of the line in the file.
        int num = 1;
        GenStack <char> var;
        // While loop to continue until the end of the file.
        while (getline(in, line)) {
          int len = line.length();
          for (int i = 0; i < len; i++) {
            // Checks if the element from the file is not considered a Delimeter, then continues the loop until it is.
            if (!is_bracket(line[i])) {
              continue;
            }
            // Checks if the element is a Delimeter and then add it.
            if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
              var.push(line[i]);
            } else {
              if (var.empty()) {
                cout << "Line " << num << " : No " << line[i] << " expected" << endl;
                exit(0);
              }
              // Checks if the delimiters match and if not tells the user the error and which line.
              if (line[i] == ')') {
                if (var.top() != '(') {
                  cerr << "Line " << num << ": expected ";
                  if (var.top() == '[') cerr << "] ";
                  if (var.top() == '{') cerr << "} ";
                  cerr << "found ) " << endl;
                  exit(0);
                } else {
                  var.pop();
                }
              } else if (line[i] == ']') {
                if (var.top() != '[') {
                  cerr << "Line " << num << ": expected ";
                  if (var.top() == '(') cerr << ") ";
                  if (var.top() == '{') cerr << "} ";
                  cerr << "found ] " << endl;
                  exit(0);
                } else {
                  var.pop();
                }
              } else if (line[i] == '}') {
                if (var.top() != '{') {
                  cerr << "Line " << num << ": expected ";
                  if (var.top() == '(') cerr << ") ";
                  if (var.top() == '[') cerr << "] ";
                  cerr << "found } " << endl;
                  exit(0);
                } else {
                  var.pop();
                }
              }
            }
          }
          num++;
        }

        in.close();
        // Checks to see if there is a missing delimiter.
        if (!var.empty()) {
          cerr << "Reached end of file: missing ";
          if (var.top() == '(') cerr << ") ";
          if (var.top() == '[') cerr << "] ";
          if (var.top() == '{') cerr << "} ";
          exit(0);
        }
        cout << "Delimeter syntax is correct" << endl;
      }
      // Prompts the user if they would like to continue to read in another file.
      cout << "Do you want to continue? Y or N : ";
      cin >> choice;
      // Checks if user input is similar to yes and continue if so.
      if (choice == "YES" || choice == "yes" || choice == "y" || choice == "Y") {
        cout << "Please enter input file name : ";
        cin >> name;
        continue;
      }
      // If the user did not enter "yes", the program will end.
      else {
        break;
      }

  }
  }
  return 0;
}
