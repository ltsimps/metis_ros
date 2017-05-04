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


class NegativeSentiment:Sentiment {
 public:
 /**
  * @brief analysis for NegativeSentiment calculates the negative score for input.
  * @return std::string.
 */
virtual std::string analysis(std::map<std::string, int> histogram);

 /**
  * @brief loadwordlist for the NegativeSentiment class loads a negative wordlist.
 */
void loadWordlist();

 private:
};
