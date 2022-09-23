# Convolustionレイヤの実装
class Convolution:

    # インスタンス変数の定義
    def __init__(self, W, b, stride=1, pad=0):
        self.W = W  # フィルタ（重み）
        self.b = b  # バイアス
        self.stride = stride  # ストライド
        self.pad = pad  # パディング

        # (逆伝播時に使用する)中間データを初期化
        self.x = None  # 入力データ
        self.col = None  # 二次元配列に展開した入力データ
        self.col_W = None  # 二次元配列に展開したフィルタ

        # 勾配に関する変数を初期化
        self.dW = None  # フィルタに関する勾配
        self.db = None  # バイアスに関する勾配

    # 準伝播メソッドの定義
    def forward(self, x):
        # 各データに関するサイズを取得
        FN, C, FH, FM = self.W.shape  # フィルタ
        N, C, H, W = x.shape  # 入力データ
        out_h = int(1 + (H + 2 * self.pad - FH)) / self.stride)  # 出力データ
        out_w = int(1 + (W + 2 * self.pad - FW)) / self.stride)  # 出力データ

        # 各データを二次元配列に展開
        col = im2col(x, FH, FW, self.stride, self.pad)  # 入力データ
