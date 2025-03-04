//���ĵ���  ���弰С���� �Լ�������

//���Ҫ���Իش�ص���������Ļ�
/*�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ����
���������ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú�����ʵ��
��ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��
*/
/*�����

��һ�ο�ִ�еĴ���������������������������룬����δ������ĳ��ʱ�̱�����ִ�У���ͽ����ص���

�������������ִ�оͳ�Ϊͬ���ص������������ִ�У����֮Ϊ�첽�ص���

�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�������

�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ


�ڻص��У�������ѻص����������һ������⺯��  �ص�
ֻҪ���Ǹı䴫���⺯���Ĳ������Ϳ���ʵ�ֲ�ͬ�Ĺ��ܣ�������û�о��ú������ҵ��⺯���ܸ�
�ӻ��߲��ɼ���ʱ�����ûص��������Ե�ʮ�����㡣

*/
#include <stdio.h>
#include <stdlib.h>
 
/****************************************
 * ����ָ��ṹ��
 ***************************************/
typedef struct _OP {
    float (*p_add)(float, float); 
    float (*p_sub)(float, float); 
    float (*p_mul)(float, float); 
    float (*p_div)(float, float); 
} OP; 
 
/****************************************
 * �Ӽ��˳�����
 ***************************************/
float ADD(float a, float b) 
{
    return a + b;
}
 
float SUB(float a, float b) 
{
    return a - b;
}
 
float MUL(float a, float b) 
{
    return a * b;
}
 
float DIV(float a, float b) 
{
    return a / b;
}
 
/****************************************
 * ��ʼ������ָ��
 ***************************************/
void init_op(OP *op)
{
    op->p_add = ADD;
    op->p_sub = SUB;
    op->p_mul = MUL;
    op->p_div = DIV;
}
 
/****************************************
 * �⺯��
 ***************************************/
float add_sub_mul_div(float a, float b, float (*op_func)(float, float))
{
    return (*op_func)(a, b);
}
 
int main(int argc, char *argv[]) 
{
    OP *op = (OP *)malloc(sizeof(OP)); 
    init_op(op);
    
    /* ֱ��ʹ�ú���ָ����ú��� */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (op->p_add)(1.3, 2.2), (*op->p_sub)(1.3, 2.2), 
            (op->p_mul)(1.3, 2.2), (*op->p_div)(1.3, 2.2));
     
    /* ���ûص����� */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", 
            add_sub_mul_div(1.3, 2.2, ADD), 
            add_sub_mul_div(1.3, 2.2, SUB), 
            add_sub_mul_div(1.3, 2.2, MUL), 
            add_sub_mul_div(1.3, 2.2, DIV));
 
    return 0; 
}
//������
/*
һ��GPRSģ��������С��Ŀ��ʹ�ù���ͬѧ���֪��2G��4G��NB��ģ��Ҫ��ʵ�������������ܶ���Ҫ����ģ���ϵ��ʼ����
ע�����硢��ѯ������Ϣ���������ӷ������Ȳ��裬����ĵ����Ӿ��ǣ�����һ��״̬�����������ݲ�ͬ״̬���ε��ò�ͬʵ��
�����ĺ�������ͨ���ص������ķ�ʽ���ε��ò�ͬ�ĺ�����ʵ��ģ���������ܣ����£�

/*********  ����״̬����  ********

typedef struct
{
 uint8_t mStatus;
 uint8_t (* Funtion)(void); //����ָ�����ʽ
} M26_WorkStatus_TypeDef;  //M26�Ĺ���״̬���ϵ��ú���
 
 
/**********************************************
** >M26����״̬���Ϻ���
***********************************************/
/*
M26_WorkStatus_TypeDef M26_WorkStatus_Tab[] =
{    
    {GPRS_NETWORK_CLOSE,  M26_PWRKEY_Off  }, //ģ��ػ�
    {GPRS_NETWORK_OPEN,  M26_PWRKEY_On  }, //ģ�鿪��
    {GPRS_NETWORK_Start,   M26_Work_Init  }, //�ܽų�ʼ��
    {GPRS_NETWORK_CONF,  M26_NET_Config  }, /ATָ������
    {GPRS_NETWORK_LINK_CTC,  M26_LINK_CTC  }, //���ӵ�������  
    {GPRS_NETWORK_WAIT_CTC, M26_WAIT_CTC  },  //�ȴ��������Ļظ� 
    {GPRS_NETWORK_LINK_FEM, M26_LINK_FEM  }, //����ǰ�û�
    {GPRS_NETWORK_WAIT_FEM, M26_WAIT_FEM  }, //�ȴ�ǰ�û��ظ�
    {GPRS_NETWORK_COMM,  M26_COMM   }, //��������    
    {GPRS_NETWORK_WAIT_Sig,  M26_WAIT_Sig  },  //�ȴ��źŻظ�
    {GPRS_NETWORK_GetSignal,  M26_GetSignal  }, //��ȡ�ź�ֵ
    {GPRS_NETWORK_RESTART,  M26_RESET   }, //ģ������
}
/**********************************************
** >M26ģ�鹤��״̬�������ε��������12������   
**********************************************
uint8_t M26_WorkStatus_Call(uint8_t Start)
{
    uint8_t i = 0;
    for(i = 0; i < 12; i++)
    {
        if(Start == M26_WorkStatus_Tab[i].mStatus)
        {          
      return M26_WorkStatus_Tab[i].Funtion();
        }
    }
    return 0;
}
*/