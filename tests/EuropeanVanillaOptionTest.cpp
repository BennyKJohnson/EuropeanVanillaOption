#include "CppUTest/TestHarness.h"
#include "VanillaOption.h"

TEST_GROUP(VanillaOption)
{
};

TEST(VanillaOption, can_create_vanilla_option_with_default_constructor)
{
    VanillaOption* option = new VanillaOption();
    CHECK(option != NULL);
    delete option;
}

TEST(VanillaOption, can_create_vanilla_option_with_constructor)
{
    VanillaOption* option = new VanillaOption(100, 0.05, 1, 100, 0.2);

    CHECK_EQUAL(100, option->getStrikePrice());
    CHECK_EQUAL(0.05, option->getRiskFreeRate());
    CHECK_EQUAL(1, option->getMaturityTime());
    CHECK_EQUAL(100, option->getUnderlyingPrice());
    CHECK_EQUAL(0.2, option->getVolatility());

    delete option;
}

TEST(VanillaOption, calculate_d1)
{
    VanillaOption* option = new VanillaOption(60, 0.05, 1, 60, 0.1);

    DOUBLES_EQUAL(0.55, option->getD1(), 0.01);

    delete option;
}

TEST(VanillaOption, calculate_d2)
{
    VanillaOption *option = new VanillaOption(60, 0.05, 1, 60, 0.1);
    DOUBLES_EQUAL(0.45, option->getD2(), 0.01);
    
    delete option;
}

TEST(VanillaOption, calculate_standard_normal_cdf)
{
    DOUBLES_EQUAL(VanillaOption::getStandardNormalCDF(1.5), 0.933192, 0.0001);
}

TEST(VanillaOption, calculate_call_price)
{
    VanillaOption* option = new VanillaOption(60, 0.05, 1, 60, 0.1);
    DOUBLES_EQUAL(4.08, option->calculateCallPrice(), 0.01);

    delete option;
}

TEST(VanillaOption, calculate_put_price)
{
    VanillaOption* option = new VanillaOption(60, 0.05, 1, 60, 0.1);
    DOUBLES_EQUAL(1.16, option->calculatePutPrice(), 0.01);

    delete option;
}