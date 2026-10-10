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
//null string returns -1
Test(strgLen, null_string)
{
    int result = strgLen(NULL);

    cr_assert_eq(result, -1);
}

//empty string has length 0
Test(strgLen, empty_string)
{
    int result = strgLen("");

    cr_assert_eq(result, 0);
}

//spaces count as characters
Test(strgLen, only_spaces)
{
    int result = strgLen("   ");

    cr_assert_eq(result, 3);
}

//symbols and digits count too
Test(strgLen, symbols_and_digits)
{
    int result = strgLen("aindf1 o13!34");

    cr_assert_eq(result, 13);
}

//stops at the first '\0'
Test(strgLen, stops_at_first_null)
{
    int result = strgLen("abc\0def");

    cr_assert_eq(result, 3);
}



//null source leaves destination alone
Test(strgCopy, null_source)
{
    char destination[10] = "unchanged";

    strgCopy(NULL, destination, sizeof destination);

    cr_assert_str_eq(destination, "unchanged");
}

//size 0 does nothing
Test(strgCopy, size_zero)
{
    char destination[10] = "unchanged";

    strgCopy("hello", destination, 0);

    cr_assert_str_eq(destination, "unchanged");
}

//empty source overwrites the old contents
Test(strgCopy, empty_source)
{
    char destination[10] = "unchanged";

    strgCopy("", destination, sizeof destination);

    cr_assert_str_eq(destination, "");
}

//string and '\0' fill the buffer
Test(strgCopy, exact_fit)
{
    char destination[7];

    strgCopy("Spooks", destination, sizeof destination);

    cr_assert_str_eq(destination, "Spooks");
}

//one byte too small cuts off the last character
Test(strgCopy, one_char_too_small)
{
    char destination[6];

    strgCopy("Dfghjk", destination, sizeof destination);

    cr_assert_str_eq(destination, "Dfghj");
}



//null string, passes if it doesn't crash
Test(strgChangeCase, null_string)
{
    strgChangeCase(NULL);

    cr_assert(1);
}

//single letter has no neighbors
Test(strgChangeCase, single_letter)
{
    char s[] = "q";

    strgChangeCase(s);

    cr_assert_str_eq(s, "Q");
}

//digit two spots away doesn't count
Test(strgChangeCase, only_immediate_neighbors)
{
    char s[] = "a-1";

    strgChangeCase(s);

    cr_assert_str_eq(s, "A-1");
}

//digits on both sides of every letter
Test(strgChangeCase, digits_on_both_sides)
{
    char s[] = "1a2B3";

    strgChangeCase(s);

    cr_assert_str_eq(s, "1a2B3");
}

//first and last letters only have one neighbor
Test(strgChangeCase, first_and_last_letters)
{
    char s[] = "aB1cD";

    strgChangeCase(s);

    cr_assert_str_eq(s, "AB1cd");
}



//null first string
Test(strgDiff, null_first)
{
    int result = strgDiff(NULL, "abc");

    cr_assert_eq(result, -2);
}

//empty string ends right away
Test(strgDiff, empty_vs_nonempty)
{
    int result = strgDiff("", "a");

    cr_assert_eq(result, 0);
}

//first string longer
Test(strgDiff, first_longer)
{
    int result = strgDiff("abcd", "abc");

    cr_assert_eq(result, 3);
}

//only the last character is different
Test(strgDiff, last_char)
{
    int result = strgDiff("Rtyuio", "Rtyuip");
    cr_assert_eq(result, 5);
}

//upper and lower case count as different
Test(strgDiff, case_sensitive)
{
    int result = strgDiff("stony", "Stony");

    cr_assert_eq(result, 0);
}



//null second string leaves destination alone
Test(strgInterleave, null_second)
{
    char destination[10] = "unchanged";

    strgInterleave("abc", NULL, destination, sizeof destination);

    cr_assert_str_eq(destination, "unchanged");
}

//size 0 does nothing
Test(strgInterleave, size_zero)
{
    char destination[10] = "unchanged";

    strgInterleave("abc", "123", destination, 0);

    cr_assert_str_eq(destination, "unchanged");
}

//size 1 only fits '\0'
Test(strgInterleave, size_one)
{
    char destination[1];

    strgInterleave("abc", "123", destination, sizeof destination);

    cr_assert_str_eq(destination, "");
}

//second string empty copies the first
Test(strgInterleave, second_empty)
{
    char destination[20];

    strgInterleave("abc", "", destination, sizeof destination);

    cr_assert_str_eq(destination, "abc");
}

//cut off in the leftover part
Test(strgInterleave, truncates_leftover)
{
    char destination[6];

    strgInterleave("ab", "12345", destination, sizeof destination);

    cr_assert_str_eq(destination, "a1b23");
}



//null string, passes if it doesn't rash
Test(strgReverseLetters, null_string)
{
    strgReverseLetters(NULL);

    cr_assert(1);
}

//no letters so nothing moves
Test(strgReverseLetters, no_letters)
{
    char s[] = "123 !?";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "123 !?");
}

//letters at both ends swap
Test(strgReverseLetters, letters_at_ends)
{
    char s[] = "a123z";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "z123a");
}

//case moves with the letter
Test(strgReverseLetters, case_moves_with_letter)
{
    char s[] = "Wolfie 2026!";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "eifloW 2026!");
}

//symbols between every letter
Test(strgReverseLetters, symbols_between)
{
    char s[] = "a.b.c.d";

    strgReverseLetters(s);

    cr_assert_str_eq(s, "d.c.b.a");
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
