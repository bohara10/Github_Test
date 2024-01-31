#include<iostream>
#include<cstring>
using namespace std;

class datain{
  public :
  int count,sount,numcount;
  char input[20],scan[20],opcode[20];
  int num[20];
  
  datain(){
    this->count=-1;
    this->sount=-1;
    this->numcount=-1;
  }
  
  int checkalphabet(char z){
    if((z>='a'&&z<='z')||(z>='A'&&z<='Z')) return 1;
    else return 0;
}

  	int add(int a,int b){
		return a+b;
	}
	
	int sub(int a,int b){
		return a-b;
	}
	 
	 int div(int a,int b){
	 	return a/b;
	 }
	 
	 int mul(int a,int b){
	 	return a*b;
	 }
	 
	 int power(int a,int b){
	 	if(b==0){
	 		return 1;
		 }else if(b==1){
		 	return a;
		 }else{
		 	return a*power(a,b-1);
		 }
	 }


 void pop(){
    ++count;
    scan[count]=opcode[sount-1];
    opcode[sount-1]=opcode[sount];
    --sount;
  }

void evaluate(){
if(opcode[sount-1]=='$'||opcode[sount-1]=='^'){

      if(opcode[sount]=='+'||opcode[sount]=='-'||opcode[sount]=='/'||opcode[sount]=='*'||opcode[sount]=='^'||opcode[sount]=='$'){
        pop();
      }
  }
  else if(opcode[sount-1]=='/'||opcode[sount-1]=='*'){
       if(opcode[sount]=='+'||opcode[sount]=='-'||opcode[sount]=='/'||opcode[sount]=='*'){
        pop();
  }
  }
  else if(opcode[sount-1]=='+'||opcode[sount-1]=='-'){
    if(opcode[sount]=='-'||opcode[sount]=='+'){
      pop();
    }
  }
}

  void push(){
    ++count;
    scan[count]=opcode[sount];
    --sount;
  }

  void getinput(){
    cout<<"Enter the given operation below : ";
    cin>>input;
  }

  void getdifferentdata(){
    for(int i=0;i<strlen(input);++i){
      if(checkalphabet(input[i])){
        ++count;
        scan[count]=input[i];
      }
      else{
        ++sount;
        opcode[sount]=input[i];
        if(sount>0){
          evaluate();
        }
        if(opcode[sount]==')'){
          sount--;
          while(opcode[sount]!='('){
            push();
          }
          --sount;
        }
      }
    }
   while(sount!=-1){
      push();
      }
  }

  void seescaned(){
    cout<<"The postfix notation is : ";
    for(int i=0;i<=count;++i){
      cout<<scan[i];
    }
    cout<<endl;
  }
  
  void exvaluate(){
  	for(int i=0;i<strlen(scan);++i){
    if(checkalphabet(scan[i])){
		cout<<"Enter the value of "<<scan[i]<<" : ";
		++numcount;
		cin>>num[numcount];
      }else{
    if(scan[i]=='+'){
			num[numcount-1]=add(num[numcount],num[numcount-1]);
	  }else if(scan[i]=='-'){
			num[numcount-1]=sub(num[numcount-1],num[numcount]);
	  }else if(scan[i]=='*'){
			num[numcount-1]=mul(num[numcount],num[numcount-1]);
      }else if(scan[i]=='/'){
			num[numcount-1]=div(num[numcount-1],num[numcount]);
		}else if(scan[i]=='&'){
			num[numcount-1]=power(num[numcount-1],num[numcount]);
		}
		--numcount;
	}
}
cout<<"The result of the evaluation is :"<<num[0]<<endl;
}
};

int main(){
  datain d1;
  d1.getinput();
  d1.getdifferentdata();
  d1.seescaned();
  d1.exvaluate();
  return 0;
}