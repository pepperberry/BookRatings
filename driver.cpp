#include eam>
#include ream>
#include ing>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
#include dc++.h>



using namespace std;

void menu(BookList &a, MemberList &b, RatingList &c);
void addBook(BookList &a);
void addMember(MemberList &b);
void login(MemberList &b);

int main(){
    cout <<endl<<"Welcome to the Book Recommendation Program."<<endl
    <<"this program allows you to rate books and find recommended books" << endl;
    //enters book file

    BookList a;//creates a book
    a.addFile();//adds files to the book
    cout << endl <<endl<<"# of books: "<<a.getBookListSize()<<endl<<endl<<endl;

    //enter rating file
    MemberList b;
    RatingList c(a.getBookListSize(),b.getMembers());
    menu(a, b, c);
    return 1;
}

void externalData(){

}

void menu(BookList &a, MemberList &b, RatingList &c){
    int option;
    bool quit = false;
    while(quit == false){
        if(b.getMember() != 0){//logged in menu
            cout<<"************** MENU **************"<<endl<<
                "* 1. Add a new member            *"<<endl<<
                "* 2. Add a new book              *"<<endl<<
                "* 3. Rate book                   *"<<endl<<
                "* 4. View ratings                *"<<endl<<
                "* 5. See recommendations         *"<<endl<<
                "* 6. Logout                      *"<<endl<<
                "**********************************"<<endl<<endl<<
                "Enter a menu option: ";
            cin >> option;
            cin.ignore();
            cout << endl;
            switch(option) {
                case 1:
                    addMember(b);
                    break;
                case 2:
                    addBook(a);
                    break;
                case 3:
                    //ratings list
                    c.addRating(b.getMember());
                    break;
                case 4:
                    //ratings list
                    break;
                case 5:
                    //ratings list
                    break;
                case 6:
                    b.logout();
                    break;
                default:
                    cout << "oops thats not an option please choose something else!"<<endl;
            }
        }else{//logged out menu
            cout<<"************** MENU **************"<<endl<<
                "* 1. Add a new member            *"<<endl<<
                "* 2. Add a new book              *"<<endl<<
                "* 3. Login                       *"<<endl<<
                "* 4. Quit                        *"<<endl<<
                "**********************************"<<endl<<endl<<
                "Enter a menu option: ";
            cin >> option;
            cin.ignore();
            cout << endl;
            switch(option) {
                case 1:
                    addMember(b);
                    break;
                case 2:
                    addBook(a);
                    break;
                case 3:
                    login(b);
                    break;
                case 4:
                    quit = true;
                    break;
                default:
                    cout << "oops thats not an option please choose something else!"<<endl;
            }
        }
    }
}

void addBook(BookList &a){
    string author;
    string title;
    string year;

    cout<<"Enter the author of the new book: ";

    getline(cin, author);
    cout << "Enter the title of the new book: ";
    getline(cin, title);
    cout <<"Enter the year (or range of years) of the new book:";
    getline(cin, year);

    cout << a.getBookISBN((a.getBookListSize()-1))<<", "<< a.getBookAuthor((a.getBookListSize()-1))<<", "<<a.getBookTitle((a.getBookListSize()-1))
    <<", "<<a.getBookYear((a.getBookListSize()-1))<<" was added."<<endl<<endl;


}
void addMember(MemberList &b){
    string name;
    cout<<"Enter the name of the new member: ";
    getline(cin, name);
    b.addMember(name);

   cout << b.getMemberName((b.getMembers()-1)) << " (account #: "<<b.getMemberNum((b.getMembers()-1))<<") was added."<<endl<<endl;

}


void login(MemberList &b) {
    int current;
    cout << "Enter member account: ";
    cin >> current;
    b.login(current);
    cin.ignore();
    cout << b.getMemberName((current-1))<<", you are logged in!"<<endl<<endl;
}
