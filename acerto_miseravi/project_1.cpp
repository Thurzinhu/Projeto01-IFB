#include <iostream>
#include <vector>
using namespace std;

// string to integer
#define STOI(c) (c - '0')

class Number {
    private:
        string digits;
        int length;
        int sign;
    
    public:
        Number (string d) : digits(d), length(d.length()) {}
        void add(Number &num);
        void sub(Number &num);
        void mult(Number &num);
};

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string a, b;
        int o;
        cin >> a;
        cin >> b;
        cin >> o;

        Number num_1(a), num_2(b);
        switch (o)
        {
            case 1:
                num_1.add(num_2);
                break;
            case 2:
                num_1.sub(num_2);
                break;
            case 3:
                num_1.mult(num_2);
                break;
        }
    }
}

void Number::add(Number &num){
    vector<int> result;
    int length_num_1 = length - 1, length_num_2 = num.length - 1;
    int digit, aux = 0;
    for (int i = length_num_1, j = length_num_2; i >= 0 || j >= 0; i--, j--){
        if (i < 0){
            digit = STOI(num.digits[j]) + aux;
        } else if (j < 0){
            digit = STOI(digits[i]) + aux;
        } else{
            digit = STOI(num.digits[j]) + STOI(digits[i]) + aux;
        }

        aux = digit / 10;
        result.insert(result.begin(), digit % 10);
    }

    if (aux){
        result.insert(result.begin(), aux);
    }

    for (int num : result){
        cout << num;
    }
    cout << endl;
}

void Number::sub(Number &num){
    int length_num_1 = length - 1, length_num_2 = num.length - 1;
    int greatest = 1;
    if (length_num_1 == length_num_2){
        for (int i = 0; i < length_num_1; i++){
            if (num.digits[i] > digits[i]){
                greatest = 0;
                break;
            } else if (digits[i] > num.digits[i]){
                break;
            }
        }
    } else if (length_num_2 > length_num_1){
        greatest = 0;
    }

    if (!greatest){
        swap(digits, num.digits);
        swap(length_num_1, length_num_2);
        cout << "-";
    }

    int digit;
    vector<int> result;
    for (int i = length_num_1, j = length_num_2; i >= 0 || j >= 0; i--, j--){
        if (i < 0){
            digit = STOI(num.digits[j]);
        } else if (j < 0){
            digit = STOI(digits[i]);
        } else{
            digit = STOI(digits[i]) - STOI(num.digits[j]);
        }

        if (digit < 0){
            digit += 10;
            int cur = i - 1;
            while (digits[cur] == '0'){
                digits[cur] += 9;
                cur--;
            }

            digits[cur] -= 1;
        }

        result.insert(result.begin(), digit);
    }

    for (int num : result){
        cout << num;
    }
    cout << endl;
}

void Number::mult(Number &num){
    int length_num_1 = length - 1, length_num_2 = num.length - 1;
    int cur;
    vector<int> result (1001);
    for (int i = length_num_1; i >= 0; i--){
        int aux = 0, digit;
        cur = result.size() - 1;

        for (int j = i; j != length_num_1; j++){
            cur--;
        }

        for (int j = length_num_2; j >= 0; j--){
        
            digit = STOI(digits[i]) * STOI(num.digits[j]) + aux;

            aux = digit / 10;
            digit %= 10;

            result[cur] += digit;
            if (result[cur] >= 10){
                aux += result[cur] / 10;
                result[cur] %= 10;
            }

            cur--;
        }

        if (aux){
            result[cur] += aux;
        }
    }

    int size = result.size();
    for (int i = cur; i < size; i++){
        cout << result[i];
    }
    cout << endl;
}
