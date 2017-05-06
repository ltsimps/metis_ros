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

Metis is a robot that shows the emotional content of it's surroundings. This project deals with the perception by analyzing Sentiment. The plan is to no only have this run in gazebo, but also be run on an arduino board.This program reads input from the user or from files and denotes whether it is positive or negative. The program also listens real time for voice input and gives back the sentiment analysis. 


## Demo
When running the program simply enter the words you would like to have anaylzed and Metis will tell you if they are positive, Neutral or Negative. You also have the option of entering a file or picking from the exemplar list.

![Alt text](./UserInput.png?raw=true "User Input Demo")



## Exemplars 
This project contains a number of examples in. You can also enter your own files here.

$../Positive_Examples 
$../Negative_Examples

These exemplars can be used to for analysis.


## SIP Documentation 
- Product Backlog
https://docs.google.com/spreadsheets/d/1r4ecKSJpceprQqqMgkKxplhz_-Z3uScsltyCwwQ0y3k/edit#gid=0

- Iteratartion Backlog
https://docs.google.com/a/terpmail.umd.edu/spreadsheets/d/1wB8Fqtjaw88LNrhkzxSVgAWAnU5Pb_bEJZ7RIEKxKpw/edit?usp=sharing


## Installation

- Checkout the repo (and submodules)
```
$ git clone --https://github.com/ltsimps/Midterm.git


## Build and Run Project
$ mkdir build
$ cd build
$ cmake ..
$ make

## To Run the program
$ ./app/metis-app

## To Test the program
./test/test-cpp

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
	
	
	
