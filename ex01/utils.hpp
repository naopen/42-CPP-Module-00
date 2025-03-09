#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace ErrorMessage {
    const std::string EMPTY_FIELD = "Field cannot be empty. Please try again.";
    const std::string INVALID_PHONE_FORMAT = "Invalid phone number format. Please use digits, spaces, and hyphens only.";
    const std::string INVALID_COMMAND = "Invalid command. Please use ADD, SEARCH, or EXIT.";
    const std::string INPUT_TERMINATED = "Input terminated. Exiting program.";
}

// 入力を取得し、EOFまたは空文字列の場合はプログラムを終了
std::string getInputOrExit(const std::string &prompt);

// 電話番号のバリデーション
bool isValidPhoneNumber(const std::string &number);

// 入力が有効な数値かどうかチェックする関数
bool isValidNumber(const std::string &str);

#endif
