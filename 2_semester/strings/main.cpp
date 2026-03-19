#include <iostream>
#include <cstring>
#include<windows.h>
#include <fstream>
using namespace std;

char ToLower(unsigned char c){
    if ( c >= 'A' && c <= 'Z' ) return c + 32;
    if (c >= 192 && c <= 223) return c + 32;
    if (c == 168) return 184;
    return c;
}

char ToUpper(unsigned char c){
    if ( c >= 'a' && c <= 'z' ) return c - 32;
    if (c >= 224 && c <= 255) return c - 32;
    if (c == 184) return 168;
    return c;
}
bool isLetter(char c) {
    unsigned char uc = c;
    return (uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z') ||
           (uc >= 192 && uc <= 255) || uc == 168 || uc == 184;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isLetterOrDigit(char c) {
    return isLetter(c) || isDigit(c);
}

bool isSeparator(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void cleanWord(char* word, char* result) {
    int len = strlen(word);
    
    int start = 0;
    while (start < len && !isLetterOrDigit(word[start])) {
        start++;
    }
    
    int end = len - 1;
    while (end >= start && !isLetter(word[end])) {
        end--;
    }
    
    if (start > end) {
        result[0] = '\0';
        return;
    }
    
    int pos = 0;
    for (int i = start; i <= end; i++) {
        result[pos++] = ToLower(word[i]);
    }
    result[pos] = '\0';
}

int countLettersAndDigits(char* word) {
    int count = 0;
    for (int i = 0; word[i]; i++) {
        if (isLetterOrDigit(word[i])) count++;
    }
    return count;
}

//Ïóíêò 0

// void PrintTable(){
    
//     cout << "=== ÒÀÁËÈÖÀ ÑÈÌÂÎËÎÂ ===" << endl;

//     cout << "Ðóññêèå áóêâû " << endl;
//     for (unsigned char c = 192; c <= 255; c++){
//         cout << "Ñèìâîëîâ: " << c << " Êîä: " <<  static_cast<unsigned int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Àíãëèéñêèå áóêâû:" << endl;
//     for (char c = 'A' ; c <= 'Z' ; c++ ){
//         cout << "Ñèìâîëû: " << c << " Êîä: " << static_cast<int>(c) << endl;
//     }
//     for (char c = 'a' ; c <= 'z' ; c++ ){
//         cout << "Ñèìâîëû: " << c << " Êîä: " << static_cast<int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Öèôðû:" << endl;
//     for ( char c = '0'; c <= '9'; c++){
//         cout << "Ñèìâîëû: " << c << " Êîä: " << static_cast<int>(c) << endl;
//     }
//     cout << " " << endl;

//     cout << "Çíàêè ïðåïèíàíèÿ: " << endl;
//     char signs[] = ".,!?;:-()\"'";
//     for (int i = 0;  i < strlen(signs); i++){
//         cout << "Ñèìâîëû: " << signs[i] << " Êîä: " << static_cast<int>(signs[i]) << endl;
//     }
// }

//Ïóíêò 1.1

// void task1(){
//     cout << "=== ÇÀÄÀ×À 1 ===" << endl;
//     char consonants[] = "áâãäæçéêëìíïðñòôõö÷øùbcdfghjklmnpqrstvwxz";
//     char line[101];
//     cout <<"Ââåäèòå ñòðîêó (< 100): ";
//     cin.getline(line, 101);
//     for (int i = 0; i < strlen(line); i++){
//         for (int j = 0; j < strlen(consonants); j++){
//             if (ToLower(line[i]) == consonants[j]){
//                 line[i] = ToUpper(line[i]);
//                 break;
//             }
//         }
//     }
//     cout << "Ðåçóëüòàò: " << line << endl;

// }

// Ïóíêò 2

void task2() {
    cout << "=== ÇÀÄÀ×À 2 ===" << endl;
    
    ifstream in("input.txt");
    if (!in) {
        cout << "Îøèáêà îòêðûòèÿ input.txt" << endl;
        return;
    }
    
    int N;
    char letter1, letter2;
    in >> N >> letter1 >> letter2;
    in.close();
    
    letter1 = ToLower(letter1);
    letter2 = ToLower(letter2);
    
    cout << "Èùåì " << N << " ñëîâ ñ áóêâàìè '" << letter1 << "' è '" << letter2 << "'" << endl;
    
    ifstream text("text.txt");
    if (!text) {
        cout << "Îøèáêà îòêðûòèÿ text.txt" << endl;
        return;
    }
    
    char words[400][51];      
    int lengths[400];          
    int wordCount = 0;
    
    char rawWord[51];          
    int pos = 0;
    char ch;
    
    while (text.get(ch)) {
        if (!isSeparator(ch)) {
            if (pos < 50) rawWord[pos++] = ch;
        }
        else if (pos > 0) {
            rawWord[pos] = '\0';
            char clean[51];
            cleanWord(rawWord, clean);
            
            if (clean[0] != '\0') {
                bool has1 = false, has2 = false;
                for (int i = 0; clean[i]; i++) {
                    if (clean[i] == letter1) has1 = true;
                    if (clean[i] == letter2) has2 = true;
                }
                
                if (has1 && has2) {
                    bool found = false;
                    for (int i = 0; i < wordCount; i++) {
                        if (strcmp(words[i], clean) == 0) {
                            found = true;
                            break;
                        }
                    }
                    
                    if (!found && wordCount < 400) {
                        strcpy(words[wordCount], clean);
                        lengths[wordCount] = countLettersAndDigits(clean);
                        wordCount++;
                    }
                }
            }
            
            pos = 0;
        }
    }
    
    if (pos > 0) {
        rawWord[pos] = '\0';
        char clean[51];
        cleanWord(rawWord, clean);
        
        if (clean[0] != '\0') {
            bool has1 = false, has2 = false;
            for (int i = 0; clean[i]; i++) {
                if (clean[i] == letter1) has1 = true;
                if (clean[i] == letter2) has2 = true;
            }
            
            if (has1 && has2) {
                bool found = false;
                for (int i = 0; i < wordCount; i++) {
                    if (strcmp(words[i], clean) == 0) {
                        found = true;
                        break;
                    }
                }
                
                if (!found && wordCount < 400) {
                    strcpy(words[wordCount], clean);
                    lengths[wordCount] = countLettersAndDigits(clean);
                    wordCount++;
                }
            }
        }
    }
    
    text.close();
    
    cout << "Íàéäåíî ñëîâ: " << wordCount << endl;
    if (wordCount == 0) return;
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (lengths[j] > lengths[j + 1]) {
                char tempWord[51];
                strcpy(tempWord, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], tempWord);
                
                int tempLen = lengths[j];
                lengths[j] = lengths[j + 1];
                lengths[j + 1] = tempLen;
            }
        }
    }
    
    ofstream res("result.txt");
    int limit = (N < wordCount) ? N : wordCount;
    
    cout << "Ðåçóëüòàò:" << endl;
    for (int i = 0; i < limit; i++) {
        cout << words[i] << " (äëèíà " << lengths[i] << ")" << endl;
        res << words[i] << endl;
    }
    
    res.close();
    cout << "Ðåçóëüòàò ñîõðàíåí â result.txt" << endl;
}



int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //PrintTable();
    //task1();
    task2();


}
