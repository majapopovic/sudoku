#include "../../unity/unity_fixture.h"
#include "../src/logic.h"
#include "../../input/src/input.h"


int* sudoku;
ENTRY* entry;

TEST_GROUP(logicTest);

TEST_GROUP_RUNNER(logicTest)
{
	RUN_TEST_CASE (logicTest, TestgenerateSudoku);
	RUN_TEST_CASE (logicTest, TestcheckFree);	
				
}

TEST_SETUP(logicTest)
{
sudoku=generateSudoku();
//entry=createEntry();
}

TEST_TEAR_DOWN(logicTest)
{
}


TEST(logicTest, TestgenerateSudoku)
{
TEST_ASSERT_EQUAL (0,*(sudoku+13));
}


TEST(logicTest, TestcheckFree)
{
TEST_ASSERT_TRUE (isEmpty(sudoku, entry));
}




