#include "billing.h"
int main()
{
	char ch,password[10],q[10]="progto";
	int s=0,y=0,w=1,i;
	FILE *fpe;
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\n");
	printf("************************************************************************************************************************\n");
	printf("*****************************************    WELCOME TO RETAIL STORE     ***********************************************\n");
	printf("\t                            GET A WELCOME BONUS ON YOUR FIRST PURCHASE \n\n");
	printf("\t\t\t       Kindly note that the Goods once sold are not returnable\n\t\t\t\t\t");
    printf("      Reference Number: %d\n",n);
    q: printf("\n\t");
    printf("****************************\n\t");
    printf("Select an Option: \n\t");
    printf("****************************\n\t");
	printf("1. ADMINISTRATOR\n\t");
	printf("2. CUSTOMER\n\t");
	printf("3. EXIT\n\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s)
	{
	          case 1:
               printf("\t____________________________\n");
			   printf("\n\tPlease Select an Option: \n\t");
               printf("____________________________\n");
		       printf("\n\t1.CREATE\n\t");
		       printf("2.DELETE/MODIFY\n\t");
		       printf("3.DISPLAY\n\t");
		       printf("4.MAIN MENU\n\n\t");
		       printf("Please Enter an Option: ");
		        scanf("%d",&y);
		        switch(y)
		        {
        		case 1:create();
        			      goto q;
  			    case 2:edit();
  			             goto q;
                case 3:display();
                         goto q;
                case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;
       case 2: printf("\n");
               printf("\t");
               printf("____________________________\n\n\t");
               printf("Select an Option: \n\t");
               printf("____________________________\n\n\t");
               printf("1.BILL\n\t");
               printf("2.INVOICE\n\t");
               printf("3.DISPLAY\n\t");
               printf("4.MYCART\n\t");
               printf("5.MAIN MENU\n\t");
               printf("6.DELETE ITEMS IN CART\n\n\t");
               printf("Please Enter an Option: ");
               scanf("%d",&y);
               printf("\n");
               switch(y)
		        {
                    case 1 : bill();
        			         goto q;
                    case 2 : invoice();
                             goto q;
                    case 3 : display();
                             goto q;
                    case 4 : mdisplay();
                             goto q;
                    case 5 : goto q;
                    case 6 : mdelete();
                             goto q;
                    default : printf("Error\n");
                              goto q;
        		}
		         break;
      case 3: printf("\tExiting...\n");
      break;
      default : printf("error\n");
      break;
	}
}
