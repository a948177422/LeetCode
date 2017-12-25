#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec_ret;

		for (vector<int>::size_type i = 0; i < nums.size(); i++)
		{
			for (vector<int>::size_type j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					vec_ret.push_back(i);
					vec_ret.push_back(j);
					++m_counter;
					return vec_ret;
				}
				else
				{
					++m_counter;
					continue;
				}
			}
		}
	}

	vector<int> twoSum_1(vector<int>& nums, int target) {
		vector<int> group_1;
		vector<int> group_2;
		vector<int> vec_ret;
		typedef vector<int>::iterator vec_it;
		m_counter = 0;

		for (vec_it iter = nums.begin(); iter != nums.end(); iter++)
		{
			if ((*iter) < target / 2)
				group_1.push_back(*iter);
			else
				group_2.push_back(*iter);
			m_counter++;
		}
	
		//if (target%2 == 0)
		//{
			for (vec_it iter_1 = group_1.begin(); iter_1 != group_1.end(); iter_1++)
			{
				for (vec_it iter_2 = group_2.begin(); iter_2 != group_2.end(); iter_2++)
				{
					m_counter++;
					if ((*iter_1) + (*iter_2) == target)
					{
						vec_it iter_res_1 = find(nums.begin(), nums.end(), *iter_1);
						vec_it iter_res_2 = find(nums.begin(), nums.end(), *iter_2);
						vec_ret.push_back(distance(nums.begin(), iter_res_1));
						vec_ret.push_back(distance(nums.begin(), iter_res_2));
					}
					else
						continue;
				}
			}
		//}

		return vec_ret;
	}
	int m_counter = 0;
};

int main()
{
	Solution sum;
	vector<int> vec_myNumbers = {1, 2, 6, 8, 12, 19, 52, 5, 7, 123, 41, 34, 27, 44, 77};

	vector<int> vec_result_1 = sum.twoSum(vec_myNumbers, 71);
	vector<int> vec_result_2 = sum.twoSum_1(vec_myNumbers, 71);

	for (vector<int>::iterator iter = vec_result_1.begin(); iter != vec_result_1.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "steps: " << sum.m_counter << endl;

	for (vector<int>::iterator iter = vec_result_2.begin(); iter != vec_result_2.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "steps: " << sum.m_counter << endl;

	int x;
	cin >> x;

	return 0;
}