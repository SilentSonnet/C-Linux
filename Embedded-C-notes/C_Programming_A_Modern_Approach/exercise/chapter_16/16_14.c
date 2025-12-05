#include <stdio.h>

#define RECTANGLE 1
#define CIRCLE 2
#define PI 3.1415926

struct shape
{
    int shape_kind; /* RECTANGLE or CIRCLE */
    struct point
    {
        int x, y;
    } center; /* coordinates of center */
    union
    {
        struct
        {
            int height, width;
        } rectangle;
        struct
        {
            int radius;
        } circle;
    } u;
} s;

double calculate_area(struct shape s);
void move(struct shape *s, int x, int y);
void scale(struct shape *s, double scale);

int main(void)
{
    struct shape s1 = {
        .shape_kind = RECTANGLE,
        .center = {0, 0},
        .u.rectangle = {5, 10} // height = 5, width = 10
    };
    struct shape s2 = {
        .shape_kind = CIRCLE,
        .center = {0, 0},
        .u.circle = {7} // radius = 7
    };
    struct shape s3 = {
        .shape_kind = RECTANGLE,
        .center = {1, 2},
        .u.rectangle = {3, 4} // height = 3, width = 4
    };
    struct shape s4 = {
        .shape_kind = CIRCLE,
        .center = {3, 4},
        .u.circle = {10} // radius = 10
    };

    printf("The area is :%.2f\n", calculate_area(s1));
    printf("The area is :%.2f\n", calculate_area(s2));

    printf("The center coordinate before moving is: (%d,%d)\n", s4.center.x, s4.center.y);
    move(&s4, 1, 2);
    printf("The center coordinate after moving is: (%d,%d)\n", s4.center.x, s4.center.y);

    printf("The size before scaling is: (%d,%d)\n", s3.u.rectangle.width, s3.u.rectangle.height);
    scale(&s3, 1.5);
    printf("The size after scaling is: (%d,%d)\n", s3.u.rectangle.width, s3.u.rectangle.height);

    return 0;
}

double calculate_area(struct shape s)
{
    double area;

    switch (s.shape_kind)
    {
    case RECTANGLE:
        area = s.u.rectangle.width * s.u.rectangle.height;
        break;
    case CIRCLE:
        area = s.u.circle.radius * s.u.circle.radius * PI;
        break;
    default:
        printf("False input!\n");
        area = 0.0;
        break;
    }

    return area;
}

void move(struct shape *s, int x, int y)
{
    (*s).center.x += x;
    (*s).center.y += y;
}

void scale(struct shape *s, double scale)
{
    switch ((*s).shape_kind)
    {
    case RECTANGLE:
        (*s).u.rectangle.width *= scale;
        (*s).u.rectangle.height *= scale;
        break;
    case CIRCLE:
        (*s).u.circle.radius *= scale;
        break;
    default:
        printf("False input!\n");
        break;
    }
}