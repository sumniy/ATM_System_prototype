#include<iostream>
using namespace std;

class Withdraw{
public:
  void withdraw();
};

// 현금 출금
class withdraw_cash{
public:
  int withdraw(DBserver* db, string acc, int m){
    int i=db->get_acc_loc(acc);

    if(db->a[i].money<m){
      return -1;
    }
    else db->a[i].money -= m;
    return 0;
  }
};

// 수표로 출금
class withdraw_check{
public:
  int withdraw(DBserver* db, string acc, int m){
    int i=db->get_acc_loc(acc);

    if(db->a[i].money<m){
      return -1;
    }
    else db->a[i].money -= m;
    return 0;
  }
};

// 신용카드 현금 서비스
class credit_cash_service{

};
