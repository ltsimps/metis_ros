/**
 * @file   Sentitment.cpp
 * @date   Mar 13, 2017
 * @author Lamar Simpson
 *@brief Class that analyzes text and returns perceived sentiment.
 *Copyright 2017 Lamar Simpson
 */



#pragma once
#include <string>
#include <set>
#include <map>
#include <vector>


class Sentiment{
 public:
  /**
   * @brief analysis  is a virtual function meant to be overriden by derived classes for the base classes analysis needs.
   * @return std::string.
   */
  virtual std::string analysis(std::map<std::string, int> histogram) = 0;

  /**
    * @brief loadwordlist for the Sentiment class is a virtual function meant to be overriden by derived classes to define functionality for sentiment .
   */
   void loadWordlist();

  /**
    * @brief setEmotionScore assigns a value to the emotionscore class member variable
    * @param int emotionScore
   */
  void setEmotionScore(int emotionScore);


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
    * @brief getWordlist returns the value of the wordlist class member set
    *
    */
  std::set<std::string> getWordlist() const;


 protected:
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
