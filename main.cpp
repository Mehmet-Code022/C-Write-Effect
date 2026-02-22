#include <iostream>
#include <chrono> 
#include <thread> 
#include <string> 
#include <cstdlib> 

using namespace std;

string UserName = "";

void Backspace(int count, int speed = 100) {
    for (int i = 0; i < count; i++) {
        cout << "\b \b" << flush; 
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

void TextAnimation(string Text, int speed_milisecond, int wrong_character_possibility_number){
    string Blue = "\033[1;34m"; // Mavi -> Blue
    string Normal = "\033[0m";
    
    // Ismin bittigi indexi onceden hesaplayalim
    int namePos = (UserName != "") ? Text.find(UserName) : -1;
    int nameEnd = (namePos != -1) ? namePos + UserName.length() : -1;

    int Special_Waiting = 350;
    int margin_of_deviation = 2;

    for (int i = 0; i < Text.length(); i++){
        
        if (namePos != -1 && i >= namePos && i < nameEnd) {
            cout << Blue;
        } else {
            cout << Normal;
        }

        if(Text[i] == '.' or Text[i] == ',' or Text[i] == '!' or Text[i] == '?'){
            this_thread::sleep_for(chrono::milliseconds(Special_Waiting));
        }

        int RandNumber = rand() % 101;
        
        // HATA YAPMA BLOGU
        if ((RandNumber < wrong_character_possibility_number && Text[i] != ' ') && (i + 1 < Text.length())){ 
            cout << (char)(Text[i] + margin_of_deviation) << Text[i + 1] << flush;
            this_thread::sleep_for(chrono::milliseconds(300));
            Backspace(2);

            if (namePos != -1 && i >= namePos && i < nameEnd) cout << Blue;
            
            cout << Text[i] << Text[i + 1] << flush;
            i++; 
        }
        else{
            cout << Text[i] << flush;
        }
        
        this_thread::sleep_for(chrono::milliseconds(speed_milisecond));

        if(i >= (int)Text.length() - 1) cout << "\n"; 
    } 
    cout << Normal; 
}

void GetName(){
    cout << "Please enter your name: ";
    getline(cin, UserName); // Bosluklari da okuyabilmesi icin
    cout << "\n" << endl;
}

int main(){
    GetName();
    srand(time(0));
    
    TextAnimation("Programa Hosgeldin. Programa gelen kisi.", 100, 0);
    this_thread::sleep_for(chrono::milliseconds(1000));
    TextAnimation(UserName + " demek?", 100 , 77); 
    TextAnimation("Bu Program yaziyi renklendirmeye, daktilo efektine ve hiz ayarlamaya yardimci olur. Noktalama isaretleri sonrasi bekleme suresi alir falan filan.", 40, 0);
    TextAnimation("Ayni zamanda rastgele insansi hatalar da yapar ve gercekcidir.", 5, 15);
    TextAnimation("Renklendirme kisminda Gemini yardimi alinmistir.", 25, 40);
    
    return 0;
}
