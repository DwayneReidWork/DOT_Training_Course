#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//decrease size of arrays (do it dynamically)

// Define struct of questions (CSV format)
typedef struct 
{
    int question_number;
    char question[256];
    //4 potential answers per question 
    char options[4][256];
    int correct_option;
} QuizQuestions;

//randomizes selected questions using fisher-yates shuffle method
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

int main()
{
    //randomizer seed. Time(NULL) uses current time for random generation
    srand(time(NULL)); 

    // Load question file
    FILE *file;
    file = fopen("questions.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    QuizQuestions quiz[10];
    int count = 0;
    char line[500];

    // Skip the header row of the CSV file
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) 
    {
        //Read each line from the CSV file and tokenize it seperated by commas
        char *token = strtok(line, ",");
        quiz[count].question_number = atoi(token);
        token = strtok(NULL, "\"");
        strcpy(quiz[count].question, token);

        for (int i = 0; i < 4; i++) 
        {
            token = strtok(NULL, "\",");
            if (token != NULL) 
            {
                strcpy(quiz[count].options[i], token);
            } 
            else
            {
                // Handles empty options if needed
                strcpy(quiz[count].options[i], ""); 
            }
        }
        token = strtok(NULL, ",");
        quiz[count].correct_option = atoi(token);
        count++;
    }
    fclose(file);

    // Shuffle the questions
    shuffle_questions(quiz, count);

    // Ask user how many questions they want to answer
    int num_questions;
    printf("There are %d questions available.\n", count);
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    // Validate the number of questions
    if (num_questions > count || num_questions <= 0) 
    {
        printf("Invalid number of questions. Exiting quiz.\n");
        return 1;
    }

    int score = 0;

    // Display the specified number of questions and take answers
    for (int i = 0; i < num_questions; i++) 
    {
        display_question(quiz[i]);

        int user_answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);

        // Validate the answer
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

    // Display final score
    printf("You got %d out of %d questions correct. (%.2f%%)\n", 
           score, num_questions, (score / (float)num_questions) * 100);

    return 0;
}