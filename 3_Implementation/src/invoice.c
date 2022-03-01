#include <Billing_System.h>

void invoice()
{
	int j;
	int o;
	float gt=0;
	if(ti==0)
	{
		printf("There are No Products in your Cart\n");
	}
	printf("\n\n                            INVOICE\n\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=((cst[o].price)*(cst[o].quantity));
		gt=gt+cst[o].amount;
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].productnumber,cst[j].productname,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount Payable:%f\n",gt);
	printf("Thank you for Shopping\n");
	printf("Visit Again\n");
}
