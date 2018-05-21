//
//  SongValidator.hpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include "Song.h"
#include <string>
#include <vector>

class SongException {
private:
    std::vector<std::string> errors;
    
public:
    SongException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
};

class SongValidator {
public:
    SongValidator() {}
    static void validate(const Song &s);
};
