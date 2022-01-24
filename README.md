# 42 Cursus - Get Next Line

## Synthèse du besoin

Créer une fonction `get_next_line()` qui permet de lire ligne par ligne depuis un _file descriptor_. L'utilisation se fait par appel successif.

**Fonctions autorisées**

- `read()`.
- `malloc()`.
- `free()`.

**Mandatory**

- [ ] La taille du buffer utilisé pour la lecture est défini par `BUFFER_SIZE`.
- [ ] Fin de lecture retourne `NULL`.
- [ ] Un ligne doit être retournée avec `\n`, sauf si la fin de ligne n'en dispose pas.
- [ ] Comportement indéterminé si le _fd_ est modifié entre deux appels.
- [ ] Comportement indéterminé si le fichier appelé est un fichier binaire. Mais il peut être gérer si l'on veut.
- [ ] Retour de la ligne lors d'un retour de ligne en cas d'utilisation par STDIN.
- [ ] Arrèt du programme lors de l'utilisation de CTRL+D.

**Bonus**

- [ ] Une seule variable statique
- [ ] Gestion de plusieurs _fd_. Le changement de _fd_ ne doit pas perdre l'endroit où la lecture d'un _fd_ s'est terminée.

