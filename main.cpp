#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include <conio.h>
#include<iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
using namespace std;
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````````````````````` CLASS USER ````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class user
{
private:
    string name;
    string email;
    string password;
public:
    user();
    user(string n, string e);
    void setName(string newName);
    void setEmail(string newEmail);
    void setPassword(string newPassword);
    string getName() const;
    string getEmail() const;
    string getPassword() const;
    bool check_reg_password(const string& password);
    string get_password();
    void registration();
    bool check_username(string s);
    bool login(string username, string pass);
};
//``````
user::user()
{
    name = "";
    email = "";
    password = "";

}
// PARAMETERIZED `
user::user(string n, string e)
{
    this->name = n;
    this->email = e;
}
//`````` SETTERS ``
void user::setName(string newName)
{
    name = newName;
}
void user::setEmail(string newEmail)
{
    email = newEmail;
}
void user::setPassword(string newPassword)
{
    password = newPassword;
}

// GETTERS `
string user::getName() const
{
    return name;
}

string user::getEmail() const
{
    return email;
}

string user::getPassword() const
{
    return password;
}

//`````` CHECKING PASSWORD `
bool user::check_reg_password(const string& password)
{
    int length = password.length();

    if (length < 6)
    {
        cout << "Enter a password of length 6 or above " << endl << endl;
        return false;
    }
    else
    {
        bool upper_case = false;
        bool lower_case = false;
        bool digits = false;
        bool special = false;

        for (int i = 0; i < length; i++)
        {
            if (password[i] >= 65 && password[i] < 91)
            {
                upper_case = true;
            }

            if (password[i] >= 97 && password[i] <= 122)
            {
                lower_case = true;
            }

            if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
            {
                special = true;
            }

            if (password[i] >= 48 && password[i] <= 57)
            {
                digits = true;
            }
        }

        if (upper_case && lower_case && digits && special)
        {
            return true;
        }
        else
        {
            cout << "Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character." << endl << endl;
            return false;
        }
    }
}
// GET PASSWORD  `
string user::get_password()
{
    string password;
    while (true)
    {
        cout << "Enter the password: ";
        getline(cin, password);
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        if (check_reg_password(password))
        {
            return password;
        }
    }
}
//`````` REGISTRATION `
void user::registration()
{
    //username stored in username.txt
    ofstream file_user("username.txt");
    if (file_user.is_open())
    {
        file_user << name << endl;
        file_user.close();
    }
    password = get_password();
    ofstream file_pass("password.txt");
    if (file_pass.is_open())
    {
        file_pass << password << endl;
        file_pass.close();
    }
}
//` CHECK USERNAME `
bool user::check_username(string s)
{
    ifstream file("username.txt");
    if (file.is_open())
    {
        string file_username;
        while (getline(file, file_username))
        {
            if (s == file_username)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    else
    {
        cout << "Failed to open the username file." << endl;
    }
    return false;
}

//``````` LOGIN `
bool user::login(string username, string pass)
{
    ifstream user_file("username.txt");
    ifstream pass_file("password.txt");

    if (!user_file.is_open() || !pass_file.is_open())
    {
        cout << "\t\t\t\t\tError opening username or password file." << endl;
        return false;
    }

    string file_username, file_password;
    bool found = false;

    while (getline(user_file, file_username) && getline(pass_file, file_password))
    {
        if (username == file_username && pass == file_password)
        {
            cout << endl;
            cout << "\t\t\t\t\tLogin Successful!!" << endl;
            found = true;
            break;
        }
    }
    user_file.close();
    pass_file.close();
    if (!found)
    {
        cout << endl;
        cout << "\t\t\t\tIncorrect username or password. Login failed :( " << endl;
    }
    return found;
}
string read_pass()
{
    char check;
    string pwd;
    for (;;)
    {
        check = _getch();
        if (check == '\r')
        {
            break;
        }
        if (check == '\b')
        {
            if (!pwd.empty())
            {
                pwd.pop_back();
                cout << "\b \b" << endl;
            }
        }
        else
        {
            pwd.push_back(check);
            cout << '*';
        }
    }
    return pwd;
}
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````````````````````` CLASS BEGINNER ````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Beginner :public user
{
public:
    Beginner() {}
    void implement()
    {
        while (true)
        {
        label:
            cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "____________________________" << endl;
            cout << "|        LRT Guitar's      |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   1: Essential Knowledge |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   2: Chords              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   3: Scales              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   4: Exit                |" << endl;
            cout << "|__________________________|" << endl;
            cout << endl;
            int q;
            cout << "Enter: ";
            cin >> q;
            cin.ignore();
            cout << endl << endl;
            //`````````````````````````````````` knowledge `````````````````````````````````
            if (q == 1)
            {
                cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t_________________________________" << endl;
                cout << "\t\t\t\t\t|      Essential Knowledge      |" << endl;
                cout << "\t\t\t\t\t|_______________________________|" << endl;
                cout << "1. Parts of the Guitar:" << endl;
                cout << "- Body" << endl;
                cout << "- Neck" << endl;
                cout << "- Headstock" << endl;
                cout << "- Frets" << endl;
                cout << "- Strings" << endl;
                cout << endl;

                cout << "2. Holding the Guitar:" << endl;
                cout << "- Sit or stand comfortably" << endl;
                cout << "- Support the guitar on your leg" << endl;
                cout << "- Relax your shoulders and wrists" << endl;
                cout << endl;

                cout << "3. Tuning the Guitar:" << endl;
                cout << "- Learn the names of the strings (E, A, D, G, B, e)" << endl;
                cout << "- Use a tuner for accurate tuning" << endl;
                cout << endl;

                cout << "4. Basic Chords:" << endl;
                cout << "- Start with easy chords like C, G, D, E, and A" << endl;
                cout << "- Practice smooth chord transitions" << endl;
                cout << endl;

                cout << "5. Strumming Patterns:" << endl;
                cout << "- Downstrokes and upstrokes" << endl;
                cout << "- Experiment with different rhythms" << endl;
                cout << endl;

                cout << "6. Basic Guitar Tabs:" << endl;
                cout << "- Read tablature for simple songs" << endl;
                cout << "- Understand numbers on the lines represent frets" << endl;
                cout << endl;

                cout << "7. Practice Routine:" << endl;
                cout << "- Dedicate time daily for practice" << endl;
                cout << "- Focus on chords, strumming, and simple songs" << endl;
                cout << endl;

                cout << "8. Resources for Learning:" << endl;
                cout << "- Online tutorials" << endl;
                cout << "- Guitar apps" << endl;
                cout << "- Songbooks" << endl;
                cout << "- Join a local music community" << endl;
            }
            //```````````````````````````` Chords ```````````````````````````````
            else if (q == 2)
            {

                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Chords          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "Chords are combinations of three or more notes played together. The most basic chord is the triad, which consists of a root note, a third and a fifth." << endl << endl;
                cout << endl << endl;
                cout << "__________________________________" << endl;
                cout << "|    Part 1: C & D & E Chords    |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 2: F & G & A Chords    |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 3: B Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << endl;
                int part;
                cout << "Enter the part: ";
                cin >> part;
                cin.ignore();
                if (part == 1)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        C       " << "\t\t\t        Cm      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__o__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\to__o__|__|__|__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t         D      " << "\t\t\t       Dm     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        E       " << "\t\t\t        Em     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__o__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Em6      " << "\t\t\t       Em7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__o__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                if (part == 2)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        F       " << "\t\t\t        Fm       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__|__|__|__o__o" << "\t\t\to__|__|__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__o__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       F#7      " << "\t\t\t        F#      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\to__|__|__|__o__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__o__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        F#m     " << "\t\t\t        Fdim   " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\to__|__|__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t         G      " << "\t\t\t       Gm      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\to__|__|__o__o__o" << endl;
                    cout << "\t\t\t|__o__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\to__|__|__|__|__o" << "\t\t\t|__o__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       G#m      " << "\t\t\t        G+      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__|__|__o__o__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Gm7     " << "\t\t\t        G9     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__|__o__o__o__o" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__o__|__|__|__|" << "\t\t\to__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        A        " << "\t\t\t        Am       " << endl;
                    cout << "\t\t\t ________________" << "\t\t\t ________________" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__o__|" << endl;
                    cout << "\t\t\t |__|__o__o__o__|" << "\t\t\t |__|__o__o__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Ab7      " << "\t\t\t        Ab+      " << endl;
                    cout << "\t\t\t ________________" << "\t\t\t ________________" << endl;
                    cout << "\t\t\t |__|__o__o__o__|" << "\t\t\t |__|__|__o__o__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__o" << "\t\t\t |__|__o__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\t\t\t |__|__|__|__|__|" << "\t\t\t |__|__|__|__|__|" << endl;
                    cout << "\n\n\n";

                }
                if (part == 3)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t         B      " << "\t\t\t        Bm      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__|__|__|__o" << "\t\t\t|__o__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__o__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Bb      " << "\t\t\t       Bbm      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__o__|__|__|__o" << "\t\t\t|__o__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__o__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
            }

            else if (q == 3)
            {
                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Scales          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "A scale is a specific sequence of notes that creates a particular sound or mood.It consists of seven notes and follows a specific pattern of whole and half steps." << endl << endl;
                cout << endl << endl;
                string root_note;
                string scale = "";
                int root;
                string notes[12];
                string order[7];
                do
                {
                    cout << "\t\t\t\t\tWhich scale do you want (Major / Minor): " << endl << endl;
                    cin >> root_note >> scale;
                    cout << "Root scale: " << root_note << " " << scale << endl;
                    cout << endl;

                    string notesArray[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

                    root = -1;
                    for (int i = 0; i < 12; i++)
                    {
                        if (notesArray[i] == root_note)
                        {
                            root = i;
                            break;
                        }
                    }

                    if (root == -1)
                    {
                        cout << "Invalid root note entered." << endl;
                        // return 0;
                    }

                    for (int i = root, j = 0; i < 12; i++, j++)
                    {
                        notes[j] = notesArray[i];
                    }
                    for (int i = 0, j = 12 - root; i < root; i++, j++)
                    {
                        notes[j] = notesArray[i];
                    }

                    const int major_scale[] = { 0, 2, 4, 5, 7, 9, 11 };
                    const int minor_scale[] = { 0, 2, 3, 5, 7, 8, 10 };


                    const int* selected_scale = nullptr;
                    int size_scale = 0;

                    if (scale == "Major" || scale == "major" || scale == "M")
                    {
                        selected_scale = major_scale;
                        size_scale = 7;
                    }
                    else if (scale == "Minor" || scale == "minor" || scale == "m")
                    {
                        selected_scale = minor_scale;
                        size_scale = 7;
                    }

                    else
                    {
                        cout << "Invalid scale entered." << endl;
                        // return 0;
                    }

                    for (int i = 0; i < size_scale; i++)
                    {
                        order[i] = notes[selected_scale[i]];
                    }

                    for (int i = 0; i < size_scale; i++)
                    {
                        cout << order[i] << " ";
                    }

                    cout << endl << endl;
                    break;
                } while (root_note != "e" || root_note != "E");

                if (root_note == "e" || root_note == "E")
                {
                    goto label;
                }
            }

            else if (q == 4)
            {
                break;
            }

        }

    }
};
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````````````````````` CLASS INTERMEDIATE ````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Intermediate :public user
{
public:
    Intermediate() {}
    void implement()
    {
        while (true)
        {
        tashi1:
            cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "____________________________" << endl;
            cout << "|        LRT Guitar's      |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   1: Essential Knowledge |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   2: Chords              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   3: Scales              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   4: Exit                |" << endl;
            cout << "|__________________________|" << endl;
            cout << endl;
            int inter;
            cout << "Enter: ";
            cin >> inter;
            cin.ignore();
            cout << endl << endl;
            //`````````````````````````````````` knowledge `````````````````````````````````
            if (inter == 1)
            {
                cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t_________________________________" << endl;
                cout << "\t\t\t\t\t|      Essential Knowledge      |" << endl;
                cout << "\t\t\t\t\t|_______________________________|" << endl;
                cout << endl;
                cout << "1. Advanced Chords and Voicings:" << endl;
                cout << "- Explore advanced chords beyond the basics, such as **maj7, m7, 9, 11,** and **13** chords." << endl;
                cout << "- Learn different voicings and inversions to enhance your chord vocabulary." << endl;
                cout << endl;

                cout << "2. Fingerstyle Techniques:" << endl;
                cout << "- Dive into fingerstyle playing, incorporating techniques like fingerpicking and thumb-slapping." << endl;
                cout << "- Explore classical fingerstyle patterns and adapt them to various genres." << endl;
                cout << endl;

                cout << "3. Scale Mastery:" << endl;
                cout << "- Master major, minor, pentatonic, and modal scales across the fretboard." << endl;
                cout << "- Understand scale relationships and use them for improvisation and soloing." << endl;
                cout << endl;

                cout << "4. Advanced Strumming Patterns:" << endl;
                cout << "- Develop intricate strumming patterns, including syncopation and percussive strumming." << endl;
                cout << "- Experiment with muting techniques and rhythmic variations." << endl;
                cout << endl;

                cout << "5. Music Theory Integration:" << endl;
                cout << "- Deepen your understanding of music theory, including chord progressions and harmony." << endl;
                cout << "- Apply modes and more advanced theoretical concepts to your playing." << endl;
                cout << endl;

                cout << "6. Improvisation Skills:" << endl;
                cout << "- Work on your ability to improvise by combining scales, arpeggios, and phrasing." << endl;
                cout << "- Play along with backing tracks to develop improvisational confidence." << endl;
                cout << endl;

                cout << "7. Songwriting and Composition:" << endl;
                cout << "- Start exploring songwriting by creating your chord progressions and melodies." << endl;
                cout << "- Understand song structures and experiment with various genres." << endl;
                cout << endl;

                cout << "8. Ear Training and Transcription:" << endl;
                cout << "- Train your ear to recognize chords, melodies, and musical intervals." << endl;
                cout << "- Practice transcription by learning songs directly from recordings." << endl;
                cout << endl;

                cout << "9. Gear Exploration:" << endl;
                cout << "- Experiment with different guitar types, amplifiers, and effects pedals." << endl;
                cout << "- Understand how gear choices can impact your tone and playing style." << endl;
            }
            //```````````````````````````` Chords ```````````````````````````````
            else if (inter == 2)
            {
                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Chords          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "Chords are combinations of three or more notes played together. The most basic chord is the triad, which consists of a root note, a third and a fifth." << endl << endl;
                cout << endl << endl;
                cout << "__________________________________" << endl;
                cout << "|    Part 1: C & D & E Chords    |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 2: F & G & A Chords    |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 3: B Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << endl;
                int parts;
                cout << "Enter the part: ";
                cin >> parts;
                cin.ignore();
                if (parts == 1)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       Cmaj7    " << "\t\t\t        C+      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__o__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        C#m     " << "\t\t\t       Cm7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       Dmaj7    " << "\t\t\t       Ddim     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        D+      " << "\t\t\t       Dm6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t      Eb+       " << "\t\t\t        E6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__o__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        E7      " << "\t\t\t       E9  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__o__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                if (parts == 2)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t      F#m7      " << "\t\t\t        Fmaj7       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__o__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Fm6      " << "\t\t\t        Fm7       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__o__o" << "\t\t\to__|__o__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       G6       " << "\t\t\t        G7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__o__|__|__|__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\to__|__|__|__|__|" << "\t\t\to__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";

                    cout << "\t\t\t       Gmaj7    " << "\t\t\t       Gm6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__o__o" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       Am6      " << "\t\t\t       Am7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__|__o" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       A+       " << "\t\t\t       Amaj7   " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__o__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                if (parts == 3)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        B6      " << "\t\t\t        B7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\to__o__|__|__|__|" << "\t\t\t|__o__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       B9       " << "\t\t\t      Bm6  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__|__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Bm7       " << "\t\t\t      Bmaj7     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__o__|__o__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
            }

            else if (inter == 3)
            {
                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Scales          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "A scale is a specific sequence of notes that creates a particular sound or mood.It consists of seven notes and follows a specific pattern of whole and half steps." << endl << endl;
                cout << endl << endl;
                string root_note;
                string scale = "";
                int root;
                string notes[12];
                string order[7];
                do
                {
                    cout << "\t\t\t\t\tWhich scale do you want (Major / Minor / Melodic ): " << endl << endl;
                    cin >> root_note >> scale;
                    cout << "Root scale: " << root_note << " " << scale << endl;
                    cout << endl;

                    string notesArray[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

                    root = -1;
                    for (int i = 0; i < 12; i++)
                    {
                        if (notesArray[i] == root_note)
                        {
                            root = i;
                            break;
                        }
                    }

                    if (root == -1)
                    {
                        cout << "Invalid root note entered." << endl;
                        //return 0;
                    }

                    for (int i = root, j = 0; i < 12; i++, j++)
                    {
                        notes[j] = notesArray[i];
                    }
                    for (int i = 0, j = 12 - root; i < root; i++, j++)
                    {
                        notes[j] = notesArray[i];
                    }

                    const int major_scale[] = { 0, 2, 4, 5, 7, 9, 11 };
                    const int minor_scale[] = { 0, 2, 3, 5, 7, 8, 10 };
                    const int melodic_scale[] = { 0, 2, 3, 5, 7, 9, 11 };
                    const int* selected_scale = nullptr;
                    int size_scale = 0;
                    if (scale == "Major" || scale == "major")
                    {
                        selected_scale = major_scale;
                        size_scale = 7;
                    }
                    else if (scale == "Minor" || scale == "minor")
                    {
                        selected_scale = minor_scale;
                        size_scale = 7;
                    }
                    else if (scale == "Melodic" || scale == "melodic")
                    {
                        selected_scale = melodic_scale;
                        size_scale = 7;
                    }
                    else
                    {
                        cout << "Invalid scale entered." << endl;
                    }
                    for (int i = 0; i < size_scale; i++)
                    {
                        order[i] = notes[selected_scale[i]];
                    }
                    for (int i = 0; i < size_scale; i++)
                    {
                        cout << order[i] << " ";
                    }
                    cout << endl << endl;
                    break;
                } while (root_note != "e" || root_note != "E");

                if (root_note == "e" || root_note == "E")
                {
                    goto tashi1;
                }
            }
            else if (inter == 4)
            {
                break;
            }
        }
    }
};
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````````````````````` CLASS EXPERT```````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Expert :public user
{
public:
    Expert() {}
    void implement()
    {
        while (true)
        {
        a:
            cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "____________________________" << endl;
            cout << "|        LRT Guitar's      |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   1: Essential Knowledge |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   2: Chords              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   3: Scales              |" << endl;
            cout << "|__________________________|" << endl;
            cout << "|   4: Exit                |" << endl;
            cout << "|__________________________|" << endl;
            cout << endl;
            int expert;
            cout << "Enter: ";
            cin >> expert;
            cin.ignore();
            cout << endl << endl;
            //`````````````````````````````````` knowledge `````````````````````````````````
            if (expert == 1)
            {
                cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t_________________________________" << endl;
                cout << "\t\t\t\t\t|      Essential Knowledge      |" << endl;
                cout << "\t\t\t\t\t|_______________________________|" << endl;
                cout << endl;
                cout << "1. Mastery of Complex Chords and Voicings:" << endl;
                cout << "- Explore intricate chords, including augmented, diminished, and extended chords like maj7, m7, 9, 11, and 13." << endl;
                cout << "- Develop a deep understanding of different voicings and inversions to enrich your harmonic palette." << endl;
                cout << endl;

                cout << "2. Virtuoso Fingerstyle Techniques:" << endl;
                cout << "- Elevate your fingerstyle playing with advanced techniques, such as intricate fingerpicking patterns and thumb-slapping." << endl;
                cout << "- Adapt classical fingerstyle patterns to push the boundaries of your playing in various genres." << endl;
                cout << endl;

                cout << "3. Expertise in Scale Mastery:" << endl;
                cout << "- Master major, minor, pentatonic, and modal scales across the entire fretboard with precision and fluidity." << endl;
                cout << "- Utilize advanced scale relationships for sophisticated improvisation and soloing." << endl;
                cout << endl;

                cout << "4. Mastery of Advanced Strumming Patterns:" << endl;
                cout << "- Develop complex strumming patterns, incorporating syncopation, percussive elements, and intricate muting techniques." << endl;
                cout << "- Experiment with rhythmic variations that showcase your advanced strumming proficiency." << endl;
                cout << endl;

                cout << "5. Integration of Cutting-Edge Music Theory:" << endl;
                cout << "- Deepen your comprehension of advanced music theory, including intricate chord progressions, harmonic structures, and modal interchange." << endl;
                cout << "- Apply advanced theoretical concepts to elevate the sophistication of your musical expressions." << endl;
                cout << endl;

                cout << "6. Mastery of Improvisational Skills:" << endl;
                cout << "- Exhibit expert-level improvisation by seamlessly combining scales, arpeggios, and nuanced phrasing." << endl;
                cout << "- Showcase your improvisational prowess by confidently playing alongside challenging backing tracks." << endl;
                cout << endl;

                cout << "7. Advanced Songwriting and Composition:" << endl;
                cout << "- Showcase your creativity through sophisticated songwriting, crafting unique chord progressions, intricate melodies, and innovative structures." << endl;
                cout << "- Experiment with diverse genres, demonstrating your versatility as a skilled composer." << endl;
                cout << endl;

                cout << "8. Advanced Ear Training and Transcription:" << endl;
                cout << "- Hone your ear to recognize complex chords, intricate melodies, and challenging musical intervals." << endl;
                cout << "- Demonstrate your advanced transcription skills by learning intricate songs directly from recordings." << endl;
                cout << endl;

                cout << "9. Cutting-Edge Gear Exploration:" << endl;
                cout << "- Experiment with a wide array of guitar types, high-end amplifiers, and sophisticated effects pedals." << endl;
                cout << "- Showcase your deep understanding of gear choices, illustrating how they intricately impact your tone and playing style." << endl;

            }
            //```````````````````````````` Chords ```````````````````````````````
            else if (expert == 2)
            {
                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Chords          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "Chords are combinations of three or more notes played together. The most basic chord is the triad, which consists of a root note, a third and a fifth." << endl << endl;
                cout << endl << endl;
                cout << "__________________________________" << endl;
                cout << "|    Part 1: C Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 2: D Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 3: E Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 4: F Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 5: G Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 6: A Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|    Part 7: B Chords            |" << endl;
                cout << "|________________________________|" << endl;
                cout << endl;
                int parts1;
                cout << "Enter the part: ";
                cin >> parts1;
                cin.ignore();
                if (parts1 == 1)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        C6      " << "\t\t\t        C7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__o__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        C9      " << "\t\t\t        Cm6  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__o__|__o__o__o" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Cdim    " << "\t\t\t       Csus     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      C#m6      " << "\t\t\t      C#m7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      C#dim     " << endl;
                    cout << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n";
                }
                else if (parts1 == 2)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t      D7        " << "\t\t\t       D9       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\to__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Dsus      " << "\t\t\t        Db      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__o" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Db6       " << "\t\t\t      Db7       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Db9      " << "\t\t\t      Dbmaj7    " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__o__|__o__o__o" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Db+      " << "\t\t\t      Dbsus     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                else if (parts1 == 3)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        Eb      " << "\t\t\t      Ebm       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Eb6       " << "\t\t\t       Eb7  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n";
                    cout << "\t\t\t      Eb9       " << "\t\t\t      Ebm6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__o__o__|__|__o" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Ebm7      " << "\t\t\t      Ebmaj7 " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Ebdim     " << "\t\t\t      Ebsus     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Emaj7    " << "\t\t\t      Edim      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__|__|__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        E+      " << "\t\t\t       Esus     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__o__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n";
                }
                else if (parts1 == 4)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t        F6      " << "\t\t\t        F7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__o" << "\t\t\to__|__o__|__o__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        F9      " << "\t\t\t        F++       " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__o" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Fsus    " << "\t\t\t       F#9      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__o" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__|__o" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      F#m6      " << "\t\t\t       F#dim    " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__o__o" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                else if (parts1 == 5)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       G#m6     " << "\t\t\t      G#m7      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      G#dim     " << "\t\t\t        Gb+     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        Gb6     " << "\t\t\t      Gbmaj7    " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__o__|" << "\t\t\t|__|__o__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Gbsus    " << "\t\t\t       Gdim     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__o" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Gsus     " << endl;
                    cout << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                else if (parts1 == 6)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       Ab       " << "\t\t\t       Ab6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__|__|__|__o__o" << "\t\t\t|__|__o__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__o__o__|__|__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\to__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Ab9      " << "\t\t\t      Abmaj7    " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__o__o__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Absus     " << "\t\t\t       A6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__o__o__o__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        A7      " << "\t\t\t       A9      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__o__o__|" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Adim      " << "\t\t\t       Asus  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                }
                else if (parts1 == 7)
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t       Bb6      " << "\t\t\t      Bb7  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__o__|__|__|__|" << "\t\t\t|__|__o__o__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__o__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Bb9       " << "\t\t\t      Bbm6      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\to__o__|__o__o__o" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Bbm7     " << "\t\t\t      Bbmaj7 " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__o__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__o__|__|" << endl;
                    cout << "\t\t\t|__|__o__o__|__o" << "\t\t\t|__|__o__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t      Bbdim     " << "\t\t\t        B+      " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__o__|" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__|__o" << "\t\t\t|__|__|__o__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t       Bbsus    " << "\t\t\t      Bdim  " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__o__|__o" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__o__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\n\n\n";
                    cout << "\t\t\t        B+      " << "\t\t\t      Bsus     " << endl;
                    cout << "\t\t\t________________" << "\t\t\t________________" << endl;
                    cout << "\t\t\t|__|__|__|__|__o" << "\t\t\t|__|__|__|__|__o" << endl;
                    cout << "\t\t\t|__|__|__o__o__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__o__|__|__|" << "\t\t\t|__|__o__o__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__o__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                    cout << "\t\t\t|__|__|__|__|__|" << "\t\t\t|__|__|__|__|__|" << endl;
                }
            }
            else if (expert == 3)
            {
                cout << "\t\t\t\t\t__________________________" << endl;
                cout << "\t\t\t\t\t|        Scales          |" << endl;
                cout << "\t\t\t\t\t|________________________|" << endl;
                cout << endl;
                cout << "A scale is a specific sequence of notes that creates a particular sound or mood.It consists of seven notes and follows a specific pattern of whole and half steps." << endl << endl;
                cout << endl << endl;
                string root_note;
                string scale = "";
                int root;
                string notes[12];
                string order[7];
                cout << "\t\t\t\t\tWhich scale do you want (Major / Minor / Melodic / Suspended): " << endl << endl;
                cin >> root_note >> scale;
                cout << "Root scale: " << root_note << " " << scale << endl;
                cout << endl;
                string notesArray[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
                root = -1;
                for (int i = 0; i < 12; i++)
                {
                    if (notesArray[i] == root_note)
                    {
                        root = i;
                        break;
                    }
                }
                if (root == -1)
                {
                    cout << "Invalid root note entered." << endl;
                }
                for (int i = root, j = 0; i < 12; i++, j++)
                {
                    notes[j] = notesArray[i];
                }
                for (int i = 0, j = 12 - root; i < root; i++, j++)
                {
                    notes[j] = notesArray[i];
                }

                const int major_scale[] = { 0, 2, 4, 5, 7, 9, 11 };
                const int minor_scale[] = { 0, 2, 3, 5, 7, 8, 10 };
                const int melodic_scale[] = { 0, 2, 3, 5, 7, 9, 11 };
                const int suspended_scale[] = { 0, 2, 5 };
                const int* selected_scale = nullptr;
                int size_scale = 0;
                if (scale == "Major" || scale == "major")
                {
                    selected_scale = major_scale;
                    size_scale = 7;
                }
                else if (scale == "Minor" || scale == "minor")
                {
                    selected_scale = minor_scale;
                    size_scale = 7;
                }
                else if (scale == "Melodic" || scale == "melodic")
                {
                    selected_scale = melodic_scale;
                    size_scale = 7;
                }
                else if (scale == "Suspended" || scale == "suspended")
                {
                    selected_scale = suspended_scale;
                    size_scale = 3;
                }
                else
                {
                    cout << "Invalid scale entered." << endl;
                }

                for (int i = 0; i < size_scale; i++)
                {
                    order[i] = notes[selected_scale[i]];
                }

                for (int i = 0; i < size_scale; i++)
                {
                    cout << order[i] << " ";
                }

                cout << endl << endl;
                break;
                goto a;
            }
            else if (expert == 4)
            {
                break;
            }
        }
    }
};




class LRT_GAME
{
public:
    string const* t_symbols;
    const int rows = 10;
    const int cols = 10;
    int t_notes;
    string grid[10][10];
    bool revealed[10][10];
    const string beginnerNoteSymbols[3] = { "C", "D", "E" };
    const string intermediateNoteSymbols[7] = { "C", "D", "E", "F", "G", "A", "B" };
    const string expertNoteSymbols[12] = { "C", "D", "E", "F", "G", "A", "B", "C#", "D#", "F#", "G#", "A#" };
    const int noteFrequencies[12] = { 440, 494, 554, 587, 659, 740, 831, 466, 53, 622, 698, 784 };

    vector<string> playedNotes;

    void initialize_grid(const string noteSymbols[], int count) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = " ";
                revealed[i][j] = false;
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int noteIndex = rand() % count;
                grid[i][j] = noteSymbols[noteIndex];
            }
        }
    }

    void print_grid(bool notes) const {
        cout << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t_________________________" << endl;
        cout << "\t\t\t\t\t\t|        LRT GAME       |" << endl;
        cout << "\t\t\t\t\t\t|_______________________|" << endl;
        cout << endl << endl;
        cout << "  ";
        for (int j = 0; j < cols; ++j) {
            cout << " " << j << "  ";
        }
        cout << endl;

        for (int i = 0; i < rows; ++i) {
            cout << i << "  ";
            for (int j = 0; j < cols; ++j) {
                if (revealed[i][j] || notes) {
                    cout << grid[i][j] << "  ";
                }
                else {
                    cout << "*   ";
                }
            }
            cout << endl;
        }
    }

    void playNote(int x, int y) {
        if (!revealed[x][y]) {
            string noteSymbol = grid[x][y];
            int noteIndex = -1;

            for (int i = 0; i < t_notes; ++i) {
                if (t_symbols[i] == noteSymbol) {
                    noteIndex = i;
                    break;
                }
            }

            if (noteIndex != -1) {
                int frequency = noteFrequencies[noteIndex];
                cout << endl;
                cout << "Playing note: " << noteSymbol << endl << endl;
                playSound(frequency, 800);
                revealed[x][y] = true;

                playedNotes.push_back(noteSymbol); // Add played note to the vector
            }
            else {
                cout << "Invalid note symbol. Try again." << endl;
            }
        }
        else {
            cout << "It is already used :(. Try another" << endl;
        }
    }

    LRT_GAME(int difficulty) {
        srand(time(0));

        switch (difficulty) {
        case 1:
            t_notes = 3;
            t_symbols = beginnerNoteSymbols;
            initialize_grid(beginnerNoteSymbols, t_notes);
            break;
        case 2:
            t_notes = 7;
            t_symbols = intermediateNoteSymbols;
            initialize_grid(intermediateNoteSymbols, t_notes);
            break;
        case 3:
            t_notes = 12;
            t_symbols = expertNoteSymbols;
            initialize_grid(expertNoteSymbols, t_notes);
            break;
        default:
            cout << "Invalid difficulty level. Defaulting to Beginner." << endl;
            t_notes = 3;
            t_symbols = beginnerNoteSymbols;
            initialize_grid(beginnerNoteSymbols, t_notes);
        }
    }

    void playGame() {
        string to_exit;
        while (!game_won()) {
            print_grid(false);
            int x, y;
            cout << endl << endl;
            cout << "Play a musical note || Type x to exit: ";
            cin >> to_exit;
            cin.ignore();

            if (to_exit == "exit" || to_exit == "e" || to_exit == "x") {
                cout << endl;
                cout << "Exiting. Bye Bye :) " << endl;
                return;
            }
            try {
                x = stoi(to_exit);
                cin >> y;
            }
            catch (const exception& e) {
                cout << "Invalid input. Please enter 'exit' or valid coordinates." << endl;
                continue;
            }
            if (!isValid(x, y)) {
                cout << "Invalid coordinates." << endl;
                continue;
            }

            playNote(x, y);

            // Check if a chord is formed (3 notes played)
            if (playedNotes.size() == 3) {
                string chordName = identifyChord(); // Identify the chord
                playChord(chordName); // Play the chord sound
                playedNotes.clear(); // Clear the played notes vector
            }
        }

        print_grid(true);
        cout << "Congratulations! You won the game." << endl;
    }

    void playSound(int hz, int time) const {
        Beep(hz, time);
    }


    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    string getGridValue(int x, int y) const {
        return grid[x][y];
    }

    bool isValid(int x, int y) const {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    bool isRevealed(int x, int y) const {
        return revealed[x][y];
    }

    bool game_won() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!revealed[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    string identifyChord() const {
        if (playedNotes.size() != 3) {
            return "";
        }

        int noteIndices[3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < t_notes; ++j) {
                if (t_symbols[j] == playedNotes[i]) {
                    noteIndices[i] = j;
                    break;
                }
            }
        }

        int interval1 = (noteIndices[1] - noteIndices[0] + 12) % 12;
        int interval2 = (noteIndices[2] - noteIndices[1] + 12) % 12;

        if (interval1 == 3 && interval2 == 4) {
            return playedNotes[0] + " Minor Chord";
        }
        else if (interval1 == 4 && interval2 == 3) {
            return playedNotes[0] + " Major Chord";
        }
        else if (interval1 == 3 && interval2 == 3) {
            return playedNotes[0] + " Suspended Chord";
        }
        else if (interval1 == 4 && interval2 == 4) {
            return playedNotes[0] + " Diminished Chord";
        }
        else {
            return playedNotes[0] + " Chord ";
        }
    }



    void playChord(const string& chordName) const
    {


        cout << "Playing chord: " << chordName << endl;
        cout << endl << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;

        int rootNoteIndex = -1;
        for (int i = 0; i < t_notes; ++i) {
            if (t_symbols[i] == playedNotes[0]) {
                rootNoteIndex = i;
                break;
            }
        }

        if (rootNoteIndex != -1) {
            int frequency = noteFrequencies[rootNoteIndex];
            playSound(frequency, 1800);
        }
    }
};


class GameGUI {
private:
    sf::RenderWindow window;
    LRT_GAME game;
    sf::Font font;

public:
    GameGUI(int difficulty) : window(sf::VideoMode(800, 600), "LRT Game"), game(difficulty)
    {
        if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
        {
            std::cerr << "Failed to load font" << std::endl;
        }

    }

    void drawGrid()
    {


        // Load the background image
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("background.png"))
        {
            std::cerr << "Failed to load background image" << std::endl;
        }

        // Create a sprite for the background
        sf::Sprite backgroundSprite(backgroundTexture);

        window.clear(sf::Color::Black);

        // Draw the background
        window.draw(backgroundSprite);

        for (int i = 0; i < game.getRows(); ++i) {
            for (int j = 0; j < game.getCols(); ++j) {
                sf::RectangleShape cell(sf::Vector2f(60, 60));  // Assuming each cell is 60x60 pixels
                cell.setPosition(j * 60, i * 60);
                cell.setOutlineColor(sf::Color::White);
                cell.setOutlineThickness(1.0f);

                if (game.isRevealed(i, j)) {
                    // Draw revealed note
                    sf::Text text(game.getGridValue(i, j), font, 20);
                    text.setPosition(j * 60 + 20, i * 60 + 15);
                    text.setFillColor(sf::Color::White);

                    window.draw(text);
                }
                else {
                    // Draw unrevealed cell
                    window.draw(cell);
                }
            }
        }

        window.display();
    }

    void handleInput()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.y / 60;  // Assuming each cell is 60x60 pixels
                    int y = event.mouseButton.x / 60;

                    if (game.isValid(x, y) && !game.isRevealed(x, y))
                    {
                        game.playNote(x, y);

                        // Check if a chord is formed (3 notes played)
                        if (game.playedNotes.size() == 3)
                        {
                            string chordName = game.identifyChord();
                            game.playChord(chordName);
                            game.playedNotes.clear();
                        }
                    }
                }
            }
        }
    }

    void run()
    {
        while (window.isOpen() && !game.game_won())
        {
            handleInput();
            drawGrid();
        }

        window.close();
    }
};


//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````````````````````` INT MAIN ``````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
int main()
{
    cout << "\033[1;36m";
    cout << "\t\t\t\t\t\t_____________________________" << endl;
    cout << "\t\t\t\t\t\t|        LRT GUITAR'S       |" << endl;
    cout << "\t\t\t\t\t\t|___________________________|" << endl;
    cout << "\t\t\t\t\t\t\t_________________" << endl;
    cout << "\t\t\t\t\t\t\t|     MENU      |" << endl;
    cout << "\t\t\t\t\t\t\t|_______________|" << endl;
    cout << endl;
    cout << "____________________________" << endl;
    cout << "|   Select From The List   |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    1: REGISTER           |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    2: LOGIN              |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    3: EXIT               |" << endl;
    cout << "|__________________________|" << endl;
    cout << endl;
    int choice = 0;
    cout << "Enter: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string n = "";
        string em = "";
        string password;
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
        while (true)
        {
            cout << "Enter your name    : ";
            getline(cin, n);
            bool isAlpha = true;
            for (char c : n)
            {
                if (!isalpha(c))
                {
                    isAlpha = false;
                    break;
                }
            }

            if (isAlpha)
            {
                break;
            }
            else
            {
                cout << "Name should only contain alphabets." << endl << endl;
            }
        }
        cout << endl;
        while (true)
        {
            cout << "Enter your email   : ";
            getline(cin, em);
            size_t atPos = em.find('@');
            if (atPos != string::npos)
            {
                break;
            }
            else
            {
                cout << "Email should contain '@' symbol." << endl << endl;
            }
        }
        cout << endl;

        user u1(n, em);
        u1.registration();
        system("cls");
        system("pause");
        cout << "____________________________" << endl;
        cout << "|   Select From The List   |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    1: REGISTER           |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    2: LOGIN              |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    3: EXIT               |" << endl;
        cout << "|__________________________|" << endl;
        cout << endl;
        cout << "Enter: ";
        cin >> choice;
        cin.ignore();
    }
    if (choice == 2)
    {
    l1:
        string username, password;
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your username: ";
        getline(cin, username);

        cout << endl;
        cout << "Enter your password: ";
        password = read_pass();
        cout << endl;
        user u1;
        if (u1.login(username, password))
        {
            system("cls");
            cout << "\033[38;5;85m";
            do
            {
                cout << endl << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t____________________________" << endl;
                cout << "\t\t\t\t\t\t|   Select From The List   |" << endl;
                cout << "\t\t\t\t\t\t|__________________________|" << endl;
                cout << "\t\t\t\t\t\t|    1: Quizes             |" << endl;
                cout << "\t\t\t\t\t\t|__________________________|" << endl;
                cout << "\t\t\t\t\t\t|    2: Lessons            |" << endl;
                cout << "\t\t\t\t\t\t|__________________________|" << endl;
                cout << "\t\t\t\t\t\t|    3: Game               |" << endl;
                cout << "\t\t\t\t\t\t|__________________________|" << endl;
                cout << "\t\t\t\t\t\t|    4: Exit               |" << endl;
                cout << "\t\t\t\t\t\t|__________________________|" << endl;
                cout << endl;
                int choice;
                cout << "Enter: ";
                cin >> choice;
                cin.ignore();
                if (choice == 1)
                {
                    cout << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "____________________________" << endl;
                    cout << "|         LEVELS           |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    1: Begginer's         |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    2: Intermediate       |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    3: Expert             |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << endl;
                    int h;
                    cout << "Enter: ";
                    cin >> h;
                    cin.ignore();
                    cout << endl << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "____________________________" << endl;
                    cout << "|         Guitar's         |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    1: Acoustic-6 Strings |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    2: Ukelele            |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << "|    3: Electric           |" << endl;
                    cout << "|__________________________|" << endl;
                    cout << endl;
                    int jak;
                    cout << "Enter: ";
                    cin >> jak;
                    cin.ignore();
                    cout << endl;

                    if (jak == 1)
                    {
                        ifstream file("acoustic.txt");
                        if (file.is_open())
                        {
                            string file_username;
                            while (getline(file, file_username))
                            {
                                cout << file_username << endl;
                            }
                            file.close();
                        }
                        else
                        {
                            cerr << "Failed to open the file." << std::endl;
                        }
                    }
                    else if (jak == 2)
                    {
                        ifstream file("ukelele.txt");
                        if (file.is_open())
                        {
                            string file_username;
                            while (getline(file, file_username))
                            {
                                cout << file_username << endl;
                            }
                            file.close();
                        }
                        else
                        {
                            cerr << "Failed to open the file." << std::endl;
                        }
                    }
                    else if (jak == 3)
                    {
                        ifstream file("electric.txt");
                        if (file.is_open())
                        {
                            string file_username;
                            while (getline(file, file_username))
                            {
                                cout << file_username << endl;
                            }
                            file.close();
                        }
                        else
                        {
                            cerr << "Failed to open the file." << std::endl;
                        }
                    }
                    else
                    {
                        cout << "Wrong Choice! " << endl;
                    }
                }

                Beginner b1;
                Intermediate i1;
                Expert e1;
                if (choice == 2)
                {
                    cout << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t____________________________" << endl;
                    cout << "\t\t\t\t\t\t|         LEVELS           |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    1: Begginer's         |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    2: Intermediate       |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    3: Expert             |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << endl;
                    int levels;
                    cout << "Enter: ";
                    cin >> levels;
                    cin.ignore();
                    cout << endl << endl;
                    //```````````````````````````````````````` BeginNer's ```````````````````````````````````````````````
                    if (levels == 1)
                    {
                        b1.implement();
                    }

                    //```````````````````````````````````````` Intermediate ``````````````````````````````````````````````
                    if (levels == 2)
                    {
                        i1.implement();
                    }
                    //`````````````````````````````````````````` Expert ```````````````````````````````````````````````````
                    if (levels == 3)
                    {
                        e1.implement();
                    }
                }

                else if (choice == 3)
                {
                    cout << endl;
                    int levelss;
                    cout << "\t\t\t\t\t\t_________________________" << endl;
                    cout << "\t\t\t\t\t\t|        LRT GAME       |" << endl;
                    cout << "\t\t\t\t\t\t|_______________________|" << endl;
                    cout << endl << endl;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t____________________________" << endl;
                    cout << "\t\t\t\t\t\t|         LEVELS           |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    1: Beginner           |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    2: Intermediate       |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << "\t\t\t\t\t\t|    3: Expert             |" << endl;
                    cout << "\t\t\t\t\t\t|__________________________|" << endl;
                    cout << endl;
                    cin >> levelss;
                    GameGUI gui1(levelss);
                    gui1.run();

                }
                else if (choice == 4)
                {
                    exit(0);
                }
            } while (choice != 4);
        }
        goto l1;
    }
    if (choice == 3)
    {
        exit(0);
    }
}