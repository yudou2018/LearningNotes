#include <iostream>

using namespace std;

typedef long long LL;

static constexpr int MOD=1e9+7; // 最终结果mod 1e9+7

LL quickPow(LL x, LL n){ // 求x的n次方
	LL ret = 1;
	while(n){
		if(n&1){
			ret *= x;
			ret %= MOD;
		}
		x *= x;
		x %= MOD;
		n>>=1;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	if(argc!=3){
		cout<<"usage: "<<argv[0]<<" x n"<<endl;
	}
	LL x=stoll(string(argv[1])), n=stoll(string(argv[2]));
	LL ret=quickPow(x,n);
	cout<<ret<<endl;
	return 0;
}


