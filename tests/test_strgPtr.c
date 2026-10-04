/*
 * CSE 220 Homework 4, Part 1 tests.
 *
 * A few sample tests are given so you can see how Criterion is set up. They
 * fail until you implement the functions, which is expected.
 *
 * You must add your own tests: at least 5 per function, for all six functions
 * in strgPtr.c. Test the edge cases too, not only the examples from the
 * assignment: NULL arguments, empty strings, and buffers that are too small.
 *
 * Build and run these with:   make test
 */
#include <criterion/criterion.h>
#include "strgPtr.h"

/* Test(suite_name, test_name) is how Criterion declares one test. */

Test(strgLen, counts_characters)
{
    cr_assert_eq(strgLen("Stony Brook"), 11);
    cr_assert_eq(strgLen(""), 0);
    cr_assert_eq(strgLen("CSE 220"),7);
    cr_assert_eq(strgLen("-1982"),5);
}

Test(strgLen, null_is_an_error)
{
    cr_assert_eq(strgLen(NULL), -1);
}



Test(strgCopy, copies_a_short_string)
{
    char destination[20];

    strgCopy("Computer Science", destination, sizeof destination);
    cr_assert_str_eq(destination, "Computer Science");
}

Test(strgCopy, stops_when_the_buffer_is_full)
{
    char destination[5];

    strgCopy("Computer Science", destination, sizeof destination);
    cr_assert_str_eq(destination, "Comp");
}
   

Test(strgCopy, size_greater_than_string)
{
    char destination[8];

    strgCopy("CSE-220", destination, sizeof destination);
    cr_assert_str_eq(destination, "CSE-220");

}

Test(strgCopy, string_empty_and_size_greater_than_string)
{
    char destination[5];

    strgCopy("", destination, sizeof destination);
    cr_assert_str_eq(destination, "");
}

Test(strgCopy, size_one_edgecase)
{
    char destination[1];

    strgCopy("abc", destination, sizeof destination);
    
    cr_assert_str_eq(destination, "");
}

Test(strgChangeCase, skips_letters_next_to_digits)
{
    char s[] = "CSE220";

    strgChangeCase(s);
    cr_assert_str_eq(s, "csE220");
}


Test(strgDiff, identical_strings)
{
    cr_assert_eq(strgDiff("Hello", "Hello"), -1);
}

Test(strgDiff, first_difference_middle)
{
    cr_assert_eq(strgDiff("CSE-220", "CSE220"), 3);
}

Test(strgDiff, first_difference_at_start)
{
    cr_assert_eq(strgDiff("CSE220", "SE220"), 0);
}

Test(strgDiff, both_empty)
{
    cr_assert_eq(strgDiff("", ""), -1);
}

Test(strgDiff, second_string_longer)
{
    cr_assert_eq(strgDiff("abc", "abcd"), 3);
}


Test(strgDiff, second_string_null)
{
    cr_assert_eq(strgDiff("abc", NULL), -2);
}



Test(strgInterleave, equal_length_strings)
{
    char destination[20];

    strgInterleave("abc", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b2c3");
}

Test(strgInterleave, first_string_longer)
{
    char destination[20];

    strgInterleave("abcdef", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b2c3def");
}

Test(strgInterleave, second_string_longer)
{
    char destination[20];

    strgInterleave("cse", "12345", destination, sizeof destination);

    cr_assert_str_eq(destination, "c1s2e345");
}

Test(strgInterleave, first_string_numbers_second_letters)
{
    char destination[20];

    strgInterleave("1234", "cs", destination, sizeof destination);

    cr_assert_str_eq(destination, "1c2s34");
}

Test(strgInterleave, both_strings_empty)
{
    char destination[20];

    strgInterleave("", "", destination, sizeof destination);

    cr_assert_str_eq(destination, "");
}

Test(strgInterleave, first_string_empty)
{
    char destination[20];

    strgInterleave("", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "123");
}

Test(strgInterleave, truncates_size_4)
{
    char destination[4];

    strgInterleave("abc", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b");
}

Test(strgInterleave, truncates_size_5)
{
    char destination[5];

    strgInterleave("abc", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b2");
}

Test(strgInterleave, truncates_first_string_longer)
{
    char destination[6];

    strgInterleave("abcdef", "12", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b2c");
}


Test(strgReverseLetters, normal_word)
{
    char s[] = "Hello";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "olleH");
}

Test(strgReverseLetters, hyphen_stays_in_place)
{
    char s[] = "ab-cd";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "dc-ba");
}

Test(strgReverseLetters, digit_stays_in_place)
{
    char s[] = "a1b2c";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "c1b2a");
}

Test(strgReverseLetters, letters_with_digit)
{
    char s[] = "C3PO";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "O3PC");
}

Test(strgReverseLetters, spaces_and_punctuation_stay_in_place)
{
    char s[] = "Hi, Bob";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "bo, BiH");
}

Test(strgReverseLetters, empty_string)
{
    char s[] = "";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "");
}

Test(strgReverseLetters, null_string)
{
    strgReverseLetters(NULL);

    // If we get here without crashing, the test passes.
    cr_assert(1);
}
  

/*
 * TODO: add your own tests below.
 *
 * You still need more tests for strgLen, strgCopy and strgChangeCase, and at
 * least 5 tests each for strgDiff, strgInterleave and strgReverseLetters.
 *
 * Useful assertions:
 *   cr_assert_eq(actual, expected)       two values are equal
 *   cr_assert_str_eq(actual, expected)   two strings have the same contents
 *   cr_assert_null(pointer)              the pointer is NULL
 *   cr_assert(condition)                 the condition is true
 */
