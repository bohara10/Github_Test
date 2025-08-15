#include<iostream>
using namespace std;

class node{
  public :
  int data;
  node *next;
  node *prev;

  node(){
  }

node(int x) : data(x), next(NULL), prev(NULL) {}

};

class linkedlist{
private:
    node *head;
    public:
    linkedlist(){
      this->head=NULL;
    }

    private:
    int getdata(){
      int a;
      cout<<"Enter data : ";
      cin>>a;
      return a;
    }


    bool checkone(){
      return head->next==NULL;
    }

    bool checkempty(){
      return head==NULL;
    }

    public:
    void inserttop(){
      node *newnode=new node(getdata());
      if(!checkempty()){
        newnode->next=head;
        head->prev=newnode;
      }
      head=newnode;
    }

    void insertend(){
      node *newnode=new node(getdata());
      if(checkempty()){
        head=newnode;
      }else{
        node *temp=head;
        while(temp->next!=NULL){
          temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
      }
    }

    void deletetop(){
      if(!checkempty()){
        node *todel=head;
        head=head->next;
        if(head!=NULL){
        head->prev=NULL;
        }
        delete todel;
      }
    }

    void deletend(){
      if(checkempty()){
        cout<<"the list is empty"<<endl;
      }else if(checkone()){
        deletetop();
      }else{
        node *temp=head;
        while(temp->next->next!=NULL){
          temp=temp->next;
        }
        node *todel=temp->next;
        delete todel;
        temp->next=NULL;
      }
    }

    void display(){
      node *temp=head;
      while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
      }
      cout<<endl;
    }


    void deleteat(){
      cout<<"Enter the position to insertat : ";
      int pos;
      cin>>pos;
      if(pos<1||checkempty()){
        cout<<"Low Indexing Error"<<endl;
        return;
      }else if(pos==1){
        deletetop(); 
        return;
      }else{
        node *temp=head;
          for(int i=1;i<pos-1;++i){
          temp=temp->next;
          if(temp==NULL||temp->next==NULL){
            cout<<"High Indexing Error"<<endl;
            return;
          }
        }
         if(temp->next->next==NULL){
          deletend();
         }
         else{
          node *todel=temp->next;
          temp->next=todel->next;
          todel->next->prev=temp;
          delete todel;
         }


    }}

    void insertat(){
      cout<<"Enter the position to insertat : ";
      int pos;
      cin>>pos;
    if(pos==1){
        inserttop(); 
        return;
      }else if(pos<1||checkempty()){
       cout<<"Low Indexing Error"<<endl;
        return;
      }else{
        node *temp=head;
        for(int i=1;i<pos-1;++i){
          temp=temp->next;
          if(temp==NULL){
            cout<<"High Indexing Error"<<endl;
            return;
          }
        }
        if(temp->next==NULL){
          insertend();
        }else{
        node *newnode=new node(getdata());
        newnode->next=temp->next;
        newnode->prev=temp;
        newnode->next->prev=newnode;
        temp->next=newnode;
      }
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
      l.inserttop();
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