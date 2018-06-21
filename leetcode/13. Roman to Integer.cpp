// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together.
// Twelve is written as, XII, which is simply X + II.
// The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII. Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: "III"
// Output: 3
// Example 2:

// Input: "IV"
// Output: 4
// Example 3:

// Input: "IX"
// Output: 9
// Example 4:

// Input: "LVIII"
// Output: 58
// Explanation: C = 100, L = 50, XXX = 30 and III = 3.
// Example 5:

// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

/*---- header ------------------------------------ */
#include <iostream>
#include <string.h>
#include <math.h>
#include <unordered_map>

/*---- namespace --------------------------------- */
using namespace std;

#define logEnd(msg) cout <<  "Log: " << msg << endl;
#define log(msg) cout <<  "Log: " << msg << '\t';

/*---- class ------------------------------------ */
class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		bool oddFlag = false;

		char *cstr = new char[s.length() + 1];
		strcpy(cstr, s.c_str());


		if (s.length() % 2 != 0) {
			oddFlag = true;
		} else {
			oddFlag = false;
		}

		for (int i = 0 ; i < s.length() ; i = i + 2)
		{

			if (oddFlag == true) {
				if (i == 0) {
					result += RomanCharToInt('0', cstr[i]);
				} else {
					result += RomanCharToInt(cstr[i - 1], cstr[i]);
				}
			}
			else {
				result += RomanCharToInt(cstr[i], cstr[i + 1]);
			}

		}

		// logEnd(result);

		delete [] cstr;

		return result;
	}


private:
	int RomanCharToInt(char firstChr, char secondChr) {
		int firstInt = 0 , secondInt = 0, result = 0;

		if (firstChr != '0') {
			firstInt = RomanTable(firstChr);
			secondInt = RomanTable(secondChr);
		} else {
			result = RomanTable(secondChr);
			return result;
		}

		if (firstInt >= secondInt) {
			result = firstInt + secondInt;
		} else {
			result = secondInt - firstInt;
		}
		return result;
	}

	int RomanTable(char &chr) {
		switch (chr) {
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return -1;
		}
		return 0;
	}

};

class Solution2
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> T = {
			{ 'I' , 1 },
			{ 'V' , 5 },
			{ 'X' , 10 },
			{ 'L' , 50 },
			{ 'C' , 100 },
			{ 'D' , 500 },
			{ 'M' , 1000 }
		};
		logEnd(s.back())
		int sum = T[s.back()];
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (T[s[i]] < T[s[i + 1]])
			{
				sum -= T[s[i]];
			}
			else
			{
				sum += T[s[i]];
			}
		}

		return sum;
	}
};

class SolutionGolden {
public:
	int romanCharToInt(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
		return 0;
	}
	int romanToInt(string s) {
		int result = 0;
		if (s.empty()) return 0;
		if (s.size() == 1) {
			return romanCharToInt(s[0]);
		}
		int temp = romanCharToInt(s[0]);
		for (size_t i = 1; i < s.size(); ++i) {
			int v = romanCharToInt(s[i]);
			if (v > temp) {
				result -= temp;
				temp = v;
			}
			else {
				result += temp;
				temp = v;
			}
		}
		result += temp;
		return result;
	}
};

int main()
{
	string ex1 = "MCDLXXVI"; // 1676
	string ex2 = "IV";
	string ex3 = "IX";
	string ex4 = "LVIII";
	string ex5 = "MCMXCIV";
	Solution2 ans;


	int result1, result2, result3, result4, result5, result6;
	result1 = ans.romanToInt(ex1);
	result2 = ans.romanToInt(ex2);
	result3 = ans.romanToInt(ex3);
	result4 = ans.romanToInt(ex4);
	result5 = ans.romanToInt(ex5);

	cout <<  "Result1: " << result1 << endl;
	cout <<  "Result2: " << result2 << endl;
	cout <<  "Result3: " << result3 << endl;
	cout <<  "Result4: " << result4 << endl;
	cout <<  "Result5: " << result5 << endl;

	return 0;
}
