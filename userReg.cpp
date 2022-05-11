#include <iostream>
#include <fstream>

using  namespace std;

void showMenu(){
    cout<<"1. Sign-up\n";
    cout<<"2. Log-in\n";
    cout<<"3. Exit\n";
}

void userRegister(){
    string userName, password, email;
    enterName:
    cout<<"Enter 0 to go back to the main menu or,\n";
    cout<<"Enter a username: ";
    getline(cin,userName);
    
    if(userName=="0")
        return;

    ofstream registered;
    registered.open(userName+".txt", ios_base::out | ios_base::in);//it will open a file but wont create or override 
    if(registered.is_open()){//returns true if a file with the same name exists in the directory
        system("cls");
        cout<<"Username already exists.\n";
        registered.close();
        goto enterName;//it will go for the re-enter of username
    }
    else{
        cout<<"Enter email: ";
        getline(cin,email);
        cout<<"Enter password: ";
        getline(cin,password);
        registered.open("e:\\cpp\\project\\login\\"+userName+".txt");
        //              here enter your own directory
        registered <<email<<endl<<password<<endl<<userName;
        registered.close();
        cout<<"Registration Successful.\n\n";
    }
}

void userLogin(){
    string userName, password, email, fileMail, filePass, fileName;
    loginAgain:
    cout<<"Enter 0 to go back to the main menu or,\n";
    cout<<"Enter username: ";
    getline(cin,userName);
    
    if(userName=="0")
        return;

    ifstream loginFile;
    loginFile.open(userName+".txt", ios_base::in);
    if(loginFile.is_open()){
        enterPass:
        cout<<"Enter 1 to go back to the main menu or,\n";
        cout<<"Enter 0 if you have forgotten password or,\n";
        cout<<"Enter password: ";
        getline(cin,password);
        getline(loginFile,fileMail);//gets the 1st line from the file
        getline(loginFile,filePass);//gets the 2nd line from the file
        getline(loginFile,fileName);//gets the 3rd line from the file

        if(password=="0"){
            enterMailAgain:
            // system("cls");
            cout<<"Press 0 to go to the previous menu or,\n";
            cout<<"Enter your email: ";
            getline(cin,email);
            if(email=="0"){
                system("cls");
                goto enterPass;
            }
            else if(email==fileMail){
                cout<<"Enter new password: ";
                cin>>password;

                loginFile.close();
                ofstream loginFile;
                loginFile.open(userName+".txt", ios_base::out);

                loginFile <<email<<endl<<password<<endl<<userName;
                loginFile.close();
                cout<<"Password reset successfull.\n";
            }
            else{
                system("cls");
                cout<<"Email doesn't match.\n";
                goto enterMailAgain;
            }
        }
        else if(password=="1"){
            system("cls");
            return;
        }

        else if(filePass==password){
            cout<<"Login successful.\n\n";
            loginFile.close();
        }
        else{
            system("cls");
            cout<<"Password wrong.\n";
            goto enterPass;//it will go for the re-enter of password
        }
    }
    else{
        system("cls");
        cout<<"Username doesn't exist.\n\n";
        goto loginAgain;
    }
}

int main(){

    char choice;//to distinguish between char and int
    do{
        showMenu();
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();//to ignore the enter button after user gives choice
        system("cls");

        if(choice=='1'){
            userRegister();
        }
        else if(choice=='2'){
            userLogin();
        }
        else if(choice!='3'){
            cout<<"Enter a valid number.\n";
        }

    }while(choice!='3');    

    return 0;
}