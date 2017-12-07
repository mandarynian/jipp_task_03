#include "game.h"

// konst
Game::Game()
{
  Init();
}
// dest
Game::~Game()
{
}
// init game properties
void Game::Init()
{
  m_nCurrentMoney = 0;
  m_nDelay = 70;
  m_nLevel = 10;
  m_nRandomOne = 0;
  m_nRandomTwo = 0;
  m_nRandomTree = 0;
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
  std::cout << "Rozpoczynanie losowania..." << std::endl << std::endl;
  Sleep(400);
  system("cls");
  srand (time(NULL));

  int nRand1 = 0, nRand2 = 0, nRand3 = 0;

  for (int i = 0;i < 70 ;i++)
  {
    if (i < 30)
      nRand1 = rand()%10;
    if (i < 50)
      nRand2 = rand()%10;  
    nRand3 = rand()%10;
    system("cls");
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    std::cout << "     " << nRand1 << "    " << nRand2 << "    " << nRand3 << std::endl;
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    Sleep(70);
  }

  system("pause");
  Menu();
}
