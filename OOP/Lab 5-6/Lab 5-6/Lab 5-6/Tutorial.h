//
//  Tutorial.h
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Tutorial_h
#define Tutorial_h

#include <iostream>

class Duration {
private:
  double minutes;
  double seconds;

public:
  Duration() : minutes(0), seconds(0) {}
  Duration(double min, double sec) : minutes(min), seconds(sec) {}

  double getMinutes() const { return minutes; }
  double getSeconds() const { return seconds; }
  void setMinutes(double min) { minutes = min; }
  void setSeconds(double sec) { seconds = sec; }
};

class Tutorial {
private:
  std::string title;
  std::string presenter;
  Duration duration;
  int likes;
  std::string source; // youtube Link

public:
  // default constructor for a Tutorial
  Tutorial();

  // constructor with parameters
  Tutorial(const std::string &artist, const std::string &title,
           const Duration &duration, const int &likes,
           const std::string &source);

  std::string getTitle() const { return title; }
  std::string getPresenter() const { return presenter; }
  Duration getDuration() const { return duration; }
  std::string getSource() const { return source; }
  int getLikes() const { return likes; }
  // Plays the current Tutorial: the page corresponding to the source link is
  // opened in a browser.
  void upLike();
  friend bool operator==(const Tutorial &a, const Tutorial &b);
  void play();
  void tests();
  void titleTest();
  void presenterTest();
  void durationTest();
  void sourceTest();
  void likeTest();
  void upLikeTest();
  void equalTest();
};

#endif /* Tutorial_h */
