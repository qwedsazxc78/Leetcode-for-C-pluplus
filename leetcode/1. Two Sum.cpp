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
		unordered_map<int, int> pairMap;
		vector<int> result;

		for (int i = 0; i < numbers.size(); ++i)
		{
			if (pairMap.find(numbers[i]) == pairMap.end() )
			{
				// save the first one value
				pairMap[ target - numbers[i]] = i;

			} else {
				// from the array map to key, then get the position from value
				result.push_back(pairMap[numbers[i]] );
				result.push_back(i);
				break;
			}
		}

		return result;
	}
};


class SolutionGolden {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		for (int i = 0; i < nums.size(); ++i) {
			auto it = m.find(target - nums[i]);
			if (it != m.end()) {
				return {it->second, i};
			}
			m[nums[i]] = i;
		}
	}
private:
	std::unordered_map<int, int> m;
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
