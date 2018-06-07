// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:
// Input: 123
// Output: 321

// Example 2:
// Input: -123
// Output: -321

// Example 3:
// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment
// which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


/*---- header ------------------------------------ */
#include <iostream>
#include <vector>
#include <unordered_map>

/*---- namespace --------------------------------- */
using namespace std;

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

/*---- class ------------------------------------ */
class Solution {
public:
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
	int reverse(int x) {
		long long reverse_tmp = 0;

		while (x != 0) {
			reverse_tmp = 10 * reverse_tmp + x % 10;
			x = x / 10;
		};

		if (reverse_tmp > INT_MAX || reverse_tmp < INT_MIN)
			return 0;

		return (int)reverse_tmp;

	}
};

int main()
{
	int ex1 = 123;
	int ex2 = -123;
	int ex3 = 1534236469;
	Solution2 ans;

	int result1, result2, result3;
	result1 = ans.reverse(ex1);
	result2 = ans.reverse(ex2);
	result3 = ans.reverse(ex3);

	cout <<  "Result1: " << result1 << endl;
	cout <<  "Result2: " << result2 << endl;
	cout <<  "Result3: " << result3 << endl;


	return 0;
}
