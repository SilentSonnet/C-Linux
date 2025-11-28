#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
  return x > y ? x : y;         \
}     

int main(void)
{
    GENERIC_MAX(unsigned long)

    return 0;
}