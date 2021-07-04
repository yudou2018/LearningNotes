#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	// LeetCode 165
    // 使用stringstream和getline函数实现以'.'分割
    int compareVersion(string version1, string version2) { 
        vector<int> v1, v2;
        stringstream ss1(version1), ss2(version2);
        string str;
        while (getline(ss1, str, '.')) {
            v1.emplace_back(stoi(str));
        }
        while (getline(ss2, str, '.')) {
            v2.emplace_back(stoi(str));
        }
        int n1 = v1.size(), n2 = v2.size();
        int i = 0;
        for (; i < min(n1, n2); ++i) {
            if (v1[i] > v2[i]) {
                return 1;
            }
            else if (v1[i] < v2[i]) {
                return -1;
            }
        }
        for (; i < n1; ++i) {
            if (v1[i] > 0) {
                return 1;
            }
        }
        for (; i < n2; ++i) {
            if (v2[i] > 0) {
                return -1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution slt;
    string version1 = "1.01", version2 = "1.001";
    cout << slt.compareVersion(version1, version2) << endl;

    return 0;
}
