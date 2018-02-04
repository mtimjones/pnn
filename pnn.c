#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define USE_ZOO_DATASET    1

#if USE_ZOO_DATASET
#define FEATURES	16
#define CLASSES		 7

typedef struct dataset_t {
   char *name;
   int  features[ FEATURES ];
   int  class;
   int  computed_class;
} dataset_t;

#define OBSERVATIONS	100

// Classes are [1] Mammal, [2] Bird, [3] Reptile, [4] Fish
//             [5] Amphibian, [6] Bug, [7] Invertebrate.

dataset_t dataset[ OBSERVATIONS ] = 
{
//  Name        Features                           Class
   {"aardvark", {1,0,0,1,0,0,1,1,1,1,0,0,4,0,0,1}, 1},
   {"antelope", {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"bass",     {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0}, 4},
   {"bear",     {1,0,0,1,0,0,1,1,1,1,0,0,4,0,0,1}, 1},
   {"boar",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"buffalo",  {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"calf",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,1}, 1},
   {"carp",     {0,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0}, 4},
   {"catfish",  {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0}, 4},
   {"cavy",     {1,0,0,1,0,0,0,1,1,1,0,0,4,0,1,0}, 1},
   {"cheetah",  {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"chicken",  {0,1,1,0,1,0,0,0,1,1,0,0,2,1,1,0}, 2},
   {"chub",     {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0}, 4},
   {"crab",     {0,0,1,0,0,1,1,0,0,0,0,0,4,0,0,0}, 7},
   {"crayfish", {0,0,1,0,0,1,1,0,0,0,0,0,6,0,0,0}, 7},
   {"crow",     {0,1,1,0,1,0,1,0,1,1,0,0,2,1,0,0}, 2},
   {"deer",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"dogfish",  {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1}, 4},
   {"dolphin",  {0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1}, 1},
   {"dove",     {0,1,1,0,1,0,0,0,1,1,0,0,2,1,1,0}, 2},
   {"duck",     {0,1,1,0,1,1,0,0,1,1,0,0,2,1,0,0}, 2},
   {"elephant", {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"flamingo", {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,1}, 2},
   {"flea",     {0,0,1,0,0,0,0,0,0,1,0,0,6,0,0,0}, 6},
   {"frog",     {0,0,1,0,0,1,1,1,1,1,0,0,4,0,0,0}, 5},
   {"frog",     {0,0,1,0,0,1,1,1,1,1,1,0,4,0,0,0}, 5},
   {"fruitbat", {1,0,0,1,1,0,0,1,1,1,0,0,2,1,0,0}, 1},
   {"giraffe",  {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"girl",     {1,0,0,1,0,0,1,1,1,1,0,0,2,0,1,1}, 1},
   {"gnat",     {0,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0}, 6},
   {"goat",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,1}, 1},
   {"gorilla",  {1,0,0,1,0,0,0,1,1,1,0,0,2,0,0,1}, 1},
   {"gull",     {0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0}, 2},
   {"haddock",  {0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 4},
   {"hamster",  {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,0}, 1},
   {"hare",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,0}, 1},
   {"hawk",     {0,1,1,0,1,0,1,0,1,1,0,0,2,1,0,0}, 2},
   {"herring",  {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0}, 4},
   {"honeybee", {1,0,1,0,1,0,0,0,0,1,1,0,6,0,1,0}, 6},
   {"housefly", {1,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0}, 6},
   {"kiwi",     {0,1,1,0,0,0,1,0,1,1,0,0,2,1,0,0}, 2},
   {"ladybird", {0,0,1,0,1,0,1,0,0,1,0,0,6,0,0,0}, 6},
   {"lark",     {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,0}, 2},
   {"leopard",  {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"lion",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"lobster",  {0,0,1,0,0,1,1,0,0,0,0,0,6,0,0,0}, 7},
   {"lynx",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"mink",     {1,0,0,1,0,1,1,1,1,1,0,0,4,1,0,1}, 1},
   {"mole",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,0}, 1},
   {"mongoose", {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"moth",     {1,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0}, 6},
   {"newt",     {0,0,1,0,0,1,1,1,1,1,0,0,4,1,0,0}, 5},
   {"octopus",  {0,0,1,0,0,1,1,0,0,0,0,0,8,0,0,1}, 7},
   {"opossum",  {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,0}, 1},
   {"oryx",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
   {"ostrich",  {0,1,1,0,0,0,0,0,1,1,0,0,2,1,0,1}, 2},
   {"parakeet", {0,1,1,0,1,0,0,0,1,1,0,0,2,1,1,0}, 2},
   {"penguin",  {0,1,1,0,0,1,1,0,1,1,0,0,2,1,0,1}, 2},
   {"pheasant", {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,0}, 2},
   {"pike",     {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1}, 4},
   {"piranha",  {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0}, 4},
   {"pitviper", {0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0}, 3},
   {"platypus", {1,0,1,1,0,1,1,0,1,1,0,0,4,1,0,1}, 1},
   {"polecat",  {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"pony",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,1}, 1},
   {"porpoise", {0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1}, 1},
   {"puma",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"pussycat", {1,0,0,1,0,0,1,1,1,1,0,0,4,1,1,1}, 1},
   {"raccoon",  {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"reindeer", {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,1}, 1},
   {"rhea",     {0,1,1,0,0,0,1,0,1,1,0,0,2,1,0,1}, 2},
   {"scorpion", {0,0,0,0,0,0,1,0,0,1,1,0,8,1,0,0}, 7},
   {"seahorse", {0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 4},
   {"seal",     {1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1}, 1},
   {"sealion",  {1,0,0,1,0,1,1,1,1,1,0,1,2,1,0,1}, 1},
   {"seasnake", {0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0}, 3},
   {"seawasp",  {0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0}, 7},
   {"skimmer",  {0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0}, 2},
   {"skua",     {0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0}, 2},
   {"slowworm", {0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0}, 3},
   {"slug",     {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0}, 7},
   {"sole",     {0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 4},
   {"sparrow",  {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,0}, 2},
   {"squirrel", {1,0,0,1,0,0,0,1,1,1,0,0,2,1,0,0}, 1},
   {"starfish", {0,0,1,0,0,1,1,0,0,0,0,0,5,0,0,0}, 7},
   {"stingray", {0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,1}, 4},
   {"swan",     {0,1,1,0,1,1,0,0,1,1,0,0,2,1,0,1}, 2},
   {"termite",  {0,0,1,0,0,0,0,0,0,1,0,0,6,0,0,0}, 6},
   {"toad",     {0,0,1,0,0,1,0,1,1,1,0,0,4,0,0,0}, 5},
   {"tortoise", {0,0,1,0,0,0,0,0,1,1,0,0,4,1,0,1}, 3},
   {"tuatara",  {0,0,1,0,0,0,1,1,1,1,0,0,4,1,0,0}, 3},
   {"tuna",     {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1}, 4},
   {"vampire",  {1,0,0,1,1,0,0,1,1,1,0,0,2,1,0,0}, 1},
   {"vole",     {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,0}, 1},
   {"vulture",  {0,1,1,0,1,0,1,0,1,1,0,0,2,1,0,1}, 2},
   {"wallaby",  {1,0,0,1,0,0,0,1,1,1,0,0,2,1,0,1}, 1},
   {"wasp",     {1,0,1,0,1,0,0,0,0,1,1,0,6,0,0,0}, 6},
   {"wolf",     {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
   {"worm",     {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0}, 7},
   {"wren",     {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,0}, 2},
};
#else
#define FEATURES	4
#define CLASSES		3

typedef struct dataset_t {
   double  features[ FEATURES ];
   int  class;
   int  computed_class;
} dataset_t;

#define OBSERVATIONS	150

// Iris Dataset.  
// Classes are [1] Iris-setosa, [2] Iris-versicolor, [3] Iris-virginica.

dataset_t dataset[ OBSERVATIONS ] = {
{ { 5.1,3.5,1.4,0.2} ,1 },
{ { 4.9,3.0,1.4,0.2} ,1 },
{ { 4.7,3.2,1.3,0.2} ,1 },
{ { 4.6,3.1,1.5,0.2} ,1 },
{ { 5.0,3.6,1.4,0.2} ,1 },
{ { 5.4,3.9,1.7,0.4} ,1 },
{ { 4.6,3.4,1.4,0.3} ,1 },
{ { 5.0,3.4,1.5,0.2} ,1 },
{ { 4.4,2.9,1.4,0.2} ,1 },
{ { 4.9,3.1,1.5,0.1} ,1 },
{ { 5.4,3.7,1.5,0.2} ,1 },
{ { 4.8,3.4,1.6,0.2} ,1 },
{ { 4.8,3.0,1.4,0.1} ,1 },
{ { 4.3,3.0,1.1,0.1} ,1 },
{ { 5.8,4.0,1.2,0.2} ,1 },
{ { 5.7,4.4,1.5,0.4} ,1 },
{ { 5.4,3.9,1.3,0.4} ,1 },
{ { 5.1,3.5,1.4,0.3} ,1 },
{ { 5.7,3.8,1.7,0.3} ,1 },
{ { 5.1,3.8,1.5,0.3} ,1 },
{ { 5.4,3.4,1.7,0.2} ,1 },
{ { 5.1,3.7,1.5,0.4} ,1 },
{ { 4.6,3.6,1.0,0.2} ,1 },
{ { 5.1,3.3,1.7,0.5} ,1 },
{ { 4.8,3.4,1.9,0.2} ,1 },
{ { 5.0,3.0,1.6,0.2} ,1 },
{ { 5.0,3.4,1.6,0.4} ,1 },
{ { 5.2,3.5,1.5,0.2} ,1 },
{ { 5.2,3.4,1.4,0.2} ,1 },
{ { 4.7,3.2,1.6,0.2} ,1 },
{ { 4.8,3.1,1.6,0.2} ,1 },
{ { 5.4,3.4,1.5,0.4} ,1 },
{ { 5.2,4.1,1.5,0.1} ,1 },
{ { 5.5,4.2,1.4,0.2} ,1 },
{ { 4.9,3.1,1.5,0.1} ,1 },
{ { 5.0,3.2,1.2,0.2} ,1 },
{ { 5.5,3.5,1.3,0.2} ,1 },
{ { 4.9,3.1,1.5,0.1} ,1 },
{ { 4.4,3.0,1.3,0.2} ,1 },
{ { 5.1,3.4,1.5,0.2} ,1 },
{ { 5.0,3.5,1.3,0.3} ,1 },
{ { 4.5,2.3,1.3,0.3} ,1 },
{ { 4.4,3.2,1.3,0.2} ,1 },
{ { 5.0,3.5,1.6,0.6} ,1 },
{ { 5.1,3.8,1.9,0.4} ,1 },
{ { 4.8,3.0,1.4,0.3} ,1 },
{ { 5.1,3.8,1.6,0.2} ,1 },
{ { 4.6,3.2,1.4,0.2} ,1 },
{ { 5.3,3.7,1.5,0.2} ,1 },
{ { 5.0,3.3,1.4,0.2} ,1 },
{ { 7.0,3.2,4.7,1.4} ,2 },
{ { 6.4,3.2,4.5,1.5} ,2 },
{ { 6.9,3.1,4.9,1.5} ,2 },
{ { 5.5,2.3,4.0,1.3} ,2 },
{ { 6.5,2.8,4.6,1.5} ,2 },
{ { 5.7,2.8,4.5,1.3} ,2 },
{ { 6.3,3.3,4.7,1.6} ,2 },
{ { 4.9,2.4,3.3,1.0} ,2 },
{ { 6.6,2.9,4.6,1.3} ,2 },
{ { 5.2,2.7,3.9,1.4} ,2 },
{ { 5.0,2.0,3.5,1.0} ,2 },
{ { 5.9,3.0,4.2,1.5} ,2 },
{ { 6.0,2.2,4.0,1.0} ,2 },
{ { 6.1,2.9,4.7,1.4} ,2 },
{ { 5.6,2.9,3.6,1.3} ,2 },
{ { 6.7,3.1,4.4,1.4} ,2 },
{ { 5.6,3.0,4.5,1.5} ,2 },
{ { 5.8,2.7,4.1,1.0} ,2 },
{ { 6.2,2.2,4.5,1.5} ,2 },
{ { 5.6,2.5,3.9,1.1} ,2 },
{ { 5.9,3.2,4.8,1.8} ,2 },
{ { 6.1,2.8,4.0,1.3} ,2 },
{ { 6.3,2.5,4.9,1.5} ,2 },
{ { 6.1,2.8,4.7,1.2} ,2 },
{ { 6.4,2.9,4.3,1.3} ,2 },
{ { 6.6,3.0,4.4,1.4} ,2 },
{ { 6.8,2.8,4.8,1.4} ,2 },
{ { 6.7,3.0,5.0,1.7} ,2 },
{ { 6.0,2.9,4.5,1.5} ,2 },
{ { 5.7,2.6,3.5,1.0} ,2 },
{ { 5.5,2.4,3.8,1.1} ,2 },
{ { 5.5,2.4,3.7,1.0} ,2 },
{ { 5.8,2.7,3.9,1.2} ,2 },
{ { 6.0,2.7,5.1,1.6} ,2 },
{ { 5.4,3.0,4.5,1.5} ,2 },
{ { 6.0,3.4,4.5,1.6} ,2 },
{ { 6.7,3.1,4.7,1.5} ,2 },
{ { 6.3,2.3,4.4,1.3} ,2 },
{ { 5.6,3.0,4.1,1.3} ,2 },
{ { 5.5,2.5,4.0,1.3} ,2 },
{ { 5.5,2.6,4.4,1.2} ,2 },
{ { 6.1,3.0,4.6,1.4} ,2 },
{ { 5.8,2.6,4.0,1.2} ,2 },
{ { 5.0,2.3,3.3,1.0} ,2 },
{ { 5.6,2.7,4.2,1.3} ,2 },
{ { 5.7,3.0,4.2,1.2} ,2 },
{ { 5.7,2.9,4.2,1.3} ,2 },
{ { 6.2,2.9,4.3,1.3} ,2 },
{ { 5.1,2.5,3.0,1.1} ,2 },
{ { 5.7,2.8,4.1,1.3} ,2 },
{ { 6.3,3.3,6.0,2.5} ,3 },
{ { 5.8,2.7,5.1,1.9} ,3 },
{ { 7.1,3.0,5.9,2.1} ,3 },
{ { 6.3,2.9,5.6,1.8} ,3 },
{ { 6.5,3.0,5.8,2.2} ,3 },
{ { 7.6,3.0,6.6,2.1} ,3 },
{ { 4.9,2.5,4.5,1.7} ,3 },
{ { 7.3,2.9,6.3,1.8} ,3 },
{ { 6.7,2.5,5.8,1.8} ,3 },
{ { 7.2,3.6,6.1,2.5} ,3 },
{ { 6.5,3.2,5.1,2.0} ,3 },
{ { 6.4,2.7,5.3,1.9} ,3 },
{ { 6.8,3.0,5.5,2.1} ,3 },
{ { 5.7,2.5,5.0,2.0} ,3 },
{ { 5.8,2.8,5.1,2.4} ,3 },
{ { 6.4,3.2,5.3,2.3} ,3 },
{ { 6.5,3.0,5.5,1.8} ,3 },
{ { 7.7,3.8,6.7,2.2} ,3 },
{ { 7.7,2.6,6.9,2.3} ,3 },
{ { 6.0,2.2,5.0,1.5} ,3 },
{ { 6.9,3.2,5.7,2.3} ,3 },
{ { 5.6,2.8,4.9,2.0} ,3 },
{ { 7.7,2.8,6.7,2.0} ,3 },
{ { 6.3,2.7,4.9,1.8} ,3 },
{ { 6.7,3.3,5.7,2.1} ,3 },
{ { 7.2,3.2,6.0,1.8} ,3 },
{ { 6.2,2.8,4.8,1.8} ,3 },
{ { 6.1,3.0,4.9,1.8} ,3 },
{ { 6.4,2.8,5.6,2.1} ,3 },
{ { 7.2,3.0,5.8,1.6} ,3 },
{ { 7.4,2.8,6.1,1.9} ,3 },
{ { 7.9,3.8,6.4,2.0} ,3 },
{ { 6.4,2.8,5.6,2.2} ,3 },
{ { 6.3,2.8,5.1,1.5} ,3 },
{ { 6.1,2.6,5.6,1.4} ,3 },
{ { 7.7,3.0,6.1,2.3} ,3 },
{ { 6.3,3.4,5.6,2.4} ,3 },
{ { 6.4,3.1,5.5,1.8} ,3 },
{ { 6.0,3.0,4.8,1.8} ,3 },
{ { 6.9,3.1,5.4,2.1} ,3 },
{ { 6.7,3.1,5.6,2.4} ,3 },
{ { 6.9,3.1,5.1,2.3} ,3 },
{ { 5.8,2.7,5.1,1.9} ,3 },
{ { 6.8,3.2,5.9,2.3} ,3 },
{ { 6.7,3.3,5.7,2.5} ,3 },
{ { 6.7,3.0,5.2,2.3} ,3 },
{ { 6.3,2.5,5.0,1.9} ,3 },
{ { 6.5,3.0,5.2,2.0} ,3 },
{ { 6.2,3.4,5.4,2.3} ,3 },
{ { 5.9,3.0,5.1,1.8} ,3 }
};

#endif

#define SIGMA	((double)0.0292)

#define SQR( x )      ( ( x ) * ( x ) )

// Determine class membership through winner-takes-all (Decision layer)
int winner_takes_all( double *output )
{
  int class, best = 0;
  double max = output[0];

  for (class = 1 ; class < CLASSES ; class++) {
    if (output[class] > max) {
      best = class;
      max = output[class];
    }
  }

  return best;
}


// PNN Classifier
int pnn_classifier( dataset_t example )
{
  int class, observation, feature, class_observations;
  double product;
  double output[CLASSES];

  for ( class = 1 ; class <= CLASSES ; class++ ) {

    output[class-1] = 0.0;
    class_observations = 0;

    for ( observation = 0 ; observation < OBSERVATIONS ; observation++ ) {

      product = 0.0;

      // Train the class output node based upon samples for this class.
      if ( dataset[observation].class == class )
      {
         class_observations++;

         // Product of the example vector and the input feature vector
         for ( feature = 0 ; feature < FEATURES ; feature++ ) {
           product += SQR( ( example.features[feature] - dataset[observation].features[feature] ) );
         }

         output[class-1] += exp( -( product / ( 2.0 * SQR( SIGMA ) ) ) );
      }

    }

    output[class-1] /= (double)class_observations;
  }

  return winner_takes_all( output ) + 1;
}


int main( void )
{
   // Compute the cluster for each observation.
   for ( int i = 0 ; i < OBSERVATIONS ; i++ )
   {
      dataset[ i ].computed_class = pnn_classifier( dataset[ i ] );
      printf( "Data %d, Class %d, Computed Class %d\n", 
               i, dataset[ i ].class, dataset[ i ].computed_class );
   }

#if USE_ZOO_DATASET
   // Emit the clusters
   for ( int class = 0 ; class < CLASSES ; class++ )
   {
      printf( "Class %d\n", class+1 );
      for ( int obs = 0 ; obs < OBSERVATIONS ; obs++ )
      {
         if ( dataset[ obs ].computed_class == class+1 )
         {
            printf( "   %s (%d)\n", dataset[ obs ].name, dataset[ obs ].class );
         }
      }
      printf("\n");
   }

   dataset_t example = {"mystery", {0,0,1,0,0,1,0,1,1,1,0,0,4,1,0,0}, 7};

   printf("Classification %d\n", pnn_classifier( example ) );
#endif

   return 0;
}

