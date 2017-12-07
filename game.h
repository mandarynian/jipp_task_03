// jednoręki bandyta - gra 

class Game
{
public:
  Game(int = 0);
  ~Game();

  //void Menu();
  
  int GiveMeMyMoneyBack();
  void Roll();  
  bool BuyTicket();
  void AddCoin(int);
  bool CheckCoin();


  void SetRandOne(int);
  void SetRandTwo(int);
  void SetRandThre(int);


private:
  int m_nCurrentMoney;            // odpowiada za przechowywanie inf. o obecnym stanie portwela gracza 
};

void Menu();
void ShowRules();
