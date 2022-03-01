#include "unity.h"
#include <calculator_operations.h>

/* Modify these two lines according to the project */
#include <calculator_operations.h>
#define PROJECT_NAME    "Calculator"

static fin_opt c1 = {0, 0, 0};

/* Prototypes for all the test functions */
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);
void test_simple(void);
void test_compound(void);
void test_total(void);
void test_fact(void);
void test_log(void);
void test_exp(void);
void test_power(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_multiply);
  RUN_TEST(test_divide);
  RUN_TEST(test_simple);
  RUN_TEST(test_compound);
  RUN_TEST(test_total);
  RUN_TEST(test_fact);
  RUN_TEST(test_log);
  RUN_TEST(test_exp);
  RUN_TEST(test_power);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
 
void test_add(void) {
  TEST_ASSERT_EQUAL(30, add(10, 20));
  
  TEST_ASSERT_EQUAL(15000, add(7500, 7500));

  TEST_ASSERT_EQUAL(4, add(7,-3));

  TEST_ASSERT_EQUAL(-10, add(-7,-3));

  TEST_ASSERT_EQUAL(-1, add(2147483647,2147483647));  
}

void test_subtract(void) {
  TEST_ASSERT_EQUAL(100, subtract(1000, 900));

  TEST_ASSERT_EQUAL(130, subtract(100, -30));

  TEST_ASSERT_EQUAL(-7, subtract(-10, -3));

  TEST_ASSERT_EQUAL(-3, subtract(0, 3)); 
}

void test_multiply(void) {
  TEST_ASSERT_EQUAL(0, multiply(1, 0));
  
  TEST_ASSERT_EQUAL(10, multiply(2, 5));

  TEST_ASSERT_EQUAL(-10, multiply(-2, 5));

  TEST_ASSERT_EQUAL(10, multiply(-2, -5));

  TEST_ASSERT_EQUAL(-1, multiply(10, 2147483647));

  TEST_ASSERT_EQUAL(-1, multiply(2147483647, 2147483647));
}

void test_divide(void) {
  TEST_ASSERT_EQUAL(10, divide(21, 2));

  TEST_ASSERT_EQUAL(1, divide(2, 2));

  TEST_ASSERT_EQUAL(-1, divide(-2, 2));

  TEST_ASSERT_EQUAL(1, divide(-2, -2));

  TEST_ASSERT_EQUAL(0, divide(1, 0));
}

void test_simple(void){

  c1.principal_amount = 1000;
  c1.rate_of_interest = 2;
  c1.time_of_period = 5;
  TEST_ASSERT_EQUAL(100,simple_interest(&c1));

  c1.principal_amount = 1100;
  c1.rate_of_interest = 2;
  c1.time_of_period = 5.5;
  TEST_ASSERT_EQUAL(121,simple_interest(&c1));

}

void test_compound(void){
  c1.principal_amount = 1000;
  c1.rate_of_interest = 2;
  c1.time_of_period = 2;
  TEST_ASSERT_EQUAL(1040.4,compound_interest(&c1));
  
  c1.principal_amount = 10000;
  c1.rate_of_interest = 10.25;
  c1.time_of_period = 5;
  TEST_ASSERT_EQUAL(16288.9,compound_interest(&c1));
}

void test_total(void){
  TEST_ASSERT_EQUAL(50000,total_amount(35000,15000));

  TEST_ASSERT_EQUAL(325691,total_amount(311440,14251));
}

void test_fact(void){
  TEST_ASSERT_EQUAL(120, fact(5));

  TEST_ASSERT_EQUAL(1, fact(0));

  TEST_ASSERT_EQUAL(1,fact(-5));

  TEST_ASSERT_EQUAL(-1,fact(20));

}

void test_log(void){
  TEST_ASSERT_EQUAL(1,logarithm(10));

  TEST_ASSERT_EQUAL(9.3319,logarithm(2147483647));

  TEST_ASSERT_EQUAL(0.7403,logarithm(5.5));

  TEST_ASSERT_EQUAL(-1,logarithm(-5));
}

void test_exp(void){
  TEST_ASSERT_EQUAL(20.0855,exponential(3));

  TEST_ASSERT_EQUAL(-1,exponential(300000));

  TEST_ASSERT_EQUAL(-1,exponential(-500000));
}

void test_power(void){
  TEST_ASSERT_EQUAL(1,power(3,0));

  TEST_ASSERT_EQUAL(0.0625,power(2,-4));

  TEST_ASSERT_EQUAL(42.44,power(2.3,4.5));
}
