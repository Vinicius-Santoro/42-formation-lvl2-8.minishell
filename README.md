<h1>42-formation-lvl2-8.minishell</h1>

### _Project 8: MiniShell - Eighth project for the formation of software engineers at school 42 São Paulo._

- This project is about creating a simple shell.

<!-- ## _The project looked like this:_

![so_long](https://user-images.githubusercontent.com/83036509/150965119-a96d5590-3971-43d0-959f-ee0d0f237d9e.gif) -->

## _Como utilizar_

- Clone the repository:
```
git clone git@github.com:Vinicius-Santoro/42-formation-lvl2-8.minishell.git
```
- Run the command to turn abstract files into object files:
```
make all
```
- Run the generated file and enjoy the minishell.
```
./minishell
```

## _How the project works_

Our minishell works as follows.

- Analysis and treatment of everything that was passed on the terminal.
- After the treatment, the arguments are tokenized, that is, each item is added to a node of a linked list (everything that arrives at this node is 100% OK).
- Checks if the node content is a builtin or an external command (the command is executed).

### _Project general fluxogram_

```mermaid
graph TD;
    main-->readline_loop;
    readline_loop-->do_command;
    do_command-->parse_line;
    parse_line-->parse_loop;
    parse_loop-->invalid_syntax_error;
    parse_loop-->parse_quotes;
    parse_loop-->parse_redirects;
    parse_loop-->parse_variables;
    parse_loop-->parse_split;
    parse_line-->cmd_split;
    parse_line-->tokenizer;
    do_command-->exec_command;
    exec_command-->check_if_built_in;
    check_if_built_in-->yes;
    yes-->exec_built_in;
    exec_built_in-->echo_built_in;
    exec_built_in-->pwd_built_in;
    exec_built_in-->export_built_in;
    exec_built_in-->env_built_in;
    exec_built_in-->exit_built_in;
    exec_built_in-->unset_built_in;
    exec_built_in-->cd_built_in;
    check_if_built_in-->no;
    no-->child_command;
    no-->parent_command;

```
