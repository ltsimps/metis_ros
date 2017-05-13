/**
 * @file   Sentitment.cpp
 * @date   Mar 14, 2017
 * @author Lamar Simpson
 *@brief Class that serves as an interface for Sentiment.
 *Copyright 2017 Lamar Simpson
 */
#include <Sentiment.hpp>
#include <iostream>
#include <string>

using std::string;

/**
    * @brief getEmotionScore returns the value of the emotionscore class member variable
    *
  */
/*
int Sentiment::getEmotionScore() const  {
    return emotionScore;
  }

*/


 /**
   * @brief setEmotionScore assigns a value to the emotionscore class member variable
   * @param int emotionScore
 */

/*
void Sentiment::setEmotionScore(int emotionScore) {

    this->emotionScore = emotionScore;
  }

*/
  /**
      * @brief getWordlist returns the value of the wordlist class member set
      *
   */
/*
  std::set<std::string> Sentiment::getWordlist() const {
    return wordlist;
  }

*/

  /**
    * @brief setWordlist assigns a value to the wordlist class member set
    * @param std::set<string> wordlist
  */
/*
void Sentiment::setWordlist(std::set<std::string> wordlist) {
    this->wordlist = wordlist;
  }
*/

  /**
     * @brief loadwordlist for the Sentiment class is a virtual function meant to be overriden by derived classes to define functionality for sentiment .
    */
void Sentiment::loadWordlist()  {
    std::cout << "Base class word list "<< std::endl;
  }

   /**
     * @brief analysis  is a virtual function meant to be overriden by derived classes for the base classes analysis needs.
     * @return std::string.
    */
std::string Sentiment::analysis(std::map<std::string, int> histogram) {
     /*for ( const auto & p : histogram ) {
       std::cout << "Word '" << p.first << "occurs " << p.second << " times.\n";
     }*/


        return " ";
}
int main() {
return 0;
}
