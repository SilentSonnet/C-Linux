#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	float radius = 0.0f, volume = 0.0f, pi = 3.1415926f;
	printf("Please enter the radius:");
	scanf("%f", &radius);

	printf("The volume of the input sphere is:%.2f\n",
		4.0f / 3.0f * radius * radius * radius * pi);
	
	return 0;
}
