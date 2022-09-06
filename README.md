# pipex_42
The pipex is a program to be executed this way "./pipex file1 cmd1 cmd2 file2",  
and do the same as the shell command "< file1 cmd1 | cmd2 > file2".  
  
Bonus part:  
You need to handle multiple pipes and support << and >> when the first parameter is "here_doc".  
  
Usage:  
enter 'make' in the project directory, it will create pipex executable!  
Execution example:  
    ./pipex infile "ls -l" "wc -l" outfile  
or enter 'make bonus' in the project directory, it will create pipex executable!  
Execution example:  
    ./pipex here_doc lim cat "wc -l" file  
    ./pipex file1 cat "grep hello" "wc -l" file2  
