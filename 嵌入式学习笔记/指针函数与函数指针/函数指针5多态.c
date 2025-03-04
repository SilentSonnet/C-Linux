//��̬������������е�һ����Ҫ��������������ڲ�֪���������͵�����µ�����Ӧ�ĺ�����
//��Ȼ C ���Բ���������������ԣ���������Ȼ����ʹ�ú���ָ����ʵ�ֶ�̬
#include <stdio.h>
#include <stdlib.h>

typedef struct shape
{
    void (*draw)(struct shape *);
} shape_t;

typedef struct circle
{
    shape_t shape;
    int x;
    int y;
    int r;
} circle_t;

typedef struct rectangle
{
    shape_t shape;
    int x;
    int y;
    int w;
    int h;
} rectangle_t;

void circle_draw(shape_t *shape)
{
    circle_t *circle = (circle_t *)shape;
    printf("Drawing a circle at (%d, %d) with radius %d.\n", circle->x, circle->y, circle->r);
}

void rectangle_draw(shape_t *shape)
{
    rectangle_t *rectangle = (rectangle_t *)shape;
    printf("Drawing a rectangle at (%d, %d) with width %d and height %d.\n", rectangle->x, rectangle->y, rectangle->w, rectangle->h);
}

int main()
{
    circle_t circle =
    {
        .shape = {circle_draw},
        .x = 10,
        .y = 20,
        .r = 5,
    };
    rectangle_t rectangle =
    {
        .shape = {rectangle_draw},
        .x = 30,
        .y = 40,
        .w = 15,
        .h = 20,
    };
    shape_t *shapes[] = {(shape_t *)&circle, (shape_t *)&rectangle};
    for (size_t i = 0; i < sizeof(shapes) / sizeof(shape_t *); i++)
    {
        shapes[i]->draw(shapes[i]); 
     }
     return 0;
  }
/*
������Ĵ����У����Ƕ�����һ�� shape �ṹ�壬����һ������ָ�� draw�����ڻ��Ƹ���״��
??���ǻ�������������״��circle �� rectangle�����Ƿֱ���������Լ������Ժ�һ��ָ�� shape �ṹ���ָ�롣ÿ����״���������Լ��� draw ���������ڻ��Ƹ���״��
??�� main �����У����Ƕ�����һ�� shape_t ���͵����飬���а���һ�� circle ��һ�� rectangle������ʹ��һ��ѭ��������������飬��ʹ��ÿ����״�� draw ���������Ƹ���״��
??ע�⣬���� shapes �����е�Ԫ������Ϊ shape_t *����������Ȼ���Ե���ÿ��Ԫ�ص� draw ��������Ϊ circle �� rectangle ���Ǵ� shape_t ���������ģ����Ƕ�����һ�� draw ����ָ�롣
??���������ʾ�����ʹ�ú���ָ����ʵ�ֶ�̬������ C ���Բ�֧����������̣������ǿ���ʹ�ýṹ��ͺ���ָ����ʵ�����Ƶĸ��
??����ָ����һ��ǿ��Ĺ��ߣ���������ʵ����಻ͬ�ı��ģʽ���㷨��
??ʹ�ú���ָ����԰������Ǳ�д��������ͨ�õĴ��룬����ߴ���Ŀ������ԺͿ���չ�ԡ�

*/