// jednoręki bandyta - gra 

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

class Game
{
  public:
    Game();
    ~Game();

    void Menu();
  //  void GeneratedResult();
  //  void GetTheMoney(int &);
   // void NextSte();
    void ShowRules();
  //  void WitherMoney();


  private:
  int m_nCurrentMoney; // odpowiada za przechowywanie inf. o obecnym stanie portwela gracza 
};