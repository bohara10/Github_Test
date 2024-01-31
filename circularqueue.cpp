#include<iostream>
using namespace std;
#define max 4
 
 class circqueue{
  protected:
  int data[max];
  int rear;
  int front;

  public:
  circqueue(){
    this->rear=-1;
    this->front=-1;
  }

  void makeempty(){
    rear=-1;
    front=-1;
  }

  int checkempty(){
    if(front==-1)
    return 1;
    else return 0;
  }

  int checkfull(){
    if(((rear+1)%max)==(front%max))
    return 1;
    else return 0;
  }

  void endqueue(int n){
    if(checkfull()){
      cout<<"The queue is full cannot enter "<< n <<" in the queue"<<endl;
    }else if(rear==-1&&front==-1){
      cout<<"the rear and front are set to 0"<<endl;
    rear=front=0;
    data[rear]=n;
    }else{
      ++rear;
      data[rear%max]=n;
      cout<<"The rear is set to "<<rear<<endl;
    }   
    }
    

    void dequeue(){
      if(checkempty()){
        cout<<"no data to dequeue"<<endl;
      }
      else{
        if(front==rear){
          makeempty();
        }else{
        ++front;
        cout<<"The front is now "<<front<<endl;
      }
    }
    }

    void traverse(){
      if(checkempty()){
        cout<<"No data to display."<<endl;
      }else{
      cout<<"The data in the queue is : ";
      for(int i=front;i<rear;++i){
        cout<<data[i%max]<<" ";
      }
      cout<<data[rear]<<endl;
      }
    }
  };

  int main(){
    circqueue q;
    int data;
    int n=0;
  cout<<"Menu"<<endl;
	cout<<"Press 1 to make the queue empty"<<endl;
	cout<<"Press 2 to checkthe queue is empty or not"<<endl;
	cout<<"Press 3 to check the queue is full or not"<<endl;
	cout<<"Press 4 to insert the data into the queue"<<endl;
	cout<<"Press 5 to delete the data from the queue"<<endl;
	cout<<"Press 6 to see the queue "<<endl;
	cout<<"Press any other key to exit"<<endl;
	do{
			cin>>n;
		switch(n){
			case 1:
      q.makeempty();
			
				break;
		case 2:
		if(q.checkempty()){
			cout<<"the given data is empty"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}	
	break;
	
	case 3:
				if(q.checkfull()){
			cout<<"the given data is full"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}	
	break;
	
	case 4:
  cout<<"Enter data : ";
  cin>>data;
		q.endqueue(data);
		break;
		
		case 5:
;
			q.dequeue();
			break;
			
			case 6:
				q.traverse();
				break;
				default:
					n=7;
			
		
}
}while(n!=7);
return 0;
}

 