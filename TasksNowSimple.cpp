#define NOMINMAX
#include <limits>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include "task/task.h"

std::vector<Task> taskList{}; //temporário

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

	std::cout << "Enter the task name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	if (name.empty())
	{
		setColor(12); // red
		std::cout << "Invalid name. Task name cannot be empty.\n";
		setColor(7);
		return;
	}

	std::cout << "Enter the task description: ";
	std::string description{};
	std::getline(std::cin >> std::ws, description);
	if (description.empty())
	{
		setColor(12); // red
		std::cout << "Invalid description. Task description cannot be empty.\n";
		setColor(7);
		return;
	}

	taskList.emplace_back(Task{ name, description, id, false });
	id++; // increments the id for the next task

	setColor(10); // green
	std::cout << "Task added successfully!\n\n";
	setColor(7);
	std::this_thread::sleep_for(std::chrono::seconds(2)); 
	clearScreen();
}

void listTasks() //funtion to list tasks
{
}

void markTaskAsCompleted() //funtion to mark a task as completed
{
}

void removeTask() //funtion to remove a task
{
}

void saveTaskList() //funtion to save the task list to a file
{
}

int main()
{
	/*	// Set console encoding to UTF - 8
	 *	SetConsoleOutputCP(CP_UTF8);
	 *	SetConsoleCP(CP_UTF8);
	 */

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
			setColor(12); // red
			std::cout << "Invalid input. Try again.\n\n";
			setColor(7);
			continue;
		}

		switch (option)
		{
		case 1:
			clearScreen();
			std::cout << "Add task selected.\n\n";
			addTask();
			break;
		case 2:
			clearScreen();
			std::cout << "List tasks selected.\n\n";
			listTasks();
			break;
		case 3:
			clearScreen();
			std::cout << "Mark task as complete selected.\n\n";
			markTaskAsCompleted();
			break;
		case 4:
			clearScreen();
			std::cout << "Remove task selected.\n\n";
			removeTask();
			break;
		case 5:
			clearScreen();
			std::cout << "Save list selected.\n\n";
			saveTaskList();
			break;
		case 6:
		case 0:
			std::cout << "Leaving the program...\n\n";
			std::this_thread::sleep_for(std::chrono::seconds(1)); 
			isRunning = false;
			break;

		default:
			setColor(12); // red
			std::cout << "Invalid option. Try again\n\n";
			setColor(7);
			cinError();
			continue;
		}

	} while (isRunning);

	return 0;
}