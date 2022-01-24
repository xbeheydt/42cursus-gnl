# 42 Cursus - Get Next Line

## Synth�se du besoin

Cr�er une fonction `get_next_line()` qui permet de lire ligne par ligne depuis un _file descriptor_. L'utilisation se fait par appel successif.

**Fonctions autoris�es**

- `read()`.
- `malloc()`.
- `free()`.

**Mandatory**

- [ ] La taille du buffer utilis� pour la lecture est d�fini par `BUFFER_SIZE`.
- [ ] Fin de lecture retourne `NULL`.
- [ ] Un ligne doit �tre retourn�e avec `\n`, sauf si la fin de ligne n'en dispose pas.
- [ ] Comportement ind�termin� si le _fd_ est modifi� entre deux appels.
- [ ] Comportement ind�termin� si le fichier appel� est un fichier binaire. Mais il peut �tre g�rer si l'on veut.
- [ ] Retour de la ligne lors d'un retour de ligne en cas d'utilisation par STDIN.
- [ ] Arr�t du programme lors de l'utilisation de CTRL+D.

**Bonus**

- [ ] Une seule variable statique
- [ ] Gestion de plusieurs _fd_. Le changement de _fd_ ne doit pas perdre l'endroit o� la lecture d'un _fd_ s'est termin�e.

