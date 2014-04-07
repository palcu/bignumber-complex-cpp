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
#include <cstdio>
#include <vector>
#include <stdexcept>

using std::string;
using std::to_string;
using std::reverse;
using std::vector;

class BigNumber {
  public:
    vector<char> integerPart, fractionaryPart;
    bool sign = 0;

    explicit BigNumber(int x) : BigNumber(to_string(x)) { }
    BigNumber(int integerPart, int fractionaryPart) :
        BigNumber(to_string(integerPart) + "." + to_string(fractionaryPart)) { }

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

    void plus_one() {
        int i = 0;
        while (integerPart[i] == '9' && integerPart.size() > i) {
            // printf("i = %d\n", i);
            integerPart[i] = '0';
            i++;
        }
        if (integerPart.size() == i)
            integerPart.push_back('1');
        else
            integerPart[i]++;
    }

    void add(BigNumber x) {
        bool carry = 0;
        std::tie(carry, fractionaryPart) = addTwoVectors(fractionaryPart,
                                                         x.fractionaryPart);
        if (carry)
            plus_one();
        std::tie(carry, integerPart) = addTwoVectors(integerPart,
                                                     x.integerPart);
        if (carry)
            integerPart.push_back('1');
    }

  private:
    const int BASE = 10;

    std::tuple<bool, vector<char>> addTwoVectors(vector<char> base,
                                                 vector<char> visitor) {
        // TODO(alex): change these reverses
        reverse(base.begin(), base.end());
        reverse(visitor.begin(), visitor.end());

        while (base.size() < visitor.size())
            base.push_back('0');
        while (visitor.size() < base.size())
            visitor.push_back('0');

        reverse(base.begin(), base.end());
        reverse(visitor.begin(), visitor.end());

        bool carry = 0;
        for (int i = 0; i < base.size(); i++) {
            base[i] += visitor[i] + carry - '0';
            if (base[i] > '9') {
                carry = 1;
                base[i] -= '9';
            } else {
                carry = 0;
            }
        }

        return make_tuple(carry, base);
    }
};

int main() {
    assert(BigNumber(6, 9).toString() == "6.9");
    assert(BigNumber(3).toString() == "3");
    assert(BigNumber(-5).toString() == "-5");

    vector<string> v = {"10", "10.3", "-10.555", "69.34433434", "0", "2"};

    for (int i = 0; i < v.size(); i++)
        assert(BigNumber(v[i]).toString() == v[i]);


    BigNumber nineteen = BigNumber(19);
    nineteen.plus_one();
    assert(nineteen.toString() == "20");

    BigNumber x = BigNumber(8);
    x.plus_one();
    assert(x.toString() == "9");
    x.plus_one();
    assert(x.toString() == "10");
    BigNumber y = BigNumber("10.6");
    y.plus_one();
    assert(y.toString() == "11.6");

    BigNumber ten = BigNumber("5.1");
    ten.add(BigNumber("3.2"));
    assert(ten.toString() == "8.3");
    ten.add(BigNumber("1.12"));
    assert(ten.toString() == "9.42");
    ten.add(BigNumber("0.1"));
    assert(ten.toString() == "9.52");
    ten.add(BigNumber("0.000001"));
    assert(ten.toString() == "9.520001");

    return 0;
}
