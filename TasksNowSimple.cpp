#define NOMINMAX // disabling min and max from Windows.h header
#include <limits>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include "task/task.h" // Class Task header
#include "storage/Storage.h" // Storage functions header

std::vector<Task> taskList{}; //temporário

// a local namespace to agroup customizing functions
namespace customize
{
	// Set console text color
	void setColor(WORD color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	// Clear console screen
	void clearScreen()
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD count;
		DWORD cellCount;
		COORD homeCoords = { 0, 0 };

		if (hStdOut == INVALID_HANDLE_VALUE) return;
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;

		cellCount = csbi.dwSize.X * csbi.dwSize.Y;

		FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);
		SetConsoleCursorPosition(hStdOut, homeCoords);
	}

	// Set a delayer
	void setDelay(int milliseconds)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
}

// Checks for input errors and clears the input buffer if necessary	
void cinError()
{
	if (std::cin.fail())
	{
		std::cin.clear(); // remove the error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
	}
}

void showMenu() //function to show the menu options

{
	std::cout << "\t\tTask Manager\n\n"
		      << "1. Add task\n"
			  << "2. List tasks\n"
			  << "3. Mark task as complete\n"
			  << "4. Remove task\n"
			  << "5. Save list\n"
		      << "6. Exit\n\n";
}

void addTask() //function to add a task
{
	static int id{ 0 }; // ID of task, start in 0 and increments with each new task

	for (const auto& task : taskList)
	{
		if (id <= task.getId()) // checks if the id is already used
		{
			id = task.getId() + 1; // increments the id to the next available one
		}
	}

	customize::setDelay(1200); 
	customize::clearScreen();

	std::cout << "Enter the task name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	if (name.empty())
	{
		customize::setColor(12); // red
		std::cout << "Invalid name. Task name cannot be empty.\n";
		customize::setColor(7);
		return;
	}

	std::cout << "Enter the task description: ";
	std::string description{};
	std::getline(std::cin >> std::ws, description);
	if (description.empty())
	{
		customize::setColor(12); // red
		std::cout << "Invalid description. Task description cannot be empty.\n";
		customize::setColor(7);
		return;
	}

	taskList.emplace_back(Task{ name, description, id, false });
	id++; // increments the id for the next task

	customize::setColor(10); // green
	std::cout << "Task added successfully!\n\n";
	customize::setColor(7);
	customize::setDelay(2000);
	customize::clearScreen();
}

void listTasks() //funtion to list tasks
{
	customize::setDelay(1200);
	customize::clearScreen();
	if(taskList.empty())
	{ 
		customize::setColor(12); // red
		std::cout << "No tasks available.\n\n";
		customize::setColor(7);
		customize::setDelay(2000);	
		customize::clearScreen();
		return;
	}
	else
	{ 
		customize::setColor(10); // green
		std::cout << "List of tasks:\n\n";
		customize::setColor(7);

		customize::setDelay(500); // delay for 0.5 seconds
		for (const auto& task : taskList)
		{
			std::cout << task << "\n\n"; // uses the overloaded operator<< from task.h to print the task
		}
		std::cout << "Press Enter to continue...\n";
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		customize::clearScreen();
	}
}

void markTaskAsCompleted() //funtion to mark a task as completed
{
	customize::setDelay(1200);
	customize::clearScreen();

	if (taskList.empty())
	{
		customize::setColor(12); // red
		std::cout << "No tasks available to mark as completed.\n\n";
		customize::setColor(7);
		customize::setDelay(2000);
		customize::clearScreen();
		return;
	}
	else
	{
		std::cout << "Enter the ID of the task to mark as completed: ";
		int id{};
		std::cin >> id;
		if (!std::cin)
		{
			cinError();
			customize::setColor(12); // red
			std::cout << "Invalid input. Please enter a valid task ID.\n\n";
			customize::setColor(7);
			customize::setDelay(2000);
			customize::clearScreen();
			return;
		}
		if (id < 0) // checks if the id is negative
		{
			customize::setColor(12); // red
			std::cout << "Invalid ID. Task ID cannot be negative.\n\n";
			customize::setColor(7);
			customize::setDelay(2000);
			customize::clearScreen();
			return;
		}

		for (auto& task : taskList) // accesses each task in the task list
		{
			if (task.getId() == id) // checks if the task ID matches the input ID
			{
				if (task.isCompleted()) // checks if the task is already marked as completed
				{
					customize::setColor(12); // red
					std::cout << "Task " << task.getName() << " is already marked as completed.\n\n";
					customize::setColor(7);
					customize::setDelay(2000);
					customize::clearScreen();
					return;
				}
				else
					{
					customize::setColor(14); // yellow
					std::cout << "Marking task " << task.getName() << " as completed...\n";
					task.markCompleted(); // marks the task as completed
					customize::setDelay(1000);
					customize::clearScreen();

					customize::setColor(10); // green
					std::cout << "Task " << task.getName() << " marked as completed successfully!\n\n";
					customize::setColor(7);
					customize::setDelay(2000);
					customize::clearScreen();
					return;
				}
			}
		}

		customize::setColor(12); // red
		std::cout << "Task with ID " << id << " not found.\n\n";
		customize::setColor(7);
		customize::setDelay(2000);
		customize::clearScreen();
	}

}

void removeTask() //funtion to remove a task
{
	customize::setDelay(1200);
	customize::clearScreen();
	if (taskList.empty())
	{
		customize::setColor(12); // red
		std::cout << "No tasks available to remove.\n\n";
		customize::setColor(7);
		customize::setDelay(2000);
		customize::clearScreen();
		return;
	}
	else
	{
		std::cout << "Enter the ID of the task to remove: ";
		int id{};
		std::cin >> id;
		if (!std::cin)
		{
			cinError();
			customize::setColor(12); // red
			std::cout << "Invalid input. Please enter a valid task ID.\n\n";
			customize::setColor(7);
			customize::setDelay(2000);
			customize::clearScreen();
			return;
		}
		if (id < 0) // checks if the id is negative
		{
			customize::setColor(12); // red
			std::cout << "Invalid ID. Task ID cannot be negative.\n\n";
			customize::setColor(7);
			customize::setDelay(2000);
			customize::clearScreen();
			return;
		}

		for (auto& task : taskList) // accesses each task in the task list
		{
			if (task.getId() == id) // checks if the task ID matches the input ID
			{
				customize::setColor(14); // yellow
				std::cout << "Removing task " << task.getName() << "...\n";
				taskList.erase(taskList.begin() + id); // removes the task from the list
				customize::setDelay(1000);
				customize::clearScreen();
				customize::setColor(10); // green
				std::cout << "Task removed successfully!\n\n";
				customize::setColor(7);
				customize::setDelay(2000);
				customize::clearScreen();
				return;
			}
		}
	}
}

void saveTaskList() //funtion to save the task list to a file
{
	customize::setDelay(1200); // delay for 1.2 seconds
	customize::clearScreen();
	if (taskList.empty())
	{
		customize::setColor(12); // red
		std::cout << "No tasks to save.\n\n";
		customize::setColor(7);
		customize::setDelay(2000); // delay for 2 seconds
		customize::clearScreen();
		return;
	}

	if (saveTaskListInFile(taskList, "task.txt"))
	{
		customize::setColor(10); // green
		std::cout << "Task list saved successfully!\n\n";
		customize::setColor(7);
	}
	else
	{
		customize::setColor(12); // red
		std::cout << "Failed to save task list.\n\n";
		customize::setColor(7);
	}

	customize::setDelay(2000); // delay for 2 seconds
	customize::clearScreen();
}

int main()
{
	/*	// Set console encoding to UTF - 8
	 *	SetConsoleOutputCP(CP_UTF8);
	 *	SetConsoleCP(CP_UTF8);
	 */

	taskList = loadTaskList("task.txt"); // Load tasks from file at the start of the program

	bool isRunning = true;

	do
	{
		showMenu();

		std::cout << "choose an option: ";
		int option{};
		std::cin >> option;
		if (!std::cin) // checks if the input is valid
		{
			cinError();
			customize::setColor(12); // red
			std::cout << "Invalid input. Try again.\n\n";
			customize::setColor(7);
			customize::setDelay(1000);
			customize::clearScreen();
			continue;
		}

		switch (option)
		{
		case 1:
			customize::clearScreen();
			std::cout << "Add task selected.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
			addTask();
			break;
		case 2:
			customize::clearScreen();
			std::cout << "List tasks selected.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			listTasks();
			break;
		case 3:
			customize::clearScreen();
			std::cout << "Mark task as complete selected.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			markTaskAsCompleted();
			break;
		case 4:
			customize::clearScreen();
			std::cout << "Remove task selected.\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			removeTask();
			break;
		case 5:
			customize::clearScreen();
			std::cout << "Save list selected.\n\n";
			saveTaskList();
			break;
		case 6:
		case 0:
			std::cout << "Leaving the program...\n\n";
			customize::setDelay(1000);
			isRunning = false;
			break;

		default:
			customize::setColor(12); // red
			std::cout << "Invalid option. Try again\n\n";
			customize::setColor(7);
			cinError();
			continue;
		}

	} while (isRunning);

	return 0;
}