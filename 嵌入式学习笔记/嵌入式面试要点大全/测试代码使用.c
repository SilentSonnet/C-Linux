#include <stdio.h>
#include<stdlib.h>

struct c1{
    int c;//ͷ�ڵ�
    struct  c1* next;//����һ���ṹ��ָ��ָ����һ������
};
 //����������׵�ַ��һֱ��ӡ���ڰ���������cֵ   ֱ��ָ��NULL
 void printfLink(struct c1 *head)//����һ����������ĺ��� ����Ĳ�����ָ����  ����˵����Ĳ���Ҫȡ��ַ
 {//���Ǳ�������
struct c1 *point;//����ṹ��ָ��
point =  head; //�������ֵ����point   ����ָ�뻥�ำֵ
while(point !=NULL)//�жϽڵ��Ƿ�Ϊ��
{
    printf("%d",point->c);
    point =point->next;//����һ���ṹ�崫����
    putchar(' ');
}
putchar('\n');
}

//ͳ������ڵ��������
int GetLinkNodeNUm(struct c1 *head)
{
struct c1 *point ;
int  sum=0;//sum����  ͳ������Ľڵ���  ��ʵ�����ͱ������ 
point =head;
while(point !=NULL)
{
    sum++;
    point=point->next;
}
return  sum;
}
//������Һ���   ����Ĳ���Ϊ��Ҫ���ҵ������ͷ   ��  ���ҵ�����Ϊ  ����ֵΪ1 0�������������������У��ڵڼ�λ
int searchLink(struct c1 *head,int data)//
{
    struct c1 *point;
    int sum=1,flag=0,weizhi=0;//���ҵ�λ��Ϊ
    point =head;
    
    while(point!=NULL)
    {
        if(point->c==data) {weizhi=sum;break;}
        else   sum++;
        
        point=point->next;
    }
    return weizhi;
}
//�����ָ���ڵ�󷽲�������
/*
1 �ҵ�Ҫ�������ݵĽڵ�
2 ��Ҫ����Ľڵ� ָ�����Ľڵ�
3 ��ǰ�ڵ�ָ���³��ֵĽڵ�

*///����Ĳ���Ϊ ͷ�ڵ㣬ָ���Ľڵ����ݣ��µĽڵ�  ����ֵΪ1��ʾ����ɹ�  ����ֵΪ0��ʾʧ��
int  insertFromBehind(struct c1* head,int data,struct c1* new)
{
struct c1* point =head;
while(point !=NULL)
{
if(point->c==data)
{
    new->next=point->next;
    point->next=new;
    return 1;
}
point =point->next;
}
return 0;
}
//��ָ���ڵ�ǰ�������½ڵ�
/*
��Ϊ�����������һ ��ԭ����ͷ�ڵ㿪ʼ���룬ͷ�ڵ㱻����
1.�ҵ�ͷ�ڵ�
2.���½ڵ�  ָ��ԭ����ͷ�ڵ�
3.��ͷ�ڵ��Ϊ�½ڵ�

�ڶ������  ����ͷ�ڵ�֮ǰ����
1 �ҵ�������ڵ�
2 ���½ڵ�ָ�򱻲���ڵ�
3 ��������ڵ�֮ǰָ���½ڵ�
*/  //����ֵΪһ��ָ���ͽṹ��  �������Ϊ ����ͷ  ����������  �µĽڵ�����
struct c1* insertFromForward(struct c1* head,int data,struct c1* new)//  ������ֵ��Ϊͷ�ڵ�
{
    struct c1*point =head;
    if(point->c==data)//�ж��ǲ��ǽڵ�ͷ
    {
        new->next=head;
       return new;//�Ǿͷ����µ�ͷ
    }
    while(point->next!=NULL)
    {
        if(point->next->c==data)
        {
            new->next=point->next;
            point->next=new;
            printf("����ɹ�");
            return head;
        }   
        point=point->next;
    }
printf("û�ҵ�%d\n",data);
return head;//���Ǿͷ���ԭ����ͷ
}
//����ɾ��ָ���ڵ�
//ͬ����Ϊ����������ı�ͷ�ڵ�ĺͲ��ı��
/*
�ı�ͷ�ڵ��
�ҵ�ͷ���  ��ͷ����Ϊͷ������һ���ڵ�
���ı�ͷ����
ɾ����һ���ڵ�����������ڵ�
�ҵ�Ҫɾ���Ľڵ��
����ɾ���Ľڵ��ǰһ���ڵ�ָ��ָ��Ҫɾ����ͷ�ڵ����һ���ڵ�
*/
struct c1* deleteNode(struct c1* head,int data)//���ص�������ı�ͷ��ָ��
{
struct c1* point =head;
if(point->c==data)
{
    head=head->next;
    printf("��ʾ ɾ������ͷ���");
    return head;
}
while(point->next!=NULL)
{
    if(point->next->c==data)
    {
        point->next=point->next->next;
        printf("��ʾ  ɾ���Ĳ���ͷ���");
        return head;
    }
    point=point->next;
}
return head;
}
//���� ����ָ������Ϊ��һ������ �Ͳ������ƾ��Ƕ���һ������  
int changeLink(struct c1* head,int data,int new)
{
struct c1* point=head;
while(point!=NULL) 
{
if(point->c==data)
{
    point->c=new;
    return 1;
}
point =point->next;
}
return 0;
}
//��̬��������֮ͷ�巨
/*
1.���ͷ�ڵ�Ϊ�գ���ֱ�ӰѴ�����ڵ���Ϊͷ�ڵ�
2.���½Ӵ�2ָ��ԭ�ڵ�1
3.���½ڵ�2��Ϊͷ�ڵ�
4.���½ڵ�3ָ��ͷ�ڵ�2  �ظ�
*/
//api ���� Ϊͷ�巨�����ڵ㺯��
struct c1*insertFromHead(struct c1* head,struct c1* new)
{
    if(head==NULL)
    {
        head=new;
    }
    else 
    {
        new->next=head;
        head=new;
    }
    return head;
}
//ͷ�巨��������ĺ���
struct c1* creatLink(struct c1*head)
{
struct c1* new;
while(1)
{
    new=(struct c1*)malloc(sizeof(struct c1));//���붯̬�ڴ����洢�²���������
    printf("�����½ڵ�\n");
    scanf("%d",&(new->c));
    if(new->c==0)
    {
      printf("0  �˳�����");
      return  head;
    }
    head=insertFromHead(head,new);
}
}
//β�巨��������
/*
1  ���ͷ�ڵ�Ϊ�գ���ֱ�ӽ��½ڵ���Ϊͷ���
2  ���ϱ�������ֱ���ҵ�β�ڵ�1
3  ��β�ڵ�1��ָ��ָ���½ڵ�
*/
//�˺���Ϊ api����  ����β�巨�����ڵ�
struct c1* insertBehind(struct c1*head,struct c1*new)
{
struct c1*p=head;
if(p==NULL)
{
    head=new;
    return head;
}
else
{
    while(p->next !=NULL)
    {
        p=p->next;
    }
    p->next=new;
    new->next=NULL;
}
return head;
}
//β�巨��������
struct c1* creatLink2(struct c1*head)
{
    struct c1* new;
    while(1)
    {
        new=(struct c1*)malloc(sizeof(struct c1));
        printf("������ڵ�\n");
        scanf("%d",&(new->c));
        if(new->c==0)
        {
            printf("0  �˳�����\n");
            free(new);
            return head;
        }
        head=insertBehind(head,new);
    }
}
int main()
{
    
   struct c1 *f;
   struct c1 q={3,NULL};//�Խṹ����г�ʼ�����Խṹ�����һ��ָ��ֵNULL
   struct c1 q1={4,NULL};
   struct c1 q2={5,NULL};
   struct c1 new={100,NULL};
   int sum1=0,sum2=0;//�ڵ����
   int x;//x����Ҫ��ѯ�Ľڵ��ֵ
   q.next=&q1;//����һ���ṹ�������ָ���ַ  ͨ����ֵ���ݸ�ǰһ����ַ
   q1.next=&q2;
   f=&q;
printf("��һ������%d\n�ڶ�������%d\n",q.c,q.next->c);//q.c  �ǵ�һ���ṹ���ֵ��q.nextָ����һ���ṹ���ͷ��ַ
//ͨ��ָ�����õ���һ���ṹ�������ָ��ĵ�ַ ����һ���ṹ��ĵ�ַλ�ã�������������һ���ṹ���ֵ
printfLink(&q);
sum1=GetLinkNodeNUm(&q);
printf("������ڵ���Ϊ%d\n",sum1);


printf("��������Ҫ��ѯ����ֵ\n");
scanf("%d",&x);
sum2=searchLink(&q,x);//�˴�Ϊ��ѯ���ҵ�Ϊλ�ú������  


if(sum2>0)//�������ֵ������  ��ʾ���������в�ѯֵ�����ҷ���ֵ�ʹ�������λ�ã� ���С���������û��
printf("�����а�������%d,%d�ڵ�%dλ\n",x,x,sum2);
else 
printf("�����в���������%d\n",x);

// insertFromBehind(&q, 5, &new);//����ڵ�ֵ  5Ϊ�����ɵ���ֵx   ���ݷ���ֵ�������������ɺͲ���ʧ��
// //����֮������ڵ�ֵ
//  printfLink(&q);

// f=insertFromForward(&q,6,&new);//    ֮�����
// printfLink(f);

// f=deleteNode(&q,5);
// printfLink(f);   ɾ��ָ���ڵ�

// f=creatLink(f);  �������ͷ�ڵ�֮ǰ����
// printfLink(f);


// f=creatLink2(f);  //�������β�ڵ�֮�����
//  printfLink(f);

return 0;
}