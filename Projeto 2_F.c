
// Gerenciador Ultra Mega Blaster da Escola de Bruxos 2.0.
// Projeto de Linguagem de Programação.
// Desenvolvido conforme especificação do projeto acadêmico.

// Includes e Defines

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32 //Definido para limpar tela
    #define LIMPAR "cls" //Definido para limpar tela
#else
    #define LIMPAR "clear" //Definido para limpar tela
#endif

#define NUM_TURMAS 4
#define NUM_BRUXOS 5
#define TOTAL_BRUXOS (NUM_TURMAS * NUM_BRUXOS)
#define MAX_ATRIBUTO 5

//Structs e Funções Auxiliares
//Estrutura que irá represnetar um bruxo
typedef struct {
    char nome[50];
    int inteligencia;
    int destreza;
    int carisma;
} Bruxo;

// Estrutura que irá representa uma turma
typedef struct {
    char nome[50];
    int pontos;
    int quantidade;
    Bruxo bruxos[NUM_BRUXOS];
} Turma;

//Declaração de Todas Funções utilizadas no programa
void cadastrarBruxos(Turma turmas[]);
void preCadastro(Turma turmas[]);
int menuInicial();
void imprimirTurmas(const Turma turmas[]);
void imprimirBruxosDaTurma(const Turma turmas[]);
void executarDesafio(Turma turmas[], int* disputasExecutadas);
void quadriLOL(Turma turmas[]);
void artesArcanas(Turma turmas[]);
void pedraFloatzal(Turma turmas[]);
void bonusGrifinoria(Turma turmas[]);
void mensagemCaracteristicaCasa(const char* casa);
void discursoFinal(const Turma turmas[]);

//Menu do Projeto
int menuInicial() {
    int escolha;
    printf("Bem-vindo ao Gerenciador Ultra Mega Blaster da Escola de Bruxos 2.0!\n");
    printf("1. Cadastrar bruxos manualmente\n");
    printf("2. Utilizar pre-cadastro automatico\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    getchar(); // Limpar o \n do scanf
    return escolha;
}

//Função dos Bruxos
void cadastrarBruxos(Turma turmas[]) {
    int modoAutomatico;

    // Escolha de modo de preenchimento
    for (int i = 0; i < NUM_TURMAS; i++) {
        printf("\n--- Cadastro de bruxos da casa %s ---\n", turmas[i].nome);
        char continuar = 's';

        while (continuar == 's' || continuar == 'S') {
            if (turmas[i].quantidade >= NUM_BRUXOS) {
                printf("Limite de %d bruxos atingido para a casa %s!\n", NUM_BRUXOS, turmas[i].nome);
                break;
            }

            Bruxo* b = &turmas[i].bruxos[turmas[i].quantidade];
            printf("Nome do bruxo: ");
            fgets(b->nome, sizeof(b->nome), stdin);
            b->nome[strcspn(b->nome, "\n")] = '\0';

        printf("\nOs atributos (inteligencia, destreza e carisma) sao preenchidos automaticamente\n");
        printf("Segue as atribuicoes executadas: \n");

                b->inteligencia = rand() % (MAX_ATRIBUTO + 1);
                b->destreza = rand() % (MAX_ATRIBUTO + 1);
                b->carisma = rand() % (MAX_ATRIBUTO + 1);
                printf("     Inteligencia: %d\n", b->inteligencia);
                printf("     Destreza:     %d\n", b->destreza);
                printf("     Carisma:      %d\n", b->carisma);


            turmas[i].quantidade++;
            while (1) {
                printf("\nDeseja cadastrar outro bruxo na casa %s? (s/n): ", turmas[i].nome);
                scanf(" %c", &continuar);
                getchar(); // limpa '\n'

                if (continuar == 's' || continuar == 'S' || continuar == 'n' || continuar == 'N') {
                    break;
                } else {
                    printf("\nEntrada invalida! Por favor, digite apenas 's' para sim ou 'n' para nao.\n");
                }
            }
        }
    }
}


//Função dos Bruxos
void imprimirBruxosDaTurma(const Turma turmas[]) {
    int i;
    printf("Escolha uma casa para listar os bruxos:\n");
    for (i = 0; i < NUM_TURMAS; i++) {
        printf("%d. %s\n", i + 1, turmas[i].nome);
    }

    int opcao;
    printf("Digite o numero da casa: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao < 1 || opcao > NUM_TURMAS) {
        printf("Opcao invalida!\n");
        return;
    }

    int idx = opcao - 1;
    printf("\nBruxos da casa %s:\n", turmas[idx].nome);
    for (int j = 0; j < turmas[idx].quantidade; j++) {
        Bruxo b = turmas[idx].bruxos[j];
        printf("  Nome: %s | Int: %d | Des: %d | Car: %d\n",
               b.nome, b.inteligencia, b.destreza, b.carisma);
    }
}

//Funções da Turma
void mensagemCaracteristicaCasa(const char* casa) {
    if (strcmp(casa, "Grifinoria") == 0) {
        printf("-> Corajoso e Determinado!\n");
    } else if (strcmp(casa, "Sonserina") == 0) {
        printf("-> Ambicioso e Astuto!\n");
    } else if (strcmp(casa, "Corvinal") == 0) {
        printf("-> Inteligente e Criativo!\n");
    } else if (strcmp(casa, "Lufa-Lufa") == 0) {
        printf("-> Leal e Trabalhador!\n");
    }
}

//Funções da Turma
void preCadastro(Turma turmas[]) {
    printf("\n=== Pre-Cadastro Automatico de Bruxos ==\n");
    printf("Realizando o sorteio dos bruxos e alocando em suas respectivas casas...\n");
    printf("Cada bruxo recebera atributos aleatorios de Inteligencia, Destreza e Carisma.\n\n");
    const char* nomesPredefinidos[TOTAL_BRUXOS] = {
        "Harry", "Rony", "Hermione", "Neville", "Luna",
        "Draco", "Pansy", "Crabbe", "Goyle", "Zabini",
        "Cho", "Padma", "Michael", "Roger", "Terry",
        "Cedrico", "Hannah", "Susan", "Ernie", "Justin"
    };

    int total = 0;
    for (int i = 0; i < NUM_TURMAS; i++) {
        for (int j = 0; j < NUM_BRUXOS; j++) {
            Bruxo* b = &turmas[i].bruxos[j];
            strcpy(b->nome, nomesPredefinidos[total]);
            b->inteligencia = rand() % (MAX_ATRIBUTO + 1);
            b->destreza = rand() % (MAX_ATRIBUTO + 1);
            b->carisma = rand() % (MAX_ATRIBUTO + 1);
            turmas[i].quantidade++;
            total++;
            printf("Bruxo '%s' foi alocado na casa %s.\n", b->nome, turmas[i].nome);
            mensagemCaracteristicaCasa(turmas[i].nome);
        }
    }
    printf("\nPre-cadastro finalizado! Pressione ENTER para continuar...\n");
    getchar(); // limpa o \n do buffer
}


// Funções da Turma
void imprimirTurmas(const Turma turmas[]) {
    printf("----- Pontuacao das Casas -----\n");
    for (int i = 0; i < NUM_TURMAS; i++) {
        printf("Casa %s: %d pontos, %d bruxos cadastrados\n",
            turmas[i].nome, turmas[i].pontos, turmas[i].quantidade);
        }
    }

//Funções da Turma
// Aplica um bônus especial de 10 pontos para a Grifinoria
void bonusGrifinoria(Turma turmas[]) {
    for (int i = 0; i < NUM_TURMAS; i++) {
        if (strcmp(turmas[i].nome, "Grifinoria") == 0) {
            turmas[i].pontos += 10;
            printf("\n>> Grifinoria recebeu um bonus de 10 pontos pela bravura!\n");
            break;
        }
    }
}

//Funções da Turma
void discursoFinal(const Turma turmas[]) {
    printf("\n--- Fim do Torneio ---\n");

    int maiorPontuacao = -1;
    int campeoes[NUM_TURMAS];
    int numCampeoes = 0;

    for (int i = 0; i < NUM_TURMAS; i++) {
        printf("%s: %d pontos\n", turmas[i].nome, turmas[i].pontos);

        if (turmas[i].pontos > maiorPontuacao) {
            maiorPontuacao = turmas[i].pontos;
            campeoes[0] = i; // novo campeão
            numCampeoes = 1;
        } else if (turmas[i].pontos == maiorPontuacao) {
            campeoes[numCampeoes] = i;
            numCampeoes++;
        }
    }

    if (numCampeoes == 1) {
        printf("\nA grande campea foi: %s! Parabens!\n", turmas[campeoes[0]].nome);
    } else if (numCampeoes > 1) {
        printf("\nEmpate entre as casas:\n");
        for (int i = 0; i < numCampeoes; i++) {
            printf("- %s\n", turmas[campeoes[i]].nome);
        }
        printf("Todas estao de parabens pelo otimo desempenho!\n");
    } else {
        printf("Nenhuma turma acumulou pontos.\n");
    }
}

// Funções Desafio
// Desafio 1: QuadriLOL (Carisma e Destreza)
void quadriLOL(Turma turmas[]) {
    int maxCarisma = -1, maxDestreza = -1;
    int turmaCarisma = -1, turmaDestreza = -1;

    printf("\n[QuadriLOL] Disputa entre as casas por carisma e destreza!\n");

    for (int i = 0; i < NUM_TURMAS; i++) {
        int somaCarisma = 0, somaDestreza = 0;
        printf("- %s:\n", turmas[i].nome);
        for (int j = 0; j < turmas[i].quantidade; j++) {
            somaCarisma += turmas[i].bruxos[j].carisma;
            somaDestreza += turmas[i].bruxos[j].destreza;
            printf("  %s | Car: %d | Des: %d\n", turmas[i].bruxos[j].nome, turmas[i].bruxos[j].carisma, turmas[i].bruxos[j].destreza);
        }
        printf("  Total Carisma: %d | Total Destreza: %d\n", somaCarisma, somaDestreza);

        if (somaCarisma > maxCarisma) {
            maxCarisma = somaCarisma;
            turmaCarisma = i;
        }
        if (somaDestreza > maxDestreza) {
            maxDestreza = somaDestreza;
            turmaDestreza = i;
        }
    }

    turmas[turmaCarisma].pontos += 5;
    turmas[turmaDestreza].pontos += 10;

    printf("\n>> %s teve o maior carisma (+5 pontos)\n", turmas[turmaCarisma].nome);
    printf(">> %s teve a maior destreza (+10 pontos)\n", turmas[turmaDestreza].nome);
}

// Funções do Desafio
// Desafio 2: Artes Arcanistas Arcanas (inteligência)
void artesArcanas(Turma turmas[]) {
    int t1 = rand() % NUM_TURMAS;
    int t2;
    do {
        t2 = rand() % NUM_TURMAS;
    } while (t1 == t2);

    if (turmas[t1].quantidade == 0 || turmas[t2].quantidade == 0) {
        printf("Uma das turmas nao tem bruxos suficientes para o duelo.\n");
        return;
    }

    int b1 = rand() % turmas[t1].quantidade;
    int b2 = rand() % turmas[t2].quantidade;


    printf("\n[Artes Arcanistas Arcanas] Duelo de inteligencia!\n");
    printf("%s (%s) com %d\n", turmas[t1].bruxos[b1].nome, turmas[t1].nome, turmas[t1].bruxos[b1].inteligencia);
    printf("%s (%s) com %d\n", turmas[t2].bruxos[b2].nome, turmas[t2].nome, turmas[t2].bruxos[b2].inteligencia);

    if (turmas[t1].bruxos[b1].inteligencia > turmas[t2].bruxos[b2].inteligencia) {
        turmas[t1].pontos += 10;
        printf(">> Vencedor: %s (+10 pontos para %s)\n", turmas[t1].bruxos[b1].nome, turmas[t1].nome);
    } else if (turmas[t1].bruxos[b1].inteligencia < turmas[t2].bruxos[b2].inteligencia) {
        turmas[t2].pontos += 10;
        printf(">> Vencedor: %s (+10 pontos para %s)\n", turmas[t2].bruxos[b2].nome, turmas[t2].nome);
    } else {
        printf(">> Empate! Nenhuma casa ganha pontos.\n");
    }
}

//Funções dos Desafios
// Desafio 3: Pedra Floatzal (destreza)
void pedraFloatzal(Turma turmas[]) {
    printf("\n[Pedra Floatzal] 5 rodadas iniciadas!\n");

    int rodada = 1;
    char enter;

    while (rodada <= 5) {
        printf("\nPressione ENTER para iniciar a rodada %d...\n", rodada);
        while ((enter = getchar()) != '\n');  // Espera o usuário apertar Enter

        printf("\nRodada %d:\n", rodada);
        int menorSoma = 999;
        int perdedora = -1;
        int sorteados[NUM_TURMAS][3];

        for (int i = 0; i < NUM_TURMAS; i++) {
            int usados[NUM_BRUXOS] = {0};
            int soma = 0;
            printf("Casa %s:\n", turmas[i].nome);
            if (turmas[i].quantidade < 3) {
                printf("Casa %s nao tem bruxos suficientes para o desafio. Pulando...\n", turmas[i].nome);
                continue;
                }

            for (int j = 0; j < 3; j++) {
                int idx;
                do {
                    idx = rand() % turmas[i].quantidade;
                } while (usados[idx]);
                 usados[idx] = 1; // marca bruxo como 'usado'

                sorteados[i][j] = idx; //armazenar bruxos sorteados

                Bruxo* b = &turmas[i].bruxos[idx];
                printf("  %s | Des: %d\n", b->nome, b->destreza);
                soma += b->destreza;
            }
            printf("  Soma: %d\n", soma);
            if (turmas[i].quantidade >= 3 && soma < menorSoma) {
                menorSoma = soma;
                perdedora = i;
            }
        }
        if (perdedora == -1) {
            printf("\nNenhuma casa válida foi encontrada nesta rodada. Pulando...\n");
        }

        printf("\n>> A casa %s foi pega pelo Valdechar!\n", turmas[perdedora].nome);
        for (int j = 0; j < 3; j++) {
            Bruxo* b = &turmas[perdedora].bruxos[sorteados[perdedora][j]];
            b->inteligencia = 0;
            b->destreza = 0;
            b->carisma = 0;
            printf("  %s teve seus atributos zerados.\n", b->nome);
        }

        printf("\n>> Verificando Pedra Floatzal...\n");
        for (int i = 0; i < NUM_TURMAS; i++) {
            if (i != perdedora && (rand() % 100) < 10) {
                turmas[i].pontos += 20;
                printf("  %s encontrou a Pedra Floatzal! (+20 pontos)\n", turmas[i].nome);
            }
        }
        printf("\nPontuacao atual:\n");
        for (int i = 0; i < NUM_TURMAS; i++) {
            printf("  %s: %d pontos\n", turmas[i].nome, turmas[i].pontos);
        }

        rodada++;
    }
}

//Funções do Desafio
void executarDesafio(Turma turmas[], int* disputasExecutadas) {
    int opcao;
    printf("\nEscolha o desafio:\n");
    printf("1. QuadriLOL\n2. Artes Arcanistas Arcanas\n3. Buscando a Pedra 'floatzal'\n> ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida! Desafio cancelado.\n");
        while (getchar() != '\n'); // limpa o buffer
        return;
    }
    getchar(); // consome o '\n'


    switch (opcao) {
        case 1: quadriLOL(turmas); break;
        case 2: artesArcanas(turmas); break;
        case 3: pedraFloatzal(turmas);
            bonusGrifinoria(turmas);break;
        default: printf("Opcao invalida!\n"); return;
    }
    (*disputasExecutadas)++;
}

//Função Principal com o Menu
int main() {
    srand(time(NULL));

    Turma turmas[NUM_TURMAS] = {
        {"Grifinoria", 0, 0},
        {"Sonserina", 0, 0},
        {"Corvinal", 0, 0},
        {"Lufa-Lufa", 0, 0}
    };

    int disputasExecutadas = 0;
    int opcao;

    // Menu Inicial do Projeto
    system(LIMPAR);
    int escolha = menuInicial();
    system(LIMPAR);

    if (escolha == 1) {
        cadastrarBruxos(turmas);
    } else if (escolha == 2) {
        preCadastro(turmas);
    } else {
        printf("Opcao invalida! Encerrando programa...\n");
        return 0;
    }

    // Menu principal do Projeto
    do {
        system(LIMPAR);
        printf("Um novo torneio magico se inicia! Escolha uma opcao:\n");
        printf("\n--- MENU ---\n");
        printf("1. Imprimir dados das turmas\n");
        printf("2. Imprimir bruxos de uma turma\n");
        printf("3. Executar desafio\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        system(LIMPAR);
        switch (opcao) {
            case 1:
                imprimirTurmas(turmas);
                break;
            case 2:
                imprimirBruxosDaTurma(turmas);
                break;
            case 3:
                if (disputasExecutadas < 5) {
                    executarDesafio(turmas, &disputasExecutadas);
                    imprimirTurmas(turmas);
                } else {
                    printf("Limite de 5 disputas atingido!\n");
                }

                discursoFinal(turmas);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        if (opcao != 4) {
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
        }

    } while (opcao != 4);


    return 0;
}




