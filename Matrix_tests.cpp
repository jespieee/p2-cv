// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// Fills a 1x1 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_matrix_at) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    *Matrix_at(mat, 0, 0) = 3;
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 3);
    delete mat; // delete the Matrix
}

TEST(test_matrix_dimensions) {
    Matrix* mat = new Matrix;
    int width1 = 3;
    int height1 = 3;
    Matrix_init(mat, width1, height1);
    int width2 = Matrix_width(mat);
    int height2 = Matrix_height(mat);

    ASSERT_EQUAL(width1, width2);
    ASSERT_EQUAL(height1, height2);
    
    delete mat;
}


// Fills a 2x2 Matrix with a value and checks
// that Matrix_row and Matrix_col are returning the correct values.
TEST(test_matrix_at_row_col) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 0);
    int* ptr = Matrix_at(mat, 1, 1);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 1);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 1);

    delete mat;
}

TEST(test_matrix_fill_border) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 4);
    Matrix_fill_border(mat, 0);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 0), 0);
    int* ptr = Matrix_at(mat, 2, 2);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
    delete mat; // delete the Matrix
}

TEST(test_matrix_print2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 2);
    ostringstream expected;
    expected << "2 2\n"
        << "2 2 \n"
        << "2 2 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}


TEST(test_matrix_print_complex) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 2);
    Matrix_fill_border(mat, 1);
    ostringstream expected;
    expected << "3 3\n"
        << "1 1 1 \n"
        << "1 2 1 \n"
        << "1 1 1 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(test_matrix_col_min_value) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 2);
    *Matrix_at(mat, 2, 0) = 1;
    *Matrix_at(mat, 2, 1) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 0, 2), 0);
    delete mat;
}

TEST(test_matrix_init){
    Matrix *mat = new Matrix;
    Matrix *mat2 = new Matrix;
    Matrix_init(mat, 3, 5);
    Matrix_init(mat2, 3, 5);
    Matrix_fill(mat, 2);
    Matrix_fill(mat2, 2);
    ASSERT_TRUE(Matrix_equal(mat, mat2));
    delete mat;
    delete mat2;
}

TEST(test_matrix_max){
    Matrix *mat = new Matrix;
    int min = 0;
    int max = 15;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, max);
    Matrix_fill_border(mat, min);
    int value = Matrix_max(mat);
    ASSERT_TRUE(value == max);
    delete mat;
}

TEST(test_matrix_max_2) {
    Matrix* mat = new Matrix;
    int max = 15;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, max);
    int value = Matrix_max(mat);
    ASSERT_TRUE(value == max);
    delete mat;
}

TEST(test_matrix_min_value_in_row){
    Matrix *mat = new Matrix;
    int min = 0;
    int num = 32;
    int numTwo = 12;
    Matrix_init(mat, 4, 4);
    Matrix_fill(mat, numTwo);
    *Matrix_at(mat, 0, 2) = min;
    *Matrix_at(mat, 0, 1) = num;
    *Matrix_at(mat, 0, 3) = 4;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 3), 0);
    delete mat;
}

TEST(test_matrix_fill_more){
    Matrix *mat = new Matrix;
    Matrix *mat2 = new Matrix;
    int min = 0;
    int num = 32;
    int numTwo = 12;
    Matrix_init(mat, 4, 4);
    Matrix_init(mat2, 4, 4);
    Matrix_fill(mat, num);
    Matrix_fill(mat2, numTwo);
    *Matrix_at(mat, 3, 3) = min;
    ASSERT_NOT_EQUAL(mat, mat2);
    delete mat;
    delete mat2;
}

TEST(test_basic_matrix_init) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 3);
    ASSERT_EQUAL(Matrix_width(mat), 2);
    ASSERT_EQUAL(Matrix_height(mat), 3);
    delete mat;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
