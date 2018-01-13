#include <iostream>
#include <vector>
#include <map>


using std::cout;
using std::endl;
using std::vector;
using std::map;

class SolutionA {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				if(nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}

		return result;
	}
};

class SolutionB {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		map<int, int> nums_map;
		for(int i = 0; i < nums.size(); i++)
		{
			nums_map[nums[i]] = i;
		}
		for(int i = 0; i < nums.size(); i++)
		{
			int component = target - nums[i];
			if(0 == nums_map.count(component))
			{
				continue;
			}
			if(i == nums_map[component])
			{
				continue;
			}

			result.push_back(i);
			result.push_back(nums_map[component]);
			break;
		}
		return result;
	}
};

class SolutionC{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		map<int, int> nums_map;
		for(int i = 0; i < nums.size(); i++)
		{
			int component = target - nums[i];
			if(0 == nums_map.count(component))
			{
				nums_map[nums[i]] = i;
				continue;
			}

			if(nums_map[component] != i)
			{
				result.push_back(nums_map[component]);
				result.push_back(i);
				return result;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	SolutionA s;
	vector<int> result = s.twoSum(nums, 13);

	SolutionB sb;
	vector<int> result_b = sb.twoSum(nums, 13);

	SolutionC sc;
	vector<int> result_c = sc.twoSum(nums, 13);
}