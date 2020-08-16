/*
* 题目：合并两个有序数组 找到中位数
*/

/*
* 方法1：暴力法
* 直接利用STL方法合并后sort
* 根据数组长度是奇数还是偶数计算中位数
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); ++i)
            nums1.push_back(nums2[i]);
        sort(nums1.begin(), nums1.end());
        int length = nums1.size();
        if (length & 1) return nums1[length / 2];
        return double(nums1[length / 2 - 1] + nums1[length / 2]) / 2;
    }
};