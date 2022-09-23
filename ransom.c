/***************************************************************************
 * Anon's Ransomware Puzzle, Version 1.1
 * Copyright 2020, Anonymous Russian Hacker. All rights reserved.
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/* 
 * Note to self: Remember to erase this file so my victims will
 * idea what is going on, and I can steal all of their files for
 * bitcoin. 
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* When run with no arguments, the binary reads its input lines 
     * from standard input. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* When run with one argument <file>, the ransomware binary reads from <file> 
     * until EOF, and then switches to standard input. Thus, as you 
     * pass each phase, you can add its pass string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* You can't call the binary with more than 1 command line argument. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Do all sorts of secret stuff that makes the ransomware harder to defeat. */
    initialize_ransom();

    printf("Too bad, West Point! You have been infected with my l33t ransomware! To defeat me, you have to pass\n");
    printf("all 6 phases by typing in the secret string for each. Your files will be mine though.. muahahahaha!\n");

    /* Hmm...  Six phases must be more secure than one phase! */
    input = read_line();             /* Get input                   */
    phase_1(input);                  /* Run the phase               */
    phase_passed();                 /* Drat!  They figured it out!
				      * They won't get the next one though. */
    printf("So you passed phase 1. Can you get the next one?\n");

    /* The second phase is harder.  No one will ever figure out
     * how to pass this... */
    input = read_line();
    phase_2(input);
    phase_passed();
    printf("That's number 2. Keep going (if you can)!\n");

    /* Perhaps it's too easy so far. This next one will confuse people. */
    input = read_line();
    phase_3(input);
    phase_passed();
    printf("So you are halfway there. Soon you'll be living on a prayer, muahahahaha...\n");

    /* This next one will definitely stump everyone */
    input = read_line();
    phase_4(input);
    phase_passed();
    printf("So you got that one.  Try this one.\n");
    
    /* It deciphers the memory in the phase, or else it will get the file encrypted again*/
    input = read_line();
    phase_5(input);
    phase_passed();
    printf("Wow! You got it! I bet the next one will stump you though...\n");

    /* No one will actually get to this phase. But just in case, make it extra
     * hard. */
    input = read_line();
    phase_6(input);
    phase_passed();
    printf("You freed the server. Congratulations!\n");

    /* Dang! They defeated me! But could there be something... missing?*/
    return 0;
}
