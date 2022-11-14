# pipex_42
project for ecole 42

The pipex is a program to be executed this way "./pipex file1 cmd1 cmd2 file2",  
(where cmd is a usual command like "ls" and file is just a file)  
and do the same as the shell command "< file1 cmd1 | cmd2 > file2".  
It will show you how shell pipes work.  
  
Bonus part:  
You need to handle multiple pipes and support << and >> when the first parameter is "here_doc".  
  
* You can see the full assignment here [subject](https://github.com/cbridget42/pipex_42/blob/main/subject/en.subject.pdf)
* Coding style: [norminette](https://github.com/cbridget42/pipex_42/blob/main/subject/en.norm.pdf)
  
### Usage:
* first you need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/pipex_42.git
	cd pipex_42
	make
	make bonus //compile with bonus
	```
* then you will have an executable called pipex.
	+ if you compiled it without the bonus part, you can use it like this:
    ```bash
    ./pipex infile "ls -l" "wc -l" outfile
	```
	+ if you compiled it with the bonus part, you can use it like this:
    ```bash
    ./pipex here_doc lim cat "wc -l" file
    or
    ./pipex file1 cat "grep hello" "wc -l" file2
	```
* also you can:
	```bash
	make clean //remove objects files
	make fclean //remove objects files and pipex
	```
  
### Usage example:
![image](https://github.com/cbridget42/pipex_42/blob/main/images/pipex.svg)
  
### final score:
![image](https://github.com/cbridget42/pipex_42/blob/main/images/Screenshot%20from%202022-11-14%2018-44-14.png)
  
