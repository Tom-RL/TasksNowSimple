#define NOMINMAX
#include <limits>
#include <Windows.h>
#include <vector>
#include <iostream>
#include "task/task.h"

std::vector<Task> taskList{}; //temporário

void cinError() //funtion to handle input errors
{
	if (std::cin.fail())
	{
		std::cin.clear(); // remove the error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
	}
}

void addTask() //function to add a task
{
	static int id{ 0 }; // ID of task, start in 0 and increments with each new task

	std::cout << "Enter the task name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	if (name.empty())
	{
		std::cout << "Nome inválido. O nome da tarefa não pode ser vazio.\n";
		return;
	}

	std::cout << "Enter the task description: ";
	std::string description{};
	std::getline(std::cin >> std::ws, description);
	if (description.empty())
	{
		std::cout << "Descrição inválida. A descrição da tarefa não pode ser vazia.\n";
		return;
	}

	taskList.emplace_back(Task{ name, description, id, false });
	id++; // increments the id for the next task

	std::cout << "\tTask added successfully!\n\n";
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
	// Define a codificação do console para UTF-8
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	bool isRunning = true;

	do
	{
		// show menu options
		std::cout << "\tTask Manager\n\n";
		std::cout << "1. Add task\n"
			<< "2. List tasks\n"
			<< "3. Mark task as complete\n"
			<< "4. Remove task\n"
			<< "5. Save list\n"
			<< "6. Exit\n\n";

		std::cout << "choose an option: ";
		int option{};
		std::cin >> option;
		if (!std::cin) // checks if the input is valid
		{
			cinError();
			std::cout << "Invalid input. Try again.\n\n";
			continue;
		}

		switch (option)
		{
		case 1:
			system("cls");
			std::cout << "Option 1. \'add task\' selected.\n";
			addTask();
			break;
		case 2:
			system("cls");
			std::cout << "Option 2. \'list tasks\' selected.\n";
			listTasks();
			break;
		case 3:
			system("cls");
			std::cout << "Option 3. \'mark task as complete\' selected.\n";
			markTaskAsCompleted();
			break;
		case 4:
			system("cls");
			std::cout << "Option 4. \'remove task\' selected.\n";
			removeTask();
			break;
		case 5:
			system("cls");
			std::cout << "Option 5. \'save list\' selected.\n";
			saveTaskList();
			break;
		case 6:
		case 0:
			std::cout << "Leaving the program...\n";
			isRunning = false;
			break;

		default:
			std::cout << "Invalid option. Try again\n\n";
			cinError(); // clean the input buffer in case of invalid input
			continue; //  returns to the beginning of the loop to request a new option
		}

	} while (isRunning);

	return 0;
}