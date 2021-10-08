#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义一个学生结构体
typedef struct student
{
	int id	;
	int score;
	struct student *next;
}student;

//创建链表
student *create(int n)
{
	//定义头节点，不存放数据
	student *head = NULL;
	head = (student *)malloc(sizeof(student));
	if(head == NULL) return NULL;
	memset (head,0,sizeof(student));
	head->id = -1;
	head->score = -1;
	head->next = NULL;
	
	//输入要加入的n个结点的信息，新的结点加到链表最后
	student *tmp = head;
	for (int i=0;i<n;i++)
	{
		student *new_node = (student *)malloc(sizeof(student));
		if(new_node == NULL) return NULL;
		scanf("%d %d",&new_node->id,&new_node->score);
		new_node->next = NULL;
		
		//新结点加到链表最后
		tmp->next = new_node;
		tmp = new_node;
	}
	return head;
}

//合并两个链表，返回第一个链表头部
student *mix_ab(student *a,student *b)
{
	if (a == NULL || b == NULL) return NULL;
	
	//找到第一个链表的尾结点
	student *tmp_a = a;
	while(tmp_a->next!=NULL)
	{
		tmp_a = tmp_a->next;
	}
	//出来之后tmp_a就成为第一个链表的尾结点
	
	student *tmp_b = b;
	//第一个链表的尾结点连接第二个链表的首结点
	tmp_a->next = tmp_b->next;
	//释放第二个链表的头结点
	free(tmp_b);
	
	//返回合并之后的头结点
	return a;
}

//链表结点排序重组
void sort_ab(student *students)
{
	if(students == NULL) return;
	student *pre=NULL;
	student *cur=NULL;
	student tmp;
	
	//选择法对结点进行排序
	for(pre=students->next;pre->next!=NULL;pre=pre->next)
	{
		for(cur=pre->next;cur!=NULL;cur=cur->next)
		{
			if(pre->id>cur->id)
			{
				//数据域交换
				tmp=*pre;
				*pre=*cur;
				*cur=tmp;
				//指针域交换
				tmp.next=pre->next;
				pre->next=cur->next;
				cur->next=tmp.next;
			}
		}
	}
}

//打印链表信息
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

//主函数
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	//创建链表
	student *a = create(N);
	student *b = create(M);
	
	//合并两个链表
	student *students = mix_ab(a,b);
	
	//对新链表进行排序并输出
	sort_ab(students);
	print_ab(students);
	
	//释放
	//destory_ab(students);
	return 0;
}