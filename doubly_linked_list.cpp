#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;
node* previous;
node(){next=previous=NULL;cout<</*"node - constructor"<<*/endl;}
};

class list{
private:
node* head;
node* temp;
node* curr;
public:
list(){head=temp=curr=NULL; cout<< /*"List - constructor"<<*/endl;}
void add_node();
void print_forward();
void print_reverse();
void search_node();
void delete_node();
void print(node*);
};


void list:: add_node(){
int x;
char decide='a';
while (decide!='b'&& decide!='e'){
cout<< "Do you want to enter at begining or at end (begining = b, end = e) = ";
cin >>decide;
cout<<endl;
if(decide!='b'&&decide!='e'){cout<<"Please entera VALID ANSWER"<<endl;}
}

cout<<endl<< "Enter the number to add = ";
cin >> x;
cout<<endl;
node *n=new node;
n->next=NULL;
n->previous=NULL;
n->data=x;

if(head!=NULL&&decide=='e'){
curr=head;
while(curr->next != NULL){curr=curr->next;}
curr->next=n;
n->previous=curr;
}
else if(head!=NULL&&decide=='b'){n->next=head;head->previous=n;head=n;}
else{head=n;}
}


void list:: print_forward(){
curr=head;
while(curr!=NULL){
cout<< curr->data<<endl;
curr=curr->next;
}
}

void list:: print_reverse(){
cout<<"printing in reverse order"<<endl;
print(head);
cout<<endl;
}

void list::print(node* x){
if(x->next!=NULL){print(x->next);}
cout<< x->data<<endl;
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
if(j==0){cout<<"Number doesnot Exist"<<endl;}
else {if(j==1){cout<<"Number is in the list, found 1 time"<<endl;}
else{cout<< "Number is in the list, found "<<j<< " times"<<endl;}}

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
if(curr->next==NULL && curr->data != x){cout<<endl<<"NUMBER NOT AVAILABLE"<<endl;}
if(curr->data == x && curr->next==NULL){temp->next=NULL;}
if(curr->data == x && curr==head){head=head->next;head->previous=NULL;}
if (curr->data==x){temp->next=curr->next;curr=curr->next;if(curr!= NULL){curr->previous=temp;}}
}





int main(){
list object;
int i=10;
while(i!=0){
 cout<< endl<<endl<<" -- 1 -- to Insert"<< endl;
 cout<< " -- 2 -- to Search"<< endl;
 cout<< " -- 3 -- to Print in order"<< endl;
 cout<< " -- 4 -- to Print in reverse order"<< endl;
 cout<< " -- 5 -- to Delete"<< endl;
 cout<< " -- 0 -- to Exit"<<endl <<endl;
cout<<"Please select one of the above option = ";
cin>> i;
cout<<endl;
if(i>5||i<0){cout<< "Please select 1 of the above option"<<endl;}
else{
if(i==1){cout<<"You selected insertion ("<< i<<")"<<endl; object.add_node();}
if(i==2){cout<<"You selected Searching ("<< i<<")"<<endl; object.search_node();}
if(i==3){cout<<"You selected Printing in order to input("<< i<<")"<<endl; object.print_forward();}
if(i==4){cout<<"You selected printing in reverse order ("<< i<<")"<<endl; object.print_reverse();}
if(i==5){cout<<"You selected deletion ("<< i<<")"<<endl; object.delete_node();}
if(i==0){cout<<" time to exit"<<endl<<endl;}}
}

return 0;
}

