// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

/*---- header ------------------------------------ */
#include <iostream>
#include <vector>
#include <unordered_map>

/*---- namespace --------------------------------- */
using namespace std;

/*---- class ------------------------------------ */
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			// not found the second one
			if (m.find(numbers[i]) == m.end() ) {
				// store the first one poisition into the second one's key
				m[target - numbers[i]] = i;
				cout << "1: " << numbers[i] << ", " << target - numbers[i] << ", " << m[target - numbers[i]] << ", " << i << endl;

			} else {
				// found the second one
				result.push_back(m[numbers[i]] + 1);
				result.push_back(i + 1);
				cout << "2: " << m[numbers[i]] + 1 << ", " << i + 1 << endl;
				cout << "2 result: " << result[0] << ", " << result[1] << endl;

				break;
			}
		}
		return result;
	}
};



int main()
{
	vector<int> v, result;
	int target = 9;
	Solution answer;

	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);

	cout << "Number: ";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
	cout << "Target: " << target << endl;

	result = answer.twoSum(v, target);

	cout <<  "Result: " << result[0] << ", " << result[1] << endl;



	return 0;
}
