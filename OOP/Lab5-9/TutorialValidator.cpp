#include "TutorialValidator.h"

using namespace std;

TutorialException::TutorialException(std::vector<std::string> _errors)
    : errors{_errors} {}

std::vector<std::string> TutorialException::getErrors() const {
  return this->errors;
}

void TutorialValidator::validate(const Tutorial &s) {
  vector<string> errors;
  if (s.getTitle().size() < 3)
    errors.push_back("The title name cannot be less than 2 characters!\n");
  if (!isupper(s.getPresenter()[0]))
    errors.push_back(
        string("The name of the artist must start with a capital letter!\n"));
  if (s.getDuration().getMinutes() == 0 && s.getDuration().getSeconds() == 0)
    errors.push_back(string("The duration cannot be 0!\n"));

  // search for "www" or "http" at the beginning of the source string
  size_t posWww = s.getSource().find("www");
  size_t posHttp = s.getSource().find("http");
  if (posWww != 0 && posHttp != 0)
    errors.push_back("The youtube source must start with one of the following "
                     "strings: \"www\" or \"http\"\n");

  if (errors.size() > 0)
    throw TutorialException(errors);
}

void TutorialValidator::tests(){
    Tutorial t{"s","df",Duration{0,0},0,"hsd"};
    try{
        validate(t);
    }
    catch(TutorialException &e){
        for (auto s : e.getErrors())
            std::cout << s;
    }
}