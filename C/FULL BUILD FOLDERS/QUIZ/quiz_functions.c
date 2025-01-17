#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quiz_functions.h"

//for use in randomizing questions
void initialize_random_seed() 
{
    srand(time(NULL));
}

//load specified number of questions from file into struct 
int load_questions(const char *filename, QuizQuestions *quiz, int max_questions)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    char line[500];

    fgets(line, sizeof(line), file); // Skip the header
    while (fgets(line, sizeof(line), file) && count < max_questions) 
    {
        char *token = strtok(line, ",");
        quiz[count].question_number = atoi(token);
        token = strtok(NULL, "\"");
        strcpy(quiz[count].question, token);

        for (int i = 0; i < 4; i++) 
        {
            token = strtok(NULL, "\",");
            strcpy(quiz[count].options[i], token ? token : "");
        }

        token = strtok(NULL, ",");
        quiz[count].correct_option = atoi(token);
        count++;
    }
    fclose(file);
    return count;
}

//ask user how many questions they want to solve
int get_number_of_questions(int available_questions) 
{
    int num_questions;
    printf("There are %d questions available.\n", available_questions);
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    if (num_questions > available_questions || num_questions <= 0) 
    {
        printf("Invalid number of questions. Exiting quiz.\n");
        return -1;
    }
    return num_questions;
}

//Allows user to select an answer and prompts if right or wrong.
int conduct_quiz(QuizQuestions *quiz, int num_questions) 
{
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        display_question(quiz[i]);

        int user_answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);

        if (user_answer == quiz[i].correct_option) 
        {
            printf("Correct!\n");
            score++;
        } 
        else 
        {
            printf("Wrong! The correct answer was %d. %s\n", 
                   quiz[i].correct_option, 
                   quiz[i].options[quiz[i].correct_option - 1]);
        }
        printf("\n");
    }
    return score;
}

//Uses the random seed function to randomize question.
void shuffle_questions(QuizQuestions *quiz, int count) 
{
    for (int i = count - 1; i > 0; i--) 
    {
        // Random index from 0 to i
        int j = rand() % (i + 1);
        // Swap quiz[i] and quiz[j]
        QuizQuestions temp = quiz[i];
        quiz[i] = quiz[j];
        quiz[j] = temp;
    }
}

// Function to display a question and options
void display_question(QuizQuestions q)
{
    // Print question
    printf("%d. %s\n", q.question_number, q.question);

    // Loop through to print options
    for (int i = 0; i < 4; i++) 
    {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

//Show score after completing selected questions.
void display_score(int score, int num_questions) 
{
    printf("You got %d out of %d questions correct. (%.2f%%)\n", 
           score, num_questions, (score / (float)num_questions) * 100);
}