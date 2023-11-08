#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <math.h>

using namespace std;
string translate(int num);
void IP_address(string str);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int num;
    string result;

    cout << "Ввод целого в десятичной форме:";
    cin >> num;
    cout << endl;
    result = translate(num);
    cout <<"Ответ  = "<< result << endl;
    IP_address(result);

    
    return 0;
}

string translate(int num) {
    int between, remain, k=0;
    string bin = "";
    between = num / 2; 
    cout << num << " / 2 = " << between << endl;
    remain = num % 2;
    cout << "Остаток = " << remain << endl;
    bin += to_string(remain);
    while (true) {
        num = between;
        between = between / 2;
        cout << num << " / 2 = " << between << endl;
        remain = num % 2;
        cout << "Остаток = " << remain << endl;
        bin += to_string(remain);

        if (between < 2) {
            cout << "Последняя цифра = " << between<<endl;
            bin += to_string(between);
            break;
        }
    }
    reverse(bin.begin(), bin.end());
    return bin;
}
void IP_address(string str)
{
    if (str.size() <= 8) {
        string emptyField = "";
        for (int i = 0; i < (8 - str.size()); i++) {
            emptyField += "0";
        }
        cout << "Ответ в IP = " << emptyField << str << endl;
    }
    else {
        cout << "Строка не подходит для IP" << endl;
    }
}
