#include "game.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

/////////////////////
// METODY KLASY GAME 
////
Game::Game(int nCoin, int nDiff) : m_nCurrentMoney(nCoin), m_nDifficultyLevel(nDiff)
{}
//---------------------------------------------------------------------------------
Game::~Game()
{
}
//---------------------------------------------------------------------------------
int Game::GiveMeMyMoneyBack()
{
  system("cls");
  std::cout << "Wybierasz: " << m_nCurrentMoney << std::endl;
  if (m_nCurrentMoney > 0)
  {
    std::cout << "Wyplacasz: " << m_nCurrentMoney << " PLN!" << std::endl;
    system("pause");
    return m_nCurrentMoney;
  } 

  return 0;
}
//---------------------------------------------------------------------------------
void Game::ResetMoney()
{
  m_nCurrentMoney = 0;
}
//---------------------------------------------------------------------------------
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
      nRand1 = rand()%(m_nDifficultyLevel/10);
    if (i < 50)
      nRand2 = rand()%(m_nDifficultyLevel/10);  
    nRand3 = rand()%(m_nDifficultyLevel/10);
    system("cls");
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    std::cout << "     " << nRand1 << "    " << nRand2 << "    " << nRand3 << std::endl;
    std::cout << "= = = = = = = = = = = = = = =" << std::endl;
    Sleep(50);
  }
//---------------------------------------------------------------------------------
  if (nRand1 == nRand2 || nRand1 == nRand3 || nRand2 == nRand3)
  {
    std::cout << "Trafiony.\n";
    m_nCurrentMoney += 5;
  }
  
  if (nRand1 == nRand2 && nRand1 == nRand3)
  {
    std::cout << "PODWOJENIE!!";
    m_nCurrentMoney = m_nCurrentMoney *2;
  }  
  system("pause");
  return;
}
//---------------------------------------------------------------------------------
bool Game::BuyTicket()
{
  if (m_nCurrentMoney < 2)
    return false;  
  
  m_nCurrentMoney -= 2;
  return true;
}
//---------------------------------------------------------------------------------
bool Game::GetCoin()
{
  if (m_nCurrentMoney < 2)
    return false;  
  
  m_nCurrentMoney -= 2;
  return true;
}
//---------------------------------------------------------------------------------
void Game::AddCoin()
{ 
  char c;
  system("cls");
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;
  std::cout << " Posiadasz: " << m_nCurrentMoney << " PLN." << std::endl << std::endl;
  std::cout << "  1. Wrzuc 1 PLN." << std::endl;
  std::cout << "  2. Wrzuc 2 PLN." << std::endl;
  std::cout << "  3. Wrzuc 5 PLN." << std::endl;
  std::cout << "  4. Wstecz." << std::endl << std::endl;
  std::cout << "= = = = = = = = = = = = = = =" << std::endl;

  c = getch();

  switch (c)
  {
    case '1':
    m_nCurrentMoney += 1;
    break;
    case '2':
    m_nCurrentMoney += 2;
    break;
    case '3':
    m_nCurrentMoney += 5;
    break;
    default:break;
  }

}
//---------------------------------------------------------------------------------
int Game::GetMoneyState()
{
  return m_nCurrentMoney;
}
//---------------------------------------------------------------------------------

/////////////////////
// FUNCKJE AUTOMATU
////
void Menu()
{
  Game *GamePlayer;
  GamePlayer = new Game();

  for (;;)
  {
    system("cls");
    std::cout << "= = = = = = = = = = = = = =" << std::endl;
    std::cout << "    JEDNOREKI BANDYTA" << std::endl << std::endl;
    std::cout << "  1. Wrzuc monete." << std::endl;
    std::cout << "  2. Pociagnij za raczke." << std::endl;
    std::cout << "  3. Wyswietl reguly." << std::endl;
    std::cout << "  4. Wyplac pieniadze." << std::endl;
    std::cout << "  5. Exit." << std::endl << std::endl;
    std::cout << "    Stan konta: " << GamePlayer->GetMoneyState() << " PLN." << std::endl;
    std::cout << "= = = = = = = = = = = = = =" << std::endl;
    char c;
    c = getch();
    switch (c)
    {
      case '1':
      GamePlayer->AddCoin();
      break;
      case '2':
      if(GamePlayer->GetCoin())
        GamePlayer->Roll();
      else std::cout << "Wrzuc monete.\n";
      break;
      case '3':
      ShowRules();
      break;
      case '4':
      GamePlayer->GiveMeMyMoneyBack();
      GamePlayer->ResetMoney();
      break;
      case '5':
        exit(0);
      break;
      default:
      break;
    }
  }
   
}
//---------------------------------------------------------------------------------
void ShowRules()
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
//---------------------------------------------------------------------------------