// Determine whether an integer is a palindrome.
// An integer is a palindrome when it reads the same backward as forward.

// Example 1:
// Input: 121
// Output: true

// Example 2:
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

/*---- header ------------------------------------ */
#include <iostream>
#include <string.h>
#include <math.h>

/*---- namespace --------------------------------- */
using namespace std;

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

/*---- class ------------------------------------ */
class Solution {
public:
	bool isPalindrome(int x) {
		int counter = 0, upNum, lowNum;
		int tmp = x;

		// handle <0 and 0~9 condition
		if (x < 0) return false;
		if (x < 10) return true;

		while (tmp != 0) {
			counter ++;
			tmp = tmp / 10;
		}

		if (counter % 2 != 0 ) {
			counter = counter / 2 + 1;
			lowNum = pow(10 , (double)counter);
			upNum = lowNum / 10;
		}
		else {
			counter = counter / 2;
			lowNum = pow(10 , (double)(counter));
			upNum = lowNum;
		}

		upNum = x / upNum;
		lowNum = x % lowNum;

		upNum = reverse(upNum);

		if (upNum != lowNum) return false;
		else return true;
	}


private:
	int reverse(int x) {
		int tmp = x, reverse_tmp = 0;

		while (tmp != 0) {
			// check overflow
			if ((reverse_tmp > (INT_MAX / 10)) || (reverse_tmp < (INT_MIN / 10)) )
			{
				return 0;
			}
			reverse_tmp = 10 * reverse_tmp + tmp % 10;
			tmp = tmp / 10;
		};

		return reverse_tmp;

	}
};

class Solution2 {
public:
	bool isPalindrome(int x) {
		string tmp, str1, str2;
		int start_pos;
		// handle <0 and 0~9 condition
		if (x < 0) return false;
		if (x < 10) return true;

		tmp = to_string(x);

		if ((tmp.length() % 2) != 0) {
			// odd length
			start_pos = tmp.length() / 2 + 1;
			str1 = str1.assign(tmp, 0, start_pos);
			str2 = str2.assign(tmp, start_pos - 1, tmp.length() + 1 );
		} else {
			start_pos = tmp.length() / 2 ;
			str1 = str1.assign(tmp, 0, start_pos);
			str2 = str2.assign(tmp, start_pos , tmp.length() + 1 );
		}

		str2 = str2.assign(str2.rbegin(), str2.rend());

		if (str1.compare(str2) != 0) return false;
		else return true;

	}
};

class Solution3 {
public:
	bool isPalindrome(int x) {
		int reversedNum = 0;
		// handle <0 and 0~9 condition
		if (x < 0) return false;
		if (x < 10) return true;
		if (x % 10 == 0 && x != 0) return false;

		while ( x > reversedNum) {
			reversedNum = reversedNum * 10 + x % 10;
			x = x / 10;
		}

		return ((x == reversedNum) || (x == (reversedNum / 10)));

	}
};

int main()
{
	int ex1 = 121;
	int ex2 = -121;
	int ex3 = 10;
	int ex4 = 0;
	int ex5 = 11;
	int ex6 = 1001;
	Solution3 ans;

	bool result1, result2, result3, result4, result5, result6;
	result1 = ans.isPalindrome(ex1);
	result2 = ans.isPalindrome(ex2);
	result3 = ans.isPalindrome(ex3);
	result4 = ans.isPalindrome(ex4);
	result5 = ans.isPalindrome(ex5);
	result6 = ans.isPalindrome(ex6);

	cout <<  "Result1: " << result1 << endl;
	cout <<  "Result2: " << result2 << endl;
	cout <<  "Result3: " << result3 << endl;
	cout <<  "Result4: " << result4 << endl;
	cout <<  "Result5: " << result5 << endl;
	cout <<  "Result6: " << result6 << endl;

	return 0;
}
