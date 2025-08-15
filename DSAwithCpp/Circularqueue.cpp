#include<iostream>
using namespace std;
#define max 10

class Queue{
  private:

  int data[max];
  int rear;
  int front;


  public:
  Queue(){
    this->rear=-1;
    this->front=-1;
  }
  protected:
  void makeEmpty(){
    rear=-1;
    front=-1;
  }

  bool checkEmpty(){
    return rear==-1&&front==-1;
  }

  bool IsFull(){
    return (rear%max)==((front-1)%max);
  }

  void Enqueue(int val){
    if(!IsFull()){
      if(checkEmpty()){
        ++front;
      }
      ++rear;
      data[rear%max]=val;
    }
  }

  int Dequeue(){
    int val=0;
     if(!checkEmpty()){
      val=data[front%max];
    if(front%max==(rear-1)%max){
      makeEmpty();
    }
    else{
      ++front;
    }
  }
  return val;
  }


  void traverse(){
    if(!checkEmpty()){
      cout<<"The data in the Queue are : ";
      for(int i=front;i<=rear;++i){
        cout<<data[i%max]<<" ";
      }
      cout<<endl;
    }
  }
  public:
  void menu(){
    int n=0;

      cout<<"Menu"<<endl;
        cout<<"Press 1 to Make the Array list empty"<<endl;
        cout<<"Press 2 to check the array list is empty"<<endl;
        cout<<"Press 3 to check the array list if full "<<endl;
        cout<<"Press 4 to insert data in the Array list"<<endl;
        cout<<"Press 8 to sort the data"<<endl;
        cout<<"Press 5 to delete a certain data"<<endl;
        cout<<"Press 6 to see the data "<<endl;
        cout<<"Press 7 to exit the menu"<<endl;

        do{
          cout<<"Enter operation : ";
        cin>>n;
        switch (n)
        {
        case 1:
          makeEmpty();
          break;


          case 2:
          if(checkEmpty()){
            cout<<"The List is empty"<<endl;
          }else{
            cout<<"The List is not empty"<<endl;
          }


          break;

          case 3:
          if(IsFull()){
            cout<<"The list is full"<<endl;
          }else{
            cout<<"The list is not full"<<endl;
          }
          break;


          case 4:
        int k;
      cout<<"Enter data : ";
      cin>>k;
      Enqueue(k);
      break;

      case 5:

      cout<<Dequeue()<<" was deleted"<<endl;
      break;
    

      case 6:
        traverse();
      break;


        
        default:
        n=7;
          break;
        }
      }while(n!=7);

    }
  };

  int main(){
    Queue arraylist;
    arraylist.menu();
    return 0;
  }



