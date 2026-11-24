// Assignment 3- print highest score and sum of score of team members.
#include<iostream>
using namespace std;
int main()
{
int list1[5]={23,69,67,88,99};
int list2[5]={49,74,98,101,169};
int team[10];
int sum=0;
int highest,index;
int lowest= team[0];
int lowestindex=0;

for (int i=0; i<5; i++)

{
team[i] = list1[i];
team[i+5] = list2[i];
}
highest= team[0];
index=0;

for(int i=0; i<10; i++)

{
sum=sum+team[i];

if (team[i] > highest)

{
highest= team[i];
index= i;
}
if (team[i] < lowest)

{
lowest= team[i];
lowestindex= i;
}
}


cout<<"sum="<<sum<<endl;
cout<<"highest score="<<highest<<endl;
cout<<"highest player index="<<index<<endl;
return 0;
}
