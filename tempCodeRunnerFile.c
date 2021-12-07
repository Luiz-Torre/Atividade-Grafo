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