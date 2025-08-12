#include <stdio.h>
#include <string.h>

char estado, estado2;
char codigoCarta[50], nomeCidade[50], codigoCarta2[50], nomeCidade2[50];
unsigned long int populacao, populacao2;
int numeroPontosTuristicos, numeroPontosTuristicos2;
double area, pib, area2, pib2, pibPerCapta, pibPerCapta2, densidadePopulacional, densidadePopulacional2;

void readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void entradaDados()
{
    char estadoStr[10], populacaoStr[20], areaStr[20], pibStr[20], pontosStr[20];
    char estadoStr2[10], populacaoStr2[20], areaStr2[20], pibStr2[20], pontosStr2[20];

    printf("\nDigite abaixo os dados da primeira carta:");

    printf("\nEstado: ");
    readLine(estadoStr, sizeof(estadoStr));
    estado = estadoStr[0];

    printf("Código: ");
    readLine(codigoCarta, sizeof(codigoCarta));

    printf("Nome da Cidade: ");
    readLine(nomeCidade, sizeof(nomeCidade));

    printf("População: ");
    readLine(populacaoStr, sizeof(populacaoStr));
    sscanf(populacaoStr, "%lu", &populacao);

    printf("Área: ");
    readLine(areaStr, sizeof(areaStr));
    sscanf(areaStr, "%lf", &area);

    printf("PIB: ");
    readLine(pibStr, sizeof(pibStr));
    sscanf(pibStr, "%lf", &pib);

    printf("Número de Pontos Turísticos: ");
    readLine(pontosStr, sizeof(pontosStr));
    sscanf(pontosStr, "%d", &numeroPontosTuristicos);

    printf("\nDigite abaixo os dados da segunda carta:");

    printf("\nEstado: ");
    readLine(estadoStr2, sizeof(estadoStr2));
    estado2 = estadoStr2[0];

    printf("Código: ");
    readLine(codigoCarta2, sizeof(codigoCarta2));

    printf("Nome da Cidade: ");
    readLine(nomeCidade2, sizeof(nomeCidade2));

    printf("População: ");
    readLine(populacaoStr2, sizeof(populacaoStr2));
    sscanf(populacaoStr2, "%lu", &populacao2);

    printf("Área: ");
    readLine(areaStr2, sizeof(areaStr2));
    sscanf(areaStr2, "%lf", &area2);

    printf("PIB: ");
    readLine(pibStr2, sizeof(pibStr2));
    sscanf(pibStr2, "%lf", &pib2);

    printf("Número de Pontos Turísticos: ");
    readLine(pontosStr2, sizeof(pontosStr2));
    sscanf(pontosStr2, "%d", &numeroPontosTuristicos2);

    printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
}

double calcularDensidadePopulacional()
{
    if (area != 0 && populacao != 0)
    {
        return (double)populacao / area;
    }
    else
    {
        printf("O valor de área e população não pode ser zero!");
        return 0.0;
    }
}

double calcularPibPerCapta()
{
    if (pib != 0 && populacao != 0)
    {
        return (pib * 1e9) / (double)populacao;
    }
    else
    {
        printf("O valor de área e população não pode ser zero!");
        return 0.0;
    }
}

double calcularDensidadePopulacional2()
{
    if (area2 != 0 && populacao2 != 0)
    {
        return (double)populacao2 / area2;
    }
    else
    {
        printf("O valor de área e população não pode ser zero!");
        return 0.0;
    }
}

double calcularPibPerCapta2()
{
    if (pib2 != 0 && populacao2 != 0)
    {
        return (pib2 * 1e9) / (double)populacao2;
    }
    else
    {
        printf("O valor de área e população não pode ser zero!");
        return 0.0;
    }
}

void exibeCalculosCarta1()
{
    densidadePopulacional = calcularDensidadePopulacional();
    pibPerCapta = calcularPibPerCapta();

    printf("Densidade Populacional:  %.2lf hab/km²", densidadePopulacional);
    printf("\nPIB per Capita:  %.2lf reais", pibPerCapta);
    printf("\n");
}

void exibeCalculosCarta2()
{
    densidadePopulacional2 = calcularDensidadePopulacional2();
    pibPerCapta2 = calcularPibPerCapta2();

    printf("Densidade Populacional:  %.2lf hab/km²", densidadePopulacional2);
    printf("\nPIB per Capita:  %.2lf reais", pibPerCapta2);
    printf("\n");
}

double superPoderCarta()
{
    double inversoDensidade = 1.0 / densidadePopulacional;

    double superPoder = (double)populacao + area + pib + numeroPontosTuristicos + pibPerCapta + inversoDensidade;

    return superPoder;
}

double superPoderCarta2()
{
    double inversoDensidade2 = 1.0 / densidadePopulacional2;

    double superPoder2 = (double)populacao2 + area2 + pib2 + numeroPontosTuristicos2 + pibPerCapta2 + inversoDensidade2;

    return superPoder2;
}

void compararAtributoEscolhido()
{
    int atributo1, atributo2;

    densidadePopulacional = calcularDensidadePopulacional();
    pibPerCapta = calcularPibPerCapta();
    densidadePopulacional2 = calcularDensidadePopulacional2();
    pibPerCapta2 = calcularPibPerCapta2();

    printf("\n=== Escolha um atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("========================================\n");

    printf("\nDigite o número do primeiro atributo: ");
    scanf("%d", &atributo1);

    printf("Digite o número do segundo atributo: ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2)
    {
        printf("\nErro: Você não pode escolher o mesmo atributo duas vezes. Tente novamente.\n");
        return compararAtributoEscolhido(); // Perguntar ao ChatGPT se é possível fazer isso em C
    }

    printf("\nPrimeiro atributo escolhido:\n");
    switch (atributo1)
    {
    case 1:
        printf("\nComparação de cartas (Atributo: População):\n");
        printf("\nPrimeira carta - São Paulo (SP): %lu", populacao);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %lu", populacao2);
        break;
    case 2:
        printf("\nComparação de cartas (Atributo: Área):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", area);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", area2);
        break;
    case 3:
        printf("\nComparação de cartas (Atributo: PIB):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", pib);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", pib2);
        break;
    case 4:
        printf("\nComparação de cartas (Atributo: Densidade Populacional):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", densidadePopulacional);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", densidadePopulacional2);
        break;
    case 5:
        printf("\nComparação de cartas (Atributo: PIB per capita):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", pibPerCapta);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", pibPerCapta2);
        break;
    default:
        break;
    }

    if (atributo1 == 1)
    {
        if (populacao > populacao2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (populacao < populacao2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo1 == 2)
    {
        if (area > area2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (area < area2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo1 == 3)
    {
        if (pib > pib2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (pib < pib2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo1 == 4)
    {
        if (densidadePopulacional < densidadePopulacional2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (densidadePopulacional > densidadePopulacional2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo1 == 5)
    {
        if (pibPerCapta > pibPerCapta2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (pibPerCapta < pibPerCapta2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else
    {
        printf("\nValor não reconhecido, encerrando...\n");
    }

    printf("\n");
    printf("\nSegundo atributo escolhido:\n");
    switch (atributo2)
    {
    case 1:
        printf("\nComparação de cartas (Atributo: População):\n");
        printf("\nPrimeira carta - São Paulo (SP): %lu", populacao);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %lu", populacao2);
        break;
    case 2:
        printf("\nComparação de cartas (Atributo: Área):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", area);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", area2);
        break;
    case 3:
        printf("\nComparação de cartas (Atributo: PIB):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", pib);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", pib2);
        break;
    case 4:
        printf("\nComparação de cartas (Atributo: Densidade Populacional):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", densidadePopulacional);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", densidadePopulacional2);
        break;
    case 5:
        printf("\nComparação de cartas (Atributo: PIB per capita):\n");
        printf("\nPrimeira carta - São Paulo (SP): %.2lf", pibPerCapta);
        printf("\nSegunda carta - Rio de Janeiro (RJ): %.2lf", pibPerCapta2);
        break;
    default:
        break;
    }

    if (atributo2 == 1)
    {
        if (populacao > populacao2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (populacao < populacao2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo2 == 2)
    {
        if (area > area2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (area < area2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo2 == 3)
    {
        if (pib > pib2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (pib < pib2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo2 == 4)
    {
        if (densidadePopulacional < densidadePopulacional2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (densidadePopulacional > densidadePopulacional2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else if (atributo2 == 5)
    {
        if (pibPerCapta > pibPerCapta2)
        {
            printf("\nResultado: Primeira carta (%s) venceu!", nomeCidade);
        }
        else if (pibPerCapta < pibPerCapta2)
        {
            printf("\nResultado: Segunda carta (%s) venceu!", nomeCidade2);
        }
        else
        {
            printf("\nTemos um empate!");
        }
    }
    else
    {
        printf("\nValor não reconhecido, encerrando...\n");
    }
}

void saidaDados()
{
    printf("\nPrimeira carta:");
    printf("\nEstado: %c", estado);
    printf("\nCódigo da Carta: %s", codigoCarta);
    printf("\nNome da Cidade: %s", nomeCidade);
    printf("\nPopulação: %lu", populacao);
    printf("\nÁrea: %.2lf km²", area);
    printf("\nPIB: %.2lf bilhões de reais", pib);
    printf("\nNúmero de Pontos Turísticos: %d\n", numeroPontosTuristicos);
    exibeCalculosCarta1();
    printf("Super Poder primeira carta:  %.2lf\n", superPoderCarta());

    printf("\nSegunda carta:");
    printf("\nEstado: %c", estado2);
    printf("\nCódigo da Carta: %s", codigoCarta2);
    printf("\nNome da Cidade: %s", nomeCidade2);
    printf("\nPopulação: %lu", populacao2);
    printf("\nÁrea: %.2lf km²", area2);
    printf("\nPIB: %.2lf bilhões de reais", pib2);
    printf("\nNúmero de Pontos Turísticos: %d\n", numeroPontosTuristicos2);
    exibeCalculosCarta2();
    printf("Super Poder segunda carta:  %.2lf\n", superPoderCarta2());

    printf("\nPopulação: %s carta venceu (%d)\n", populacao > populacao2 ? "Primeira" : "Segunda", populacao > populacao2);
    printf("Área: %s carta venceu (%d)\n", area > area2 ? "Primeira" : "Segunda", area > area2);
    printf("PIB: %s carta venceu (%d)\n", pib > pib2 ? "Primeira" : "Segunda", pib > pib2 ? 1 : 0);
    printf("Pontos Turísticos: %s carta venceu (%d)\n", numeroPontosTuristicos > numeroPontosTuristicos2 ? "Primeira" : "Segunda", numeroPontosTuristicos > numeroPontosTuristicos2);
    printf("Densidade Populacional: %s carta venceu (%d)\n", densidadePopulacional < densidadePopulacional2 ? "Primeira" : "Segunda", densidadePopulacional < densidadePopulacional2); // quanto menor, melhor
    printf("PIB per Capita: %s carta venceu (%d)\n", pibPerCapta > pibPerCapta2 ? "Primeira" : "Segunda", pibPerCapta > pibPerCapta2);
    printf("Super Poder: %s carta venceu (%d)\n", superPoderCarta() > superPoderCarta2() ? "Primeira" : "Segunda", superPoderCarta() > superPoderCarta2());
}

int main()
{
    printf("\n***Super Trunfo - Desafio aventureiro***\n");

    entradaDados();
    saidaDados();
    compararAtributoEscolhido();

    /*if (atributo1 != atributo2) {
        compararAtributos();
    }*/

    return 0;
}
