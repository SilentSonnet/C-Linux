#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	float radius = 0.0f, volume = 0.0f, pi = 3.1415926f;
	printf("Please enter the radius:");
	scanf("%f", &radius);

	printf("The volume of the input sphere is:%.2f\n",
		4 / 3 * radius * radius * radius * pi);
	
	return 0;
}
// 如果将分数改写成4/3的话，就会被向下取整数为1，导致最终的计算结果不准确。
