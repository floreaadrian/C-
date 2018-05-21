//
//  RepositoryExceptions.cpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
    return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string & msg): message{msg}
{
}

const char * RepositoryException::what()
{
    return this->message.c_str();
}

const char * DuplicateSongException::what()
{
    return "There is another song with the same artist and title!";
}
