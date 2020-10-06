/* Copyright (c) 2020, Patrik Nyström
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "readinput/readinput.h"

struct Question {
    const char* question;
    const char* answer;
};

void runQuiz(void);
void validateQuestion(struct Question question);
void lowerString(char* str);

static unsigned int score = 0;

void runQuiz(void) {
    // Create questions
    struct Question q1 = {
        .question = "What's the most important component of a computer?",
        .answer = "motherboard"
    };
    struct Question q2 = {
        .question = "What Ctrl+Z does in Word?",
        .answer = "undos"
    };
    struct Question q3 = {
        .question = "How many megabytes are in a gigabyte?",
        .answer = "1024"
    };
    struct Question q4 = {
        .question = "What's the computer bus called in Finnish?",
        .answer = "tietokoneväylä"
    };
    struct Question q5 = {
        .question = "What was the brand of the first PC computer?",
        .answer = "ibm"
    };
    struct Question q6 = {
        .question = "How many bits are in a byte?",
        .answer = "8"
    };
    struct Question q7 = {
        .question = "How many values can be in a bit?",
        .answer = "2"
    };
    struct Question q8 = {
        .question = "From what word the letter L comes on LAN?",
        .answer = "local"
    };
    struct Question q9 = {
        .question = "What's the full name of BIOS?",
        .answer = "basic input/output system"
    };
    struct Question q10 = {
        .question = "What's the full name of .exe?",
        .answer = "executable"
    };
    struct Question q11 = {
        .question = "What's the full name of HTTP?",
        .answer = "hypertext transfer protocol"
    };
    struct Question q12 = {
        .question = "What's the full name of HTTPS?",
        .answer = "hypertext transfer protocol secure"
    };
    struct Question q13 = {
        .question = "What's the full name of FTP?",
        .answer = "file transfer protocol"
    };
    struct Question q14 = {
        .question = "What's the full name of SFTP?",
        .answer = "ssh file transfer protocol"
    };
    struct Question q15 = {
        .question = "What's the full name of SGI?",
        .answer = "silicon graphics"
    };
    struct Question q16 = {
        .question = "What's the short name of Bourne Shell?",
        .answer = "sh"
    };


    // Validate questions
    validateQuestion(q1);
    validateQuestion(q2);
    validateQuestion(q3);
    validateQuestion(q4);
    validateQuestion(q5);
    validateQuestion(q6);
    validateQuestion(q7);
    validateQuestion(q8);
    validateQuestion(q9);
    validateQuestion(q10);
    validateQuestion(q11);
    validateQuestion(q12);
    validateQuestion(q13);
    validateQuestion(q14);
    validateQuestion(q15);
    validateQuestion(q16);

    if (score > 7) {
        printf("Congratulations! You won! Your score was %d\n", score);
    } else {
        printf("You lost! Your score was %d\n", score);
    }
}

void validateQuestion(struct Question question) {
    printf("%s\n", question.question);
    char* q = readStrInput();
    lowerString(q);

    if (strncmp(question.answer, q, strlen(question.answer)) == 0) {
        score++;
        printf("\nCorrect! Your score is %d\n", score);
    } else {
        printf("\nIncorrect! Your score is %d\n", score);
    }
    free(q);
}

void lowerString(char* str) {
    if (str == NULL) {
        return;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (!islower((unsigned char) str[i])) {
            str[i] = tolower((unsigned char) str[i]);
        }
    }
}

void upperString(char* str) {
    if (str == NULL) {
        return;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (!isupper((unsigned char) str[i])) {
            str[i] = toupper((unsigned char) str[i]);
        }
    }
}

int main() {
    printf("Do you want to start the quiz? yes/no\n");

    char* choice = readStrInput();
    if (strncmp(choice, "yes\n", 5) == 0) {
        printf("Starting quiz\n\n");
        runQuiz();
    } else if (strncmp(choice, "no\n", 4) == 0) {
        printf("Exiting...\n");
    } else {
        printf("Exiting...\n");
    }

    free(choice);
    return 0;
}
