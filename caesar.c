/*
 * CSE 220 Homework 4, Part 2: position aware Caesar cipher.
 *
 * Implement the two functions below. You may not use <string.h> or <ctype.h>.
 * You must use your own strgLen from Part 1 whenever you need the length of a
 * string, which is why strgPtr.h is included here.
 *
 * Remove the (void) lines as you fill each function in. They are only there so
 * the starter kit compiles with -Werror before you have written any code.
 */
#include "caesar.h"
#include "strgPtr.h"
#include <stdio.h>

/* The end of message marker. It is never encrypted or decrypted. */
#define EOM "__EOM__"
#define EOM_LEN 7

int encryptCaesar(const char *plaintext, char *ciphertext, size_t size, int key)
{
    /*
     * TODO: encrypt plaintext into ciphertext, then append __EOM__ and '\0'.
     *
     * Check the errors in this order and change nothing in ciphertext when
     * you return one:
     *   1. a NULL pointer returns -2
     *   2. a size with no room for the marker and its terminator returns -1
     *
     * The marker plus '\0' needs 8 bytes, so at most size - 8 characters of
     * the payload fit. Encrypt only that many when the message is longer, and
     * return how many you actually wrote.
     *
     * Shifting, where index starts at 0 and counts every character:
     *   letters shift by key + index, within A to Z or a to z
     *   digits shift by key + 2 * index, within 0 to 9
     *   everything else is copied unchanged but still uses up an index
     *
     * Careful with negative keys: in C, -3 % 26 is -3, not 23. Make sure the
     * value you end up with is inside the range before you turn it back into
     * a character.
     */

 

    if (!plaintext){return -2;}
    if ((int)size <= 8){return -1;}
    
    int count = 0;
    while (plaintext[count+1]){
        count++;
    }
    int payload_size = (int)size;
    if (count > (int)size){
        payload_size = size-8;
    }

    int index = 0;

    while (index < payload_size && plaintext[index]){
        //if its a capital letter
        if ((int)plaintext[index] >= 65 && (int)plaintext[index] <= 90){
            char letter = (char)((int)plaintext[index] + (index + key));
            if((int)letter > 90){
                char difference = letter % (char)91;
                ciphertext[index] = ('A' + difference);
            }
            else{
                ciphertext[index] = letter;
            }
        }

        //if its a lowercase letter

        else if ((int)plaintext[index] >= 97 && (int)plaintext[index] <= 122){
            char letter = (char)((int)plaintext[index] + (index + key));
            if((int)letter > 122){
                char difference = letter % (char)123;
                ciphertext[index] = ('a' + difference);
            }
            else if((int)letter < 97){
                char difference = (char)97 - letter;
                ciphertext[index] = ('z' - (difference-1));
            }
            else{
                ciphertext[index] = letter;
            }
        }
        //if its a number
        else if ((int)plaintext[index] >= 48 && (int)plaintext[index] <= 57){
            printf("\nWent INSIDE");
            char num = (char)( (2 * index) + (int)plaintext[index] + key);
            if ((int)num > 57){
                
                char difference = num % (char)58;
                printf("\nCharacter: %c\n", plaintext[index]);
                printf("Difference Character %d\n",(int)difference);
                ciphertext[index] = ('0' + difference);
            }
            else{
                ciphertext[index] = num;
            }
            
        }
        // anything else
        else{
            ciphertext[count] = plaintext[count];
        }
        index++;
    }
    int temp = index;
    if (index < (int)size){
        ciphertext[temp++] = '_';
        ciphertext[temp++] = '_';
        ciphertext[temp++] = 'E';
        ciphertext[temp++] = 'O';
        ciphertext[temp++] = 'M';
        ciphertext[temp++] = '_';
        ciphertext[temp++] = '_';
    }
    ciphertext[temp] = '\0';
    return index;
}

int decryptCaesar(const char *ciphertext, char *plaintext, size_t size, int key)
{
    /*
     * TODO: decrypt ciphertext into plaintext, stopping at the marker.
     *
     * Check the errors in this order and change nothing in plaintext when you
     * return one:
     *   1. a NULL pointer returns -2
     *   2. a size of 0 or 1, which leaves no room for any character, returns 0
     *   3. a ciphertext with no complete __EOM__ returns -1
     *
     * Decrypt up to the first complete marker only, and ignore anything after
     * it. All 7 characters must be present and in order, so __EOM_ does not
     * count as a marker.
     *
     * Write at most size - 1 characters and then terminate. Return how many
     * you actually wrote. Decrypting means shifting backward by the same
     * amounts that encryption shifted forward, using the same indexes.
     */
    (void)ciphertext;
    (void)plaintext;
    (void)size;
    (void)key;
    return 0;
}
