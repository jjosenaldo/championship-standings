# Championship Standings

This is the management system of a championship standings table. It was formally specified using the B language. From that specification, the [Atelier-B](https://www.atelierb.eu/) tool generated C code in an automatic fashion. After that, the [CppUTest](https://cpputest.github.io/) framework was used for unit-testing the functions implemented, and the code coverage plus its branch coverage were analyzed using the [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) tool. Finally, the [lcov](https://linux.die.net/man/1/lcov) and [genhtml](https://linux.die.net/man/1/genhtml) tools were used for generating nice report tables from the output of gcov.

## Pre-requisites

In order to run the tests, you'll need to have the following softwares installed on your pc:
- CppUTest;
- gcov;
- lcov;
- genhtml.

After cloning this repo, you have to edit the [Makefile](test/Makefile). Set the `CPPUTEST_HOME` variable to the installation folder of CppUTest on your computer (this step is not needed if you installed it via apt-get or brew), and set the `PROJECT_DIR` variable to the path of this repo on your machine. 

<!-- ## Features

The championship standings has the following functions:
- `getGameResult`: gets the result of a game;
- `addNewGame`: registers the result of a game; 
- `removeGame`: removes a game, reversing its effects in the table;
- `editGame`: edits the result of a game;
- `getPosition`: gets the position of a team in the championship;
- `getPoints`: gets the total number of points of a team;
- `getWins`: gets the number of wins of a team;
- `getDraws`: gets the number of draws of a team;
- `getLosses`: gets the number of losses of a team;
- `getGoalsFor`: gets the number of goals that a team scored;
- `getGoalsAgainst`: gets the number of goals that other teams scored against a given team;
- `getGoalDiff`: gets the difference between the number of goals that a team scored and the goals that other teams scored against that one. -->

## Usage

Enter the [test](test/) directory. Here are some commands:
- `make test`: runs the tests in the [test](test/) directory;
- `make gcov`: generates line coverage and branch coverage reports using the gcov tool;
- `make lcov`: generates a more human-readable report, using the tool lcov, based on the output of gcov.

For more options, type `make` in your terminal and check on what your autocomplete suggests to you. ;)

