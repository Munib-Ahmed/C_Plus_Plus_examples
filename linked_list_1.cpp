#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;
node(){next=NULL;/*cout<<"node - constructor"<<endl;*/}
};

class list{
private:
node* head;
node* temp;
node* curr;
public:
list(){head=temp=curr=NULL; /*cout<< "List - constructor"<<endl;*/}
void add_node();
void print();
void search_node();
void delete_node();
};


void list:: add_node(){
int x;
cout<< "Enter the number to add = ";
cin >> x;
node *n=new node;
n->next=NULL;
n->data=x;

if(head!=NULL){
curr=head;
while(curr->next != NULL){curr=curr->next;}
curr->next=n;
}
else{head=n;}
}


void list:: print(){
curr=head;
while(curr!=NULL){
cout<< curr->data<<endl;
curr=curr->next;
}
}

void list:: search_node(){
curr=head;
int x=0,j=0;
cout<< "Enter number to search = ";
cin >>x;
while(curr!=NULL){
if(curr->data==x)
{j=j+1;}
curr=curr->next;
}
if(j==0){cout<<"NUmmber doesnot Exist"<<endl;}
else{cout<< "Number is in the list, found "<<j<< " times"<<endl;}

}


void list:: delete_node(){
int x;
cout<< "Enter the number to delete = ";
cin >> x;
temp=head;
curr=head;
while (curr->data != x && curr->next!=NULL){
temp=curr;
curr=curr->next;
}
if(curr->next==NULL && curr->data != x){cout<<"Number not avaialable"<<endl;}
if (curr->data==x){temp->next=curr->next;}
if(curr->data == x && curr->next==NULL){temp->next=NULL;}
if(curr->data == x && curr==head){head=head->next;}
}


int main(){
list object;
int i=10;
while(i!=0){
 cout<< " -- 1 -- to Insert"<< endl;
 cout<< " -- 2 -- to Search"<< endl;
 cout<< " -- 3 -- to Print"<< endl;
 cout<< " -- 4 -- to Delete"<< endl;
 cout<< " -- 0 -- to Exit"<< endl;
cout<<"Please select one of the above option = ";
cin>> i;
if(i>4||i<0){cout<< "Please select 1 of the above option"<<endl;}
else{
if(i==1){cout<<"You selected insertion ("<< i<<")"<<endl; object.add_node();}
if(i==2){cout<<"You selected Searching ("<< i<<")"<<endl; object.search_node();}
if(i==3){cout<<"You selected Printing ("<< i<<")"<<endl; object.print();}
if(i==4){cout<<"You selected deletion ("<< i<<")"<<endl; object.delete_node();}
if(i==0){cout<<" time to exit"<<endl;}}
}

return 0;
}

