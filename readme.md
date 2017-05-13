## Midterm-Metis 
[![Build Status](https://travis-ci.org/ltsimps/Midterm.svg?branch=master)](https://travis-ci.org/ltsimps/Midterm)

[![Coverage Status](https://coveralls.io/repos/github/ltsimps/Midterm/badge.svg?branch=master)](https://coveralls.io/github/ltsimps/Midterm?branch=master)
---

## Overview

Initial Midterm Commit 
- cmake
- googletest

## Description of Project
Metis:

Metis is a robot that shows the emotional content of its surroundings. This project deals with the perception by analyzing Sentiment. The plan is to no only have this run in gazebo, but also be run on an arduino board.This program reads input from the user or from files and denotes whether it is positive or negative. The program also listens real time for voice input and gives back the sentiment analysis. 

## Demo
When running the program simply enter the words you would like to have anaylzed and Metis will tell you if they are positive, Neutral or Negative. You also have the option of entering a file or picking from the exemplar list.



[DEMO](https://www.youtube.com/watch?v=bseQLcLv7SQ)




## Exemplars 
This project contains a number of examples in. You can also enter your own files here.
- Files
  - ../Positive_Examples 
  - ../Negative_Examples

These exemplars can be used to for analysis.


## SIP Documentation 
- Product Backlog
https://docs.google.com/spreadsheets/d/1r4ecKSJpceprQqqMgkKxplhz_-Z3uScsltyCwwQ0y3k/edit#gid=0

- Iteration Backlog
https://docs.google.com/spreadsheets/d/1r4ecKSJpceprQqqMgkKxplhz_-Z3uScsltyCwwQ0y3k/edit#gid=1733421727



## Installation
```
$ git clone --https://github.com/ltsimps/metis_ros.git

$ sudo apt-get install arduino arduino-core

$ sudo apt-get install ros-indigo-rosserial ros-indigo-rosserial-arduino ros-ind
igo-rosserial-server

$ sudo apt-get install pocketsphinx-hmm-wsj1

$ sudo apt-get install pocketsphinx-lm-wsj

$ sudo apt-get install python-pocketsphinx
```
## Dependencies
- Ubuntu 14.04
- ROS indigo
- TurtleBot_Gazebo
- Package Dependencies
    - roscpp
    - rosserial
    - arduino-core 
    - std_msgs
    - message_generation
    - pocketsphinx
    - rostest
    - rosbag

## Build
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
$ cd ~/catkin_ws/
$ catkin_make
$ source ./src/setup.bash
```

## To Run the program
$ roslaunch metis_launch.launch record:=(false/true)

## To Test the program
```
$ rostest metis_ros talker_test.launch

```

## Doxygen Documentation
Contained in the docs folder of the project.

$ cd docs/


## References
  Minqing Hu and Bing Liu. "Mining and Summarizing Customer Reviews." 
        Proceedings of the ACM SIGKDD International Conference on Knowledge 
        Discovery and Data Mining (KDD-2004), Aug 22-25, 2004, Seattle, 
        Washington, USA, 
    Bing Liu, Minqing Hu and Junsheng Cheng. "Opinion Observer: Analyzing 
        and Comparing Opinions on the Web." Proceedings of the 14th 
        International World Wide Web conference (WWW-2005), May 10-14, 
        2005, Chiba, Japan.

  Theresa Wilson, Janyce Wiebe, Paul Hoffmann
	Recognizing Contextual Polarity in Phrase-Level Sentiment Analysis
	Intelligent Systems Program Department of Computer Science Intelligent Systems Program
	University of Pittsburgh University of Pittsburgh University of Pittsburgh Pittsburgh, PA 15260
	Pittsburgh, PA 15260 Pittsburgh, PA 15260
	twilson@cs.pitt.edu wiebe@cs.pitt.edu hoffmanp@cs.pitt.edu
	http://people.cs.pitt.edu/~wiebe/pubs/papers/emnlp05polarity.pdf
	
	
	
