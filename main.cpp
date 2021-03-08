#include <iostream>
#include <fstream>

enum AppState {Running, Done, Error};

//Todo - Shows options
void Menu() {
    std::cout << "Ran menu" << std::endl;
}

//Todo - shows completed or current tasks to command line
void ShowTasks(char category) {
    std::cout << "Showed Tasks" << std::endl;
}

//Todo - adds a task to Tasks.txt
void AddTask() {
    std::cout << "Added Task" << std::endl;
}

//Todo - adds a task to Completed.txt
void CompleteTask() {
    std::cout << "Completed Task" << std::endl;
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
    default:
        EndCheck(editor_state);
        break;
    }
}
int main() {
    AppState editor = Running;
    while (editor == Running) {
        Menu();
        EndCheck(editor);
    }
    return 0;
}
