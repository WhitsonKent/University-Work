#include <stdio.h>
#include <math.h>

int main()
{
  int a,b,c;
  printf("Enter 3 integers that form an equation\n");
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);

  if(a+b==c)
  {
    printf("%d+%d=%d\n",a,b,c);
  }
  if(a-b==c)
  {
    printf("%d-%d=%d\n",a,b,c);
  }
  if(a*b==c)
  {
    printf("%dx%d=%d\n",a,b,c);
  }
  if(a/b==c)
  {
    printf("%d/%d=%d\n",a,b,c);
  }
  if(a==b+c)
  {
    printf("%d=%d+%d\n",a,b,c);
  }
  if(a==b-c)
  {
    printf("%d=%d-%d\n",a,b,c);
  }
  if(a==b*c)
  {
    printf("%d=%dx%d\n",a,b,c);
  }
  if(a==b/c)
  {
    printf("%d=%d/%d\n",a,b,c);
  }
}
