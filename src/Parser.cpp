/**
 * @file   Parser.cpp
 * @date   Mar 11, 2017
 * @author Lamar Simpson
 * Copyright 2017 Lamar Simpson
 *@brief Class that handles all input and parses it out into a format that Semantics class can use.
 **@details implementation of Parser class.
 */
#include <Parser.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include<fstream>
#include <sstream>


using std::cin;
using std::string;

/**
  * @brief  Constructor Parser Class
 */
Parser::Parser() {
  this->input = "";
}


/**
  * @brief  setInput assigns a value to the Parser class member variable input.
  * @param  input  std::string
 */

void Parser::setInput(std::string input) {
this->input = input;
}

 /**
  * @brief  stringCoversion takes an input vector and returns string output
  * @param  input  std::vector<std::string>
  * @return string
 */
std::string Parser::stringConversion(std::vector<std::string> input) {
//std::ostringstream oss;

if(!input.empty()) {
//std::copy(input.begin(), input.end(),
//std::ostream_iterator<string>(oss, " "));
}
  //return oss.str();
  return "";
}


  /**
   * @brief Handles getting input from File exemplars or user specified files.
   * @return std::vector<std::string> that contains all input from files specified by the user or file exemplars.
  */

std::vector<std::string> Parser::getInput() {
  string line;
  string input = "";
  std::vector<string> file;

  char c = std::cin.peek();  // peek character

  if (c == '\n') {
    cin.ignore();
  }

  while ( getline(cin, line) ) {
       if (line.empty())
          break;
       std::stringstream ss(line);
       string s;

       while (getline(ss, s, ' ')) {
         file.push_back(s);
       }
  }

  return file;
}


/**
   * @brief Handles getting input from File exemplars or user specified files.
   * @return std::vector<std::string> that contains all input from files specified by the user or file exemplars.
  */
std::vector<std::string> Parser::getFileInput(std::string in ) {
  // std::ifstream inputFile{"../Positive_Examples/Positive_Example_1.txt"};

  //std::ifstream inputFile{in};


  std::vector<string> file;

/*
  // test file open
  if (inputFile) {
      string value;

      // read the elements in the file into a vector
      while ( inputFile >> value ) {
          file.push_back(value);
      }
      std::cin.clear();
      // input>>std:flush;
  }

 */
  return file;
}



  /**
   * @brief  generateHistogram takes a input vector and counts the frequency of words in that input and return a map
   * @param  input  std::vector<std::string>
   * @return map<std::string, int>
   */
std::map<string, int> Parser::generateHistogram(std::vector<string> input) {
  std::map<string, int> histogram;

  //for (const string & s : input) { ++histogram[s]; }

/*
  for (const auto & p : histogram)
  {
      std::cout << "Word '" << p.first << "' occurs " << p.second << " times.\n";
  }
  */

  return histogram;
}

int main (){

 return 0;
}
