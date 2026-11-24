// Implement non-recursive function to compute factorial.
#include<iostream>
using namespace std;
int main(){
	int num;
	unsigned long long factorial=1;

	cout<<"Enter a positive integer: "<<endl;
	cin>>num;
	
	if(num<0){
		cout<<"Error: Factorial of a number doesn't exist."<<endl;
	}
	else{
		for(int i=1;i<=num;i++){
		factorial*=i;
	}
		cout<<"The factorial of the given number: "<<factorial<<endl;
	}
return 0;
}
