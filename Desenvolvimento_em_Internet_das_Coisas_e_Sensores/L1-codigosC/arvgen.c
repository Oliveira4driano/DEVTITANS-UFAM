#include <stdio.h>
#include <stdlib.h>

struct arvgen {
  int info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;


ArvGen* cria (int info)
{
  ArvGen *a =(ArvGen *)malloc(sizeof(ArvGen));
  a->info = info;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void insere (ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}



void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%d\n",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

int busca (ArvGen* a, char c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

int main()
{
  ArvGen* a43 = cria(43);
  ArvGen* a22 = cria(22);
  ArvGen* a21 = cria(21);
  ArvGen* a58 = cria(58);
  ArvGen* a45 = cria(45);
  ArvGen* a66 = cria(66);
  ArvGen* a31 = cria(31);
  ArvGen* a71 = cria(71);
  ArvGen* a59 = cria(59);
  ArvGen* a12 = cria(12);
  ArvGen* a35 = cria(35);

  insere(a22,a66);
  insere(a22,a31);
  insere(a43,a22);
  insere(a43,a21);
  insere(a58,a71);
  insere(a58,a59);
  insere(a58,a12);
  insere(a43,a58);
  insere(a45,a35);
  insere(a43,a45);


  // Implimir
  imprime(a43);

  //Busca elementos 12 e 88
  if(busca(a43,12)){
    printf("Elemento 12 presente");
  }else{
    printf("Elemento 12 nao presente");
  }
  printf("\n");

  if(busca(a43,88))
    printf("Elemento 88 presente");
  else
    printf("Elemento 88 nao presente");

}
