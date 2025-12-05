#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point { int x,  y; };
struct rectangle { struct point upper_left, lower_right; };

int calculate_area(struct rectangle r);
struct point calculate_center(struct rectangle r);
bool isInPoint(struct rectangle r, struct point p);
void move(struct rectangle *r, int x, int y);

char *string;

int main(void)
{
    bool isInside = false;
    struct point p;
    struct rectangle r;

    printf("Enter upper-left coordinates :");
    scanf("%d%d", &r.upper_left.x, &r.upper_left.y);
    printf("Enter lower_right coordinates :");
    scanf("%d%d", &r.lower_right.x, &r.lower_right.y);

    printf("The area is: %d\n", calculate_area(r));

    p = calculate_center(r);
    printf("The center point is: (%d, %d)\n", p.x, p.y);

    printf("The rectangle before moving is:(%d, %d), (%d, %d)\n", r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);
    move(&r, 1, 1);
    printf("The rectangle after moving is:(%d, %d), (%d, %d)\n", r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);


    printf("Enter the point :");
    scanf("%d%d", &p.x, &p.y);
    string = isInPoint(r, p) ? "" : " NOT" ;
    printf("The point is%s inside the rectangle.\n", string);

    return 0;
}

int calculate_area(struct rectangle r)
{
    return abs((r.upper_left.x - r.lower_right.x) * (r.upper_left.y - r.lower_right.y));
}

struct point calculate_center(struct rectangle r)
{
    struct point p;

    p.x = (r.upper_left.x + r.lower_right.x) / 2;
    p.y = (r.upper_left.y + r.lower_right.y) / 2;

    return p;
}

void move(struct rectangle *r, int x, int y)
{
    (*r).upper_left.x += x;
    (*r).lower_right.x += x;

    (*r).upper_left.y += y;
    (*r).lower_right.y += y;
}

bool isInPoint(struct rectangle r, struct point p)
{
    return ((r.lower_right.x <= p.x && p.x <= r.upper_left.x && r.upper_left.y <= p.y && p.y <= r.lower_right.y));
}