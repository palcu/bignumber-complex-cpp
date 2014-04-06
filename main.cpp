/*
The MIT License (MIT)

Copyright (c) 2014 Alex Palcuie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::string;
using std::to_string;
using std::reverse;

class BigNumber {
  public:
    BigNumber(int integerPart, int fractionaryPart) {
        BigNumber(to_string(integerPart) + "." + to_string(fractionaryPart));
    }
    explicit BigNumber(int x) {
        BigNumber(to_string(x));
    }
    explicit BigNumber(string v) {
        int i = 0;
        if (v[i] == '-') {
            sign = 1;
            i++;
        }
        while (i < v.size()) {
            if (isdigit(v[i])) {
                integerPart.push_back(v[i]);
            } else {
                if (v[i] != '.')
                    throw std::runtime_error("NaN");
                break;
            }
            i++;
        }
        if (v[i] == '.') {
            i++;
            while (i < v.size()) {
                if (isdigit(v[i]))
                    fractionaryPart.push_back(v[i]);
                else
                    throw std::runtime_error("NaN");
                i++;
            }
        }
        reverse(integerPart.begin(), integerPart.end());
        if (fractionaryPart.size())
            reverse(fractionaryPart.begin(), fractionaryPart.end());
    }
    string toString() {
        string answer;
        if (sign)
            answer += "-";
        string x = string(integerPart.data(), integerPart.size());
        reverse(x.begin(), x.end());
        answer += x;
        if (fractionaryPart.size()) {
            answer += ".";
            string x = string(fractionaryPart.data(), fractionaryPart.size());
            reverse(x.begin(), x.end());
            answer += x;
        }
        return answer;
    }

  private:
    std::vector<char> integerPart, fractionaryPart;
    bool sign = 0;
};

int main() {
    std::vector<string> v = {"10", "10.3", "-10.555", "69.34433434", "0"};

    for (int i = 0; i < v.size(); i++) {
        BigNumber a = BigNumber(v[i]);
        assert(a.toString() == v[i]);
    }

    return 0;
}
