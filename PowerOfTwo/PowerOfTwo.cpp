/*
 *  Given an integer, write a function to determine if it is a power of two.
 */


#include <iostream>

using namespace std;

/*
 *  2 的幂数从二进制的角度来看一定是最高位为1， 其余位数为0， 例如：
 *    2 的 1 次方为 2 ： 10
 *    2 的 2 次方为 4 ： 100
 *    2 的 3 次方为 8 ： 1000
 *  因此问题的解变为判断是否最高位为1 ，其余位位 0. 对于这种数据的特点，如果N＝＝ 100
 *  那么 N － 1 ＝＝ 011，因此  N & （N － 1） 如果位 0 则表示是 2 的幂数
 *
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
		return n > 0 && !(n & (n - 1));
    }
};

int main(void) {
	Solution s;
	cout << "0 is power of 2  : " << boolalpha << s.isPowerOfTwo(0)  << endl;
	cout << "1 is power of 2  : " << boolalpha << s.isPowerOfTwo(1)  << endl;
	cout << "-2 is power of 2  : " << boolalpha << s.isPowerOfTwo(-2)  << endl;
	cout << "16 is power of 2 : " << boolalpha << s.isPowerOfTwo(16) << endl;
	cout << "15 is power of 2 : " << boolalpha << s.isPowerOfTwo(15) << endl;
	return 0;
}
