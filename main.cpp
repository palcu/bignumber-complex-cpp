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

#include <cmath>
#include <string>
#include <cassert>

using std::string;
using std::to_string;

class BigNumber {
  public:
    BigNumber(int integerPart, int fractionaryPart) {
        this->integerPart = abs(integerPart);
        this->fractionaryPart = fractionaryPart;
        if (integerPart < 0)
            sign = 1;
        else
            sign = 0;
    }
    explicit BigNumber(int x) {
        BigNumber(x, 0);
    }
    string toString() {
        string answer;
        if (sign)
            answer += "-";
        answer += to_string(integerPart);
        if (fractionaryPart)
            answer += "." + to_string(fractionaryPart);
        return answer;
    }

  private:
    int integerPart, fractionaryPart;
    bool sign;
};

int main() {
    BigNumber a = BigNumber(10, 3);
    assert(a.toString() == "10.3");
    BigNumber b = BigNumber(-10, 0);
    assert(b.toString() == "-10");
    return 0;
}
