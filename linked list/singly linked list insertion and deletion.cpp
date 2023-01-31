#include <bits/stdc++.h>
using namespace std;
class node {
public:
  int data;
  node *next;
  node(int d)
{
	this->data=d;
		this->next=NULL;
		}
};
void insertathead(node* &head,int d)
{
	node* newnode=new node(d);
	newnode->next=head;
	head=newnode;
}
void insertattail(node* &tail,int d)
{
	node* newnode=new node(d);
	tail->next=newnode;
	tail=newnode;
}
void print(node* &head)
{
	if(!head)
		return;
	node* temp=head;
	while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
}
void insertatpos(node* &head,int data,node* &tail,int pos)
{
	if(pos==1)
	{
		insertathead(head,data);
		return;
	}
	node* temp=head;
	int cnt=1;
	while(cnt<pos-1)
		{
			temp=temp->next;
			cnt++;
		}
		if(temp->next==NULL)
		{
			insertattail(tail,data);
			return;
		}
	node* newnode=new node(data);
  newnode->next=temp->next;
	temp->next=newnode;
}
void deletenode(int pos,node*&head)
{
	//deleting first node
	if(pos==1)
	{
		node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete(temp);
	}
	//deleting middle or first node
	else
	{
      node* curr=head;
		int count=1;
		  node* prev=NULL;
		  while(count<pos)
				{
					prev=curr;
					curr=curr->next;
					count++;
				}
		prev->next=curr->next;
		curr->next=NULL;
		delete(curr);
	}
}
int main()
{
	node* node1=new node(3);
	node* head=node1;
	node* tail=node1;
	// print(head);
	insertathead(head,23);
		insertattail(tail,25);
	insertatpos(head,22, tail,3);
	print(head);    
  // cout << "head " << head -> data << endl;
  // cout << "tail " << tail -> data << endl;

	return 0;
}
