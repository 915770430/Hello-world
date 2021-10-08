#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//����һ��ѧ���ṹ��
typedef struct student
{
	int id	;
	int score;
	struct student *next;
}student;

//��������
student *create(int n)
{
	//����ͷ�ڵ㣬���������
	student *head = NULL;
	head = (student *)malloc(sizeof(student));
	if(head == NULL) return NULL;
	memset (head,0,sizeof(student));
	head->id = -1;
	head->score = -1;
	head->next = NULL;
	
	//����Ҫ�����n��������Ϣ���µĽ��ӵ��������
	student *tmp = head;
	for (int i=0;i<n;i++)
	{
		student *new_node = (student *)malloc(sizeof(student));
		if(new_node == NULL) return NULL;
		scanf("%d %d",&new_node->id,&new_node->score);
		new_node->next = NULL;
		
		//�½��ӵ��������
		tmp->next = new_node;
		tmp = new_node;
	}
	return head;
}

//�ϲ������������ص�һ������ͷ��
student *mix_ab(student *a,student *b)
{
	if (a == NULL || b == NULL) return NULL;
	
	//�ҵ���һ�������β���
	student *tmp_a = a;
	while(tmp_a->next!=NULL)
	{
		tmp_a = tmp_a->next;
	}
	//����֮��tmp_a�ͳ�Ϊ��һ�������β���
	
	student *tmp_b = b;
	//��һ�������β������ӵڶ���������׽��
	tmp_a->next = tmp_b->next;
	//�ͷŵڶ��������ͷ���
	free(tmp_b);
	
	//���غϲ�֮���ͷ���
	return a;
}

//��������������
void sort_ab(student *students)
{
	if(students == NULL) return;
	student *pre=NULL;
	student *cur=NULL;
	student tmp;
	
	//ѡ�񷨶Խ���������
	for(pre=students->next;pre->next!=NULL;pre=pre->next)
	{
		for(cur=pre->next;cur!=NULL;cur=cur->next)
		{
			if(pre->id>cur->id)
			{
				//�����򽻻�
				tmp=*pre;
				*pre=*cur;
				*cur=tmp;
				//ָ���򽻻�
				tmp.next=pre->next;
				pre->next=cur->next;
				cur->next=tmp.next;
			}
		}
	}
}

//��ӡ������Ϣ
void print_ab(student *students)
{
	if(students==NULL || students->next == NULL)
	{
		printf("invalid list!\n");
		return;
	}
	student *cur = students->next;
	while(cur != NULL)
	{
		printf("%d %d\n",cur->id,cur->score);
		cur=cur->next;
	}
}

//������
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	//��������
	student *a = create(N);
	student *b = create(M);
	
	//�ϲ���������
	student *students = mix_ab(a,b);
	
	//������������������
	sort_ab(students);
	print_ab(students);
	
	//�ͷ�
	//destory_ab(students);
	return 0;
}