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

//encrypt then decrypt the same key
Test(decryptCaesar, negative_key)
{
    char ciphertext[40];
    char plaintext[40];
    const char *message = "xQ7 kz!9 Mb#3 pL";
 
    cr_assert_eq(encryptCaesar(message, ciphertext, sizeof ciphertext, -7), 16);
 
    int result = decryptCaesar(ciphertext, plaintext, sizeof plaintext, -7);
 
    cr_assert_eq(result, 16);
    cr_assert_str_eq(plaintext, message);
}
//checks that NULL is tested first
Test(encryptCaesar, null_checked)
{
    char ciphertext[20] = "unchanged";
 
    int result = encryptCaesar(NULL, ciphertext, 3, 1);
 
    cr_assert_eq(result, -2);
    cr_assert_str_eq(ciphertext, "unchanged");
}
 
//empty input
Test(encryptCaesar, empty_intput)
{
    char ciphertext[8];
    int result = encryptCaesar("", ciphertext, 8, 3);
    cr_assert_eq(result, 0);
    cr_assert_str_eq(ciphertext, "__EOM__");
}
 
//one character too long for the buffer
Test(encryptCaesar, one_char_too_long)
{
    char ciphertext[12];
 
    int result = encryptCaesar("Hello", ciphertext, 12, 0);
    cr_assert_eq(result, 4);
    cr_assert_str_eq(ciphertext, "Hfno__EOM__");
}
 
//negative key forced left rotation
Test(encryptCaesar, left_rotation)
{
    char ciphertext[20];
 
    int result = encryptCaesar("0", ciphertext, 20, -1);
 
    cr_assert_eq(result, 1);
    cr_assert_str_eq(ciphertext, "9__EOM__");
}
 
//max key
Test(encryptCaesar, max_key)
{
    char ciphertext[20];
 
    int result = encryptCaesar("Hi, 42!", ciphertext, 20, 1000000);
 
    cr_assert_eq(result, 7);
    cr_assert_str_eq(ciphertext, "Vx, 22!__EOM__");
}
 


//null plaintext
Test(decryptCaesar, null_plaintext)
{
    int result = decryptCaesar("ceg__EOM__", NULL, 20, 2);
 
    cr_assert_eq(result, -2);
}
//no null value
Test(decryptCaesar, missing_null)
{
    char plaintext[20] = "unchanged";
 
    int result = decryptCaesar("tbh", plaintext, 0, 2);
 
    cr_assert_eq(result, 0);
    cr_assert_str_eq(plaintext, "unchanged");
}
 
//eom isn't complete
Test(decryptCaesar, incomplete_eom)
{
    char plaintext[20];
 
    int result = decryptCaesar("ab__EOM_cd__EOM__", plaintext, 20, 0);
 
    cr_assert_eq(result, 10);
    cr_assert_str_eq(plaintext, "aa__AJG_uu");
}
 
// Buffer too small and min key
Test(decryptCaesar, small_buffer_and_min_key)
{
    char plaintext[3];
 
    int result = decryptCaesar("Lm45__EOM__", plaintext, 3, -1000000);
    cr_assert_eq(result, 2);
    cr_assert_str_eq(plaintext, "Zz");
}

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
