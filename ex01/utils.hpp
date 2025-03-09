#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace ErrorMessage {
    extern const std::string EMPTY_FIELD;
    extern const std::string INVALID_PHONE_FORMAT;
    extern const std::string INVALID_COMMAND;
    extern const std::string INPUT_TERMINATED;
}

// 入力を取得し、EOFまたは空文字列の場合はプログラムを終了
std::string getInputOrExit(const std::string &prompt);

// 電話番号のバリデーション
bool isValidPhoneNumber(const std::string &number);

// 入力が有効な数値かどうかチェックする関数
bool isValidNumber(const std::string &str);

#endif
