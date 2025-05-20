/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

void insert(int data, node*& head)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    node* temp = head;
    if(temp==NULL)
    {
        head= newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(node* &head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

node* split(node* &head, node* &head_a)
{
    int c=0;
    node* temp= head;
    node* head_c=head;
    while(temp!=NULL)
    {
        c++;
        temp= temp->next;
    }
    int pos = (c/2) + (c%2);
    for(int i=0; i<pos; i++)
    {
        insert(head_c->data, head_a);
        head_c= head_c->next;
    }
    return head_c;
}

void mergelist(node* &head_new, node* &head_a, node* &head_b)
{
    node* newnode = new node;
    while(head_a!=NULL and head_b!=NULL)
    {
        if(head_a->data>head_b->data)
        {
            insert(head_b->data, head_new);
            head_b= head_b->next;
        }
        else
        {
            insert(head_a->data, head_new);
            head_a= head_a->next;
        }
    }
    while(head_a)
    {
        insert(head_a->data, head_new);
        head_a= head_a->next;
    }
    while(head_b)
    {
        insert(head_b->data, head_new);
        head_b= head_b->next;
    }
}

int main()
{
    node* head= NULL;
    node* head_a= NULL;
    node* head_b= NULL;
    node* head_new= NULL;
    int arr[9]= {1,2,3,4,5,6,7,8,9};
    for(int i=0; i<9; i++)
    {
        insert(arr[i], head);
    }
    cout<<"The Primary Linked List: ";
    display(head);
    head_b= split(head, head_a);
    cout<<"The First Half: ";
    display(head_a);
    cout<<"The Second Hald :";
    display(head_b);
    cout<<"Merge Linked List: ";
    mergelist(head_new, head_a, head_b);
    display(head_new);
    return 0;
}
