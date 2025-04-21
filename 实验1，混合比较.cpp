#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int convertToDecimal(const string& num) {
    return stoi(num.substr(num[1] == 'x' || num[1] == 'b' ? 2 : 0), nullptr,
                num[0] == '0' ? (num[1] == 'x' ? 16 : (num[1] == 'b' ? 2 : 8)) : 10);
}

int main() {
    string input, token;
    getline(cin, input);

    vector<int> numbers;
    stringstream ss(input);
    while (getline(ss, token, ',')) numbers.push_back(convertToDecimal(token));

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); i++) cout << (i ? "," : "") << numbers[i];
}
