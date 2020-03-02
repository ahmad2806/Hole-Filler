//
// Created by ahmad on 4/20/19.
//

#include <iostream>
#include "ExceptionValidator.h"

// in c++11 could use stof instead of this function, but i have already build all the exc using c++98
// and that's why i wrote this function
float ExceptionValidator::HelperMethods::convertStringToFloat(const std::string &s, int dot_counter) {
    unsigned i;
    float answer = 0;
//    finding the ascii for 0
    int base = int('0');
//    for every char in the string we check ig its a number or dot
    for (i = 0; i < s.length(); ++i) {
        if (int(s[i]) >= int('0') && int(s[i]) <= int('9')) {
//            if its a number, " we shift our number to the left " and add the number in its digit
            answer *= 10;
            answer += int(s[i]) - base;

        } else if (s[i] == '.' && dot_counter++ == 0) {
//            if it is a dot we first increment the dot param, so we dont let strings with more than one dot pass
//            then we do the same algorithm, starting after the dot
            int start_from = s.find('.') + 1;
            float temp = convertStringToFloat(s.substr(start_from, s.length()), dot_counter);
//            we add the number we got from the recursion (the number after the dot) to the answer num
//            (and that's of course after putting it in its origin location)
            answer += temp / (std::pow(10, s.length() - start_from));
            break;
        } else {
            throw std::invalid_argument("invalid number");
        }

    }
    return answer;

}
