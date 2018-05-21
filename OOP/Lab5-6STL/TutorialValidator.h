#pragma once
#include "Tutorial.h"
#include <string>
#include <vector>

class TutorialException {
private:
  std::vector<std::string> errors;

public:
  TutorialException(std::vector<std::string> _errors);
  std::vector<std::string> getErrors() const;
};

class TutorialValidator {
public:
  TutorialValidator() {}
  static void validate(const Tutorial &s);
  void tests();
};
