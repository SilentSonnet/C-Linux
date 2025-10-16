/* Computes the dimensional weight of a 12" x 10" x 8" box */ 
#include <stdio.h> 
int main(void) 
{ 
 int height = 8, length = 12, width = 10, volume; 
 volume = height * length * width; 
 printf("Dimensions: %dx%dx%d\n", length, width, height); 
 printf("Volume (cubic inches): %d\n", volume); 
 printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166); 
 return 0; 
}

// 1.使用初始化器替换变量的赋值
// 2.去掉了weight变量，直接在printf用表达式中来输出。
