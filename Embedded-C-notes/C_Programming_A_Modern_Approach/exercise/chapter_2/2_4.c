#include<stdio.h>
int main(void)
{
	int a, b, c;
	float d, e, f;
	printf("%d, %d, %d\n", a, b, c);
	printf("%f, %f, %f\n", d, e, f);
	return 0;
}
// 如果没有给数据赋初值，这些变量使用的就是未经初始化的内存的数值。
// 很明显，这些输出的数值没有一点点的规律。
