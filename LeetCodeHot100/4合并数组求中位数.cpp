/*
* ��Ŀ���ϲ������������� �ҵ���λ��
*/

/*
* ����1��������
* ֱ������STL�����ϲ���sort
* �������鳤������������ż��������λ��
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