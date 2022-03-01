#include"Billing_System.h"
#include"unity_internals.h"
#include"unity.h"

#include <Billing_System.h>
#define PROJECT_NAME    "RetailBillingSystemr"



void create()
void bill()
void display()
void edit()
void invoice()
void mdelete()
void mdisplay()

void setUp(){}

void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(create);
  RUN_TEST(bill);
  RUN_TEST(display);
  RUN_TEST(edit);
  RUN_TEST(invoice);
  RUN_TEST(mdelete);
  RUN_TEST(mdisplay);


  /* Close the Unity Test Framework */
  return UNITY_END();
}
 
void test_create()(void) {
  TEST_ASSERT_EQUAL(pass,enter_product_code);
  
  TEST_ASSERT_EQUAL(pass,enter_product_name);
  
  TEST_ASSERT_EQUAL(pass,enter_quantity);
  
  TEST_ASSERT_EQUAL(pass,enter_price);
}

void test_bill()(void) {
  TEST_ASSERT_EQUAL(pass,enter_product_number);
  
  TEST_ASSERT_EQUAL(pass,enter_the_quantity);
  
  TEST_ASSERT_EQUAL(fail,enter_quantity(out of stock));
  
}

void test_display()(void) {
  TEST_ASSERT_EQUAL(pass,product_number|product_name|quantity|price);
  
  TEST_ASSERT_EQUAL(fail(no items in cart));
  
}



void test_edit()(void) {
  TEST_ASSERT_EQUAL(pass,enter_the_product_number_to_delete);
  
  TEST_ASSERT_EQUAL(pass(producthas been successfully deleted));
  
  TEST_ASSERT_EQUAL(fail(product not found));
}


void test_invoice()(void) {
  TEST_ASSERT_EQUAL(pass,product_number|product_name|quantity|amount);
  
  TEST_ASSERT_EQUAL(235,invoice(100,135);
  
  TEST_ASSERT_EQUAL(pass,thank_you_for_shopping);
                    
  TEST_ASSERT_EQUAL(pass,visit_again);
}

                    
void test_mdelete()(void) {
  TEST_ASSERT_EQUAL(pass,enter_the_product_number_to_be_deleted);
  
  TEST_ASSERT_EQUAL(pass(producthas deleted successfully));
}
                    
void test_mdisplay()(void) {
    TEST_ASSERT_EQUAL(pass,product_number|product_name|quantity|price);
}               


int main(){
    UNITY_BEGIN();

    RUN_TEST(test_create);
    RUN_TEST(test_bill);
    RUN_TEST(test_display);
    RUN_TEST(test_edit);
    RUN_TEST(test_invoice);
    RUN_TEST(test_mdelete);
    RUN_TEST(test_mdisplay);
    return UNITY_END();
}
