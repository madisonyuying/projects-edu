#include <iostream>
#include <string>

using namespace std;

int main(){
    string username = "";
    string password = "";
    bool loginSuccess = false;

    cout << "\tWelcome! Login below.\n\n";
    do{
        cout << "Username:  ";
        cin >> username;
        cout << "Password:  ";
        cin >> password;

        if (username == "username123" && password == "password123" ){
            cout << "Successful login\n\n";
            loginSuccess = true;
        } else {
            cout << "Incorrect username-password combination \n";
            cout << "Please try login again.";
        }
    }while(!loginSuccess);





    
    return 0 ;
}