#include "pch.h"
#include <iostream>

class Point {
public:
	void output() {}
	static void init() {
		std::cout << "I m static" << std::endl;
	} // ��̬��Ա���������౾��
	// ����ͨ�� Point::init(); ����
};

int main()
{
	Point pt;
	pt.init();
	pt.output();
	Point::init();
	return 0;
}