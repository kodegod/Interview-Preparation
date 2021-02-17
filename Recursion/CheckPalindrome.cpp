#include<string>
using namespace std;
class CheckPalindrome {
public:
	bool helper(string s)
	{
		if(s.size()==1||s.size()==0)
			return true;
		else
		{
			if(s[0]==s[s.size()-1])
			{
				s.erase(s.end()-1);
				s.erase(s.begin());
				return helper(s);
			}
			else
				return false;
		}
	}
	bool isPalindrome(std::string s) {
		// Code here
		return helper(s);
	}
};
