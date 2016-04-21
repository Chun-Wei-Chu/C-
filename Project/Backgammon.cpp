/* 
名稱：五子棋(雙打) 15x15 
作者：阿蛇 
完成日期：2012年4月19日 
目前版本：1.0 
*/ 

#include<iostream> 
#include<string> 
using namespace std; 
short board[17][17]; 
bool endtry; 

void default_board();//初始化棋盤15x15 
void show_board();//顯示棋盤15x15 
void put_chess(short,short,short);//下棋+判斷有無棋子 
bool winner(short i,short j,short whosturn);//勝負 win = 1 勝利 
void multiplayer();//兩個玩家, 黑棋先下 
int main()//※ 主程式 ※ 
{ 
    cout <<"遊戲名稱：五子棋(雙打)"<< endl 
         <<"　　作者：阿蛇"<< endl 
         <<"　　版本：1.0"<< endl 
         << endl; 
    string choose; 
    system("pause"); 
    do{ 
       default_board(); 
       multiplayer(); 
       cout <<"輸入 y 再玩一次？："; 
       getline(cin,choose); 
    }while(choose == "y" || choose == "Y"); 
    return 0; 
} 
/* 
進度： 
20120417棋盤初始化完 
20120418可以下棋了, 重開局時有bug：多餘顯示「下棋的範圍超出格子外！」 
20120419修正 
*/ 
void default_board()//初始化棋盤15x15 
{ 
     for(int i=0 ;i<=16 ;i++){ 
        for(int j=0 ;j<=16 ;j++){ 
            if(i==0 && j==0){ 
                 board[i][j] = 0; 
            }else if(i==16 || j==16){ 
                 board[i][j] = 0; 
            }else if(i==0){ 
                 board[i][j] = j+30; 
            }else if(j==0){ 
                 board[i][j] = i+10; 
            }else if(i==1 && j==1){ 
                 board[i][j] = -7; 
            }else if(i==1 && j==15){ 
                 board[i][j] = -9; 
            }else if(i==15 && j==1){ 
                 board[i][j] = -1; 
            }else if(i==15 && j==15){ 
                 board[i][j] = -3; 
            }else if(i==1){ 
                 board[i][j] = -8; 
            }else if(j==1){ 
                 board[i][j] = -4; 
            }else if(j==15){ 
                 board[i][j] = -6; 
            }else if(i==15){ 
                 board[i][j] = -2; 
            }else{ 
                 board[i][j] = -5; 
            } 
        } 
     } 
} 
void show_board()//顯示棋盤15x15 
{ 
     for(int i=0 ;i<=16 ;i++){ 
           for(int j=0 ;j<=16 ;j++){ 
                 switch(board[i][j]){ 
                    case -1: 
                      cout << "└"; 
                      break; 
                    case -2: 
                      cout << "┴"; 
                      break; 
                    case -3: 
                      cout << "┘"; 
                      break; 
                    case -4: 
                      cout << "├"; 
                      break; 
                    case -5: 
                      cout << "┼"; 
                      break; 
                    case -6: 
                      cout << "┤"; 
                      break; 
                    case -7: 
                      cout << "┌"; 
                      break; 
                    case -8: 
                      cout << "┬"; 
                      break; 
                    case -9: 
                      cout << "┐"; 
                      break; 
                    case 0: 
                      cout << "　"; 
                      break; 
                    case 1: 
                      cout << "○"; 
                      break; 
                    case 2: 
                      cout << "●"; 
                      break; 
                    /*case 3: 
                      cout << "☆"; 
                      break; 
                    case 4: 
                      cout << "★"; 
                      break;*/ 
                    case 11: 
                      cout << "１"; 
                      break; 
                    case 12: 
                      cout << "２"; 
                      break; 
                    case 13: 
                      cout << "３"; 
                      break; 
                    case 14: 
                      cout << "４"; 
                      break; 
                    case 15: 
                      cout << "５"; 
                      break; 
                    case 16: 
                      cout << "６"; 
                      break; 
                    case 17: 
                      cout << "７"; 
                      break; 
                    case 18: 
                      cout << "８"; 
                      break; 
                    case 19: 
                      cout << "９"; 
                      break; 
                    case 20: 
                      cout << "10"; 
                      break; 
                    case 21: 
                      cout << "11"; 
                      break; 
                    case 22: 
                      cout << "12"; 
                      break; 
                    case 23: 
                      cout << "13"; 
                      break; 
                    case 24: 
                      cout << "14"; 
                      break; 
                    case 25: 
                      cout << "15"; 
                      break; 
                    case 31: 
                      cout << "Ａ"; 
                      break; 
                    case 32: 
                      cout << "Ｂ"; 
                      break; 
                    case 33: 
                      cout << "Ｃ"; 
                      break; 
                    case 34: 
                      cout << "Ｄ"; 
                      break; 
                    case 35: 
                      cout << "Ｅ"; 
                      break; 
                    case 36: 
                      cout << "Ｆ"; 
                      break; 
                    case 37: 
                      cout << "Ｇ"; 
                      break; 
                    case 38: 
                      cout << "Ｈ"; 
                      break; 
                    case 39: 
                      cout << "Ｉ"; 
                      break; 
                    case 40: 
                      cout << "Ｊ"; 
                      break; 
                    case 41: 
                      cout << "Ｋ"; 
                      break; 
                    case 42: 
                      cout << "Ｌ"; 
                      break; 
                    case 43: 
                      cout << "Ｍ"; 
                      break; 
                    case 44: 
                      cout << "Ｎ"; 
                      break; 
                    case 45: 
                      cout << "Ｏ"; 
                      break; 
                    
                 } 
           } 
           cout << endl; 
     } 
} 
void put_chess(short i,short j,short whosturn){//下棋+判斷有無棋子 
     if(i == 0 || i >= 16 || j == 0 || j >= 16){ 
        cout <<"下棋的範圍超出格子外！"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else if(board[i][j] == 1 || board[i][j] == 2){ 
        cout <<"此位置已經有棋子了！"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else{ 
        board[i][j] = whosturn; 
     } 
} 

bool winner(short i,short j,short whosturn){//勝負 win = 1 勝利 
   short count,tempi,tempj; 
   bool win = 0; 
   //←→ 
   count = 1; 
   tempi = i; 
   while(board[--tempi][j] == whosturn){count++;} 
   tempi = i; 
   while(board[++tempi][j] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↑↓ 
   count = 1; 
   tempj = j; 
   while(board[i][--tempj] == whosturn){count++;} 
   tempj = j; 
   while(board[i][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↖↘ 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[--tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[++tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↙↗ 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[++tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[--tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
winner_check_end: 
   return win; 
} 
void multiplayer(){//兩個玩家, 黑棋先下 
     string keyin; 
     short whosturn = 1,I,J; 
     system("cls"); 
     show_board(); 
nextstep: 
     I = 0; 
     J = 0; 
     endtry = 1; 
     system("cls"); 
     show_board(); 
     if(whosturn == 1){ 
          cout <<"○換黑子下："; 
     }else{ 
          cout <<"●換白子下："; 
     } 
     getline(cin,keyin); 
     for(int n=0 ;n<keyin.length() ;n++){//處理字串keyin 
        if(keyin[n]>='a' && keyin[n]<='o'){ 
           J = keyin[n] - 'a' + 1; 
        }else if(keyin[n]>='A' && keyin[n]<='O'){ 
           J = keyin[n] - 'A' + 1; 
        }else if(keyin[n]>='0' && keyin[n]<='9'){ 
           I = I*10 + keyin[n] - '0'; 
        }else if(keyin[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"輸入了不合法的字元！"<< endl; 
           system("pause"); 
           goto nextstep; 
        } 
     } 
     put_chess(I,J,whosturn); 
     if(endtry == 0){goto nextstep;} 
     endtry = winner(I,J,whosturn); 
     whosturn = (whosturn == 1? 2:1); 
     if(endtry == 0){goto nextstep;} 
     else{ 
        whosturn = (whosturn == 1? 2:1); 
        system("cls"); 
        show_board(); 
        if(whosturn == 1){cout <<"黑棋贏了！"<< endl;}else{cout <<"白棋贏了！"<< endl;} 
     } 
      
} 
