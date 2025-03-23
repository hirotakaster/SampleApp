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

- [PlatformIO](https://platformio.org/) または [Arduino IDE](https://www.arduino.cc/en/software)
- [M5Stack Core2](https://shop.m5stack.com/products/m5stack-core2-esp32-iot-development-kit)
- [M5Core2ライブラリ](https://github.com/m5stack/M5Core2)

## インストール方法

### PlatformIOを使用する場合

1. このリポジトリをクローン
   ```
   git clone https://github.com/hirotakaster/SampleApp.git
   ```

2. PlatformIOでプロジェクトを開く

3. ビルドしてM5Stack Core2にアップロード
   ```
   platformio run --target upload
   ```

### Arduino IDEを使用する場合

1. このリポジトリをクローン
   ```
   git clone https://github.com/hirotakaster/SampleApp.git
   ```

2. Arduino IDEでSampleApp.inoを開く

3. M5Core2ライブラリをインストール
   - スケッチ > ライブラリをインクルード > ライブラリを管理 から「M5Core2」を検索してインストール

4. M5Stack Core2をUSBで接続し、ボードとポートを選択

5. スケッチをアップロード

## 使用方法

1. アプリケーションが起動すると、「Touch the screen to start」というメッセージが表示されます
2. 画面をタッチすると、タッチした場所に円が表示されます
3. 円は時間経過とともに拡大し、画面を埋め尽くします
4. 画面が埋め尽くされると、初期状態に戻ります

## ライセンス

[MIT](LICENSE)
