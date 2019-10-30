#include "db_server.hpp"
#include "deposit.hpp"
#include "withdraw.hpp"
#include "log.hpp"
#include "transaction.hpp"
#include "menu.hpp"



#include <iostream>

class Menu;

bool is_error = false;

DBserver test;
Transfer trans;
deposit_no_book nb;
withdraw_cash wc;
Menu menu_;
Log logfile;
Transaction ta;

int main(){

  menu_.display();

  return 0;
}
