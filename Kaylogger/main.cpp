#include <iostream>
using namespace std;

class account {
public:
    bool is_secure = false;

    void strenght() {
        string x;
        do {
        cout << "podaj ha�so" << endl;
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
                cout << "has�o spe�nia odpowiednie warunki" << endl;
                cout << "D�ugo�� has�a: " << x.length() << endl;
                cout << "Ilo�� ma�ych liter: " << lowchar_counter << endl;
                cout << "Ilo�� du�ych liter: " << upchar_counter << endl;
                cout << "Ilo�� znak�w: " << character_counter << endl;
                cout << "Ilo�� cyfr w ha�le: " << numb_counter << endl;
                break;
            }
            if (!is_secure) {
                cout << "has�o nie spe�nia podyktowanych wymaga�" << endl;
                if (!passwd_length) { cout << "has�o jest zbyt kr�tkie" << endl; }
                if (!upchar) { cout << "brakuje du�ej litery" << endl; }
                if (!lowchar) { cout << "brakuje ma�ej litery" << endl; }
                if (!numb) { cout << "brakuje cyfry" << endl; }
                if (!character) { cout << "brakuje znaku" << endl; }
                if (space) { cout << "w ha�le pojawia si� spacja" << endl; }
                suggest(x, passwd_length, upchar, lowchar, numb, character);
            }
        } while (!is_secure);
    }

    void suggest(string x, bool passwd_length, bool upchar, bool lowchar, bool numb, bool character) {
        cout << "� - word jebany jest";
    }
};


int main() {
    account passwd;
    passwd.strenght();
    return 0;
}