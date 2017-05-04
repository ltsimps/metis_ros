/**
 * @file   main.cpp
 * @date   May 05, 2017
 * @author Lamar Simpson
 * copyright 2017 Lamar Simpson
 * @brief Parsed input from the user.
 */
#include <glob.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <Parser.hpp>
#include <Sentiment.hpp>
#include <PositiveSentiment.hpp>
#include <NegativeSentiment.hpp>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
  * @brief  Glob function that gets the contents of  files directory
  * @return boolean value denoting the user's desire to continue the program.
 */
std::vector<string> dsiplayCurentFiles(const string& pattern) {
    glob_t glob_result;
    glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
    std::vector<string> files;
    for (unsigned int i=0 ; i< glob_result.gl_pathc; ++i) {
        files.push_back(string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return files;
}

/**
 * @brief demo allows the user to choose between inputing their own text for analysis or using file input
 */
std::string demo() {
  string response = "";

std::cout << "For file processing write 'file', write 'user' "
      "for the command line input" << std::endl;
  std::cin >> response;

return response;
}

/**
 * @brief  getUserInput() obtains user input and processes it.
 */
void getUserInput() {
  /*
    std::cout << " " << std::endl;
    Parser  p;
    PositiveSentiment ps;
    NegativeSentiment ns;
    Sentiment *sp;
    sp = &ps;
    std::vector<string> vectorOutput;
    string path = " ";
    string strOutput = " ";
    std::map<string, int> histogram;


    std::cout << "Enter Text to be analyzed. ";
    std::cout << "Press enter  on blank line when you're done." << std::endl;
    vectorOutput =  p.getInput();


    strOutput = p.stringConversion(vectorOutput);
    std::cout<< "INPUT Below \n" << strOutput << std::endl;
    histogram =  p.generateHistogram(vectorOutput);


  sp->loadWordlist();
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();

  if (positiveScore > negativeScore)
     std::cout << "\033[1;34mPOSITIVE\033[0m\n" << std::endl;
  else if (positiveScore < negativeScore)
     std::cout << "\033[1;31mNEGATIVE\033[0m\n" << std::endl;
  else
     std::cout << "\033[1;36mNEUTRAL\033[0m\n" << std::endl;
*/
}

/**
 * @brief gets the file input from the user and processes the data for analysis
 */

void getFileInput() {
   /*
    std::cout << " " << std::endl;
    Parser  p;
    PositiveSentiment ps;
    NegativeSentiment ns;
    Sentiment *sp;
    sp = &ps;
    std::vector<string> vectorOutput;
    string path = " ";
    string strOutput = " ";
    std::map<string, int> histogram;


    string filename = "";
    std::cout << "Current File Choices  " << std::endl;

    std::vector<string> posFiles = dsiplayCurentFiles("../Positive_Examples/*");
    std::vector<string> negFiles = dsiplayCurentFiles("../Negative_Examples/*");

    for (auto file : posFiles) {
      std::cout << file << " " << std::endl;
    }

    std::cout << std::endl;

    for (auto file : negFiles) {
         std::cout << file << " " << std::endl;
    }

    std::cout << "enter file name " << std::endl;
    std::cin >> filename;

    vectorOutput = p.getFileInput(filename);

    strOutput = p.stringConversion(vectorOutput);
    cout<< "INPUT Below \n" << strOutput << endl;
    histogram =  p.generateHistogram(vectorOutput);


  sp->loadWordlist();
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();

  if (positiveScore > negativeScore)
    std::cout << "\033[1;34mPOSITIVE\033[0m\n" << std::endl;
  else if (positiveScore < negativeScore)
    std::cout << "\033[1;31mNEGATIVE\033[0m\n" << std::endl;
  else
    std::cout << "\033[1;36mNEUTRAL\033[0m\n" << std::endl;
*/
}




int main() {
 /* string response =  "Y";


  while (response == "Y" || response == "y") {
    std::cin.clear();

    std::string processing = demo();
  if (processing == "user") {
    getUserInput();
  } else if (processing == "file") {
    getFileInput();

  } else {
    std::cout << "Bad Input please enter file or user (all lowercase)\n"
        << std::endl;
    continue;
  }

  std::cout << "Enter y or Y if you wish to continue " << std::endl;
  std::cin >> response;
}*/
  return 0;
}
