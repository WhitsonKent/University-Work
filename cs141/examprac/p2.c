#include <stdio.h>

int main() {

  int cart;//number or items in cart
  printf("How many Items are being purchased?\n");
  scanf("%d",&cart);
  int prices[cart];//items to be scanned
  int temp;
  int discount=0;

  //scans item prices
  for (int i = 0;i<cart;i++)
  {
    printf("item %d: ",i+1 );
    scanf("%d",&prices[i]);
  }
  //sorts prices from greatest to least
  for (int i = 0;i<cart;i++)
  {
    for (int j = 0; j < cart-i-1; j++)
    {
      if(prices[j]<prices[j+1])
      {
        temp = prices[j];
        prices[j]=prices[j+1];
        prices[j+1]=temp;
      }
    }
  }

  //prints items entered
  for (int i = 0;i<cart;i++)
  {
    printf("%d ",prices[i]);
  }

  for (int i = 2;i<cart;i+=3)
  {
    discount+=prices[i];
  }

  printf("\nMax Discount:%d", discount);
  return 0;
}
