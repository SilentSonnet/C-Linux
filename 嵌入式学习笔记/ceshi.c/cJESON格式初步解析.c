#include <stdio.h>
#include "cJSON.h"
//没有这个库cJSON   不过可以大概的了解一下解析流程
/*
本文件初步引入cjeson格式的api函数，进行初步的解析

*/
char *message = 
"{                              \
    \"name\":\"mculover666\",   \
    \"age\": 22,                \
    \"weight\": 55.5,           \
    \"address\":                \
        {                       \
            \"country\": \"China\",\
            \"zip-code\": 111111\
        },                      \
    \"skill\": [\"c\", \"Java\", \"Python\"],\
    \"student\": false          \
}";

int main(void)
{
    cJSON* cjson_test = NULL;
    cJSON* cjson_name = NULL;
    cJSON* cjson_age = NULL;
    cJSON* cjson_weight = NULL;
    cJSON* cjson_address = NULL;
    cJSON* cjson_address_country = NULL;
    cJSON* cjson_address_zipcode = NULL;
    cJSON* cjson_skill = NULL;
    cJSON* cjson_student = NULL;
    int    skill_array_size = 0, i = 0;
    cJSON* cjson_skill_item = NULL;

    /* 解析整段JSO数据 */
    cjson_test = cJSON_Parse(message);//通过节点读取解析全部数据
    if(cjson_test == NULL)//对数据返回值进行判断，如果没有解析到记得返回，并输出错误提示信息
    {
        printf("parse fail.\n");
        return -1;
    }

    /* 依次根据名称提取JSON数据（键值对） */
    cjson_name = cJSON_GetObjectItem(cjson_test, "name");//依次读取   通过name  保存到test然后返回cjson_name 
    cjson_age = cJSON_GetObjectItem(cjson_test, "age");
    cjson_weight = cJSON_GetObjectItem(cjson_test, "weight");

    printf("name: %s\n", cjson_name->valuestring);//输出匹配格式类型的    string 
    printf("age:%d\n", cjson_age->valueint);//输出匹配格式类型的     int
    printf("weight:%.1f\n", cjson_weight->valuedouble);//输出匹配格式类型的   double

    /* 解析嵌套json数据 */
    cjson_address = cJSON_GetObjectItem(cjson_test, "address");
    cjson_address_country = cJSON_GetObjectItem(cjson_address, "country");
    cjson_address_zipcode = cJSON_GetObjectItem(cjson_address, "zip-code");
    printf("address-country:%s\naddress-zipcode:%d\n", cjson_address_country->valuestring, cjson_address_zipcode->valueint);

    /* 解析数组 */
    cjson_skill = cJSON_GetObjectItem(cjson_test, "skill");//读取地址  保存地址
    skill_array_size = cJSON_GetArraySize(cjson_skill);//对数组获取长度
    printf("skill:[");
    for(i = 0; i < skill_array_size; i++)
    {
        cjson_skill_item = cJSON_GetArrayItem(cjson_skill, i);
        printf("%s,", cjson_skill_item->valuestring);
    }
    printf("\b]\n");

    /* 解析布尔型数据 */
    cjson_student = cJSON_GetObjectItem(cjson_test, "student");//  对于boll型数据进行解析时应该判断其 值  然后输出即可
    if(cjson_student->valueint == 0)
    {
        printf("student: false\n");
    }
    else
    {
        printf("student:error\n");
    }
    
    return 0;
}
