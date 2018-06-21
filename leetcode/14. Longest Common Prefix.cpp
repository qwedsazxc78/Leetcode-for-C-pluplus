// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.


/*---- header ------------------------------------ */
#include <iostream>
#include <string.h>
#include <math.h>
#include <unordered_map>
#include <vector>

/*---- namespace --------------------------------- */
using namespace std;

#define logEnd(msg) cout <<  "Log: " << msg << endl;
#define log(msg) cout <<  "Log: " << msg << '\t';

/*---- class ------------------------------------ */
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];

		int strsLen = strs.size();
		int strsMinLen = strs[0].size();
		int strsMinIndex = 0;
		string strsMinStr = strs[0];
		string result;

		for (int i = 1; i < strsLen; ++i)
		{
			if (strsMinLen > strs[i].size())
			{
				strsMinLen = strs[i].size();
				strsMinStr = strs[i];
				strsMinIndex = i;
			}
		}

		string tmpSearch;
		int strFindCNT = 0;

		for (int i = 0; i < strsMinLen; ++i)
		{
			for (int j = strsMinLen; j >= 0; --j)
			{
				tmpSearch.assign(strsMinStr, i, j);

				for (int k = 0; k < strsLen; ++k)
				{
					if (strsMinIndex != k) {

						if (strs[k].find(tmpSearch) != -1) {
							strFindCNT ++;
						}
					}
				}
				if (strFindCNT >= strsLen - 1) {
					return tmpSearch;
				}
				strFindCNT = 0;
			}

		}
		return "";


	}
};

class SolutionGolden {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() < 1) return "";
		int tag = 0;
		for (int i = 0; i < strs.size(); ++i)
		{
			if (strs[i].size() < tag) {
				tag = i;
			}
		}
		string re;

		for (int i = 0; i < strs[tag].size(); ++i) {
			char c = strs[tag][i];
			for (int j = 0; j < strs.size(); ++j) {
				if (strs[j][i] == c) {
					continue;
				}
				else {
					return re;
				}
			}
			re.push_back(c);
		}
		return re;
	}
};

int main()
{


	vector<string> ex1;
	vector<string> ex2;
	ex1.push_back("flower");
	ex1.push_back("flow");
	ex1.push_back("flight");

	ex2.push_back("dog");
	ex2.push_back("racecar");
	ex2.push_back("car");

	// string ex3 = "IX";
	// string ex4 = "LVIII";
	// string ex5 = "MCMXCIV";
	Solution ans;


	string result1, result2, result3, result4, result5, result6;
	result1 = ans.longestCommonPrefix(ex1);
	result2 = ans.longestCommonPrefix(ex2);
	// // result3 = ans.romanToInt(ex3);
	// // result4 = ans.romanToInt(ex4);
	// // result5 = ans.romanToInt(ex5);

	cout <<  "Result1: " << result1 << endl;
	cout <<  "Result2: " << result2 << endl;
	// cout <<  "Result3: " << result3 << endl;
	// cout <<  "Result4: " << result4 << endl;
	// cout <<  "Result5: " << result5 << endl;

	return 0;
}
