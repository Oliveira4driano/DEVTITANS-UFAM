#include <stdio.h>

struct lista {
  int info;
  struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa (void)
{
  return NULL;
}

Lista* insere (Lista* l, int i)
{
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}

void imprime (Lista* l)
{
  Lista* p;
  printf("Lista: ");
  for (p = l; p != NULL; p = p->prox)
    printf("%d  ", p->info);
  printf("\n");
}

int vazia (Lista* l)
{
  return (l == NULL);
}

Lista* busca (Lista* l, int v)
{
  Lista* p;
  for (p=l; p!=NULL; p=p->prox)
    if (p->info == v)
      return p;
  return NULL; /* n�o achou o elemento */
}


Lista* retira(Lista* l, int v)
{
  Lista* ant = NULL; /* ponteiro para elemento anterior */
  Lista* p = l; /* ponteiro para percorrer a lista*/
  /* procura elemento na lista, guardando anterior */
  while (p != NULL && p->info != v) {
    ant = p;
    p = p->prox;
  }
  /* verifica se achou elemento */
  if (p == NULL)
    return l; /* n�o achou: retorna lista original */
  /* retira elemento */
  if (ant == NULL) {
    /* retira elemento do inicio */
    l = p->prox;
  }
  else {
    /* retira elemento do meio da lista */
    ant->prox = p->prox;
  }
  free(p);
  return l;
}


void libera(Lista* l)
{
  Lista* p = l;
  while (p != NULL)
  {
    Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
    free(p); /* libera a mem�ria apontada por p */
    p = t; /* faz p apontar para o pr�ximo */
  }
}

int igual(Lista *l1, Lista *l2)
{

    no *atual1 = l1;
    no *atual2 = l2;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->info != atual2->info)
        {
            return 0;
        }

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    return atual1 == NULL && atual2 == NULL;
}

int main ()
{
  Lista* L1, L2;       /* declara duas listas nao iniciadas */
  L1 = inicializa();   /* inicia lista vazia */
  L1 = insere(L1, 23); /* insere na lista o elemento 23 */
  L1 = insere(L1, 45); /* insere na lista o elemento 45 */
  L1 = insere(L1, 56); /* insere na lista o elemento 56 */
  L1 = insere(L1, 78); /* insere na lista o elemento 78 */
  imprime(L1);         /* imprime: 78 56 45 23 */

  L2 = inicializa();   /* inicia lista vazia */
  L2 = insere(L2, 23); /* insere na lista o elemento 23 */
  L2 = insere(L2, 45); /* insere na lista o elemento 45 */
  L2 = insere(L2, 56); /* insere na lista o elemento 56 */
  imprime(L2);         /* imprime: 56 45 23 */

  if (igual(L1, L2))
    printf("L1 e L2 sao iguais\n");
  else
    printf("L1 e L2 sao diferentes\n");

  L2 = insere(L2, 78); /* insere na lista o elemento 78 */
  imprime(L1);         /* imprime: 78 56 45 23 */
  imprime(L2);         /* imprimw: 78 56 45 23 */

  if (igual(L1, L2))
    printf("L1 e L2 sao iguais\n");
  else
    printf("L1 e L2 sao diferentes\n");

  libera(L1);
  libera(L2);
}

