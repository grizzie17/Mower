#include "TArray2.hpp"

#include "gtest/gtest.h"

using namespace Yogi::Utilities;


TEST( TArray2, allocate )
{
    TArray2<double> test( 4, 4 );

    ASSERT_DOUBLE_EQ( 0, test.getValue( 0, 0 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 0, 1 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 0, 2 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 0, 3 ) );

    ASSERT_DOUBLE_EQ( 0, test.getValue( 1, 0 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 1, 1 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 1, 2 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 1, 3 ) );

    ASSERT_DOUBLE_EQ( 0, test.getValue( 2, 0 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 2, 1 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 2, 2 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 2, 3 ) );

    ASSERT_DOUBLE_EQ( 0, test.getValue( 3, 0 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 3, 1 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 3, 2 ) );
    ASSERT_DOUBLE_EQ( 0, test.getValue( 3, 3 ) );
}

TEST( TArray2, assignByRef )
{
    TArray2<int> test( 2, 2 );

    test.getRef( 0, 0 ) = 11;


    ASSERT_EQ( 11, test.getValue( 0, 0 ) );
}

TEST( TArray2, assignByBrackets )
{
    TArray2<char> test( 2, 2 );

    test[0][0] = 'a';
    test[0][1] = 'b';
    test[1][0] = 'c';
    test[1][1] = 'd';

    ASSERT_EQ( 'a', test.getValue( 0, 0 ) );
    ASSERT_EQ( 'c', test.getValue( 1, 0 ) );
}
