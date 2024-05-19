#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Printing welcome statement to the terminal   
    std::cout << "\n\nWelcome hacker, you are on a mission to break into a secure server room! \n< LEVEL > " << Difficulty << std::endl;
    std::cout << " \nYou will need to enter the codes to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declaring 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done hacker. You extracted a file! KEEP GOING! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** Thats the wrong code... CAREFULL hacker... TRY AGAIN! ***";
        return false;
    }

}

int main()
{
    srand(time(NULL)); // Create a new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** GREAT JOB Hacker! You got all the files! Now get out of there! ***";
    return 0;
}