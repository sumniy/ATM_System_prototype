

class Deposit{
  void deposit();
};

class deposit_account : public Deposit {

};

class deposit_no_book : public Deposit {
public:
  void deposit(DBserver* db, string acc, int m){
    int i=db->get_acc_loc(acc);
    db->a[i].money += m;
    return;
  }
};

class pay_due : public Deposit {

};

class Transfer{
public:
  int transfer(DBserver* db, string out, string in, int trans_money){
    int o, i;
    o = db->get_acc_loc(out);
    i = db->get_acc_loc(in);
    if(db->a[o].money<trans_money){
      return -1;
    }
    db->a[o].money -= trans_money;
    db->a[i].money += trans_money;
    return 0;
  }
};

class Exchange {
  void exchane(int money, int m_unit){
    int num;
    if(money%m_unit != 0) return;
    num = money/m_unit;

    // m_unit단위의 지폐로 num장 출금
  }
};
