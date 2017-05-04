/**
 * @file   PositiveSentitment.cpp
 * @date   Mar 14, 2017
 * @author Lamar Simpson
 *@brief Class that analyzes text for Positive sentiment.
 *Copyright 2017 Lamar Simpson
 */
#include<PositiveSentiment.hpp>
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <set>

using std::cin;
using std::string;




/**
  * @brief loadwordlist for the NegativeSentiment class preloads a dictionary of positive words.
 */

void PositiveSentiment::loadWordlist()  {
    //std::ifstream inputFile{"../positive_words.txt"};

    std::set<string> wordlist;


    // test file open
    /*if (inputFile) {
        string value;

        // read the elements in the file into a vector
        while ( inputFile >> value ) {
            wordlist.insert(value);
        }
    }*/

    // close the file
   /* for ( auto token : wordlist ) {
      std::cout << token << std::endl;
    }
   */
    //setWordlist(wordlist);
}




  /**
   * @brief analysis takes in a histogram of input and returns a negative or positive score based on word frequency.
   * @return std::string.
   */

std::string PositiveSentiment::analysis(std::map<string, int> histogram) {
    int score = 1;
/*
     for (const auto & p : histogram) {
         if ( wordlist.find(p.first) != wordlist.end() ) {
           score +=p.second;
         }
     }

    setEmotionScore(score);
 */
  return " ";
}



int main(){



return 0;

}
