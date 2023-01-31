#include <bits/stdc++.h>
using namespace std;
class node {
public:
  int data;
  node *next;
node* prev;
  node(int d)
{
	this->data=d;
		this->prev=NULL;
	this->next=NULL;
		}
};
void insertathead(node* &head,int d,node* &tail)
{
	if(!head)
	{
		node* newnode=new node(d);
		head=newnode;
		tail=newnode;
	}
	node* newnode=new node(d);
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
void insertattail(node* &tail,int d)
{
	if(!tail)
	{
		node* newnode=new node(d);
		tail=newnode;
	}
	node* newnode=new node(d);
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
}
void print(node* &head)
{
	node* temp=head;
	if(!head)
		return;
	while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
}
int getlength(node* head)
{
	int cnt=0;
	node* temp=head;
	while(temp!=NULL)
		{
			cnt++;
			temp=temp->next;
		}
	return cnt;
}
void insertatpos(node* &head,int data,node* &tail,int pos)
{
	if(pos==1)
	{
		insertathead(head,data,tail);
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
	newnode->prev=temp;
	temp->next=newnode;
	temp->next->prev=newnode;
}
void deletenode(int pos,node*&head)
{
	//deleting first or start node
    if(pos == 1) {
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < pos) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}
int main()
{
	node* node1=new node(3);
	node* head=node1;
	node* tail=node1;
	// print(head);
	insertathead(head,23,tail);
		insertattail(tail,25);
	insertatpos(head,22, tail,3);
	print(head);    
  // cout << "head " << head -> data << endl;
  // cout << "tail " << tail -> data << endl;

	return 0;
}
