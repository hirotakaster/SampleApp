# SampleApp for M5Stack Core2

M5Stack Core2向けのインタラクティブなタッチアプリケーションです。画面をタッチすると、タッチした場所に円が表示され、時間経過とともに拡大していきます。

## 機能

- 画面のタッチ位置に円を表示
- 時間経過とともに円が拡大
- 円はランダムな色で塗りつぶされる
- 画面が埋め尽くされると初期状態に戻る

## デモ

![デモ画像](docs/demo.gif)

※実際のデモ画像はM5Stack Core2デバイスで実行時に追加してください。

## 必要な環境

- [Arduino IDE](https://www.arduino.cc/en/software)
- [M5Stack Core2](https://shop.m5stack.com/products/m5stack-core2-esp32-iot-development-kit)
- [M5Core2ライブラリ](https://github.com/m5stack/M5Core2)
- [ESP32ボード定義](https://github.com/espressif/arduino-esp32)

## インストール方法

### Arduino IDEを使用する場合

1. このリポジトリをクローン
   ```
   git clone https://github.com/hirotakaster/SampleApp.git
   ```

2. Arduino IDEをインストール
   - [Arduino IDE](https://www.arduino.cc/en/software)からダウンロードしてインストール

3. ESP32ボード定義をインストール
   - ファイル > 環境設定 > 追加のボードマネージャのURL に以下を追加:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - ツール > ボード > ボードマネージャ から「esp32」を検索してインストール

4. M5Core2ライブラリをインストール
   - スケッチ > ライブラリをインクルード > ライブラリを管理 から「M5Core2」を検索してインストール

5. Arduino IDEでSampleApp.inoを開く

6. ボードの設定
   - ツール > ボード > ESP32 Arduino > M5Stack-Core2 を選択
   - ツール > ポート から接続されているM5Stack Core2のポートを選択

7. スケッチをアップロード
   - スケッチ > アップロード をクリック

## 使用方法

1. アプリケーションが起動すると、「Touch the screen to start」というメッセージが表示されます
2. 画面をタッチすると、タッチした場所に円が表示されます
3. 円は時間経過とともに拡大し、画面を埋め尽くします
4. 画面が埋め尽くされると、初期状態に戻ります

## ライセンス

[MIT](LICENSE)
