void bubbleSort(vector<int>& nums) {
	// �Ľ���ð������ ÿ����С����������ð
	// ��������һ��ѭ��û�н�������ʱ ����
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
	// ѡ������ ÿ������ҵ�һ����Сֵ�±�
	// ��������Сֵ�±�ı� ����н���
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
	// λ��0���ڱ� ������������������
	// �������ǰ�� nums[0]��ֵΪ����Ǹ�
	// Ȼ����ǰ��ѰֻҪ����nums[0]�Ķ������ƶ�һλ
	// ѭ���ƶ�������nums[0]���뵽ֹͣ��λ�� 
	// ����һ��С�ڵ���nums[0]��λ��
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
	// ÿ����һ���������в�������
	// ��ÿ����һ�������ȡһ���ֽ��в�������
	// λ��0�Ǹ������� ����������������
	// ����ÿ��inc/=3 ����ѭ�����̳�ָ���ͼ�С
	// �÷������Ӷ�ΪO(n*logn)
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