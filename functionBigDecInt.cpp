//
// Created by Abdelrhman Sayed on 11/12/2022.
//
#include "classBigDecInt.h"

    string BigDecimalInt::case_1_decStr1PlusDecStr2(string decStr1, string decStr2)
    {
        string finalResult = "";
        decStr1 = deleteSign(decStr1);
        decStr2 = deleteSign(decStr2);
        if (size(decStr1) > size(decStr2))
        {
            decStr2 = equalitySize(decStr1, decStr2);
        }
        else if (size(decStr1) < size(decStr2))
        {
            decStr1 = equalitySize(decStr1, decStr2);
        }
        finalResult = functionSum(decStr1, decStr2);
        return finalResult;
    }
    string BigDecimalInt:: case_2_minusDecStr1MinusDecStr2(string decStr1, string decStr2)
    {
        string finalResult = "";
        decStr1 = deleteSign(decStr1);
        decStr2 = deleteSign(decStr2);

        if (size(decStr1) > size(decStr2))
        {
            decStr2 = equalitySize(decStr1, decStr2);
        }
        else if (size(decStr1) < size(decStr2))
        {
            decStr1 = equalitySize(decStr1, decStr2);
        }
        finalResult = "-" + functionSum(decStr1, decStr2);
        return finalResult;
    }
    string BigDecimalInt:: case_3_minusDecStrPlusDecStr2(string decStr1, string decStr2)
    {
        string finalResult = "";
        decStr1 = deleteSign(decStr1);
        decStr2 = deleteSign(decStr2);
        // cout << "decStr1 : " << decStr << ", decStr2 : " << anthorStr.decStr << endl;
        if (size(decStr1) > size(decStr2)) // in this case final res (negative)
        {
            decStr2 = equalitySize(decStr1, decStr2);
            finalResult = "-" + subFunction(decStr1, decStr2);
            return finalResult;
        }
        else if (size(decStr1) < size(decStr2)) // in this case final res (postive)
        {
            decStr1 = equalitySize(decStr1, decStr2);
            finalResult = subFunction(decStr2, decStr1);
            return finalResult;
        }
        else // this condation in case same size
        {

            if (checkBiggestDecStr(decStr1, decStr2) == decStr1)
            {
                finalResult = "-" + subFunction(decStr1, decStr2);
                return finalResult;
            }
            else if (checkBiggestDecStr(decStr1, decStr2) == decStr2)
            {
                finalResult = subFunction(decStr2, decStr1);
                return finalResult;
            }
            else
            {
                return "0";
            }
        }
    }
    string BigDecimalInt:: case_4_DecStrMinusDecStr2(string decStr1, string decStr2)
    {
        string finalResult = "";
        decStr1 = deleteSign(decStr1);
        decStr2 = deleteSign(decStr2);
        if (size(decStr1) > size(decStr2)) // in this case final res (negative)
        {
            decStr2 = equalitySize(decStr1, decStr2);
            finalResult = subFunction(decStr1, decStr2);
            return finalResult;
        }
        else if (size(decStr1) < size(decStr2)) // in this case final res (postive)
        {
            decStr1 = equalitySize(decStr1, decStr2);
            finalResult = "-" + subFunction(decStr2, decStr1);
            return finalResult;
        }
        else // this condation in case same size
        {
            if (checkBiggestDecStr(decStr1, decStr2) == decStr1)
            {
                finalResult = subFunction(decStr1, decStr2);
                return finalResult;
            }
            else if (checkBiggestDecStr(decStr1, decStr2) == decStr2)
            {
                finalResult = "-" + subFunction(decStr2, decStr1);
                return finalResult;
            }
            else
            {
                return "0";
            }
        }
    }
    // this function to delete sign
    string BigDecimalInt:: deleteSign(string decStr)
    {
        if ((decStr[0] == '+') || ((decStr[0] == '-')))
        {
            decStr.erase(0, 1);
        }
        return decStr;
    }
    // this function to equality the size of numbers
    string BigDecimalInt:: equalitySize(string decStr1, string decStr2)
    {
        string strZeros = "";
        int diff = 0;
        // to check that same size  or no --- > to became them same in size with increment with zeros
        if (decStr1.size() > decStr2.size())
        {
            strZeros = "";
            diff = decStr1.size() - decStr2.size();
            for (size_t i = 0; i < diff; i++)
            {
                strZeros += '0';
            }
            decStr2 = strZeros + decStr2;
            return decStr2;
        }
        else if (decStr1.size() < decStr2.size())
        {
            strZeros = "";
            diff = decStr2.size() - decStr1.size();
            for (size_t i = 0; i < diff; i++)
            {
                strZeros += '0';
            }
            decStr1 = strZeros + decStr1;
            return decStr1;
        }
    }
    // this function to sum decStr1 and decStr2
    string BigDecimalInt:: functionSum(string decStr1, string decStr2)
    {
        string res = "", finalRes = "", sum = "";
        int reminder = 0;
        for (int i = decStr1.size() - 1; i >= 0; i--)
        {

            string strOfI_1 = "", strOfI_2 = "", sum = "";
            strOfI_1 = decStr1[i];
            strOfI_2 = decStr2[i];

            if (i == 0)
            {
                if ((stoi(strOfI_1) + stoi(strOfI_2)) >= 10)
                {
                    sum = to_string((stoi(strOfI_1) + stoi(strOfI_2)) + reminder);
                    reverse(res.begin(), res.end());
                    finalRes = sum + res;
                    return finalRes;
                }
                else
                {
                    sum = to_string((stoi(strOfI_1) + stoi(strOfI_2)) + reminder);
                    res += sum;
                    reverse(res.begin(), res.end());
                    finalRes = res;
                    return finalRes;
                }
            }
            else
            {
                if ((stoi(strOfI_1) + stoi(strOfI_2) + reminder) >= 10)
                {
                    sum = to_string(((stoi(strOfI_1) + stoi(strOfI_2) + reminder) - 10));
                    res += sum;
                    reminder = 1;
                }
                else
                {
                    sum = to_string((stoi(strOfI_1) + stoi(strOfI_2) + reminder));
                    res += sum;
                    reminder = 0;
                }
            }
        }
    }
    // this function check whose the bigest in case size is equal for two numbers
    string BigDecimalInt:: checkBiggestDecStr(string decStr1, string decStr2)
    {
        for (size_t i = 0; i < decStr1.size(); i++)
        {
            if ((decStr1[i] - '0') > (decStr2[i] - '0'))
            {
                return decStr1;
            }
            else if ((decStr1[i] - '0') < (decStr2[i] - '0'))
            {
                return decStr2;
            }
            else if ((i == decStr1.size() - 1))
            {
                return "equal";
            }
        }
    }
    // this function check whose the smallest in case size is equal for two numbers
    string BigDecimalInt:: checkSmallestDecStr(string decStr1, string decStr2)
    {
        for (size_t i = 0; i < decStr1.size(); i++)
        {

            if ((decStr1[i] - '0') > (decStr2[i] - '0'))
            {
                return decStr2;
            }
            else if ((decStr1[i] - '0') < (decStr2[i] - '0'))
            {
                return decStr1;
            }
            else if ((i == decStr1.size() - 1))
            {
                return "equal";
            }
        }
    }
    // this function to substruct decStr1, decStr2
    string BigDecimalInt:: subFunction(string decStr1, string decStr2)
    {
        string res = "";
        int carry = 0;
        for (int i = decStr1.size() - 1; i >= 0; i--)
        {
            int sub = ((decStr1[i] - '0') - (decStr2[i] - '0') - carry);
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(sub + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int BigDecimalInt::size(string decStr)
    {
        int sizeDecStr = decStr.size();
        return sizeDecStr;
    }
    bool BigDecimalInt::sign(string decStr)
    {
        if ((decStr[0] == '+') || ((decStr[0] != '-') && (decStr[0] != '+')))
        {
            return true; // this return to prove this string positive
        }
        else if (decStr[0] == '-')
        {
            return false; // this return to prove this string negative
        }
    }


    BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anthorStr)
    {
        string signStr = "";
        BigDecimalInt finalRes;
        if ((sign(decStr)) && (sign(anthorStr.decStr))) // num1 -> (56565) | num2 -> (565656565)
        {
            finalRes.decStr = case_1_decStr1PlusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((!sign(decStr)) && (!sign(anthorStr.decStr)))
        {
            finalRes.decStr = case_2_minusDecStr1MinusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((!sign(decStr)) && (sign(anthorStr.decStr))) // num1 -> -56565 | num2 -> 565656565
        {
            finalRes.decStr = case_3_minusDecStrPlusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((sign(decStr)) && (!sign(anthorStr.decStr)))
        {
            finalRes.decStr = case_4_DecStrMinusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        return finalRes;
    }
    BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anthorStr)
    {
        string signStr = "";
        BigDecimalInt finalRes;
        if ((sign(decStr)) && (!sign(anthorStr.decStr))) // num1 - (-num2) --> num1 + num2
        {
            finalRes.decStr = case_1_decStr1PlusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((!sign(decStr)) && (sign(anthorStr.decStr))) //(-num1) - (num2) --> -(num1 + num2)
        {
            finalRes.decStr = case_2_minusDecStr1MinusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((!sign(decStr)) && (!sign(anthorStr.decStr))) //(-num1) - (-num2) --> (-num1 + num2)
        {
            finalRes.decStr = case_3_minusDecStrPlusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        else if ((sign(decStr)) && (sign(anthorStr.decStr))) //(num1) - (num2) --> (num1 - num2)
        {
            finalRes.decStr = case_4_DecStrMinusDecStr2(decStr, anthorStr.decStr);
            // cout << "finalRes.decStr : " << finalRes.decStr << endl;
        }
        return finalRes;
    }
    bool BigDecimalInt::operator>(BigDecimalInt anthorStr)
    {
        if (sign(decStr) && !sign(anthorStr.decStr))
            return true;
        else if (!sign(decStr) && sign(anthorStr.decStr))
            return false;
        else if (sign(decStr) && sign(anthorStr.decStr))
        {
            decStr = deleteSign(decStr);
            anthorStr.decStr = deleteSign(anthorStr.decStr);
            if (size(decStr) > size(anthorStr.decStr))
                return true;
            else if (size(decStr) == size(anthorStr.decStr))
                return (checkBiggestDecStr(decStr, anthorStr.decStr) == decStr);
            else
                return false;
        }
        else if (!sign(decStr) && !sign(anthorStr.decStr))
        {
            if (size(decStr) < size(anthorStr.decStr))
                return true;
            else if (size(decStr) == size(anthorStr.decStr))
                return (checkSmallestDecStr(decStr, anthorStr.decStr) == decStr);
            else
                return false;
        }
    }
    bool BigDecimalInt::operator<(BigDecimalInt anthorStr)
    {
        if (!sign(decStr) && sign(anthorStr.decStr))
            return true;
        else if (sign(decStr) && !sign(anthorStr.decStr))
            return false;
        else if (sign(decStr) && sign(anthorStr.decStr))
        {
            decStr = deleteSign(decStr);
            anthorStr.decStr = deleteSign(anthorStr.decStr);
            if (size(decStr) < size(anthorStr.decStr))
                return true;
            else if (size(decStr) == size(anthorStr.decStr))
                return (checkBiggestDecStr(decStr, anthorStr.decStr) == anthorStr.decStr);
            else
                return false;
        }
        else if (!sign(decStr) && !sign(anthorStr.decStr))
        {
            if (size(decStr) > size(anthorStr.decStr))
                return true;
            else if (size(decStr) == size(anthorStr.decStr))
                return (checkSmallestDecStr(decStr, anthorStr.decStr) == anthorStr.decStr);
            else
                return false;
        }
    }
    bool BigDecimalInt::operator==(BigDecimalInt anthorStr)
    {
        if (decStr[0] == '+')
        {
            decStr = deleteSign(decStr);
        }
        if (anthorStr.decStr[0] == '+')
        {
            anthorStr.decStr = deleteSign(anthorStr.decStr);
        }
        return (decStr == anthorStr.decStr);
    }
    BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anthorStr)
    {
        decStr = anthorStr.decStr;
    }
ostream &operator<<(ostream &out, BigDecimalInt &decString)
{
    out << decString.decStr;
}
// in this cases on this functions we use it in add and subtruct
//   case one   ---> (((num1) + (num2)) in operator+)   ==  (((num1) - (-num2)) in operator-)
//   case two   ---> (((-num1) + (-num2)) in operator+) ==  (((-num1) - (num2)) in operator-)
//   case three ---> (((-num1) + (num2)) in operator+)  ==  (((-num1) - (-num2)) in operator-)
//   case four  ---> (((-num1) + (num2)) in operator+)  ==  (((-num1) - (-num2)) in operator-)


