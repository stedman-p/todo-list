#include <iostream>
#include <fstream>
#include <iomanip>

enum AppState {Running, Done, Error};

//Todo - shows completed or current tasks to command line
void ShowTasks(AppState &editor_state) {
    std::cout << "Showed Tasks" << std::endl;
}

//Todo - adds a task to Tasks.txt
void AddTask(AppState &editor_state) {
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
     * I think this might cause memory problems if the user keeps entering the wrong
     * value - maybe a do/while or while true loop might be better
    */
    default:
        EndCheck(editor_state);
        break;
    }
}

void Menu(AppState &editor_state) {
    std::cout << "Options:" << std::endl;
    std::cout << std::setw(8) << "" << "1. Show Tasks" << std::endl;
    std::cout << std::setw(8) << "" << "2. Add Task" << std::endl;
    std::cout << std::setw(8) << "" << "3. Complete Task" << std::endl;
    std::cout << std::setw(8) << "" << "4. Remove Task" << std::endl;
    std::cout << "Enter number of choice: ";
    
    char menu_choice = '0';

    std::cin >> menu_choice;

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
        // check for error before running
        if (editor == Error) {
            std::cout << "Error while running" << std::endl;
            return 1;
        }
        Menu(editor);
        EndCheck(editor);
    }
    return 0;
}
