#include "game.h"

#include <windows.h>
#include <conio.h>
#include <stdlib.h>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Menu()
{
  system("cls");
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;
  std::cout << "    JEDNOREKI BANDYTA" << std::endl << std::endl;
  std::cout << "  1. Start." << std::endl;
  std::cout << "  2. Rzuc monete." << std::endl;
  std::cout << "  3. Pociagnij za raczke." << std::endl;
  std::cout << "  4. Wyswietl reguly." << std::endl;
  std::cout << "  5. Wyplac pieniadze." << std::endl;
  std::cout << "  6. Wyjscie z programu." << std::endl << std::endl;
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;
  char c;
  c = getch();
  switch (c)
  {
    case '1':
      Menu();
    break;
    case '2':
      Menu();
    break;
    case '3':
      Menu();
    break;
    case '4':
      ShowRules();
    break;
    case '5':
      Menu();
    break;
    case '6':
      exit(0);
    break;
    default:
      Menu();
    break;
  } 
}

void Game::ShowRules()
{
  system("cls");
  std::ifstream m_hFileRules("rules.txt");
  if (m_hFileRules) 
  {
    std::streambuf * pbuf = m_hFileRules.rdbuf();
    do 
    {
      char ch = pbuf->sgetc();
      std::cout << ch;
    } while ( pbuf->snextc() != EOF );

    m_hFileRules.close();
  }
  else 
    std::cout << "Nie udalo sie otworzyc zasad.\n";
  system("pause");
  Menu();
}
