#include <bits/stdc++.h>

using namespace std;

// struct to store a task
struct Task{
    string name; // name of the task
    bool completed; // status of the task
};

// vector to store the list of tasks
vector<Task> task_list;

// function to display the menu
void displayOptions(){
	cout << endl;
    cout << "Welcome to the To-Do List manager !!" << endl;
    cout << "You can perform the following actions:" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark a task as completed" << endl;
    cout << "4. Remove a task" << endl;
    cout << "5. Exit the program" << endl;
    cout << endl;
}

// function to get the user's choice
int getUserChoice(){
    int choice;
    bool valid;
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        valid = (choice >= 1 && choice <= 5);
        
        if (!valid)
            cout << "Invalid choice. Try again.\n";
    }
	while(!valid);
	
    return choice;
}

// function to add a task
void addTask(){
    string name;

    // Prompt the user to enter the task name
    cout << "Enter the name of the task: ";
    cin.ignore(); // Ignore the newline character from the previous input
    getline(cin, name); // Gets the whole line of input

    Task new_task;
    new_task.name = name;
    new_task.completed = false;

    task_list.push_back(new_task);

    cout << "Task added successfully." << endl;
}

// function to view tasks
void viewTasks(){
    if (task_list.empty()){
    	cout << "You have no tasks in your list." << endl;
	}
    else{
        cout << "Here are your to_do tasks:" << endl;

        // Loop through the list and print each task with its index and status
        for (int i = 0; i < task_list.size(); i++){
            cout << i + 1 << ". " << task_list[i].name;
            
            if (task_list[i].completed)
                cout << " (Completed)" << endl;
            else
                cout << " (Pending)" << endl;
        }
    }
}

// function to mark a task as completed
void markTaskAsCompleted(){
    if (task_list.empty()){
        cout << "You have no tasks in your list." << endl;
    }
    else{
        int index;

        cout << "Enter the index of the task you want to mark as completed: ";
        cin >> index;

        // Check if the index is valid
        if (index >= 1 && index <= task_list.size())
        {
            // Mark the task as completed
            task_list[index - 1].completed = true;
            cout << "Task marked as completed successfully." << endl;
        }
        else
        {
            cout << "Invalid index. No such task exists." << endl;
        }
    }
}

// function to remove a task
void removeTask(){
    if (task_list.empty()){
        cout << "The task list is currently empty." << endl;
    }
    else{
        int index;

        cout << "Enter the index of the task you want to remove: ";
        cin >> index;

        // Check if the index is valid
        if (index >= 1 && index <= task_list.size()){
            task_list.erase(task_list.begin() + index - 1);

            cout << "Task removed successfully." << endl;
        }
        else
            cout << "Invalid index. No such task exists." << endl;
    }
}

void runProgram()
{
    int choice;

    do{
        displayOptions();

        // Get the user's choice from above created function
        choice = getUserChoice();

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Thank you for using the to-do task manager. !!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 5);
}

int main(){
    runProgram();

    return 0;
}
