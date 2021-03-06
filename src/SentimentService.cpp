/**
 * @file   SentimentService.cpp
 * @date   May 11, 2017
 * @author Lamar Simpson
 * copyright 2017 Lamar Simpson
 * @brief Parsed input from the user.
 */
#include <glob.h>
#include <std_msgs/Int8.h>
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
#include "ros/ros.h"
#include "metis_ros/strings.h"




using std::string;
using std::cout;
using std::cin;
using std::endl;

ros::Publisher chatter_pub;
int score;
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


std::vector<string> split(const char *str, char c = ' ') {
    std::vector<string> result;

    do {
        const char *begin = str;

        while (*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}


bool negative_output(metis_ros::stringsRequest   &req, // NOLINT
                    metis_ros::stringsResponse  &resp) { // NOLINT 
     ROS_WARN_STREAM("Now getting Negative Score");
     int NegativeScore, PositiveScore;

     std::map<string, int> histogram;
     std::vector<string> vectorOutput;
     vectorOutput = split(req.input.c_str());
     Parser  p;
     NegativeSentiment ns = NegativeSentiment();
     PositiveSentiment ps = PositiveSentiment();
     // ROS_ERROR_STREAM("There is no string value that you input ");
     ns.loadWordlist();
     histogram = p.generateHistogram(vectorOutput);
     ns.analysis(histogram);
     NegativeScore = ns.getEmotionScore();
     ps.loadWordlist();
     ps.analysis(histogram);
     PositiveScore = ps.getEmotionScore();
     ROS_WARN_STREAM(NegativeScore);
     ROS_WARN_STREAM(PositiveScore);

  if (PositiveScore > NegativeScore)
    std::cout << "\033[1;34mPOSITIVE\033[0m\n" << std::endl;
  else if (PositiveScore < NegativeScore)
    std::cout << "\033[1;31mNEGATIVE\033[0m\n" << std::endl;
  else
    std::cout << "\033[1;36mNEUTRAL\033[0m\n" << std::endl;

  score =   PositiveScore - NegativeScore;
  std_msgs::Int8 msg;
  msg.data = score;
  ROS_INFO("%d", msg.data);
  chatter_pub.publish(msg);

  return true;
}



int main(int argc, char **argv) {
  ros::init(argc, argv, "SentimentService");
  ros::NodeHandle n;
  // service to change string output that launches in xterm window.
  ros::ServiceServer negative_service;
  negative_service  = n.advertiseService("negative_output", negative_output);

  ros::NodeHandle v;
  chatter_pub = v.advertise<std_msgs::Int8>("score", 1000);
  ros::spin();

  return 0;
}
