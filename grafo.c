#include <stdio.h>



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
int main(){
    int var;
    
    printf("Informe: \n 1- Inserir Arestra\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Imprimir todos os caminhos entre uma origem e um destino\n 7- Imprimir o caminho mais curto\n 8- Imprimir o caminho de menor custo\n 9- Sair");
    scanf("%d", &var);
    while(var != 9){
        switch(var){
            case 1:
                break;
            case 2:
                break;
            case 3:
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
                printf("Valor Invalido \nInforme: \n 1- Inserir Arestra\n 2- Remover uma aresta\n 3- Imprimir grafo\n 4- Imprimir os graus de entrada e saída de um vértice\n 5- Verificar se um grafo é completo\n 6- Imprimir todos os caminhos entre uma origem e um destino\n 7- Imprimir o caminho mais curto\n 8- Imprimir o caminho de menor custo\n 9- Sair");
                scanf("%d", &var);
        }
    }
    return 0;
}