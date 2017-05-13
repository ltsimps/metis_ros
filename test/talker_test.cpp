#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <gtest/gtest.h>
#include <ros/service_client.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <memory>
#include <Parser.hpp>
#include <Sentiment.hpp>
#include <PositiveSentiment.hpp>
#include <NegativeSentiment.hpp>
#include <ros/ros.h>
#include <ros/service_client.h>
#include "metis_ros/strings.h"









using std::string;
using std::cout;
using std::cin;

/*

//test the strings service existence
TEST(TalkeSuite, existence_Test) {
  ros::NodeHandle nh; 
  ros::ServiceClient client;
  //call service and check for existence
  client = nh.serviceClient < metis_ros::strings > ("change_output");
  bool exists(client.waitForExistence(ros::Duration(20)));
  EXPECT_TRUE(exists);

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
  ns.loadWordlist();

  EXPECT_GT(ns.getWordlist().size(), 0);
}

TEST(file_test, posLoadWordlist) {
  PositiveSentiment ps;
  ps.loadWordlist();

  EXPECT_GT(ps.getWordlist().size(), 0);
}

/**
 * @brief Test analysis of Sentiment class for detection of negative words given stub histogram simulating voice input. 
 *
 */
TEST(input,  NegAnalysis) {
  Parser  p;
  NegativeSentiment ns;
  ns.loadWordlist();
  


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

  ns.analysis(testMap);
  int negativeEmotionScore = ns.getEmotionScore();
  EXPECT_GT(negativeEmotionScore, 0);


}



/**
 * @brief Test analysis of Sentiment class for specific number of negative words. 
 *
 */
TEST(input,  exactWordScoreNegative) {
  Parser  p;
  NegativeSentiment ns;
  ns.loadWordlist();



  std::vector<string> words;
  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");
  words.push_back("TOM");
  words.push_back("HELLO");
  words.push_back("HELLO");
  words.push_back("GUESS");

  std::map<string , int > testMap = p.generateHistogram(words);

  ns.analysis(testMap);
  int negativeEmotionScore = ns.getEmotionScore();
  EXPECT_EQ(negativeEmotionScore, 1);

}




/*
 * @brief  analysis of Sentiment class for specific number of positive  words. 
 *
 */
TEST(input,  exactWordScorePositive) {
  Parser  p;
  NegativeSentiment ns;
  ns.loadWordlist();



  std::vector<string> words;
  words.push_back("LOVE");
  words.push_back("HELLO");
  words.push_back("HELLO");
  words.push_back("GUESS");

  std::map<string , int > testMap = p.generateHistogram(words);

  ns.analysis(testMap);
  int negativeEmotionScore = ns.getEmotionScore();
  EXPECT_EQ(negativeEmotionScore, 1);

}


/**
 * @brief Test analysis of Sentiment class for detection of positive  words given stub histogram simulating voice input. 
 *
 */

TEST(input,  posAnalysis) {
  Parser  p;
  PositiveSentiment ps;
  ps.loadWordlist();



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

  ps.analysis(testMap);
  int positiveEmotionScore = ps.getEmotionScore();
  EXPECT_GT(positiveEmotionScore, 0);


}




int main(int argc, char **argv) {

  ros::init(argc, argv, "talker_test");

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
