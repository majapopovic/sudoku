#include "../../unity/unity_fixture.h"
#include "../src/logic.h"



int* sudoku;
ENTRY* entry;

TEST_GROUP(logicTest);

TEST_GROUP_RUNNER(logicTest)
{
	RUN_TEST_CASE (logicTest, TestgenerateSudoku);
	RUN_TEST_CASE (logicTest, TestcheckFree);
	RUN_TEST_CASE (logicTest, TestcheckNOTFree);
	RUN_TEST_CASE (logicTest, TestcheckColumnFree);
	RUN_TEST_CASE (logicTest, TestcheckColumnNOTFree);	
	RUN_TEST_CASE (logicTest, TestcheckRowFree);
	RUN_TEST_CASE (logicTest, TestcheckRowNOTFree);
	RUN_TEST_CASE (logicTest, TestcheckBoxFree);
	RUN_TEST_CASE (logicTest, TestcheckBoxNOTFree);
	RUN_TEST_CASE (logicTest, TestupdateSudoku);				
}

TEST_SETUP(logicTest)
{
sudoku=generateSudoku();
//entry=createEntry1();
}

TEST_TEAR_DOWN(logicTest)
{
}


TEST(logicTest, TestgenerateSudoku)
{
TEST_ASSERT_EQUAL (8,*(sudoku+13));
}


TEST(logicTest, TestcheckFree)
{
entry=createEntry2(8,2,7);
TEST_ASSERT_TRUE (isEmpty(sudoku, entry));
}

TEST(logicTest, TestcheckNOTFree)
{
entry=createEntry2(7,3,7);
TEST_ASSERT_FALSE (isEmpty(sudoku, entry));
}


TEST(logicTest, TestcheckColumnFree)
{
entry=createEntry2(1,5,7);
TEST_ASSERT_TRUE (isColumnfree(sudoku, entry));
}


TEST(logicTest, TestcheckColumnNOTFree)
{
entry=createEntry2(1,5,8);
TEST_ASSERT_FALSE (isColumnfree(sudoku, entry));
}


TEST(logicTest, TestcheckRowFree)
{
entry=createEntry2(2,2,3);
TEST_ASSERT_TRUE (isRowfree(sudoku, entry));
}


TEST(logicTest, TestcheckRowNOTFree)
{
entry=createEntry2(2,2,4);
TEST_ASSERT_FALSE (isRowfree(sudoku, entry));
}

TEST(logicTest, TestcheckBoxFree)
{
entry=createEntry2(2,2,4);
TEST_ASSERT_TRUE (isBoxfree(sudoku, entry));
}

TEST(logicTest, TestcheckBoxNOTFree)
{
entry=createEntry2(2,2,5);
TEST_ASSERT_FALSE (isBoxfree(sudoku, entry));
}

TEST(logicTest, TestupdateSudoku)
{
entry=createEntry2(2,2,6);
updateSudoku(sudoku, entry);
TEST_ASSERT_EQUAL (6,*(sudoku+convertIndex(entry)));
}



