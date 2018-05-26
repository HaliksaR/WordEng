#define CTEST_MAIN
#include "../src/check_global.h"
#include "../src/correct_start.h"
#include <ctest.h>

CTEST(level, correct_level) {
    int expected = 0;
    level = 2;
    int result = correct_level();
    ASSERT_EQUAL(expected,result);
}

CTEST(level, incorrect_level) {
    int expected = -1;
    level = 6;
    int result = correct_level();
    ASSERT_EQUAL(expected,result);
}

CTEST(words, correct_words) {
    int expected = 0;
    words = 2;
    int result = correct_words();
    ASSERT_EQUAL(expected,result);
}

CTEST(words, incorrect_words) {
    int expected = -1;
    words = 6;
    int result = correct_words();
    ASSERT_EQUAL(expected,result);
}

CTEST(fail, correct_fail) {
    int expected = 0;
    fail = 657;
    int result = correct_fail();
    ASSERT_EQUAL(expected,result);
}

CTEST(fail, incorrect_fail) {
    int expected = -1;
    fail = -434;
    int result = correct_fail();
    ASSERT_EQUAL(expected,result);
}

CTEST(name, correct_name) {
    int expected = 0;
    name = L"Alexey";
    int result = correct_name();
    ASSERT_EQUAL(expected,result);
}

CTEST(name, incorrect_name) {
    int expected = -1;
    name = L"\0";
    int result = correct_name();
    ASSERT_EQUAL(expected,result);
}

CTEST(max_index, correct_max_index) {
    int expected = 0;
    max_index = 134;
    int result = correct_max_index();
    ASSERT_EQUAL(expected,result);
}

CTEST(max_index, incorrect_max_index) {
    int expected = -1;
    max_index = 0;
    int result = correct_max_index();
    ASSERT_EQUAL(expected,result);
}

CTEST(index, correct_index) {
    int expected = 0;
    max_index = 1000;
    index = 134;
    int result = correct_index_global();
    ASSERT_EQUAL(expected,result);
}

CTEST(index, incorrect_index) {
    int expected = -1;
    index = 134;
    max_index = 10;
    int result = correct_index_global();
    ASSERT_EQUAL(expected,result);
}

CTEST(russian_num, correct_russian_num) {
    int expected = 0;
    russian_num = 9;
    int result = correct_russian_num();
    ASSERT_EQUAL(expected,result);
}

CTEST(russian_num, incorrect_russian_num) {
    int expected = -1;
    russian_num = -35;
    int result = correct_russian_num();
    ASSERT_EQUAL(expected,result);
}

CTEST(english, correct_english) {
    int expected = 0;
    english = L"Fantasy";
    int result = correct_english();
    ASSERT_EQUAL(expected,result);
}

CTEST(english, incorrect_english) {
    int expected = -1;
    english = L"\0";
    int result = correct_english();
    ASSERT_EQUAL(expected,result);
}

CTEST(russian, correct_russian) {
    int expected = 0;
    russian = L"Фантазия";
    int result = correct_russian();
    ASSERT_EQUAL(expected,result);
}

CTEST(russian, incorrect_russian) {
    int expected = -1;
    russian = L"\0";
    int result = correct_russian();
    ASSERT_EQUAL(expected,result);
}

CTEST(start, correct_start) {
    int expected = 0;
    max_index = 60;
    max_learn = 60;
    int result = start_program();
    ASSERT_EQUAL(expected,result);
}

CTEST(start, incorrect_start) {
    int expected = -1;
    max_index = 60;
    max_learn = 78;
    int result = start_program();
    ASSERT_EQUAL(expected,result);
}
int main(int argc, const char** argv) {
    int test_res = ctest_main(argc, argv);
    return test_res;
}