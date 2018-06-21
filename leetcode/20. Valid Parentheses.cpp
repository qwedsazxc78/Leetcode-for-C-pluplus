// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true


/*---- header ------------------------------------ */
#include <iostream>
#include <string.h>
#include <math.h>
#include <unordered_map>
#include <vector>
#include <stack>


/*---- namespace --------------------------------- */
using namespace std;

#define logEnd(msg) cout <<  "Log: " << msg << endl;
#define log(msg) cout <<  "Log: " << msg << '\t';

/*---- class ------------------------------------ */
class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0) return true;
		if (s.size() % 2 != 0) return false;

		vector<char> mapArray;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				mapArray.push_back(s[i]);
			} else {
				if (mapArray.size() == 0) {
					return false;
				} else {
					char check = mapArray.back();
					if (check == '{' && s[i] == reverseChar(check)) {
						mapArray.pop_back();
					}
					else if (check == '[' && s[i] == reverseChar(check))
					{
						mapArray.pop_back();
					}
					else if (check == '(' && s[i] == reverseChar(check)) {
						mapArray.pop_back();
					}
					else
					{ return false;}

				}
			}
		}
		return mapArray.size() == 0;

	}

private:
	char reverseChar(char chr) {
		switch (chr) {
		case '{':
			return '}';
		case '}':
			return '{';
		case '[':
			return ']';
		case ']':
			return '[';
		case '(':
			return ')';
		case ')':
			return '(';
		default:
			return 0;
		}
		return 0;
	}
};

class Solution2 {
public:
	bool isValid(string s) {
		const  unordered_map<char, char> symbol_pair =
		{	{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> parentheses;
		for (const auto& c : s) {
			const auto& it = symbol_pair.find(c);
			if (it != symbol_pair.cend()) {
				if (parentheses.empty() || parentheses.top() != it->second) {
					return false;
				}
				parentheses.pop();
			} else {
				parentheses.emplace(c);
			}
		}
		return parentheses.empty();
	}
};

class GoldenSolution {
public:
	bool isValid(string s) {
		vector<char> v;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
				v.push_back(s[i]);
			} else {
				if (v.size() == 0) {
					return false;
				}
				char c = v.back();
				if (s[i] == '}' && c == '{') {
					v.pop_back();
				} else if (s[i] == ']' && c == '[') {
					v.pop_back();
				} else if (s[i] == ')' && c == '(') {
					v.pop_back();
				} else {
					return false;
				}
			}
			for (auto i = v.begin(); i != v.end(); ++i)
				std::cout << *i << ' ';
			std::cout << endl;
		}


		return v.size() == 0;
	}
};

int main()
{

	string ex1 = "[({(())}[()])]";
	string ex2 = "()[]{}";
	string ex3 = "(]";
	string ex4 = "([)]";
	string ex5 = "{[]}";
	Solution ans;


	string result1, result2, result3, result4, result5, result6;
	result1 = ans.isValid(ex1);
	result2 = ans.isValid(ex2);
	result3 = ans.isValid(ex3);
	result4 = ans.isValid(ex4);
	result5 = ans.isValid(ex5);

	cout <<  "Result1: " << result1 << endl;
	cout <<  "Result2: " << result2 << endl;
	cout <<  "Result3: " << result3 << endl;
	cout <<  "Result4: " << result4 << endl;
	cout <<  "Result5: " << result5 << endl;

	return 0;
}
