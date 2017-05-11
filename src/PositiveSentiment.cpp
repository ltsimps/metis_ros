
/**
 * @file   PositiveSentitment.cpp
 * @date   Mar 14, 2017
 * @author Lamar Simpson
 *@brief Class that analyzes text for Positive sentiment.
 *Copyright 2017 Lamar Simpson
 */
#include <PositiveSentiment.hpp>
#include <map>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>


using std::map;
using std::string;


/**
 * @brief loadwordlist for the PositiveSentiment class preloads a dictionary of negative words.
*/

void PositiveSentiment::loadWordlist() {
  std::ifstream inputFile;
  inputFile.open("/home/viki/catkin_ws/src/metis_ros/positive_words.txt");


  std::set<string> wordlist;

  std::cout << " IN LOAD WORD LIST" << std::endl;
    // test file open
  if (inputFile) {
    string value;

    // read the elements in the file into a vector
    while ( inputFile >> value ) {
      wordlist.insert(value);
    }
  }

  std::set<string>::iterator it;

  for ( it = wordlist.begin(); it != wordlist.end(); it++ ) {
    std::cout << *it << std::endl;
  }
  setWordlist(wordlist);
}



/**
  * @brief analysis takes in a histogram of input and returns a negative or positive score based on word frequency.
  * @return std::string.
*/
std::string PositiveSentiment::analysis(std::map<string, int> histogram)  {
    int score = 1;
    map<string, int>::iterator it;

    for ( it = histogram.begin(); it != histogram.end(); it++ ) {
            std::cout << it->first  // string (key)
              << ':'
              << it->second   // string's value
              << std::endl;
              if (wordlist.find(it->first) != wordlist.end()) {
                  score += it->second;
                  std::cout << " IN word llist if " << std::endl;
              }
    }
    setEmotionScore(score);

    return " ";
}



/**
 * @brief getEmotionScore returns the value of the emotionscore class member variable
 *
*/

int PositiveSentiment::getEmotionScore() const  {
  return emotionScore;
}



/**
 * @brief setEmotionScore assigns a value to the emotionscore class member variable
 * @param int emotionScore
*/

void PositiveSentiment::setEmotionScore(int emotionScore) {
  this->emotionScore = emotionScore;
}


/**
 * @brief getWordlist returns the value of the wordlist class member set
 *
*/

std::set<std::string> PositiveSentiment::getWordlist() const {
  return wordlist;
}


/**
 * @brief setWordlist assigns a value to the wordlist class member set
 * @param std::set<string> wordlist
*/

void PositiveSentiment::setWordlist(std::set<std::string> wordlist) {
  this->wordlist = wordlist;
}
