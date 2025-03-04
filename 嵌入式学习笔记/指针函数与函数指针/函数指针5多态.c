//多态是面向对象编程中的一个重要概念，它允许我们在不知道对象类型的情况下调用相应的函数。
//虽然 C 语言不是面向对象编程语言，但我们仍然可以使用函数指针来实现多态
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
在上面的代码中，我们定义了一个 shape 结构体，它有一个函数指针 draw，用于绘制该形状。
??我们还定义了两个形状：circle 和 rectangle，它们分别包含它们自己的属性和一个指向 shape 结构体的指针。每个形状都定义了自己的 draw 函数，用于绘制该形状。
??在 main 函数中，我们定义了一个 shape_t 类型的数组，其中包含一个 circle 和一个 rectangle。我们使用一个循环来遍历这个数组，并使用每个形状的 draw 函数来绘制该形状。
??注意，尽管 shapes 数组中的元素类型为 shape_t *，但我们仍然可以调用每个元素的 draw 函数，因为 circle 和 rectangle 都是从 shape_t 派生出来的，它们都包含一个 draw 函数指针。
??这个例子演示了如何使用函数指针来实现多态。尽管 C 语言不支持面向对象编程，但我们可以使用结构体和函数指针来实现类似的概念。
??函数指针是一种强大的工具，可以用于实现许多不同的编程模式和算法。
??使用函数指针可以帮助我们编写更加灵活和通用的代码，并提高代码的可重用性和可扩展性。

*/