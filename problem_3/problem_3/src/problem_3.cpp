#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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
				// ����Ƚϣ��鿴��start_index��֮ǰ���ַ����Ƿ������ͬ�ģ������ͬ����start_index��1
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

int main()
{
	string s = "au";
	int max_length = 0;
	SolutionA sa;
	max_length = sa.lengthOfLongestSubstring(s);
	return 0;
}