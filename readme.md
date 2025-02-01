# Manuel d'Utilisation : Implémentation d'un Trie




## Introduction

Ce projet propose deux implémentations différentes d'un **Trie** (ou arbre préfixe), une structure de données utilisée pour stocker efficacement des chaînes de caractères.

- **Trie avec une Table de Hachage** : Permet de stocker et d'accéder aux transitions entre les nœuds du Trie à l'aide d'une table de hachage.
- **Trie avec une Matrice de Transitions** : Utilise une matrice pour représenter les transitions d'un nœud à l'autre dans le Trie.

Ce manuel couvre l'installation, l'utilisation et la compréhension du fonctionnement de ces deux approches.

---

## Structure du Projet

Le projet est organisé en deux répertoires distincts :

1. **`hach/`** : Contient le code pour l'implémentation du Trie utilisant une table de hachage.
2. **`transitionTable/`** : Contient le code pour l'implémentation du Trie avec une matrice de transitions.

### Répertoire `hach/`
- `hash.c` : Code source pour la gestion des transitions via une table de hachage.
- `structureHash.h` : Définitions des structures de données utilisées pour le Trie basé sur une table de hachage.
- `Makefile` : Script pour compiler le projet dans ce répertoire.

### Répertoire `transitionTable/`
- `main.c` : Code source principal pour manipuler le Trie via une matrice de transitions.
- `structure.h` : Définitions des structures de données utilisées pour représenter la matrice.
- `Makefile` : Script pour compiler ce projet.

---

### Exécution des programmes

1. **Table de hachage** : Accédez au répertoire `hach`, puis exécutez la commande **make**. Ensuite, lancez le programme avec la commande :
```bash
   ./Trie
```
2. **Table des transition**: Accédez au répertoire `transitionTable` puis executez la commande **make** puis executez le programme  
```bash
./Trie
```

#### NOTE: 
Le programme contient une fonction de test qui vérifie les fonctions sur des mots arbitraires.



