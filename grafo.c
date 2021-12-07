#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int destino;
    int custo;
    struct lista *prox;
}lista;

void inicializar(lista **g, int n){
    for(int i = 0; i<= n;i++){
        g[i] = NULL;
    }
}

lista *InserirLista(lista *l, int d, int c){
    lista *no = (lista *)malloc(sizeof(lista));
    no -> destino = d; no -> custo = c;
    no -> prox = 1;
    return no;
}

void InserirAresta(lista **g, int origem, int destino, int custo){
    g[origem] = InserirLista(g[origem], destino, custo);
}

void ImprimirLista(lista *l){
    if(l!= NULL){
        printf("-(%d, %d)", l-> destino, l->custo);
        ImprimirLista(l->prox);
    }
}


void ImprimirGrafo(lista **g, int n){
    int i;
    printf("Grafo");
    for(i = 1;i<n;i++){
        printf("\n\t%d", i);
        ImprimirLista(g[i]);
    }
}

int main(){
    int var, tam;
    int origem, destino, custo;
    lista **g;
    puts("Informe quantos nós terá seu grafo: \n");
    scanf("%d", &tam);
    inicializar(g, tam);
    printf("Informe: \n 1- Inserir Arestra\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Imprimir todos os caminhos entre uma origem e um destino\n 7- Imprimir o caminho mais curto\n 8- Imprimir o caminho de menor custo\n 9- Sair");
    scanf("%d", &var);
    while(var != 9){
        switch(var){
            case 1:
                InserirAresta(g, origem, destino, custo);                break;
            case 2:

                break;
            case 3:
                ImprimirGrafo(g, tam);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                printf("\nValor Invalido \n");
                break;
            printf("Informe: \n 1- Inserir Arestra\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Imprimir todos os caminhos entre uma origem e um destino\n 7- Imprimir o caminho mais curto\n 8- Imprimir o caminho de menor custo\n 9- Sair")
            scanf("%d", &var);

        }
    }
    return 0;
}