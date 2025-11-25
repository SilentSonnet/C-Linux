#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 100

void build_index_url(const char *domain, char *index_url);

int main(void)
{
    char domain[SIZE] = "knking.com", index_url[SIZE];

    build_index_url(domain, index_url);
    printf("The result is : %s\n", index_url);

    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}