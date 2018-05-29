#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
struct list* create(int n)
{
	struct list *temp;
	temp=(struct list*)malloc(sizeof(struct list));
	temp->data=n;
	temp->next='\0';
	return temp;
}
void traverse(struct list *head)
{
	struct list *iterator;
	if(head=='\0')
	{
		printf("List is empty");
	}
	else
	{
		iterator=head;
		while(iterator!='\0')
		{
			printf("%d->",iterator->data);
			iterator=iterator->next;
		}
	}
}
struct list * middle(struct list *head)
{
	struct list *temp1,*temp2;
	temp1=temp2=head;
	while(temp2!='\0')
	{
		temp2=temp2->next;
		if(temp2=='\0')
		{
		 	return temp1;
		}
		temp2=temp2->next;
		temp1=temp1->next;
	}
	return temp1;
}
int main()
{
	int n,c;
	struct list *head='\0',*temp,*node;
	while(scanf("%d",&n)>=1)
	{
		if(head=='\0')
		{
			head=create(n);
			node=head;
		}
		else
		{
			temp=create(n);
			node->next=temp;
			node=temp;
		}
		printf("For continue press 0 else press -1\t");
		scanf("%d",&c);
		if(c==-1)
		{
			break;
		}
	}
	traverse(head);
	temp=middle(head);
	printf("\nMiddle element is %d",temp->data);
}
