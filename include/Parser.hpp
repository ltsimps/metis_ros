#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

/**
 *
 *  @copyright GNU Public License.
 *  @file      Parser.hpp
 *  @brief     Parser Class Definition. Class designed to process user input.
 *  @author    Lamar Simpson ( https://github.com/ltsimps )
 *  @date      02/20/2017
 *
 */

class Parser {
 public:
  Parser();

  /**
   * @brief Handles getting user input from the commandline.
   * @return std::vector<std::string> that contains all input from user on commandline.
   */
  std::vector<std::string> getInput();

  /**
     * @brief Handles getting input from File exemplars or user specified files.
     * @return std::vector<std::string> that contains all input from files specified by the user or file exemplars.
    */
  std::vector<std::string> getFileInput(std::string in);

  /**
   * @brief  generateHistogram takes a input vector and counts the frequency of words in that input and return a map
   * @param  input  std::vector<std::string>
   * @return map<std::string, int>
   */
  std::map<std::string, int> generateHistogram(std::vector<std::string> input);

  /**
     * @brief  stringCoversion takes an input vector and returns string output
     * @param  input  std::vector<std::string>
     * @return string
     */
  std::string stringConversion(std::vector<std::string> input);
  // std::string stringConversion(std::map<std::string, int> input);


  /**
    * @brief  setInput sets the input class member variable.
    * @param  input std::string
    * @return string
  */
  void setInput(std::string input);


 private:
  /**
    * @brief  input is class member variable that hold input from files or user input on the commandline.
  */
  std::string input;
};
