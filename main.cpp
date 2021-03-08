#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

enum AppState {Running, Done, Error};

// Reads tasks from Tasks.txt
void ShowTasks(AppState &editor_state) {

    // 
    std::ifstream myFile;
    myFile.open("Tasks.txt");

    // Check for opening errors
    if (!myFile.is_open()) {
        std::cout << "Could not open file Tasks.txt." << std::endl;
        editor_state = Error;
        return;
    }

    // outputs tasks in order, numbered
    int counter = 1;
    std::string current_task = "";
    do {
        myFile >> current_task;
        std::cout << counter << ") "
            << std::setw(25) << std::left << current_task 
            << std::endl;     
        ++counter;        
    } while (!myFile.fail());
    std::cout << std::endl;


    myFile.close();

    std::cout << "Showed Tasks" << std::endl;
}

//INCOMPLETE - adds a task to Tasks.txt
void AddTask(AppState &editor_state) {
    std::ifstream MAIN_FILE;
    std::ofstream TEMP_FILE;
    TEMP_FILE.open("TMP.txt", std::_Ios_Openmode::_S_ate);
    MAIN_FILE.open("Tasks.txt");

    std::cout << "Showing tasks:" << std::endl;

    std::string contents = "";
    MAIN_FILE >> contents;
    std::cout << contents << std::endl;
    while (!MAIN_FILE.fail()) {
        MAIN_FILE >> contents;
        std::cout << contents << std::endl;
    }
    /*
     * TODO: read MAIN_FILE into a vector in order to edit it
     * write vector into TEMP File
     * Write TEMP into MAIN File
     * 
     * this is probably unoptimized
     * would be better not to write and read entire file every time
     * but let's not feature creep here
    */

    MAIN_FILE.close();
    TEMP_FILE.close();
    std::cout << "Added Task" << std::endl;
}

//Todo - adds a task to Completed.txt
void CompleteTask(AppState &editor_state) {
    std::cout << "Completed Task" << std::endl;
}

//Todo - Deletes a task from Tasks.txt
void RemoveTask(AppState &editor_state) {
    std::cout << "Removed Task" << std::endl;
}

// run again if the user wishes
void EndCheck(AppState &editor_state) {

    char done_answer = 'n';
    std::cout << "Run again? y/n:  ";
    std::cin >> done_answer;

    switch (done_answer)
    {
    case 'y':
        break;
    case 'n':
        editor_state = Done;
        break;
    /*
     * I think calling EndCheck() inside itself might cause memory problems 
     * if the user keeps entering the wrong value
     * maybe a do/while or while true loop might be better
     * not sure right now, will ask someone
    */
    default:
        EndCheck(editor_state);
        break;
    }
    std::cout << std::endl;
}

void Menu(AppState &editor_state) {
    // Menu
    std::cout << "Options:" << std::endl;
    std::cout << std::setw(8) << "" << "1. Show Tasks" << std::endl;
    std::cout << std::setw(8) << "" << "2. Add Task" << std::endl;
    std::cout << std::setw(8) << "" << "3. Complete Task" << std::endl;
    std::cout << std::setw(8) << "" << "4. Remove Task" << std::endl;
    std::cout << "Enter number of choice: ";
    
    // calls selected function
    char menu_choice = '0';
    std::cin >> menu_choice;
    std::cout << std::endl;
    switch (menu_choice)
    {
    case '1':
        ShowTasks(editor_state);
        break;
    case '2':
        AddTask(editor_state);
        break;
    case '3':
        CompleteTask(editor_state);
        break;
    case '4':
        RemoveTask(editor_state);
        break;
    default:
        editor_state = Error;
        break;
    }

}

int main() {
    AppState editor = Running;
    while (editor == Running) {
        Menu(editor);
        // check for error before running
        if (editor == Error) {
            std::cout << "Error while running" << std::endl;
            return 1;
        }
        EndCheck(editor);
    }
    return 0;
}
