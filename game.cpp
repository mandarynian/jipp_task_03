#include "game.h"

// konst
Game::Game()
{
}
// dest
Game::~Game()
{
}
// menu gry 
void Game::Menu()
{
  system("cls");
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;
  std::cout << "    JEDNOREKI BANDYTA" << std::endl << std::endl;
  std::cout << "  1. Rzuc monete." << std::endl;
  std::cout << "  2. Pociagnij za raczke." << std::endl;
  std::cout << "  3. Wyswietl reguly." << std::endl;
  std::cout << "  4. Wyplac pieniadze." << std::endl;
  std::cout << "  5. Wyjscie z programu." << std::endl << std::endl;
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;
  char c;
  c = getch();
  switch (c)
  {
    case '1':
      Menu();
    break;
    case '2':
      Roll();
    break;
    case '3':
      ShowRules();
    break;
    case '4':
      GiveMeMyMoneyBack();
    break;
    case '5':
      exit(0);
    break;
    default:
      Menu();
    break;
  } 
}
// pokazuje zasady z pliku 
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
// wybiieramy pieniądze 
int Game::GiveMeMyMoneyBack()
{
  std::cout << "Wybierasz: " << m_nCurrentMoney << std::endl;
  return m_nCurrentMoney;
}
// metoda odpiowada za losowanie i wyswietlanie wyniku 
void Game::Roll()
{
  system("cls");
  // loading screan 
  std::cout << "Losowanie w toku..." << std::endl << std::endl;
  Sleep(400);
  system("cls");
  for (int i = 0;i < 100 ;i++)
  {
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    std::cout << "   " << i << "\t" << i << "\t" << i << std::endl;
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    Sleep(100);
    system("cls");
  }

  system("pause");
}
