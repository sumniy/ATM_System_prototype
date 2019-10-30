#include<stdio.h>
#include<string>
#include<fstream>

using namespace std;

struct account;
class DBserver;

struct account {
  string name;
  int money;
  string account_id;
};

//singleton
class DBserver {
private:

public:
  struct account a[20];
  int acc_num = 3;

  DBserver(){
    ifstream in("account.txt");
    int num;
    in>>num;
    acc_num = num;
    for(int i=0;i<num;i++){
      in>>a[i].name;
      in>>a[i].money;
      in>>a[i].account_id;
    }
  }

  void save(){
    ofstream out("account.txt");
    out<<acc_num<<endl;
    for(int i=0;i<acc_num;i++){
      out<<a[i].name<<" ";
      out<<a[i].money<<" ";
      out<<a[i].account_id<<endl;
    }
  }

  bool check_account(string accid){
    bool check = false;
    for(int i=0; i<acc_num; i++){
      if(a[i].account_id == accid) check = true;
    }
    if(check==false) printf("일치하는 계좌가 없습니다.\n");
    return check;
  }

  account get_account(string accid){
    for(int i=0; i<acc_num;i++){
      if(a[i].account_id == accid) return a[i];
    }
  }
  void set_money(string accid, int m){
    int it=-1;
    for(int i=0; i<acc_num;i++){
      if(a[i].account_id == accid) it = i;
    }

    if(it!=-1){
      a[it].money = m;
    }
    else{printf("일치하는 계좌가 없습니다.\n");}
    return;
  }

  int get_acc_loc(string accid){
    int it=-1;
    for(int i=0; i<acc_num;i++){
      if(a[i].account_id == accid) it = i;
    }

    if(it==-1){
      printf("일치하는 계좌가 없습니다.\n");
      return -1;
    }
    else{
      return it;
    }
  }

  int get_money(int id){
    return a[id].money;
  }
};
