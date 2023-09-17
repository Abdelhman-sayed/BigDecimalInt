// Author 1 : Abdelrhman Sayed Ali 20210205
// Author 2 : Ziad Emad Elsayed    20210151
// Created by Abdelrhman Sayed on 11/12/2022.
//
#ifndef BIGDECIMALINT_CLASSBIGDECINT_H
#define BIGDECIMALINT_CLASSBIGDECINT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
class BigDecimalInt
{
private:
    string decStr;
    int num = 0;
    string case_1_decStr1PlusDecStr2(string decStr1, string decStr2);
    string case_2_minusDecStr1MinusDecStr2(string decStr1, string decStr2);
    string case_3_minusDecStrPlusDecStr2(string decStr1, string decStr2);
    string case_4_DecStrMinusDecStr2(string decStr1, string decStr2);
    // this function to delete sign
    string deleteSign(string decStr);
    // this function to equality the size of numbers
    string equalitySize(string decStr1, string decStr2);
    // this function to sum decStr1 and decStr2
    string functionSum(string decStr1, string decStr2);
    // this function check whose the bigest in case size is equal for two numbers
    string checkBiggestDecStr(string decStr1, string decStr2);
    // this function check whose the smallest in case size is equal for two numbers
    string checkSmallestDecStr(string decStr1, string decStr2);
    // this function to substruct decStr1, decStr2
    string subFunction(string decStr1, string decStr2);
    int size(string decStr);
    bool sign(string decStr);

public:
    BigDecimalInt(){};
    BigDecimalInt(string decString)
    {
        decStr = decString;
        regex filter("[+-]?[1-9]+[0-9]*");
        if (!regex_match(decStr, filter))
        {
            cout << "\n\t\t\tInvalid Input, Please try again." << endl;
            exit(0);
        }
    }
    BigDecimalInt operator+(BigDecimalInt anthorStr);
    BigDecimalInt operator-(BigDecimalInt anthorStr);
    bool operator>(BigDecimalInt anthorStr);
    bool operator<(BigDecimalInt anthorStr);
    bool operator==(BigDecimalInt anthorStr);
    BigDecimalInt operator=(BigDecimalInt anthorStr);
    friend ostream &operator<<(ostream &out, BigDecimalInt &decString);
};
#endif //BIGDECIMALINT_CLASSBIGDECINT_H
