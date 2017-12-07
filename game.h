// jednoręki bandyta - gra 

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

class Game
{
  public:
    Game();
    ~Game();

    void Init();
    void Menu();
    void Roll();
    int GiveMeMyMoneyBack();
   // void NextSte();
    void ShowRules();
  //  void WitherMoney();


  private:
  int m_nCurrentMoney; // odpowiada za przechowywanie inf. o obecnym stanie portwela gracza 
  int m_nDelay;
  int m_nLevel;

  int m_nRandomOne;
  int m_nRandomTwo;
  int m_nRandomTree;
};