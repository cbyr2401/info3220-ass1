# README #

This is the assignment of Cian Byrne for space invaders part 1 INFO3220.

### Completed Tasks ###
* Custom Configuration File (see below for usage)
* Configuration File: set size of spaceship (tiny, normal, large, giant)
* Configuration File: set starting position of spaceship
* Configuration File: give "moves" or instructions to the spaceship.
* Selected Builder OO Design Method (Creational Design Pattern)
* Spaceship moves left, right and shoots.
* Spaceship renders in four sizes.
* Program checks if a Configuration File is present, if not present, quits.
* Internal Code documentation (commenting, variable names, method names, etc)
* Sound FX for shooting.

### Configuration File Usage ###

The configuration must be in the following format:


```
#!bash

<size spaceship integer>
<start position spaceship integer>
<move1 string>
<move2 string>
 . . .
<move2000 string>
```

The accepted values for size are: tiny, normal, large and giant.

Tiny: 90 px x 30 px
Normal: 120 px x 40 px
Large: 150 px x 50 px
Giant: 180 px x 60 px

The accepted values for position are any integer between 0 and 600 (window size).

The accepted values for moves are: LEFT, RIGHT and SHOT.

NOTE: Please do not put anything else in the configuration file or you will experience unexpected behaviour.



### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact