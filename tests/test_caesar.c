/*
 * CSE 220 Homework 4, Part 2 tests.
 *
 * A few sample tests are given so you can see how Criterion is set up. They
 * fail until you implement the functions, which is expected.
 *
 * You must add your own tests: at least 5 per function, for both
 * encryptCaesar and decryptCaesar. Test the edge cases too: NULL arguments,
 * an empty message, negative keys, a buffer too small for the message, a
 * missing marker, and text after the marker.
 *
 * Build and run these with:   make test
 */
#include <criterion/criterion.h>
#include "caesar.h"
/*
Test(encryptCaesar, shifts_letters_by_key_plus_index)
{
    char ciphertext[20];

    cr_assert_eq(encryptCaesar("abc", ciphertext, sizeof ciphertext, 2), 3);
    cr_assert_str_eq(ciphertext, "ceg__EOM__");
}

Test(encryptCaesar, shifts_digits_by_key_plus_twice_the_index)
{
    char ciphertext[20];

    cr_assert_eq(encryptCaesar("Cse220", ciphertext, sizeof ciphertext, 1), 6);
    cr_assert_str_eq(ciphertext, "Duh911__EOM__");
}

Test(encryptCaesar, reports_a_buffer_with_no_room_for_the_marker)
{
    char ciphertext[7];

    cr_assert_eq(encryptCaesar("abc", ciphertext, sizeof ciphertext, 2), -1);
}

Test(decryptCaesar, recovers_the_message)
{
    char plaintext[20];

    cr_assert_eq(decryptCaesar("ceg__EOM__", plaintext, sizeof plaintext, 2), 3);
    cr_assert_str_eq(plaintext, "abc");
}

Test(decryptCaesar, reports_a_missing_marker)
{
    char plaintext[20];

    cr_assert_eq(decryptCaesar("ceg", plaintext, sizeof plaintext, 2), -1);
}
    

    Test(encryptCaesar, basic_lowercase)
{
    char ciphertext[20];

    int result = encryptCaesar("abc", ciphertext, 20, 2);

    cr_assert_eq(result, 3);
    cr_assert_str_eq(ciphertext, "ceg__EOM__");
}


Test(encryptCaesar, mixed_case)
{
    char ciphertext[20];

    int result = encryptCaesar("Ayb", ciphertext, 20, 3);

    cr_assert_eq(result, 3);
    cr_assert_str_eq(ciphertext, "Dcg__EOM__");
}

Test(encryptCaesar, letters_and_numbers)
{
    char ciphertext[20];

    int result = encryptCaesar("Cse220", ciphertext, 20, 1);

    cr_assert_eq(result, 6);
    cr_assert_str_eq(ciphertext, "Duh911__EOM__");
}

Test(encryptCaesar, key_zero)
{
    char ciphertext[20];

    int result = encryptCaesar("CS", ciphertext, 20, 0);

    cr_assert_eq(result, 2);
    cr_assert_str_eq(ciphertext, "CT__EOM__");
}

Test(encryptCaesar, negative_key)
{
    char ciphertext[20];

    int result = encryptCaesar("abc", ciphertext, 20, -2);

    cr_assert_eq(result, 3);
    cr_assert_str_eq(ciphertext, "yac__EOM__");
}
*/

Test(encryptCaesar, key_over_26)
{
    char ciphertext[20];

    int result = encryptCaesar("Cse220", ciphertext, 20, 27);

    cr_assert_eq(result, 6);
    cr_assert_str_eq(ciphertext, "Duh577__EOM__");
}
/*
Test(encryptCaesar, empty_plaintext)
{
    char ciphertext[20];

    int result = encryptCaesar("", ciphertext, 20, 5);

    cr_assert_eq(result, 0);
    cr_assert_str_eq(ciphertext, "__EOM__");
}

Test(encryptCaesar, full_message)
{
    char ciphertext[30];

    int result = encryptCaesar("System Fundamentals", ciphertext, 30, 1);

    cr_assert_eq(result, 19);
    cr_assert_str_eq(ciphertext, "Tavxjs Ndxomzscjrdl__EOM__");
}

Test(encryptCaesar, truncated_message)
{
    char ciphertext[12];

    int result = encryptCaesar("System Fundamentals", ciphertext, 12, 1);

    cr_assert_eq(result, 4);
    cr_assert_str_eq(ciphertext, "Tavx__EOM__");
}

Test(encryptCaesar, size_too_small)
{
    char ciphertext[20] = "unchanged";

    int result = encryptCaesar("abc", ciphertext, 7, 2);

    cr_assert_eq(result, -1);
    cr_assert_str_eq(ciphertext, "unchanged");
}

Test(encryptCaesar, null_plaintext)
{
    char ciphertext[20] = "unchanged";

    int result = encryptCaesar(NULL, ciphertext, 20, 1);

    cr_assert_eq(result, -2);
    cr_assert_str_eq(ciphertext, "unchanged");
}
*/

/*
 * TODO: add your own tests below.
 *
 * One good habit is a round trip test: encrypt a message, decrypt the result
 * with the same key, and check that you get the original message back.
 *
 * Useful assertions:
 *   cr_assert_eq(actual, expected)       two values are equal
 *   cr_assert_str_eq(actual, expected)   two strings have the same contents
 *   cr_assert(condition)                 the condition is true
 */
