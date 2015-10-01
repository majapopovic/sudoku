#include "../../unity/unity_fixture.h"
#include "../src/input.h"


int* sudoku;
ENTRY* entry;

TEST_GROUP(inputTest);

TEST_GROUP_RUNNER(inputTest)
{
	RUN_TEST_CASE (inputTest, TestassignXCoordinate);	
	RUN_TEST_CASE (inputTest, TestassignYCoordinate);
	RUN_TEST_CASE (inputTest, TestassignValue);
	RUN_TEST_CASE (inputTest, TestconvertIndex);
	RUN_TEST_CASE (inputTest, TestindexValid);
	RUN_TEST_CASE (inputTest, TestvalueValid);
	RUN_TEST_CASE (inputTest, TestentryValid);			
}

TEST_SETUP(inputTest)
{
sudoku=createSudoku();
entry=createEntry();
}

TEST_TEAR_DOWN(inputTest)
{
//free(sudoku);
//free(entry);
}

TEST(inputTest, TestassignXCoordinate)
{
//assignXCoordinate(entry);
//entry=createEntry();
TEST_ASSERT_EQUAL (75,entry->x);
}

TEST(inputTest, TestassignYCoordinate)
{
//assignYCoordinate(entry);
TEST_ASSERT_EQUAL (92,entry->y);
}

TEST(inputTest, TestassignValue)
{
//assignValue(entry);
TEST_ASSERT_EQUAL (-8,entry->value);
}

TEST(inputTest, TestconvertIndex)
{
//assignValue(entry);
TEST_ASSERT_EQUAL (47,convertIndex(entry));
}


TEST(inputTest, TestindexValid)
{
//assignXCoordinate(entry);
//assignYCoordinate(entry);
//assignValue(entry);
TEST_ASSERT_TRUE (isIndexValid(entry));
}

TEST(inputTest, TestvalueValid)
{
//assignXCoordinate(entry);
//assignYCoordinate(entry);
//assignValue(entry);
TEST_ASSERT_TRUE (isValueValid(entry));
}

TEST(inputTest, TestentryValid)
{
//assignXCoordinate(entry);
//assignYCoordinate(entry);
//assignValue(entry);
TEST_ASSERT_TRUE (isEntryValid(entry));
}

/*TEST(inputTest, TestupdateSudoku)
{
updateSudoku(sudoku, entry);
TEST_ASSERT_EQUAL (4,entry->value);
}*/

