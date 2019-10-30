extern DBserver test;
extern Log logfile;
extern bool is_error;

class Transaction {
  struct account b[20];
  int acc_num; // db_server의 attribute
public:
  void rollback(){
    save_acc();
  }
  
  void trade_success(string trade){
    test.save();
    logfile.add_log(trade, __TIMESTAMP__);
    logfile.save_log();
  }

  string create_trade(int state){
    string trade;
    switch(state){
      case 1 : trade = "예금출금"; break;
      case 2 : trade = "입금/무통장입금"; break;
      case 3 : trade = "계좌이체"; break;
      case 4 : trade = "통장정리"; break;
      case 5 : trade = "예금조회"; break;
      case 6 : trade = "신용카드_현금서비스"; break;
      case 7 : trade = "지폐교환"; break;
      case 11 : trade = "예금출금_실패"; break;
      case 22 : trade = "입금_실패"; break;
      case 33 : trade = "계좌이체_실패"; break;
      case 44 : trade = "통장정리_실패"; break;
      case 55 : trade = "예금조회_실패"; break;
      case 66 : trade = "신용카드_현금서비스 실패"; break;
      case 77 : trade = "지폐교환_실패"; break;
      default : break;
    }
    return trade;
  }

  void make_temp(){
    load_acc();
  }

  void all_trade(int state){

    string trade = create_trade(state);

    if(is_error==true){
      rollback();
    }
    else if(is_error==false){
      trade_success(trade);
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
