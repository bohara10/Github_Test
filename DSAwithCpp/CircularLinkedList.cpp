#include<iostream>
using namespace std;

template<typename k>
class queue{

private:
class node{
  public:
  k data;
  node *next;

node(){
  this->next=NULL;
}

node(k ta){
  this->data=ta;
  this->next=NULL;
}
};
node *head;
node *tail;

public:

queue(){
  this->head=NULL;
  this->tail=NULL;
}

bool IsEmpty(){
  return head==NULL;
}


void Enqueue(k datum){
  node *newnode = new node(datum);
  if(IsEmpty()){
    head=tail=newnode;
    }else{
    tail->next=newnode;
    tail=newnode;
  }
   tail->next=head;
}


k getdata(){
  k d;
  cout<<"Enter data : "<<endl;
  cin>>d;
  return d;

}

k dequeue(){
  if(IsEmpty()){
    throw std::underflow_error("Queue is Empty");
  }else {
    node *todel=head;
    k ret = head->data;

    if(head==tail){
      head=tail=NULL;
    }else{
      head=head->next;
      tail->next=head;
    }
    delete todel;
    return ret;
  }
}


void makeempty(){
while(!IsEmpty()){
  node *todel=head;
  head=head->next;
  delete todel;
}
}

void display(){
  if(IsEmpty()){
    cout<<"The Queue is empty"<<endl;
  }else{
    node *temp = head;
    do{
      cout<<temp->data<<" ";
      temp=temp->next;
    }while(temp!=head);
    cout<<endl;
  }
}
};

int main(){
   queue<char> stack;

  cout<<"Menu"<<endl;
  cout<<"Press 1 to Queue empty"<<endl;
  cout<<"Press 2 to Enqueue data"<<endl;
  cout<<"Press 3 to Dequeue data"<<endl;
  cout<<"Press 4 to make the Queue empty"<<endl;
  cout<<"Press 5 to display the Queue"<<endl;
  cout<<"Press any other key to exit"<<endl;
    int n;

  do{
    cin>>n;
    switch ((n))
    {
    case 1:
    if(stack.IsEmpty()){
      cout<<"Stack is empty"<<endl;
    }else{
      cout<<"The stack isnot empty"<<endl;
    }
      break;

      case 2:
      stack.Enqueue(stack.getdata());
      break;

      case 3:
      cout<<stack.dequeue()<<" was removed."<<endl;
      break;

      case 4:
      stack.makeempty();
      break;

      case 5:
      stack.display();
      break;

    
    default:
    n=6;
      break;
    }

  }while(n!=6);
return 0;
}

