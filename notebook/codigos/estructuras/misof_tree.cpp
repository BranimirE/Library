/*
http://codeforces.com/blog/entry/10493#comment-159335

Sirve para encontrar el i-esimo numero de un conjunto de numeros que vamos insertando en el arbol.
Sirve solo si nuestros numeros son del 0 al n-1 (pero podemos mapearlos antes de usarlos)

La idea es esta:

Funcionamiento: 
	- En el fondo sigue siendo un Segment-Tree (hacemos que 'n' sea 2^x)
	- Cada nodo guarda cuantos numeros hay en el intervalo (entonces en tree[1] dice cuantos numeros tenemos en total)
	- Se sigue representando los hijos del nodo 'i' con '2 * i' (izq) y '2 * i + 1' (der);
Query:
	- si kth es mas grande que todos los que tenemos(tree[1]) o es negativo entonces -1
	- siempre nos mantenemos en el nodo de la izquierda y si es necario avanzamos al de la derecha
											'i <<= 1'
		- si kth es mas grande que el nodo de la izquierda(el actual) quiere decir que podemos quitarle todos esos
		numeros a nuestra busqueda 'kth - tree[i]' y buscar el nuevo kth en el arbol de la derecha
			if (kth > tree [i]) kth -= tree [i++];
		- Ojo en el 'i++' ahí es donde avanzamos al nodo de la derecha
	- luego hace su formula rara que aun no entendi xD:
			'i - leaf + (kth > tree [i])';
*/
const int MaxN = 1e6;

int a [MaxN], s [MaxN];
int leaf, tree [100 + MaxN << 2];

void bld (int n) { leaf = 1 << (32 - __builtin_clz (n)); }
void add (int x) { for (int i = leaf + x; i; i >>= 1) ++tree [i]; }//Podemos insertar mas de una copia la vez tree [i] += xcopies;
void del (int x) { for (int i = leaf + x; i; i >>= 1) --tree [i]; }//Podemos eliminar mas de una copia la vez tree [i] -= xcopies;
// en "leaf + x" esta cuantas copias tenemos de "x"
//Cuidado con intentar hacer del con mas copias de las disponibles, el kth() no funcionaria
long kth  (int kth, int i = -1) {
    if (kth > tree [1] || kth <= 0) return i;
	for (i = 1; i < leaf; i <<= 1) if (kth > tree [i]) kth -= tree [i++];
    return i - leaf + (kth > tree [i]);
}