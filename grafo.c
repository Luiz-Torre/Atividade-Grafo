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
    no -> prox = l;
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
    for(i = 1;i<n+1;i++){
        printf("\n\t%d", i);
        ImprimirLista(g[i]);
    }
}
void MostraGraus(lista **g,int tam){
    int vetE[tam+1];
    int vetS[tam+1];
    for(int i = 0; i< tam+1;i++){
        vetE[i] = 0;
        vetS[i] = 0;
    }
    for (int i = 1; i <= tam; i++) {
        while (g[i] != NULL){
            for (int j = 1; j <= tam; j++) {
                if (g[i]->destino == j){
                    vetS[i]+= 1;
                    vetE[j]+= 1;
                }
            }
            g[i] = g[i]->prox;
        }
    }
    for (int i = 1; i < tam+1; ++i) {
        printf("Vertice %d\n", (i));
        printf("gs (Grau de saida): %d\n",vetS[i]);
        printf("ge (Grau de entrada): %d\n",vetE[i]);
    }
}

void excluirAresta(lista **g, int aux, int aux_dest){
    lista *atual = g[aux];

    lista *lista_aux;

    if (atual -> destino == aux_dest) {
        g[aux] = g[aux] -> prox;
        free(atual);
        return;
    }

    while (atual){
        lista_aux = atual;
        atual = atual -> prox;
        if (atual && atual -> destino == aux_dest){
        lista_aux -> prox = atual -> prox;
        free(atual);
        return;
        }
    }
    
    puts("O valor não se encontra em nenhum no");
}
void TestaCompleta(lista **g,int tam){
    int soma = 0;
    int vetE[tam+1];
    int vetS[tam+1];
    for(int i = 0; i< tam+1;i++){
        vetE[i] = 0;
        vetS[i] = 0;
    }
    for (int i = 1; i <= tam; i++) {
        while (g[i] != NULL){
            for (int j = 1; j <= tam; j++) {
                if (g[i]->destino == j){
                    vetS[i]+= 1;
                    vetE[j]+= 1;
                    soma += 2;
                }
            }
            g[i] = g[i]->prox;
        }
    }
    int total = (tam*(tam-1));
    if( total == soma){
        printf("O grafo é completo");
    }
    else{
        printf("O grafo não completo");
    }
}
int main(){
    int var, tam;
    int origem, destino, custo, aux, aux_dest;
    lista **g;
    puts("Informe quantos nós terá seu grafo: \n");
    scanf("%d", &tam);

    g = (lista**)malloc((tam+1)*sizeof(lista*));
    inicializar(g, tam);
    printf("Informe: \n 1- Inserir Aresta\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Sair");

    scanf("%d", &var);
    while(var != 9){
        switch(var){
            case 1:
                puts("Informe qual a origem: \n");
                scanf("%d", &origem);
                puts("Informe qual o destino: \n");
                scanf("%d", &destino);
                puts("Informe qual o custo: \n");
                scanf("%d", &custo);
                InserirAresta(g, origem, destino, custo);  
                break;
            case 2:
                puts("Informe de qual no de origem que você deseja excluir a arestra");
                scanf("%d", &aux);
                puts("Informe de qual no de destino que você deseja excluir a arestra");
                scanf("%d", &aux_dest);
                excluirAresta(g, aux, aux_dest );
                break;
            case 3:
                ImprimirGrafo(g, tam);
                break;
            case 4:
                MostraGraus(g,tam);
                break;
            case 5:

                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nValor Invalido");
                break;
        }
        printf("\nInforme: \n 1- Inserir Aresta\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Sair\n");
        scanf("%d", &var);
    }
    return 0;
}

//1 1 2 4
//1 2 1 7
//1 1 3 9
//1 3 1 10
//1 2 3 11
//1 3 2 3