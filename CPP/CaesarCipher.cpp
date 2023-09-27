#include <iostream>
#include <string>

using namespace std;

class CaesarCipher{
    char plainText[40], cipher[40];
    int key;

public:
    int stringLength(){
        int i = 0;
        while (plainText[i] != '\0'){
            i++;
        }
        return i;
    }

    void takePlainText(){
        cout<<"Enter Plain Text" << endl;
        cin >> plainText;
        cout<<"Enter key: " << endl;
        cin >> key;
    }

    void getEncryptedText(){
        cout<<"Encrypted text " << endl;
        for (int i = 0; i < stringLength(); i++){
            cout << cipher[i];
        }
        cout << endl;
    }

    void getDecryptedText(){
        cout << "Decrypted text\n";
        for (int i = 0; i<stringLength(); i++){
            cout << plainText[i];
        }
        cout << endl;
    }

    void encryptText(){
        for (int i = 0; i < stringLength(); i++){
            cipher[i] = plainText[i] + key;
            if(isupper(plainText[i]) && (cipher[i] > 'Z')){
                cipher[i] = cipher[i] - 26;
            }
            
            if(islower(plainText[i]) && (cipher[i] > 'z')){
                cipher[i] = cipher[i] - 26;
            }
        }
    }

    void decryptText(){
        for (int i = 0; i < stringLength(); i++){
            plainText[i] = cipher[i] - key;
            if(isupper(cipher[i]) && (plainText[i] < 'A')){
                plainText[i] = plainText[i] + 26;
            }
            if(islower(cipher[i]) && (plainText[i] < 'a')){
                plainText[i] = plainText[i] + 26;
            }
        }
    }

    void encryptionDecryption(){
        takePlainText();
        encryptText();
        getEncryptedText();
        decryptText();
        getDecryptedText(); 
    }

    char getchoice(){
        char ch;
        cout << "Do you want to continue? (y/n)" << endl;
        cin >> ch;  
        return ch;
    }
};

int main(){
    char ch = 'n';
    do
    {
        CaesarCipher c;
        c.encryptionDecryption();
        ch = c.getchoice();
    } while (ch=='y');
    
}