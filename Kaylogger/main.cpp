#include <iostream>
#include <string>

using namespace std;

class account {
public:
    bool is_secure = false;

    void accept() {
        string x;
        do {
            cout << "podaj hałso" << endl;
            getline(cin, x);

            bool passwd_length = false, upchar = false, lowchar = false, numb = false, character = false, space = false;
            int  upchar_counter = 0, lowchar_counter = 0, numb_counter = 0, character_counter = 0;
            int score1 = 1, score2 = 1, score3 = 1, score4 = 1; // [0]uppercase [1]lowercase [2]nubmers [3]special characters

            for (int i = 0; i < x.length(); i++) {
                if (x.length() >= 8) { passwd_length = true; }
                if (isupper(x[i])) { upchar = true; upchar_counter++; score1 *= 36; }
                if (islower(x[i])) { lowchar = true; lowchar_counter++; score2 *= 36; }
                if (isdigit(x[i])) { numb = true; numb_counter++; score3 *= 10; }
                if (x[i] == ' ') { space = true; }
            }
            if (x.length() != upchar_counter + lowchar_counter + numb_counter) {
                character = true;
                character_counter = x.length() - upchar_counter - lowchar_counter - numb_counter;
                for (int i = 0; i < character_counter; i++) { score4 *= 33; }
            }
            if (passwd_length && upchar && lowchar && numb && character && !space) { is_secure = true; }
            if (is_secure) {
                cout << "hasło spełnia odpowiednie warunki" << endl;
                cout << "Długość hasła: " << x.length() << endl;
                cout << "Ilość małych liter: " << lowchar_counter << endl;
                cout << "Ilość dużych liter: " << upchar_counter << endl;
                cout << "Ilość znaków: " << character_counter << endl;
                cout << "Ilość cyfr w haśle: " << numb_counter << endl;

                if (is_secure) { calc_strenght(x, score1, score2, score3, score4); }
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
            }
        } while (!is_secure);
    }

    void calc_strenght(string x, int score1, int score2, int score3, int score4) {
        int score = 0;
        score = score1 * score2 * score3 * score4;
        cout << "punkty hasła:      " << score;
    }
};

int main() {
    account passwd;
    passwd.accept();
    return 0;
}