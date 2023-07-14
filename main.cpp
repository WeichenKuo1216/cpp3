#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


// Function prototypes
void playHangman();
bool isGuessCorrect(const std::string& word, char guess, std::string& guessedWord);
bool isGameOver(const std::string& word, const std::string& guessedWord, int attempts);
bool playAgain();

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Game loop
    do {
        playHangman();
    } while (playAgain());

    return 0;
}

void playHangman() {
    // Words to be guessed
    std::vector<std::string> words = {
        "apple",
        "banana",
        "cherry",
        "durian",
        "elderberry",
        "fig",
        "grape",
        "honeydew",
        "indigo",
        "jackfruit"
    };

    // Select a random word from the list
    std::string word = words[std::rand() % words.size()];
    int wordLength = word.length();

    // Initialize the guessed word with underscores
    std::string guessedWord(wordLength, '_');

    // Track the guessed letters
    std::string guessedLetters;

    // Number of attempts
    int attempts = 6;

    // Game loop
    while (true) {
        std::cout << "Word: " << guessedWord << std::endl;
        std::cout << "Guessed letters: " << guessedLetters << std::endl;
        std::cout << "Remaining attempts: " << attempts << std::endl;

        // Get a letter guess from the player
        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        // Check if the guess is correct
        if (isGuessCorrect(word, guess, guessedWord)) {
            std::cout << "Correct guess!" << std::endl;
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            attempts--;
        }

        // Add the guessed letter to the list
        guessedLetters += guess;

        // Check if the game is over
        if (isGameOver(word, guessedWord, attempts)) {
            if (guessedWord == word) {
                std::cout << "Congratulations! You guessed the word correctly: " << word << std::endl;
            } else {
                std::cout << "Game over! The word was: " << word << std::endl;
            }
            break;
        }
    }
}

bool isGuessCorrect(const std::string& word, char guess, std::string& guessedWord) {
    bool correctGuess = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
            correctGuess = true;
        }
    }
    return correctGuess;
}

bool isGameOver(const std::string& word, const std::string& guessedWord, int attempts) {
    return guessedWord == word || attempts <= 0;
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

