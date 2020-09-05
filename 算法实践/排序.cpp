void bubbleSort(vector<int>& nums) {
	// 改进的冒泡排序 每次让小的数字往上冒
	// 当发现有一轮循环没有交换数字时 跳出
	int n = nums.size();
	bool flg = true;
	for (int i = 0; i < n - 1 && flg; ++i) {
		flg = false;
		for (int j = n - 1; j > i; --j) {
			if (nums[j - 1] > nums[j]) {
				swap(nums[j], nums[j - 1]);
				flg = true;
			}
		}
	}
}

void selectSort(vector<int>& nums) {
	// 选择排序 每次向后找到一个最小值下标
	// 若发现最小值下标改变 则进行交换
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (nums[j] < nums[min])
				min = j;
		}
		if (min != i)
			swap(nums[i], nums[min]);
	}
}

void insertSort(vector<int>& nums) {
	// 位置0是哨兵 不参与真正的排序中
	// 遇到后比前大 nums[0]赋值为大的那个
	// 然后往前搜寻只要大于nums[0]的都往后移动一位
	// 循环移动结束后将nums[0]插入到停止的位置 
	// 即第一个小于等于nums[0]的位置
	int n = nums.size();
	int i, j;
	for (i = 1; i < n; ++i) {
		if (nums[i] < nums[i - 1]) {
			nums[0] = nums[i];
			for (j = i - 1; nums[j] > nums[0]; --j)
				nums[j + 1] = nums[j];
			nums[j + 1] = nums[0];
		}
	}
}

void shellSort(vector<int>& nums) {
	// 每次以一定增量进行插入排序
	// 即每次以一定间隔抽取一部分进行插入排序
	// 位置0是辅助功能 不参与真正的排序
	// 由于每次inc/=3 所以循环缩短呈指数型减小
	// 该方法复杂度为O(n*logn)
	int i, j;
	int n = nums.size(), inc = n;
	do {
		inc = inc / 3 + 1;
		for (i = inc + 1; i < n; ++i) {
			if (nums[i] < nums[i - inc]) {
				nums[0] = nums[i];
				for (j = i - inc; j > 0 && nums[0] < nums[j]; j -= inc)
					nums[j + inc] = nums[j];
				nums[j + inc] = nums[0];
			}
		}
	} while (inc > 1);
}