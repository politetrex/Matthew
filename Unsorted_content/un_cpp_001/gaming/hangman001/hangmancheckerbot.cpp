#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    char confirm;
    do {
        cout<<"enter word ";
        cin>>s;
        int sz=s.size(), guessed=0;
        vector<bool> guess(sz, 0);
        while(guessed<sz){
            if (sz-guessed==2){
                cout<<"Getting close!\n";
            } else if (sz-guessed==1){
                cout<<"Definitely obvious now!\n";
            }
            for(int i=0; i<sz; i++){
                if (guess[i]) cout<<s[i];
                else cout<<'_';
            }
            cout<<'\n';
            char inp; cin>>inp;
            if (s.find(inp) != string::npos) {
                for (int i = 0; i < sz; i++) {
                    if (s[i] == inp && !guess[i]) {
                        guess[i] = 1;
                        guessed++;
                    }
                }
            } else {
                cout<<"no "<<inp<<'\n';
            }
        }
        cout<<"yay! word is "<<s<<'\n';
        cin>>confirm;
    } while (confirm!='n');
}