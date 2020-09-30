#include "pch.h"
#include <iostream>

class Point {
public:
	void output() {}
	static void init() {
		std::cout << "I m static" << std::endl;
	} // 静态成员函数属于类本身
	// 可以通过 Point::init(); 调用
};

int main()
{
	Point pt;
	pt.init();
	pt.output();
	Point::init();
	return 0;
}