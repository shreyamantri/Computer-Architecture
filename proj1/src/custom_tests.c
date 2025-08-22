#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in game.c
#include "game.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) { return x > 42; }

bool is_vowel(char c) {
  char *vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  // TODO: Implement this function.
  char testcase_1 = 'a';
    bool output_1 = is_tail(testcase_1);
    if (!assert_true("output_1", output_1)) {
        return false;
    }
    char testcase_2 = 's';
    bool output_2 = is_tail(testcase_2);
    if (!assert_true("output 2", output_2)) {
        return false;
    }
    char testcase_3 = 'w';
    bool output_3 = is_tail(testcase_3);
    if (!assert_true("output_3", output_3)) {
        return false;
    }

    char testcase_4 = 'd';
    bool output_4 = is_tail(testcase_4);
    if (!assert_true("output_4", output_4)) {
        return false;
    }
    char testcase_6 = 'm';
    bool output_6 = is_tail(testcase_6);
    if (!assert_false("output_6", output_6)) {
        return false;
    }
  return true;
}

bool test_is_head() {
  // TODO: Implement this function.
  char testcase_1 = 'W';
  bool output_1 = is_head(testcase_1);
  if (!assert_true("output_1", output_1)) {
          return false;
  }
  char testcase_2 = 'A';
  bool output_2 = is_head(testcase_2);
  if (!assert_true("output_2", output_2)) {
      return false;
  }
  char testcase_3 = 'S';
  bool output_3 = is_head(testcase_3);
  if (!assert_true("output_3", output_3)) {
          return false;
  }
  char testcase_4 = 'D';
  bool output_4 = is_head(testcase_4);
  if (!assert_true("output_4", output_4)) {
      return false;
  }
  char testcase_5 = 'x';
  bool output_5 = is_head(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }
  char testcase_7 = 'm';
  bool output_7 = is_head(testcase_7);
  if (!assert_false("output_7", output_7)) {
      return false;
  }
  return true;
}

bool test_is_snake() {
  // TODO: Implement this function.
  // following the same structure from above, for the rest of the tasks
  char testcase_1 = 'a';
  bool output_1 = is_snake(testcase_1);
  if (!assert_true("output_1", output_1)) {
        return false;
  }
  char testcase_2 = 'w';
  bool output_2 = is_snake(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }
  char testcase_3 = 's';
  bool output_3 = is_snake(testcase_3);
  if (!assert_true("output_3", output_3)) {
      return false;
  }
  char testcase_4 = 'd';
  bool output_4 = is_snake(testcase_4);
  if (!assert_true("output_4", output_4)) {
      return false;
  }
  char testcase_5 = 'v';
  bool output_5 = is_snake(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }
  char testcase_6 = '^';
  bool output_6 = is_snake(testcase_6);
  if (!assert_true("output_6", output_6)) {
      return false;
  }
  char testcase_7 = '<';
  bool output_7 = is_snake(testcase_7);
  if (!assert_true("output_7", output_7)) {
      return false;
  }
  char testcase_8 = '>';
  bool output_8 = is_snake(testcase_8);
  if (!assert_true("output_8", output_8)) {
      return false;
  }
  char testcase_9 = 'W';
  bool output_9 = is_snake(testcase_9);
  if (!assert_true("output_9", output_9)) {
      return false;
  }
  char testcase_10 = 'A';
  bool output_10 = is_snake(testcase_10);
  if (!assert_true("output_10", output_10)) {
      return false;
  }
  char testcase_11 = 'S';
  bool output_11 = is_snake(testcase_11);
  if (!assert_true("output_11", output_11)) {
      return false;
  }
  char testcase_12 = 'D';
  bool output_12 = is_snake(testcase_12);
  if (!assert_true("output_12", output_12)) {
      return false;
  }
  char testcase_13 = 'x';
  bool output_13 = is_snake(testcase_13);
  if (!assert_true("output_13", output_13)) {
      return false;
  }
  char testcase_15 = 'l';
  bool output_15 = is_snake(testcase_15);
  if (!assert_false("output_15", output_15)) {
      return false; //sufficient cases done
  }
  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.
  // checking if !output == expected
  char testcase_1 = '^';
  char output_1 = body_to_tail(testcase_1);
  if (!(output_1 == 'w')) {
      return false;
  }
  char testcase_2 = '<';
  char output_2 = body_to_tail(testcase_2);
  if (!(output_2 == 'a')) {
        return false;
  }
  char testcase_3 = 'v';
  char output_3 = body_to_tail(testcase_3);
  if (!(output_3 == 's')) {
      return false;
  }
  char testcase_4 = '>';
  char output_4 = body_to_tail(testcase_4);
  if (!(output_4 == 'd')) {
      return false;
  }
  //char testcase_5 = 'e';
  //char output_5 = body_to_tail(testcase_5);
 // if (output_5 == 'w' || output_5 == 's' || output_5 == 'd' || output_5 == 'a') {
  //    return false;
 // }
  return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  char testcase_1 = 'A';
  char output_1 = head_to_body(testcase_1);
  if (!(output_1 == '<')) {
      return false;
    }
  char testcase_2 = 'W';
  char output_2 = head_to_body(testcase_2);
  if (!(output_2 == '^')) {
      return false;
  }
  char testcase_3 = 'S';
  char output_3 = head_to_body(testcase_3);
  if (!(output_3 == 'v')) {
      return false;
  }
  char testcase_4 = 'D';
  char output_4 = head_to_body(testcase_4);
  if (!(output_4 == '>')) {
      return false;
  }
  //char testcase_5 = 'M';
  //char output_5 = head_to_body(testcase_5);
  //if (output_5 == '^' || output_5 == 'v' || output_5 == '<' || output_5 == '>') {
    //  return false;
  //}
  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  // getting the next row
  // Returns cur_row + 1 if c is v or s or S. Returns cur_row - 1 if c is ^ or w or W. Returns cur_row otherwise -- from spec
  char testcase_1 = 'v';
  unsigned int cur_row = 4;
  unsigned int ans = get_next_row(cur_row, testcase_1);
  if (!(ans == 5)) {
      return false;
  }
  char testcase_2 = 'c';
  cur_row = 1;
  ans = get_next_row(cur_row, testcase_2);
  if (!(ans == 1)) {
      return false;
  }
  char testcase_3 = 's';
  cur_row = 3;
  ans = get_next_row(cur_row, testcase_3);
  if (!(ans == 4)) {
      return false;
  }
  char t4 = 'S';
  cur_row = 0;
  ans = get_next_row(cur_row, t4);
  if (!(ans == 1)) {
      return false;
  }
  char testcase_5 = 'M';
  cur_row = 5;
  ans = get_next_row(cur_row, testcase_5);
  if (!(ans == 5)) {
      return false;
  }
  char testcase_6 = '^';
  cur_row = 3;
  ans = get_next_row(cur_row, testcase_6);
  if (!(ans == 2)) {
      return false;
  }
  char testcase_7 = 'w';
  cur_row = 4;
  ans = get_next_row(cur_row, testcase_7);
  if (!(ans == 3)) {
      return false;
  }
  char testcase_8 = 'W';
  cur_row = 7;
  ans = get_next_row(cur_row, testcase_8);
  if (!(ans == 6)) {
      return false;
  }

  return true;
}

bool test_get_next_col() {
  // TODO: Implement this function.
  // Returns cur_col + 1 if c is > or d or D. Returns cur_col - 1 if c is < or a or A. Returns cur_col otherwise. -- spec
  char testcase_1 = 'd';
  unsigned int cur_col = 0;
  unsigned int ans = get_next_col(cur_col, testcase_1);
  if (!(ans == 1)) {
      return false;
  }
    char testcase_2 = '>';
    cur_col = 4;
    ans = get_next_col(cur_col, testcase_2);
    if (!(ans == 5)) {
        return false;
    }
    char testcase_3 = 'D';
    cur_col = 7;
    ans = get_next_col(cur_col, testcase_3);
    if (!(ans == 8)) {
        return false;
    }
    char testcase_4 = 'a';
    cur_col = 3;
    ans = get_next_col(cur_col, testcase_4);
    if (!(ans == 2)) {
        return false;
    }
    char testcase_5 = '<';
    cur_col = 3;
    ans = get_next_col(cur_col, testcase_5);
    if (!(ans == 2)) {
        return false;
    }
    char testcase_6 = 'A';
    cur_col = 8;
    ans = get_next_col(cur_col, testcase_6);
    if (!(ans == 7)) {
        return false;
    }
    char testcase_7 = 'l';
    cur_col = 10;
    ans = get_next_col(cur_col, testcase_7);
    if (!(ans == 10)) {
        return false;
    }
    char testcase_8 = 'm';
    cur_col = 1;
    ans = get_next_col(cur_col, testcase_7);
    if (!(ans == 1)) {
        return false;
    }
  return true;
}

bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
