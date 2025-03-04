#include <stdio.h>
#include "cJSON.h"
//û�������cJSON   �������Դ�ŵ��˽�һ�½�������
/*
���ļ���������cjeson��ʽ��api���������г����Ľ���

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

    /* ��������JSO���� */
    cjson_test = cJSON_Parse(message);//ͨ���ڵ��ȡ����ȫ������
    if(cjson_test == NULL)//�����ݷ���ֵ�����жϣ����û�н������ǵ÷��أ������������ʾ��Ϣ
    {
        printf("parse fail.\n");
        return -1;
    }

    /* ���θ���������ȡJSON���ݣ���ֵ�ԣ� */
    cjson_name = cJSON_GetObjectItem(cjson_test, "name");//���ζ�ȡ   ͨ��name  ���浽testȻ�󷵻�cjson_name 
    cjson_age = cJSON_GetObjectItem(cjson_test, "age");
    cjson_weight = cJSON_GetObjectItem(cjson_test, "weight");

    printf("name: %s\n", cjson_name->valuestring);//���ƥ���ʽ���͵�    string 
    printf("age:%d\n", cjson_age->valueint);//���ƥ���ʽ���͵�     int
    printf("weight:%.1f\n", cjson_weight->valuedouble);//���ƥ���ʽ���͵�   double

    /* ����Ƕ��json���� */
    cjson_address = cJSON_GetObjectItem(cjson_test, "address");
    cjson_address_country = cJSON_GetObjectItem(cjson_address, "country");
    cjson_address_zipcode = cJSON_GetObjectItem(cjson_address, "zip-code");
    printf("address-country:%s\naddress-zipcode:%d\n", cjson_address_country->valuestring, cjson_address_zipcode->valueint);

    /* �������� */
    cjson_skill = cJSON_GetObjectItem(cjson_test, "skill");//��ȡ��ַ  �����ַ
    skill_array_size = cJSON_GetArraySize(cjson_skill);//�������ȡ����
    printf("skill:[");
    for(i = 0; i < skill_array_size; i++)
    {
        cjson_skill_item = cJSON_GetArrayItem(cjson_skill, i);
        printf("%s,", cjson_skill_item->valuestring);
    }
    printf("\b]\n");

    /* �������������� */
    cjson_student = cJSON_GetObjectItem(cjson_test, "student");//  ����boll�����ݽ��н���ʱӦ���ж��� ֵ  Ȼ���������
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
