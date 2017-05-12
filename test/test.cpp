/**
 * @file   tets.cpp
 * @date   Mar 09, 2017
 * @author Lamar Simpson
 * copyright 2017 Lamar Simpson
 *@brief Test file for Metis Program.
 */

#include <gtest/gtest.h>
#include <map>
#include <vector>
#include <iostream>
#include<fstream>
#include <string>
#include <set>
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
 * @brief Test the input function on file input to make sure it returns nonzero values when reading files
 */

TEST(input, inputNonzero) {
Parser  p;
std::vector<string> testInput;
testInput = p.getFileInput("../Positive_Examples/Positive_Example_1.txt");
EXPECT_GT(testInput.size(), 0);
}

/**
 * @brief Test the histogram function to make sure it returns words and frequencies.
 *
 */
TEST(input, histogram) {
  Parser  p;
  std::vector<string> words;
  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");
  words.push_back("TOM");
  words.push_back("JOB");
  words.push_back("HELLO");
  words.push_back("HELLO");
  words.push_back("HELLO");
  words.push_back("GUESS");

  std::map<string , int > testMap = p.generateHistogram(words);
  EXPECT_EQ(testMap["GUESS"] , 2);
  EXPECT_EQ(testMap["HANGMAN"] , 1);
  EXPECT_EQ(testMap["DIFFICULT"] , 1);
  EXPECT_EQ(testMap["TOM"] , 1);
  EXPECT_EQ(testMap["JOB"] , 1);
  EXPECT_EQ(testMap["HELLO"] , 3);
}

TEST(file_test, NegLoadWordlist) {
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ns;
  sp->loadWordlist();

  EXPECT_GT(sp->getWordlist().size(), 0);
}

TEST(file_test, posLoadWordlist) {
  PositiveSentiment ps;
  Sentiment *sp;
  sp = &ps;
  sp->loadWordlist();

  EXPECT_GT(sp->getWordlist().size(), 0);
}

TEST(sentiment, positiveSentiment1) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Positive_Examples/Positive_Example_1.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(positiveScore, negativeScore);
}


TEST(sentiment, positiveSentiment2) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Positive_Examples/Positive_Example_2.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(positiveScore, negativeScore);
}

TEST(sentiment, positiveSentiment3) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Positive_Examples/Positive_Example_3.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(positiveScore, negativeScore);
}






TEST(sentiment, negativeSentiment1) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Negative_Examples/Negative_Example_1.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(negativeScore, positiveScore);
}

TEST(sentiment, negativeSentiment2) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Negative_Examples/Negative_Example_2.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(negativeScore, positiveScore);
}



TEST(sentiment, negativeSentiment3) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Negative_Examples/Negative_Example_3.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_GT(negativeScore, positiveScore);
}

TEST(sentiment, neuralSentiment) {
  Parser  p;
  PositiveSentiment ps;
  NegativeSentiment ns;
  Sentiment *sp;
  sp = &ps;

  std::vector<string> vectorOutput;
  std::map<string, int> histogram;
  vectorOutput = p.getFileInput("../Random_Examples/Random_Example_3.txt");




  sp->loadWordlist();
  histogram =  p.generateHistogram(vectorOutput);
  sp->analysis(histogram);
  int positiveScore = sp->getEmotionScore();

  sp  = &ns;
  sp->loadWordlist();
  sp->analysis(histogram);
  int negativeScore = sp->getEmotionScore();


  EXPECT_EQ(negativeScore, positiveScore);
}

