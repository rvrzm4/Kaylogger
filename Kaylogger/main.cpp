#include <iostream>
#include <string>

using namespace std;

class account {
public:
    bool is_secure = false;

    void strenght() {
        string x;
        do {
        cout << "podaj hałso" << endl;
        getline(cin, x);
        
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
                cout << "hasło spełnia odpowiednie warunki" << endl;
                cout << "Długość hasła: " << x.length() << endl;
                cout << "Ilość małych liter: " << lowchar_counter << endl;
                cout << "Ilość dużych liter: " << upchar_counter << endl;
                cout << "Ilość znaków: " << character_counter << endl;
                cout << "Ilość cyfr w haśle: " << numb_counter << endl;
                break;
            }
            if (!is_secure) {
                cout << "hasło nie spełnia podyktowanych wymagań" << endl;
                if (!passwd_length) { cout << "hasło jest zbyt krótkie" << endl; }
                if (!upchar) { cout << "brakuje dużej litery" << endl; }
                if (!lowchar) { cout << "brakuje małej litery" << endl; }
                if (!numb) { cout << "brakuje cyfry" << endl; }
                if (!character) { cout << "brakuje znaku" << endl; }
                if (space) { cout << "w haśle pojawia się spacja" << endl; }
                //suggest(x, passwd_length, upchar, lowchar, numb, character, space);
            }
        } while (!is_secure);
    }

    /*void suggest(string x, bool passwd_length, bool upchar, bool lowchar, bool numb, bool character, bool space) {
        string offer_pswrd;
        bool corrected__passwd_length = false, corrected__upchar = false, corrected__lowchar = false, corrected__numb = false, corrected__character = false, corrected__space = false;
        int num = 0;

        for (int i = 0; i < x.length(); i++) {
            if (!upchar && !corrected__upchar) {
                if (islower(x[i])) { offer_pswrd += toupper(x[i]); corrected__upchar = true; }
            }
            else if (!lowchar && !corrected__lowchar) {
                if (isupper(x[i])) { offer_pswrd += tolower(x[i]); corrected__lowchar = true; }
            }
            else if (!numb) {
                if (isdigit(x[i])) { srand(time(NULL)); num = rand() % 90 + 10; offer_pswrd += to_string(num); }
            }
            else { offer_pswrd += x[i]; }
         
        }
        cout << "oferowane hasło:   " << offer_pswrd << endl << endl;
    }*/
};

int main() {
    account passwd;
    passwd.strenght();
    return 0;
}
