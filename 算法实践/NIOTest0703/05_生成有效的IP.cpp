#include <iostream>
#include <vector>

using namespace std;

class Solution{
	// LeetCode 93
	vector<string> ans;
	vector<int> segs;
	string s;
	int n=0;
	void dfs(int begin){
		if(segs.size()==4){ // 如果已经有了4段
			if(begin==n){ // 并且已经遍历完了 说明找到了4段合法的
				string str;
				for(int& seg:segs){
					str += to_string(seg)+'.';
				}
				str.pop_back();
				ans.emplace_back(str);
			}
			return; // 只要有4段就要退出
		}
		
		if(begin==n){ // 或者遍历完了还没4段
			return;
		}

		if(s[begin]=='0'){ // 不能有前导0所以这一段只能是0
			segs.push_back(0);
			dfs(begin+1);
			segs.pop_back();
			return;
		}
		
		int seg=0;
		for(int i=begin;i<begin+3;++i){
			seg=seg*10+s[i]-'0';
			if(seg<=255){
				segs.push_back(seg);
				dfs(i+1);
				segs.pop_back();
			}
		}

	}
public:
	vector<string> restoreIpAddresses(string s){
		this->s = s;
		n = s.size();
		dfs(0);
		return ans;
	}
};

int main()
{
	Solution slt;
	vector<string> ret = slt.restoreIpAddresses("25525511135");
	for(string& str:ret){
		cout<<str<<endl;
	}

	return 0;
}
