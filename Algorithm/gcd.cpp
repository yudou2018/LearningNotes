#include <iostream>

using namespace std;

// 最大公约数 递归写法
int gcd_r(int a, int b){
	return a%b==0? b : gcd_r(b, a%b);
}

// 参考递归可写出迭代法
int gcd_i(int a, int b){
	while(a%b){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return b;
}

int main()
{
	cout<<"48, 40的最大公因子："<<endl;
	cout<<gcd_r(48,40)<<endl;
	cout<<gcd_i(40,48)<<endl;
	return 0;
}
