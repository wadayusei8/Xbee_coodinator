// 変数の定義
const int LEFT_BUTTON = 7;            //左移動ボタン
const int ROB1_FORWARD_BUTTON = 8;    //ロボット1前進ボタン
const int ROB1_BACK_BUTTON = 9;       //ロボット1後退ボタン
const int ROB2_FORWARD_BUTTON = 10;   //ロボット2前進ボタン
const int ROB2_BACK_BUTTON = 11;      //ロボット2後退ボタン
const int RIGHT_BUTTON = 12;           //右移動ボタン

//設定
void setup() {
  pinMode( LEFT_BUTTON, INPUT_PULLUP );
  pinMode( ROB1_FORWARD_BUTTON, INPUT_PULLUP );
  pinMode( ROB1_BACK_BUTTON, INPUT_PULLUP );
  pinMode( ROB2_FORWARD_BUTTON, INPUT_PULLUP );
  pinMode( ROB2_BACK_BUTTON, INPUT_PULLUP );
  pinMode( RIGHT_BUTTON, INPUT_PULLUP );
  Serial.begin( 9600 );
}

//メイン
void loop() {
  /*ボタンの状態をビットで表現する
    ボタンを押してないとき:1 ボタンを押している時:0
    D7 D8 D9 D10 D11 D12順にビット表示
    例)ロボット1前進ボタン(D8)を押しているとき　Button_state = 101111*/

  long int Button_state = 111111;
  Button_state = 100000 * digitalRead( LEFT_BUTTON ) + 10000 * digitalRead( ROB1_FORWARD_BUTTON )
                 +  1000 * digitalRead( ROB1_BACK_BUTTON ) + 100 * digitalRead( ROB2_FORWARD_BUTTON )
                 +  10 * digitalRead( ROB2_BACK_BUTTON ) + digitalRead( RIGHT_BUTTON );
  // Serial.println(Button_state);

  switch (Button_state) {
    case 101011:   //2台とも前進
      Serial.write('1');
      delay(10);
      break;
    case 110101:   //2台とも後退
      Serial.write('2');
      delay(10);
      break;
    case 101101:   //1前進2後退
      Serial.write('3');
      delay(10);
      break;
    case 110011:   //1後退2前進
      Serial.write('4');
      delay(10);
      break;
    case 101111:   //ロボット1前進
      Serial.write('f');
      delay(10);
      break;
    case 110111:   //ロボット1後退
      Serial.write('b');
      delay(10);
      break;
    case 111011:   //ロボット2前進
      Serial.write('F');
      delay(10);
      break;
    case 111101:   //ロボット2後退
      Serial.write('B');
      delay(10);
      break;
    case 11111:   //左移動
      Serial.write('l');
      delay(10);
      break;
    case 111110:   //右移動
      Serial.write('r');
      delay(10);
      break;
    default:
      break;
  }
}
