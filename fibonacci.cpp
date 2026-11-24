// Implement non-recursive function to compute fibonacci.
#include<iostream>
using namespace std;
int main() {

int i, n, first=0,second=1,next;
cout<<"Enter a number: "<<endl;
cin>>n;
for(i=0;i<n;i++){
if(i<=1){
next=i;
}
else{
next=first+second;
first=second;
second=next;
}
cout<<next<<" ";
}
cout<<endl;
return 0;
}
