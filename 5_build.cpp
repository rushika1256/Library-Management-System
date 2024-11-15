// make a items class with all common props of books , magazines and RS
// inherit books, magazinez, Rs from library class 
// create a class user and derive admin and student from it with name and id as common property
//each user different functionalities 
// prev functionaliites stay the same

#include<iostream>
#include<ctime>
#include<sstream>
#include<fstream>


using namespace std;
#define max_size 100

tm convert_to_tm(const string &date_str)
{
    tm time_struct = {};
    stringstream ss(date_str);
    string temp;

    getline(ss, temp, '-');
    time_struct.tm_year = stoi(temp) - 1900;
    getline(ss, temp, '-');
    time_struct.tm_mon = stoi(temp) - 1;
    getline(ss, temp, '-');
    time_struct.tm_mday = stoi(temp);

    return time_struct;
}
int days_elapsed(const string &issue_date, const string &return_date_str)
{
    tm issue_tm = convert_to_tm(issue_date);
    tm return_tm = convert_to_tm(return_date_str);

    time_t issue_time = mktime(&issue_tm);
    time_t return_time = mktime(&return_tm);

    double difference_in_seconds = difftime(return_time, issue_time);
    int days = difference_in_seconds / (60 * 60 * 24);

    return days;
}
class items{
    protected:
    string title;
    string publisher;
    int copies;
    int rack;
    int position;
   
    public :
    items(){

    }
    items(string,string, int, int , int);
};
items::items(string item_title, string item_publisher ,int no_copies, int book_rack , int book_position){
title = item_title;
publisher=item_publisher;
copies=no_copies;
rack=book_rack;
position=book_position;

}
class issue_entites{
public:
string name;
int id;
string issued_title;
string issue_date;

};
class student{
    string name;
    int id;
    string issued_book;
    string issue_date;
    string last_returned_date;
    bool is_issued;


    public:
    student()
    {

        last_returned_date = " ";
    }
    student(string student_name, int student_id, string book_name, string date)
    {
        name = student_name;
        id = student_id;
        issued_book = book_name;
        issue_date = date;
    }
    void storestudent();
    void display_student();
    void search_student(string s);
    string get_name()
    {
        return name;
    }
    void set_last_returned_date(string date)
    {
        last_returned_date = date;
    }
    string get_issued_date()
    {
        return issue_date;
    }
    string get_issued_book()
    {
        return issued_book;
    }
    void set_is_issued(bool x)
    {
        is_issued = x;
    }
    bool get_is_issued()
    {
        return is_issued;
    }
    int get_id()
    {
        return id;
    }
    void set_issued_book(string t)
    {
        issued_book = t;
    }
    string get_last_returned_date()
    {
        return last_returned_date;
    }
    tm convert_to_tm(const string &date_str)
    {
        tm time_struct = {};
        stringstream ss(date_str);
        string temp;

        getline(ss, temp, '-');
        time_struct.tm_year = stoi(temp) - 1900;
        getline(ss, temp, '-');
        time_struct.tm_mon = stoi(temp) - 1;
        getline(ss, temp, '-');
        time_struct.tm_mday = stoi(temp);

        return time_struct;
    }

    int days_elapsed(const string &issue_date, const string &return_date_str)
    {
        tm issue_tm = convert_to_tm(issue_date);
        tm return_tm = convert_to_tm(return_date_str);

        time_t issue_time = mktime(&issue_tm);
        time_t return_time = mktime(&return_tm);

        double difference_in_seconds = difftime(return_time, issue_time);
        int days = difference_in_seconds / (60 * 60 * 24);

        return days;
    }
};
void student::storestudent()
{
    ofstream fout;
    fout.open("issuedlist.txt", ios::app);
    if (!fout)
    {
        cout << "File could not be opened!" << endl;
        return;
    }
    fout << name << " " << id << " " << issued_book << " " << issue_date << "\n";
    fout.close();
   
}
void student::display_student()
{

    cout << "The student :" << name << " " << "The book : " << issued_book << "Issued date " << issue_date << "\n"
         << endl;
    cout << "\n";
}
void student::search_student(string t)
{
    ifstream fin;
    int x = -1;
    fin.open("issuedlist.txt", ios::in);
    if (!fin)
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, name);
            getline(fin, issued_book);
            getline(fin, issue_date);

            fin >> id;
            fin.ignore();

            if (name == t)
            {
                x = 1;
             
                return;
            }
        }
        if (x == -1)
        {
            cout << "Book not found !!!" << endl;
        }
        fin.close();
    }
}
class book : public items{
    protected:
     string author;
public:
book(){

}
            book(string book_title, string book_author,string book_publisher, int no_copies, int book_rack , int book_position):items( book_title, book_publisher, no_copies,  book_rack ,  book_position){

            author=book_author;
            }
            string get_title();
    string get_author();
    string get_publisher();
    int get_copies();
    int get_position();
    int get_rack();
    void set_copies(int i);
    void storebook();
};



void book::storebook()
{
    ofstream fout;
    fout.open("file1.txt", ios::app);
    if (!fout)
    {
        cout << "File could not be opened!" << endl;
        return;
    }
    fout << title << " " << author << " " << publisher << " " << copies << " " << rack << " " << position << "\n";

    fout.close();
    cout << "Storing book: " << title << " to file." << endl;
}
void book::set_copies(int i)
{
    copies = i;
}

string book::get_title()
{
    return title;
}
string book::get_author()
{
    return author;
}
string book::get_publisher()
{
    return publisher;
}
int book::get_copies()
{
    return copies;
}
int book::get_position()
{
    return position;
}
int book::get_rack()
{
    return rack;
}


class newspaper:public items{
    public:
    newspaper(){

    }
    newspaper(string newspaper_title, string newspaper_publisher, int no_copies, int paper_rack, int magazine_position):items(newspaper_title, newspaper_publisher,no_copies,paper_rack, magazine_position){
     
      }
       string get_title(){
        return title;
       }
      string get_publisher(){
        return publisher;
      }

     int get_copies(){
        return copies;
     }
     int get_rack(){
        return rack;
     }
     int get_position(){
        return position;
     }
};

class magazine: public items{
int edition;
public:
magazine(){

}
magazine(string magazine_title, string magazine_publisher, int no_copies, int magazine_rack, int magazine_position, int magazine_edition):items(magazine_title, magazine_publisher,no_copies,magazine_rack, magazine_position){
    edition=magazine_edition;
}
 string get_title(){
        return title;
       }
      string get_publisher(){
        return publisher;
      }

     int get_copies(){
        return copies;
     }
     int get_rack(){
        return rack;
     }
     int get_position(){
        return position;
     }
     int get_edition(){
        return edition;
     }
   void storemagazine()
{
    ofstream fout;
    fout.open("magazinelist.txt", ios::app);
    if (!fout)
    {
        cout << "File could not be opened!" << endl;
        return;
    }
    fout << title  << " " << publisher << " " << copies << " " << rack << " " << position << " "<<edition<< "\n";

    fout.close();
    cout << "Storing magazine: " << title << " to file." << endl;
}
};
class research_paper : public items{
int year_of_publication;
 string author;
 public:
 research_paper(){

 }
 research_paper(string research_title, string research_publisher, int no_copies, int research_rack, int research_position, int year_of_pub, string research_author):items(research_title,research_publisher,no_copies, research_rack, research_position){
year_of_publication=year_of_pub;
author=research_author;
 }
//  void set_title(string s){

//  }
//  void set_
 string get_title(){
        return title;
       }
      string get_publisher(){
        return publisher;
      }
     string get_author(){
        return author;
     }
     int get_year_of_publication(){
        return year_of_publication;
     }
     int get_copies(){
        return copies;
     }
     int get_rack(){
        return rack;
     }
     int get_position(){
        return position;
     }
    void storepaper()
{
    ofstream fout;
    fout.open("Researchpaperslist.txt", ios::app);
    if (!fout)
    {
        cout << "File could not be opened!" << endl;
        return;
    }
    fout << title  << " " << publisher << " " << author << " "<<copies<<" " << rack << " " << position << " "<<year_of_publication<< "\n";

    fout.close();
    cout << "Storing magazine: " << title << " to file." << endl;
}

};
class user{
protected :
string username;
public:
user(){

}
user(string user_name){
    username=user_name;
}
string get_username(){
    return username;
}
void set_username(string x){
    username=x;
}
};
class admin: public user{
string password;
public:
admin(){

}
admin(string user_name, string pass_word):user(user_name){
    password=pass_word;
}
string get_password(){
    return password;
}
void set_password(string x){
    password=x;
}
};
class log_students : public user{
int id;
public:
log_students(string user_name, int log_id):user(user_name){
    id=log_id;
}
};



class library
{
private:
    admin a;
    book books[max_size];
    student students[max_size];
    newspaper newspapers[max_size];
    research_paper research_papers[max_size];
    magazine magazines[max_size];


    
    int total_requested_books = 0;

public:
    int total_books_in_library = 0;
    int total_newspapers_in_library = 0;
     int total_magazines_in_library = 0;
      int total_research_papers_in_library = 0;
    int issued_students = 0;
    library(int n, string name, string pwd)
    {
        a.set_username(name);
        a.set_password(pwd);
        for (int i = 0; i < n; i++)
        {

            string book_title, book_author, book_publisher;
            int book_copies, book_rack, book_position;

            cout << "Enter the title of the book you want to add " << endl;
            cin >> book_title;

            cout << "Enter the author of the book you want to add " << endl;

            cin >> book_author;
            cout << "Enter the publisher of the book you want to add " << endl;
            cin >> book_publisher;
            cout << "Enter the number of copies the book you want to add " << endl;

            cin >> book_copies;
            do
            {
                cout << "Enter the Rack of the book you want to add " << endl;
                cin >> book_rack;
                cout << "Enter the position of the book you want to add " << endl;
                cin >> book_position;
                if (is_position_occupied(book_rack, book_position))
                {
                    cout << "Error: The rack " << book_rack << " and position " << book_position << " is already occupied. Please choose another position." << endl;
                }
                else
                {
                    break;
                }
            } while (1);
            book x(book_title, book_author, book_publisher, book_copies, book_rack, book_position);
            books[i] = x;
            total_books_in_library++;
            books[i].storebook();
        }
    }
    bool login(string username, string password);
    bool login(string name, int id);
    void add_book();
    void add_newspaper();
    void add_magazine();
    void add_research_paper();
    void issue(string student_name, int student_id);
    void return_book(string book_title, string student_name, int student_id);
    void search(string s);
    void search(string book_title,  string book_publisher);
    void display_list_of_books();
    void display_requested_books();
    void display_newspapers();
     void display_magazines();
     void search_magazine(string t);
     void student_magazine_issue(string s, string t, int i, int x);
     void returnmagazine(string student_name, int id, int x);
    void search_research_paper();
    void issue_research_paper(string, string, int );
    void search_newspaper();
      void display_research_papers();
    bool is_position_occupied(int book_rack, int book_position);
};
// void library::issue_research_paper(string s, string student_name, int id ){

// ifstream fin;
//   bool is_available=false;
//   issue_entites x[max_size];
//   int x_size=0;
//      time_t t = time(0);
//     tm *now = localtime(&t);
//      string current_date = to_string(now->tm_year + 1900) + "-" +
//                           to_string(now->tm_mon + 1) + "-" +
//                           to_string(now->tm_mday);

//       for (int i = 0; i < total_research_papers_in_library; i++) {
//         if (s == research_papers[i].get_title()) {
//             is_available = true;
//             break;
//         }
//     }

//     if (!is_available) {
//         cout << "Research paper not available in the library" << endl;
//         return;
//     }

//     string date_of_res_issue;
//     cout << "Enter the date of issue of res: " << endl;
//     cin >> date_of_res_issue;

//     fin.open("research_issued.txt", ios::in);

//     if (!fin) {
//         cout << "File does not exist" << endl;
//         return;
//     }
    

//      string name, paper_subscribed, date_of_issue;
//     int existing_id;
//     bool already_issued = false;


//      while (fin >> name >> existing_id >> paper_subscribed>> date_of_issue) {
//         x[x_size].name = name;
//         x[x_size].id = existing_id;
//         x[x_size].issued_title = paper_subscribed;
//         x[x_size].issue_date = date_of_issue;
//         x_size++;

//         // Check if the student already has an issued magazine
//         if (name == student_name && existing_id == id) {
//             int days_held = days_elapsed(date_of_issue, current_date);
//             if (days_held >= 15) {
//                // build logic for automatic erase from issuedlist of research_issued.txt

//             }
//         }
//         else{

            
//     // Add new entry for the issued magazine
//     x[x_size].name = student_name;
//     x[x_size].id = id;
//     x[x_size].issued_title = s;
//     x[x_size].issue_date = date_of_res_issue;
//     x_size++;

//     // Write the updated list back to the file
//     ofstream fout("research_issued.txt", ios::out);
//     for (int i = 0; i < x_size; i++) {
//         fout << x[i].name << " " << x[i].id << " " << x[i].issued_title << " " << x[i].issue_date << endl;
//     }
//     fout.close();

//     cout << "research paper issued successfully to " << student_name << " with ID " << id << endl;


//         }
//     }
//     fin.close();


// }
void library::issue_research_paper(string s, string student_name, int id) {
    ifstream fin;
    bool is_available = false;
    issue_entites x[max_size];
    int x_size = 0;
    time_t t = time(0);
    tm *now = localtime(&t);
    string current_date = to_string(now->tm_year + 1900) + "-" +
                          to_string(now->tm_mon + 1) + "-" +
                          to_string(now->tm_mday);

    // Check if the research paper is available
    for (int i = 0; i < total_research_papers_in_library; i++) {
        if (s == research_papers[i].get_title()) {
            is_available = true;
            break;
        }
    }

    if (!is_available) {
        cout << "Research paper not available in the library" << endl;
        return;
    }

    string date_of_res_issue;
    cout << "Enter the date of issue of the research paper: " << endl;
    cin >> date_of_res_issue;

    fin.open("research_issued.txt", ios::in);
    if (!fin) {
        cout << "File does not exist" << endl;
        return;
    }

    string name, paper_subscribed, date_of_issue;
    int existing_id;
    bool already_issued = false;

    // Read the existing entries
    while (fin >> name >> existing_id >> paper_subscribed >> date_of_issue) {
        x[x_size].name = name;
        x[x_size].id = existing_id;
        x[x_size].issued_title = paper_subscribed;
        x[x_size].issue_date = date_of_issue;

        // Check if the student already has an issued research paper
        if (name == student_name && existing_id == id) {
            int days_held = days_elapsed(date_of_issue, current_date);
            if (days_held >= 15) {
                // Automatically remove the overdue entry from the issued list
                cout << "Research paper \"" << paper_subscribed << "\" issued by " << student_name 
                     << " is overdue and will be removed from the issued list." << endl;
                // Do not add this to the new list (effectively removing it)
                continue;
            } else {
                cout << "Cannot issue another research paper before returning the current one." << endl;
                fin.close();
                return;
            }
        }

        // Add current entry to the array to keep it
        x_size++;
    }
    fin.close();

    // Add a new entry for the issued research paper
    x[x_size].name = student_name;
    x[x_size].id = id;
    x[x_size].issued_title = s;
    x[x_size].issue_date = date_of_res_issue;
    x_size++;

    // Write the updated list back to the file
    ofstream fout("research_issued.txt", ios::out);
    for (int i = 0; i < x_size; i++) {
        fout << x[i].name << " " << x[i].id << " " << x[i].issued_title << " " << x[i].issue_date << endl;
    }
    fout.close();

    cout << "Research paper issued successfully to " << student_name << " with ID " << id << endl;
}

void library::student_magazine_issue(string s, string student_name, int id, int m) {
    bool is_available = false;
    issue_entites x[max_size];
    int x_size = 0;
    time_t t = time(0);
    tm *now = localtime(&t);
    string current_date = to_string(now->tm_year + 1900) + "-" +
                          to_string(now->tm_mon + 1) + "-" +
                          to_string(now->tm_mday);

    // Check if the magazine is available
    for (int i = 0; i < total_magazines_in_library; i++) {
        if (s == magazines[i].get_title()) {
            is_available = true;
            break;
        }
    }

    if (!is_available) {
        cout << "Magazine not available in the library" << endl;
        return;
    }

    string date_of_mag_issue;
    cout << "Enter the date of issue of magazine: " << endl;
    cin >> date_of_mag_issue;

    ifstream fin("students_magazine_issued.txt", ios::in);
    if (!fin) {
        cout << "File does not exist" << endl;
        return;
    }

    // Read existing issued data into `x` array
    string name, book_taken, date_of_issue;
    int existing_id;
    bool already_issued = false;

    while (fin >> name >> existing_id >> book_taken >> date_of_issue) {
        x[x_size].name = name;
        x[x_size].id = existing_id;
        x[x_size].issued_title = book_taken;
        x[x_size].issue_date = date_of_issue;
        x_size++;

        // Check if the student already has an issued magazine
        if (name == student_name && existing_id == id) {
            int days_held = days_elapsed(date_of_issue, current_date);
            if (days_held >= 1) {
                cout << "Cannot issue another magazine before the return of the current one" << endl;
                fin.close();
                return;
            }
        }
    }
    fin.close();

    // Add new entry for the issued magazine
    x[x_size].name = student_name;
    x[x_size].id = id;
    x[x_size].issued_title = s;
    x[x_size].issue_date = date_of_mag_issue;
    x_size++;

    // Write the updated list back to the file
    ofstream fout("students_magazine_issued.txt", ios::out);
    for (int i = 0; i < x_size; i++) {
        fout << x[i].name << " " << x[i].id << " " << x[i].issued_title << " " << x[i].issue_date << endl;
    }
    fout.close();

    cout << "Magazine issued successfully to " << student_name << " with ID " << id << endl;
}
void library::returnmagazine(string student_name, int id, int y) {
       time_t t = time(0);
    tm *now = localtime(&t);
    string current_date = to_string(now->tm_year + 1900) + "-" +
                          to_string(now->tm_mon + 1) + "-" +
                          to_string(now->tm_mday);

    issue_entites x[max_size];
    int x_size = 0;
    bool entry_found = false;

    // Read the file and store existing entries
    ifstream fin("students_magazine_issued.txt", ios::in);
    if (!fin) {
        cout << "File does not exist" << endl;
        return;
    }

    string name, book_taken, date_of_issue;
    int existing_id;

    while (fin >> name >> existing_id >> book_taken >> date_of_issue) {
        // Check if the entry matches the student who wants to return the magazine
        if (name == student_name && existing_id == id) {
            entry_found = true;
                int days_held = days_elapsed(date_of_issue, current_date);
            if (days_held >= 1 &&(y==2||y==3)) {
              int fine=(days_held-1)*2;
              cout<<"Fine of amount : "<<fine<<endl;
            }
            cout << "Magazine \"" << book_taken << "\" issued by " << student_name << " is now returned." << endl;
            // Do not add this entry to the `x` array, effectively removing it
        } else {
            // Keep other entries in the array
            x[x_size].name = name;
            x[x_size].id = existing_id;
            x[x_size].issued_title = book_taken;
            x[x_size].issue_date = date_of_issue;
            x_size++;
        }
    }
    fin.close();

    if (!entry_found) {
        cout << "No issued magazine found for " << student_name << " with ID " << id << "." << endl;
        return;
    }

    // Rewrite the updated list back to the file
    ofstream fout("students_magazine_issued.txt", ios::out);
    for (int i = 0; i < x_size; i++) {
        fout << x[i].name << " " << x[i].id << " " << x[i].issued_title << " " << x[i].issue_date << endl;
    }
    fout.close();

    cout << "Updated issued magazine list written to file." << endl;
}

void library::search_research_paper(){
    string name;
    cout << "Enter the title of the research paper you want to search: " << endl;
    cin >> name;
    for(int i=0;i<total_research_papers_in_library;i++){
     if(name==research_papers[i].get_title()){
         cout<<"Research paper : "<< research_papers[i].get_title()<<" "<<" publisher : "<< research_papers[i].get_publisher()<<" Author : "<<research_papers[i].get_author()<<" year of publication : "<< research_papers[i].get_year_of_publication()<<" copies : " <<  research_papers[i].get_copies()<<" rack : "<< research_papers[i].get_rack()<<" position : "<< research_papers[i].get_position()<<endl;
        break;
     }
       
    }

}

void library::search_newspaper(){
       string name;
    cout << "Enter the title of the research paper you want to search: " << endl;
    cin >> name;
  
         for(int i=0;i<total_newspapers_in_library;i++){
              if(name==newspapers[i].get_title()){
                   cout<<"newspaper : "<<newspapers[i].get_title()<<" "<<" publisher : "<<newspapers[i].get_publisher()<<" copies : "<<newspapers[i].get_copies()<<" rack : "<<newspapers[i].get_rack()<<" position : "<<newspapers[i].get_position()<<endl;
              }
       
    }
    


}
void library::search_magazine(string name){
  
string x_title,x_publisher;
    int x_copies, x_rack, x_position, x_edition;
     ifstream fin;
    int x = -1;
    fin.open("magazinelist.txt", ios::in);
    if (!fin)
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while (!fin.eof())
        {

            getline(fin, x_title, ' ');
            getline(fin, x_publisher, ' ');

            fin >> x_copies >> x_rack >> x_position>>x_edition;
            fin.ignore();

            if (x_title == name)
            {
                x = 1;
                 cout << "The title : " << x_title <<" The publisher : "<<x_publisher<<"  The copies : "<<x_copies<<" The rack : "<<x_rack<<" The position : "<<x_position<<"The edition :"<<x_edition<< endl;
               fin.close();
                return;
            }
        }
        if (x == -1)
        {
            cout << "magazine not found !!!" << endl;
        }
        fin.close();
    }
}
void library::add_newspaper(){
 string newspaper_title, newspaper_publisher;
    int paper_copies, paper_rack, paper_position;

    cout << "Enter the title of the newspaper you want to add " << endl;
    cin >> newspaper_title;
       cout << "Enter the publisher of the newspaper you want to add " << endl;
    cin >> newspaper_publisher;
    cout << "Enter the number of copies the newspaper you want to add " << endl;
    cin >> paper_copies;

   
        cout << "Enter the Rack of the newspaper you want to add " << endl;
        cin >> paper_rack;
        cout << "Enter the position of the newspaper you want to add " << endl;
        cin >> paper_position;
     
    newspaper x(newspaper_title, newspaper_publisher, paper_copies, paper_rack, paper_position);
  newspapers[total_newspapers_in_library] = x;
    total_newspapers_in_library++;
}
void library::add_magazine(){
string magazine_title, magazine_publisher;
    int magazine_copies, magazine_rack, magazine_position, magazine_edition;

    cout << "Enter the title of the magazine you want to add " << endl;
    cin >> magazine_title;
       cout << "Enter the publisher of the magazine you want to add " << endl;
    cin >> magazine_publisher;
    cout << "Enter the number of copies the magazine you want to add " << endl;
    cin >> magazine_copies;

  
        cout << "Enter the Rack of the magazine you want to add " << endl;
        cin >> magazine_rack;
        cout << "Enter the position of the magazine you want to add " << endl;
        cin >> magazine_position;
        cout << "Enter the edition of the magazine you want to add " << endl;
        cin >> magazine_edition;

    magazine x(magazine_title, magazine_publisher, magazine_copies, magazine_rack, magazine_position, magazine_edition);
  magazines[total_magazines_in_library] = x;
      magazines[total_magazines_in_library].storemagazine();
    total_magazines_in_library++;
}
void library::add_research_paper(){
string research_title,  research_publisher, research_author;
    int  research_copies,  research_rack, research_position, research_year_of_publication;

    cout << "Enter the title of the research you want to add " << endl;
    cin >>  research_title;
       cout << "Enter the publisher of the research you want to add " << endl;
    cin >>  research_publisher;
        cout << "Enter the author of the research you want to add " << endl;
    cin >>  research_author;
    cout << "Enter the number of copies the research you want to add " << endl;
    cin >>  research_copies;

  
        cout << "Enter the Rack of the research you want to add " << endl;
        cin >>  research_rack;
        cout << "Enter the position of the research you want to add " << endl;
        cin >>  research_position;
        cout << "Enter the year of publication of the research you want to add " << endl;
        cin >> research_year_of_publication;

   research_paper x( research_title,  research_publisher,  research_copies,  research_rack,  research_position,  research_year_of_publication, research_author);

  research_papers[total_research_papers_in_library] = x;
  research_papers[total_research_papers_in_library].storepaper(); 
    total_research_papers_in_library++;
}
void library::search(string book_title)
{
   string x_author,x_title,x_publisher;
    int x_copies, x_rack, x_position;
     ifstream fin;
    int x = -1;
    fin.open("file1.txt", ios::in);
    if (!fin)
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while (!fin.eof())
        {

            getline(fin, x_title, ' ');
            getline(fin, x_author, ' ');
            getline(fin, x_publisher, ' ');

            fin >> x_copies >> x_rack >> x_position;
            fin.ignore();

            if (x_title == book_title)
            {
                x = 1;
                 cout << "The title : " << x_title << " The author : " << x_author <<" The publisher : "<<x_publisher<<"  The copies : "<<x_copies<<" The rack : "<<x_rack<<" The position : "<<x_position<< endl;
               fin.close();
                return;
            }
        }
        if (x == -1)
        {
            cout << "Book not found !!!" << endl;
        }
        fin.close();
    }

}
 void library::search(string book_title, string book_author){
        string x_author,x_title,x_publisher;
    int x_copies, x_rack, x_position;
    ifstream fin;

    fin.open("file1.txt", ios::in);
    
    if (!fin)
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while ( getline(fin, x_title, ' ')) 
        {
           
           
            getline(fin, x_author, ' ');   
            getline(fin, x_publisher, ' '); 

            fin >> x_copies >> x_rack >> x_position;
          fin.ignore();
            
            if(book_title==x_title && book_author==x_author)
            { 
            
          
                cout << "The book " << book_title << " is available in the library" << endl;
                fin.close();  
                return;
        
               
            }
        }
        
      
        
            cout << "Book not found !!!" << endl;
        
        
        fin.close(); 
    }
 
 }
void library::add_book()
{

    string book_title, book_author, book_publisher;
    int book_copies, book_rack, book_position;

    cout << "Enter the title of the book you want to add " << endl;
    cin >> book_title;

    cout << "Enter the author of the book you want to add " << endl;
    cin >> book_author;
    cout << "Enter the publisher of the book you want to add " << endl;

    cin >> book_publisher;
    cout << "Enter the number of copies the book you want to add " << endl;
    cin >> book_copies;
  do
    {
        cout << "Enter the Rack of the newspaper you want to add " << endl;
        cin >> book_rack;
        cout << "Enter the position of the newspaper you want to add " << endl;
        cin >> book_position;
        if (is_position_occupied(book_rack, book_position))
        {
            cout << "Error: The rack " << book_rack << " and position " << book_position << " is already occupied. Please choose another position." << endl;
        }
        else
        {
            break;
        }
    } while (1);
     
       
    book x(book_title, book_author, book_publisher, book_copies, book_rack, book_position);
    books[total_books_in_library] = x;
    books[total_books_in_library].storebook();
    
    total_books_in_library++;
}
void library::display_newspapers(){
    for(int i=0;i<total_newspapers_in_library;i++){
        cout<<"newspaper : "<<newspapers[i].get_title()<<" "<<" publisher : "<<newspapers[i].get_publisher()<<" copies : "<<newspapers[i].get_copies()<<" rack : "<<newspapers[i].get_rack()<<" position : "<<newspapers[i].get_position()<<endl;
    }
}
void library::display_magazines(){
    for(int i=0;i<total_magazines_in_library;i++){
        cout<<"magazine : "<<magazines[i].get_title()<<" "<<" publisher : "<<magazines[i].get_publisher()<<" edition : "<<magazines[i].get_edition()<<" copies : " << magazines[i].get_copies()<<" rack : "<<magazines[i].get_rack()<<" position : "<<magazines[i].get_position()<<endl;
    }
}
void library::display_research_papers(){
    for(int i=0;i<total_research_papers_in_library;i++){

        cout<<"Research paper : "<< research_papers[i].get_title()<<" "<<" publisher : "<< research_papers[i].get_publisher()<<" Author : "<<research_papers[i].get_author()<<" year of publication : "<< research_papers[i].get_year_of_publication()<<" copies : " <<  research_papers[i].get_copies()<<" rack : "<< research_papers[i].get_rack()<<" position : "<< research_papers[i].get_position()<<endl;
    }
}
void library::display_requested_books()
{
  
    if (total_requested_books == 0)
    {
        cout << "The requested book list is empty!!!" << endl;
        return;
    }

    string title;
    cout << "The list of requested books are as follows :" << endl;
   ifstream fin;
   fin.open("requestedlist.txt", ios::in);
   while(fin>>title){
  ;
    cout<<title<<endl;
   }
}
void library::issue(string student_name, int student_id) {
    ifstream fin;
    string book_to_issue;
    string issue_date;
    time_t t = time(0);
    tm *now = localtime(&t);
    string current_date = to_string(now->tm_year + 1900) + "-" +
                          to_string(now->tm_mon + 1) + "-" +
                          to_string(now->tm_mday);

    fin.open("issuedlist.txt", ios::in);
    if (!fin) {
        cout << "File does not exist" << endl;
    } else {
        string name, book_taken, date_of_issue;
        int id;
        while (fin >> name >> id >> book_taken >> date_of_issue) {
            if (name == student_name && id == student_id) {
                int days_held = days_elapsed(date_of_issue, current_date);
                if (days_held == 0) {
                    cout << "Cannot issue the same book consecutively" << endl;
                    return;
                }
                if (days_held > 15) {
                    cout << "You have exceeded the 15-day limit. Please return the book before issuing another." << endl;
                    return;
                } else {
                    cout << "The student already has a book, cannot issue another one." << endl;
                    return;
                }
            }
        }
        fin.close();
    }

    
    cout << "Enter the book to be issued: ";
    cin >> book_to_issue;
    cout << "Enter the date of issue (yyyy-mm-dd): ";
    cin >> issue_date;
    bool check_book = false;

    for (int i = 0; i < total_books_in_library; i++) {
        if (book_to_issue == books[i].get_title()) {
            if (books[i].get_copies() > 0) {
                books[i].set_copies(books[i].get_copies() - 1);
                check_book = true;
                break;
            } else {
                cout << "The book is currently unavailable!" << endl;
                return;
            }
        }
    }

    //add to requested list
    if (!check_book) {
        cout << "The book is not available in the library!" << endl;
        if (total_requested_books < max_size) {
            total_requested_books++;
            ofstream fout1("requestedlist.txt", ios::app);
            fout1 << book_to_issue << endl;
            fout1.close();
            cout << "The book " << book_to_issue << " has been added to the requested books list." << endl;
        } else {
            cout << "The requested books list is full, cannot add more requests." << endl;
        }
        return;
    }

    // Issue the book
    student s(student_name, student_id, book_to_issue, issue_date);
    students[issued_students] = s;
    students[issued_students].set_is_issued(true);
    students[issued_students].set_issued_book(book_to_issue);
    issued_students++;

    // Updating issuedlist.txt
    ofstream fout("issuedlist.txt", ios::out);
    for (int i = 0; i < issued_students; i++) {
        if (students[i].get_is_issued() == true) {
            fout << students[i].get_name() << " " << students[i].get_id() << " "
                 << students[i].get_issued_book() << " " << students[i].get_issued_date() << "\n";
        }
    }
    fout.close();

    // Updating file1
    ofstream fout1("file1.txt", ios::out);
    for (int i = 0; i < total_books_in_library; i++) {
        fout1 << books[i].get_title() << " " << books[i].get_author() << " "
              << books[i].get_publisher() << " " << books[i].get_copies() << " "
              << books[i].get_rack() << " " << books[i].get_position() << "\n";
    }
    fout1.close();

    cout << "Book issued successfully." << endl;
}
void library::return_book(string book_title, string student_name, int student_id) {
    bool student_found = false;
    time_t t = time(0);
    tm *now = localtime(&t);
    string current_date = to_string(now->tm_year + 1900) + "-" +
                          to_string(now->tm_mon + 1) + "-" +
                          to_string(now->tm_mday);

    for (int i = 0; i < issued_students; i++) {
        if (students[i].get_issued_book() == book_title &&
            students[i].get_name() == student_name &&
            students[i].get_id() == student_id && students[i].get_is_issued()==true) {

            student_found = true;
            int elapsed_days = students[i].days_elapsed(students[i].get_issued_date(), current_date);

            // Fine calc
            if (elapsed_days > 15) {
                int fine = (elapsed_days - 15) * 5;
                students[i].set_is_issued(false);

                // Increment book copies
                for (int j = 0; j < total_books_in_library; j++) {
                    if (book_title == books[j].get_title()) {
                        books[j].set_copies(books[j].get_copies() + 1);
                    }
                }

                // Updating book list
                ofstream fout1("file1.txt", ios::out);
                for (int j = 0; j < total_books_in_library; j++) {
                    fout1 << books[j].get_title() << " " << books[j].get_author() << " "
                          << books[j].get_publisher() << " " << books[j].get_copies() << " "
                          << books[j].get_rack() << " " << books[j].get_position() << "\n";
                }
                fout1.close();

                // Updating issuedlist.txt
                ofstream fout("issuedlist.txt", ios::out);
                for (int j = 0; j < issued_students; j++) {
                    if (students[j].get_is_issued() == true) {
                        fout << students[j].get_name() << " " << students[j].get_id() << " "
                             << students[j].get_issued_book() << " " << students[j].get_issued_date() << "\n";
                    }
                }
                fout.close();

                cout << "The book is returned late, the fine amount is: " << fine << endl;
                return;
            } else {
                // No fine, return the book
                students[i].set_is_issued(false);

                // Increment book copies
                for (int j = 0; j < total_books_in_library; j++) {
                    if (book_title == books[j].get_title()) {
                        books[j].set_copies(books[j].get_copies() + 1);
                    }
                }

                // Updating book list
                ofstream fout1("file1.txt", ios::out);
                for (int j = 0; j < total_books_in_library; j++) {
                    fout1 << books[j].get_title() << " " << books[j].get_author() << " "
                          << books[j].get_publisher() << " " << books[j].get_copies() << " "
                          << books[j].get_rack() << " " << books[j].get_position() << "\n";
                }
                fout1.close();

                // Updating issuedlist.txt
                ofstream fout("issuedlist.txt", ios::out);
                for (int j = 0; j < issued_students; j++) {
                    if (students[j].get_is_issued() == true) {
                        fout << students[j].get_name() << " " << students[j].get_id() << " "
                             << students[j].get_issued_book() << " " << students[j].get_issued_date() << "\n";
                    }
                }
                fout.close();

                cout << "The book is returned on time." << endl;
                return;
            }
        }
    }

    if (!student_found) {
        cout << "Error: No record found for student \"" << student_name << "\" with ID " << student_id << " and book: " << book_title << endl;
    }
}
void library::display_list_of_books()
{
    if (total_books_in_library == 0)
    {
        cout << "No books in library " << endl;
        return;
    }
    string title;
    string author;
    string publisher;
    int copies;
    int rack;
    int position;
    ifstream fin;
    fin.open("file1.txt", ios::in);
    while (fin >> title >> author >> publisher >> copies >> rack >> position)
    {
        cout << "The title : " << title << " " << " The author : " << author <<" The publisher : "<<publisher<<" The copies : "<<copies<<" The rack :"<<rack<<" The position : "<<position<< endl;
    }
    fin.close();
}
bool library::is_position_occupied(int book_rack, int book_position)
{
    for (int i = 0; i < total_books_in_library; i++)
    {
        if (books[i].get_position() == book_position && books[i].get_rack() == book_rack)
        {
            return true;
        }
    }
    return false;
}
bool library::login(string name, string pwd)
{
    if (a.get_username() == name && a.get_password() == pwd)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}
bool library::login(string student_name, int student_id)
{  
    int id;
    string name;
      bool is_registered=false;

           ifstream fin;
           fin.open("students.txt", ios::in);
           if(!fin){
            cout<<"File does not exist"<<endl;

           }
           else{
            while(!fin.eof()){
                getline(fin, name, ' ');
                fin>>id;
              
              if(name==student_name && id==student_id){
                is_registered=true;
              }
            }
           }
           fin.close();
 
    return is_registered;
}


int main(){
    


    string username;
    string password;

    
    cout << "Enter the username for the admin of the library:\n";
    cin >> username;
    cout << "Enter the password for the admin of the library:\n";
    cin >> password;

  

    int n;
    cout << "Enter how many books you want to add in the library initially: " << endl;
    cin >> n;
    library lib(n, username, password); 

    int user_type;

    do {
        cout << "\nEnter '1' for Admin login, '2' for Student login, '3' for PHD students login or '0' to Exit: ";
        cin >> user_type;

        switch(user_type) {
            case 1: { 
                string name, pwd;
                cout << "Enter the admin username: " << endl;
                cin >> name;
                cout << "Enter the password for the admin: " << endl;
                cin >> pwd;

                if (lib.login(name, pwd)) { 
                    int choice;
                    do {
                        cout << "\n1 -> Add a book\n"
                             << "2 -> Search for a book\n"
                             << "3 -> Display the books in library\n"
                             << "4 -> Display requested books\n"
                             << "5 -> Add a newspaper\n"
                             << "6 -> Display the newspapers\n"
                             << "7 -> Add a Magazine\n"
                             << "8 -> Display the Magazines\n"
                             << "9 -> search a Magazines\n"
                             << "10 -> Add a Research paper\n"
                             << "11 -> Display the Research papers\n"
                             << "12 -> Search a research paper\n"
                             << "13 -> Search a newspaper\n"
                             << "0 -> Exit\n";
                        cout << "Choose an option from the menu by entering the corresponding number: ";
                        cin >> choice;

                        switch(choice) {
                            case 1:
                                lib.add_book(); 
                                break;
                            case 2: {

                                string title;
                                cout << "Enter the title of the book you want to search: " << endl;
                                cin >> title;
                                lib.search(title); 
                                break;
                            }
                            case 3:
                                lib.display_list_of_books(); 
                                break;
                            case 4:
                                lib.display_requested_books(); 
                                break;
                             case 5:
                            lib.add_newspaper();
                             break;
                             case 6:
                             lib.display_newspapers();
                             break;
                             case 7:
                             lib.add_magazine(); 
                             break;  
                             case 8:
                            lib.display_magazines();
                            break; 
                            case 9:{
                                      string name;
                                cout << "Enter the title of the magazine you want to search: " << endl;
                                cin >> name;
                            lib.search_magazine(name);
                            }
                               
                            break;
                             case 10:
                             lib.add_research_paper();  
                             break; 
                             case 11:
                             lib.display_research_papers(); 
                             break;
                             case 12:
                             lib.search_research_paper();
                             break;
                              case 13:
                             lib.search_newspaper();
                             break;
                            case 0:
                                break; 
                            default:
                                cout << "Invalid option. Please try again." << endl;
                        }
                    } while (choice != 0);
                } else {
                    cout << "Wrong admin credentials." << endl;
                }
                break;
            }

            case 2: { 
                string student_name,student_username;
                int student_id;
                cout<<"Enter the student username:\n";
                cin>>student_username;
                cout << "Enter the student name:\n";
                cin >> student_name;
                cout << "Enter the student ID:\n";
                cin >> student_id;
               

                //  log_students(student_username, student_id);




                bool is_registered = lib.login(student_name, student_id); 
                if (!is_registered) {
                    ofstream fout;
                    fout.open("students.txt", ios::app); 
                    fout << student_name << " " << student_id << endl;
                    cout << "The student has been registered!" << endl;
                    fout.close();
                }

                int choice;
                do {
                    cout << "\n1 -> Issue a book\n"
                         << "2 -> Search for a book\n"
                         << "3 -> Return a book\n"
                          << "4 -> Issue a magazine\n"
                           << "5 -> Return a magazine\n"
                         << "0 -> Exit\n";
                    cout << "Choose an option from the menu by entering the corresponding number: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            lib.issue(student_name, student_id); 
                            break;
                        case 2: 
                        {
                            string title, author, publisher;
                            cout << "Enter the title of the book you want to search: " << endl;
                            cin >> title;
                            cout << "Enter the author of the book: " << endl;
                            cin >> author;
                            lib.search(title,  author); 
                            break;
                        }
                        case 3: 
                        {
                            string book_title;
                            cout << "Enter the book title to return: " << endl;
                            cin >> book_title;
                            lib.return_book(book_title, student_name, student_id); 
                            break;
                        }
                        case 4:
                        {
                            string magazine_title;
                              cout << "Enter the magazine title to issue: " << endl;
                            cin >> magazine_title;
                            lib.student_magazine_issue(magazine_title, student_name, student_id, user_type);
                            break;
                        }
                        case 5:
                        {
                            lib.returnmagazine(student_name, student_id, user_type);
                        }
                        case 0:
                            break; // Exit
                        default:
                            cout << "Invalid option. Please try again." << endl;
                    }
                } while (choice != 0);
                break;
            }
            
            case 3: { 
                string student_name,student_username;
                int student_id;
                cout<<"Enter the student username:\n";
                cin>>student_username;
                cout << "Enter the student name:\n";
                cin >> student_name;
                cout << "Enter the student ID:\n";
                cin >> student_id;
               

                //  log_students(student_username, student_id);




                bool is_registered = lib.login(student_name, student_id); 
                if (!is_registered) {
                    ofstream fout;
                    fout.open("students.txt", ios::app); 
                    fout << student_name << " " << student_id << endl;
                    cout << "The student has been registered!" << endl;
                    fout.close();
                }

                int choice;
                do {
                    cout << "\n1 -> Issue a Magazine\n"
                         << "2 -> Return a Magazine\n"
                        <<"3 -> Issue a Research paper\n"
                         << "0 -> Exit\n";
                    cout << "Choose an option from the menu by entering the corresponding number: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:{
                                 string magazine_title;
                              cout << "Enter the magazine title to issue: " << endl;
                            cin >> magazine_title;
                            lib.student_magazine_issue(magazine_title, student_name, student_id, user_type);
                            
                            break;
                        }
                          
                        case 2: 
                        {
                              lib.returnmagazine(student_name, student_id, user_type);
                              break;
                        }
                        case 3:
                        {
                               string paper_title;
                              cout << "Enter the research paper title to issue: " << endl;
                            cin >> paper_title;
                            lib.issue_research_paper( paper_title,student_name, student_id);
                            break;
                        }
                        case 0:
                            break; // Exit
                        default:
                            cout << "Invalid option. Please try again." << endl;
                    }
                } while (choice != 0);
                break;
            }
            case 0:
                cout << "Exiting the system." << endl;
                break;

            default:
                cout << "Invalid option. Please enter 1 for Admin, 2 for Student, or 0 to Exit." << endl;
        }
    } while (user_type != 0);
          ofstream fout1;
             fout1.open("file1.txt", ios::trunc);
             fout1.close();

              ofstream fout2;
             fout2.open("issuedlist.txt", ios::trunc);
             fout2.close();

              ofstream fout3;
             fout3.open("students.txt", ios::trunc);
             fout3.close();

             ofstream fout4;
              fout4.open("requestedlist.txt", ios::trunc);
             fout4.close();

               ofstream fout5;
              fout5.open("magazinelist.txt", ios::trunc);
             fout5.close();

       ofstream fout6;
              fout6.open("students_magazine_issued.txt", ios::trunc);
             fout6.close();


          ofstream fout7;
              fout7.open("research_issued.txt", ios::trunc);
             fout7.close();

               ofstream fout8;
              fout8.open("Researchpaperslist.txt", ios::trunc);
             fout8.close();




    return 0;
}

