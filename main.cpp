#include <iostream>
#include <ctime>

void PrintHeader() {
  std::cout << std::endl;
  std::cout << "Welcom to TripleX game! Find the correct code to go to the next level\n";
  std::cout << "Here is the input format example: '4 7 6<enter>'\n";
}

void PrintFinalGuessCode(int Difficulty, int CodeSum, int CodeMultiply) {
  std::cout << "Difficulty is: "<< Difficulty << std::endl;
  std::cout << "The codes add up to: "<< CodeSum << std::endl;
  std::cout << "The codes multiply to give: "<< CodeMultiply << std::endl;
  std::cout << "Enter your codes: ";
}

bool PlayAndGuess(int Difficulty) {
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeMultiply = CodeA * CodeB * CodeC;

  PrintFinalGuessCode(Difficulty, CodeSum, CodeMultiply);

  int GuessA, GuessB, GuessC;

  std::cin >> GuessA >> GuessB >> GuessC;

  std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessMultiply = GuessA * GuessB * GuessC;

  if (GuessSum == CodeSum && GuessMultiply == CodeMultiply) {
    std::cout << "> Good Job you got it!\n\n";
    return true;
  }

  std::cout << "> Wrong!\n\n";

  return false;
}

int main()
{
  srand(time(NULL));
  PrintHeader();

  int Difficulty = 2;
  int MaxDifficulty = 10;

  while (Difficulty < MaxDifficulty) {
    if (PlayAndGuess(Difficulty)) {
      ++Difficulty;
    }

    std::cin.clear();
    std::cin.ignore();
  }

  std::cout << "> Good JOB! You've completed the game!\n";

  return 0;
}
