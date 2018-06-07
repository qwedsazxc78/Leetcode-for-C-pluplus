// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

/*---- header ------------------------------------ */
#include <iostream>
#include <vector>
#include <unordered_map>

/*---- namespace --------------------------------- */
using namespace std;

/*---- class ------------------------------------ */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

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
