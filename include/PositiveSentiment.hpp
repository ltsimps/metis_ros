/**
 * @file   PositiveSentitment.hpp
 * @date   Mar 14, 2017
 * @author Lamar Simpson
 *@brief  Header Class for NegativeSentiment that analyzes text for Negative sentiment.
 *Copyright 2017 Lamar Simpson
 */

#pragma once
#include <map>
#include <string>
#include <Sentiment.hpp>


class PositiveSentiment:public Sentiment {
 public:
  /**
    * @brief analysis for NegativeSentiment calculates the negative score for input.
    * @return std::string.
   */
  std::string analysis(std::map<std::string, int> histogram) override;

  /**
    * @brief loadwordlist for the NegativeSentiment class loads a negative wordlist.
   */
  void loadWordlist() override;

 private:
};
