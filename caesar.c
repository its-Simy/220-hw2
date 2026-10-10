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

    if (!plaintext || !ciphertext){return -2;}
    if ((int)size < 8){return -1;}
    
    int count = strgLen(plaintext);
    int payload = (int)size-8;
    if(count < payload){payload=count;}

    int index = 0;

    while (index < payload && plaintext[index]){
        //if its a capital letter
        if ((int)plaintext[index] >= 65 && (int)plaintext[index] <= 90){
            int shift = (index + key) % 26;
            int letter = (int)plaintext[index] + shift;
            if(letter > 90){
                int difference = letter % 91;
                ciphertext[index] = (char)('A' + difference);
            }
            else if(letter < 65){
                int difference = 65 - letter;
                ciphertext[index] = (char)('Z' - (difference-1));
            }
            else{
                ciphertext[index] = (char)letter;
            }
        }

        //if its a lowercase letter

        else if ((int)plaintext[index] >= 97 && (int)plaintext[index] <= 122){
            int shift = (index + key)%26;
            int letter = (int)plaintext[index] + shift;
            if(letter > 122){
                int difference = letter % 123;
                ciphertext[index] = (char)('a' + difference);
            }
            else if(letter < 97){
                int difference = 97 - letter;
                ciphertext[index] = (char)('z' - (difference-1));
            }
            else{
                ciphertext[index] = (char)letter;
            }
        }
        //if its a number
        else if ((int)plaintext[index] >= 48 && (int)plaintext[index] <= 57){
            int shift = ((2 * index) + key)%10;
            int num = (int)plaintext[index] + shift;
            if (num > 57){
                int difference = (int)num % 58;
                ciphertext[index] = (char)('0' + difference);
            }
            else if((int)num < 48){
                int difference = 48 - num;
                ciphertext[index] = (char)('9' - (difference-1));
            }
            else{
                ciphertext[index] = (char)num;
            }
        }
        // anything else
        else{
            ciphertext[index] = plaintext[index];
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
    if (!ciphertext || !plaintext){return -2;}
    if (size == 0 || size == 1){return 0;}

    char eom[] = "__EOM__";
    int point = -1;
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        int j = 0;
        while (j < 7 && ciphertext[i + j] == eom[j]) {
            j++;
        }
        if (j == 7) {
            point = i;
            break;
        }
    }

    if (point == -1){return -1;}

    point = point > (int)size-1 ? (int)size-1 : point;
    int index = 0;

    while (index < point){

        //if its a capital letter
        if ((int)ciphertext[index] >= 65 && (int)ciphertext[index] <= 90){
            int shift = (index + key) % 26;
            int letter = (int)ciphertext[index] - shift;
            if(letter > 90){
                int difference = letter % 91;
                plaintext[index] = ('A' + difference);
            }
            else if(letter < 65){
                int difference = 65- letter;
                plaintext[index] = ('Z' - (difference-1));
            }
            else{
                plaintext[index] = (char)letter;
            }
        }

        //if its a lowercase letter

        else if ((int)ciphertext[index] >= 97 && (int)ciphertext[index] <= 122){
            int shift = (index + key) % 26;
            int letter = (int)ciphertext[index] - shift;
            if(letter > 122){
                int difference = letter % 123;
                plaintext[index] = (char)('a' + difference);
            }
            else if(letter < 97){
                int difference = 97 - letter;
                plaintext[index] = (char)('z' - (difference-1));
            }
            else{
                plaintext[index] = (char)letter;
            }
        }
        //if its a number
        else if ((int)ciphertext[index] >= 48 && (int)ciphertext[index] <= 57){
            int shift = ((2 * index) + key)%10;
            int num = (int)ciphertext[index] - shift;
            if (num > 57){
                int difference = (int)num % 58;
                plaintext[index] = (char)('0' + difference);
            }
            else if(num < 48){
                int difference = 48 - num;
                plaintext[index] = (char)('9' - difference+1);
            }
            else{
                plaintext[index] = (char)num;
            }
        }
        // anything else
        else{
            plaintext[index] = ciphertext[index];
        }
        index++;
    }

    plaintext[index] = '\0';
    return index;
}