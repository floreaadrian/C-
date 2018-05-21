//
// Created by Adrian-Paul Florea on 4/25/18.
//

#include <gtest/gtest.h>
#include "ClassName.h"
#include "../lib/googletest-master/googlemock/include/gmock/gmock-matchers.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        ClassName obj;
        ClassDeclaration(){
            obj;
        }
    };
}
TEST_F(ClassDeclaration,nameOfTheTest1){
    ASSERT_EQ("","");
}