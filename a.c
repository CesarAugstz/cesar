#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *esq;
    struct nodo *dir;
} Nodo;

Nodo* criarNodo(int v){
    Nodo *p = (Nodo*)malloc(sizeof(Nodo));
    p->valor = v;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}

void mostraArvore(Nodo *p, int nivel){
    int i;
    if(p == NULL){
        for(i=0;i<nivel;i++)
            printf("  ");
        printf("#\n");
    }else{
        for(i=0;i<nivel;i++)
            printf("  ");
        printf("%i\n",p->valor);
        nivel++;
        mostraArvore(p->esq,nivel);
        mostraArvore(p->dir,nivel);
    }
}

Nodo* inserirNodo(Nodo *raiz, int v){
    if(!raiz){
        raiz = criarNodo(v);
    }else{
        if(v <= raiz->valor){
            raiz->esq = inserirNodo(raiz->esq,v);
        }else{
            raiz->dir = inserirNodo(raiz->dir,v);
        }
    }
    return raiz;
}

Nodo* busca(Nodo *raiz, int v){
    if(raiz){
        if(v == raiz->valor){
            return raiz;
        }else if(v < raiz->valor){
            return busca(raiz->esq, v);
        }else
            return busca(raiz->dir, v);
    }else
        return NULL;
}

Nodo* excluir(Nodo *raiz, int v){
    if(raiz){
        if(v < raiz->valor){
            raiz->esq = excluir(raiz->esq, v);
        }else if(v > raiz->valor){
            raiz->dir = excluir(raiz->dir, v);
        }else{ // encontrou v
            Nodo *aux = raiz;
            if(!raiz->esq){
                raiz = raiz->dir;
                free(aux);
            }else if(!raiz->dir){
                raiz = raiz->esq;
                free(aux);
            }else{
                Nodo *menorDir = raiz->dir;
                while(menorDir->esq)
                    menorDir = menorDir->esq;

                raiz->valor = menorDir->valor;
                raiz->dir = excluir(raiz->dir,menorDir->valor);
            }
        }
    }
    return raiz;
}

typedef struct fila{
    Nodo *no;
    struct fila *prox;
}Fila;

Fila* criarFila(Nodo *no){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    int *novo;
    f->no = novo;
    f->prox = NULL;

    return f;
}

Fila* enfileirar(Fila *f, Nodo *p){
    if(p){
        if(f){
            Fila *aux = f;
            while(aux->prox)
                aux = aux->prox;
            aux->prox = criarFila(p);
        }else
            f = criarFila(p);
    }
    return f;
}

Fila* desenfileirar(Fila *f, Nodo *p){
    
        if(f){
            Fila *aux = f;
            f->prox = criarFila(p);
        }else
            f = criarFila(p);
    return f;
}

Nodo* buscaLarg(Nodo* raiz, int v){
    if(raiz){
        
    }
    return raiz;
}

int main(){
    Nodo *raiz = NULL, *aux = NULL;
    int op, v;

    do{
        printf("1 - inserir novo nodo\n");
        printf("2 - mostrar arvore\n");
        printf("3 - buscar nodo\n");
        printf("4 - excluir nodo\n");

        printf("0 - sair\n");
        printf("opcao: ");
        scanf("%d",&op);

        switch(op){
        case 1:
            printf("\nCriando novo nodo\n");
            printf("valor: ");
            scanf("%d",&v);
            raiz = inserirNodo(raiz,v);
            break;
        case 2:
            mostraArvore(raiz,0);
            break;
        case 3:
            printf("\nBuscando nodo\n");
            printf("valor: ");
            scanf("%d",&v);
            aux = busca(raiz,v);
            if(aux)
                printf("\nValor %i econtrado.",aux->valor);
            else
                printf("\nValor nao esta na arvore.");
            break;
        case 4:
            printf("\nExcluindo nodo\n");
            printf("valor: ");
            scanf("%d",&v);
            raiz = excluir(raiz,v);
            mostraArvore(raiz,0);
            break;
        case 0:
            printf("Sair\n");
            break;
        default:
            printf("opcao invalida\n");
        }
        printf("\n\n\n");
    }while(op!=0);

    return 0;
}
