/*
* 题目：红、白、蓝用0、1、2表示
* 实现数组的排序000...111...222...
*/

/*
* 方法1：两趟扫描计数排序
* 第一次遍历计数0、1、2
* 第二次遍历重写数组
*/
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = { 0 };
        for (const int& num : nums)
            ++cnt[num];
        nums.clear();
        for (int i = 0; i < 3; ++i) {
            while (cnt[i]-- > 0)
                nums.push_back(i);
        }
    }
};

/*
* 方法2：三指针一次遍历
* 以p遍历数组 p0记录当下应该放0的位置 p2记录当下应该放2的位置
* 碰到0则换至p0 p、p0递增1
* 碰到2则换至p2 p2递减 p不变 因为有可能p2本身指向的就是2 则要再进行一次
* 否则是碰到1 只需递增p即可
*/
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int p = 0, p0 = 0, p2 = nums.size() - 1;
        while (p <= p2)
            if (nums[p] == 0)
                swap(nums[p0++], nums[p++]);
            else if (nums[p] == 2)
                swap(nums[p2--], nums[p]);
            else
                ++p;
    }
};