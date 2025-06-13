#define NOMINMAX
#include <limits>
#include <Windows.h>
#include <iostream>

void cinError()
{
	if (std::cin.fail())
	{
		std::cin.clear(); // Limpa o estado de erro
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer
	}
}

void addTask() //função para adicionar tarefa
{
}

void listTasks() //função para listar tarefas
{
}

void markTaskAsCompleted() //função para marcar tarefa como concluída
{
}

void removeTask() //função para remover tarefa
{
}

void saveTaskList() //função para salvar lista de tarefas
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
		// Exibe o menu de opções
		std::cout << "\tGerenciador de Tarefas\n\n";
		std::cout << "1. Adicionar tarefa\n"
			<< "2. Listar tarefas\n"
			<< "3. Marcar tarefa como concluída\n"
			<< "4. Remover tarefa\n"
			<< "5. Salvar lista\n"
			<< "6. Sair\n\n";

		std::cout << "Escolha uma opção: ";
		int option{};
		std::cin >> option;
		if (!std::cin) // Verifica se a entrada é válida
		{
			cinError();
			std::cout << "Entrada inválida. Tente novamente.\n\n";
			continue;
		}

		switch (option)
		{
		case 1:
			std::cout << "Opção 1. \'adicionar tarefa\' selecionada.\n";
			addTask();
			isRunning = false;
			break;
		case 2:
			std::cout << "Opção 2. \'listar tarefas\' selecionada.\n";
			listTasks();
			isRunning = false;
			break;
		case 3:
			std::cout << "Opção 3. \'marcar tarefa como concluída\' selecionada.\n";
			markTaskAsCompleted();
			isRunning = false;
			break;
		case 4:
			std::cout << "Opção 4. \'remover tarefa\' selecionada.\n";
			removeTask();
			isRunning = false;
			break;
		case 5:
			std::cout << "Opção 5. \'salvar lista\' selecionada.\n";
			saveTaskList();
			isRunning = false;
			break;
		case 6:
		case 0:
			std::cout << "Saindo do programa...\n";
			return 0;

		default:
			std::cout << "Opção inválida. Tente novamente.\n\n";
			cinError(); // Limpa o buffer de entrada em caso de opção inválida
			continue; // Volta ao início do loop para solicitar uma nova opção
		}

	} while (isRunning);

	return 0;
}