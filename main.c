/* ME2 Programação Avançada
* Alunos: Fábio Bandolin Martins, Gladiston Teles , João Victor de Andrade e Paulo Felipe Rezende da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

#define MAX_CLIENTES 1000
#define MAX_AUTOMOVEIS 1000
#define MAX_FUNCIONARIOS 1000

// Structs

// Dados em memória


////
///
///
///
#define MAX_CLIENTES 1000
#define MAX_AUTOMOVEIS 1000
#define MAX_FUNCIONARIOS 1000
#define MAX_UNIDADES 100
#define MAX_MANUTENCOES 1000
#define MAX_LOCACOES 1000
#define MAX_OFICINAS 100

// Structs

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char tipoVia[50];
    char nomeVia[100];
    int numero;
    char cep[10];
    char cidade[50];
    char estado[3];
    char bairro[50];
} Endereco;

typedef struct {
    int idCliente;
    char nome[100];
    char cpf[15];
    char dataNascimento[11];
    Endereco endereco;
    char cnh[20];
    char telefone[20];
} Cliente;

typedef struct {
    char placa[10];
    char modelo[50];
    char marca[50];
    int ano;
    char chassi[20];
    char tipo[30];
    int disponivel;
} Automovel;

typedef struct {
    int idFuncionario;
    char cpf[15];
    char nome[100];
    char dataNascimento[11];
    char telefone[20];
    float salario;
} Funcionario;

typedef struct {
    int idUnidade;
    char cidade[50];
    Endereco endereco;
    char telefone[20];
} Unidade;

typedef struct {
    float valor;
    char formaPagamento[30];
} Pagamento;

typedef struct {
    char tipo[50];
    float valor;
} DebitoAdicional;

typedef struct {
    int idOficina;
    Endereco endereco;
    char cnpj[20];
    char nome[100];
} Oficina;

typedef struct {
    int idManutencao;
    char placaAutomovel[10];
    char tipo[50];
    int duracaoPrevista;
    int idOficina;
    float custo;
} Manutencao;

typedef struct {
    int idLocacao;
    int idCliente;
    int idUnidade;
    char placaAutomovel[10];
    int duracao;
    Data dataLocacao;
    Pagamento pagamento;
    DebitoAdicional debito;
} Locacao;

typedef struct {
    int idCliente;
    int idFuncionario;
    char placaAutomovel[10];
    Pagamento pagamento;
    DebitoAdicional debito;
    float custoTotal;
} RelatorioLocacao;

// Protótipos dos menus e funções
void menuClientes();
void menuAutomoveis();
void menuManutencoes();
void menuRelatorios();
void cadastrarUnidade();
void listarUnidades();
void cadastrarFuncionario();
void listarFuncionarios();
void realizarLocacao();
void listarLocacoes();

// Arrays globais
Cliente clientes[MAX_CLIENTES]; int numClientes = 0;
Automovel automoveis[MAX_AUTOMOVEIS]; int numAutomoveis = 0;
Funcionario funcionarios[MAX_FUNCIONARIOS]; int numFuncionarios = 0;
Unidade unidades[MAX_UNIDADES]; int numUnidades = 0;
Manutencao manutencoes[MAX_MANUTENCOES]; int numManutencoes = 0;
Locacao locacoes[MAX_LOCACOES]; int numLocacoes = 0;

// Funções
void cadastrarCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }
    Cliente c;
    c.idCliente = numClientes + 1;
    printf("Nome: "); fflush(stdin); fgets(c.nome, 100, stdin);
    printf("CPF: "); scanf("%s", c.cpf);
    printf("Data de nascimento (dd/mm/aaaa): "); scanf("%s", c.dataNascimento);
    printf("CNH: "); scanf("%s", c.cnh);
    printf("Telefone: "); scanf("%s", c.telefone);

    printf("Tipo de via: "); fflush(stdin); fgets(c.endereco.tipoVia, 50, stdin);
    printf("Nome da via: "); fgets(c.endereco.nomeVia, 100, stdin);
    printf("Número: "); scanf("%d", &c.endereco.numero);
    printf("CEP: "); scanf("%s", c.endereco.cep);
    printf("Cidade: "); scanf("%s", c.endereco.cidade);
    printf("Estado: "); scanf("%s", c.endereco.estado);
    printf("Bairro: "); scanf("%s", c.endereco.bairro);

    clientes[numClientes++] = c;
    printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes() {
    for (int i = 0; i < numClientes; i++) {
        printf("ID: %d - Nome: %s\n", clientes[i].idCliente, clientes[i].nome);
    }
}

void cadastrarAutomovel() {
    if (numAutomoveis >= MAX_AUTOMOVEIS) {
        printf("Limite de automóveis atingido.\n");
        return;
    }
    Automovel a;
    printf("Placa: "); scanf("%s", a.placa);
    printf("Modelo: "); scanf("%s", a.modelo);
    printf("Marca: "); scanf("%s", a.marca);
    printf("Ano: "); scanf("%d", &a.ano);
    printf("Chassi: "); scanf("%s", a.chassi);
    printf("Tipo: "); scanf("%s", a.tipo);
    a.disponivel = 1;

    automoveis[numAutomoveis++] = a;
    printf("Automóvel cadastrado com sucesso!\n");
}

void listarAutomoveis() {
    for (int i = 0; i < numAutomoveis; i++) {
        printf("Placa: %s - Modelo: %s - Disponível: %s\n", automoveis[i].placa, automoveis[i].modelo, automoveis[i].disponivel ? "Sim" : "Não");
    }
}

void cadastrarFuncionario() {
    if (numFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionários atingido.\n");
        return;
    }
    Funcionario f;
    f.idFuncionario = numFuncionarios + 1;
    printf("Nome: "); fflush(stdin); fgets(f.nome, 100, stdin);
    printf("CPF: "); scanf("%s", f.cpf);
    printf("Data de nascimento (dd/mm/aaaa): "); scanf("%s", f.dataNascimento);
    printf("Telefone: "); scanf("%s", f.telefone);
    printf("Salário: "); scanf("%f", &f.salario);

    funcionarios[numFuncionarios++] = f;
    printf("Funcionário cadastrado com sucesso!\n");
}

void listarFuncionarios() {
    for (int i = 0; i < numFuncionarios; i++) {
        printf("ID: %d - Nome: %s\n", funcionarios[i].idFuncionario, funcionarios[i].nome);
    }
}

// Submenus
void menuClientes() {
    int opcao;
    do {
        printf("\n--- Menu Clientes ---\n");
        printf("1. Cadastrar Cliente\n2. Listar Clientes\n3. Voltar\nEscolha: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes(); break;
        }
    } while(opcao != 3);
}

void menuAutomoveis() {
    int opcao;
    do {
        printf("\n--- Menu Automóveis ---\n");
        printf("1. Cadastrar Automóvel\n2. Listar Automóveis\n3. Voltar\nEscolha: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: cadastrarAutomovel(); break;
            case 2: listarAutomoveis(); break;
        }
    } while(opcao != 3);
}

void menuFuncionarios() {
    int opcao;
    do {
        printf("\n--- Menu Funcionários ---\n");
        printf("1. Cadastrar Funcionário\n2. Listar Funcionários\n3. Voltar\nEscolha: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: cadastrarFuncionario(); break;
            case 2: listarFuncionarios(); break;
        }
    } while(opcao != 3);
}

// Funções de exemplo (demais funções podem ser adicionadas conforme necessário)

void cadastrarUnidade() {
    Unidade u;
    u.idUnidade = numUnidades + 1;
    printf("Cidade da unidade: "); scanf("%s", u.cidade);
    printf("Telefone: "); scanf("%s", u.telefone);
    printf("Endereço - Tipo de via: "); scanf("%s", u.endereco.tipoVia);
    printf("Nome da via: "); scanf("%s", u.endereco.nomeVia);
    printf("Número: "); scanf("%d", &u.endereco.numero);
    printf("CEP: "); scanf("%s", u.endereco.cep);
    printf("Cidade: "); scanf("%s", u.endereco.cidade);
    printf("Estado: "); scanf("%s", u.endereco.estado);
    printf("Bairro: "); scanf("%s", u.endereco.bairro);
    unidades[numUnidades++] = u;
    printf("Unidade cadastrada com sucesso!\n");
}

void listarUnidades() {
    for (int i = 0; i < numUnidades; i++) {
        printf("ID: %d - Cidade: %s - Telefone: %s\n", unidades[i].idUnidade, unidades[i].cidade, unidades[i].telefone);
    }
}
void menuManutencoes() {
    int opcao;
    do {
        printf("\n--- Menu Manutenções ---\n");
        printf("1. Cadastrar Manutenção\n");
        printf("2. Listar Manutenções\n");
        printf("3. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Manutencao m;
            m.idManutencao = numManutencoes + 1;
            printf("Placa do Automóvel: "); scanf("%s", m.placaAutomovel);
            printf("Tipo de manutenção: "); scanf("%s", m.tipo);
            printf("Duração prevista (dias): "); scanf("%d", &m.duracaoPrevista);
            printf("ID da oficina: "); scanf("%d", &m.idOficina);
            printf("Custo: "); scanf("%f", &m.custo);

            for (int i = 0; i < numAutomoveis; i++) {
                if (strcmp(automoveis[i].placa, m.placaAutomovel) == 0) {
                    automoveis[i].disponivel = 0;
                    break;
                }
            }

            manutencoes[numManutencoes++] = m;
            printf("Manutenção cadastrada.\n");
        } else if (opcao == 2) {
            for (int i = 0; i < numManutencoes; i++) {
                printf("ID: %d - Placa: %s - Tipo: %s - Oficina: %d - Custo: %.2f\n",
                    manutencoes[i].idManutencao,
                    manutencoes[i].placaAutomovel,
                    manutencoes[i].tipo,
                    manutencoes[i].idOficina,
                    manutencoes[i].custo);
            }
        }
    } while (opcao != 3);
}

void realizarLocacao() {
    if (numClientes == 0 || numUnidades == 0 || numAutomoveis == 0) {
        printf("Certifique-se de que há clientes, unidades e automóveis cadastrados.\n");
        return;
    }

    Locacao l;
    l.idLocacao = numLocacoes + 1;

    printf("ID do cliente: "); scanf("%d", &l.idCliente);
    printf("ID da unidade: "); scanf("%d", &l.idUnidade);
    printf("Placa do automóvel: "); scanf("%s", l.placaAutomovel);
    printf("Duração (dias): "); scanf("%d", &l.duracao);

    printf("Data da locação (dd mm aaaa): ");
    scanf("%d %d %d", &l.dataLocacao.dia, &l.dataLocacao.mes, &l.dataLocacao.ano);

    printf("Valor: "); scanf("%f", &l.pagamento.valor);
    printf("Forma de pagamento: "); scanf("%s", l.pagamento.formaPagamento);

    printf("Débito adicional (tipo): "); scanf("%s", l.debito.tipo);
    printf("Débito adicional (valor): "); scanf("%f", &l.debito.valor);

    for (int i = 0; i < numAutomoveis; i++) {
        if (strcmp(automoveis[i].placa, l.placaAutomovel) == 0) {
            if (automoveis[i].disponivel == 0) {
                printf("Erro: veículo indisponível para locação.\n");
                return;
            }
            automoveis[i].disponivel = 0;
            break;
        }
    }

    locacoes[numLocacoes++] = l;
    printf("Locação registrada com sucesso!\n");
}

void listarLocacoes() {
    for (int i = 0; i < numLocacoes; i++) {
        printf("Locação %d: Cliente ID %d, Unidade ID %d, Placa %s, Valor: %.2f\n",
               locacoes[i].idLocacao,
               locacoes[i].idCliente,
               locacoes[i].idUnidade,
               locacoes[i].placaAutomovel,
               locacoes[i].pagamento.valor);
    }
}

void menuRelatorios() {
    printf("\n--- Relatórios ---\n");
    for (int i = 0; i < numLocacoes; i++) {
        float custoTotal = locacoes[i].pagamento.valor + locacoes[i].debito.valor;
        printf("Relatório Locação %d:\n", locacoes[i].idLocacao);
        printf("  Cliente ID: %d\n", locacoes[i].idCliente);
        printf("  Automóvel: %s\n", locacoes[i].placaAutomovel);
        printf("  Pagamento: %.2f (%s)\n",
               locacoes[i].pagamento.valor, locacoes[i].pagamento.formaPagamento);
        printf("  Débito adicional: %.2f (%s)\n",
               locacoes[i].debito.valor, locacoes[i].debito.tipo);
        printf("  Custo total: %.2f\n\n", custoTotal);
    }
}


// Menu principal
void menuPrincipal() {
    int opcao;
    do {
        printf("\n====== SISTEMA LOCADORA ======\n");
        printf("\t 1. Gestão de Clientes\n");
        printf("\t 2. Gestão de Automóveis\n");
        printf("\t 3. Cadastrar Unidade\n");
        printf("\t 4. Listar Unidades\n");
        printf("\t 5. Cadastrar Funcionário\n");
        printf("\t 6. Listar Funcionários\n");
        printf("\t 7. Gestão de Manutenções\n");
        printf("\t 8. Realizar Locação\n");
        printf("\t 9. Listar Locações\n");
        printf("\t 10. Gerar Relatórios\n");
        printf("\t 0. Sair\n");
        printf("\n\t Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: menuClientes(); break;
            case 2: menuAutomoveis(); break;
            case 3: cadastrarUnidade(); break;
            case 4: listarUnidades(); break;
            case 5: cadastrarFuncionario(); break;
            case 6: listarFuncionarios(); break;
            case 7: menuManutencoes(); break;
            case 8: realizarLocacao(); break;
            case 9: listarLocacoes(); break;
            case 10: menuRelatorios(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 0);
}

void seedInicial() {
    // Cliente
    Cliente c = {
        .idCliente = 1,
        .nome = "Joao Silva",
        .cpf = "12345678900",
        .dataNascimento = "01/01/1990",
        .cnh = "CNH123456",
        .telefone = "79999999999",
        .endereco = {
            .tipoVia = "Rua",
            .nomeVia = "Central",
            .numero = 100,
            .cep = "49000000",
            .cidade = "Aracaju",
            .estado = "SE",
            .bairro = "Centro"
        }
    };
    clientes[numClientes++] = c;

    // Automóvel
    Automovel a = {
        .placa = "ABC1234",
        .modelo = "Onix",
        .marca = "Chevrolet",
        .ano = 2020,
        .chassi = "CHASSI123456",
        .tipo = "Hatch",
        .disponivel = 1
    };
    automoveis[numAutomoveis++] = a;

    // Unidade
    Unidade u = {
        .idUnidade = 1,
        .cidade = "Aracaju",
        .telefone = "7933334444",
        .endereco = {
            .tipoVia = "Avenida",
            .nomeVia = "Beira Mar",
            .numero = 500,
            .cep = "49030100",
            .cidade = "Aracaju",
            .estado = "SE",
            .bairro = "13 de Julho"
        }
    };
    unidades[numUnidades++] = u;
}

int main() {
    SetConsoleOutputCP( 65001 );
    seedInicial();
    menuPrincipal();
    return 0;
}

