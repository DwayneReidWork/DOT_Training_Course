#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quiz_functions.h"

int main() 
{
    initialize_random_seed();

    QuizQuestions quiz[10];
    int count = load_questions("questions.csv", quiz, 10);
    if (count == -1) return 1;

    shuffle_questions(quiz, count);

    int num_questions = get_number_of_questions(count);
    if (num_questions == -1) return 1;

    int score = conduct_quiz(quiz, num_questions);

    display_score(score, num_questions);

    return 0;
}