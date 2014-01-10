#include "UnitTest++.h"
#include "spark_descriptor.h"

struct FunctionFixture {
  static void execute_a_function(const char *func_key, const char *arg);
  static int get_retval(void);
  static int get_number_of_funcs(void);
  static void copy_a_function_key(char *destination, int function_index);
  static int a_return_value;
};

int FunctionFixture::a_return_value = 2;

void FunctionFixture::execute_a_function(const char *, const char *)
{
  a_return_value = 99;
}

int FunctionFixture::get_retval(void)
{
  return a_return_value;
}

int FunctionFixture::get_number_of_funcs(void)
{
  return 3;
}

void FunctionFixture::copy_a_function_key(char *destination, int function_index)
{
  const char *function_keys[] = {
    "brew\0\0\0\0\0\0\0\0", "clean\0\0\0\0\0\0\0", "bean_alert\0\0" };
  memcpy(destination, function_keys[function_index], 12);
}

SUITE(Descriptor)
{
  TEST_FIXTURE(FunctionFixture, DescriptorKnowsNumberOfRegisteredFunctions)
  {
    SparkDescriptor descriptor;
    descriptor.num_functions = get_number_of_funcs;
    CHECK_EQUAL(3, descriptor.num_functions());
  }

  TEST_FIXTURE(FunctionFixture, DescriptorCanAccessArrayOfFunctionKeys)
  {
    SparkDescriptor descriptor;
    descriptor.copy_function_key = copy_a_function_key;
    char buf[12];
    descriptor.copy_function_key(buf, 2);
    CHECK_EQUAL("bean_alert\0\0", buf);
  }

  TEST_FIXTURE(FunctionFixture, DescriptorCanCallRegisteredFunction)
  {
    SparkDescriptor descriptor;
    descriptor.request_execution = execute_a_function;
    descriptor.get_function_return_value = get_retval;
    const char *function_key = "brew";
    const char *arg = "32,240";
    descriptor.request_execution(function_key, arg);
    int return_value = descriptor.get_function_return_value();
    CHECK_EQUAL(99, return_value);
  }
}
