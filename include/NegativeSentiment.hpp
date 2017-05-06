/**
 * @file   NegativeSentitment.hpp
 * @date   Mar 14, 2017
 * @author Lamar Simpson
 *@brief  Header Class for NegativeSentiment that analyzes text for Negative sentiment.
 *Copyright 2017 Lamar Simpson
 */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include <vector>
#include <set>
#include <Sentiment.hpp>



using std::cin;
using std::string;


class NegativeSentiment {
 public:
 /**
  * @brief analysis for NegativeSentiment calculates the negative score for input.
  * @return std::string.
 */
std::string analysis(std::map<std::string, int> histogram);

 /**
  * @brief loadwordlist for the NegativeSentiment class loads a negative wordlist.
 */
void loadWordlist();

  /**
    * @brief setWordlist assigns a value to the wordlist class member set
    * @param std::set<string> wordlist
  */
   void setWordlist(std::set<std::string> wordlist);
  /**
    * @brief getEmotionScore returns the value of the emotionscore class member variable
    *
  */
  int getEmotionScore() const;

 /**
   * @brief setEmotionScore assigns a value to the emotionscore class member variable
   * @param int emotionScore
 */

  void setEmotionScore(int emotionScore);


   /**
      * @brief getWordlist returns the value of the wordlist class member set
      *
   */

  std::set<std::string> getWordlist() const;
private:

 /**
    * @brief emotionScore that is used to calculate whether sentiment is negative or positive.
   */
  int emotionScore;
  /**
    * @brief Emotions  is an Enum that keeps track of emotion score to denote a negative or positive score.
   */
  enum Emotions {Positive = 1, Negative = -1 };

  /**
    * @brief color  is an Enum that emotional color for Metis
   */
  enum color {Blue = 1, Red = -1};

  /**
    * @brief wordlist is a set that holds the negative or positive wordlist.
   */
  std::set<std::string>wordlist;

};
