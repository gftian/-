#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct {
    char no[10];   //8λѧ��
    char name[20]; //����
    int price;     //�ɼ�
}Student;

typedef struct LNode
{
	Student data;
	struct LNode *next;
}LNode,*Linklist;


Linklist creatlist()//��ͷ���뷨������ѧ����Ϣ��
{
    Linklist L,p;
    int i,n;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    printf("������Ҫ¼��ѧ���ĸ�����");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(LNode));
        printf("������ѧ������Ϣ��\n");
        printf("������");
        scanf("%s",&p->data.name);
        printf("ѧ�ţ�");
        scanf("%s",&p->data.no);
        printf("�ɼ���");
        scanf("%d",&p->data.price);
        p->next=L->next;
        L->next=p;
    }
    return L;
}

void putlist(Linklist L)//��ӡѧ����Ϣ��
{
    Linklist p;
    p=L->next;
    while(p)
    {
        printf("������%s\nѧ�ţ�%s\n�ɼ���%d\n",p->data.name,p->data.no,p->data.price);
        p=p->next;
        printf(" ");
    }printf("\n");
}

int lengthlist(Linklist L)//��ѧ����������
{
    Linklist p;
    int j;
    p=L->next;
    j=0;
    while(p!=NULL)
    {
        j++;
        p=p->next;
    }
    printf("���е�ѧ������Ϊ:%d\n",j);
}
void namegetlist(Linklist L)//����ѧ����������ѧ������Ϣ��
{
    char name[10];
    int j=1;
    Linklist p;
    printf("���������ѧ��������:");
    scanf("%s",&name);
    p=L->next;
    while(p&&strcmp(p->data.name,name)!=0)
    {
        p=p->next;
        j++;
    }
    if(p)
        printf("��ѧ������Ϣ��\nѧ�ţ�%s\n�ɼ���%d\n",p->data.no,p->data.price);
    else
        printf("�ñ���û�и�ѧ������Ϣ��");
    }
void getlist(Linklist L)//����ѧ�����λ�ò���ѧ����Ϣ��
{
    int i,j=1,l=0;
    Linklist p;
    printf("���������ѧ����λ�ý�㣺");
    scanf("%d",&i);
    p=L->next;
    while(p!=NULL)
    {
             l++;
             p=p->next;
    }
    p=L->next;
    while((p->next)&&(j<i))
    {
             p=p->next;
             ++j;
    }
    while(i>l)
    {
              printf("����Ľ��ֵ����ѧ������ ������������ѧ����λ�ý�㣺");
              scanf("%d",&i);
    }
    while((p!=NULL)&&(j<i))
    {
             p=p->next;
             j++;
    }
    printf("����ѧ����Ϣ��\n����:%s\nѧ�ţ�%s\n�ɼ���%d\n",p->data.name,p->data.no,p->data.price);
}

void insertlist(Linklist L)//ѧ����Ϣ���롣
{
    int i,j,l;
    Linklist p,s;
    p=L;l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    printf("���������ѧ���Ľ��λ��:");
    scanf("%d",&i);
    while(l<i)
    {
         printf("����Ľ��ֵ�ѳ�������,�������������ѧ���Ľ��λ��:");
         scanf("%d",&i);
    }
    p=L;j=1;
    while(p&&(j<i))
    {
        p=p->next;
        ++j;
    }
    s=(Linklist)malloc(sizeof(LNode));
    printf("������ѧ������Ϣ��\n");
    printf("������");
    scanf("%s",&s->data.name);
    printf("ѧ�ţ�");
    scanf("%s",&s->data.no);
    printf("�ɼ���");
    scanf("%d",&s->data.price);
    s->next=p->next;
    p->next=s;
    printf("ѧ����Ϣ����ɹ���");
    printf("\n");
}
void deletelist(Linklist L)//ѧ����Ϣ��ɾ����
{
    int i,j,l=0;
    Linklist p,q;
    p=L->next;
    while(p!=NULL)
    {
        l++;p=p->next;
    }
    printf("������Ҫɾ��ѧ����λ�ý�㣺");
    scanf("%d",&i);
    while(l<i)
    {
        printf("����Ľ��ֵ��������,����������Ҫɾ��ѧ����λ�ý�㣺");
        scanf("%d",&i);
    }
    p=L; j=1;
    while((p->next)&&(j<i))
    {
        p=p->next;
        ++j;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    printf("ɾ���ɹ���\n");
}


int main()//������
{
    Linklist L;
    int k;
    L=creatlist();
    printf("\n");
    putlist(L);
    printf("ѧ����Ϣ����ɹ���\n");
    printf("ѧ����Ϣ����ϵͳ�Ĳ���Ŀ¼:\n");
    printf("__________________________\n");
    printf("__________________________\n");
    printf("1������ѧ���Ľ��λ�ò���ѧ����Ϣ��2�������ѧ����������3������ѧ������Ϣ��4��ɾ��ѧ������Ϣ��5������ѧ������������ѧ����Ϣ��\n");
    printf("__________________________\n");
    while(1)
    {
        printf("��ѡ�������");
        scanf("%d",&k);
        switch(k)
        {
             case 0:printf("ллʹ�ã�");exit(0);
             case 1:getlist(L);break;
             case 2:lengthlist(L);break;
             case 3:insertlist(L);putlist(L);break;
             case 4:deletelist(L);putlist(L);break;
             case 5:namegetlist(L);break;
        }
    }
}

