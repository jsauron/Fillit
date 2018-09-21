# FILLIT
  
* *Fillit is a tetris solver that takes as input a list of pieces (tetriminos) and displays on the standart output the smallest possible square formed by these pieces*
* *It is a project at 42 school*

## Built With

C language

## Return Value
 
* Display a tetris visualisator
 
## Running
 
* Git clone https://github.com/jsauron/fillit.git
* Create files of tetriminos
* *Exemple* :
```
$> cat [file] | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$ 
.###$
...#$ 
....$
....$ 
$
....$
..##$
.##.$
....$
$ 
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$ 
.#..$
....$ 
$
....$
###.$
.#..$
....$
```

Run `Make` and `./fillit [file]`

```
$> ./fillit [file] | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$ $>
```

## Author

**Jeanne Sauron**
