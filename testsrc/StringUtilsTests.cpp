#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base, 1), "ello");
    //EXPECT_EQ(StringUtils::Slice(Base, -1), "o");
}

TEST(StringUtilsTest, Capitalize){
    std::string Base = "hello";
    EXPECT_EQ(StringUtils::Capitalize(Base), "Hello");
}

TEST(StringUtilsTest, Upper){
    std::string Base = "Hello";
    EXPECT_EQ(StringUtils::Upper(Base), "HELLO");
}

TEST(StringUtilsTest, Lower){
    std::string Base = "Hello";
    EXPECT_EQ(StringUtils::Lower(Base), "hello");
}

TEST(StringUtilsTest, LStrip){
    std::string Base = "     Hello     ";
    EXPECT_EQ(StringUtils::LStrip(Base), "Hello     ");
}

TEST(StringUtilsTest, RStrip){
    std::string Base = "     Hello     ";
    EXPECT_EQ(StringUtils::RStrip(Base), "     Hello");
}

TEST(StringUtilsTest, Strip){
    std::string Base = "     Hello     ";
    EXPECT_EQ(StringUtils::Strip(Base), "Hello");
}

TEST(StringUtilsTest, Center){
    std::string Base = "HelloHello";
    std::string UPPER = "Loveyou";
    EXPECT_EQ(StringUtils::Center(Base, 10), "HelloHello");
    EXPECT_EQ(StringUtils::Center(Base, 11), " HelloHello");
    EXPECT_EQ(StringUtils::Center(Base, 12), " HelloHello ");
    EXPECT_EQ(StringUtils::Center(UPPER, 1), "Loveyou");
    EXPECT_EQ(StringUtils::Center(UPPER, 8, 'a'), "Loveyoua");
}

TEST(StringUtilsTest, LJust){
    std::string Base = "Hello";
    EXPECT_EQ(StringUtils::LJust(Base, 10), "Hello          ");
}

TEST(StringUtilsTest, RJust){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::RJust(Base, 10), "          Hello");
}

TEST(StringUtilsTest, Replace){
    std::string Base = "Hello, good to see you guys and thank you for showing up";
    std::string Upper = "see";
    std::string out = "chat with";

    EXPECT_EQ(StringUtils::Replace(Base, Upper, out), "Hello, good to chat with you guys and thank you for showing up");
}

TEST(StringUtilsTest, Split){
    std::string Base = "Thank you for your teaching and help";
    std::vector< std::string> test = {"Thank", "you", "for", "your", "teaching", "and", "help"};

    EXPECT_EQ(StringUtils::Split(Base, ""), test);
}

TEST(StringUtilsTest, Join){
    std::string Base = "";
    std::vector< std::string> test = {"Thank", "you", "for", "your", "teaching", "and", "help", "! Have a good day!"};

    EXPECT_EQ(StringUtils::Join(Base, test), "Thank you for your teaching and help ! Have a good day!");
}

TEST(StringUtilsTest, ExpandTabs){
    std::string Base = "Hello\tChi\tEa\tEca\tEssay";

    EXPECT_EQ(StringUtils::ExpandTabs(Base, 1), "Hello Chi Ea Eca Essay");
    EXPECT_EQ(StringUtils::ExpandTabs(Base, 8), "Hello      Chi      Ea      Eca      Essay");
}

TEST(StringUtilsTest, EditDistance){
    
}
