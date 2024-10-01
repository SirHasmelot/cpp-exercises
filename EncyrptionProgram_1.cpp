#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <list>

using namespace std;

class EncryptionProgram{
private:
    vector<char> chars= {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '{', '|', '}', '~','`',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    };
    vector<char> key = chars; 
    string plain_text, cipher_text, text;

public:
    EncryptionProgram& encrypt(){
        cout<< "Enter the text: ";
        getline(cin, plain_text);    

        random_device rd;
        shuffle(key.begin(), key.end(), rd);

        for(char letter : plain_text){
            auto index = find(chars.begin(), chars.end(), letter)- chars.begin();
            cipher_text += key[index];
        }
        cout << "original message : " << plain_text << endl;
        cout << "encrypted message: " << cipher_text << endl << endl;
        return *this;
    }

    EncryptionProgram& decrypt(){
    cout << "Enter a message to decrypt: ";
    getline(cin, cipher_text);
    plain_text.clear();

    for (char letter : cipher_text) {
        auto index = find(key.begin(), key.end(), letter) - key.begin();
        plain_text += chars[index];
    }

    cout << "encrypted message: " << cipher_text << endl;
    cout << "original message : " << plain_text << endl;
    
    return *this;
    }
};

int main() {
    EncryptionProgram ep;

    ep.encrypt().decrypt();

    return 0;
}


