#include <iostream>
#include <fstream>

using  namespace std;

void showMenu(){
    cout<<"1. Sign-up\n";
    cout<<"2. Log-in\n";
    cout<<"3. Exit\n";
}

void userRegister(){
    string userName, password;
    enterName:
    cout<<"Enter a username: ";
    getline(cin,userName);

    ofstream registered;
    registered.open(userName+".txt", ios_base::out | ios_base::in);//it will open a file but wont create or override 
    if(registered.is_open()){//returns true if a file with the same name exists in the directory
        cout<<"Username already exists.\n";
        registered.close();
        goto enterName;//it will go for the re-enter of username
    }
    else{
        cout<<"Enter password: ";
        getline(cin,password);
        registered.open("e:\\cpp\\project\\login\\"+userName+".txt");
        //              here enter your own directory
        registered <<userName<<endl<<password;
        registered.close();
        cout<<"Registration Successful.\n\n";
    }

}

void userLogin(){
    string userName, password, fileName, filePass;
    cout<<"Enter username: ";
    getline(cin,userName);

    ifstream loginFile;
    loginFile.open(userName+".txt", ios_base::in);
    if(loginFile.is_open()){
        enterPass:
        cout<<"Enter password: ";
        getline(cin,password);
        getline(loginFile,fileName);//gets the 1st line from the file
        getline(loginFile,filePass);//gets the 2nd line from the file
        if(filePass==password){
            cout<<"Login successful.\n\n";
            loginFile.close();
        }
        else{
            cout<<"Password wrong.\n";
            goto enterPass;//it will go for the re-enter of password
        }
    }
    else{
        cout<<"Username doesn't exist.\n\n";
    }
}

int main(){

    int choice;
    do{
        showMenu();
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();//to ignore the enter button after user gives choice
        
        if(choice==1){
            userRegister();
        }
        else if(choice==2){
            userLogin();
        }
        else if(choice!=3){
            cout<<"Enter a valid number.\n";
        }

    }while(choice!=3);    

    return 0;
}