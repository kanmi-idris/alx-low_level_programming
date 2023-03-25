#include<stdio.h>
int main(){

  char fname[20],lname[20];

  printf("Enter your First name :");
  scanf("%s", fname);

  printf("Enter your Last name :");
  scanf("%s", lname);

  printf("Your Full Name is %s %s", fname, lname);

  return 0;
}