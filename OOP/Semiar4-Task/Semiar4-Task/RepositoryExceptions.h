//
//  RepositoryExceptions.hpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
    std::string message;
    
public:
    FileException(const std::string& msg);
    virtual const char* what();
};

class RepositoryException : public std::exception
{
protected:
    std::string message;
    
public:
    RepositoryException();
    RepositoryException(const std::string& msg);
    virtual ~RepositoryException() {}
    virtual const char* what();
};

class DuplicateSongException : public RepositoryException
{
    const char* what();
};
