#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <cstdio>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    return str.substr(start, str.length() - start);
}

std::string Capitalize(const std::string &str) noexcept{
    // Replace code here
    auto copy = str;

    copy[0] = toupper(str[0]);

    for (size_t i = 1; str[i] != '\0'; i++) {
        copy[i] = tolower(copy[i]);
    }
    return copy;
}

std::string Upper(const std::string &str) noexcept{
    // Replace code here
    auto copy = str;

    for (size_t i = 0; str[i] != '\0'; i++) {
        copy[i] = toupper(copy[i]);
    }

    return copy;
}

std::string Lower(const std::string &str) noexcept{
    // Replace code here
    auto copy = str;

    for (size_t i = 0; str[i] != '\0'; i++) {
        copy[i] = tolower(copy[i]);
    }

    return copy;
}

std::string LStrip(const std::string &str) noexcept{
    // Replace code here
    int start = 0;
    int end = str.length();

    for (size_t i = 0; str[i] == ' '; i++) {
        start++;
    }

    return str.substr(start, end);
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    int start = 0;
    int end = str.length();

    for (size_t i = str.length() - 1; str[i] == ' '; i--) {
        end--;
    }

    return str.substr(start, end);
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return RStrip(LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    
    auto copy = str;
    int front = 0; int rear = 0; int operations = width - str.length();

    if (0 >= operations) {
        return copy;
    }
    
    if (operations % 2 == 1) {
        if (str.length() % 2 == 1) {
            rear = operations / 2 + 1;
            front = operations / 2;
        } else {
            front = operations / 2 + 1;
            rear = operations /2;
        }
    } else {
        rear = operations / 2;
        front = operations / 2;
    }

    for (size_t i = 0; i < front; i++) {
        copy.insert(0, 1, fill);
    }

    for (size_t j = 0; j < rear; j++) {
        copy.push_back(fill);
    }

    return copy;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    auto copy = str;

    for (size_t i = 0; i < width; i++) {
        copy.push_back(fill);
    }

    return copy;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    std::string copy = "";

    for (size_t i = 0; i < width; i++) {
        copy.insert(0, 1, fill);
    }
    
    return copy + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    auto copy = str;
    int Found = str.find(old);

    return str.substr(0, Found) + rep + str.substr(Found + old.length(), str.length());
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    auto copy = str;
    std::vector< std::string> res = {};

    copy = Strip(str);
    int i = 0; int j = 0;

    while (j <= copy.length()) {
        if (j == 0) {
            if (copy[i] == ' ') {
                j = i;
            } else {
                i++;
            }
        } else {
            if ((copy[j] == ' ') || (copy[j] == copy.length())) {
                res.push_back(copy.substr(i, j - i));
                i = j + 1;
                j = 0;
            } else {
                j++;
            }
        }
    }

    return res;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    auto copy = str;

    for (size_t j = 0; j < vect.size(); j++) {
        for (size_t i = 0; j < vect.at(j).size(); i++) {
            copy.push_back(vect.at(j)[i]);
        }
        copy.push_back(' ');
    }

    return copy;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    auto copy = str;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\t') {
            for (size_t j = 0; j < tabsize; j++) {
                copy.push_back(' ');
            }
        } else {
            copy.push_back(str[i]);
        }
    }
    return copy;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};