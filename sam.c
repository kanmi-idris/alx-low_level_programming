#include <stdio.h>
// #include <iot.h>


int main () 
{
  int numval;
  int * value;
  int loopcounter;
  int result = 0;
  printf("How many values\n");
  scanf("%d",&numval);
  for (loopcounter = 0; loopcounter < numval; loopcounter++)
  {
  result
    = result + value[loopcounter];
  }
  printf("Result=%d\n", result);
  return (result);
}