#include <iostream>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct no
{
    time_t criacao, remocao;
    struct no *prox;
};

void inserir(no **fila, no **fim)
{
    no *novo = (no *)malloc(sizeof(no));
    struct tm data;

    if (novo != NULL)
    {
        novo->prox = NULL;
        novo->criacao = time(NULL);
        data = *localtime(&novo->criacao);
    }

    if ((*fila) == NULL)
    {
        (*fila) = novo;
        (*fim) = novo;
    }
    else
    {
        (*fim)->prox = novo;
        (*fim) = novo;
    }
}

void entrada()
{
    cout << "\n\n\n ####   #    #  ######    #    #  ######       ####   #  #    #  #    #  #         ##    #####  #   ####   #    # ";
    cout << "\n#    #  #    #  #         #    #  #           #       #  ##  ##  #    #  #        #  #     #    #  #    #  ##   #";
    cout << "\n#    #  #    #  #####     #    #  #####        ####   #  # ## #  #    #  #       #    #    #    #  #    #  # #  # ";
    cout << "\n#  # #  #    #  #         #    #  #                #  #  #    #  #    #  #       ######    #    #  #    #  #  # #";
    cout << "\n#   #   #    #  #         #    #  #           #    #  #  #    #  #    #  #       #    #    #    #  #    #  #   ## ";
    cout << "\n ### #   ####   ######     ####   ######       ####   #  #    #   ####   ######  #    #    #    #   ####   #    # ";
    cout << "\n\n\n                                  #";
    cout << "\n                                  #         ####     ##    #####   #  #    #   #### ";
    cout << "\n                                  #        #    #   #  #   #    #  #  ##   #  #    # ";
    cout << "\n                                  #        #    #  #    #  #    #  #  # #  #  #      ";
    cout << "\n                                  #        #    #  ######  #    #  #  #  # #  #  ###";
    cout << "\n                                  #        #    #  #    #  #    #  #  #   ##  #    #";
    cout << "\n                                  #######   ####   #    #  #####   #  #    #   ####";
    cout << "\n\n\n\n          ( D ) ( E ) ( S ) ( E ) ( N ) ( V ) ( O ) ( L ) ( V ) ( E ) ( D ) ( O ) ( R )  " << endl;
    cout << "\n-------------------------------------------------" << endl;
    cout << "          Matheus Henry Barbosa Ra: 20068649       ";
    cout << "\n-------------------------------------------------" << endl;
    sleep(5);
}

void opcoes(int *duracao, int *insere, int *remove, int *remove2, int *delet1, int *delet2, int *especial)
{
    cout << "\n ----------------- Opcoes da simulacao----------------------";
    cout << "\n\n Informe o Tempo de duracao da Simulacao: : ";
    cin >> (*duracao);
    cout << "\n Informe o tempo para inserir nas filas : ";
    cin >> (*insere);
    cout << "\n Informe o tempo de atendimento da FILA 1 do Servidor (1) ";
    cin >> (*remove);
    cout << " \n Informe o tempo  de atendimento da FILA 2 do Servidor (2) ";
    cin >> (*remove2);
    cout << "\n (Voce chegou a fila especial FILA(3) com 2 servidores de atendimento!)" << endl;
    cout << " \n Qual tempo do atendimento do (1) servidor da fila (3): ";
    cin >> (*delet1);
    cout << "\n Qual tempo do atendiemento do (2) servidor da fila (3): ";
    cin >> (*delet2);
    cout << "\n Informe o tempo de atendimento do servidor especial (IDOSOS): ";
    cin >> (*especial);
    cout << "\n -----------------Simulacao esta preste a comecar------------";
    system("cls");
}

int deletar(no **fila, int *menor, int *maior, int *soma, int *qtdmin)
{
    struct tm data;
    time_t tempo;
    (*qtdmin) = (*qtdmin) + 1;

    if ((*fila) == NULL)
        return 0;

    else
    {
        no *lixo = (*fila);
        lixo->remocao = time(NULL);
        data = *localtime(&lixo->remocao);
        tempo = (difftime(lixo->remocao, lixo->criacao));
        (*soma) += tempo;
        if ((*menor) > tempo)
            (*menor) = tempo;
        if ((*maior) < tempo)
            (*maior) = tempo;
        (*fila) = (*fila)->prox;
        free(lixo);
    }
}

void imprime1(no *fila)
{
    struct tm data;
    time_t diferenca;

    while (fila != NULL)
    {
        cout << "\n\n                                (FILA 1)";
        cout << "\n ---------------------------------------------------------------------------";
        data = *localtime(&fila->criacao);
        cout << " \n Cliente, Horario de chegada 1 : " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        diferenca = time(NULL);
        cout << "\n Tempo de fila " << difftime(diferenca, fila->criacao) << " Segundos";
        cout << "\n ---------------------------------------------------------------------------" << endl;
        fila = fila->prox;
    }
}

void imprime2(no *fila2)
{
    struct tm data;
    time_t diferenca2;

    while (fila2 != NULL)
    {
        cout << "\n\n                                (FILA 2)";
        cout << "\n ---------------------------------------------------------------------------";
        data = *localtime(&fila2->criacao);
        cout << " \n Cliente, Horario de chegada 2 : " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        diferenca2 = time(NULL);
        cout << "\n Tempo de fila " << difftime(diferenca2, fila2->criacao) << " Segundos";
        cout << "\n ---------------------------------------------------------------------------" << endl;
        fila2 = fila2->prox;
    }
}

void imprime3(no *fila3)
{
    struct tm data;
    time_t diferenca3;

    while (fila3 != NULL)
    {
        cout << "\n\n                                (FILA 3)";
        cout << "\n ---------------------------------------------------------------------------";
        data = *localtime(&fila3->criacao);
        cout << " \n Cliente, Horario de chegada 3 : " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        diferenca3 = time(NULL);
        cout << "\n Tempo de fila " << difftime(diferenca3, fila3->criacao) << " Segundos";
        cout << "\n ---------------------------------------------------------------------------" << endl;
        fila3 = fila3->prox;
    }
}

int removerIDOSO(no **fila, int *somaIDOSO, int *menorIDOSO, int *maiorIDOSO)
{
    struct tm data;
    time_t tempoidoso;

    if ((*fila == NULL))
        return 0;

    else
    {
        no *lixo2 = (*fila);
        lixo2->remocao = time(NULL);
        data = *localtime(&lixo2->remocao);
        tempoidoso = (difftime(lixo2->remocao, lixo2->criacao));
        if ((*menorIDOSO) > tempoidoso)
            (*menorIDOSO) = tempoidoso;
        if ((*maiorIDOSO) < tempoidoso)
            (*maiorIDOSO) = tempoidoso;
        (*somaIDOSO) += tempoidoso;
        (*fila) = (*fila)->prox;
        free(lixo2);
    }
}

void imprime4(no *filaESPECIAL)
{
    struct tm data;
    time_t diferenca3;

    while (filaESPECIAL != NULL)
    {
        cout << "\n\n                                (FILA ESPECIAL)";
        cout << "\n ---------------------------------------------------------------------------";
        data = *localtime(&filaESPECIAL->criacao);
        cout << " \n Idoso horario de chegada  : " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        diferenca3 = time(NULL);
        cout << "\n Tempo de fila " << difftime(diferenca3, filaESPECIAL->criacao) << " Segundos";
        cout << "\n ---------------------------------------------------------------------------" << endl;
        filaESPECIAL = filaESPECIAL->prox;
    }
}

int main()
{
    entrada();
    system("cls");
    time_t atual, inicio;
    no *fila1 = NULL, *fim1 = NULL, *fila2 = NULL, *fim2 = NULL, *fila3 = NULL, *fim3 = NULL;
    int opcao, qtd = 0, menor = 9999, maior = 0, soma = 0, qtdmin = 0, duracao, insere, remove, remove2, qtd2 = 0, total5 = 0, total6 = 0, qtd3 = 0, delet1, delet2;
    int total7 = 0, soma1 = 0, soma2 = 0, soma3 = 0, cont = 0, somaIDOSO = 0, mediaIDOSO, maiorIDOSO = 0, menorIDOSO = 9999, especial;
    no *filaESPECIAL = NULL, *fimESPECIAL = NULL;

    opcoes(&duracao, &insere, &remove, &remove2, &delet1, &delet2, &especial);
    time(&atual);
    time(&inicio);

    while ((int)difftime(atual, inicio) <= duracao)
    {
        cout << " \n\n ----------------------- Simulation started --------------------------------";
        cout << "\n Tempo de simulacao : " << difftime(atual, inicio) << " Segundos ";
        cout << " (Tempo esperado de simulacao:" << duracao << " Segundos )" << endl;
        cout << "\n |Pressione Enter para inserir um idoso !|" << endl;

        if (kbhit())
        {
            inserir(&filaESPECIAL, &fimESPECIAL);
            cont++;
            cin.ignore();
        }
        else
        {
            if ((int)difftime(atual, inicio) % insere == 0 && (int)difftime(atual, inicio))
            {
                if (qtd < qtd2 && qtd < qtd3)
                {
                    inserir(&fila1, &fim1);
                    qtd++;
                    soma1++;
                }
                else if (qtd2 < qtd && qtd2 < qtd3)
                {
                    inserir(&fila2, &fim2);
                    qtd2++;
                    soma2++;
                }
                else if (qtd3 < qtd && qtd3 < qtd2)
                {
                    inserir(&fila3, &fim3);
                    qtd3++;
                    soma3++;
                }

                else
                {
                    inserir(&fila1, &fim1);
                    qtd++;
                    soma1++;
                    inserir(&fila2, &fim2);
                    qtd2++;
                    soma2++;
                    inserir(&fila3, &fim3);
                    qtd3++;
                    soma3++;
                }
            }

            if ((int)difftime(atual, inicio) % delet1 == 0 && (int)difftime(atual, inicio) != 0 && qtd3 > 0)
            {
                deletar(&fila3, &menor, &maior, &soma, &qtdmin);
                total7++;
                qtd3--;
            }

            if ((int)difftime(atual, inicio) % delet2 == 0 && (int)difftime(atual, inicio) != 0 && qtd3 > 0)
            {
                deletar(&fila3, &menor, &maior, &soma, &qtdmin);
                total7++;
                qtd3--;
            }

            if ((int)difftime(atual, inicio) % remove == 0 && (int)difftime(atual, inicio) != 0 && qtd > 0)
            {
                deletar(&fila1, &menor, &maior, &soma, &qtdmin);
                total5++;
                qtd--;
            }

            if ((int)difftime(atual, inicio) % remove2 == 0 && (int)difftime(atual, inicio) != 0 && qtd2 > 0)
            {
                deletar(&fila2, &menor, &maior, &soma, &qtdmin);
                total6++;
                qtd2--;
            }

            if ((int)difftime(atual, inicio) % especial == 0 && (int)difftime(atual, inicio) != 0)
            {
                removerIDOSO(&filaESPECIAL, &somaIDOSO, &menorIDOSO, &maiorIDOSO);
            }

            imprime3(fila3);
            imprime1(fila1);
            imprime2(fila2);
            imprime4(filaESPECIAL);

            Sleep(900);
            system("cls");
            time(&atual);
        }
    }

    cout << "----------------------------------------------------------------------------\n";
    cout << "                  (Relatorio final Fim da simulacao)" << endl;
    cout << "\n Total de clientes que entraram nas filas : " << (soma1 + soma2 + soma3) << " Pessoas";
    cout << "\n Total de clientes atendidos nas filas : " << qtdmin << " Pessoas ";
    cout << "\n O menor tempo de espera do Cliente nas filas foi : " << menor << " Segundos";
    cout << "\n O maior tempo espera do Cliente nas filas foi : " << maior << " segundos";
    cout << "\n O tempo medio dos clientes na filas foi : " << float(soma / (soma1 + soma2 + soma3)) << " segundos";
    cout << "\n O Tempo total de espera de todos clientes e : " << soma << " segundos";
    cout << "\n O numero de clientes que restaram na fila (1) minimo e : " << (soma1 - total5) << " pessoas ";
    cout << "\n O numero de clientes que restaram na fila (2) minimo e : " << (soma2 - total6) << " pessoas ";
    cout << "\n O numero de clientes que restaram na fila (3) minimo e : " << (soma3 - total7) << " pessoas ";
    cout << "\n O Numero medio dos clientes que participaram das filas e : " << (soma1 + soma2 + soma3) / 3 << " pessoas";
    cout << "\n O numero de clientes que entraram na (1) fila: " << soma1 << " pessoas";
    cout << "\n O numero de clientes que entraram na (2) fila: " << soma2 << " pessoas";
    cout << "\n O numero de clientes que entraram na (3) fila: " << soma3 << " pessoas";
    cout << "\n O numero de clientes que foram atendidos na fila (1) e : " << total5 << " pessoas";
    cout << "\n O numero de clientes que foram atendidos na fila (2) e : " << total6 << " pessoas";
    cout << "\n O numero de clientes que foram atendidos na fila (3) e : " << total7 << " pessoas";
    cout << "\n----------------------------------------------------------------------------\n";
    cout << "\n --------------------------(FILA ESPECIAL )---------------------------------\n";
    cout << " \n Total de clientes que entraram na fila especial : " << cont << " Pessoas ";
    cout << "\n Somatoria do tempo de fila dos idosos : " << somaIDOSO << " Segundos ";
    cout << "\n O tempo medio na fila especial : " << (somaIDOSO / cont) << " Segundos";
    cout << "\n O maior tempo de espera na fila especial : " << maiorIDOSO << " Segundos ";
    cout << "\n O menor tempo na fila de espera especial  : " << menorIDOSO << " Segundos";
    cout << "\n----------------------------------------------------------------------------\n";
    return 0;
}