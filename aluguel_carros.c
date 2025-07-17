#include <stdio.h> 
#include <string.h>

int main() {
    char nome[20][50], status[20][11], x[50];
    float valor[20], vlraluguel = 0.0; 
    // Variáveis de controle
    int i = 0; 
    int a = 0;
    int b = 0;  
    int c = 0;  
    int qtddias = 0;
    do {
        // Exibe o menu de opções
        printf("\nSISTEMA DE ALUGUEL DE CARROS");
        printf("\n1 - CADASTRAR");
        printf("\n2 - EXIBIR");
        printf("\n3 - BUSCAR");
        printf("\n4 - ALUGAR");
        printf("\n5 - LISTAR OS ALUGADOS");
        
        // Recebe a opção escolhida
        printf("\n\nESCOLHA UMA OPCAO: ");
        scanf("%d", &b);
        getchar();  

        // Executa a opção escolhida
        switch (b) {
            case 1:
                // Cadastro de novo carro
                printf("\nDADOS PARA CADASTRO");
                printf("\nDigite o modelo do carro: ");
                fgets(nome[i], 50, stdin); // Lê o nome do carro
                nome[i][strcspn(nome[i], "\n")] = 0; 
                
                printf("Digite o valor do aluguel do carro: ");
                scanf("%f", &valor[i]);
                getchar();

                strcpy(status[i], "DISPONIVEL"); // Define o status inicial como disponível

                printf("\nCARRO CADASTRADO COM SUCESSO !\n");
                i++;
                break;

            case 2:
                // Lista todos os carros cadastrados
                printf("\nMODULO DE LISTAR");
                for (c = 0; c < i; c++) {
                    printf("\nModelo do veículo: %s", nome[c]);
                    printf("\nValor do aluguel: R$ %.2f", valor[c]);
                    printf("\nStatus: %s", status[c]);
                    printf("\n---------------");
                }
                break;

            case 3:
                // Busca um carro pelo nome
                printf("\nDADOS PARA BUSCA\n");
                printf("Digite o modelo do carro para busca: ");
                fgets(x, 50, stdin);
                x[strcspn(x, "\n")] = 0; // Remove o \n no final

                for (c = 0; c < i; c++) {
                    if (strcmp(x, nome[c]) == 0) { // Compara nome buscado com nome cadastrado
                        printf("\nCARRO ENCONTRADO !");
                        printf("\nO carro: %s", nome[c]);
                        printf("\nO valor do carro: R$ %.2f", valor[c]);
                        printf("\nStatus do carro: %s", status[c]);
                        printf("\n---------------");
                    }
                }
                break;

            case 4:
                // Aluga um carro se estiver disponível
                printf("\nDADOS PARA ALUGUEL:\n");
                printf("DIGITE O MODELO DO CARRO P/ ALUGAR: ");
                fgets(x, 50, stdin);
                x[strcspn(x, "\n")] = 0;

                 for (c = 0; c < i; c++) {
                    if (strcmp(x, nome[c]) == 0 && strcmp(status[c], "DISPONIVEL") == 0) {
                        printf("\nCARRO ENCONTRADO !");
                        printf("\nO carro: %s", nome[c]);
                        printf("\nO valor do carro: R$ %.2f", valor[c]);
                        printf("\n-------------");

               
printf("\nInforme a quantidade de dias que deseja alugar: ");
scanf("%d", &qtddias);
                        getchar();

                        // Calcula o valor do aluguel total
                        vlraluguel = qtddias * valor[c];

                        // Atualiza o status para "ALUGADO"
                        strcpy(status[c], "ALUGADO");

                        printf("\n### O VALOR DO ALUGUEL: R$ %.2f", vlraluguel);
                        printf("\n$$ Carro alugado com sucesso! ###\n");
                    }
                }
                break;

            //Lista apenas os carros alugados
            case 5:
                printf("\n  VEÍCULOS ALUGADOS  \n");
                for (c = 0; c < i; c++) {
                    if (strcmp(status[c], "ALUGADO") == 0) {
                        printf("\nCARRO ALUGADO !");
                        printf("\nModelo: %s", nome[c]);
                        printf("\n---------------");
                    }
                }
                break;

            // Caso padrão para opções inválidas
            default:
                printf("\nESTA OPCAO ESTÁ EM DESENVOLVIMENTO !");
        }

        // Pergunta se o usuário deseja voltar ao menu ou encerrar o programa
        printf("\nDigite 1 para retornar ao menu ou 0 (zero) para sair: ");
        scanf("%d", &a);
        getchar(); // Limpa o buffer
    } while (a != 0); // Sai do laço se o usuário digitar 0

    return 0; // Fim
}


