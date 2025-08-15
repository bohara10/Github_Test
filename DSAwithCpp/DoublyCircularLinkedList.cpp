#include<iostream>
using namespace std;

class linkedlist{
  private:
  class node{
    public:
    int data;
    node *next;
    node *prev;

    node(){
      this->next=NULL;
      this->prev=NULL;
    }

    node(int d){
      this->data=d;
      this->next=NULL;
      this->prev=NULL;
    }
  };


  node *head;
  node *tail;

public:
  linkedlist(){
    this->head=NULL;
    this->tail=NULL;
  }

  private:
  int getdata(){
    int a;
    cout<<"Enter data : ";
    cin>>a;
    return a;
  }

  int getpos(){
    int po;
    cout<<"Enter the position : ";
    cin>>po;
    return po;
  }

  bool IsEmpty(){
    return head==NULL;
  }

bool IsOne(){
  return head->next==head;
}

public:
void insertop(){
  node *newnode=new node(getdata());
  if(IsEmpty()){
    head=tail=newnode;
    head->next=tail;
    tail->prev=head;
  }else{
    newnode->next=head;
    newnode->prev=tail;
    tail->next=newnode;
    head->prev=newnode;
    head=newnode;
  }
}


void insertat(){
  int pos = getpos();
  if(pos<1){
    cout<<"Error"<<endl;
  }else if(pos==1){
    insertop();
  }else{
    node *temp=head;
    for(int i=1;i<pos-1;++i){
      temp=temp->next;
      if(temp==head){
        cout<<"Error"<<endl;
        return ;
      }
    }
    if(temp->next==head){
      insertend();
    }else{
      node *newnode = new node (getdata());
      newnode-> next=temp->next;
      newnode->prev=temp;
      temp->next=newnode;
      newnode->next->prev=newnode;
    }
  }
}

void insertend(){
  node *newnode = new node(getdata());
  if(IsEmpty()){
    head=tail=newnode;
    head->next=tail;
    tail->next=head;
  }else{
    newnode->prev=tail;
    newnode->next=head;
    tail->next=newnode;
    head->prev=newnode;
    tail=newnode;
  }
}



  void deletetop(){
    if(IsEmpty()){
      cout<<"Error "<<endl;
    }else if(IsOne()){
      node *todel=head;
      head=tail=NULL;
      delete todel;
    }else{
      node *todel=head;
      head=head->next;
      head->prev=tail;
      tail->next=head;
    }
  }

  void deletend(){
    if(IsEmpty()){
      cout<<"Error"<<endl;
    }else if(IsOne()){
      node *todel=head;
      head=tail=NULL;
      delete todel;
    }else{
      node *todel=tail;
      tail=tail->prev;
      tail->next=head;
      head->prev=tail;
      delete todel;
    }
  }


  void deleteat(){
    int pos=getpos();
    if(IsEmpty()||pos<1){
      cout<<"Error"<<endl;
    }else if(pos==1){
      insertop();
    }else{
      node *temp = head;
      for(int i=1;i<pos-1;++i){
        temp = temp->next;
        if(temp==head||temp->next==head){
          cout<<"Error"<<endl;
          return;
        }
      }
      if(temp->next==tail){
        deletend();
      }else{
        node *todel = temp->next;
        temp->next=todel->next;
        todel->next->prev=temp;
        delete todel;
      }
    }
  }

void display(){
  if(IsEmpty()){
    cout<<"Error"<<endl;
  }else{
    node *temp=head;
    do{
      cout<<temp->data<<" ";
      temp=temp->next;
    }while(temp!=head);
    cout<<endl;
  }
}

void opos(){
  if(IsEmpty()){
    cout << "Error" << endl;
  } else {
    node *temp = tail;
    do {
      cout << temp->data << " ";
      temp = temp->prev;
    } while(temp != tail);
    cout << endl;
  }
}

};

int main(){
  linkedlist l;
  cout<<"Press 1 to insert top"<<endl;
  cout<<"Press 2 to insert end"<<endl;
  cout<<"Press 3 to insert at"<<endl;
  cout<<"Press 4 to delete top"<<endl;
  cout<<"Press 5 to delete end"<<endl;
  cout<<"Press 6 to delete at"<<endl;
  cout<<"Press 7 to show"<<endl;
  cout<<"Press 8 to search"<<endl;
  cout<<"Press any other key to exit"<<endl;

  int n=0;
  do{
    cin>>n;
    switch(n){
      case 1:
      l.insertop();
      break;

      case 2:
      l.insertend();
      break;

      case 3:
      l.insertat();
      break;

      case 4:
      l.deletetop();
      break;

      case 5:
      l.deletend();
      break;

      case 6:
      l.deleteat();
      break;

      case 7:
      l.display();
      break;


      default:
      n=8;
    }
  }while (n!=8);

  return 0;
}