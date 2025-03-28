#include <Arduino.h>
#include <M5Core2.h>

// 円の構造体
struct Circle {
  float x;        // 中心のX座標
  float y;        // 中心のY座標
  float radius;   // 半径
  uint32_t color; // 色
  bool active;    // アクティブかどうか
};

// 円のインスタンス
Circle circle;

// 画面の幅と高さ
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;

// 円の拡大速度
const float GROWTH_RATE = 2.0;

// 最大半径（画面の対角線の長さより少し大きく）
const float MAX_RADIUS = sqrt(SCREEN_WIDTH * SCREEN_WIDTH + SCREEN_HEIGHT * SCREEN_HEIGHT) / 1.5;

// スプライト（ダブルバッファリング用）
TFT_eSprite sprite = TFT_eSprite(&M5.Lcd);

void setup() {
  // M5Stack初期化
  M5.begin();
  
  // スプライトの初期化
  sprite.createSprite(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite.fillSprite(BLACK);
  sprite.setTextColor(WHITE);
  sprite.setTextSize(2);
  sprite.setCursor(20, 110);
  sprite.println("Touch the screen to start");
  sprite.pushSprite(0, 0);
  
  // 円を非アクティブに設定
  circle.active = false;
}

void loop() {
  // タッチ入力の更新
  M5.update();
  
  // タッチイベントの検出
  if (M5.Touch.ispressed() && !circle.active) {
    TouchPoint_t pos = M5.Touch.getPressPoint();
    
    // 円を初期化
    circle.x = pos.x;
    circle.y = pos.y;
    circle.radius = 0;
    // ランダムな色を生成 (RGB)
    circle.color = sprite.color565(
      random(256),  // R (0-255)
      random(256),  // G (0-255)
      random(256)   // B (0-255)
    );
    circle.active = true;
    
    // スプライトをクリア
    sprite.fillSprite(BLACK);
    sprite.pushSprite(0, 0);
  }
  
  // アクティブな円を拡大して描画
  if (circle.active) {
    // スプライトをクリア
    sprite.fillSprite(BLACK);
    
    // 半径を増加
    circle.radius += GROWTH_RATE;
    
    // 新しい円をスプライトに描画
    sprite.fillCircle(circle.x, circle.y, circle.radius, circle.color);
    
    // スプライトを画面に表示
    sprite.pushSprite(0, 0);
    
    // 円が画面を埋め尽くしたかチェック
    if (circle.radius >= MAX_RADIUS) {
      // 少し待機
      delay(500);
      
      // スプライトをクリアして初期状態に戻す
      sprite.fillSprite(BLACK);
      sprite.setTextColor(WHITE);
      sprite.setTextSize(2);
      sprite.setCursor(20, 110);
      sprite.println("Touch the screen to start");
      sprite.pushSprite(0, 0);
      
      // 円を非アクティブに設定
      circle.active = false;
    }
  }
  
  // 少し待機して CPU 負荷を下げる
  delay(10);
}
