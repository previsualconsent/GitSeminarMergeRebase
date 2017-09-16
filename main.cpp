#include <iostream>
#include<limits>

int main (int argc, char *argv[])
{
   std::cout << "This is the hardest HIGH/LOW game ever!\n";
   std::cout << "Enter -1 to quit\n";
   std::cout << "I'm thinking of a integer between 1-100.\n";
   std::cout << "Can you guess it?\n";

   int n_guesses = 0;
   int min = 1;
   int max = 100;
   int guess;

   bool end = false;
   while(!end)
   {
      std::cout << "Guess my number(" << min << "-" << max << "): ";
      std::cin >> guess;
      while(1)
      {
         if(std::cin.fail())
         {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad Input\n";
            std::cout << "Guess my number(" << min << "-" << max << "): ";
            std::cin >> guess;
         }
         else if(guess == -1)
         {
            std::cout << "Exitting...\n";
            return 0;
         }
         else if(min > guess || max < guess)
         {
            std::cout << "Out of Range\n";
            std::cout << "Guess my number(" << min << "-" << max << "): ";
            std::cin >> guess;
         }

         if(!std::cin.fail() && min <= guess && guess <= max)
            break;
      }
      std::cout << "Guess is " << guess << std::endl;
      n_guesses++;

      if(min == max && guess == max)
      {
         std::cout << "You got it!\n";
         end == true;
      }
      else if( (guess - min) > (max - guess)) 
      {
         std:: cout << "Too High\n";
         max = guess - 1;
      }
      else
      {
         std:: cout << "Too Low\n";
         min = guess + 1;
      }
   }
   std::cout << "You guessed my number in " << n_guesses << "guesses\n";

}
