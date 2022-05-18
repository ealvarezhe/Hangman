#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/**
 * Function to calculate scores.
 * Use as parameters the level of difficulty,
 * number of tries and if the word was guessed.
 * Return the score.
 */
int score(int tries, int guess, int lvl){
    //Declare variable to store the final score.
    int points = 0;
    //Checking if the word was found. 
    if(guess == 1){
        points = 200;
        int i = 0;
        //Multiply points * 2 for each try.
        while(i != tries){
            points *= 2;
            i++;
        }
        //Multiply points for the level of difficulty. 
        points = points * lvl;
        //Return points.
        return points;
    }
    //Else return points = 0.
    else{
        return points;
    }
}

/**
 * Function to execute the main game. 
 * Using parameter of the word to guess 
 * Using parameter of the level of difficulty.
 * Returning the total score. 
 */
int game(char A[], int lvl){
    //Flag variable to check if the word has been found.
    int guess = 0;
    //Variable to check tries to guess the word.
    int tries  = 8;

    //Varible to store user's character input.
    char k;
    //Variables to store the length of the word to guess.
    int j = strlen(A);
    char word[j];
    //for loop printing underscore if a character hasn't been discovered.
    for(int i = 0; i < j; i++){
        word[i] = '_';
        printf("%c", word[i]);
    }
    printf("\n");

    //Game sequence.
    do{
        //Asking user to input a character. 
        printf("Enter a letter\n");
        printf("To Exit, press: 0\n");
        scanf(" %c", &k);
        k = tolower(k); 

        //Checking if user wants to exit.
        if(k == '0'){
            return 0;
        }
        
        //Flag variable to check if a letter has been found. 
        int letterFound = 0;
        for(int i = 0; i < j; i++){
            //Checking if the input letter matches a letter of the string.
            if(A[i] == k){
                word[i] = k;
                letterFound = 1;
            }
            //Branch in case no letter was found or if it's the last try.
            else if(letterFound == 0 && i == j - 1){
                //Substracting tries after missing.
                tries--;
                //Hagman printing pattern. 
                if(tries <= 7){
                    printf("\n");
                    printf("/`\\\n");
                }
                if(tries <= 6){
                    printf("\\_/\n");
                }
                if(tries <= 5){
                    printf("/");
                }
                if(tries <= 4){
                    printf("|");
                }
                if(tries <= 3){
                    printf("\\\n");
                }
                if(tries <= 2){
                    printf("/");
                }
                if(tries <= 1){
                    printf(" \\\n");
                    printf("LAST CHANCE!\n");
                }
            }
        }
        printf("\n");
        //Checking if all the letters of the word have been found.
        int letters = 0;
        for(int i = 0; i < j; i++){
            printf("%c", word[i]);
            if(word[i] != '_'){
                letters++;
                if(letters == j){
                    //If all letter have been found.
                    //Set variable guess to 1.
                    guess = 1;
                }
            }
        }
        printf("\n");
        //Continue looping until user run out of tries or word has been found.
    }while(tries > 0 && guess == 0);
    //If the word was founf print message. 
    if(guess == 1){
        printf("Congratulations!!! You have won the game!\n");
    }//Else
    else{
        printf("You lost :(\n");  
    }
    //Call score function to know the points the user got.
    //Use as parameters the level of difficulty, 
    //number of tries and if the word was guessed.
    int points = score(tries, guess, lvl);
    printf("You got a score of: %d\n", points);
    printf("\n");
    //Returning score. 
    return points;
}

/**
 * Method that contains categories and calls the game. 
 * Parameter n, index of word. 
 * Parameter lvl, level of difficulty.
 * Parameter points, to store the score.
 */
void Categories(int n, int lvl, int* points){
    //Category Selected.
    char cat;

    //Declaring Categories.
    char A [9][15] = {"lion", "dog", "cat", "panda", "snake", "horse", "orangutan", "rooster", "elephant"};
    char S [9][15] = {"hulk", "thor", "robin", "batman", "superman", "spiderman", "wonderwoman", " wolverine", "daredevil"};
    char C [9][15] = {"audi", "honda", "fiat", "ferrari", "toyota", "nissan", "chevrolet", "bugatti", "lamborghini"};
    char P [9][15] = {"spain", "peru", "cuba", "mexico", "france", "india", "germany", "argentina", "netherlands"};
    char F [9][15] = {"kiwi", "pear", "lime", "apple", "orange", "banana", "watermelon", "blueberry", "strawberry"};

    //Category Menu.
    printf("------------------------------\n");
    printf("Press a key to select a category\n");
    printf("------------------------------\n");
    printf("> A for Animals\n");
    printf("> S for Superheroes\n");
    printf("> C for Car Brands\n");
    printf("> P for Countries\n");
    printf("> F for Fruits\n");
    printf("> B to go back\n");
    printf("------------------------------\n");
    //Asking for user category input. 
    scanf(" %c", &cat);
    cat = tolower(cat);
    //Checking for a valid input.
    while(cat != 'a' && cat != 's' && cat != 'c' && cat != 'p' && cat != 'f' && cat != 'b'){
        printf("Invalid option, please type a valid option\n");
        scanf(" %c", &cat);
        cat = tolower(cat);
    } 
    //Checking user input and calling game depending on difficulty.
    if(cat == 'a'){
        char Z[strlen(A[n])];
        strcpy(Z, A[n]);
        *points = game(Z, lvl);
    }
    else if(cat == 's'){
        char Z[strlen(S[n])];
        strcpy(Z, S[n]);
        *points = game(Z, lvl); 
    }
    else if(cat == 'c'){
        char Z[strlen(C[n])];
        strcpy(Z, C[n]);
        *points = game(Z, lvl);
    }
    else if(cat == 'p'){
        char Z[strlen(P[n])];
        strcpy(Z, P[n]);
        *points = game(Z, lvl);
    }
    else if(cat == 'f'){
        char Z[strlen(F[n])];
        strcpy(Z, F[n]);
        *points = game(Z, lvl);
    }
    else if(cat == 'b'){
        //If option is b, return to menu.
        return;
    }
}

void Start(int* score){
    //Declaring variables for:
    //Difficulty selection by user input.
    char diff;
    //Level of difficult
    int lvl = 0;
    //Variable to randomize word.
    int n;
    //Variable to keep score.
    int points = 0;
    
    //Difficulty selection Menu. 
    printf("------------------------------\n");
    printf("Select  difficulty:\n");
    printf("> E for easy\n");
    printf("> M for medium\n");
    printf("> H for hard\n");
    //ASking for user input and setting it to lowerCase.
    scanf(" %c", &diff);
    diff = tolower(diff); 
    //Checking for valid input.
    while(diff != 'e' && diff != 'm' && diff != 'h'){
        printf("Invalid option, please type a valid option\n");
        scanf(" %c", &diff);
        diff = tolower(diff); 
    }
    //Setting sets of words according to difficulty.
    //And defining level of difficulty. 
    if(diff == 'e'){
        n = rand() % 3;
        lvl = 2; //Easy = lvl(2)
    }
    else if(diff == 'm'){
        n = (rand() % 3) + 3;
        lvl = 4; //Medium = lvl(4)
    }
    else{
        n = (rand() % 3) + 6;
        lvl = 6; //Hard = lvl(6)
    }
    //Calling categories function
    //Parameter n, lvl and points address.
    Categories(n, lvl, &points);
    
    int previous = 0;
    for(int i = 0; i < 5; i++){
        if(*score == 0){
            *score = points;
            break;
        }
        else if(points > *score){
            previous = *score;
            *score = points;
            points = previous;
        }
        score++;
    }
}
/**
 * Function to view and print scores. 
 * Pointer to scores array first elementas parameter.
 * Flag parameter to fprint or not.
 */
void PrintScores(int* score, int flag){
    //Pointer duplicate to scores array element 0,
    //In case of file printing. 
    int* printElem = score;
    //Printing scores.
    printf("Highest scores:\n");
    for(int i = 0; i < 5; i++){
        printf("%d: %d\n", i + 1, *score);
        score++;
    }
    if(flag == 1){
        //Declaring pointer and opening file in write mode.
        FILE* filePointer;
        filePointer = fopen("scores.txt", "w");
        for(int i = 0; i < 5; i++){
            //Printing each line of scores in file.
            fprintf(filePointer,"%d: %d\n", i + 1, *printElem);
            //Updating pointer position.
            printElem++;
        }
        //Closing file.
        fclose(filePointer);
        printf("Scores printed successfully\n");
    }
    printf("\n");
}

/**
 * Method to reset the scores.
 * Pointer to scores array first elementas parameter.
 */
void ResetScores(int* score){
    printf("Reseting scores:\n");
    //Set score to 0 for each element in array scores.
    for(int i = 0; i < 5; i++){
        *score = 0;
        //Printing updated score.
        printf("%d: %d\n", i + 1, *score);
        score++;   
    }
    printf("Scores have been reset\n");
    printf("------------------------------\n");
}

/**
 * Method to print instructions
 * on how to play the game.
 */
void Help(){
    //Printing Instructions on how to play.
    printf("\n");
    printf("------------------------------\n");
    printf("Welcome to the most incredible game\n");
    printf("where you can become easily millionare\n");
    printf("------------------------------\n");
    printf("The rules are easy:\n");
    printf("Select a difficulty and a category\n");
    printf("Try to guess the secret word,\n");
    printf("by typing a letter at the time.\n");
    printf("------------------------------\n");
    printf("Get some of the highest scores\n"); 
    printf("to win a lot of money!!!! \n");
    printf("------------------------------\n");
}

/**
 * Method to display 
 * the game menu.
 */
void MenuCall(){
    //Declaring user option.
    char opt;
    //Declaring scores array.
    int scores[5] = {0, 0, 0, 0, 0};
    
    do{
        //Game menu.
        printf(">Press H for help on how to play\n");
        printf("\n");
        printf(">Press S to start the game\n");
        printf(">Press V to view the highest score\n");
        printf(">Press R to reset scores\n");
        printf(">Press Q to quit\n");
        
        //Asking user for option input.
        scanf(" %c", &opt);
        opt = tolower(opt);
        //Checking that the input is a valid option.
        while(opt != 's' && opt != 'v' && opt != 'r' && opt != 'h' && opt != 'q'){
            printf("Invalid option, please type a valid option\n");
            scanf(" %c", &opt);
            //Set opt to lowerCase
            opt = tolower(opt); 
        }

        if(opt == 's'){
            Start(&scores[0]);
        }
        else if(opt == 'v'){
            //Asking user whether to print and view or just view.
            printf("To Only View the scores press: V\n");
            printf("To View and Print the scores in .txt file press: P\n");
            char ScoreOptView;
            scanf(" %c", &ScoreOptView);
            ScoreOptView = tolower(ScoreOptView);
            while(ScoreOptView != 'v' && ScoreOptView != 'p'){
                printf("Invalid option, try again.\n");
                scanf(" %c", &ScoreOptView);
                ScoreOptView = tolower(ScoreOptView);
            }
            //Flag variable to know whether to print or not.
            int print = 0;
            if(ScoreOptView == 'p'){
                print = 1;
            }
            printf("------------------------------\n");
            //Calling function "PrintScores()" to print and view scores.
            //Using a pointer at element 0 of scores array.  
            PrintScores(&scores[0], print);
            printf("------------------------------\n");
        }
        else if(opt == 'r'){
            //Calling function "ResetScores()" to reset scores.
            //Using a pointer at element 0 of scores array.
            ResetScores(&scores[0]);
        }
        else if(opt == 'h'){
            //Calling function "Help()" of How to Play.
            Help();
        }
        else if(opt == 'q'){
            //Breaking the game loop if user wants to do so.
            break;
        }

    }while(opt != 'q');
    //Ending program message.
    printf("Game over\n");
}

int main(){
    //Presentation of game.
    printf("   C PROGRAM TRIVIA GAME\n");
    printf("------------------------------\n");
    printf("\t WELCOME\n"); 
    printf("\t   TO\n"); 
    printf("\t THE GAME\n");

    printf("------------------------------\n");
    printf("------------------------------\n");
    printf("  The game where you can\n"); 
    printf("  become a MILLIONARE!!!!!!");
    printf("\n");

    printf("------------------------------\n");
    printf("------------------------------\n");
    
    //Calling the menu option. 
    MenuCall();

    return 0;
}