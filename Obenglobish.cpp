/*
 * File: Obenglobish.java
 * ----------------------
 * Name: [TODO: Amy R. Weiner]
 * Section: [TODO: enter section leader here]
 * This program translates a word from English
 * into Obenglobish, according to the rules 
 * given in the Assignment 1 handout. 
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */
string obenglobish (string word);
bool isVowel (char ch);
bool isFollowingVowel(int i, string word);
bool isFinalE(char ch, int i, string word);
string prependOb(string sub);
    
/* Main program */
int main() {
    while (true) {
        string word = getLine("Please enter a word: ");
        if (word == "") break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
   return 0;
}

/* Function: obenglobish
 * Usage: string translation = obenglobish(word);
 * ----------------------------------------------
 * This function translates a word from English
 * to Obenglobish, according to the rules 
 * specified in the assignment. The translated
 * word is returned as the value of the function.
 */
string obenglobish (string word) {
    string trans = "";
    for (int i = 0; i < word.length(); i ++) {
        char ch = word.at(i);
        if (isVowel(ch) && (!isFollowingVowel(i, word) && !isFinalE(ch, i, word))) {
            string substring = word.substr(i, 1);
            trans += prependOb(substring);
            }else {
            trans += ch;
        }
    }
    return trans;
}

/* Function: isVowel
 * Usage: if (isVowel(ch)) . . .
 * -----------------------------
 * This function returns true if
 * the character ch is a vowel.
 */
bool isVowel (char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

/* Function: isFollowingVowel
 * Usage: if (isFollowingVowel(i, word)) . . .
 * -------------------------------------------
 * This function returns true if the current
 * index position i of the word is greater than 
 * zero, and the character at the previous index 
 * position is not a vowel. 
 */
bool isFollowingVowel(int i, string word) {
    return (i > 0) && (isVowel(word.at(i -1))); 
}

/* Function: isFinalE
 * Usage: if (isFinalE(ch, i, word)) . . .
 * ---------------------------------------
 * This function returns true if the 
 * current index position i of the word is 
 * the last index position, and the 
 * character ch is the vowel 'e' or 'E'.  
 */
bool isFinalE(char ch, int i, string word) {
    int last = word.length() - 1;
    return (i == last) && ((ch == 'e') || (ch == 'E'));
}

/* Function: prependOb
 * Usage: string translation = prependOb(substring);
 * -------------------------------------------------
 * This function prepends the string of characters
 * "ob" to a substring. The substring with the "ob"
 * prepended is returned as the value of the functin.
 */
string prependOb(string substring) {
    string ob = "ob";
    return ob + substring;
}
 
