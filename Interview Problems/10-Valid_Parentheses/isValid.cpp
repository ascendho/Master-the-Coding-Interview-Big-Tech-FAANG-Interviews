#include "isValid.h"
#include <stack>

bool isValid(std::string s) {
    std::stack<char> st; // 创建一个空栈以存储开括号

    // 循环遍历字符串中的每个字符
    for (char c: s) {

        // 字符是开括号
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);                                // 入栈
        } else {                                          // 字符是闭括号
            if (st.empty() ||                             // 若栈为空且闭括号不能匹配栈顶的开括号
                (c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')) {
                return false;                        // 字符串非法, 返回false
            }
            st.pop();                                // 弹出栈顶的开括号
        }
    }

    // 若栈为空, 说明所以开括号都被对应的闭括号匹配, 所以字符串合法;
    // 否则, 存在未被匹配的开括号, 返回false
    return st.empty();

}