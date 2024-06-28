#include <bits/stdc++.h>

using namespace std;

bool isOpeningBracket(char bracket) {
  return bracket == '(' || bracket == '[' || bracket == '{';
}

char getCorrespondingOpeningBracket(char closingBracket) {
  if (closingBracket == ')') {
    return '(';
  } else if (closingBracket == '}') {
    return '{';
  } else {
    return '[';
  }
}

bool areBracketsBalanced(string brackets) {
  stack<char> balancingStack;
  for (int i = 0; i < brackets.length(); i++) {
    if (isOpeningBracket(brackets[i])) {
      balancingStack.push(brackets[i]);
      continue;
    }

    if (balancingStack.empty()) {
      return false;
    }
    char correspondingOpeningBracket =
        getCorrespondingOpeningBracket(brackets[i]);
    if (balancingStack.top() != correspondingOpeningBracket) {
      return false;
    } else {
      balancingStack.pop();
    }
  }
  // If stack empty all brackets are correctly closed.
  return balancingStack.empty();
}