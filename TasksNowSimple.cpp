#include <Windows.h>
#include <iostream>

int main()
{
	// Define a codificação do console para UTF-8
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	do
	{
		// Exibe o menu de opções
		std::cout << "\tGerenciador de Tarefas\n\n";
		std::cout << "1. Adicionar tarefa\n"
			<< "2. Listar tarefas\n"
			<< "3. Marcar tarefa como concluída\n"
			<< "4. Remover tarefa\n"
			<< "5. Salvar como... (JSON, TXT, CSV)\n"
			<< "6. Sair\n\n";

		std::cout << "Escolha uma opção: ";
		int option{};
		std::cin >> option;
		std::cin.ignore(); // Limpa o buffer de entrada

	} while (true);

	return 0;
}