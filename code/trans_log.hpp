extern Log logf;

class Transaction {
  struct account b[20];
  int acc_num; // db_server의 attribute
public:
  void rollback(){}
  void trade_success(string trade){
    test.save();
    logf.add_log(trade, __TIMESTAMP__, )
  }

  string create_trade(int state){
    string trade;
    switch(state){
      case 1 : trade = "예금출금"; break;
      case 2 : trade = "입금/무통장입금"; break;
      case 3 : trade = "계좌이체"; break;
      case 4 : trade = "통장정리"; break;
      case 5 : trade = "예금조회"; break;
      case 6 : trade = "신용카드 현금서비스"; break;
      case 7 : trade = "지폐교환"; break;
      default : break;
    }
    return trade;
  }

  void all_trade(int state){

    load_acc();

    string trade = create_trade(state);

    if(is_error==true){
      rollback();
    }
    else if(is_error==false){
      trade_success();
    }



  }

  void load_acc(){
    ifstream in("account.txt");
    int num;
    in>>num;
    for(int i=0;i<num;i++){
      in>>b[i].name;
      in>>b[i].money;
      in>>b[i].account_id;
    }
  }

  void save_acc(){
    ofstream out("account.txt");
    out<<acc_num<<endl;
    for(int i=0;i<acc_num;i++){
      out<<b[i].name<<" ";
      out<<b[i].money<<" ";
      out<<b[i].account_id<<endl;
    }
  }

};
