# Simplified C Compiler

A translator built for a simplified version of the C language, called C-IPL, with limited functionalities and adding a List type along with custom list operators.

The input file is translated to a Three Address Code that can be read by this interpreter: https://github.com/lhsantos/tac

This translator was implemented as a project on the Translators course in the Computer Science Undergraduate course in Universidade de Brasília.


## Implementation

The translator is divided in 4 modules: 3 analysis modules and 1 translation module. The analysis consists of lexical, syntactical and semantic analysis.

Each module is implemented on top of the previous one, because each module needs the result of the previous module. Therefore, each folder contains the translator developed up to that point.

Example:
    Lexical Analysis: Contains a functioning lexical analyzer only
    Syntax analysis folder: Contains the previous functioning lexical analyzer, modified as needed to work with the syntax analyzer, and the functioning syntax analyzer.

The same follows for the other folders.


### Lexical
The lexical analysis parses the source file and breaks it into tokens. It was built using `flex`.

### Syntactic
The syntactic analysis takes the tokens created by the lexical analysis and checks if the source code is following the syntax defined by the language. To do that, a syntactic grammar was implemented using `bison`. A syntax tree is built in this stage, storing important information to continue translation.

### Semantic
The semantic analysis uses the syntax tree and the information stored in it to analyze the semantic defined by the language.

### Code Generation
Uses the previous generated information to generate the translated Three Address Code.

## Compilation

Each folder contains a function version of the translator at separate stages of implementation. The most "complete" version is, therefore, inside the Code Generation folder.

Each folder has its own compilation and execution instructions in each README.txt file. All have makefiles to help compilation, so its only needed to run `make SOMETHING` replacing SOMETHING with the corresponding name, written in the corresponding README.txt file inside the folder of each version of the translator.

Example: `make sintatico` for the syntax folder.

## Use

To use the compiled translator, type `./tradutor FILENAME`, replacing FILENAME with the C-IPL file that needs to be translated.

Each stage of the translator contains a `tests` folder with a few C-IPL test files. They can be used to test the translator

# :warning: Warning

Although simplified, the C-IPL language is still reasonably complex to create a translator for, without any previous knowledge on how to implement a translator. There are bugs that could not be fixed in time. The translator might crash or the translated file might not have the desired functionality.

There are a lot of things that need to be checked in every stage, but specially in the syntactic and semantic analysis. Implementing each stage at a time meant going back and modifying the previous stage to work with the next, while developing it.

Development took a lot of time, research and trial-and-error. All the concepts and tools used were learned by hand while developing, without any previous knowledge.

So, even though is it not perfect and there are definitely bugs, this project is a good example of how a translator works. It is possible to see how each stage uses the previous one and how the previous had to be modified to work with each subsequent stage.
