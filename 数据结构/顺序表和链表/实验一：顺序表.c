#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct
{
    char name[10]; //����
    char no[8];   //8λѧ��
    int price;     //�ɼ�
}Student;
typedef  struct
{
  Student  elem[100]; //ָ������Ԫ�صĻ���ַ
  int  length; //���Ա�ĵ�ǰ����
  int listsize;//��
}Sqlist,*Seqlist;


void initlist( Seqlist L)//����һ���յ�˳�����Ա�
{
    L->length=0;
    L->listsize=MAXSIZE;
}

void displist(Seqlist L)//��ӡѧ����Ϣ
{
    int i;
    for( i=1;i<=L->length;i++)
    {
      printf("����:%s\n",L->elem[i-1].name);
      printf("ѧ��:%s\n",L->elem[i-1].no);
      printf("�ɼ�:%d\n",L->elem[i-1].price);
    }
    printf("\n");
}

void inputlist(Seqlist L)//ѧ����Ϣ������
{
    int i,n;
    printf("������ѧ���ĸ�����");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("������ѧ������Ϣ��\n");
        printf("������");
        scanf("%s",&L->elem[i].name);
        printf("ѧ�ţ�");
        scanf("%s",&L->elem[i].no);
        printf("�ɼ���");
        scanf("%d",&L->elem[i].price);
        L->length++;
    }
    printf("\n");
}

void seeklist(Seqlist L)//����ѧ���ڵ�λ�ò���ѧ����Ϣ
{
    int i;
    printf("���������ѧ���Ľ�㣺");
    scanf("%d",&i);
    while(i<1||i>L->length)
    {
          printf("���볬��ѧ�����������������������ѧ���Ľڵ㣺");
          scanf("%d",&i);
    }
    printf("��ѧ������Ϣ��\n");
    printf("������%s\nѧ�ţ�%s\n�ɼ���%d\n",L->elem[i-1].name,L->elem[i-1].no,L->elem[i-1].price);
}

void nameseeklist(Seqlist L)//����ѧ����������ѧ����Ϣ
{
       int i;
       char name[20];
       printf("���������ѧ��������");
       scanf("%s",&name);
       for(i=0;i<L->length;i++)
       {
            if(strcmp(L->elem[i].name,name)==0)
            {
                break;
            }
       }
       if(strcmp(L->elem[i].name,name)==0)
            {
                printf("��ѧ������Ϣ��\n");
                printf("ѧ�ţ�%s\n�ɼ���%d\n",L->elem[i].no,L->elem[i].price);
            }
      else
            printf("�ñ���û�и�ѧ����\n");

}

void deletelist(Seqlist L)//ѧ����Ϣ��ɾ��
{
      int i;
      int j;
      printf("������ɾ��ѧ���Ľڵ㣺");
      scanf("%d",&i);
      while(i<1||i>L->length)
      {
          printf("���볬��ѧ��������������������ɾ��ѧ���Ľڵ㣺");
          scanf("%d",&i);
      }
      for(j=i;j<=L->length-1;j++)
      {
          L->elem[j-1]=L->elem[j];
      }
      L->length--;
}
void insertlist(Seqlist L)//ѧ����Ϣ�Ĳ���
{
      int i,j,x;
      printf("������Ҫ����ѧ���Ľڵ�λ�ã�");
      scanf("%d",&i);
      if(L->length==MAXSIZE)
         printf("�洢�������޷�����\n");
      while(i<1||i>(L->length+1))
      {
         printf("�޷����룬�������������ѧ���Ľڵ�λ�ã�");
         scanf("%d",&i);
      }
         for(j=L->length-1;j>=i-1;j--)
         {
              L->elem[j+1]=L->elem[j];
         }
         printf("������ѧ������Ϣ��\n");
         printf("������");
         scanf("%s",&L->elem[i-1].name);
         printf("ѧ�ţ�");
         scanf("%s",&L->elem[i-1].no);
         printf("�ɼ���");
         scanf("%d",&L->elem[i-1].price);
         ++L->length;
         printf("\n");
}

int lengthlist(Seqlist L)//�����ѧ��������
{
    return L->length;
}

void main()//ѧ����Ϣ����ϵͳ��������
{
    Sqlist L1;
    Seqlist L=&L1;
    int k;
    initlist(L);//����һ���յ�˳�����Ա�
    inputlist(L);//����ѧ������Ϣ��
    printf("\n");
    displist(L);//��ӡѧ������Ϣ��
    printf("ѧ����Ϣ����ɹ���\n");
    printf("\n");
    printf("ѧ����Ϣ����ϵͳ�Ĳ���Ŀ¼:\n");
    printf("__________________________\n");
    printf("__________________________\n");
    printf("1������ѧ���Ľ��λ�ò���ѧ����Ϣ��2������ѧ������������ѧ����Ϣ��3������ѧ������Ϣ��4��ɾ��ѧ������Ϣ��5�������ѧ����������\n");
    printf("__________________________\n");
    while(1)
    {
        printf("��ѡ�������");
        scanf("%d",&k);
        switch(k)
        {
             case 0:printf("ллʹ�ã�");exit(0);
             case 1:seeklist(L);break;
             case 2:nameseeklist(L);break;
             case 3:insertlist(L);displist(L);break;
             case 4:deletelist(L);displist(L);break;
             case 5:printf("�ñ���ѧ��������%d\n",lengthlist(L));break;
        }
    }
}


