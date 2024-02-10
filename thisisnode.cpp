//lets code the node 

#include<iostream>
using namespace std;


class linkedlist{
  public :
  class node{
    public:
      int data;
      node *next;


      public:
      node(int value){
        //making the  constructor to intitialize the data
        this->data=value;
        this->next=nullptr;
      }

      void seenode(){
        cout<<data<<"   ";
      }
  };
  int datacount;
  node *head;

  linkedlist(){
    this->datacount=0;
    this->head=nullptr;
  }

    void makeempty(){
      cout<<"The destructor was called to destry"<<endl;
      while(head!=nullptr){
        node *temp=head;
        head=head->next;
        delete temp;
      }
  }

  int getdata(){
    int datum;
    cout<<"Enter data : ";
    cin>>datum;
    return datum;
  }

void Insertdatafrombegining(){
  node *newnode=new node(getdata());
  if(head==nullptr){
    head=newnode;
  }else{
    node *pointer=head;
    head=newnode;
    head->next=pointer;
  }
}

void Insertdataatlast(){
  node *thisnode=new node(getdata());
  if(head==nullptr){
    head=thisnode;
  }else{
  node *point=head;
  while(point->next!=nullptr){
    point=point->next;
  }
  point->next=thisnode;
  }
}

void deletefromtop(){
  node *del;
  if(head==nullptr){
    cout<<"no data to delete"<<endl;
  }else{
    del=head;
    head=head->next;
    delete del;
  }
}

void deletefromend(){
  if(head==nullptr){
    cout<<"No data to delete"<<endl;
  }else if(head->next==nullptr){
    head=nullptr;
  } else{

    node *letsgo=head;
    while(letsgo->next->next!=nullptr){
      letsgo=letsgo->next;
    }
    delete letsgo->next;
    letsgo->next=nullptr;
  }
}

void display(){
  if(head==nullptr){
    cout<<"no data to display"<<endl;
  }else{
  node *dis=head;
  while(dis!=nullptr){
    dis->seenode();
    dis=dis->next;
  }
}
}

};


int main(){
  linkedlist l;
  l.Insertdatafrombegining();
  l.Insertdatafrombegining();
  l.Insertdatafrombegining();
  l.Insertdataatlast();
  l.Insertdataatlast();
  l.deletefromend();
  l.display();
  return 0;
}