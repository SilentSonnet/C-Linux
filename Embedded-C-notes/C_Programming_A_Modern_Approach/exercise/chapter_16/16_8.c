#include <stdio.h>
#include <stdbool.h>

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

struct color
{
    int red;
    int green;
    int blue;
};

int main(void)
{
    // const struct color MAGENTA = {255, 0, 255};
    const struct color MAGENTA = {.red = 255, .blue = 255};
    struct color c;

    int color_red;

    printf("red:%d, green:%d, blue:%d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    c = make_color(255, 255, 255);
    printf("red:%d, green:%d, blue:%d\n", c.red, c.green, c.blue);
    color_red = getRed(c);
    printf("The red color is : %d\n", color_red);
    if (equal_color(MAGENTA, c))
        printf("The two color vertor is equal!\n");
    else
        printf("The two color vertor is not equal!\n");

    c = brighter(c);
    printf("red:%d, green:%d, blue:%d\n", c.red, c.green, c.blue);

    c = darker(c);
    printf("red:%d, green:%d, blue:%d\n", c.red, c.green, c.blue);

    return 0;
}

struct color make_color(int red, int green, int blue)
{
    struct color c;

    c.red = red > 255 ? 255 : (red < 0 ? 0 : red);
    c.green = green > 255 ? 255 : (green < 0 ? 0 : green);
    c.blue = blue > 255 ? 255 : (blue < 0 ? 0 : blue);

    return c;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    return ((color1.red == color2.red) &&
            (color1.green == color2.green) &&
            (color1.blue == color2.blue));
}

struct color brighter(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0)
        c.red = c.green = c.blue = 3;

    if (0 < c.red && c.red < 3)
        c.red = 3;
    if (0 < c.green && c.green < 3)
        c.green = 3;
    if (0 < c.blue && c.blue < 3)
        c.blue = 3;

    c.red = (int)(c.red / 0.7);
    c.green = (int)(c.green / 0.7);
    c.blue = (int)(c.blue / 0.7);

    if (c.red > 255)
        c.red = 255;
    if (c.green > 255)
        c.green = 255;
    if (c.blue > 255)
        c.blue = 255;

    return c;
}

struct color darker(struct color c)
{
    c.red = (int)(c.red * 0.7);
    c.green = (int)(c.green * 0.7);
    c.blue = (int)(c.blue * 0.7);

    return c;
}