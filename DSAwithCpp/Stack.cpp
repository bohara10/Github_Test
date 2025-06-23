#include<iostream>
using namespace std;
#define max 3

class stack{
	public:
		int data[10];
		int count;

		
		stack(){
			this->count=-1;
		}
		 
		
		 void makeempty(){
		 	count = -1;
		 }
		 
		 
		 int checkempty(){
		 	if(count<0)
		 		return 1;
			 else return 0;
		 }
		 
		 
		 int checkfull(){
		 	if((count+1)==max) 
        return 1;
				 else return 0;
				 
		 }
		 
		 void push(){
		 	if(checkfull()){
		 		cout<<"The data cannot be entered "<<endl;
			 }
			 else{
			 	cout<<"enter data"<<endl;
		 	++count;
		 	cin>>data[count];
		 }
		 }
		 
		 void pop(){
		 	if(checkempty()){
		 		cout<<"The list is empty so you cannot enter the data"<<endl;
			 }else{
			 	int temp= data[count];
				 --count;
				 cout<<temp<<" was delted from the stack"<<endl;
			 }
		}
		
		
		void seetop(){
			cout<<"The data in the top is : "<<data[count]<<endl;
		}
		
		void stacktraverse(){
			if(checkempty()){
				cout<<"The given data has no data"<<endl;
			}else{
			
			cout<<"The required data is :"<<endl;
			for(int i=0;i<=count;++i){
				cout<<data[i]<<" ";
				
				
			}
			cout<<endl;
		}
	}

};
int main(){
	int n=0;
	stack l;

  cout<<"Menu"<<endl;
	cout<<"Press 1 to make the stack empty"<<endl;
	cout<<"Press 2 to checkthe stack is empty or not"<<endl;
	cout<<"Press 3 to check the stack is full or not"<<endl;
	cout<<"Press 4 to push the stack"<<endl;
	cout<<"Press 5 to pop the stack"<<endl;
	cout<<"Press 6 to see the top element"<<endl;
	cout<<"Press 7 to see the stack"<<endl;
	cout<<"Press any other key to exit"<<endl;

	do{

	cin>>n;
		switch(n){
			case 1:
				l.makeempty();
				break;
		case 2:
		if(l.checkempty()){
			cout<<"the given data is empty"<<endl;
		}
		else{
		cout<<"no"<<endl;
		}	
		break;
	
		case 3:
				if(l.checkfull()){
				cout<<"the given data is full"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}	
		break;
	
	case 4:
		l.push();
		break;
		
		case 5:
			l.pop();
			break;
			
			case 6:
				l.seetop();
				break;
			case 7:
				l.stacktraverse();
				break;
					
				default:
					n=8;
			
		
}
}while(n!=8);
return 0;
}