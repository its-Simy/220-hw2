/*
 * CSE 220 Homework 4, Part 1: string manipulation.
 *
 * Implement the six functions below. You may not use <string.h> or <ctype.h>.
 * <stddef.h> is included for you through strgPtr.h, and you may include
 * <stdio.h> while you debug.
 *
 * Array indexing and pointer arithmetic are both accepted. Pointers are
 * encouraged, since that is what this homework is meant to practice.
 *
 * Remove the (void) lines as you fill each function in. They are only there so
 * the starter kit compiles with -Werror before you have written any code.
 */
#include "strgPtr.h"

int strgLen(const char *s)
{
    /* TODO: return the number of characters before the terminating '\0'. */

    /* NULL is an error here and returns -1. */
    if (!s){return -1;}
    

    /*
    we can check if iterating through the string is null or not, so if its not then we increment because that means theres a value there
    otherwise the loop ends, and then we can just return the count.
    */
    int count = 0;
    while(*(s + count)){
        count++;
    }

    return count;
}


//void strgCopy(const char *source, char *destination, size_t size)
//{
    /*
     * TODO: copy source into destination, including the '\0'.
     *
     * size is the whole capacity of destination, so at most size - 1
     * characters plus the terminator fit. Copy what fits and terminate.
     * Do nothing at all when a pointer is NULL or size is 0.
     */
     /*
    (void)source;
    (void)destination;
    (void)size;

    if (!source || !destination || size == 0){
        return;
    }
        */
    /*

    If source does not fit, copy the first (size-1) with size 5, "Computer Science" becomes "Comp".
    1 characters and then write '\0'
    For example: 
    
    If size is 1, store only '\0'

    */



//}

//void strgChangeCase(char *s)
//{
    /*
     * TODO: flip the case of each letter, in place.
     *
     * Skip a letter when the character immediately before it or immediately
     * after it is a digit. The first character has no left neighbor and the
     * last character has no right neighbor, so only check the side that
     * exists. Characters that are not letters never change.
     */
    //(void)s;
//}

//int strgDiff(const char *s1, const char *s2)
//{
    /*
     * TODO: return the index of the first position where the two strings
     * differ, or -1 when they are identical.
     *
     * When one string ends first, that position is the index of its '\0',
     * so "abc" and "abcd" differ at index 3.
     */
     /*
    (void)s1;
    (void)s2;
    return 0;
}

void strgInterleave(const char *s1, const char *s2, char *d, size_t size)
{
*/
    /*
     * TODO: write characters into d, alternating s1, s2, s1, s2, and so on,
     * starting with s1. When one string runs out, copy the rest of the other.
     *
     * size is the whole capacity of d. Stop as soon as size - 1 characters
     * have been written, then terminate. Watch the buffer check between the
     * two writes of a pair: the character from s1 may fit while the one from
     * s2 does not.
     */
    /*
    (void)s1;
    (void)s2;
    (void)d;
    (void)size;
}

void strgReverseLetters(char *s)
{
*/
    /*
     * TODO: reverse the order of the letters in s, in place.
     *
     * Every character that is not a letter keeps its original index, so
     * "ab-cd" becomes "dc-ba". Walking one index in from each end and
     * swapping only when both sides are letters is one way to do this.
     */
   // (void)s;
//}
