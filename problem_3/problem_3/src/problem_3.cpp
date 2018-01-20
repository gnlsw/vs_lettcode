#include <iostream>
#include <string>
#include <set>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;

class SolutionA {
public:
	int lengthOfLongestSubstring(string s)
	{
		if(s.size() <= 1)
		{
			return s.size();
		}

		int max_length = 0;
		for(string::size_type start_index = 0; start_index < s.size(); start_index++)
		{
			int length = 1;
			for(string::size_type curr_index = start_index + 1; curr_index < s.size(); curr_index++)
			{
				// 逐个比较，查看从start_index到之前的字符，是否存在相同的，如果相同，则start_index加1
				int flag_dup = 0;
				for(string::size_type index = start_index; index < curr_index; index++)
				{
					if(s[curr_index] == s[index])
					{
						flag_dup = 1;
						break;
					}
				}
				if(0 == flag_dup)
				{
					length++;
				}
				else
				{
					break;
				}
			}
			max_length = (length > max_length) ? length : max_length;
		}

		return max_length;
	}
};

class SolutionB {
public:
	int lengthOfLongestSubstring(string s)
	{
		if(s.size() <= 1)
		{
			return s.size();
		}

		int max_length = 0;
		for(string::size_type start_index = 0; start_index < s.size(); start_index++)
		{
			int length = 1;
			for(string::size_type curr_index = start_index + 1; curr_index < s.size(); curr_index++)
			{
				/* 查看从start_index到当前的字符，是否存在相同的，
				 * 如果无，长度加1，计算下一个字符
				 * 如果有，start_index变化
				 */
				int pos = s.find(s[curr_index], start_index);
				if(pos >= curr_index)
				{
					length++;
				}
				else
				{
					break;
				}
			}
			max_length = (length > max_length) ? length : max_length;
		}

		return max_length;
	}
};

class SolutionC {
public:
	int lengthOfLongestSubstring(string s)
	{
		int max = 0;
		int i = 0;
		int j = 0;
		int len = 0;
		int n = s.size();
		set<char> str_set;

		while((i < n) && (j < n))
		{
			if(str_set.count(s[j]))
			{
				str_set.erase(s[i]);
				len = j - i;
				max = max > len ? max : len;
				i++;
			}
			else
			{
				str_set.insert(s[j]);
				j++;
			}
		}
		len = j - i;
		max = max > len ? max : len;

		return max;
	}
};

class SolutionD 
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max = 0;
		int i = 0;
		int j = 0;
		int len = 0;
		int n = s.size();
		map<char, int> s_map;

		while((i < n) && (j < n))
		{
			if(s_map.find(s[j]) == s_map.end())
			{
				s_map[s[j]] = j;
				j++;
			}
			else
			{
				if(s_map.find(s[j])->second >= i)
				{
					len = j - i;
					max = max > len ? max : len;
					i = s_map.find(s[j])->second + 1;
				}
				s_map.find(s[j])->second = j;
				j++;
			}
		}
		len = j - i;
		max = max > len ? max : len;

		return max;
	}
};

int main()
{
	string s = "au";
	int max_length = 0;
	SolutionA sa;
	max_length = sa.lengthOfLongestSubstring(s);

	SolutionB sb;
	max_length = sb.lengthOfLongestSubstring(s);

	SolutionC sc;
	max_length = sc.lengthOfLongestSubstring("abcabc");

	SolutionD sd;
	max_length = sd.lengthOfLongestSubstring("abcabcbb");
	return 0;
}