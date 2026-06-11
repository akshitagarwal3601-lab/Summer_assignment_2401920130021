class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currString = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(currNum);
                stringStack.push(currString);

                currNum = 0;
                currString = "";
            }
            else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string prevString = stringStack.top();
                stringStack.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += currString;
                }

                currString = prevString + temp;
            }
            else {
                currString += c;
            }
        }

        return currString;
    }
};
