// jednoręki bandyta - gra 

class Game
{
public:
  Game(int = 0, int = 99);
  ~Game();
  
  int GiveMeMyMoneyBack();
  void Roll();  
  bool BuyTicket();
  void AddCoin();
  bool GetCoin();
  int GetMoneyState();
  void ResetMoney();

private:
  int m_nCurrentMoney;            // odpowiada za przechowywanie inf. o obecnym stanie portwela gracza 
  int m_nDifficultyLevel;         // poziom trudności 
};

void Menu();
void ShowRules();
