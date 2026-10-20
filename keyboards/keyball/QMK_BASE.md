# ベースにした QMK のバージョン

Keyball (https://github.com/Yowkees/keyball) を、本家 QMK (https://github.com/qmk/qmk_firmware) の
下記バージョンに移植・修正して使っている。本家 QMK には手を入れていない (更新もしない)。

| 項目 | 内容 |
|---|---|
| ベースの QMK | 0.34.6 の 1コミット後 (`git describe`: `0.34.6-1-g7a1bbf37c5`) |
| コミット | `7a1bbf37c5c07da4ea0a162bb139083a46ef40a1` (2026-10-02, "Add support for mini_mighty/kbd (#25878)") |
| 本家から取得した日 | 2026-10-11 (`git pull --tags origin master`) |
| Keyball を移植した日 | 2026-10-13 |
| QMK の置き場所 | `/Users/zoe_family/keyboard/qmk_firmware` (移植した Keyball は `keyboards/keyball/`) |
| 確認方法 | `cd /Users/zoe_family/keyboard/qmk_firmware && git describe --tags` |

QMK を更新するときは、上のコミットとの差分 (特にキーボード定義の書き方や API の変更) を確認してから取り込むこと。
