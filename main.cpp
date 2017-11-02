//���ڲ��Կռ�������
#include <time.h>
#include "vector.h"
#include <vector>
#include <thread>

#define print(x) std::cout << #x << "=" << x << std::endl;

int main()
{
	clock_t start, finish;
	start = clock();
	mystl::vector<int> v(1);
	v.push_back(2);
	v.erase(v.begin());
	print(*v.begin());
	print(*(v.end() - 1));
	print(v.size());
	print(v.capacity());
	for (mystl::vector<int>::iterator it = v.begin(); it != v.end(); it++) print(*it);
	finish = clock();
	std::cout << "time: " << (double)(finish - start) << std::endl;
}