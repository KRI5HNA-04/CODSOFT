#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        clearScreen();
        cout << "Task added: " << description << endl << endl;
    }

    void viewTasks() {
        clearScreen();
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            const Task& task = tasks[i];
            cout << i + 1 << ". " << (task.completed ? "[X] " : "[ ] ") << task.description << endl;
        }
        cout << endl;
    }

    void markTaskCompleted(int index) {
        if (validateIndex(index)) {
            Task& task = tasks[index - 1];
            task.completed = true;
            clearScreen();
            cout << "Task marked as completed: " << task.description << endl << endl;
        }
    }

    void removeTask(int index) {
        if (validateIndex(index)) {
            const Task& task = tasks[index - 1];
            clearScreen();
            cout << "Task removed: " << task.description << endl << endl;
            tasks.erase(tasks.begin() + (index - 1));
        }
    }

    bool validateIndex(int index) {
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            return true;
        }
        clearScreen();
        cout << "Invalid task index." << endl << endl;
        return false;
    }

    void clearScreen() {
        // Use system-specific command to clear the terminal
        #ifdef _WIN32
            system("cls"); // For Windows
        #else
            system("clear"); // For Linux and macOS
        #endif
    }

    void menu() {
        int choice;
        while (true) {
            cout << "To-Do List Manager" << endl;
            cout << "1. Add Task" << endl;
            cout << "2. View Tasks" << endl;
            cout << "3. Mark Task as Completed" << endl;
            cout << "4. Remove Task" << endl;
            cout << "5. Quit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                clearScreen();
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                addTask(description);
            } else if (choice == 2) {
                viewTasks();
            } else if (choice == 3) {
                clearScreen();
                int index;
                cout << "Enter the task index to mark as completed: ";
                cin >> index;
                markTaskCompleted(index);
            } else if (choice == 4) {
                clearScreen();
                int index;
                cout << "Enter the task index to remove: ";
                cin >> index;
                removeTask(index);
            } else if (choice == 5) {
                clearScreen();
                cout << "Goodbye!" << endl;
                break;
            } else {
                clearScreen();
                cout << "Invalid choice. Please try again." << endl << endl;
            }
        }
    }
};

int main() {
    ToDoList toDoList;
    toDoList.menu();
    return 0;
}
