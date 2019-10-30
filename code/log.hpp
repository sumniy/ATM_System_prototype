struct logdata{
  string trade;
  string date;
  int logcount;
};

class Log {
public:
  int count;
  logdata log_[1024];


  Log(){
    ifstream in("log.txt");
    int num;
    in>>num;
    count = num;
    for(int i=0;i<num;i++){
      in>>log_[i].trade;
      for(int j=0;j<5;j++){
        string temp;
        in>>temp;
        log_[i].date += temp;
        if(j<4) log_[i].date += " ";
      }
      in>>log_[i].logcount;
    }
  }

  void save_log(){
    ofstream out("log.txt");
    out<<count<<endl;
    for(int i=0;i<count;i++){
      out<<log_[i].trade<<" ";
      out<<log_[i].date<<" ";
      out<<log_[i].logcount<<endl;
    }
  }

  void add_log(string t, string d){
    log_[count].trade = t;
    log_[count].date = d;
    log_[count].logcount = count;
    count++;
  }
  string get_trade(int c){
    return log_[c].trade;
  }
  string get_date(int c){
    return log_[c].date;
  }
  int get_count(int c){
    return log_[c].logcount;
  }


  void print_log(int c){
    cout<<"log: "<<log_[c].trade<<", date: "<<log_[c].date<<", lognum: "<<log_[c].logcount<<endl;
  }
};
