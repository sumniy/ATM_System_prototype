#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern DBserver test;
extern withdraw_cash wc;
extern deposit_no_book nb;
extern Transfer trans;
extern Transaction ta;
extern bool is_error;

class Menu {
public:
  string language;
  int displaystate;
  char buf[100];
  Menu(){
    language = "korean";
    displaystate = 0; // main display
  }
  void display(){
    if(displaystate == 0){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"메뉴를 선택하세요."<<endl<<endl;
      cout<<"1. 예 금 출 금"<<endl;
      cout<<"2. 입금 / 무통장 입금"<<endl;
      cout<<"3. 계 좌 이 체"<<endl;
      cout<<"4. 통 장 정 리"<<endl;
      cout<<"5. 예 금 조 회"<<endl;
      cout<<"6. 신용카드 현금 서비스"<<endl;
      cout<<"7. 지폐 교환"<<endl;
      cout<<"8. 언어 선택"<<endl;
      cout<<"9. 종 료"<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      int a;
      scanf("%d", &a);

      displaystate = a;
      display();
    }
    else if(displaystate == 1){
      // 카드나 통장을 삽입대신 계좌 id 입력하기
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"계좌번호를 입력한 후 출금할 금액을 입력하세요."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;

      ta.make_temp();

      string id;
      int mon;
      scanf("%s", buf);
      id = buf;

      int accid, before;
      accid = test.get_acc_loc(id);
      before = test.get_money(accid);

      scanf("%d", &mon);
      if(wc.withdraw(&test, id, mon)==-1){
        cout<<endl<<"*********************************************"<<endl<<endl;
        cout<<"잔고가 부족합니다. 아무 숫자키를 입력하면 다시 금액 선택화면으로 돌아갑니다."<<endl<<endl;
        cout<<endl<<"*********************************************"<<endl<<endl;

        ta.all_trade(11);

        int dummy;
        scanf("%d", &dummy);
        display();
      }
      else{
        cout<<endl<<"*********************************************"<<endl<<endl;
        cout<<"출금이 완료되었습니다. 아무 숫자키를 입력하면 메인 화면으로 돌아갑니다."<<endl<<endl;
        cout<<"name : "<<test.a[accid].name<<", money : "<<before<<" -> "
        <<test.a[accid].money<<", id : "<<test.a[accid].account_id<<endl<<endl;
        cout<<endl<<"*********************************************"<<endl<<endl;
        ta.all_trade(displaystate);
        displaystate = 0;
        int dummy;
        scanf("%d", &dummy);
        display();
      }
    }
    else if(displaystate == 2){
      //atm기에 돈을 넣는 대신 금액을 입력하는 것
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"계좌번호를 입력한 후 입금할 금액을 입력하세요."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;

      ta.make_temp();

      string id;
      int mon;
      scanf("%s", buf);
      id = buf;
      for(int i=0;i<100;i++) buf[i]='\0';

      int accid, before;

      accid = test.get_acc_loc(id);
      before = test.get_money(accid);

      scanf("%d", &mon);

      nb.deposit(&test, id, mon);

      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"입금이 완료되었습니다. 아무 숫자키를 입력하면 메인 화면으로 돌아갑니다."<<endl<<endl;
      cout<<"name : "<<test.a[accid].name<<", money : "<<before<<" -> "
      <<test.a[accid].money<<", id : "<<test.a[accid].account_id<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;

      if(is_error==true) ta.all_trade(22);
      else ta.all_trade(displaystate);
      displaystate = 0;
      int dummy;
      scanf("%d", &dummy);
      display();
    }
    else if(displaystate == 3){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"(출금계좌번호) (입금계좌번호) (이체할 금액) 순으로 입력하세요."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;

      ta.make_temp();

      string outid, inid;
      int mon;
      scanf("%s", buf);
      outid = buf;
      scanf("%s", buf);
      inid = buf;
      scanf("%d", &mon);

      int oid, iid, before;

      oid = test.get_acc_loc(outid);
      iid = test.get_acc_loc(inid);
      before = test.get_money(oid);

      if(trans.transfer(&test, outid, inid, mon)==-1){
        cout<<endl<<"*********************************************"<<endl<<endl;
        cout<<"잔고가 부족합니다. 아무 숫자키를 입력하면 다시 이체 선택화면으로 돌아갑니다."<<endl<<endl;
        cout<<endl<<"*********************************************"<<endl<<endl;
        ta.all_trade(33);
        int dummy;
        scanf("%d", &dummy);
        display();
      }
      else{
        cout<<endl<<"*********************************************"<<endl<<endl;
        cout<<"name : "<<test.a[iid].name<<", id : "<<test.a[iid].account_id<<endl<<endl;
        cout<<"위 계좌로 이체가 완료되었습니다. 아무 숫자키를 입력하면 메인 화면으로 돌아갑니다."<<endl<<endl;
        cout<<"name : "<<test.a[oid].name<<", money : "<<before<<" -> "
        <<test.a[oid].money<<", id : "<<test.a[oid].account_id<<endl<<endl;
        cout<<endl<<"*********************************************"<<endl<<endl;
        ta.all_trade(displaystate);
        displaystate = 0;
        int dummy;
        scanf("%d", &dummy);
        display();
      }
    }
    else if(displaystate == 4){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"미구현 기능입니다. 2초뒤 메인화면으로 돌아갑니다."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      displaystate = 0;
      usleep(2000000);
      display();
    }
    else if(displaystate == 5){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"조회할 계좌번호를 입력하세요."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;

      string id;
      int mon;
      scanf("%s", buf);
      id = buf;
      for(int i=0;i<100;i++) buf[i]='\0';

      int accid, balance;

      accid = test.get_acc_loc(id);


      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"현재 계좌 정보입니다. 아무 숫자키를 입력하면 메인화면으로 돌아갑니다."<<endl<<endl;
      cout<<"name : "<<test.a[accid].name<<", money : "
      <<test.a[accid].money<<", id : "<<test.a[accid].account_id<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      if(is_error==true) ta.all_trade(55);
      else ta.all_trade(displaystate);
      displaystate = 0;
      int dummy;
      scanf("%d", &dummy);
      display();
    }
    else if(displaystate == 6){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"미구현 기능입니다. 2초뒤 메인화면으로 돌아갑니다."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      displaystate = 0;
      usleep(2000000);
      display();
    }
    else if(displaystate == 7){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"미구현 기능입니다. 2초뒤 메인화면으로 돌아갑니다."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      displaystate = 0;
      usleep(2000000);
      display();
    }
    else if(displaystate == 8){
      cout<<endl<<"*********************************************"<<endl<<endl;
      cout<<"미구현 기능입니다. 2초뒤 메인화면으로 돌아갑니다."<<endl<<endl;
      cout<<endl<<"*********************************************"<<endl<<endl;
      displaystate = 0;
      usleep(2000000);
      display();
    }
    else if(displaystate == 9){
      test.~DBserver();
      return;
    }
  }
};
