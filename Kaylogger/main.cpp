#include <iostream>
using namespace std;

class account {
public:
    bool is_secure = false;

    void strenght() {
        string x;
        do {
        cout << "podaj ha³so" << endl;
        cin >> x;
        
            bool passwd_length = false, upchar = false, lowchar = false, numb = false, character = false, space = false;
            int  upchar_counter = 0, lowchar_counter = 0, numb_counter = 0, character_counter = 0;
            char spec_char[8] = { '!', '@', '#', '$', '%', '^', '&', '*' };

            for (int i = 0; i < x.length(); i++) {
                if (x.length() >= 8) { passwd_length = true; }
                if (isupper(x[i])) { upchar = true; upchar_counter++; }
                if (islower(x[i])) { lowchar = true; lowchar_counter++; }
                if (isdigit(x[i])) { numb = true; numb_counter++; }
                for (int z = 0; z < 8; z++) {
                    if (x[i] == spec_char[z]) { character = true; character_counter++; }
                }
                if (x[i] == ' ') { space = true; }
            }
            if (passwd_length && upchar && lowchar && numb && character && !space) { is_secure = true; }
            if (is_secure) {
                cout << "has³o spe³nia odpowiednie warunki" << endl;
                cout << "D³ugoœæ has³a: " << x.length() << endl;
                cout << "Iloœæ ma³ych liter: " << lowchar_counter << endl;
                cout << "Iloœæ du¿ych liter: " << upchar_counter << endl;
                cout << "Iloœæ znaków: " << character_counter << endl;
                cout << "Iloœæ cyfr w haœle: " << numb_counter << endl;
                break;
            }
            if (!is_secure) {
                cout << "has³o nie spe³nia podyktowanych wymagañ" << endl;
                if (!passwd_length) { cout << "has³o jest zbyt krótkie" << endl; }
                if (!upchar) { cout << "brakuje du¿ej litery" << endl; }
                if (!lowchar) { cout << "brakuje ma³ej litery" << endl; }
                if (!numb) { cout << "brakuje cyfry" << endl; }
                if (!character) { cout << "brakuje znaku" << endl; }
                if (space) { cout << "w haœle pojawia siê spacja" << endl; }
                suggest(x, passwd_length, upchar, lowchar, numb, character);
            }
        } while (!is_secure);
    }

    void suggest(string x, bool passwd_length, bool upchar, bool lowchar, bool numb, bool character) {
        cout << "¿ - word jebany jest";
    }
};


int main() {
    account passwd;
    passwd.strenght();
    return 0;
}